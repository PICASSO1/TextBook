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
 ; Description: 攔截修改程式原先的 ISR (Interrupt Service Routine)程序 (INT 31H)。
 ;

.MODEL	SMALL

.STACK

.DATA

.CODE
main:
	JMP  AA                  ; 直接跳到 AA 標籤所在之處開始執行
INT1C:
	MOV  AX, 0B800H          ; 將 0xB800 設定給 .EXTRA Segment Register
	MOV  ES, AX
	MOV  DI, 00H             ; 將 DI Register 設定成 0x00
	MOV  CX, 01H             ; 將 CX Register 設定成 1
	MOV  AL, 01H             ; 將 AL (AX Low Byte)設定成 0x01
	MOV  AH, 07H             ; 將 AH (AX High Byte)設定成 0x07
	REP  STOSW               ; 重覆執行 STOSW 指令 100 次；Store TO String by Word, 
	                         ; 將 AX Register 的內容 (0x0701)移動至 ES:DI 所指定的記憶體位址上 (B800:0000)
	IRET                     ; 執行完之後要離開中斷向量的區間 .... 
NUL SEGMENT                      ; 標記一個空白區段 (NULL Segment) .... 
NUL ENDS
AA:
	PUSH CS                  ; 將 .CODE Segment Register 的記憶體位址先移動至 .STACK Segment
	POP  DS                  ; 從 .STACK Segment 取值再放進 .DATA Segment；
	                         ; 即將 .CODE Segment Register 的內容移動至 .DATA Segment Register
	MOV  DX, OFFSET INT1C    ; 將標籤 INT1C 的記憶體位址，再加上偏移量，移動至 DX Register
	MOV  AL, 1CH             ; 設定中斷向量編號為 1CH
	MOV  AH, 25H             ; DOS 的第 25 號中斷服務 (設定中斷向量)；AL (AX Low Byte)為中斷向量的定義值
	INT  21H                 ; INT 21H: DOS 中斷
	MOV  AH, 62H             ; DOS 的第 62 號中斷服務─取得 .CODE Segment 的記憶體位址，存放在 BX Register
	INT  21H                 ; INT 21H: DOS 中斷	
	MOV  DX, SEG NUL         ; 將空白區段 (NULL Segment)的長度存放至 DX Register
	SUB  DX, BX              ; 計算中斷程序的長度 (DX)
	MOV  AH, 31H             ; 更換原本的 ISR ；而新的 ISR (INT05)的記憶體位址就是 DS:DX 
	INT  21H                 ; INT 21H: DOS 中斷
	MOV  AH, 4CH             ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H                 ; INT 21H: DOS 中斷
END main
