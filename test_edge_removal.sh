#!/bin/bash 
make
echo "Runnning DVRP"  
./main.exe < test_cases/testcase_dvrp_with_removal.txt > output/output_dvrp_with_removal.txt
echo "Runnning LSRP"  
./main.exe < test_cases/testcase_lsrp_with_removal.txt > output/output_lsrp_with_removal.txt