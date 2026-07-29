#define hook-stop
#	#translate the segment:offset into a physical address
#	printf "[%4x:%4x] ", $cs, $eip
#	x/i $cs*16+$eip
#end
#intel syntax
set disassembly-flavor intel
#set to 16-bit
set architecture i8086
target remote localhost:26000
#where out bootloader code starts
break *0x7c00
# break *0x7c3c
# break *0x7c2a
# break *0x7c27
layout asm
layout reg

