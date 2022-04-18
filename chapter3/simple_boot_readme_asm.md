# Simple Boot Sector with Assembler
This example shows how to generate a simple boot sector with assembly instructions

## Generating the boot sector binary file

Run the below command to generate the boot sector binary to run on `x86_64` machines.
```
$ nasm boot sect.asm -f bin -o boot sect.bin
```
+ Option `-f bin`: option to instruct `nasm` to produce raw machine code

## Emulating on Qemu

Run the following command to emulate running the boot binary on x86_64 systems:
```
$ qemu-system-x86_64 boot_sector.bin
```

+ This time we don't give any storage device preference to run the code from.