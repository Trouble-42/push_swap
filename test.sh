{
    SUM=0
    MIN=999999
    MAX=0
    OVER=0

    for i in $(seq 1 2); do
        ARG=$(shuf -i 0-9999 -n 100 | paste -sd' ' -)
        SCORE=$(./push_swap $ARG | wc -l)

        echo "Test $i : $SCORE"

        SUM=$((SUM + SCORE))
        [ $SCORE -lt $MIN ] && MIN=$SCORE
        [ $SCORE -gt $MAX ] && MAX=$SCORE
        [ $SCORE -gt 5500 ] && OVER=$((OVER + 1))
    done

    echo
    echo "Average     : $(awk "BEGIN {printf \"%.2f\", $SUM/2}")"
    echo "Best        : $MIN"
    echo "Worst       : $MAX"
    echo "> 5500      : $OVER/2"
    echo "Percentage  : $(awk "BEGIN {printf \"%.2f\", ($OVER*100)/2}")%"
} | tee results2.txt