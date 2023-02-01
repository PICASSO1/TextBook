 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build112322
 ;
 ; Date: 2022 / 11 / 23
 ;
 ; Description: 這個範例呈現未包裝運算指令 -- DAA (Decimal Adjust for Addition)。
 ;              - 在執行完 ADD 之後，可把 AX Low Byte 的值調整為１０進制；規則：
 ;                若 AL 的低 4 bit 介於 A ~ F 之間或 AF == 1 時，AL 的數值內容 +0x06 且 AF = 1
 ;                若 AL 的高 4 bit 介於 A ~ F 之間或 CF == 1 時，AL 的數值內容 +0x60 且 CF = 1
 ;              - 受影響的旗標為：SF、ZF、PF
 ;              - DAA 會搭配 ADD 來使用
 ;

.MODEL	SMALL

.STACK

.DATA
	NUM1  DB  0FH      ; 宣告變數名稱為 NUM1，將數值 0x0F (15)以 Byte 的資料型態儲存
	NUM2  DB  0CH      ; 宣告變數名稱為 NUM2，將數值 0x0C (12)以 Byte 的資料型態儲存

.CODE
main:
	MOV   AX, @DATA    ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV   DS, AX       ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV   AL, NUM1     ; 把 NUM1 的數值 (0x0F == 15) 設定給 AX Low Byte
	MOV   BL, NUM2     ; 把 NUM2 的數值 (0x0C == 12) 設定給 BX Low Byte
	ADD   AL, BL       ; 兩者相加之後，儲存回 AX Low Byte (0x1B == 27)
	DAA                ; 因為 AL 的低 4 bit (0xB)介於 A ~ F ，所以 AL 會再加上６
	MOV   DL, AL       ; 把 AL 的內容移動到 DL (0x21 == 33)
	ADD   DL, 30H      ; 將 DX Low Byte 的數值 (0x21)加上 0x30 ('0')變成可顯字元 ('Q')
	MOV   AH, 02H      ; DOS 的第 02 號中斷服務 (顯示字元)；DX Low Byte 為要輸出的資料
	INT   21H          ; INT 21H: DOS 中斷
	MOV   AH, 4CH      ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT   21H          ; INT 21H: DOS 中斷
END main
