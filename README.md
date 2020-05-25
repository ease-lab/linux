# Continuous page table entry allocation

Using continuous memory allocator (CMA) to allocate physically continued page to last level of page table i.e. page table entry (pte).

## Set Up Environment

### Download

Download the source code to local machine and all the dependencies for booting Linux kernel.

### Configuration

1. "make kvmconfig" 
2. "make menuconfig" or editing .config file directly - configure the following changes to enable continuous page table entry allocation
    - CMA  in x86-64

        CONFIG_CMA=y
        CONFIG_DMA_CMA =y
        CONFIG_CMA_DEBUG=y
        CONFIG_CMA_DEBUGFS=y
        
    - Retrieve PID

        CONFIG_MEMCG=y

3. "make" - compile the kernel

## Boot kernel with QEMU

```bash
qemu-system-x86_64 -kernel arch/x86_64/boot/bzImage -initrd <Initial ramdisk address> -m 1G -append "cma=400M"
```
Optionally one can append '-enable-kvm' (requiring root permission).

## Turn on allocation 

```bash
sysctl -w vm/continuous_pgtable_enable=1
```
