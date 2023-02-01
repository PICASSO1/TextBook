 ;
 ; File Name: SUB_1.ASM
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

.CODE
	EXTRN  SUM: WORD    ; 使用關鍵字 EXTRN 來告訴程式，我們要使用外部變數 SUM (MAIN.ASM 宣告)，其資料長度為 Word (2 Bytes)
	PUBLIC BCD          ; 關鍵字 PUBLIC 告訴組譯器，BCD 這個函式大家都可以使用
BCD proc              ; 這是宣告一個函式的寫法；後面要加上關鍵字 proc
	MOV    AH, 00H      ; 先將 AX High Byte 設定為 0x00
	AAA                 ; 將整個 AX Register 調整為１０進制；原本 AH: 0x00; AL: 0x0D (13)
                      ; 調整後 AH: 0x01 (1); AL: 0x03 (3)
	ADD    AX, 3030H    ; 將整個 AX Register 的內容加上 0x3030，變成 AH: 0x31 ('1'); AL: 0x33 ('3')
	XCHG   AH, AL       ; AH & AL 內的資料彼此交換，變成 AH: 0x33 ('3'); AL: 0x31 ('1')
	MOV    SUM, AX      ; 將 Ax Register 的內容移動到 SUM 變數
	RET                 ; return 離開函式
BCD endp              ; 函式的結束，後面要加上 endp
END
