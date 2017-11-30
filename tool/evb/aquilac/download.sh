#!/bin/bash

if [ $# -lt 1 -o $# -gt 2 ]; then
    echo ""
    echo "******************************************************"
    echo "USAGE: $0 file_name [running_addr]"
    echo "e.g. : $0 build/aquila_evb/img/example/aquila_evb_example_test.bin [0x00000000]"
    echo "******************************************************"
    echo ""
    exit 1;
fi

DOWNLOAD_BUFFER_SIZE=$((256*1024*1024))

file_name=$1
if [ ! -f ${file_name} ]; then
    echo ""
    echo "******************************************************"
    echo "WARNING:"
    echo "${file_name} does not exist!"
    echo "******************************************************"
    echo ""
    exit 1;
fi

file_size=`ls -l ${file_name} | awk '{ print $5 }'`
if [ ${file_size} -gt ${DOWNLOAD_BUFFER_SIZE} ]; then
    echo ""
    echo "******************************************************"
    echo "WARNING:"
    echo "the size of ${file_name} exceeds the max buffer size"
    echo "${file_size} > ${DOWNLOAD_BUFFER_SIZE}"
    echo "you should use burn.sh instead"
    echo "******************************************************"
    echo ""
    exit 1;
elif [ ${file_size} -eq 0 ]; then
    echo ""
    echo "******************************************************"
    echo "WARNING:"
    echo "the size of ${file_name} is 0"
    echo "download.sh does not support to download a empty file"
    echo "******************************************************"
    echo ""
    exit 1;
fi

if [ $# == 1 ]; then
    running_addr=0x00000000
else
    running_addr=$2
fi

base_dir=$(cd "$(dirname "$0")";pwd)

echo ""
echo "******************************************************"
echo "file_name   :" ${file_name}
echo "file_size   :" ${file_size}
echo "running_addr:" ${running_addr}
echo "pwd         :" $PWD
echo "base_dir    :" ${base_dir}
echo "******************************************************"
echo ""

sudo ${base_dir}/aimgtool cmd -c DWLD -m 1 -n spl -i ${base_dir}/sdl.pak
sudo ${base_dir}/aimgtool cmd -c DWLD -d ${running_addr} -m 1 -n cache -i ${file_name}
