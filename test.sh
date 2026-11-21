ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
./push_swap $ARG | grep -cE '^(sa|sb|ss|pa|pb|ra|rb|rr|rra|rrb|rrr)$'
