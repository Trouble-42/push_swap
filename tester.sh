#!/bin/bash
LOGFILE="evaluation_$(date +%Y%m%d_%H%M%S).txt"

exec > >(tee "$LOGFILE")
exec 2>&1

PS=./push_swap

BEST=999999
WORST=0
TOTAL=0
COUNT=0

OVER700=0
OVER900=0
OVER1100=0

OVER5500=0
OVER7000=0
OVER8500=0

print_header()
{
    echo
    echo "========================================"
    echo "$1"
    echo "========================================"
}

test_case()
{
    SCORE=$($PS $1 | wc -l)

    echo "$1"
    echo "Operations: $SCORE"
    echo

    TOTAL=$((TOTAL + SCORE))
    COUNT=$((COUNT + 1))

    [ "$SCORE" -lt "$BEST" ] && BEST=$SCORE
    [ "$SCORE" -gt "$WORST" ] && WORST=$SCORE
}
print_header "ERROR HANDLING"

test_error()
{
    OUTPUT=$("$PS" "$1" 2>&1 >/dev/null)
    RET=$?

    if echo "$OUTPUT" | grep -q "^Error$" && [ "$RET" -ne 0 ]; then
        echo "[OK] '$1'"
    else
        echo "[FAIL] '$1'"
        echo "Exit code : $RET"
        echo "Output    : '$OUTPUT'"
    fi
}
test_error "1 2 2"
test_error "42 42"

test_error "a"
test_error "1 a 2"
test_error "hello"

test_error "2147483648"
test_error "-2147483649"

test_error "+"
test_error "-"

test_error "--1"
test_error "++1"

test_error "1  2  a"

test_error "1a"
test_error "2b"

test_error "1.5"
test_error "3.14"

test_error " "

print_header "PARSER TORTURE TESTS"

test_error "--"
test_error "---"
test_error "++++"
test_error "----"

test_error "+-1"
test_error "-+1"

test_error "+42-"
test_error "-42+"

test_error "  +"
test_error "  -"

test_error "2147483649"
test_error "-2147483650"

test_error "999999999999999999999999999"
test_error "-999999999999999999999999999"

test_error "1,2,3"
test_error "1;2;3"
test_error "1:2:3"

test_error "1\t2\t3"

test_error "abc123"
test_error "123abc"

test_error "1--2"
test_error "1++2"

test_error "+ 1"
test_error "- 1"

print_header "DUPLICATE TORTURE TESTS"

test_error "0 0"
test_error "-0 0"
test_error "+0 0"

test_error "01 1"
test_error "001 1"
test_error "0001 1"

test_error "42 042"
test_error "42 00042"

test_error "-01 -1"

test_error "2147483647 2147483647"
test_error "-2147483648 -2147483648"

print_header "Bench error test"
test_error "--"
test_error "--hello"
test_error "--unknown"

test_error "--bench --hello 3 2 1"

test_error "--1"
test_error "--123"

test_error "--complexe"
test_error "--benchh"
test_error "--adapt"

test_flag()
{
    OUTPUT=$($PS $1 2>&1)
    RET=$?

    if [ "$RET" -eq 0 ]; then
        echo "[OK] $1"
    else
        echo "[FAIL] $1"
        echo "Exit code : $RET"
        echo "Output    : $OUTPUT"
    fi
}
print_header "FLAGS TESTS"
test_flag "--adaptative 3 2 1"
test_flag "--simple 3 2 1"
test_flag "--medium 3 2 1"
test_flag "--complex 3 2 1"
test_flag "--bonus 3 2 1"

test_flag "--bench 3 2 1"

test_flag "--bench --adaptative 3 2 1"
test_flag "--bench --simple 3 2 1"
test_flag "--bench --medium 3 2 1"
test_flag "--bench --complex 3 2 1"
test_flag "--bench --bonus 3 2 1"
test_flag "--simple --complex 3 2 1"
test_flag "--adaptative --bonus 3 2 1"

