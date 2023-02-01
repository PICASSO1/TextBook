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
 ; Description: 這個範例呈現算術指令中的擴展指令 -- CBW。
 ;              這個指令會將 AX Low Byte 中的最高位元值，存入 AX High Byte 的每一個位元中。
 ;              在運算的過程當中，若出現資料長度不足的情況，可以利用此一指令來擴展長度，
 ;              而不影響原值。
 ;              This example refer from 6-7.2
 ;

.MODEL	SMALL

.STACK

.DATA
	NUM1 DB 14       ; 宣告變數名稱為 NUM1，將 0x0E 以 Byte 的資料型態儲存到 NUM1
	                 ; 原本被除數應宣告成 DW (2 Bytes)，這裡刻意宣告成 DB (Byte)
	NUM2 DB 03       ; 宣告變數名稱為 NUM2，將 0x03 以 Byte 的資料型態儲存到 NUM2

.CODE
main:
	MOV AX, @DATA    ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV DS, AX       ; 把 AX Register 的記憶體位址設定給 Data Segment Register；
	                 ; 換句話說，就是把 .DATA Segment 此時的記憶體位址，設定給 Data Segment Register
	MOV DL, NUM2     ; 把 NUM2 (0x03) 設定給 DX Low Byte
	MOV AL, NUM1     ; 把 NUM1 (0x0E) 設定給 AX Low Byte
	CBW              ; 此時的 AL (0x0E, 0000 1110)的最高位元為 0 ；會塞給 AH (0000 0000)，所以整個
	                 ; AX Register 為: 0000 0000 0000 1110 == 0x0E！
	DIV DL           ; AX (0x0E) / DL (0x03) = 4 (0x04) (AL) .... 2 (0x02) (AH) ----> AX == 0x0204
	MOV DL, AH       ; 把 AH (0x02) 的資料移動到 DL 作為輸出 (此時 AL 的值應為 0X04 且為回傳值)。
	ADD DL, '0'      ; 把此時的 DL (0x02) 再加上 '0' (0x30) = 0x32 ('2')
	MOV AH, 02H      ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的資料
	INT 21H          ; INT 21H: DOS 中斷
	MOV AH, 4CH      ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；BL (BX Low Byte)為回傳值
	INT 21H          ; INT 21H: DOS 中斷
END main
