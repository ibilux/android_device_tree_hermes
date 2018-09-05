#!/bin/sh
rootdirectory="$PWD"
dirs="frameworks/av frameworks/base frameworks/native system/core system/netd system/sepolicy packages/apps/FMRadio"

for dir in $dirs ; do
	cd $rootdirectory
	cd $dir
	echo "Cleaning $dir patches..."
	git checkout -- . && git clean -df
done

echo "Done!"
cd $rootdirectory
