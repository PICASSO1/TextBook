 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build012223
 ;
 ; Date: 2023 / 01 / 22
 ;
 ; Description: 一位數減法運算
 ;

.MODEL	SMALL

.STACK

.DATA
	NUM1 DB  7
	NUM2 DB  2

.CODE
main:
	MOV  AX, @DATA    ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX       ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV  AL, NUM1     ; 將 NUM1 移動到 AL (AX Low Byte)
	MOV  AH, NUM2     ; 將 NUM2 移動到 AH (AX High Byte)
	SUB  AL, AH       ; 被減數 (AL == NUM1 == 0x07) - 減數 (AH == NUM2 == 0x02)的差 (0x05)儲存回 AL (AX Low Byte)
	ADD  AL, '0'      ; 將 AL (AX Low Byte)內的數值 (0x05)轉換成字元 ('5')
	MOV  DL, AL       ; 將 AL (AX Low Byte)的內容移動到 DL (DX Low Byte)
	MOV  AH, 02H      ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的字元
	INT  21H          ; INT 21H: DOS 中斷
	MOV  AH, 4CH      ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H          ; INT 21H: DOS 中斷
END main
