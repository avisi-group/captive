#!/usr/bin/env bash
set -e

# Create the kvm node (required --privileged)
if [ ! -e /dev/kvm ]; then
   mknod /dev/kvm c 10 $(grep '\<kvm\>' /proc/misc | cut -f 1 -d' ')
fi

./captive --block-dev-file ./rootfs.ext2 \
    --engine ./arm64.arch \
    --device-tree ./captive-platform.dtb \
    --kernel ./kernel \
    --platform virt
