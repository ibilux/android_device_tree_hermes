#!/bin/sh

rootdirectory="$PWD"
dirs="bionic build/make/core build/soong frameworks/av frameworks/base frameworks/native frameworks/opt/telephony hardware/interfaces hardware/ril packages/apps/Settings system/core system/sepolicy"

for dir in $dirs ; do
	cd $rootdirectory
	cd $dir
	echo "Cleaning $dir patches..."
	git checkout -- . && git clean -df
done

echo "Done!"
cd $rootdirectory
