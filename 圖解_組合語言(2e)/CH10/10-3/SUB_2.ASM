 ;
 ; File Name: SUB_2.ASM
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
	PUBLIC   PrintStr        ; 關鍵字 PUBLIC 告訴組譯器，這個函式大家都可以使用
PrintStr proc              ; 這是宣告一個函式的寫法；後面要加上關鍵字 proc
	MOV    AH, 09H           ; DOS 的第 09 號中斷服務 (顯示字串)；DX Register 為要顯示的位址
	INT    21H               ; INT 21H: DOS 中斷
	RET                      ; return 離開函式
PrintStr endp              ; 函式的結束，後面要加上 endp
END
