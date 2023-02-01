 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build012123
 ;
 ; Date: 2023 / 01 / 21
 ;
 ; Description: 這乙章節很無聊！「INT 17H: Printer 中斷」的印表機輸入服務；
 ;              Printer 的第 02 號中斷服務─讀取印表機的狀態；其狀態值會回傳到 AH (AX High Byte)
 ;              AH (AX High Byte)的內容定義如下：
 ;              Bit 0: 逾時 (Over Time)
 ;              Bit 1: 保留 (Reserved)
 ;              Bit 2: 保留 (Reserved)
 ;              Bit 3: I/O 錯誤 (I/O Error)
 ;              Bit 4: 已選定印表機 (Printer is Set)
 ;              Bit 5: 紙張用罄 (NO Paper)
 ;              Bit 6: 確認 (Printer is Confirmed)
 ;              Bit 7: 閒置 (已準備好了) (Idle)
 ;

.MODEL	SMALL

.STACK

.DATA
	MSG1 DB  0DH, 0AH, 'Over Time. $'
	MSG2 DB  0DH, 0AH, 'I/O Error. $'
	MSG3 DB  0DH, 0AH, 'Printer is Set. $'
	MSG4 DB  0DH, 0AH, 'NO Paper!! $'
	MSG5 DB  0DH, 0AH, 'Printer is Confirmed. $'
	MSG6 DB  0DH, 0AH, 'Printer is Idle. $'

.CODE
main:
	MOV  AX, @DATA          ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX             ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV  AH, 02H            ; Printer 的第 02 號中斷服務─讀取印表機的狀態
	MOV  DX, 0              ; 將數值 0x00 移動到 DX Register (初始化)
	INT  17H                ; INT 17H: Printer 中斷；
NEXT0:
	PUSH AX                 ; 將 AX Register 的內容移動到 Stack Segment
	AND  AH, 00000001B      ; 將 AX Register 的內容，與數值 0x01 做 AND 運算；在儲存回 AX Register
	CMP  AH, 00000001B      ; 將 AX Register 的內容，與數值 0x01 做比較
	JNE  NEXT1              ; 當 Zero Flag != 1 的時候，跳躍到 NEXT1 標籤所在的地方
	MOV  AH, 09H            ; DOS 的第 09 號中斷服務 (顯示字串)；DX Register 為要顯示的位址
	MOV  DX, OFFSET MSG1    ; 將 MSG1 的記憶體位址，再加上偏移量，移動到 DX Register
	INT  21H                ; INT 21H: DOS 中斷
NEXT1:                          ; 以下類似，予以省略！
	POP  AX
	PUSH AX
	AND  AH, 00001000B
	CMP  AH, 00001000B
	JNE  NEXT2
	MOV  AH, 09H
	MOV  DX, OFFSET MSG2
	INT  21H
NEXT2:
	POP  AX
	PUSH AX
	AND  AH, 00010000B
	CMP  AH, 00010000B
	JNE  NEXT3
	MOV  AH, 09H
	MOV  DX, OFFSET MSG3
	INT  21H
NEXT3:
	POP  AX
	PUSH AX
	AND  AH, 00100000B
	CMP  AH, 00100000B
	JNE  NEXT4
	MOV  AH, 09H
	MOV  DX, OFFSET MSG4
	INT  21H
NEXT4:
	POP  AX
	PUSH AX
	AND  AH, 01000000B
	CMP  AH, 01000000B
	JNE  NEXT5
	MOV  AH, 09H
	MOV  DX, OFFSET MSG5
	INT  21H
NEXT5:
	POP  AX
	PUSH AX
	AND  AH, 10000000B
	CMP  AH, 10000000B
	JNE  ENDDOS
	MOV  AH, 09H
	MOV  DX, OFFSET MSG6
	INT  21H
ENDDOS:
	MOV  AH, 4CH            ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H                ; INT 21H: DOS 中斷
END main
