# Simple Boot Sector

## Generating the boot sector binary file

Run the below command to generate the boot sector binary to run on `x86_64` machines.
```
$ gcc gen_bootsector.c
$ ./a.out
```

## Emulating on Qemu

Run the following command to emulate running the boot binary on x86_64 systems:
```
$ qemu-system-x86_64 -fda boot_sector.bin
```

### Description of the Qemu Emulation Options:

+ `-fda`:
    - -fda/-fdb file  use 'file' as floppy disk 0/1 image

### Emulating bad boot sector:

+ Change the value of `BOOTSECTOR_MAGICNUM` LSB or MSB macro to other than what is set in `gen_bootsector.c` 
+ Use the Qemu Emulation command above with the new bin file. 
+ Qemu should show that boot failed as no bootable device found.
