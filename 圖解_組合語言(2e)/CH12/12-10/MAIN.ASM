 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build011123
 ;
 ; Date: 2023 / 01 / 11
 ;
 ; Description: (NONE). 
 ;

.MODEL	SMALL

.STACK

.DATA

.CODE
main:
	MOV  AX, 4142H         ; 將數值 0x1234 移動到 AX Register
	MOV  BX, 4344H         ; 將數值 0x5678 移動到 BX Register
	MOV  CX, 4546H         ; 將數值 0x9ABC 移動到 CX Register
	MOV  DX, 4748H         ; 將數值 0xDE39 移動到 DX Register
	PUSH AX                ; 將 AX Register 的內容移動到 .STACK Segment
	PUSH BX                ; 將 BX Register 的內容移動到 .STACK Segment
	PUSH CX                ; 將 CX Register 的內容移動到 .STACK Segment
	PUSH DX                ; 將 DX Register 的內容移動到 .STACK Segment
	MOV  BP, SP            ; 將 Stack Pointer 的內容移動到 Base Pointer
	MOV  DL, [BP+4]        ; 將 Base Pointer 所指到的記憶體位址 (此時內容應為 0x48)再加上４(此時內容應為 0x44 == 'D')移動到 DX Low Byte
;	MOV  AH, 09H           ; DOS 的第 09 號中斷服務 (顯示字串)；DL (DX Low Byte)為要開始輸出的字串
;	INT  21H               ; INT 21H: DOS 中斷
	MOV  AH, 02H           ; DOS 的第 02 號中斷服務 (顯示輸出字元)；DL (DX Low Byte)為要輸出的字元
	INT  21H               ; INT 21H: DOS 中斷
	MOV  AH, 4CH           ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H               ; INT 21H: DOS 中斷
END main
