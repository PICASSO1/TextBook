 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build103022
 ;
 ; Date: 2022 / 10 / 30
 ;
 ; Description: 這個範例呈現算術指令中的乘法指令 -- IMUL。
 ;              IMUL 其實和 MUL 的處理方式是一樣的；差別在於 IMUL 多了正負號的處理。
 ;              將兩個運算元進行相乘，其特性為將乘數放進 AL or AX 暫存器再進行相乘。
 ;              "位元組" 和 "位元組" 相乘的時候 (Byte)：
 ;              "被乘數"放在AL，"乘數"放在一般暫存器or記憶體，積放在AX Register。
 ;              "字組" 和 "字組" 相乘的時候 (WORD, 2 Bytes)：
 ;              "被乘數"放在AX，"乘數"放在一般暫存器or記憶體，積放在 DX:AX。 
 ;              IMUL 會將最高位元的數值當作是正負號來處理；而 MUL 則是當成一般的數值。
 ;              受影響的 Flag Register 位元：OF, CF
 ;

.MODEL	SMALL

.STACK

.DATA
	NUM1 DB -2        ; 宣告變數名稱為 NUM1，將 1110 (-2) 以 Byte 的資料型態儲存到 NUM1
	NUM2 DB -3        ; 宣告變數名稱為 NUM2，將 1101 (-3) 以 Byte 的資料型態儲存到 NUM2

.CODE
main:
	MOV  AX, @DATA    ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV  DS, AX       ; 把 AX Register 的記憶體位址設定給 Data Segment Register；
	                  ; 換句話說，就是把 .DATA Segment 此時的記憶體位址，設定給 Data Segment Register
	MOV  DL, NUM2     ; 把 NUM2 (-2, 1110) 設定給 DX Low Byte
	MOV  AL, NUM1     ; 把 NUM1 (-3, 1101) 設定給 AX Low Byte
	IMUL DL           ; DL (-2, 1110) * AL (-3, 1101) = 0x06 (0110) (AL)
	MOV  DL, AL       ; 把 AL (0x06) 的資料移動到 DL 作為輸出 (此時 AL 的值應為 0 且為回傳值)。
	ADD  DL, '0'      ; 把此時的 DL (0x06) 再加上 '0' (0x30) = 0x36 ('6')
	MOV  AH, 02H      ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的資料
	INT  21H          ; INT 21H: DOS 中斷
	MOV  AH, 4CH      ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；BL (BX Low Byte)為回傳值
	INT  21H          ; INT 21H: DOS 中斷
END main
