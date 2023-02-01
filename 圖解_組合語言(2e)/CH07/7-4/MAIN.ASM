 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build110922
 ;
 ; Date: 2022 / 11 / 09
 ;
 ; Description: 這個範例呈現字串載入指令 -- LODS (Load  String by Byte or Word)。
 ;              和前置重複指令 -- REPE (Repeat)。
 ;              還有字串比對指令 -- CMPSB (Compare String by Byte)。
 ;
 ;              LODS 這個指令：
 ;              - 將 DS:SI 記憶體位址上所指的字串，以 Byte or Word 為單位載入至 AL or AX。
 ;              - 搜尋且比對完成之後，SI 值會被 +1 / -1 (依照 STD / CLD)。
 ;
 ;              REPE 這個指令：
 ;              - 會有條件重複地執行 REPE 後面所接的動作；
 ;              - 而重複的次數，則是 CX Register 逐一遞減至０；或 Zero Flag == 0 為止。
 ;
 ;              CMPSB 這個指令：
 ;              - 需要搭配 REPE 指令來使用；
 ;              - 而比較的結果會清除或是設定 Zero Flag；
 ;              - 字串相同，ZF == 1；反之為０。
 ;

.MODEL	SMALL

.STACK

.DATA
	SOUR  DB  'TG is dood boy$'    ; 宣告變數名稱為 SOUR，將字串分別以 Byte 的資料型態儲存到 SOUR
	DEST  DB  'TG is good boy$'    ; 宣告變數名稱為 DEST，將字串分別以 Byte 的資料型態儲存到 DEST
	SLEN  DW  $-SOUR               ; 宣告變數名稱為 SLEN，將 SOUR 的字串長度以 Word 的資料型態儲存

.CODE
main:
	MOV   AX, @DATA                ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV   DS, AX                   ; 把 AX Register 的記憶體位址設定給 Data Segment Register；
	MOV   ES, AX                   ; 把 AX Register 的記憶體位址設定給 Extra Segment Register；
	CLD                            ; 這裡使用 CLD 狀態，由記憶體位址「低」的地方往「高」處移動。
	MOV   CX, SLEN                 ; 將 SOUR 的字串長度移動到 CX Register
	LEA   SI, SOUR                 ; 將 SOUR 變數的偏移量，儲存到 SI Register
	LEA   DI, DEST                 ; 將 DEST 變數的偏移量，儲存到 DI Register
	REPE  CMPSB                    ; 比較２組字串是否相同？
	JCXZ  ENDDOS                   ; 若 CX Register 為０時 (Jump CX Zero)，就跳躍到 ENDDOS 標籤執行下一段程式碼；
	                               ; 若 CMPSB 找到相異字元時，則 CX Register 不會等於０
	DEC   SI                       ; SI Register 再 -1，因為是使用 CLD 狀態。
	LODS  SOUR                     ; 將 SOUR 載入至 AL Register
	MOV   DL, AL                   ; 將 AL Register 的資料移動至 DL Register
	MOV   AH, 02H                  ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的資料
	INT   21H                      ; INT 21H: DOS 中斷	

ENDDOS:
	MOV   AH, 4CH                  ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT   21H                      ; INT 21H: DOS 中斷
END main
