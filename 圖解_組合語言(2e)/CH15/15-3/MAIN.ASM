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
 ; Description: 使用者輸入１６進位的加法運算
 ;              這個範例很笨，並沒有做任何的防呆機制；隨便輸入一個字元都會去做運算。
 ;

.MODEL	SMALL

.STACK

.DATA
	MSG1 DB  'INPUT A: ? $'
	MSG2 DB  0DH, 0AH, 'INPUT B: ? $'
	MSG3 DB  0DH, 0AH, 'A + B = $'

.CODE
main:
	MOV  AX, @DATA          ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX             ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	; 顯示 INPUT A: ? 
	MOV  DX, OFFSET MSG1    ; 將 MSG1 的記憶體位址，再加上偏移量，移動到 DX Register
	MOV  AH, 09H            ; DOS 的第 09 號中斷服務 (顯示字串)；DX Register 為要顯示的位址
	INT  21H                ; INT 21H: DOS 中斷
	; 輸入被加數
	MOV  AH, 01H            ; DOS 的第 01 號中斷服務 (由鍵盤輸入字元並顯示)；AL (AX Low Byte)為輸入的字元
	INT  21H                ; INT 21H: DOS 中斷
	SUB  AL, 30H            ; 將輸入的字元 AL (AX Low Byte) 轉換成「數值」
	MOV  BL, AL             ; 將輸入的字元 AL (AX Low Byte) 移動到 BL (BX Low Byte)
	; 顯示 INPUT B: ? 
	MOV  DX, OFFSET MSG2    ; 將 MSG2 的記憶體位址，再加上偏移量，移動到 DX Register
	MOV  AH, 09H            ; DOS 的第 09 號中斷服務 (顯示字串)；DX Register 為要顯示的位址
	INT  21H                ; INT 21H: DOS 中斷
	; 輸入加數
	MOV  AH, 01H            ; DOS 的第 01 號中斷服務 (由鍵盤輸入字元並顯示)；AL (AX Low Byte)為輸入的字元
	INT  21H                ; INT 21H: DOS 中斷
	SUB  AL, 30H            ; 將輸入的字元 AL (AX Low Byte) 轉換成「數值」
	ADD  BL, AL             ; 將被加數 (BL) + 加數 (AL)，儲存回 BL (BX Low Byte)
	; 顯示 A + B = 
	MOV  DX, OFFSET MSG3    ; 將 MSG3 的記憶體位址，再加上偏移量，移動到 DX Register
	MOV  AH, 09H            ; DOS 的第 09 號中斷服務 (顯示字串)；DX Register 為要顯示的位址
	INT  21H                ; INT 21H: DOS 中斷
	; 開始計算 .... 
	MOV  DL, BL             ; 將 BL (BX Low Byte) 的內容移動到 DL (DX Low Byte)
	ADD  DL, 30H            ; 將 DL (DX Low Byte) 的內容 (和)轉換成字元
	CMP  DL, '9'            ; 比對 DL (DX Low Byte) 的內容和 '9' (0x39)是否相等
	JBE  MAA                ; 當 Zero Flag == 1 || Carry Flag == 1 時，就跳躍到 MAA 標籤所在的地方
	ADD  DL, 7              ; 否則，將 DL (DX Low Byte) 的內容加上７
MAA:
	MOV  AH, 02H            ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的字元
	INT  21H                ; INT 21H: DOS 中斷
	MOV  AH, 4CH            ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H                ; INT 21H: DOS 中斷
END main
