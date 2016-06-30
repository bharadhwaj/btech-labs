.model small
.stack 100h
.data
	msg1 db 10, "Enter the number: $"
	msg2 db 10, "The series is: $"
	space db 32,"$"
	n1 db ?
	n2 db ?	
	
.code
	mov ax, @data
	mov ds, ax
	
	mov ah, 09h
	lea dx, msg1
	int 21h

	mov ah, 01h
	int 21h
	mov n1, al
	int 21h
	mov n2, al

	mov ah, 09h
	lea dx, msg2
	int 21h

	mov dh, n1
	mov bl, n2
	
	mov cl, 09h
	mov dl, dh
	mov ah, 02h
	int 21h
	mov dl, bl
	int 21h

	mov n1, dl
	mov n2, dh
	mov ah, 09h
	lea dx, space
	int 21h
	mov dl, n1
	mov dh, n2	

	loop1:			
		cmp bl, 39h
		je loop2
		mov dl, dh
		mov ah, 02h
		int 21h
		inc bl
		mov dl, bl
		mov ah, 02h
		int 21h	

		mov n1, dl
		mov n2, dh
		mov ah, 09h
		lea dx, space
		int 21h
		mov dl, n1
		mov dh, n2	


		loop loop1 
		jmp loop3
			

	loop2:	
		inc dh
		mov bl, 30h
		mov dl, dh			
		mov ah, 02h
		int 21h
		mov dl, bl
		mov ah, 02h
		int 21h
		
		mov n1, dl
		mov n2, dh
		mov ah, 09h
		lea dx, space
		int 21h
		mov dl, n1
		mov dh, n2	

		loop loop1
		
	loop3: 
		mov ax, 4c00h
		int 21h
end