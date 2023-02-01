 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build102722
 ;
 ; Date: 2022 / 10 / 27
 ;
 ; Description: 這個範例呈現算術指令中的加法指令 -- ADD。
 ;              將兩個運算原相加，將結果儲存回目的運算元。
 ;              受影響的 Flag Register 位元：OF, SF, ZF, AF, PF, CF
 ;

.MODEL	SMALL

.STACK

.DATA
	NUM1 DB 3        ; 宣告變數名稱為 NUM1，將 0x03 以 Byte 的資料型態儲存到 NUM1
	NUM2 DB 2        ; 宣告變數名稱為 NUM2，將 0x02 以 Byte 的資料型態儲存到 NUM2

.CODE
main:
	MOV AX, @DATA    ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV DS, AX       ; 把 AX Register 的記憶體位址設定給 Data Segment Register；
	                 ; 換句話說，就是把 .DATA Segment 此時的記憶體位址，設定給 Data Segment Register
	MOV AH, NUM2     ; 把 NUM2 (0x03) 設定給 AX High Byte
	MOV AL, NUM1     ; 把 NUM1 (0x02) 設定給 AX Low Byte
	ADD AL, AH       ; AL (NUM1) + AH (NUM2) 的結果儲存回 AX Low Byte
	ADD AL, '0'      ; 把此時的 AL (0x05) 再加上 '0' (0x30) = 0x35 ('5')
	MOV DL, AL       ; 把 AL 的資料移動到 DL 作為輸出 (此時 AL 的值應為 0 且為回傳值)。
	MOV AH, 02H      ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的資料
	INT 21H          ; INT 21H: DOS 中斷
	MOV AH, 4CH      ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT 21H          ; INT 21H: DOS 中斷
END main
