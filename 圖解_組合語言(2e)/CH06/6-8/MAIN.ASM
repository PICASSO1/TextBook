 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build103122
 ;
 ; Date: 2022 / 10 / 31
 ;
 ; Description: 這個範例呈現算術指令中的邏輯指令 -- AND。
 ;              此一範例會將小寫字母轉換成大寫字母。
 ;              受影響的 Flag Register 位元：SF, ZF, PF, CF = 0, OF = 0
 ;

.MODEL	SMALL

.STACK

.DATA
	MSG  DB               'abcdefghijklmnopqrstuvwxyz$'
	                      ; 我們定義一個變數 MSG ，裡面存放 a ~ z，且最後記得用 '$' 做結尾
	SUMM EQU              $-MSG
	                      ; '$' 代表「目前的記憶體位址」；而 $ - MSG 的記憶體位址 ('a')等
	                      ; 價於字串長度，即 SUMM == 26
.CODE
main:
	MOV  AX, @DATA        ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV  DS, AX           ; 把 AX Register 的記憶體位址設定給 Data Segment Register；
	                      ; 換句話說，就是把 .DATA Segment 此時的記憶體位址，設定給 Data Segment Register  
	MOV  BX, 0H           ; 把數值 0 移動到 BX Register
	MOV  CX, SUMM         ; 把 SUMM (26) 移動到 CX Register
again:
	MOV  DL, MSG[BX]      ; 這種寫法想像成Ｃ語言的陣列存取即可！
	AND  DL, 11011111B    ; 這個動作，就是把小寫字母轉換成大寫字母。
	MOV  AH, 02H          ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的資料
	INT  21H              ; INT 21H: DOS 中斷
	INC  BX               ; 把 MSG 的記憶體位址 +1 
	LOOP again            ; 跳到 again 開始的地方，不斷重複。
	MOV  AH, 4CH          ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H              ; INT 21H: DOS 中斷
END main
