 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build012323
 ;
 ; Date: 2023 / 01 / 23
 ;
 ; Description: 使用者輸入三位數加法運算；EX: 555 + 888 = 1443
 ;

.MODEL	SMALL

.STACK

.DATA
	MSG1 DB  'KEY IN a summand A: ? $'
	MSG2 DB  0DH, 0AH, 'KEY IN an addend B: ? $ '
	MSG3 DB  0DH, 0AH, 'ANSWER IS: $'

.CODE
main:
	MOV  AX, @DATA          ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX             ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	; 顯示 "KEY IN a summand A: ? "
	MOV  DX, OFFSET MSG1    ; 將 MSG1 的記憶體位址，再加上偏移量，移動到 DX Register
	MOV  AH, 09H            ; DOS 的第 09 號中斷服務 (顯示字串)；DX Register 為要顯示的位址
	INT  21H                ; INT 21H: DOS 中斷
	; 輸入第一組三位數
	MOV  CX, 3              ; 設定 MAA 標籤的 loop 次數
MAA:
	MOV  AH, 01H            ; DOS 的第 01 號中斷服務 (由鍵盤輸入字元並顯示)；AL (AX Low Byte)為輸入的字元
	INT  21H                ; INT 21H: DOS 中斷
	MOV  [SI], AL           ; 將輸入的字元 (AX Low Byte)，移動到 SI Register 所指定的位址
	INC  SI                 ; 將 SI Register 的值 +1
	LOOP MAA                ; 重覆 MAA 直到 CX == 0 為止
	; 顯示 "KEY IN an addend B: ? "
	MOV  DX, OFFSET MSG2    ; 將 MSG2 的記憶體位址，再加上偏移量，移動到 DX Register
	MOV  AH, 09H            ; DOS 的第 09 號中斷服務 (顯示字串)；DX Register 為要顯示的位址
	INT  21H                ; INT 21H: DOS 中斷
	; 輸入第二組三位數
	MOV  CX, 3              ; 設定 MBB 標籤的 loop 次數
MBB:
	MOV  AH, 01H            ; DOS 的第 01 號中斷服務 (由鍵盤輸入字元並顯示)；AL (AX Low Byte)為輸入的字元
	INT  21H                ; INT 21H: DOS 中斷
	MOV  [SI], AL           ; 將輸入的字元 (AX Low Byte)，移動到 SI Register 所指定的位址
	INC  SI                 ; 將 SI Register 的值 +1
	LOOP MBB                ; 重覆 MBB 直到 CX == 0 為止
	; 顯示 "ANSWER IS: "
	MOV  DX, OFFSET MSG3    ; 將 MSG3 的記憶體位址，再加上偏移量，移動到 DX Register
	MOV  AH, 09H            ; DOS 的第 09 號中斷服務 (顯示字串)；DX Register 為要顯示的位址
	INT  21H                ; INT 21H: DOS 中斷
	; 開始做進位計算
	MOV  DI, 5              ; 將數值 0x05 移動到 DI Register；即指到「和」的個位數
	MOV  SI, 2              ; 將數值 0x02 移動到 SI Register；即指到「被加數」和「加數」的個位數
	MOV  CX, 3              ; 設定 MCC 標籤的 loop 次數
MCC:
	MOV  AH, 00H            ; 將 AH (AX High Byte)初始化為 0x00
	MOV  AL, [SI]           ; 將被加數 (依序為個、十、百位數)，即 '5' 移動到 AL (AX Low Byte)
	ADC  AL, [SI] + 3       ; 將加數 (依序為個、十、百位數)，即 '8'，加上 AL 的內容 (即'5')，把結果儲存回 AL (0x6D == 109)
	                        ; 再加上 Carry Flag == 1 所以，第一輪會是 0x6D ；而第二、三輪則是 0x6E
	AAA                     ; 未包裝運算指令：將 AX Register 調整為１０進制；此時 AX 內容為 0x0103 (8 + 5 = 13 = 0x0D)
	MOV  [DI], AL           ; 將 AL 的內容依序地移到和的個、十、百、千位數
	DEC  SI                 ; 將 SI 依序地指到「被加數」和「加數」的十、百位數
	DEC  DI                 ; 將 DI 依序地指到「和」的十、百、千位數
	LOOP MCC                ; 重覆 MCC 直到 CX == 0 為止
	; 顯示結果 (和)；依序為千、百、十、個位數來呈現
	MOV  [DI], AH           ; 此時的 AX Register 的內容停留在百位數的'5'、'8'和 Carry Flag 的和：0x0E == 14 ==> 0x0104
	MOV  CX, 4              ; 設定 MDD 標籤的 loop 次數
MDD:
	MOV  AL, [DI]           ; 將 DI Register 的內容移動到 AL (AX Low Byte)
	ADD  AL, '0'            ; 將 AL (AX Low Byte)內的「數值」轉換成「字元」
	INC  DI                 ; DI Register 依序地遞減，分別指到千、百、十、個位數
	MOV  DL, AL             ; 將 AL (AX Low Byte) 記憶體位址所指到的內容，移動到 DL (DX Low Byte)
	MOV  AH, 02H            ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的字元
	INT  21H                ; INT 21H: DOS 中斷
	LOOP MDD                ; 重覆 MDD 直到 CX == 0 為止
	MOV  AH, 4CH            ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H                ; INT 21H: DOS 中斷
END main
