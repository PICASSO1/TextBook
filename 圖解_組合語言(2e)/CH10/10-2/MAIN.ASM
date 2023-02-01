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
 ; Description: 這一個範例呈現了呼叫外部函式 (在別的檔案)的寫法。
 ;

.MODEL	SMALL

.STACK

.DATA
	MSG    DB  'I LOVE ASSEMBLY LANGUAGE.$'
	                         ; 宣告一個字串變數 MSG 裡面的資料用 Byte 的方式來儲存
.CODE
  EXTRN  PrintStr: NEAR          ; 使用關鍵字 EXTRN 來告訴程式，我們要使用一個外部函式 PrintStr ;
	                         ; 而 NEAR 表示 PrintStr 和 main 都在同一個 .CODE Segment ；反之則用 FAR
main:
	MOV    AX, @DATA         ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV    DS, AX            ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV    DX, OFFSET MSG    ; 將變數 MSG 再加上 OFFSET 的偏移量的記憶體位址，移動到 DX Register
	CALL   PrintStr          ; 呼叫函式 PrintStr
	JMP    ENDDOS            ; 直接跳到 ENDDOS 標籤所在的地方
ENDDOS:
	MOV    AH, 4CH           ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT    21H               ; INT 21H: DOS 中斷
END main
