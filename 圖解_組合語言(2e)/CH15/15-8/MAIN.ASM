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
 ; Description: 多位數減法運算；EX: 888 - 555 = 333
 ;

.MODEL	SMALL

.STACK

.DATA
	NUM1 DB  '888$'
	NUM2 DB  '555$'
	NUM3 DB  '000$'
	MSG  DB  '888 - 555 = $'

.CODE
main:
	MOV  AX, @DATA         ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX            ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	LEA  SI, NUM1 + 2      ; 將 NUM1 再加上２的記憶體位址，即個位數的 '8' 存入 Source Index Register
	LEA  DI, NUM2 + 2      ; 將 NUM2 再加上２的記憶體位址，即個位數的 '5' 存入 Destination Index Register
	LEA  BX, NUM3 + 2      ; 將 NUM3 再加上２的記憶體位址，即個位數的 '0' 存入 BX Register
	; 先計算結果
	MOV  CX, 3             ; 設定 MAA 的 loop 次數
MAA:
	MOV  AX, 00H           ; 將 AH (AX High Byte)初始化為 0x00
	MOV  AL, [SI]          ; 將 SI 所儲存的記憶體位址的內容 (即'8' == 0x38)，移動到 AL (AX Low Byte)
	SBB  AL, [DI]          ; 將被減數 (AL == 0x08) - 減數 (即 DI 所儲存的記憶體位址的內容 0x05) - Carry Flag (0x00) 的結果儲存回 AX Low Byte
	AAS                    ; 將整個 AX Register 調整為１０進制；原本：0x0003；調整後：0x0003
	MOV  [BX], AL          ; 將 AL (AX Low Byte)的內容 (0x03)移動到 BX Register 所指定的位址
	DEC  SI                ; 將 SI 所儲存的記憶體位址 -１；此時指到的是十位數的'8'
	DEC  DI                ; 將 DI 所儲存的記憶體位址 -１；此時指到的是十位數的'5'
	DEC  BX                ; 將 BX 所儲存的記憶體位址 -１；此時指到的是個位數的'0'
	LOOP MAA               ; 重覆 MAA 直到 CX == 0 為止
	; 顯示 "888 - 555 = "
	MOV  DX, OFFSET MSG    ; 將 MSG 的記憶體位址，再加上偏移量，移動到 DX Register
	MOV  AH, 09H           ; DOS 的第 09 號中斷服務 (顯示字串)；DX Register 為要顯示的位址
	INT  21H               ; INT 21H: DOS 中斷
	; 呈現結果
	MOV  CX, 3             ; 設定 MBB 的 loop 次數
MBB:                           ; 由百位數依序開始列印出：'3', '3', '3'
	MOV  DL, [BX] + 1      ; 將 BX Register 記憶體位址所指到的內容，移動到 DL (DX Low Byte)
	ADD  DL, 30H           ; 將 DL (DX Low Byte)內的數值轉換成字元
	MOV  AH, 02H           ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的字元
	INT  21H               ; INT 21H: DOS 中斷
	INC  BX                ; BX Register 記憶體位址 -１
	LOOP MBB               ; 重覆 MBB 直到 CX == 0 為止
	MOV  AH, 4CH           ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H               ; INT 21H: DOS 中斷
END main
