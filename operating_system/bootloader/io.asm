; io.asm A simple I/O library move a cursor to a specifc location and remmeber this location
;initialize the x and y cords at 0,0
;bh and bl are parameters, y and x
MovCursor:
	;mov dh, bh
	;mov dl, bl
	mov ah, 0x03
	int 0x10
	inc dl
	mov ah, 0x02 ; set the cursor for the interrupt - treated as arguments
	int 0x10 ; call BIOS video interrupt
	ret ; return to caller

; print a char on screen at the cursor pos prev set by MovCursor
; parameters: al - character to print, bl, text color, cx - # times char is repeated
PutChar:
	int 0x10 ;
	call MovCursor
	ret


; print a string
; parameters: ds:si = zero terminated string
Print:
	lodsb ; load string byte - al = [ds:si] then si++
	or al, al ; check if al == 0, the null terminator 
	; remember al is the place you store the character for the PutChar routine above
	mov bl, 0x0E ; COLORRRR
	mov cx, 0x01 ; print it just once
	mov bh, 0x00 ; page number (?)
	jz .done ; jump if zero flag is 0
	mov ah, 0x09
	call PutChar
	jmp Print
.done:
	ret
