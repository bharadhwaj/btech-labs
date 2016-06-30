.model small
.stack 100h
.data
	msg1 db 10,"Enter the first number: $"
	msg2 db 10,"Enter the second number: $"
	msg3 db 10,"The sum is $"
	x db ?
.code
	mov ax, @data
	mov ds, ax
	mov ah, 09h
	lea dx, msg1
	int 21h

	mov ah, 01h
	int 21h
	mov bl, al
	sub bl, 30h
	mov x, bl

	mov ah, 09h
	lea dx, msg2
	int 21h

	mov ah, 01h
	int 21h
	mov bl, al
	sub bl, 30h

	add x, bl
	mov bl, x
	mov ah, 00
	mov al,bl
	mov bl, 10
	div bl

	
	mov bx, ax
	
	mov ah, 09h
	lea dx, msg3
	int 21h
	
	mov dl,bl
	add dl, 30h
	mov ah, 02h
	int 21h
	
	mov dl,bh
	add dl, 30h
	mov ah,02
	int 21h
	
	mov ax, 4c00h
	int 21h
end