
;*************************
;**     顯示字串   **
;*************************
@PrintString  MACRO  string    ; 定義一個名為 PrintString 的巨集，會傳遞一個 string 型態的參數
  MOV  DX, OFFSET string       ; 將 string 加上偏移量的記憶體位址，移動到 DX Register 
  MOV  AH, 09H                 ; DOS 的第 09 號中斷服務 (顯示字串)；DX Register 為要顯示的位址
  INT  21H                     ; INT 21H: DOS 中斷
ENDM                           ; 巨集定義結束

;*************************
;**     顯示字元   **
;*************************
@PrintChar  MACRO  char
  MOV  DL, char                ; 將 char 的記憶體位址，移動到 DX Low Byte
  MOV  AH, 02H                 ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的字元
  INT  21H                     ; INT 21H: DOS 中斷
ENDM

;*************************
;**     結束程式   **
;*************************
@EndDos  MACRO
  MOV  AH, 4CH                 ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
  INT  21H                     ; INT 21H: DOS 中斷
ENDM

;*************************
;**     輸入字元   **
;*************************
@InputChar  MACRO char
  MOV  AH, 01H                 ; DOS 的第 01 號中斷服務 (從鍵盤讀取輸入並顯示)；AL (AX Low Byte)為輸入值
  INT  21H                     ; INT 21H: DOS 中斷
  MOV  char, AL
ENDM

;*************************
;**     字元+'0'   **
;*************************
;影響暫存器 :AL 值會改變
@ASCChar  MACRO  char
  MOV  AL, char
  ADD  AL, '0'
ENDM
