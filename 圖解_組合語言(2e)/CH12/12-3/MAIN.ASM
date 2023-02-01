 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build010323
 ;
 ; Date: 2023 / 01 / 03
 ;
 ; Description: 「直接定址法」：組合語言當中的指令，所指定的「運算元」，為記憶體位址上的數值。
 ;

.MODEL	SMALL

.STACK

.DATA
	NUM  DB  0099H

.CODE
main:
	MOV  AX, @DATA  ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV  DS, AX     ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV  NUM, 32H   ; 將數值 0x32 ('2') 移動到變數 NUM
	MOV  DL, NUM    ; 將變數 NUM 的內容再移動到 DX Low Byte
	MOV  AH, 02H    ; DOS 的第 02 號中斷服務 (顯示字元輸出)；DL (DX Low Byte)為要輸出的字元
	INT  21H        ; INT 21H: DOS 中斷
	MOV  AH, 4CH    ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H        ; INT 21H: DOS 中斷
END main
