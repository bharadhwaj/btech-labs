.model small
.stack 100h
.data
     msg1 db 10, "Enter a string : $"
     msg2 db 10, 10, "The modified string is : $"
     arr db 40 dup(?)
.code
     main proc
         mov ax, @data
         mov ds, ax
         mov si, 00
         mov di, 00
         mov dx, offset msg1
         mov ah, 09
         int 21h

         rd:
             mov ah, 01
             int 21h
             cmp al,13
             je wr
             cmp al, ' '
             je op
             mov arr[di], al
             inc di
             loop rd

        op:
             dec di
             mov arr[di], 'A'
             inc di
             mov arr[di], ' '
             inc di
             jmp rd

        wr:
            dec di
            mov arr[di], 'A'
            inc di
            mov dx, offset msg2
            mov ah, 09
            int 21h

        wr1:
             cmp si,di
             je ext
             mov dl, arr[si]
             mov ah, 02
             int 21h
             inc si
             loop wr1

        ext:
             mov ax, 4c00h
             int 21h

     main endp
end main
