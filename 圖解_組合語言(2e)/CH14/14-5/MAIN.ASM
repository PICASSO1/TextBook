 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build011923
 ;
 ; Date: 2023 / 01 / 19
 ;
 ; Description: 這乙章節很無聊！「INT 21H: DOS 中斷」的鍵盤中斷服務；
 ;              DOS 的第 0B 號中斷服務：檢查鍵盤的狀態
 ;              AL (AX Low Byte) == 0xFF ，鍵盤的緩衝區內「有」字元在等待輸入；
 ;              AL (AX Low Byte) == 0x00 ，鍵盤的緩衝區內「無」字元在等待輸入。
 ;

.MODEL	SMALL

.STACK

.DATA
	MSG1 DB  'keyboard buffer has characters $'
	MSG2 DB  'keyboard buffer has NOT characters $'

.CODE
main:
	MOV  AX, @DATA               ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX                  ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV  AH, 0BH                 ; DOS 的第 0B 號中斷服務─檢查鍵盤的狀態
	INT  21H                     ; INT 21H: DOS 中斷
	CMP  AL, 0FFH                ; 倘若 AL (AX Low Byte) 的內容等價於 0xFF
	JE   PRINTMSG1               ; 是，就跳到 PRINTMSG1 標籤所在的地方
	JMP  PRINTMSG2               ; 不是，就跳到 PRINTMSG2 標籤所在的地方
PRINTMSG1:
	MOV  DX, OFFSET MSG1         ; 將 MSG1 的記憶體位址，再加上偏移量，移動到 DX Register
	JMP  PRINTX                  ; 直接跳到 PRINTX 標籤所在的地方
PRINTMSG2:
	MOV  DX, OFFSET MSG2         ; 將 MSG2 的記憶體位址，再加上偏移量，移動到 DX Register
PRINTX:
	MOV  AH, 09H                 ; DOS 的第 09 號中斷服務 (顯示字串)；DX Register 為要顯示的位址
	INT  21H                     ; INT 21H: DOS 中斷
ENDDOS:
	MOV  AH, 4CH                 ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H                     ; INT 21H: DOS 中斷
END main
