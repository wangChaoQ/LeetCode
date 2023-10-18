#!/bin/bash
current_directory=$(cd `dirname $0`;pwd)
# echo $current_directory

folders=()
while IFS= read -r -d '' folder; do
    folder_name=$(basename "$folder")
    if [[ "$folder_name" != "." ]] && ! [[ "$folder_name" =~ ^\. ]]; then
        folders+=("$folder_name")
    fi
done < <(find . -maxdepth 1 -type d -not -name '.' -print0 | grep -zv '^\./\.')

# 打印文件夹变量
for folder in "${folders[@]}"; do
    # echo "$folder"
    binary_direcory=${folder}/project/bin/
    if [ -d ${binary_direcory} ]; then
        cd ${binary_direcory}
        rm -r ./*
    else
        echo "This directory does not exist"
    fi
    # cd ${current_directory}
done



