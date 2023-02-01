 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build010323
 ;
 ; Date: 2023 / 01 / 03
 ;
 ; Description: 「暫存器間接定址法」：顧名思義，暫存器所存放的資料是記憶體位址；
 ;              將運算元中的暫存器以 [] 含括住，代表暫存器間接定址法。
 ;

.MODEL	SMALL

.STACK

.DATA
	T    DB  'ABCDEFGHIJKLMNOPQRSTUVWXYZ$'

.CODE
main:
	MOV  AX, @DATA  ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX     ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV  BX, 02H    ; 將數值 0x02 移動到 BX Register ；因為字串是從「位移兩個位址處」開始存放
	MOV  DL, [BX]   ; 將 BX Register 中的記憶體位址 (0x02)，移動到 DX Low Byte
	MOV  AH, 02H    ; DOS 的第 02 號中斷服務 (顯示字元輸出)；DL (DX Low Byte)為要輸出的字元
	INT  21H        ; INT 21H: DOS 中斷
	MOV  AH, 4CH    ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H        ; INT 21H: DOS 中斷
END main
