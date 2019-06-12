num=$1
num=$num-1

ARG=`ruby -e "puts (0..$num).to_a.shuffle.join(' ')"`
echo $ARG
opers=`./push_swap $ARG | wc -l`
echo "OPERATIONS: $opers"
./push_swap $ARG | ./checker $ARG