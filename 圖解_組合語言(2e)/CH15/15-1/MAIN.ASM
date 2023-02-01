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
 ; Description: 一位數加法運算：4 + 9 = 13
 ;

.MODEL	SMALL

.STACK

.DATA
	MSG0 DB  '4 + 9 = $'
	NUM1 DB  4
	NUM2 DB  9

.CODE
main:
	MOV  AX, @DATA          ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX             ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV  DX, OFFSET MSG0    ; 將 MSG0 的記憶體位址，再加上偏移量，移動到 DX Register
	MOV  AH, 09H            ; DOS 的第 09 號中斷服務 (顯示字串)；DX Register 為要顯示的位址
	INT  21H                ; INT 21H: DOS 中斷
	MOV  AH, 0              ; 將 AH (AX High Byte)初始化為 0x00
	MOV  AL, NUM1           ; 將 NUM1 的值 (0x04)移動到 AL (AX Low Byte)
	MOV  BH, NUM2           ; 將 NUM2 的值 (0x09)移動到 BH (BX High Byte)
	ADD  AL, BH             ; AL (0x04) + BH (0x09) == 0x0D (13)儲存回 AL (AX Low Byte)
	AAA                     ; 未包裝運算指令：將 AX (13)調整為１０進制；AH == 0x01; AL == 0x03
	MOV  BX, AX             ; 將 AX Register 的內容移動到 BX Register
	MOV  DL, BH             ; 將 BH (BX High Byte)的內容 (0x01)移動到 DL (DX Low Byte)
	ADD  DL, '0'            ; 將 DL (DX Low Byte)的內容 (0x01)轉換為字元 ('1')
	MOV  AH, 02H            ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的字元
	INT  21H                ; INT 21H: DOS 中斷
	MOV  DL, BL             ; 將 BL (BX Low Byte)的內容 (0x03)移動到 DL (DX Low Byte)
	ADD  DL, '0'            ; 將 DL (DX Low Byte)的內容 (0x03)轉換為字元 ('3')
	MOV  AH, 02H            ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的字元
	INT  21H                ; INT 21H: DOS 中斷
	MOV  AH, 4CH            ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H                ; INT 21H: DOS 中斷
END main
