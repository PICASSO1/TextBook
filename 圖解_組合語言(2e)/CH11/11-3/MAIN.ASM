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
 ; Description: 這個範例展現了連續 include 兩個標頭檔。。。。。
 ;

INCLUDE DOS.H
INCLUDE MATH.H

.MODEL	SMALL

.STACK

.DATA
	NUM1        DB  3
	NUM2        DB  1

.CODE
main:
	MOV         AX, @DATA    ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV         DS, AX       ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV         AL, NUM1     ; 將 NUM1 的內容移動到 AX Low Byte
	@TG_ADD     AL, NUM2     ; 呼叫 TG_ADD 加法巨集，並傳遞 AX Low Byte 和 NUM2 兩個參數，結果會移動到 AL
	@ASCChar    AL           ; 將 AX Low Byte 內的「數值」以「字元」的型態呈現 (4)
	MOV         DL, AL       ; 將 AX Low Byte 的內容移動到 DX Low Byte
	@PrintChar  DL           ; 將 DX Low Byte 的內容列印出來
	MOV         AL, NUM1     ; 將 NUM1 的內容移動到 AX Low Byte
	@TG_SUB     AL, NUM2     ; 呼叫 TG_SUB 減法巨集，並傳遞 AX Low Byte 和 NUM2 兩個參數，結果會移動到 AL
	@ASCChar    AL           ; 將 AX Low Byte 內的「數值」以「字元」的型態呈現 (2)
	MOV         DL, AL       ; 將 AX Low Byte 的內容移動到 DX Low Byte
	@PrintChar  DL           ; 將 DX Low Byte 的內容列印出來
	@EndDos                  ; 呼叫 EndDos 巨集
END main
