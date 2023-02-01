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
 ; Description: 這個範例呈現字串載入指令 -- STOSB (Store String by Byte)。
 ;
 ;              STOSB 這個指令：
 ;              - 將 AX / AL 記憶體位址上所指的字串，以 Byte 為單位拷貝到 ES:DI 所指定的記憶體位址。
 ;              - 且 DI 的值會依 STD / CLD 的設定而遞增或遞減。
 ;

.MODEL	SMALL

.STACK

.DATA
	SOUR  DB  'TG is a good boy$'    ; 宣告變數名稱為 SOUR，將字串內容以 Byte 的資料型態儲存
	SLEN  DW  $-SOUR                 ; 宣告變數名稱為 SLEN，計算字串的長度

.CODE
main:
	MOV   AX, @DATA                  ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV   DS, AX                     ; 把 AX Register 的記憶體位址設定給 Data Segment Register；
	MOV   ES, AX                     ; 把 AX Register 的記憶體位址設定給 Extra Segment Register；
	CLD                              ; 這裡使用 CLD 狀態，由記憶體位址「低」的地方往「高」處移動。
	MOV   AL, 'G'                    ; 設定 AL Register 中的資料為字元 'G' 
	LEA   DI, SOUR                   ; 將 SOUR 變數的偏移量，儲存到 DI Register
	MOV   CX, SLEN                   ; 將 SOUR 字串的長度設定給 CX Register
	REPNE SCASB                      ; 在 DI Register (SOUR) 中搜尋是否有 AX Low Byte ('G') 的字元
	JCXZ  ENDDOS                     ; 若 CX Register 為０時 (Jump CX Zero)，就跳躍到 ENDDOS 標籤執行下一段程式碼；
	                                 ; 若 SCASB 找到相同字元 ('G')時，則 CX Register 不會等於０
	MOV   AL, '*'                    ; 將字元 '*' 移動至 AX Low Byte；即將 'G' 取代為 '*'
	DEC   DI                         ; 因為有找到相對應的字元；此時的偏移量是停留在下一個字元 (' ')，
	                                 ; 所以要將偏移量 -1 回到 'G' 的地方
	STOSB SOUR                       ; 將 AX Low Byte 的資料 ('*') 儲存回 SOUR + OFFSET 的地方
	MOV   DX, OFFSET SOUR            ; 再將 SOUR 的記憶體位址設定給 DX Register 準備輸出
	MOV   AH, 09H                    ; DOS 的第 09 號中斷服務 (顯示字串)；DX Register 為要輸出的資料
	INT   21H                        ; INT 21H: DOS 中斷	
                                   
ENDDOS:                            
	MOV   AH, 4CH                    ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT   21H                        ; INT 21H: DOS 中斷
END main
