 ;
 ; File Name: 9-1.ASM
 ;
 ; CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build120522
 ;
 ; Date: 2022 / 12 / 05
 ;
 ; Description: 此章節的所有範例都是在介紹 Assembly 的「結構流程虛擬指令」，
 ;              但必須在 "MASM 6.X" 以上的版本方能正常執行！
 ;              目前程式碼的執行環境是 DOSBox v0.74-3 + MASM 5.00 所以無法正常執行。
 ;              而 8086 Emulator 的 Assembler 也不夠新，亦無法正常執行。
 ;

.MODEL	SMALL

.STACK

.DATA
	MSG1   DB  'equal !$'        ; 宣告一個變數 MSG1 以 Byte 的資料型態來儲存
	MSG2   DB  'NOT equal !$'    ; 宣告一個變數 MSG2 以 Byte 的資料型態來儲存

.CODE
main:
	MOV    AX, @DATA             ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV    DS, AX                ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV    AX, 00H               ; 將 AX Register 初始化為０
	MOV    AH, 32H               ; 將數值 0x32 ('2')設定給 AX High Byte
	.IF AH == '2'
		MOV    DX, OFFSET MSG1
	.ENDIF
	.IF AH != '2'
		MOV    DX, OFFSET MSG2
	.ENDIF
	MOV    AH, 09H              ; DOS 的第 09 號中斷服務 (顯示字串)；DX Register 為要開始顯示的位址
	INT    21H                  ; INT 21H: DOS 中斷
	MOV    AH, 4CH              ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT    21H                  ; INT 21H: DOS 中斷
END main
