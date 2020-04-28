#!/bin/sh

echo $1
rootdirectory="$PWD"
# ---------------------------------

dirs="frameworks/av frameworks/base frameworks/native frameworks/opt/telephony hardware/interfaces packages/apps/FMRadio system/core system/netd"

# red + nocolor
RED='\033[0;31m'
NC='\033[0m'

for dir in $dirs ; do
	cd $rootdirectory
	cd $dir
    echo -e "\n${RED}Applying ${NC}$dir ${RED}patches...${NC}\n"
	git apply -v $rootdirectory/device/xiaomi/hermes/patches/$dir/*.patch
done

# -----------------------------------
echo -e "Done !\n"
cd $rootdirectory
