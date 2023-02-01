 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build111522
 ;
 ; Date: 2022 / 11 / 15
 ;
 ; Description: 這個範例並沒有任何意義！只想呈現
 ;              字串載入指令 -- LODSW (Load  String by Word)；和
 ;              字串比對指令 -- CMPSW (Compare String by Word)。
 ;
 ;              LODSW 這個指令：
 ;              - 將 DS:SI 記憶體位址上所指的字串，以 Word 為單位載入至 AX。
 ;              - 搜尋且比對完成之後，SI 值會被 +2 / -2 (依照 STD / CLD)。
 ;
 ;              CMPSW 這個指令：
 ;              - 需要搭配 REPE / REPZ 指令來使用；
 ;              - 而比較的結果會清除或是設定 Zero Flag；
 ;              - 字串相同，ZF == 1；反之為０。
 ;

.MODEL	SMALL

.STACK

.DATA
	SOUR  DW  1278H            ; 宣告變數名稱為 SOUR，將數值 0x1278 以 Word 的資料型態儲存
	DEST  DW  1234H            ; 宣告變數名稱為 DEST，將數值 0x1234 以 Word 的資料型態儲存

.CODE
main:
	MOV   AX, @DATA            ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV   DS, AX               ; 把 AX Register 的記憶體位址設定給 Data Segment Register；
	MOV   ES, AX               ; 把 AX Register 的記憶體位址設定給 Extra Segment Register；
	STD                        ; 這裡使用 STD 狀態，由記憶體位址「高」的地方往「低」處移動。
	MOV   CX, 2                ; 設定 CMPSW 的比對次數....
	LEA   SI, SOUR             ; 將 SOUR 變數的偏移量，儲存到 SI Register
	LEA   DI, DEST             ; 將 DEST 變數的偏移量，儲存到 DI Register
	REPZ  CMPSW                ; 比較２組數值是否相同？
	JCXZ  ENDDOS               ; 若 CX Register 為０時 (Jump CX Zero)，就跳躍到 ENDDOS 標籤執行下一段程式碼；
	                           ; 若 CMPSW 找到相異字元時，則 CX Register 不會等於０
	ADD   SI, 02H              ; 如果這一輪的比對不一樣，就將 SI Register 的值 +２ 進行下一輪的比對
	LODSW SOUR                 ; 將 SOUR 載入至 AL Register
	MOV   DL, AL               ; 將 AL Register 的資料移動至 DL Register；此時 AL 的值應為 0x78 ('x')
	                           ; AX == 0x1278；AH == 0x12；AL == 0x78
	MOV   AH, 02H              ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的資料
	INT   21H                  ; INT 21H: DOS 中斷	

ENDDOS:
	MOV   AH, 4CH              ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT   21H                  ; INT 21H: DOS 中斷
END main
