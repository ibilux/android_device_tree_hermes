#!/bin/sh
rootdirectory="$PWD"
dirs="frameworks/av frameworks/base frameworks/native system/core system/netd system/sepolicy"

for dir in $dirs ; do
	cd $rootdirectory
	cd $dir
    echo "Applying $dir patches..."
	git apply $rootdirectory/device/xiaomi/hermes/patches/$dir/*.patch
done

echo "Done!"
cd $rootdirectory
