#!/bin/sh

rootdirectory="$PWD"
dirs="frameworks/av frameworks/base frameworks/native frameworks/opt/telephony hardware/interfaces packages/apps/FMRadio system/core system/netd"

for dir in $dirs ; do
	cd $rootdirectory
	cd $dir
	echo "Cleaning $dir patches..."
	git checkout -- . && git clean -df
done

echo "Done!"
cd $rootdirectory
