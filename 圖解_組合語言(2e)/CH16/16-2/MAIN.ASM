 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build012523
 ;
 ; Date: 2023 / 01 / 25
 ;
 ; Description: 一個用組合語言來建立、開啟、讀取和關閉檔案的範例。
 ;

@CreateFile  MACRO  PATH, ATTRIB                   ; 定義一個巨集，用來「建立」檔案
	MOV  DX, OFFSET PATH                       ; 將 PATH 的記憶體位址，再加上偏移量，移動到 DX Register
	MOV  CL, ATTRIB                            ; 將檔案的屬性值，移動到 CL (CX Low Byte)
	MOV  CH, 0                                 ; 將 CH (CX High Byte) 初始化為 0x00 (因為用不到)
	NOV  AH, 3CH                               ; DOS 的第 3C 號中斷服務 (建立檔案)。
	                                           ; DS:DX 為 ASCIIZ 字串的記憶體位址；CX Register 為檔案屬性
	                                           ; Carry Flag == 0 開檔成功，AX Register 回傳檔案代碼；
	                                           ; Carry Flag == 1 開檔失敗，AX Register 回傳錯誤代碼 (03H / 04H / 05H)。
	INT  21H                                   ; INT 21H: DOS 中斷
ENDM

@OpenFile  MACRO  PATH, MODE                       ; 定義一個巨集，用來「開啟」檔案
	MOV  DX, OFFSET PATH                       ; 將 PATH 的記憶體位址，再加上偏移量，移動到 DX Register
	MOV  AL, MODE                              ; MODE: 00H: 唯讀檔；01H: 寫入檔；02H: 可寫入或是讀取的檔案
	MOV  AH, 3DH                               ; DOS 的第 3D 號中斷服務 (開啟檔案)。
	                                           ; DS:DX 為 ASCIIZ 字串的記憶體位址；AL (AX Low Byte) 為檔案模式
	                                           ; Carry Flag == 0 開檔成功，AX Register 回傳檔案代碼；
	                                           ; Carry Flag == 1 開檔失敗，AX Register 回傳錯誤代碼 (02H / 03H / 04H / 0CH)。
	INT  21H                                   ; INT 21H: DOS 中斷
ENDM

@ReadFile  MACRO  FILEHAND, BUFFER, BYTES          ; 定義一個巨集，用來「讀取」檔案的資料
	MOV  BX, FILEHAND                          ; 設定檔案代碼.... 
	MOV  DX, OFFSET BUFFER                     ; 將 BUFFER 的記憶體位址，再加上偏移量，移動到 DX Register
	MOV  CX, BYTES                             ; 將 BYTES 數設定給 CX Register
	MOV  AH, 3FH                               ; DOS 的第 3F 號中斷服務 (讀取檔案)；DS:DX 為要開始「讀取」的記憶體位址
	                                           ; BX Register 為檔案代碼；CX Register 為要讀取的位元數
	                                           ; Carry Flag == 0 讀取成功，AX Register 回傳所讀取的位元數；
	                                           ; Carry Flag == 1 讀取失敗，AX Register 回傳錯誤代碼 (05H / 06H)。
	INT  21H                                   ; INT 21H: DOS 中斷
ENDM

@WriteFile  MACRO FILEHAND, BUFFER, BYTES          ; 定義一個巨集，可以將「資料」寫進檔案
	MOV  BX, FILEHAND                          ; 設定檔案代碼.... 
	MOV  DX, OFFSET BUFFER                     ; 將 BUFFER 的記憶體位址，再加上偏移量，移動到 DX Register
	MOV  CX, BYTES                             ; 將 BYTES 數設定給 CX Register
	MOV  AH, 40H                               ; DOS 的第 40 號中斷服務 (寫入檔案)；DS:DX 為要開始「寫入」的記憶體位址
	                                           ; BX Register 為檔案代碼；CX Register 為要寫入的位元數
	                                           ; Carry Flag == 0 讀取成功，AX Register 回傳所寫入的位元數；
	                                           ; Carry Flag == 1 讀取失敗，AX Register 回傳錯誤代碼 (05H / 06H)。
	INT  21H                                   ; INT 21H: DOS 中斷
ENDM 

@CloseFile  MACRO  FILEHAND                        ; 定義一個巨集，用來「關閉」檔案
	MOV  BX, FILEHAND                          ; 設定檔案代碼.... 
	MOV  AH, 3EH                               ; DOS 的第 3E 號中斷服務 (關閉檔案)，BX Register 為檔案代碼；
	                                           ; 若關檔失敗，AX Register 回傳錯誤代碼。
	INT  21H                                   ; INT 21H: DOS 中斷
ENDM                                         
                                             
