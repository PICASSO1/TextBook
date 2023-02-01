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
 ; Description: 「暫存器定址法」：組合語言當中的指令，所指定的「運算元」或是「資料」，都是指定存放在某一個暫存器當中。
 ;

.MODEL	SMALL

.STACK

.DATA

.CODE
main:
	MOV  AL, 64     ; 將數值 64 移動到 AX Low Byte
	MOV  DL, AL     ; 將 AX Low Byte 的內容移動到 DX Low Byte
	MOV  AH, 02H    ; DOS 的第 02 號中斷服務 (顯示字元輸出)；DL (DX Low Byte)為要輸出的字元
	INT  21H        ; INT 21H: DOS 中斷
	MOV  AH, 4CH    ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H        ; INT 21H: DOS 中斷
END main
