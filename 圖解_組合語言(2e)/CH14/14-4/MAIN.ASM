 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build011823
 ;
 ; Date: 2023 / 01 / 18
 ;
 ; Description: 這乙章節很無聊！「INT 21H: DOS 中斷」的鍵盤中斷服務；
 ;              DOS 的第 0A 號中斷服務：將鍵盤的輸入，先移動到緩衝區；DS:DX 為緩衝區的起始位址
 ;              至於緩衝區 (Buffer)的結構，請參考課本 Page 14-7 這裡不贅述。
 ;

.MODEL	SMALL

.STACK

.DATA
	BUF  DB  11, 10 DUP(0), '$'  ; 搭配 DOS 的第 0A 號中斷服務的用法，宣告緩衝區的格式 (樣子)
	MSG  DB  0DH, 0AH, 'USER KEY IN: $'

.CODE
main:
	MOV  AX, @DATA               ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX                  ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV  DX, OFFSET BUF          ; 將 BUF 的記憶體位址，再加上偏移量的值，移動到 DX Register
	MOV  AH, 0AH                 ; DOS 的第 0A 號中斷服務：將鍵盤的輸入，先移動到緩衝區
	INT  21H                     ; INT 21H: DOS 中斷
	; 顯示字串："\nUSER KEY IN: \0"
	MOV  DX, OFFSET MSG          ; 將 MSG 的記憶體位址，再加上偏移量的值，移動到 DX Register
	MOV  AH, 09H                 ; DOS 的第 09 號中斷服務 (顯示字串)；DX Register 為要顯示的位址
	INT  21H                     ; INT 21H: DOS 中斷
	; 顯示剛剛儲存在緩衝區的字串
	MOV  BX, OFFSET BUF          ; 將 BUF 的記憶體位址，再加上偏移量的值，移動到 BX Register
	ADD  BX, 2                   ; 將 BX Register 的內容 (記憶體位址)再 +２；即 BUF 的前２ Bytes (11 & 10)不要
printc:
	MOV  DL, BYTE PTR DS:[BX]    ; 將 BUF 的記憶體位址 +２ 所指到的字元，移動到 DL (DX Low Byte)
	CMP  DL, 0DH                 ; 比對 DL (DX Low Byte) 和數值 0x0D 是否一樣？
	JE   ENDDOS                  ; 如果一樣：就跳躍到 ENDDOS 標籤 (結束程式)
	MOV  AH, 02H                 ; 如果不一樣：DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為輸出的字元
	INT  21H                     ; INT 21H: DOS 中斷
	INC  BX                      ; 將 BX 的記憶體位址 +１再儲存回 BX Register
	JMP  printc                  ; 跳躍到 printc 標籤
ENDDOS:
	MOV  AH, 4CH                 ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H                     ; INT 21H: DOS 中斷
END main