@OutPutStr  MACRO  String                          ; 定義一個巨集，用來「輸出」字串
	MOV  DX, OFFSET String                     ; 將 String 的記憶體位址，再加上偏移量，移動到 DX Register
	MOV  AH, 09H                               ; DOS 的第 09 號中斷服務 (顯示字串)；DX Register 為要顯示的位址
	INT  21H                                   ; INT 21H: DOS 中斷
ENDM

@OutPutChar  MACRO  Char                           ; 定義一個巨集，用來「輸出」字元
	MOV  DL, Char                              ; 將要輸出的 Char 移動到 DL (DX Low Byte)
	MOV  AH, 02H                               ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的字元
	INT  21H                                   ; INT 21H: DOS 中斷
ENDM                                         
                                             
@InPutStr  MACRO  String                           ; 定義一個巨集，用來「輸入」字串
	MOV  DX, OFFSET String                     ; 將 String 的記憶體位址，再加上偏移量，移動到 DX Register
	MOV  AH, 0AH                               ; DOS 的第 0A 號中斷服務：將鍵盤的輸入，先移動到緩衝區
	INT  21H                                   ; INT 21H: DOS 中斷
ENDM

.MODEL	SMALL

.STACK

.DATA
	MSG1        DB  'KEY IN File Name: $'
	MSG2        DB  'File can not open. $'
	MSG3        DB  'File contents: $'
	MSG4        DB  0DH, 0AH, '$'
	FILEH       DW  ?
	FILEBUFFER  DB  10, 11 DUP(?)
	DATABUFFER  DB  1000 DUP(?)

.CODE
main:
	MOV  AX, @DATA                             ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX                                ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	@OutPutStr  MSG1                           ; 輸出「KEY IN File Name: 」
	@InPutStr  FILEBUFFER                      ; 輸入檔案名稱 .... 
	MOV  BL, FILEBUFFER + 1                    ; 將使用者所輸入的檔案名稱，移動到 BX Register
	MOV  BH, 00H                               ; 將 BH (BX High Byte)初始化為 0x00；因為只用到 BL (BX Low Byte)
	MOV  [FILEBUFFER + BX + 2], 00H            ; 在 FILEBUFFER 變數的最後面加上 0x00 變成 ASCIIZ 字串的形式
	@OpenFile  [FILEBUFFER+2], 00H             ; 開檔！但 FILEBUFFER 的前２ Bytes (10 & 11)不要！
	MOV  FILEH, AX                             ; 將開檔的結果代碼，移動到變數 FILEH
	JC   NUMBER                                ; 若開檔失敗 (Carry Flag == 1)時，則跳到 NUMBER 標籤所在的地方
READDATA:                                          ; 若開檔成功，則開始讀取檔案內容
	@ReadFile  FILEH, DATABUFFER, 100          ; 開始讀取檔案，依序傳入：檔案代碼、要接收資料的位址和要讀取的位元組數
	JC   NUMBER                                ; 若讀取失敗 (Carry Flag == 1)時，則跳到 NUMBER 標籤所在的地方
	CMP  AX, 00H                               ; 若在 @ReadFile 中，AX Register 被設定為０，代表已到檔案末端
	JE   EXIT                                  ; 當 Zero Flag == 1 則跳到 EXIT 標籤所在的地方
	MOV  CX, AX                                ; 將所讀取到的位元組數設定給 CX Register
	MOV  BX, OFFSET DATABUFFER                 ; 將 DATABUFFER 的記憶體位址，再加上偏移量，設定給 BX Register
	@OutPutStr  MSG4                           ; 輸出「\n」
	@OutPutStr  MSG3                           ; 輸出「File contents: 」
	@OutPutStr  MSG4                           ; 輸出「\n」
PRINTDATA:                                         ; 開始輸出所讀取到的資料 ....
	MOV  DL, [BX]                              ; 將剛剛的 BX Register 所指到的記憶體內容，移動到 DL (DX Low Byte)
	@OutPutChar  DL                            ; 輸出字元
	INC  BX                                    ; 將要輸出的字元移動到下一個位址 .... 
	LOOP PRINTDATA                             ; 一直輸出字元，直到 CX Register == 0 為止
	JMP  READDATA                              ; 讀取下一段資料 .... 
EXIT:
	@CloseFile  FILEH                          ; 關檔！
	JMP  ENDDOS                                ; 直接跳到 ENDDOS 標籤所在的地方
NUMBER:                                      
	@OutPutStr  MSG4                           ; 輸出「\n」
	@OutPutStr  MSG2                           ; 輸出「File can not open. 」
ENDDOS:                                      
	MOV  AH, 4CH                               ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H                                   ; INT 21H: DOS 中斷
END main
