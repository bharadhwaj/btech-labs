$.model small
.stack 100h
.data
     msg0a db 10, 10, "1:Addition  2:Subtraction  3:Multiplication  4:Division  5:Exit$"
     msg0b db 10, 10, "Enter your choice : $"
     msg1 db 10, "Enter the first number : $" ,10,10
     msg2 db 10, "Enter the second number : $"
     msg3 db 10, 10, "Sum  : $"
     msg4 db 10, 10, "Difference  : $"
     msg5 db 10, 10, "Product  : $"
     msg6 db 10, 10, "Quotient : $"
     msg7 db 10, 10, "Remainder : $"
     msg8 db 10, 10, "$"
     x db ?
     y db ?
     d1 db ?
     d2 db ?
     d3 db ?
     d4 db ?
.code
     main proc
	mov ax, @data
	mov ds, ax
	mov ah, 09h
	mov dx, offset msg1
	int 21h
	mov ah, 01h
	int 21h
	sub al, 30h
	mov bh, al
	mov ah, 01h
	int 21h
	sub al, 30h
	mov bl, al
	mov al, bh
	mov dl, 10
	mul dl
	add al, bl
	mov x, al

	mov ah, 09h
	mov dx, offset msg2
	int 21h
	mov ah, 01h
	int 21h
	sub al, 30h
	mov bh, al
	mov ah, 01h
	int 21h
	sub al, 30h
	mov bl, al
	mov al, bh
	mov dl, 10
	mul dl
	add al, bl
	mov y, al

	mov dx, offset msg0a
	mov ah, 09
	int 21h
	mov dx, offset msg0b
	mov ah, 09
	int 21h
	mov ah, 01
	int 21h

	cmp al, '1'
	je addition
	cmp al, '2'
	je subtraction
	cmp al, '3'
	je multiplication
	cmp al, '4'
	je division
	cmp al, '5'
	je ext1

        ext1:	
            mov ax, 4C00h
	int 21h

        addition:
            mov al, x
	add al, y
	mov dl, 100
	mov ah, 00
	div dl
	mov bl, al
	mov bh, ah
	mov ah, 09h
	mov dx, offset msg3
	int 21h
	call prnt

        subtraction:
	mov al, x
	sub al, y
	mov dl, 100
	 mov ah, 00
	 div dl
	 mov bl, al
	 mov bh, ah
	 mov ah, 09h
	 mov dx, offset msg4
	 int 21h
	 call prnt

        multiplication:
	 mov al, x
	 mov ah, y
	 mul ah
	 mov dl,100 
	 div dl
	 mov bl, al
	 mov bh, ah
	 mov ah, 09h
	 mov dx, offset msg5
	 int 21h
	 call prnt

        division:
	 mov al, x
	 mov ah, 00
	 div y
 	 mov ch, ah
	 mov cl, al
	 mov ah, 09h
	 mov dx, offset msg6
	 int 21h
	 mov al, cl
	 mov ah, 00
	 mov dl, 10
	 div dl
	 mov d1, al
	 add d1, 30h
	 mov d2, ah
	 add d2, 30h
	 mov ah, 02
	 mov dl, d1
	 int 21h
	 mov ah, 02
	 mov dl, d2
	 int 21h
	 mov ah, 09h
	 mov dx, offset msg7
	 int 21h
	 mov al, ch
	 mov ah, 00
	 mov dl, 10
	 div dl
	 mov d1, al
	 add d1, 30h
 	 mov d2, ah
	 add d2, 30h
	 mov ah, 02
	 mov dl, d1
	 int 21h
	 mov ah, 02
	 mov dl, d2
	 int 21h
	 jmp ext

        prnt:
	 mov al, bl
	 mov dl, 10
	 mov ah, 00
	 div dl
	 mov d4, ah
	 mov d3, al
	 mov al, bh
	 mov ah, 00
	 div dl
 	 mov d2, ah
 	 mov d1, al
	 add d4, 30h
	 add d3, 30h
	 add d2, 30h
	 add d1, 30h
	 mov ah, 02
	 mov dl, d3
	 int 21h
	 mov dl, d4
	 int 21h
       	 mov dl, d1
	 int 21h
	 mov dl, d2
	 int 21h

         ext:	
             mov ax,4C00h
	 int 21h
    main endp
end main                       
