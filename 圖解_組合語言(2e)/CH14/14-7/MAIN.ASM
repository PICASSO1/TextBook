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
 ; Description: 這乙章節很無聊！「INT 16H: BIOS 中斷」的鍵盤中斷服務；
 ;              BIOS 的第 00 號中斷服務；從鍵盤的緩衝區讀取鍵盤碼
 ;              回傳值：AH (AX High Byte)為緩衝區讀取到的鍵盤碼；AL (AX Low Byte)為 ASCII 碼。
 ;

.MODEL	SMALL

.STACK

.DATA

.CODE
main:
	MOV  AX, @DATA    ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX       ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV  AH, 00H      ; BIOS 的第 00 號中斷服務：從鍵盤的緩衝區讀取鍵盤碼
	INT  16H          ; INT 16H: BIOS 中斷；此時的狀態是等待輸入
	PUSH AX           ; 將 AX Register 的內容移動到 Stack Segment
	MOV  DL, 0DH      ; 將數值 0x0D 移動到 DL (DX Low Byte)
	MOV  AH, 02H      ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為輸出的字元
	INT  21H          ; INT 21H: DOS 中斷
	POP  AX           ; 將 Stack Segment 的內容移動到 AX Register；此時的內容為剛剛所讀取到的鍵盤碼及其 ASCII 碼
	MOV  DL, AL       ; 將 AL (AX Low Byte)的內容移動到 DL (DX Low Byte)
	MOV  AH, 02H      ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為輸出的字元
	INT  21H          ; INT 21H: DOS 中斷
	MOV  AH, 4CH      ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H          ; INT 21H: DOS 中斷
END main
