 ;
 ; File Name: 9-7.ASM
 ;
 ; CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build121122
 ;
 ; Date: 2022 / 12 / 11
 ;
 ; Description: 此章節的所有範例都是在介紹 Assembly 的「結構流程虛擬指令」，
 ;              但必須在 "MASM 6.X" 以上的版本方能正常執行！
 ;              目前程式碼的執行環境是 DOSBox v0.74-3 + MASM 5.00 所以無法正常執行。
 ;              而 8086 Emulator 的 Assembler 也不夠新，亦無法正常執行。
 ;

.MODEL	SMALL

.STACK	100H                             ; 這一行是幹嘛的？

.DATA

.CODE
main:
	MOV    AX, @DATA                 ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV    DS, AX                    ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	.REPEAT
		MOV    AH, 01H           ; DOS 的第 01 號中斷服務 (從鍵盤上讀取輸入，並輸出至螢幕)；AL (AX Low Byte)為要顯示的字元
		INT    21H               ; INT 21H: DOS 中斷
	.UNTIL AL == 'Q' || AL == 'q'    ; 直到 AX Low Byte 內的值為'Q'或'q'，就跳離 REPEAT - UNTIL 迴圈
	MOV    AH, 4CH                   ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT    21H                       ; INT 21H: DOS 中斷
END main
