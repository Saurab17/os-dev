# Boot Sector Programming in 16 bit Real Mode

## 3.1 Simple Boot Sector with Assembly
This example shows how to generate a simple boot sector with assembly instructions

### 3.1.1 Generating the boot sector binary file

Run the below command to generate the boot sector binary to run on `x86_64` machines.
```
$ nasm boot_sect.asm -f bin -o boot_sect.bin
```
+ Option `-f bin`: option to instruct `nasm` to produce raw machine code

### 3.1.2 Emulating on Qemu

Run the following command to emulate running the boot binary on x86_64 systems:
```
$ qemu-system-x86_64 boot_sector.bin
```

+ This time we don't give any storage device preference to run the code from.

## 3.2 Simple Boot Sector Hello with Assembly
This example shows how to write a simple boot sector that outputs hello on the screen

### 3.2.1 Generating the boot sector binary file
```
$ nasm boot_sect_hello.asm -f bin -o boot_sect_hello.bin
```
Then use qemu to emulate the boot sector on your machine