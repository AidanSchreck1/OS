# Operating System Project

By: Aidan Schreck

This initial commit includes three folders. The readelf folder is meant for my own ELF experimentation. The kernel folder is for kernel module experimentation. These have no direct connection to my OS.

The actual OS that im building is all within the folder bootloader. This folder holds the file structure that I'm using for my OS development . This folder also includes a sample.asm file that will eventually become my kernel. At the moment of this commit all the bootloader does is print "Welcome to my Operating System" in yellow to the screen. And my basic kernel - "sample.asm" copies 1 into the eax register then adds 1 to it.

Im running this OS in QEMU and debugging with gdb.
