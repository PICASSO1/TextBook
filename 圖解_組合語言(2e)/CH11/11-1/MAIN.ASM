 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build010323
 ;
 ; Date: 2023 / 01 / 03
 ;
 ; Description: 這一個範例呈現了組合語言中「巨集的寫法」及其「參數傳遞」。
 ;

@PrintString  MACRO  string               ; 定義一個名為 PrintString 的巨集，會傳遞一個 string 型態的參數
	MOV          DX, OFFSET string    ; 將 string 加上偏移量的記憶體位址，移動到 DX Register
	MOV          AH, 09H              ; DOS 的第 09 號中斷服務 (顯示字串)；DX Register 為要顯示的位址
	INT          21H                  ; INT 21H: DOS 中斷
ENDM                                      ; 巨集定義結束

@PrintChar    MACRO  char                 ; 定義一個名為 PrintChar 的巨集，會傳遞一個 char 型態的參數
	MOV          DL, char             ; 將 char 加上偏移量的記憶體位址，移動到 DX Register
	MOV          AH, 02H              ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的字元
	INT          21H                  ; INT 21H: DOS 中斷
ENDM                                      ; 巨集定義結束

@EndDos      MACRO                        ; 定義一個名為 EndDos 的巨集；但它並不傳遞參數
	MOV          AH, 4CH              ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT          21H                  ; INT 21H: DOS 中斷
ENDM                                      ; 巨集定義結束

.MODEL	SMALL

.STACK

.DATA
	tChar        DB  'T$'
	tString      DB  'his is a book!$'

.CODE
main:
	MOV          AX, @DATA            ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV          DS, AX               ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV          AL, tChar            ; 將 tChar 的記憶體位址移動到 AX Low Byte
	@PrintChar   AL                   ; 呼叫 PrintChar 巨集並傳遞 AX Low Byte 的內容
	@PrintString tString              ; 呼叫 PrintString 巨集並傳遞 tString
	@EndDos                           ; 呼叫 EndDos
END main
