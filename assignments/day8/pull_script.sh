#!/bin/bash
echo "cloning repo"
git clone https://github.com/SubspaceBob/cpp_bootcamp.git
echo "cloning done, will now change dir"
cd "cpp_bootcamp/assignments/day5"
make
./Shapy
echo "Rock n Roll! "

