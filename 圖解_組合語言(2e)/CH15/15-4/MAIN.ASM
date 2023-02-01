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
 ; Description: 三位數加法運算
 ;

.MODEL	SMALL

.STACK

.DATA
	NUM1 DB  '777$'
	NUM2 DB  '333$'
	NUM3 DB  '0000$'
	MSG  DB  '777 + 333 = $'

.CODE
main:
	MOV  AX, @DATA         ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX            ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	; 顯示 "777 + 333 = "
	MOV  DX, OFFSET MSG    ; 將 MSG 的記憶體位址，再加上偏移量，移動到 DX Register
	MOV  AH, 09H           ; DOS 的第 09 號中斷服務 (顯示字串)；DX Register 為要顯示的位址
	INT  21H               ; INT 21H: DOS 中斷
	LEA  SI, NUM1 + 2      ; 將 NUM1 再加上２的記憶體位址，即個位數的 '7' 存入 Source Index Register
	LEA  DI, NUM2 + 2      ; 將 NUM2 再加上２的記憶體位址，即個位數的 '3' 存入 Destination Index Register
	LEA  BX, NUM3 + 3      ; 將 NUM3 再加上３的記憶體位址，即個位數的 '0' 存入 BX Register
	MOV  CX, 3             ; 設定 LOOP 的次數為３
MAA:                           ; 開始從個位數相加
	MOV  AX, 00H           ; 將 AH (AX High Byte)初始化為 0x00
	MOV  AL, [SI]          ; 將 SI 所儲存的記憶體位址的內容 (即'7' == 0x37)，移動到 AL (AX Low Byte)
	ADC  AL, [DI]          ; 將 DI 所儲存的記憶體位址的內容 (即'3' == 0x33)，加上 AL 的內容 (即'7')，把結果儲存回 AL (0x6A == 106)
	                       ; 再加上 Carry Flag == 1 所以，第一輪會是 0x6A ；而第二、三輪則是 0x6B
	AAA                    ; 未包裝運算指令：將 AX Register 調整為１０進制；此時 AX 內容為 0x0100
	                       ; 且 Carry Flag == 1 (進位旗標)和 Auxiliary Carry == 1 (輔助進位)
	MOV  [BX], AL          ; 將 AL (AX Low Byte)的內容 (0x00)移動到 BX Register 所指定的位址
	DEC  SI                ; 將 SI 所儲存的記憶體位址 -１；此時指到的是十位數的'7'
	DEC  DI                ; 將 DI 所儲存的記憶體位址 -１；此時指到的是十位數的'3'
	DEC  BX                ; 將 BX 所儲存的記憶體位址 -１；此時指到的是個位數的'0'
	LOOP MAA               ; 重覆 MAA 直到 CX == 0 為止
	; 開始做進位計算
	MOV  [BX], AH          ; 將 AH (AX High Byte)的內容 (0x01)移動到 BX Register 所指定的位址
	MOV  CX, 4             ; 設定 LOOP 的次數為４
MBB:                           ; 由千位數依序開始列印出：'1', '1', '1', '0'
	MOV  DL, [BX]          ; 將 BX Register 記憶體位址所指到的內容，移動到 DL (DX Low Byte)
	ADD  DL, 30H           ; 將 DL (DX Low Byte)內的數值轉換成字元
	MOV  AH, 02H           ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的字元
	INT  21H               ; INT 21H: DOS 中斷
	INC  BX                ; BX Register 記憶體位址 -１
	LOOP MBB               ; 重覆 MBB 直到 CX == 0 為止
	MOV  AH, 4CH           ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H               ; INT 21H: DOS 中斷
END main
