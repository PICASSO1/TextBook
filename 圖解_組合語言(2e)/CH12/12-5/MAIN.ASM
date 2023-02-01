 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build010523
 ;
 ; Date: 2023 / 01 / 05
 ;
 ; Description: 「基底相對定址法」：利用 Base Pointer 或 BX Register 再加上一個偏移量 (OFFSET)來得到一個記憶體位址。
 ;

.MODEL	SMALL

.STACK

.DATA

.CODE
main:
	MOV  AX, 4142H   ; 將數值 0x4142 移動到 AX Register
	MOV  BX, 4344H   ; 將數值 0x4344 移動到 BX Register
	MOV  CX, 4546H   ; 將數值 0x4546 移動到 CX Register
	MOV  DX, 4748H   ; 將數值 0x4748 移動到 DX Register
	PUSH AX          ; 將 AX Register 的內容丟進 .STACK Segment
	PUSH BX          ; 將 BX Register 的內容丟進 .STACK Segment
	PUSH CX          ; 將 CX Register 的內容丟進 .STACK Segment
	PUSH DX          ; 將 DX Register 的內容丟進 .STACK Segment
	MOV  BP, SP      ; 將 Stack Pointer 的記憶體位址移動到 Base Pointer
	                 ; 此時的 Stack Pointer 所指到的「記憶體位址的內容」應為 0x48
	MOV  DL, [BP+7]  ; 而 Base Pointer 所指的記憶體位址，再加上 7 Bytes
	                 ; 因為 .STACK Segment 是由「記憶體位址高的地方往下減少」，
	                 ; 所以 +7 之後的記憶體位址的內容應為 0x41 ('A')
	MOV  AH, 02H     ; DOS 的第 02 號中斷服務 (顯示字元輸出)；DL (DX Low Byte)為要輸出的字元
	INT  21H         ; INT 21H: DOS 中斷
	MOV  AH, 4CH     ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H         ; INT 21H: DOS 中斷
END main
