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
 ; Description: 這個範例呈現算術指令中的擴展指令 -- CWD。
 ;              這個指令會將 AX 中的最高位元值，存入 DX 的每一個位元中。
 ;

.MODEL	SMALL

.STACK

.DATA
	NUM DW 32769     ; 宣告變數名稱為 NUM，將 32,769 (0x8001, 1000 0000 0000 0001)
	                 ; 以 Word 的資料型態儲存到 NUM
.CODE
main:
	MOV AX, @DATA    ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV DS, AX       ; 把 AX Register 的記憶體位址設定給 Data Segment Register；
	                 ; 換句話說，就是把 .DATA Segment 此時的記憶體位址，設定給 Data Segment Register
	MOV AX, NUM      ; 把 NUM (0x8001, 1000 0000 0000 0001) 設定給 AX Register
	CWD              ; 此時的 AX (0x8001, 1000 0000 0000 0001)的最高位元為 1 ；會塞給 DX ，
	                 ; 所以整個 DX Register 為：1111 1111 1111 1111 (0xFF)
	ADD DL, 'D'      ; 把此時的 DL (1111 1111)，這是２的補數結果，其值為 -1 ；
	                 ; 再加上 'D' (0x44) = 0x43 ('C')
	MOV AH, 02H      ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的資料
	INT 21H          ; INT 21H: DOS 中斷
	MOV AH, 4CH      ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；BL (BX Low Byte)為回傳值
	INT 21H          ; INT 21H: DOS 中斷
END main
