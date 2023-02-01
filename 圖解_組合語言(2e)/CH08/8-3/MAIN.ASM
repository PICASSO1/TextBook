 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build120322
 ;
 ; Date: 2022 / 12 / 03
 ;
 ; Description: 此一範例呈現了旗標設定指令的用法
 ;              CLC (Clear Carry Flag): 將 Carry Flag 設定為０
 ;              CMC (Complements Carry Flag): 取 Carry Flag 的補數 (NOT Carry Flag)
 ;              STC (Set To Carry Flag): 將 Carry Flag 設定為１
 ;

.MODEL	SMALL

.STACK

.DATA
	NUM1  DB 2         ; 宣告變數名稱為 NUM1，將數值２以 Byte 的資料型態儲存到 NUM1
	NUM2  DB 3         ; 宣告變數名稱為 NUM2，將數值３以 Byte 的資料型態儲存到 NUM2

.CODE
main:
	MOV   AX, @DATA    ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV   DS, AX       ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV   BH, NUM1     ; 將 NUM1 (2)移動到 BX High Byte
	MOV   BL, NUM2     ; 將 NUM2 (3)移動到 BX Low Byte
	CLC                ; 設定進位旗標值 Carry Flag 為０
	ADC   BL, BH       ; BX Low Byte (2) + BX High Byte (3) + Carry Flag (0) 再儲存回 BX Low Byte
	ADD   BL, '0'      ; 把此時的 BL (5) 再加上 '0' (0x30) = 0x35 ('5')
	MOV   DL, BL       ; 把 BL 的資料移動到 DL 作為輸出 (此時 AL 的值應為 0 且為回傳值)。
	MOV   AH, 02H      ; DOS 的第 02 號中斷服務 (顯示字元)；DX Low Byte 為要輸出的字元
	INT   21H          ; INT 21H: DOS 中斷	
	JMP   ENDDOS       ; 直接跳到 ENDDOS 標籤所在的程式碼
ENDDOS:
	MOV   AH, 4CH      ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT   21H          ; INT 21H: DOS 中斷
END main
