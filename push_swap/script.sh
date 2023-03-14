#!/bin/bash
seed1001=2818571723
seed1002=2262684586
seed1003=2818514795
seed1004=3313617173
seed1005=2362838860
#
seed5001=576435059
seed5002=3840795785
seed5003=1179992518
seed5004=2237469931
seed5005=973388254
make re
echo "---------------FIRST MAKE------------------"
echo "---------------TEST 01------------------"
./push_swap_tester/complexity -s $seed1001 100 10000 1100
./push_swap_tester/complexity -s $seed5001 500 1000 8500
echo "---------------TEST 02------------------"
./push_swap_tester/complexity -s $seed1002 100 10000 1100
./push_swap_tester/complexity -s $seed5002 500 1000 8500
echo "---------------TEST 03----------------"
./push_swap_tester/complexity -s $seed1003 100 10000 1100
./push_swap_tester/complexity -s $seed5003 500 1000 8500
echo "---------------TEST 04----------------"
./push_swap_tester/complexity -s $seed1004 100 10000 1100
./push_swap_tester/complexity -s $seed5004 500 1000 8500
echo "---------------TEST 05----------------"
./push_swap_tester/complexity -s $seed1005 100 10000 1100
./push_swap_tester/complexity -s $seed5005 500 1000 8500
echo "-----------------END----------------"
make re
echo "---------------SECOND MAKE------------------"
echo "---------------TEST 01------------------"
./push_swap_tester/complexity -s $seed1001 100 10000 1100
./push_swap_tester/complexity -s $seed5001 500 1000 8500
echo "----------------TEST 02----------------"
./push_swap_tester/complexity -s $seed1002 100 10000 1100
./push_swap_tester/complexity -s $seed5002 500 1000 8500
echo "----------------TEST 03----------------"
./push_swap_tester/complexity -s $seed1003 100 10000 1100
./push_swap_tester/complexity -s $seed5003 500 1000 8500
echo "----------------TEST 04---------------"
./push_swap_tester/complexity -s $seed1004 100 10000 1100
./push_swap_tester/complexity -s $seed5004 500 1000 8500
echo "----------------TEST 05---------------"
./push_swap_tester/complexity -s $seed1005 100 10000 1100
./push_swap_tester/complexity -s $seed5005 500 1000 8500
echo "-----------------END------------------"
