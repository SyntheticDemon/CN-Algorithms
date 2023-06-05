#!/bin/bash 
make
echo "Runnning DVRP"  
./main.exe < test_cases/testcase_dvrp.txt > output/output_dvrp.txt
echo "Runnning LSRP"  
./main.exe < test_cases/testcase_lsrp.txt > output/output_lsrp.txt