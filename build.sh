#!/bin/bash
set -e


BUSYBOX_VERSION=1.35.1
KERNEL_VERSION=5.19.8
CORES=6

mkdir -p src
cd src
    KERNEL_MAJOR=$(echo $KERNEL_VERSION | sed 's/\([0-9]*\)[^0-9].*/\1/')

    # Install busybox, and the linux kernel.
    wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-$KERNEL_VERSION.tar.xz
    wget https://busybox.net/downloads/busybox-$BUSYBOX_VERSION.tar.bz2

    # Extract the files.
    tar -xf  linux-$KERNEL_VERSION.tar.xz
    tar -xf busybox-$BUSYBOX_VERSION.tar.bz2
    # Compile the kernel.
    cd linux-$KERNEL_VERSION
        make defconfig
        make -j$CORES || exit
    cd ..

    # Compile busybox.
    cd busybox-$BUSYBOX_VERSION.tar.bz2
        make defconfig
        sed 's/^.$CONFIG_STATIC.*$/CONFIG_STATIC=y/g' -i .config
        make -j$CORES || exit
    cd ..

cd ..

set +e