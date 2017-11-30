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

MAX_EMMC_PARTITION_SIZE=$((2*1024*1024*1024))

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
if [ ${file_size} -gt ${MAX_EMMC_PARTITION_SIZE} ]; then
    echo ""
    echo "******************************************************"
    echo "WARNING:"
    echo "the size of ${file_name} exceeds the max emmc size"
    echo "${file_size} > ${MAX_EMMC_PARTITION_SIZE}"
    echo "burn.sh does not support to burn a too large file"
    echo "******************************************************"
    echo ""
    exit 1;
elif [ ${file_size} -eq 0 ]; then
    echo ""
    echo "******************************************************"
    echo "WARNING:"
    echo "the size of ${file_name} is 0"
    echo "burn.sh does not support to burn a empty file"
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

orig_addr=`awk '$1~/sloader/{print $4}' ${base_dir}/testkeys/secureboot/rtpk.cfg`
echo "orignal running addr:"${orig_addr}
if [ ${orig_addr} != ${running_addr} ]; then

    # modify the load address of the sloader entry, and save it as a tmp file
    awk '$1~/sloader/{$4="'${running_addr}'"}1' ${base_dir}/testkeys/secureboot/rtpk.cfg 1<>${base_dir}/testkeys/secureboot/rtpk.cfg.tmp

    ###
    ### NOTE:
    ### there is a bug when test(not always):
    ### the line number of rtpk.cfg.tmp will be one line more than rtpk.cfg
    ### so, cut the last one line of rtpk.cfg.tmp and then save it as rtpk.cfg
    ###
    lines=`awk '{print NR}' ${base_dir}/testkeys/secureboot/rtpk.cfg|tail -n1`
    echo "line number of rtpk.cfg:"${lines}

    tmplines=`awk '{print NR}' ${base_dir}/testkeys/secureboot/rtpk.cfg.tmp|tail -n1`
    echo "line number of rtpk.cfg.tmp:"${tmplines}

    if [ ${lines} -lt ${tmplines} ]; then
        delete_start=`expr ${lines} + 1`
        echo "delete start:"${delete_start}
        # cut the last lines
        sed -i ${delete_start}',$d' ${base_dir}/testkeys/secureboot/rtpk.cfg.tmp
        tmplines=`awk '{print NR}' ${base_dir}/testkeys/secureboot/rtpk.cfg.tmp|tail -n1`
        echo "new line number of rtpk.cfg.tmp:"${tmplines}
    elif [ ${lines} -gt ${tmplines} ]; then
        echo "TODO:"
    fi

    cp ${base_dir}/testkeys/secureboot/rtpk.cfg.tmp ${base_dir}/testkeys/secureboot/rtpk.cfg
    rm ${base_dir}/testkeys/secureboot/rtpk.cfg.tmp
fi

orig_dir=`awk '$1~/imgdir/{print $3}' ${base_dir}/ctest_table.cfg`
echo "orignal dir:"${orig_dir}
if [ ${orig_dir} != ${base_dir} ]; then

    # modify the imgdir in ctest_table.cfg, and save it as a tmp file
    awk '$1~/imgdir/{$3="'${base_dir}'"}1' ${base_dir}/ctest_table.cfg 1<>${base_dir}/ctest_table.cfg.tmp

    ###
    ### NOTE:
    ###
    lines=`awk '{print NR}' ${base_dir}/ctest_table.cfg|tail -n1`
    echo "line number of ctest_table.cfg:"${lines}

    tmplines=`awk '{print NR}' ${base_dir}/ctest_table.cfg.tmp|tail -n1`
    echo "line number of ctest_table.cfg.tmp:"${tmplines}

    if [ ${lines} -lt ${tmplines} ]; then
        delete_start=`expr ${lines} + 1`
        echo "delete start:"${delete_start}
        # cut the last lines
        sed -i ${delete_start}',$d' ${base_dir}/ctest_table.cfg.tmp
        tmplines=`awk '{print NR}' ${base_dir}/ctest_table.cfg.tmp|tail -n1`
        echo "new line number of ctest_table.cfg.tmp:"${tmplines}
    elif [ ${lines} -gt ${tmplines} ]; then
        echo "TODO:"
    fi

    cp ${base_dir}/ctest_table.cfg.tmp ${base_dir}/ctest_table.cfg
    rm ${base_dir}/ctest_table.cfg.tmp
fi

orig_partition_size=`awk '$1~/^sloader$/{print $2}' ${base_dir}/ctest_table.cfg`
echo "orignal partition size:"${orig_partition_size}"MB"
if [ $(( ${orig_partition_size} * 1024 * 1024 )) -lt ${file_size} ]; then
    ###
    ### round_ceil_N(x)= ((((x) + (N-1)) / N ) * N)
    ###
    align=1 ### 1MB alignment
    expand_partition_size=$(( (${file_size}+(${align}*1024*1024-1))/(${align}*1024*1024)*${align} ))
    echo "expand emmc partition size to "${expand_partition_size}"MB"

    # modify the sloader in ctest_table.cfg, and save it as a tmp file
    awk '$1~/^sloader$/{$2="'${expand_partition_size}'"}1' ${base_dir}/ctest_table.cfg 1<>${base_dir}/ctest_table.cfg.tmp

    ###
    ### NOTE:
    ###
    lines=`awk '{print NR}' ${base_dir}/ctest_table.cfg|tail -n1`
    echo "line number of ctest_table.cfg:"${lines}

    tmplines=`awk '{print NR}' ${base_dir}/ctest_table.cfg.tmp|tail -n1`
    echo "line number of ctest_table.cfg.tmp:"${tmplines}

    if [ ${lines} -lt ${tmplines} ]; then
        delete_start=`expr ${lines} + 1`
        echo "delete start:"${delete_start}
        # cut the last lines
        sed -i ${delete_start}',$d' ${base_dir}/ctest_table.cfg.tmp
        tmplines=`awk '{print NR}' ${base_dir}/ctest_table.cfg.tmp|tail -n1`
        echo "new line number of ctest_table.cfg.tmp:"${tmplines}
    elif [ ${lines} -gt ${tmplines} ]; then
        echo "TODO:"
    fi

    cp ${base_dir}/ctest_table.cfg.tmp ${base_dir}/ctest_table.cfg
    rm ${base_dir}/ctest_table.cfg.tmp
fi

cp ${file_name} ${base_dir}/sloader.img
sudo ${base_dir}/aimgtool signall -c ${base_dir}/testkeys/secureboot/rtpk.cfg -k ${base_dir}/testkeys/secureboot -i ${base_dir}
sudo ${base_dir}/aimgtool download -t ${base_dir}/ctest_table.cfg
