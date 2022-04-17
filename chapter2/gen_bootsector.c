#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BOOTSECTOR_FILENAME     "boot_sector.bin"
#define BOOTSECTOR_SIZE_BYTES   512U
#define BOOTSECTOR_MAGICNUM_LSB 0x55
#define BOOTSECTOR_MAGICNUM_MSB 0xAA

/**
 * @brief A very simple Boot Sector 
 * @note: First three bytes are machine instructions, to perform an endless jump on x86 machines
 * @note: Last two bytes represent the Boot Sector Magic Number 0xaa55 that identify a BIOS boot block
 * @note: In between bytes represent zero padding to have the magic number at the end of the boot sector file
 */
uint8_t boot_sector[BOOTSECTOR_SIZE_BYTES] = {
    [0] = 0xe9,
    [1] = 0xfd,
    [2] = 0xff,
    [BOOTSECTOR_SIZE_BYTES-2] = BOOTSECTOR_MAGICNUM_LSB,
    [BOOTSECTOR_SIZE_BYTES-1] = BOOTSECTOR_MAGICNUM_MSB,
};

int main() {

    FILE *fptr = fopen(BOOTSECTOR_FILENAME,"wb");
    if(fptr == NULL)
    {
        fprintf(stderr, "Can't open file for writing \n");
        return 1;
    }
    fwrite(boot_sector, 1, sizeof(boot_sector), fptr);
    fclose(fptr);
    return 0;
}