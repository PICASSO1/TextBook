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
 ; Description: 這個範例呈現算術指令中的邏輯指令 -- NOT 和 TEST。
 ;              TEST 指令的作用是測試運算元的內容是否相同，且只針對旗標值改變而已，
 ;              並不改變運算元的內容。
 ;              TEST 受影響的 Flag Register 位元：SF, ZF, PF, CF = 0, OF = 0
 ;              此一程式的功能為：若鍵盤輸入'1'，就跟著列印出'1'；否則為'0'。
 ;

.MODEL	SMALL

.STACK

.DATA

.CODE
main:
	MOV  AH, 01H          ; DOS 的第 01 號中斷服務 (從鍵盤讀取輸入)；並儲存在 AX Low Byte
	INT  21H              ; INT 21H: DOS 中斷
	NOT  AL               ; 把鍵盤的輸入值做 NOT 運算
	TEST AL, 01H          ; 用 TEST 指令判斷結果是否為 0 ；注意！
	                      ; 如果鍵盤輸入為 '1' 的時候，因為 '1' 和 '1' 相等，結果為０；ZF 會被設定成１！
	JE   GOX              ; 若 Zero Flag == 1 時，跳至 GOX ；否則繼續執行
	MOV  DL, '0'          ; 準備秀出 '0'
	MOV  AH, 02H          ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的資料
	INT  21H              ; INT 21H: DOS 中斷
	JMP  EDOS             ; 跳躍至 EDOS 結束程式
GOX:
	MOV  DL, '1'          ; 準備秀出 '1'
	MOV  AH, 02H          ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的資料
	INT  21H              ; INT 21H: DOS 中斷
EDOS:
	MOV  AH, 4CH          ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H              ; INT 21H: DOS 中斷
END main
