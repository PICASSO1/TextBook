 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build112122
 ;
 ; Date: 2022 / 11 / 21
 ;
 ; Description: 這個範例呈現未包裝運算指令 -- AAD (ASCII Adjust Before Division)。
 ;              - 將 AX Register 的內容調整為十進制的值；其中：
 ;                高位元儲存至 AX High Byte；而低位元儲存至 AX Low Byte
 ;              - 亦稱為「未包裝除法調整指令」
 ;              - 受影響的旗標為：SF、ZF、PF
 ;              - AAD 會搭配 DIV 來使用
 ;

.MODEL	SMALL

.STACK

.DATA
	NUM1  DW  0504H    ; 宣告變數名稱為 NUM1，將數值 0x0504 (0000 0101 0000 0100)以 Word 的資料型態儲存
	NUM2  DW  0105H    ; 宣告變數名稱為 NUM2，將數值 0x0105 (0000 0001 0000 0101)以 Word 的資料型態儲存

.CODE
main:
	MOV   AX, @DATA    ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV   DS, AX       ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV   CX, NUM2     ; 把 NUM2 的數值 (0x0105) 設定給 CX Register
	MOV   AX, CX       ; 再將 CX 設定給 AX (因應 AAD 的運作)
	AAD                ; 將整個 AX Register 調整為１０進制；原本 AH: 0x01; AL: 0x05
	                   ; 調整後 AH: 0x00 (0); AL: 0x0F (15)
	MOV   CL, AL       ; 調整完後將 AX Low Byte 放到 CX Low Byte
	MOV   AX, NUM1     ; 再把 NUM1 的數值 0x0504 設定給 AX Register
	AAD                ; 將整個 AX Register 調整為１０進制；原本 AH: 0x05; AL: 0x04
	                   ; 調整後 AH: 0x00 (0); AL: 0x36 (54)
	DIV   CL           ; AL (0x36 == 54) / CL (0x0F == 15) = 3 (0x03) (AL) .... 9 (0x09) (AH) ----> AX == 0x0903
	MOV   BH, AH       ; 先將餘數 (AH)設定給 BX High Byte (為了後面的顯示)
	MOV   DL, AL       ; 將 AX Low Byte 的內容移置 DX Low Byte
	ADD   DL, 30H      ; 將 DX Low Byte 的數值 (0x03)加上 0x30 ('0')變成可顯字元 ('3')
	MOV   AH, 02H      ; DOS 的第 02 號中斷服務 (顯示字元)；DX Low Byte 為要輸出的資料
	INT   21H          ; INT 21H: DOS 中斷
	MOV   DL, BH       ; 將 BX High Byte 的內容移置 DX Low Byte
	ADD   DL, 30H      ; 將 DX Low Byte 的數值 (0x09)加上 0x30 ('0')變成可顯字元 ('9')
	MOV   AH, 02H      ; DOS 的第 02 號中斷服務 (顯示字元)；DX Low Byte 為要輸出的資料
	INT   21H          ; INT 21H: DOS 中斷
	MOV   AH, 4CH      ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT   21H          ; INT 21H: DOS 中斷
END main
