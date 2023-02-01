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
 ; Description: 使用者輸入一位數減法運算；EX: 6 - 3 = 3
 ;

.MODEL	SMALL

.STACK

.DATA
	MSG1 DB  'KEY IN a minuend A: ? $'
	MSG2 DB  0DH, 0AH, 'KEY IN a subtrahend B: ? $ '
	MSG3 DB  0DH, 0AH, 'ANSWER IS: $'

.CODE
main:
	MOV  AX, @DATA          ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX             ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	; 顯示 "KEY IN a minuend A: ? "
	MOV  DX, OFFSET MSG1    ; 將 MSG1 的記憶體位址，再加上偏移量，移動到 DX Register
	MOV  AH, 09H            ; DOS 的第 09 號中斷服務 (顯示字串)；DX Register 為要顯示的位址
	INT  21H                ; INT 21H: DOS 中斷
	MOV  AH, 01H            ; DOS 的第 01 號中斷服務 (由鍵盤輸入字元並顯示)；AL (AX Low Byte)為輸入的字元
	INT  21H                ; INT 21H: DOS 中斷
	SUB  AL, 30H            ; 把輸入的字元轉換成數值，並儲存回 AL (AX Low Byte)
	PUSH AX                 ; 先將整個 AX Register 的內容 (被減數)移動至 .STACK Segment
	; 顯示 "KEY IN a subtrahend B: ? "
	MOV  DX, OFFSET MSG2    ; 將 MSG2 的記憶體位址，再加上偏移量，移動到 DX Register
	MOV  AH, 09H            ; DOS 的第 09 號中斷服務 (顯示字串)；DX Register 為要顯示的位址
	INT  21H                ; INT 21H: DOS 中斷
	MOV  AH, 01H            ; DOS 的第 01 號中斷服務 (由鍵盤輸入字元並顯示)；AL (AX Low Byte)為輸入的字元
	INT  21H                ; INT 21H: DOS 中斷
	SUB  AL, 30H            ; 把輸入的字元轉換成數值，並儲存回 AL (AX Low Byte) (減數)
	; 開始計算 .... 
	MOV  DL, AL             ; 先把減數移動至 DL (DX Low Byte)
	POP  AX                 ; 再把 .STACK Segment 裡的內容移動到 AX Register (被減數)
	SUB  AL, DL             ; 被減數 (AL) - 減數 (DL) = 差，儲存回 AL (AX Low Byte)
	MOV  AH, 00H            ; 初始化 AH (AX High Byte)
	AAS                     ; 將整個 AX Register 調整為１０進制
	PUSH AX                 ; 再把整個 AX Register 的內容 (十進制的差)移動至 .STACK Segment
	; 顯示 "ANSWER IS: "
	MOV  DX, OFFSET MSG3    ; 將 MSG3 的記憶體位址，再加上偏移量，移動到 DX Register
	MOV  AH, 09H            ; DOS 的第 09 號中斷服務 (顯示字串)；DX Register 為要顯示的位址
	INT  21H                ; INT 21H: DOS 中斷

	MOV  DL, ' '            ; 保留一個空白字元
	JNS  PRI                ; 當 Sign Flag != 1 (Jump Not Sign，即正數)時，就跳躍到 PRI 標籤所在的地方
	; 若 Sign Flag == 1 (即負數)，就將結果取１０的補數，並將 DL + 13 = 45 ('-' 的 ASCII 碼)
	POP  AX
	MOV  BL, 10
	SUB  BL, AL
	MOV  AX, BX
	PUSH AX
	ADD  DL, 13
PRI:
	MOV  AH, 02H            ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的字元
	INT  21H                ; INT 21H: DOS 中斷
	POP  AX                 ; 再把 .STACK Segment 裡的內容移動到 AX Register (十進制的差)
	MOV  DL, AL             ; 將差 (AL)移動至 DL (DX Low Byte)
	ADD  DL, 30H            ; 把 DL (DX Low Byte) 的內容由「數值」轉換成「字元」
	MOV  AH, 02H            ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的字元
	INT  21H                ; INT 21H: DOS 中斷
	MOV  AH, 4CH            ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H                ; INT 21H: DOS 中斷
END main
