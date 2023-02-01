 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build011723
 ;
 ; Date: 2023 / 01 / 17
 ;
 ; Description: 這乙章節很無聊！「INT 21H: DOS 中斷」的鍵盤中斷服務；
 ;              DOS 的第 07 號中斷服務 (由鍵盤輸入字元，但並不顯示在螢幕上)；AL (AX Low Byte)為輸入的字元
 ;              與第 01 號中斷服務的差異：無法使用 Ctrl + C 來中斷；會等待使用者按下任意鍵。
 ;

.MODEL	SMALL

.STACK

.DATA

.CODE
main:
	MOV  AX, @DATA    ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX       ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV  AH, 07H      ; DOS 的第 07 號中斷服務 (由鍵盤輸入字元，但並不顯示在螢幕上)；AL (AX Low Byte)為輸入的字元
	INT  21H          ; INT 21H: DOS 中斷
	MOV  DL, AL       ; 將 AL (AX Low Byte) 的內容移動到 DL (DX Low Byte)
	MOV  AH, 02H      ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為輸出的字元
	INT  21H          ; INT 21H: DOS 中斷
	MOV  AH, 4CH      ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H          ; INT 21H: DOS 中斷
END main
