current_directory=$(cd `dirname $0`;pwd)

binary_name=myprocess

binary_direcory=${current_directory}/bin
if [ -d ${binary_direcory} ]; then
    cd ${binary_direcory}
    ./${binary_name} 400 $@
else
    echo ${binary_direcory} is not exist!!!!
fi