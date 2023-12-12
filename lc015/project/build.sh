current_directory=$(cd `dirname $0`;pwd)
echo $current_directory

build_directory=${current_directory}/build

if [ -d ${build_directory} ]; then
    echo ${build_directory} is exist!!!!
    rm -r ${build_directory}
fi

mkdir ${build_directory}
cd ${build_directory}

cmake ..

cpu_count=`cat /proc/cpuinfo| grep "processor"| wc -l`
use_count=$(($cpu_count - 2))
echo "make -j$use_count"
make -j$use_count

binary_direcory=${current_directory}/bin
if [ -d ${binary_direcory} ]; then
    echo ${binary_direcory} is exist!!!!
else
    mkdir ${binary_direcory}
fi

cp -r ${build_directory}/* ${binary_direcory}

rm -r ${build_directory}

