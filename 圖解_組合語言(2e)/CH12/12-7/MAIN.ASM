 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build010923
 ;
 ; Date: 2023 / 01 / 09
 ;
 ; Description: 「基底索引定址法」：簡言之，「基底相對定址法」和「直接索引定址法」合併在一起使用。
 ;              複習：
 ;              「基底相對定址法」：利用 Base Pointer 或 BX Register 再加上一個偏移量 (OFFSET)來得到一個記憶體位址。
 ;              「直接索引定址法」：利用 Source Index Register 或 Destination Index Register 再加上一個偏移量 (OFFSET)來得到一個記憶體位址。
 ;

.MODEL	SMALL

.STACK

.DATA
	T    DB  'ABCDEFGHIJKLMNOPQRSTUVWXYZ$'

.CODE
main:
	MOV  AX, @DATA      ; 把 .DATA Segment 的位址傳送到 AX 暫存器；即 .DATA Segment 的起始位址放到 AX
	MOV  DS, AX         ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV  BX, 03H        ; 將數值 0x03 移動到 BX Register
	MOV  SI, 07H        ; 將數值 0x07 移動到 Source Index Register
	MOV  DL, [BX+SI]    ; [BX+SI] == [0x03+0x07] == 0x0A == 10 == 'K'
	                    ; 在 8086 Emulator 上執行，結果是'K' ----> 合乎預期！
	                    ; 在 DosBox (MASM 5.00)上執行，結果是'E' ----> 不知道怎麼來的？
	                    ; 而教科書上的執行結果，居然是'D' ----> 應該是寫錯了！
	MOV  AH, 02H        ; DOS 的第 02 號中斷服務 (顯示字元輸出)；DL (DX Low Byte)為要輸出的字元
	INT  21H            ; INT 21H: DOS 中斷
	MOV  AH, 4CH        ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H            ; INT 21H: DOS 中斷
END main
