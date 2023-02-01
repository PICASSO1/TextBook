 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build012623
 ;
 ; Date: 2023 / 01 / 26
 ;
 ; Description: 自行撰寫一個新的 ISR (Interrupt Service Routine)程序 (INT 60H)。
 ;

.MODEL	SMALL

.STACK

.DATA

.CODE
main:
	PUSH CS                  ; 將 .CODE Segment Register 的記憶體位址先移動至 .STACK Segment
	POP  DS                  ; 從 .STACK Segment 取值再放進 .DATA Segment；
	                         ; 即將 .CODE Segment Register 的內容移動至 .DATA Segment Register
	MOV  DX, OFFSET INT60    ; 將標籤 INT60 的記憶體位址，再加上偏移量，移動至 DX Register
	MOV  AL, 60H             ; 設定中斷向量編號為 60H
	MOV  AH, 25H             ; DOS 的第 25 號中斷服務 (設定中斷向量)；AL (AX Low Byte)為中斷向量的定義值
	INT  21H                 ; INT 21H: DOS 中斷
PRINT:
	INT  60H                 ; INT 60H: 執行我們自行設定的中斷向量 (功能)
	JMP  ENDDOS              ; 直接跳到 ENDDOS 標籤所在的地方
INT60:
	MOV  AX, 0B800H          ; 將 0xB800 設定給 .EXTRA Segment Register
	MOV  ES, AX
	MOV  DI, 00H             ; 將 DI Register 設定成 0x00
	MOV  CX, 100             ; 將 CX Register 設定成 100
	MOV  AL, 01H             ; 將 AL (AX Low Byte)設定成 0x01
	MOV  AH, 07H             ; 將 AH (AX High Byte)設定成 0x07
	REP  STOSW               ; 重覆執行 STOSW 指令 100 次；Store TO String by Word, 
	                         ; 將 AX Register 的內容 (0x0701)移動至 ES:DI 所指定的記憶體位址上 (B800:0000)
	IRET                     ; 執行完之後要離開中斷向量的區間 .... 
ENDDOS:
	MOV  AH, 4CH             ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H                 ; INT 21H: DOS 中斷
END main
