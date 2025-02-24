#!/bin/bash

echo "start building..."

obj_path="../../obj/"
if [ ! -d ${obj_path} ]; then
  echo "mkdir ${obj_path}"
  mkdir ${obj_path}
fi

test_file="_test_ring_classification_interpreter.cxx"
parameter=""
if [ $# -ge 1 ]; then
  parameter=$1
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
color_src_path="../color/"
combinatorics_src_path="../combinatorics/"
permutator_src_path="../combinatorics/permutator/"
combinator_src_path="../combinatorics/combinator/"
basic_src_path="../basic/"
relation_src_path="../relation/"
operator_src_path="../operator/"
kempe_src_path="../color/kempe/"
# gtest requires at least C++14
# O2 optmization may modify primary output, turn off for debug purpose
# -Wall : force to give an error when forgetting to return a value
g++ -Wall -std=c++17 -o ${obj_file} -cpp ${test_file} ${algebra_src_path}permutation.cxx ${basic_src_path}global.cxx ${topology_src_path}birkhoff_diamond.cxx ${topology_src_path}ring.cxx ${topology_src_path}planar_graph.cxx ${basic_src_path}graph.cxx ${algebra_src_path}symmetry_group_generator.cxx ${permutator_src_path}next_iter_permutator.cxx ${combinator_src_path}gray_code_combinator.cxx ${basic_src_path}math.cxx

if [ -f ${obj_file} ]; then
  echo "${obj_file} generated!"
else
  echo "fail to generate ${obj_file}!"
fi

./${obj_file} ${parameter}

echo "end running..."
