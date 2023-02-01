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
 ; Description: 「立即定址法」：直接將資料，存放在目的運算元中的記憶體位址上。
 ;

.MODEL	SMALL

.STACK

.DATA

.CODE
main:
	MOV  DL, 00E4H  ; 將數值 0x00E4 (228) 移動到 DX Low Byte
	MOV  AH, 02H    ; DOS 的第 02 號中斷服務 (顯示字元輸出)；DL (DX Low Byte)為要輸出的字元
	INT  21H        ; INT 21H: DOS 中斷
	MOV  AH, 4CH    ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H        ; INT 21H: DOS 中斷
END main
