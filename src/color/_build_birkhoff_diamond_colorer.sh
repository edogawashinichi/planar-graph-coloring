#!/bin/bash

echo "start building..."

obj_path="../../obj/"
if [ ! -d ${obj_path} ]; then
  echo "mkdir ${obj_path}"
  mkdir ${obj_path}
fi

test_file="_test_birkhoff_diamond_colorer.cxx"
if [ $# -ge 1 ]; then
  test_file=$1
fi
obj_suf=".o"
obj_file=${obj_path}${test_file:0:-4}${obj_suf}

echo "test file: ${test_file}"
echo "obj file: ${obj_file}"

if [ -f ${obj_file} ]; then
  echo "remove ${obj_file}"
  rm ${obj_file}
fi

src_path="./"
topology_src_path="../topology/"
algebra_src_path="../algebra/"
basic_src_path="../basic/"
# gtest requires at least C++14
# O2 optmization may modify primary output, turn off for debug purpose
# -Wall : force to give an error when forgetting to return a value
g++ -Wall -std=c++17 -o ${obj_file} -cpp ${test_file} ${src_path}birkhoff_diamond_colorer.cxx ${src_path}color_result.cxx ${src_path}naive_color_representation.cxx ${topology_src_path}birkhoff_diamond.cxx ${topology_src_path}ring.cxx ${topology_src_path}graph.cxx ${algebra_src_path}symmetry.cxx ${basic_src_path}math.cxx
if [ -f ${obj_file} ]; then
  echo "${obj_file} generated!"
else
  echo "fail to generate ${obj_file}!"
fi

./${obj_file}

echo "end running..."
