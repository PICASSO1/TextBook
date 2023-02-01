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
 ; Description: 這個範例呈現位元平移指令 -- SAR (Shift Arithmetic Right)。
 ;              SHL / SAL 這２組指令的功能「一模一樣」；但是，
 ;              SHR / SAR 這２組指令的功能「不太一樣」！
 ;              - 可以將 Register or Memory 上的資料，向右位移１個 bit
 ;              - 而位移量必須搭配 CX Low Byte Register 來指定
 ;              - 最左邊的位元「保持不變」；而最右邊移出的位元則是會移入到 Carry Flag
 ;
 ;              這個範例用的不好，SAR 指令主要是用在負數的呈現；但是在電腦的世界裡並沒有
 ;              「負數」的觀念，而是用最左邊的 bit 和 Sign Flag 來表示。
 ;              所以要顯示出負數必須要以"字串"的方式，例如：-2。但我還不會寫。
 ;

.MODEL	SMALL

.STACK

.DATA
	NUM   DB  40H      ; 宣告變數名稱為 NUM，將數值 0x40 (0100 0000)以 Byte 的資料型態儲存

.CODE
main:
	MOV   AX, @DATA    ; 把 .DATA Segment 的位址傳送到 AX 暫存器
	MOV   DS, AX       ; 把 AX Register 的記憶體位址設定給 Data Segment Register
	MOV   AL, NUM      ; 把數值 NUM 設定給 AX Low Byte
	MOV   CL, 05H      ; 將數值５設定給 CX Low Byte
	SAR   AL, CL       ; 將 AL 內的值 (0x40 == 0100 0000)向左位移５個 bit
	MOV   DL, AL       ; 再將 AX Low Byte 的值移動到 DX Low Byte
	ADD   DL, 30H      ; 將 DL 內的值 (0x02)加上 0x30 (48)，變成可顯字元 ('2')
	MOV   AH, 02H      ; DOS 的第 02 號中斷服務 (顯示字元)；DX Low Byte 為要輸出的資料
	INT   21H          ; INT 21H: DOS 中斷	
	MOV   AH, 4CH      ; DOS 的第 4C 號中斷服務 (帶回傳值結束)；AL (AX Low Byte)為回傳值
	INT   21H          ; INT 21H: DOS 中斷
END main
