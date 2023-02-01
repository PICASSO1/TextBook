 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build110722
 ;
 ; Date: 2022 / 11 / 07
 ;
 ; Description: 這個範例呈現字串搜尋指令 -- SCASB (Scan String by Byte)。
 ;              和前置重複指令 -- REPNE (Repeat)。
 ;
 ;              SCASB 這個指令：
 ;              - 等價於 SCAS 指令；但一次只能搜尋且比對一個 Byte。
 ;              - 搜尋且比對完成之後，DI 值會被 +1 / -1 (依照 STD / CLD)。
 ;
 ;              REPNE 這個指令：
 ;              - 會有條件重複地執行 REPNE 後面所接的動作；
 ;              - 而重複的次數，則是 CX Register 逐一遞減至０；或 Zero Flag == 1 為止。
 ;
 ;              受影響的 Flag Register 位元：OF, SF, ZF, AF, PF, CF
 ;

.MODEL	SMALL

.STACK

.DATA
	FIND   DB  'ABCDEFGHIJKLMNOPQRSTUVWXYZ$'    ; 宣告變數名稱為 FIND，將２６個英文大寫字母以 Byte 的資料型態儲存
	SOUR   DB  'FIND$'                          ; 宣告變數名稱為 SOUR，將'FIND'以 Byte 的資料型態儲存到 SOUR
	DEST   DB  'NOT FIND$'                      ; 宣告變數名稱為 DEST，將'NOT FIND'以 Byte 的資料型態儲存到 DEST

.CODE
main:
	MOV    AX, @DATA                            ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV    DS, AX                               ; 把 AX Register 的記憶體位址設定給 Data Segment Register；
	MOV    ES, AX                               ; 把 AX Register 的記憶體位址設定給 Extra Segment Register；
	CLD                                         ; 這裡使用 CLD 狀態，由記憶體位址「低」的地方往「高」處移動。
	MOV    AL, 'M'                              ; 把大寫字母'M'移動到 AX (Low Byte) 暫存器
	LEA    DI, FIND                             ; 將 FIND 變數的偏移量，儲存到 DI Register
	MOV    CX, 26                               ; 把數值２６移動到 CX Register (設定搜尋的次數)
	REPNE  SCASB                                ; 在 FIND 中以 Byte 為單位依序搜尋是否有 AL 內的資料 ('M')，且搜尋２６次
	JE     ISFIND                               ; 假如「有」找到就跳躍到 ISFIND 標籤執行下一段程式碼
	JNE    NOFIND                               ; 假如「沒」找到就跳躍到 NOFIND 標籤執行下一段程式碼

ISFIND:
	MOV    DX, OFFSET SOUR                      ; 把 SOUR 的記憶體位址 (此時偏移量應為０)移動到 DX Register
	MOV    AH, 09H                              ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的資料
	INT    21H                                  ; INT 21H: DOS 中斷
	JMP    ENDDOS                               ; 直接跳躍到 ENDDOS 標籤執行下一段程式碼

NOFIND:
	MOV    DX, OFFSET DEST                      ; 把 DEST 的記憶體位址 (此時偏移量應為０)移動到 DX Register
	MOV    AH, 09H                              ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的資料
	INT    21H                                  ; INT 21H: DOS 中斷
	JMP    ENDDOS                               ; 直接跳躍到 ENDDOS 標籤執行下一段程式碼

ENDDOS:
	MOV    AH, 4CH                              ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT    21H                                  ; INT 21H: DOS 中斷
END main
