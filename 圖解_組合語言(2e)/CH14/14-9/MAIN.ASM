 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build012023
 ;
 ; Date: 2023 / 01 / 20
 ;
 ; Description: 這乙章節很無聊！「INT 16H: BIOS 中斷」的鍵盤中斷服務；
 ;              BIOS 的第 02 號中斷服務─回傳鍵盤控制鍵的狀態；其狀態值會回傳到 AL (AX Low Byte)
 ;              AL (AX Low Byte)的內容定義如下：
 ;              Bit 0: 按下左邊的 Shift 鍵
 ;              Bit 1: 按下右邊的 Shift 鍵
 ;              Bit 2: 按下 Ctrl 鍵
 ;              Bit 3: 按下 Alt 鍵
 ;              Bit 4: 按下 Scroll Lock 鍵
 ;              Bit 5: 按下 Num Lock 鍵
 ;              Bit 6: 按下 CAPs Lock 鍵 
 ;              Bit 7: 按下 Insert 鍵
 ;

@PrintStr  MACRO  MSG         ; 定義一個名為 PrintStr 的巨集，會傳遞一個參數名為 MSG 
	MOV  DX, OFFSET MSG   ; 將 MSG 的記憶體位址，再加上偏移量，移動到 DX Register
	MOV  AH, 09H          ; DOS 的第 09 號中斷服務 (顯示字串)；DX Register 為要顯示的位址
	INT  21H              ; INT 21H: DOS 中斷
ENDM

POPPUSHAX  MACRO              ; 定義一個名為 POPPUSHAX 的巨集；並沒有傳遞任何參數
	POP  AX               ; 把 Stack Segment 的內容，移動到 AX Register
	PUSH AX               ; 把 AX Register 的內容，移動到 Stack Segment
ENDM

.MODEL	SMALL

.STACK

.DATA
	MSG1 DB  'USER press the Right Shift!! $'
	MSG2 DB  'USER press the Left Shift!! $'
	MSG3 DB  'USER press the Right Ctrl!! $'
	MSG4 DB  'USER press the Left Alt!! $'
	MSG5 DB  'keyboard Scroll is light!! $'
	MSG6 DB  'keyboard Num Lock is light!! $'
	MSG7 DB  'keyboard CAPs Lock is light!! $'
	MSG8 DB  'USER press Insert!! $'

.CODE
main:
	MOV  AX, @DATA        ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX           ; 把 AX Register 的記憶體位址設定給 Data Segment Register
START:
	MOV  AH, 02H          ; BIOS 的第 02 號中斷服務─回傳鍵盤控制鍵的狀態
	INT  16H              ; INT 16H: BIOS 中斷；

	PUSH AX               ; 把 AX Register 的內容，移動到 Stack Segment
	AND  AL, 00000001B    ; 將 AL (AX Low Byte)的內容，和 0x01 做 AND 運算
	CMP  AL, 01H          ; 倘若值為 0x01
	JE   RSHIFT           ; 就跳到 RSHIFT 標籤所在的地方
                              ; 以下雷同，予以省略！
	POPPUSHAX
	AND  AL, 00000010B
	CMP  AL, 02H
	JE   LSHIFT

	POPPUSHAX
	AND  AL, 00000100B
	CMP  AL, 04H
	JE   CTRL

	POPPUSHAX
	AND  AL, 00001000B
	CMP  AL, 08H
	JE   ALT

	POPPUSHAX
	AND  AL, 00010000B
	CMP  AL, 10H
	JE   SCROLL

	POPPUSHAX
	AND  AL, 00100000B
	CMP  AL, 20H
	JE   NUM

	POPPUSHAX
	AND  AL, 01000000B
	CMP  AL, 40H
	JE   CAPS

	POPPUSHAX
	AND  AL, 10000000B
	CMP  AL, 80H
	JE   INTS

WAITX:
	MOV  AH, 01H          ; BIOS 的第 01 號中斷服務─檢查鍵盤的狀態
	INT  16H              ; INT 16H: BIOS 中斷；
	JNE  ENDDOS           ; 當 Zero Flag != 1 的時候，跳躍到 ENDDOS 標籤所在的地方
	JMP  START            ; 反之，則是跳躍到 START 標籤所在的地方

RSHIFT:
	@PrintStr  MSG1
	JMP  ENDDOS
LSHIFT:
	@PrintStr  MSG2
	JMP  ENDDOS
CTRL:
	@PrintStr  MSG3
	JMP  ENDDOS
ALT:
	@PrintStr  MSG4
	JMP  ENDDOS
SCROLL:
	@PrintStr  MSG5
	JMP  ENDDOS
NUM:
	@PrintStr  MSG6
	JMP  ENDDOS
CAPS:
	@PrintStr  MSG7
	JMP  ENDDOS
INTS:
	@PrintStr  MSG8
	JMP  ENDDOS

ENDDOS:
	MOV  AH, 4CH          ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H              ; INT 21H: DOS 中斷
END main
