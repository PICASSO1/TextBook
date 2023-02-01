 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build011623
 ;
 ; Date: 2023 / 01 / 16
 ;
 ; Description: 這乙章節很無聊！「INT 21H: DOS 中斷」的鍵盤中斷服務；
 ;              DOS 的第 06 號中斷服務 (由鍵盤輸入字元的 I/O 控制)。若：
 ;              a). 由鍵盤直接輸入，DL (DX Low Byte) == 0xFF；回傳值：
 ;                  Flag Register 的 Zero Flag == 0 時，AL (AX Low Byte)為輸入的字元；但並不顯示在螢幕上 (因為是直接I/O 控制)
 ;                  Flag Register 的 Zero Flag == 1 時，無任何輸入
 ;              b). 直接輸出，DL (DX Low Byte) != 0xFF；沒有回傳值。
 ;

.MODEL	SMALL

.STACK

.DATA

.CODE
main:
	MOV  AX, @DATA    ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX       ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV  DL, 0FFH     ; 設定成「由鍵盤直接輸入」；先不管 Zero Flag .... 
	MOV  AH, 06H      ; DOS 的第 06 號中斷服務 (由鍵盤輸入字元的直接 I/O )；AL (AX Low Byte)為輸入的字元
	INT  21H          ; INT 21H: DOS 中斷
	MOV  AH, 4CH      ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H          ; INT 21H: DOS 中斷
END main
