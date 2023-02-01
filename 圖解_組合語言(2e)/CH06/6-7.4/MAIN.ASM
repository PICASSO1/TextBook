 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build103022
 ;
 ; Date: 2022 / 10 / 30
 ;
 ; Description: 這個範例呈現算術指令中的除法指令 -- IDIV。
 ;              IDIV 其實和 DIV 的處理方式是一樣的；差別在於 IDIV 多了正負號的處理。
 ;              其特性為將「被除數」放進 AX 暫存器中；「除數」放進一般暫存器 or 記憶體。
 ;              「商」會放在 AL ，而「餘數」會放在 AH。
 ;              字組 (Word)除以位元組 (Byte)的時候，被除數 (字組)會存放在 AX Register；
 ;              除數 (位元組)存放在一般暫存器 or 記憶體，商數存放在 AL，餘數存放在 AH。
 ;              雙字組 (Double Word)除以字組 (Word)的時候，被除數 (雙字組)會存放在 AX & DX Register；
 ;              除數 (字組)存放在一般暫存器 or 記憶體，商數存放在 AX，餘數存放在 DX。
 ;

.MODEL	SMALL

.STACK

.DATA
	NUM1 DW -17      ; 宣告變數名稱為 NUM1，將 -17 (0001 0001) 以 Word (2 Byte, 0000 0000 0001 0001) 的資料型態儲存到 NUM1
	NUM2 DB -3       ; 宣告變數名稱為 NUM2，將 -3 (1111 1101) 以 Byte 的資料型態儲存到 NUM2

.CODE
main:
	MOV  AX, @DATA   ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV  DS, AX      ; 把 AX Register 的記憶體位址設定給 Data Segment Register；
	                 ; 換句話說，就是把 .DATA Segment 此時的記憶體位址，設定給 Data Segment Register
	MOV  DL, NUM2    ; 把 NUM2 (-3, 1111 1101) 設定給 DX Low Byte
	MOV  AX, NUM1    ; 把 NUM1 (-17, 0000 0000 0001 0001) 設定給 AX Register
	IDIV DL          ; AX (-17) / DL (-3) = 5 (0x05) (AL) .... 2 (0x02) (AH) ----> AX == 0x0205
	MOV  DL, AL      ; 把 AL (0x05) 的資料移動到 DL 作為輸出 (此時 AL 的值應為 0 且為回傳值)。
	ADD  DL, '0'     ; 把此時的 DL (0x05) 再加上 '0' (0x30) = 0x35 ('5')
	MOV  AH, 02H     ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的資料
	INT  21H         ; INT 21H: DOS 中斷
	MOV  AH, 4CH     ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；BL (BX Low Byte)為回傳值
	INT  21H         ; INT 21H: DOS 中斷
END main
