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
 ; Description: 九九乘法表。。。。。被乘數 * 乘數
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
	NUM1 DB  1
	NUM2 DB  1
	MSG1 DB  ' * $'
	MSG2 DB  ' = $'
	MSG3 DB  0DH, 0AH, '$'

.CODE
main:
	MOV  AX, @DATA          ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX             ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV  AX, 00H            ; 初始化 AX Register
	MOV  AL, NUM1           ; 把數值 NUM1 移動到 AL (AX Low Byte)
	MOV  BL, NUM2           ; 把數值 NUM2 移動到 BL (BX Low Byte)
	MOV  CX, 9              ; 設定「乘數」的次數
AA:
	PUSH AX                 ; 先將 AX Register 的內容移動至 .STACK Segment
	PUSH BX                 ; 再把 BX Register 的內容移動至 .STACK Segment
	MOV  DL, AL             ; 列印「被乘數」
	H0221
	@H0921  MSG1            ; 列印「 * 」
	MOV  DL, BL             ; 列印「乘數」
	H0221
	@H0921  MSG2            ; 列印「 = 」
	; 以下４行的目的是取出原本 AX & BX 的內容，再予以保留
	POP  BX
	POP  AX
	PUSH AX
	PUSH BX
	MOV  DL, BL             ; 將「乘數」(BL)移動至 DL (DX Low Byte)
	MUL  DL                 ; DL (乘數) * AL (被乘數) = 積 (AL)
	AAM                     ; 將整個 AX Register 調整為１０進制
	MOV  BX, AX             ; 將 AX Register 的內容移動到 BX Register
	MOV  DL, BH             ; 先列印出十位數
	H0221
	MOV  DL, BL             ; 再列印出個位數
	H0221
	@H0921  MSG3            ; 列印「\n」
	POP  BX                 ; 將 .STACK Segment 的內容移動至 BX Register
	POP  AX                 ; 將 .STACK Segment 的內容移動至 AX Register
	INC  BL                 ; 將「乘數」+１
	LOOP AA                 ; 依序地列印出：1 * 1 = 1; 1 * 2 = 2; 1 * 3 = 3 .... 
	@H0921  MSG3
	MOV  BL, NUM2           ; 當列印完上一輪的「N * 9」之後，再把乘數設為１，進行下一輪運算
	INC  AL                 ; 將「被乘數」+１
	MOV  CX, 9              ; 設定「被乘數」的次數
	CMP  AL, 10             ; 「被乘數」是否已經等於１０？
	JL   AA                 ; 當小於等於 (Sign Flag == 1)時，則跳躍至 AA 標籤所在的地方
	MOV  AH, 4CH            ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H                ; INT 21H: DOS 中斷
END main
