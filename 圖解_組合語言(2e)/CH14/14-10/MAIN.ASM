 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build011823
 ;
 ; Date: 2023 / 01 / 18
 ;
 ; Description: 這乙章節很無聊！「INT 21H: DOS 中斷」的印表機輸出服務；
 ;              DOS 的第 05 號中斷服務 (印表機輸出)；DL (DX Low Byte)為要輸出的字元
 ;

.MODEL	SMALL

.STACK

.DATA

.CODE
main:
	MOV  AX, @DATA    ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX       ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV  AH, 05H      ; DOS 的第 05 號中斷服務 (印表機輸出)；DL (DX Low Byte)為要輸出的字元
	MOV  DL, 'a'      ; 將字元'a'移動到 DL (DX Low Byte)
	INT  21H          ; INT 21H: DOS 中斷
	MOV  AH, 4CH      ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H          ; INT 21H: DOS 中斷
END main
