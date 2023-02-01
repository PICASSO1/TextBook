 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build101622
 ;
 ; Date: 2022 / 10 / 16
 ;
 ; Description: MDFK!!
 ;

EN EQU 0Dh                                   ; EQU 假指令為「定義常數的宣告」
LF EQU 0Ah                                   ; 這兩行為：定義 EN 為 0x0D；LF 為 0x0A

.MODEL	SMALL

.CODE
main:
	mov ax, @data                        ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	mov ds, ax                           ; 再把 AX 暫存器的值，傳送給 Data Segment Register。
	mov dx, OFFSET mess                  ; 把 mess 的起始位址，加上偏移量 (OFFSET，此時應為０)，移動到 DX 暫存器
	mov ah, 09h                          ; DOS 的第 09 號中斷服務 (顯示字串)
	int 21h                              ; INT 21H: DOS 中斷
	mov ah, 4Ch                          ; DOS 的第 4C 號中斷服務 (帶回傳值結束)
	int 21h                              ; INT 21H: DOS 中斷

.DATA
mess DB 'Happy New Year!!', 0Dh, 0Ah         ; 0x0D, 0x0A == '\n'
     DB 'Welcome to 80x86! ', EN, LF, '$'    ; 字串必須以 '$' 做結尾

.STACK

END main

 ; 
 ; 假指令 DB 的用意：用來指定變數的資料，或數值的長度大小
 ; ┌─────────────┬────────┬──────────┐
 ; │ Instruction │  SIZE  │  LENGTH  │
 ; ├─────────────┼────────┼──────────┤
 ; │    BYTE     │  byte  │  1 Byte  │
 ; │     DB      │  byte  │  1 Byte  │
 ; │     DW      │  word  │  2 Byte  │
 ; │     DD      │  dword │  4 Byte  │
 ; │     DQ      │  qword │  8 Byte  │
 ; │     DT      │  tbyte │ 10 Byte  │
 ; └─────────────┴────────┴──────────┘
 ;
 ; EX: 
 ;     DB 0Dh, 0Ah    ; 其資料會被存成 0x0D, 0x0A (1 Byte)
 ;     DW 0Dh, 0Ah    ; 其資料會被存成 0x00, 0x0D, 0x00, 0x0A (2 Bytes)
 ;
 ; 09H, 4CH 必須查詢 DOS 的中斷向量表才知道其功能及用法。
 ;
