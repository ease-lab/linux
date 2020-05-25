#!/bin/bash
qemu-system-x86_64 -enable-kvm -kernel arch/x86_64/boot/bzImage -initrd initramfs.img -m 1G -append "cma=400M" 
