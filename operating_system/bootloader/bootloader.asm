;***********************************************
; bootloader.asm
; A Simple Bootloader
;**********************************************
global start
;org 0x7c00 ; origin command, sets the starting memory location for the code that follows it
bits 16 ; tells the assembler to generate 16bit real-mode machine code
start: jmp boot ; start is a label that is replaced with a mem adress at assemble time

;; constant and variable definitions
msg db "Welcome to my Operating System", 0h

%include "io.asm"

boot: ; boot label, this is replaced with its current address
	cli ; no interrupts
	cld ; all that we need to init
	;;**************print message****************
	xor ax, ax
	mov ds, ax

	mov si, msg
	call Print 
	;;*******************************************

	;*************read from 2nd sector**********
	; mov ch, 0x00 ; track 0
	; mov cl, 0x02 ; sector to read (second sector)
	; mov dh, 0x00 ; head number
	; mov dl, 0x00 ; drive number

	; mov ah, 0x02 ; read sectors from disk
	; int 0x13 ; call the BIOS Routine
	; the buffer is composed of the es:bx reg where es is the segment and bx is the offset

	mov ax, 0x50
	;;set the buffer
	mov es, ax
	xor bx, bx ; this is the buffer for loading the sector into memory. 
	mov ah, 0x02 ; read sectors from disk (paired with int 13h)
	mov al, 0x01 ; read 1 sectors
	mov ch, 0x00 ; track 0
	mov cl, 0x02 ; sector to read (second sector)
	mov dh, 0x00 ; head number
	mov dl, 0x00 ; drive number

	int 0x13 ; call the BIOS Routine
	jmp 0x50:0x0 ; jump and execute the sector! address 0x500
	;******************************************


	hlt ; halt the system

; We have to be 512 bytes. Clear the rest of te bytes with 0
times 510 - ($-$$) db 0 
dw 0xAA55	; Boot Signature
