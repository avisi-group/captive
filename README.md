# captive
The Captive Hypervisor

Captive only works on Linux with KVM support.  You will need to have the appropriate permissions
on the `/dev/kvm` device to use it.

## Getting started
Check out the repository and compile:

    $ git clone https://github.com/tspink/captive
    $ cd captive
    $ make

You will get a bunch of warnings about variables that are set but not used - these come from the
auto-generated DBT/JIT compiler, and are harmless.

This should have built the captive hypervisor executable, configured for AArch64 virtualisation as `captive/bin/captive`

## Kernel and User-space
You will also need an AArch64 kernel and user-space to try running with.

### Kernel
You can build a Linux kernel from source quite easily:

    $ git clone git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git
    $ cd linux
    $ git checkout v5.2
    $ export ARCH=arm64
    $ make defconfig
    $ make
    
Which should have built `arch/arm64/boot/Image`.  Alternatively, you can download an example kernel from:

https://groups.inf.ed.ac.uk/card-project/captive/arm64-kernel-image (approx. 25 Mb)

### User-space
The user-space is provided to the guest operating system as a block device, so captive requires a file that
represents the contents of the block device.

Captive has been tested with an Arch Linux Arm64 userspace, but also with a lighter buildroot-based
userspace.

It would not be feasible to host a full user-space image, so please consult the appropriate guides from
e.g. https://archlinuxarm.org/platforms/armv8/generic for a fully fledged user-space, or from here
https://buildroot.org/ for a lightweight userspace.

You should end up with a single file representing a block device that contains a file system containing
a user-space.

## Running Captive
Once you have built captive, have your Linux kernel and arm64 userspace, you can run captive with the
following command (assuming you're in the top of the captive build directory).

    $ bin/captive --block-dev-file <PATH TO BLOCK DEVICE FILE> \
    --engine arch/aarch64.arch \
    --device-tree ./captive-platform.dtb \
    --kernel <PATH TO KERNEL IMAGE> \
    --platform virt

This will start captive with the provided userspace in the block device, and by booting the provided
Linux kernel.  The device tree is a stripped down tree that includes a virtio block device and network
device.

See the next section for how to use the network.

## Networking
Captive can support networking by means of a TAP device.

To boot with networking support, two more command-line options need to be added:

    --mac-address 020000000001 \
    --tap-device <NAME OF TAP DEVICE>

### Setting up a TAP device
Coming soon: a helper script!
