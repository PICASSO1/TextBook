 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build011223
 ;
 ; Date: 2023 / 01 / 12
 ;
 ; Description: 這是一個用堆疊 (.STACK Segment) 來當作函式參數傳遞的範例！
 ;              建議使用類似 8086 Emulator 的圖形化介面，來觀察堆疊區段內資料的變化會比較清楚及理解。
 ;

.MODEL	SMALL

.STACK

.DATA
	MSG1 DB  '1 + 4 = $'
	MSG2 DB  0DH, 0AH, '2 * 3 = $'

.CODE
main:
	MOV  AX, @DATA          ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX             ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV  AX, 0104H          ; 將數值 0x0104 移動到 AX Register
	MOV  BX, 0203H          ; 將數值 0x0203 移動到 BX Register
	PUSH AX                 ; 將 AX Register 的內容移動到 .STACK Segment
	CALL ADDX               ; 呼叫 ADDX 函式
	MOV  BP, SP             ; 將 Stack Pointer 的記憶體位址移動到 Base Pointer
	MOV  DX, OFFSET MSG1    ; 將 MSG1 的記憶體位址，再加上偏移量，移動到 DX Register
	MOV  AH, 09H            ; DOS 的第 09 號中斷服務 (顯示字串)；DL (DX Low Byte)為要開始輸出的字串
	INT  21H                ; INT 21H: DOS 中斷
	MOV  DL, [BP+1]         ; 將 Base Pointer 所指到的記憶體位址 (此時內容應為 0x04)再加上１(此時內容應為 0x35 == '5')移動到 DX Low Byte
	MOV  AH, 02H            ; DOS 的第 02 號中斷服務 (顯示輸出字元)；DL (DX Low Byte)為要輸出的字元 ('5')
	INT  21H                ; INT 21H: DOS 中斷

	PUSH BX                 ; 將 BX Register 的內容移動到 .STACK Segment
	CALL MULX               ; 呼叫 MULX 函式
	MOV  BP, SP             ; 將 Stack Pointer 的內容移動到 Base Pointer
	MOV  DX, OFFSET MSG2    ; 將 MSG2 的記憶體位址，再加上偏移量，移動到 DX Register
	MOV  AH, 09H            ; DOS 的第 09 號中斷服務 (顯示字串)；DL (DX Low Byte)為要開始輸出的字串
	INT  21H                ; INT 21H: DOS 中斷
	MOV  DL, [BP+1]         ; 將 Base Pointer 所指到的記憶體位址 (此時內容應為 0x03)再加上１(此時內容應為 0x36 == '6')移動到 DX Low Byte
	MOV  AH, 02H            ; DOS 的第 02 號中斷服務 (顯示輸出字元)；DL (DX Low Byte)為要輸出的字元 ('6')
	INT  21H                ; INT 21H: DOS 中斷
	MOV  AH, 4CH            ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H                ; INT 21H: DOS 中斷

ADDX PROC                       ; 定義 ADDX 函式
	MOV  BP, SP             ; 將 Stack Pointer 的內容移動到 Base Pointer
	MOV  DL, [BP+2]         ; 將 Base Pointer 所指到的記憶體位址，再加上２(此時內容應為 0x04 == 4)移動到 DX Low Byte
	MOV  AL, [BP+3]         ; 將 Base Pointer 所指到的記憶體位址，再加上３(此時內容應為 0x01 == 1)移動到 AX Low Byte
	ADD  AL, DL             ; 將 AX Low Byte (0x01 == 1) + DX Low Byte (0x04 == 4) = (0x05 == 5)，儲存回 AX Low Byte
	ADD  AL, '0'            ; 將 AX Low Byte 的數值內容 (5)轉換成字元'5' (0x35)
	MOV  [BP+3], AL         ; 將 AX Low Byte 的內容儲存回 Base Pointer 所指到的記憶體位址再加上３
	                        ; 此時 .STACK Segment 內的資料會由 0x0104 變成 0x3504
	RET                     ; 回傳值.... 
ADDX ENDP                       ; ADDX 函式結束

MULX PROC                       ; 定義 MULX 函式
	MOV  BP, SP             ; 將 Stack Pointer 的內容移動到 Base Pointer
	MOV  DL, [BP+2]         ; 將 Base Pointer 所指到的記憶體位址，再加上２(此時內容應為 0x02 == 2)移動到 DX Low Byte
	MOV  AL, [BP+3]         ; 將 Base Pointer 所指到的記憶體位址，再加上３(此時內容應為 0x03 == 3)移動到 AX Low Byte
	MUL  DL                 ; 將 AX Low Byte (0x02 == 2) * DX Low Byte (0x03 == 3) = (0x06 == 6)，儲存回 AX Low Byte
	ADD  AL, '0'            ; 將 AX Low Byte 的數值內容 (6)轉換成字元'6' (0x36)
	MOV  [BP+3], AL         ; 將 AX Low Byte 的內容儲存回 Base Pointer 所指到的記憶體位址再加上３
	                        ; 此時 .STACK Segment 內的資料會由 0x0203 變成 0x3603
	RET                     ; 回傳值.... 
MULX ENDP                       ; ADDX 函式結束
END main