random_tests()
{
    SIZE=$1
    TESTS=$2

    print_header "Random tests ($SIZE numbers)"

    for ((i=1;i<=TESTS;i++))
    do
        ARG=$(shuf -i 0-99999 -n $SIZE | tr '\n' ' ')
        SCORE=$($PS $ARG | wc -l)

        TOTAL=$((TOTAL + SCORE))
        COUNT=$((COUNT + 1))

        [ "$SCORE" -lt "$BEST" ] && BEST=$SCORE
        [ "$SCORE" -gt "$WORST" ] && WORST=$SCORE

        if [ "$SIZE" -eq 100 ]; then
            [ "$SCORE" -gt 700 ] && ((OVER700++))
            [ "$SCORE" -gt 900 ] && ((OVER900++))
            [ "$SCORE" -gt 1100 ] && ((OVER1100++))
        fi

        if [ "$SIZE" -eq 500 ]; then
            [ "$SCORE" -gt 5500 ] && ((OVER5500++))
            [ "$SCORE" -gt 7000 ] && ((OVER7000++))
            [ "$SCORE" -gt 8500 ] && ((OVER8500++))
        fi

        printf "\rProgress: %d/%d" "$i" "$TESTS"
    done

    echo
}

print_header "EDGE CASES"

echo "[EMPTY]"
$PS

echo
echo "[ALREADY SORTED]"
test_case "1 2 3 4 5"

echo "[REVERSE SORTED]"
test_case "5 4 3 2 1"

echo "[SINGLE NUMBER]"
test_case "42"

echo "[TWO SORTED]"
test_case "1 2"

echo "[TWO REVERSED]"
test_case "2 1"

echo "[THREE NUMBERS]"
test_case "2 3 1"

echo "[FOUR NUMBERS]"
test_case "4 2 1 3"

echo "[FIVE NUMBERS]"
test_case "5 1 4 2 3"

echo "[NEGATIVES]"
test_case "-5 -9 12 0 42"

echo "[INT LIMITS]"
test_case "-2147483648 2147483647 0"

print_header "NEARLY SORTED"

test_case "1 2 3 4 5 6 7 8 10 9"
test_case "1 2 3 4 5 7 6 8 9 10"

random_tests 3 100
random_tests 5 100
random_tests 10 100
random_tests 50 200
random_tests 100 1000
random_tests 500 200
bench_test()
{
    SIZE=$1

    ARG=$(shuf -i 0-999999 -n $SIZE | tr '\n' ' ')
    SCORE=$(./push_swap --bench $ARG | wc -l)

    echo "$SIZE numbers"
    echo "Score : $SCORE"

    if [ "$SIZE" -eq 100 ]; then
        [ "$SCORE" -le 700 ] && echo "<=700 PASS"
        [ "$SCORE" -gt 700 ] && [ "$SCORE" -le 900 ] && echo "<=900 PASS"
        [ "$SCORE" -gt 900 ] && [ "$SCORE" -le 1100 ] && echo "<=1100 PASS"
        [ "$SCORE" -gt 1100 ] && echo ">1100 FAIL"
    fi

    if [ "$SIZE" -eq 500 ]; then
        [ "$SCORE" -le 5500 ] && echo "<=5500 PASS"
        [ "$SCORE" -gt 5500 ] && [ "$SCORE" -le 7000 ] && echo "<=7000 PASS"
        [ "$SCORE" -gt 7000 ] && [ "$SCORE" -le 8500 ] && echo "<=8500 PASS"
        [ "$SCORE" -gt 8500 ] && echo ">8500 FAIL"
    fi

    echo
}
print_header "BENCH TESTS"

bench_test 100
bench_test 500

print_header "STATISTICS"

echo "Tests performed : $COUNT"
echo "Average         : $AVG"
echo "Best            : $BEST"
echo "Worst           : $WORST"

echo
echo "100 NUMBERS"
echo ">700  : $OVER700"
echo ">900  : $OVER900"
echo ">1100 : $OVER1100"

echo
echo "500 NUMBERS"
echo ">5500 : $OVER5500"
echo ">7000 : $OVER7000"
echo ">8500 : $OVER8500"

print_header "VALGRIND"
valgrind --leak-check=full ./push_swap " "
valgrind --leak-check=full ./push_swap 1 2 2
valgrind --leak-check=full ./push_swap --1
valgrind --leak-check=full ./push_swap 2147483648

valgrind \
--leak-check=full \
--show-leak-kinds=all \
--error-exitcode=1 \
$PS 5 4 3 2 1 > /dev/null

if [ $? -eq 0 ]; then
    echo "No leaks detected"
else
    echo "Leaks detected"
fi

echo
echo "Evaluation complete"