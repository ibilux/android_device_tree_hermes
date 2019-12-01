#!/bin/sh

rootdirectory="$PWD"
dirs="bionic build/make/core build/soong frameworks/av frameworks/base frameworks/opt/telephony hardware/interfaces hardware/ril system/core"

RED='\033[0;31m'
NC='\033[0m'

for dir in $dirs ; do
	cd $rootdirectory
	cd $dir
	echo -e "${RED}Applying ${NC}$dir ${RED}patches...${NC}\n"
	git apply -v --check $rootdirectory/device/xiaomi/hermes/patches/$dir/*.patch
done

# -----------------------------------
echo -e "Done !\n"
cd $rootdirectory

