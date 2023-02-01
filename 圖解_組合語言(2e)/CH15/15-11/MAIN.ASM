 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build012423
 ;
 ; Date: 2023 / 01 / 24
 ;
 ; Description: 除法運算
 ;

H0221  MACRO                    ; 定義一個巨集，可以把數值轉換成字元
	ADD  DL, '0'            ; 將數值轉換成字元
	MOV  AH, 02H            ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的字元
	INT  21H                ; INT 21H: DOS 中斷
ENDM

@H0921  MACRO  MSG              ; 定義一個巨集，用來輸出字串
	MOV  DX, OFFSET MSG     ; 將 MSG 的記憶體位址，再加上偏移量，移動到 DX Register
	MOV  AH, 09H            ; DOS 的第 09 號中斷服務 (顯示字串)；DX Register 為要顯示的位址
	INT  21H                ; INT 21H: DOS 中斷
ENDM

.MODEL	SMALL

.STACK

.DATA
	NUM1 DB  8
	NUM2 DB  2
	NUM3 DB  3
	MSG1 DB  '82 / 3 = ? $'
	MSG2 DB  0DH, 0AH, 'Quotient: $'
	MSG3 DB  0DH, 0AH, 'Remainder: $'

.CODE
main:
	MOV  AX, @DATA          ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX             ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	@H0921  MSG1            ; 列印「82 / 3 = ? 」
	MOV  AH, 00H            ; 初始化 AX Register
	MOV  AL, NUM1           ; 把 NUM1 (8)移動到 AL (AX Low Byte)
	MOV  DL, NUM3           ; 把 NUM3 (3)移動到 DL (DX Low Byte)
	DIV  DL                 ; AX (0x0008) / DL (0x03) = 2 (0x02) (AL) .... 2 (0x02) (AH) ----> AX == 0x0202
	MOV  BL, AL             ; 將商數 (AL == 2)移動到 BL (BX Low Byte)
	MOV  AL, AH             ; 將餘數 (AH == 2)移動到 AL (AX Low Byte)
	MOV  DL, 10             ; 將 10 移動到 DL (DX Low Byte)
	MUL  DL                 ; DL (10) * AL (2) = 20 (AL == 0x14)
	ADD  AL, NUM2           ; 將上一輪除法的餘數 * 10 再加上被除數的個位數 (AL == 0x16)
	AAD                     ; 將整個 AX Register 調整為１０進制；原本 AH: 0x00; AL: 0x16
	                        ; 調整後 AH: 0x02 (2); AL: 0x02 (2)
	MOV  DL, NUM3           ; 把 NUM3 (3)移動到 DL (DX Low Byte)
	DIV  DL                 ; AX (0x0202) / DL (0x03) = 7 (0x07) (AL) .... 1 (0x01) (AH) ----> AX == 0x0107
	MOV  CX, AX             ; 將 AX Register 的內容移動到 CX Register
	@H0921  MSG2            ; 列印「Quotient: 」
	MOV  DL, BL             ; 先列印出第一輪除法的商數 ('2')，即十位數
	H0221
	MOV  DL, CL             ; 再列印出第二輪除法的商數 ('7')，即個位數
	H0221
	@H0921  MSG3            ; 列印「Remainder: 」
	MOV  DL, CH             ; 列印出最後的餘數 ('1')
	H0221
	MOV  AH, 4CH            ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H                ; INT 21H: DOS 中斷
END main
