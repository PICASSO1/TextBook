 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build112022
 ;
 ; Date: 2022 / 11 / 20
 ;
 ; Description: 這個範例呈現未包裝運算指令 -- AAS (ASCII Adjust After Subtraction)。
 ;              - 將 AX Register 的內容調整為十進制的值；其中：
 ;                高位元儲存至 AX High Byte；而低位元儲存至 AX Low Byte
 ;              - 亦稱為「未包裝減法調整指令」
 ;              - 受影響的旗標為：AF、CF
 ;              - AAA 會搭配 ADD 來使用；而 AAS 則是搭配 SUB 來使用
 ;

.MODEL	SMALL

.STACK

.DATA
	NUM1   DB  0BH     ; 宣告變數名稱為 NUM1，將數值 0x0B (0000 1011 == 11)以 Byte 的資料型態儲存
	NUM2   DB  06H     ; 宣告變數名稱為 NUM2，將數值 0x06 (0000 0110)以 Byte 的資料型態儲存

.CODE
main:
	MOV   AX, @DATA    ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV   DS, AX       ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV   AL, NUM1     ; 把數值 NUM1 設定給 AX Low Byte
	MOV   BL, NUM2     ; 把數值 NUM2 設定給 BX Low Byte
	SUB   AL, BL       ; 將 AL (11) - BL (6) 且儲存回 AL (5)；此值並非 BCD 碼
	MOV   AH, 00H      ; 將 AX High Byte 設置為０
	AAS                ; 將整個 AX Register 調整為１０進制；原本 AH: 0x00; AL: 0x05
	                   ; 調整後 AH: 0x00 (0); AL: 0x05 (5)
	MOV   BX, AX       ; 將 AX Register 的內容移置 BX Register
	MOV   DL, BH       ; 將 BX High Byte 的內容移置 DX Low Byte
	ADD   DL, 30H      ; 將 DX Low Byte 的數值 (0x00)加上 0x30 ('0')變成可顯字元 ('0')
	MOV   AH, 02H      ; DOS 的第 02 號中斷服務 (顯示字元)；DX Low Byte 為要輸出的資料
	INT   21H          ; INT 21H: DOS 中斷	
	MOV   DL, BL       ; 將 BX Low Byte 的內容移置 DX Low Byte
	ADD   DL, 30H      ; 將 DX Low Byte 的數值 (0x05)加上 0x30 ('0')變成可顯字元 ('5')
	MOV   AH, 02H      ; DOS 的第 02 號中斷服務 (顯示字元)；DX Low Byte 為要輸出的資料
	INT   21H          ; INT 21H: DOS 中斷	
	MOV   AH, 4CH      ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT   21H          ; INT 21H: DOS 中斷
END main
