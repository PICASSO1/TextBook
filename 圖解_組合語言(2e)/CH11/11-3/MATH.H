
;*************************
;** 加法           **
;*************************
@TG_ADD  MACRO  NUM1,NUM2     ; 定義一個名為 TG_ADD 的巨集，會傳遞 NUM1 & NUM2 參數
  MOV  AL, NUM1
  ADD  AL, NUM2
  MOV  NUM1, AL                ; NUM1 + NUM2 的結果再儲存回 NUM1
ENDM

;*************************
;** 減法           **
;*************************
@TG_SUB  MACRO  NUM1,NUM2     ; 定義一個名為 TG_SUB 的巨集，會傳遞 NUM1 & NUM2 參數
  MOV  AL, NUM1
  SUB  AL, NUM2
  MOV  NUM1, AL                ; NUM1 - NUM2 的結果再儲存回 NUM1
ENDM

