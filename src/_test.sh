#!/bin/bash

for path in $(ls); do
  if [ -f ${path} ]; then
    continue
  fi
  echo "path: ${path}"
  sudo chmod +x -R ${path}
  echo "chmod result: $?"
  cd ${path}
  for file in $(ls *.sh); do
    echo "file: ${file}"
    bash ${file}
  done
  # TODO: if folder
  cd ..
done
