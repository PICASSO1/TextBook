 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build010223
 ;
 ; Date: 2023 / 01 / 02
 ;
 ; Description: 這一個範例呈現了函式的寫法和呼叫。
 ;

.MODEL	SMALL

.STACK

.DATA
	MSG    DB  'I LOVE ASSEMBLY LANGUAGE.$'
	                         ; 宣告一個字串變數 MSG 裡面的資料用 Byte 的方式來儲存
.CODE
main:
	MOV    AX, @DATA         ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV    DS, AX            ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	CALL   PrintStr          ; 呼叫函式 PrintStr
	JMP    ENDDOS            ; 直接跳到 ENDDOS 標籤所在的地方
ENDDOS:
	MOV    AH, 4CH           ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT    21H               ; INT 21H: DOS 中斷
PrintStr proc              ; 這是宣告一個函式的寫法；後面要加上關鍵字 proc
	MOV    DX, OFFSET MSG    ; 將變數 MSG 再加上 OFFSET 的偏移量的記憶體位址，移動到 DX Register
	MOV    AH, 09H           ; DOS 的第 09 號中斷服務 (顯示字串)；DX Register 為要顯示的位址
	INT    21H               ; INT 21H: DOS 中斷
	RET                      ; return 離開函式
PrintStr endp                    ; 函式的結束，後面要加上 endp
END main
