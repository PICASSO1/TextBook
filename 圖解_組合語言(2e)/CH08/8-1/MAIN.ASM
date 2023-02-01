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
 ; Description: 此一程序的用意可以讓使用者輸入１~３然後會顯示相對應的字串
 ;              示範了 CMP 和無條件跳躍指令 JMP 的用法
 ;              而有條件跳躍指令，除了 Jump Equal (Zero Flag == 1)之外，總共還有１７種
 ;              不再一一列舉
 ;

.MODEL	SMALL

.STACK

.DATA
	MSG1  DB '=>KEY IN NUMBR 1$'    ; 宣告４組字串，裡面的元素以 Byte 的型態來儲存
	MSG2  DB '=>KEY IN NUMBR 2$'
	MSG3  DB '=>KEY IN NUMBR 3$'
	MSG4  DB '=>NOT KEY IN NUMBER 1 OR 2 OR 3$'

.CODE
main:
	MOV   AX, @DATA                 ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV   DS, AX                    ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV   AH, 01H                   ; DOS 的第 01 號中斷服務 (從鍵盤讀取輸入並顯示)；AX Low Byte 會顯示要輸入的字元
	INT   21H                       ; INT 21H: DOS 中斷
	CMP   AL, '1'                   ; 如果 AX Low Byte 的值等價於 0x31 ('1')
	JE    PMSG1                     ; 此時 Zero Flag == 1 進行 Jump Equal 到 PMSG1 標籤所在的程式碼
	CMP   AL, '2'                   ; 如果 AX Low Byte 的值等價於 0x32 ('2')
	JE    PMSG2                     ; 此時 Zero Flag == 1 進行 Jump Equal 到 PMSG2 標籤所在的程式碼
	CMP   AL, '3'                   ; 如果 AX Low Byte 的值等價於 0x33 ('3')
	JE    PMSG3                     ; 此時 Zero Flag == 1 進行 Jump Equal 到 PMSG3 標籤所在的程式碼
	JMP   PMSG4                     ; 此時 Zero Flag == 1 進行 Jump Equal 到 PMSG4 標籤所在的程式碼
PMSG1:
	MOV   DX, OFFSET MSG1           ; 將 MSG1 所在的記憶體位址，再加上偏移量；移動到 DX Register
	MOV   AH, 09H                   ; DOS 的第 09 號中斷服務 (顯示字串)；AX Register 為要開始顯示的位址
	INT   21H                       ; INT 21H: DOS 中斷
	JMP   ENDDOS                    ; 直接跳到 ENDDOS 標籤所在的程式碼
PMSG2:
	MOV   DX, OFFSET MSG2
	MOV   AH, 09H
	INT   21H
	JMP   ENDDOS
PMSG3:
	MOV   DX, OFFSET MSG3
	MOV   AH, 09H
	INT   21H
	JMP   ENDDOS
PMSG4:
	MOV   DX, OFFSET MSG4
	MOV   AH, 09H
	INT   21H
	JMP   ENDDOS
ENDDOS:
	MOV   AH, 4CH                   ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT   21H                       ; INT 21H: DOS 中斷
END main
