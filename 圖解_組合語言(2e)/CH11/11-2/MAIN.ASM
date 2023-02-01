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
 ; Description: 這一個範例呈現了組合語言中 include 標頭檔案的寫法。
 ;

INCLUDE DOS.H

.MODEL	SMALL

.STACK

.DATA
	NUM1        DB  'H$'
	NUM2        DB  'apply$'

.CODE
main:
	MOV          AX, @DATA    ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV          DS, AX       ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	@PrintChar   NUM1         ; 呼叫 PrintChar 巨集並傳遞 NUM1 的內容
	@PrintString NUM2         ; 呼叫 PrintString 巨集並傳遞 NUM2 的內容
	@EndDos                   ; 呼叫 EndDos 巨集
END main
