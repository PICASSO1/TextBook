 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build110522
 ;
 ; Date: 2022 / 11 / 05
 ;
 ; Description: 這個範例呈現字串搬移指令 -- MOVSW (Move String by Word)。
 ;              這個指令一次只能移動１Word (2 Bytes) 的資料。
 ;              因為一次只能移動２ Bytes 且移動９次，共１８ Bytes！
 ;              所以最後呈現的結果為「ASSEMBLY       LAN99999」。
 ;

.MODEL	SMALL

.STACK

.DATA
	SOUR DB  'ASSEMBLY       LANGUAGE$'    ; 宣告變數名稱為 SOUR，以 Byte 的資料型態儲存
	DEST DB  '99999999999999999999999$'    ; 宣告變數名稱為 DEST，將２３個'9'以 Byte 的資料型態儲存

.CODE
main:
	MOV  AX, @DATA                         ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV  DS, AX                            ; 把 AX Register 的記憶體位址設定給 Data Segment Register；
	MOV  ES, AX                            ; 把 AX Register 的記憶體位址設定給 Extra Segment Register；
	CLD                                    ; 在這裡我們使用 CLD 狀態，由記憶體位址「低」的地方往「高」處移動。
	MOV  SI, OFFSET SOUR                   ; 把 SOUR 的記憶體位址 (此時偏移量為０)移動到 Source Index Register
	MOV  DI, OFFSET DEST                   ; 把 DEST 的記憶體位址 (此時偏移量為０)移動到 Destination Index Register
	MOV  CX, 9                             ; 把數值９移動到 CX Register
	REP  MOVSW                             ; 把 SI Register 的資料分別移動 CX(９) 次到 DI Register
	MOV  DX, OFFSET DEST                   ; 再把 DEST 的記憶體位址，移動到 DX Register
	MOV  AH, 09H                           ; DOS 的第 02 號中斷服務 (顯示輸出)；DL (DX Low Byte)為要輸出的資料
	INT  21H                               ; INT 21H: DOS 中斷
	MOV  AH, 4CH                           ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT  21H                               ; INT 21H: DOS 中斷
END main
