 ;
 ; File Name: 9-8.ASM
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

.STACK	100H                ; 這一行是幹嘛的？

.DATA

.CODE
main:
	MOV    AX, @DATA    ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV    DS, AX       ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV    AX, 0        ; 將數值０移動到 AX Register
	MOV    BX, 1        ; 將數值１移動到 BX Register
	.REPEAT             ; 這個 REPEAT - UNTIL 是在計算數值１~９的總和
		ADD    AX, BX     ; AX + BX 並儲存回 AX Register
		AAA               ; 將 AX Register 內的數值調整為１０進制的值
		INC    BX         ; 將 BX Register 內的數值 +1
	.UNTIL BX > 9       ; 倘若 BX Register 內的數值大於９就跳離迴圈
	ADD    AX, 3030H    ; 將 AX Register 內的值 (0x0405)加上 0x3030
	MOV    BX, AX       ; 將 AX Register 內的值 (0x3435)移動到 BX Register
	MOV    DL, BH       ; 將 BX High Byte 內的值 (0x34 == '4')移動到 DX Low Byte
	MOV    AH, 02H      ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的值
	INT    21H          ; INT 21H: DOS 中斷
	MOV    DL, BL       ; 將 BX Low Byte 內的值 (0x35 == '5')移動到 DX Low Byte
	MOV    AH, 02H      ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的值
	INT    21H          ; INT 21H: DOS 中斷
	MOV    AH, 4CH      ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT    21H          ; INT 21H: DOS 中斷
END main
