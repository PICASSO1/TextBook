 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build011023
 ;
 ; Date: 2023 / 01 / 10
 ;
 ; Description: .STACK Segment 除了 PUSH & POP 指令之外，還有 PUSHAW & POPAW。
 ;              不過，以上這兩種指令只能夠在 80286 上執行；80386 並不支援此二種指令。
 ;              但此一範例經過改寫，亦能夠達到與教科書一樣的執行結果！
 ;

;.286                          ; 80286 support PUSHAW & POPAW instructions ONLY!!

.MODEL	SMALL

.STACK

.DATA
	MSG  DB  'TEST STACK',0DH,0AH,'$'

.CODE
main:
	MOV  AX, 1234H         ; 將數值 0x1234 移動到 AX Register
	MOV  BX, 5678H         ; 將數值 0x5678 移動到 BX Register
	MOV  CX, 9ABCH         ; 將數值 0x9ABC 移動到 CX Register
	MOV  DX, 0DE39H        ; 將數值 0xDE39 移動到 DX Register
;	PUSHAW                 ; 此一指令，等價於依序執行：PUSH AX, BX, CX, DX 和 Flag Register
	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	PUSHF                  ; 將 Flag Register 的內容移動到 Stack Segment
	MOV  AX, @DATA         ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX            ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV  DX, OFFSET MSG    ; 將 MSG 的記憶體位址，再加上偏移量，移動到 DX Register
	MOV  AH, 09H           ; DOS 的第 09 號中斷服務 (顯示字串)；DL (DX Low Byte)為要開始輸出的字串
	INT  21H               ; INT 21H: DOS 中斷
;	POPAW                  ; 此一指令，等價於依序執行：POP Flag Register, DX, CX, BX 和 AX
	POPF
	POP DX                 ; DX High Byte: 0xDE; DX Low Byte: 0x39 ('9')
	POP CX
	POP BX
	POP AX
	MOV  AH, 02H           ; DOS 的第 02 號中斷服務 (顯示輸出字元)；DL (DX Low Byte)為要輸出的字元
	INT  21H               ; INT 21H: DOS 中斷
	MOV  AH, 4CH           ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H               ; INT 21H: DOS 中斷
END main
