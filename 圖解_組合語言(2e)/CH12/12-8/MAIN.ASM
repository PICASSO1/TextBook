 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build010923
 ;
 ; Date: 2023 / 01 / 09
 ;
 ; Description: 這是一個用 .STACK Segment 來暫存資料的範例。
 ;              Stack (堆疊)是一種 FILO (Fisrt In, Last Out; 先進後出)的資料表示；
 ;              以下的範例 BX & DX Register 的內容會交換！
 ;

.MODEL	SMALL

.STACK

.DATA

.CODE
main:
	MOV  DX, 1234H    ; 將數值 0x1234 移動到 DX Register
	MOV  BX, 0506H    ; 將數值 0x0506 移動到 BX Register
	PUSH DX           ; 將 DX Register 的內容移動到 .STACK Segment
	PUSH BX           ; 將 BX Register 的內容移動到 .STACK Segment
	POP  DX           ; 將 .STACK Segment 的內容取出，移動到 DX Register (0x0506)
	POP  BX           ; 將 .STACK Segment 的內容取出，移動到 BX Register (0x1234)
	MOV  AH, 02H      ; DOS 的第 02 號中斷服務 (顯示字元輸出)；DL (DX Low Byte)為要輸出的字元 (0x06)
	INT  21H          ; INT 21H: DOS 中斷
	MOV  AH, 4CH      ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H          ; INT 21H: DOS 中斷
END main
