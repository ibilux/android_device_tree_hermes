#!/bin/sh

rootdirectory="$PWD"
dirs="frameworks/av frameworks/base frameworks/opt/telephony packages/apps/FMRadio system/core"

for dir in $dirs ; do
	cd $rootdirectory
	cd $dir
	echo "Cleaning $dir patches..."
	git checkout -- . && git clean -df
done

echo "Done!"
cd $rootdirectory
