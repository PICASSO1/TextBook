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
 ;              DOS 的第 0C 號中斷服務；清除鍵盤的緩衝區，並執行 AX Low Byte 所指定的功能
 ;              此時的 AX Low Byte 限定為：01H, 06H, 07H, 08H, 0AH
 ;              若為 00H 僅清除鍵盤的緩衝區，且程式終止 (等價於 INT 20H)
 ;

.MODEL	SMALL

.STACK

.DATA

.CODE
main:
	MOV  AX, @DATA    ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX       ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV  AL, 01H      ; DOS 的第 01 號中斷服務 (由鍵盤輸入字元並顯示)；AL (AX Low Byte)為輸入的字元
	MOV  AH, 0CH      ; DOS 的第 0C 號中斷服務；清除鍵盤的緩衝區，並執行 AX Low Byte 所指定的功能
	INT  21H          ; INT 21H: DOS 中斷
	MOV  AH, 4CH      ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H          ; INT 21H: DOS 中斷
END main
