 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build011923
 ;
 ; Date: 2023 / 01 / 19
 ;
 ; Description: 這乙章節很無聊！「INT 21H: DOS 中斷」的印表機輸出服務；
 ;              DOS 的第 05 號中斷服務 (印表機輸出)；DL (DX Low Byte)為要輸出的字元
 ;              承範例 14-10 ，此一範例展現如何使用印表機來列印字串。
 ;              列印字串的方式，是以一個字元、一個字元地依序輸出。
 ;

.MODEL	SMALL

.STACK

.DATA
	MSG  DB  'TG is good!! $'
	LEN  DW  $-MSG

.CODE
main:
	MOV  AX, @DATA    ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX       ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV  CX, LEN      ; 把字串的長度 LEN 移動到 CX Register
	LEA  SI, MSG      ; 將字串 MSG 的記憶體位址存入到 SI Register
next:
	MOV  AH, 05H      ; DOS 的第 05 號中斷服務 (印表機輸出)；DL (DX Low Byte)為要輸出的字元
	MOV  DL, [SI]     ; 將 SI Register 的「內容」移動到 DL (DX Low Byte)
	INT  21H          ; INT 21H: DOS 中斷
	INC  SI           ; 將 SI Register 的值 +１；即指到下一個字元的記憶體位址
	LOOP next         ; 重覆 next 標籤的行為，直到 CX == 0 為止！
	MOV  AH, 4CH      ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H          ; INT 21H: DOS 中斷
END main
