#!/bin/bash

echo ""
echo "... MyLIB ..."
echo ""

mkdir mylib/build
cd mylib/build
cmake .. -DCMAKE_PREFIX_PATH=$1 -DCMAKE_INSTALL_PREFIX=$2
make && make install


echo ""
echo "... MyAPP ..."
echo ""

cd ../..
mkdir myapp/build
cd myapp/build
cmake .. -DCMAKE_PREFIX_PATH=$2
