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
 ; Description: 四則綜合運算；EX: [(14 * 3) + 8] / (15 - 5) = 5
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
	X    DW  '0$'
	Y    DW  '0$'
	A    DW  14             ; 被乘數
	B    DW  3              ; 乘數
	Cy   DW  8              ; 加數
	D    DW  15             ; 被減數

.CODE
main:
	MOV  AX, @DATA          ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX             ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	; 14 * 3
	MOV  AX, A              ; 先將被乘數 (14)移動至 AX Register (0x000E)
	IMUL B                  ; B (3 == 0x03) * AL (14 == 0x0E) = 42 (0x2A) (AL)
	; (14 * 3) + 8；分子
	MOV  CX, Cy             ; 將加數 (Cy)移動至 CX Register (0x0008)
	ADC  AX, CX             ; AX (0x002A) + CX (0x0008) + Carry Flag (0x00)的結果儲存回 AX Register (0x0032 == 50)
	; 15 - 5；分母
	MOV  CX, D              ; 將被減數 (15)移動至 CX Register (0x000F)
	SUB  CX, 5              ; CX (0x000F == 15) - 5 的結果儲存回 CX Low Byte (0x000A == 10)
	; 分子 / 分母
	IDIV CX                 ; AX (0x0032 == 50) / CX (0x000A == 10) = 5 (0x05) (AL) .... 0 (0x00) (AH) ----> AX == 0x0005
	; 讓 SI & DI Register 分別指向 DX & AX Register
	MOV  X, DX
	MOV  Y, AX
	LEA  SI, X
	LEA  DI, Y
	; 呈現結果
	MOV  DL, [SI]           ; 先列印出商數的十位數 ('0')
	H0221
	MOV  DL, [DI]           ; 再列印出商數的個位數 ('5')
	H0221
	MOV  AH, 4CH            ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H                ; INT 21H: DOS 中斷
END main
