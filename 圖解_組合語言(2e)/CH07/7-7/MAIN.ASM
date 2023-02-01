 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build111922
 ;
 ; Date: 2022 / 11 / 19
 ;
 ; Description: 這個範例呈現位元旋轉指令 -- ROL (Rotate Left)。
 ;              - 可以將 Register or Memory 上的資料，向左旋轉１個 bit
 ;              - 而位移量必須搭配 CX Low Byte Register 來指定
 ;              - 最左邊的位元會移入到 Carry Flag 和 最右邊的 bit
 ;              - 受影響的旗標為：OF、CF
 ;

.MODEL	SMALL

.STACK

.DATA
	NUM   DB  01H      ; 宣告變數名稱為 NUM，將數值 0x01 (0000 0001)以 Byte 的資料型態儲存

.CODE
main:
	MOV   AX, @DATA    ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV   DS, AX       ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV   AL, NUM      ; 把數值 NUM 設定給 AX Low Byte
	MOV   CL, 03H      ; 將數值３設定給 CX Low Byte
	ROL   AL, CL       ; 將 AL 內的值 (0x01 == 0000 0001)向左位移３個 bit
	MOV   DL, AL       ; 再將 AX Low Byte 的值移動到 DX Low Byte
	ADD   DL, '0'      ; 將 DL 內的值 (0x08)加上 '0' (48)，變成可顯字元 ('8')
	MOV   AH, 02H      ; DOS 的第 02 號中斷服務 (顯示字元)；DX Low Byte 為要輸出的資料
	INT   21H          ; INT 21H: DOS 中斷	
	MOV   AH, 4CH      ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT   21H          ; INT 21H: DOS 中斷
END main
