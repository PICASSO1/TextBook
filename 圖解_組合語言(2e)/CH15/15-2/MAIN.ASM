 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build012123
 ;
 ; Date: 2023 / 01 / 21
 ;
 ; Description: 使用者輸入一位數加法運算
 ;

.MODEL	SMALL

.STACK

.DATA

.CODE
main:
	MOV  AX, @DATA    ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX       ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	; 輸入被加數
	MOV  AH, 01H      ; DOS 的第 01 號中斷服務 (由鍵盤輸入字元並顯示)；AL (AX Low Byte)為輸入的字元
	INT  21H          ; INT 21H: DOS 中斷
	MOV  BL, AL       ; 將輸入的字元 AL (AX Low Byte) 移動到 BL (BX Low Byte)
	SUB  AL, '0'      ; 將輸入的字元 AL (AX Low Byte) 轉換成「數值」
	MOV  DL, ' '      ; 將空白鍵 (Space) 移動到 DL (DX Low Byte)
	MOV  AH, 02H      ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的字元
	INT  21H          ; INT 21H: DOS 中斷
	; 輸出加號和空白鍵
	MOV  DL, '+'
	MOV  AH, 02H
	INT  21H
	MOV  DL, ' '
	MOV  AH, 02H
	INT  21H
	; 輸入加數
	MOV  AH, 01H      ; DOS 的第 01 號中斷服務 (由鍵盤輸入字元並顯示)；AL (AX Low Byte)為輸入的字元
	INT  21H          ; INT 21H: DOS 中斷
	SUB  AL, 30H      ; 將輸入的字元 AL (AX Low Byte) 轉換成「數值」
	ADD  AL, BL       ; 將被加數 (BL) + 加數 (AL)，儲存回 AL (AX Low Byte)
	; 開始計算 .... 
	MOV  AH, 00H      ; 將 AH (AX High Byte)初始化為 0x00
	AAA               ; 未包裝運算指令：將 AX Register 調整為１０進制
	MOV  BX, AX       ; 將 AX Register 的內容移動到 BX Register 
	MOV  DL, ' '      ; 將空白鍵 (Space) 移動到 DL (DX Low Byte)
	MOV  AH, 02H      ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的字元
	INT  21H          ; INT 21H: DOS 中斷
	; 輸出等號和空白鍵
	MOV  DL, '='
	MOV  AH, 02H
	INT  21H
	MOV  DL, ' '
	MOV  AH, 02H
	INT  21H
	; 輸出十位數
	MOV  DL, BH
	ADD  DL, '0'
	MOV  AH, 02H
	INT  21H
	; 輸出個位數
	MOV  DL, BL
	ADD  DL, '0'
	MOV  AH, 02H
	INT  21H
	MOV  AH, 4CH      ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H          ; INT 21H: DOS 中斷
END main
