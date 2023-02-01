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
 ; Description: 這一個範例呈現了呼叫外部函式 (在別的檔案)和「傳遞參數」的寫法。
 ;

.MODEL	SMALL

.STACK

.DATA
	NUM1   DB 7              ; 宣告一個變數 NUM1 ，將數值７以 Byte 的資料型態來儲存
	NUM2   DB 6              ; 宣告一個變數 NUM2 ，將數值６以 Byte 的資料型態來儲存
	SUM    DW ?, '$'         ; 宣告一個變數 SUM ，其資料長度為 Word (2 Bytes)且全部初始化為'$'

.CODE
	PUBLIC SUM               ; 關鍵字 PUBLIC 告訴組譯器，變數 SUM 大家都可以使用
  EXTRN  BCD: NEAR, PrintStr: NEAR
	                         ; 使用關鍵字 EXTRN 來告訴程式，我們要使用兩個外部函式 BCD 和 PrintStr ;
	                         ; 而 NEAR 表示 PrintStr / BCD 和 main 都在同一個 .CODE Segment ；反之則用 FAR
main:
	MOV    AX, @DATA         ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV    DS, AX            ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV    AL, NUM1          ; 將 NUM1 的內容移動到 AX Low Byte
	ADD    AL, NUM2          ; 將 AX Low Byte 的內容 (NUM1, 7)再加上 NUM2 (6)，並儲存回 AX Low Byte (13)
	CALL   BCD               ; 呼叫函式 BCD
	LEA    DX, SUM           ; 將 SUM 的記憶體位址傳送給 DX Register
	CALL   PrintStr          ; 呼叫函式 PrintStr
	JMP    ENDDOS            ; 直接跳到 ENDDOS 標籤所在的地方
ENDDOS:
	MOV    AH, 4CH           ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT    21H               ; INT 21H: DOS 中斷
END main
