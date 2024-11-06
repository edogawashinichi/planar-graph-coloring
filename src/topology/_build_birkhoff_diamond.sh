#!/bin/bash

echo "start building..."

obj_path="../../obj/"
if [ ! -d ${obj_path} ]; then
  echo "mkdir ${obj_path}"
  mkdir ${obj_path}
fi

test_path="./"
test_file=${test_path}"_test_birkhoff_diamond.cxx"
parameter=""
if [ $# -ge 1 ]; then
  parameter=$1
fi
obj_suf=".o"
obj_file=${obj_path}${test_file:2:-4}${obj_suf}

echo "test file: ${test_file}"
echo "obj file: ${obj_file}"

if [ -f ${obj_file} ]; then
  echo "remove ${obj_file}"
  rm ${obj_file}
fi

src_path="./"
algebra_src_path="../algebra/"
basic_src_path="../basic/"
# gtest requires at least C++14
# O2 optmization may modify primary output, turn off for debug purpose
# -Wall : force to give an error when forgetting to return a value
g++ -Wall -std=c++17 -o ${obj_file} -cpp ${test_file} ${src_path}birkhoff_diamond.cxx ${src_path}ring.cxx ${basic_src_path}graph.cxx ${algebra_src_path}symmetry.cxx ${basic_src_path}global.cxx

if [ -f ${obj_file} ]; then
  echo "${obj_file} generated!"
else
  echo "fail to generate ${obj_file}!"
fi

./${obj_file} ${parameter}

echo "end running..."
