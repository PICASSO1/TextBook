 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build012223
 ;
 ; Date: 2023 / 01 / 22
 ;
 ; Description: 乘法運算
 ;

.MODEL	SMALL

.STACK

.DATA
	NUM1 DB  6
	NUM2 DB  3
	MSG  DB  '6 * 3 = $'

.CODE
main:
	MOV  AX, @DATA         ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX            ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV  DX, OFFSET MSG    ; 將 MSG 的記憶體位址，再加上偏移量，移動到 DX Register
	MOV  AH, 09H           ; DOS 的第 09 號中斷服務 (顯示字串)；DX Register 為要顯示的位址
	INT  21H               ; INT 21H: DOS 中斷
	MOV  AL, NUM1          ; 將 NUM1 移動到 AL (AX Low Byte)
	MOV  DL, NUM2          ; 將 NUM2 移動到 DL (DX Low Byte)
	MUL  DL                ; 被乘數 (AL == NUM1 == 0x06) * 乘數 (DL == NUM2 == 0x03)的積 (0x12 == 18)儲存回 AX Register
	AAM                    ; 將整個 AX Register 調整為１０進制；原本 AH: 0x00; AL: 0x12
	                       ; 調整後 AH: 0x01 (1); AL: 0x08 (8)
	MOV  BX, AX            ; 將 AX Register 的內容移動到 BX Register
	MOV  DL, BH            ; 將 BH (BX High Byte)的內容 (0x01)移動到 DL (DX Low Byte)
	ADD  DL, '0'           ; 將 DL (DX Low Byte)內的數值 (0x01)轉換成字元 ('1')
	MOV  AH, 02H           ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的字元
	INT  21H               ; INT 21H: DOS 中斷
	MOV  DL, BL            ; 將 BL (BX Low Byte)的內容 (0x08)移動到 DL (DX Low Byte)
	ADD  DL, '0'           ; 將 DL (DX Low Byte)內的數值 (0x08)轉換成字元 ('8')
	MOV  AH, 02H           ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的字元
	INT  21H               ; INT 21H: DOS 中斷
	MOV  AH, 4CH           ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H               ; INT 21H: DOS 中斷
END main
