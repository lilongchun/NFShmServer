mkdir Build
cd Build
mkdir Lib

mkdir build64_debug
cd build64_debug
rm * -rf

cmake -Wno-dev -DCMAKE_BUILD_TYPE=Debug  ../..
make -j4
