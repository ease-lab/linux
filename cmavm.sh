#!/bin/bash
qemu-system-x86_64 -enable-kvm -kernel arch/x86_64/boot/bzImage -initrd ../pagewalk/initramfs.img -m 1G -append " cma=300M" 
