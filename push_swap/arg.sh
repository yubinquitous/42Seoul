export ARG=$(./random_numbers 500)
./push_swap $ARG
echo $ARG
#./push_swap $ARG | ./checker_Mac $ARG
#./push_swap $ARG | wc -l
