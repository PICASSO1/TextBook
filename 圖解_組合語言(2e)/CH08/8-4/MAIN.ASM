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
 ; Description: 此一範例呈現了迴圈指令的用法；
 ;              - LOOP:   指令會依照 CX Register 的值依序遞減，直到０為止
 ;              - LOOPE:  指令會依照 CX Register 的值依序遞減，直到０為止；或
 ;                        兩運算元「比較結果『不相等』」 (Zero Flag 會被設定成０)，直接停止迴圈
 ;              - LOOPNE: 指令會依照 CX Register 的值依序遞減，直到０為止；或
 ;                        兩運算元「比較結果『相等』」 (Zero Flag 會被設定成１)，直接停止迴圈
 ;

.MODEL	SMALL

.STACK

.DATA

.CODE
main:
	MOV   AX, @DATA    ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV   DS, AX       ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV   CX, 255      ; 設定迴圈 (Loop)的次數為 255
	MOV   DL, 00H      ; 先將數值０ (0x00)移動到 DX Low Byte
AGAIN:
	MOV   AH, 02H      ; DOS 的第 02 號中斷服務 (顯示字元)；DX Low Byte 為要輸出的字元
	INT   21H          ; INT 21H: DOS 中斷
	INC   DL           ; 將 DX Low Byte 裡的值 +1 
	LOOP  AGAIN        ; 直接到 AGAIN 標籤所在的程式碼繼續執行，且 CX Register 的值 -1 直到０為止
	JMP   ENDDOS       ; 直接跳到 ENDDOS 標籤所在的程式碼
ENDDOS:
	MOV   AH, 4CH      ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT   21H          ; INT 21H: DOS 中斷
END main
