#!/bin/bash

for path in $(ls); do
  if [ -f ${path} ]; then
    continue
  fi
  echo "path: ${path}"
  cd ${path}
  for file in $(ls *.sh); do
    echo "file: ${file}"
    bash ${file}
  done
  cd ..
done
