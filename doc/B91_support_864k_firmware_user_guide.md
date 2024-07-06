## software settings

set FIRMWARE_SIZE_EXCEED_512K_EN to 1, which locates at firmware\vendor\mesh\app_config_B91.h.

## compile projects

compile B91_mesh project to generate B91_mesh.bin

compile B91_bootloader project to generate B91_bootloader.bin

## burning firmware

burning B91_mesh.bin to flash address 0x0000 through BDT tool.

burning B91_bootloader.bin to flash address 0x10000 through BDT tool.

then reboot, then it works.

## flash map

please refer to doc\SIGMeshFlashmap_20240628.xlsx: sheet "SIGMeshB91m2M".

or refer to blt_config.h.

