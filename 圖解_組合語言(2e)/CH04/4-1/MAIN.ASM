 ;
 ; File Name: MAIN.ASM
 ;
 ; CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 ;
 ; Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 ;
 ; Version: 1.0.0.build101022
 ;
 ; Date: 2022 / 10 / 10
 ;
 ; Description: This is a very easy example for Assembly.
 ;

.MODEL	SMALL

.CODE

main:
	mov dl, "T"
	mov ah, 02h
	int 21h
	mov ah, 4ch
	int 21h

.STACK

END main

 ;
 ; .MODEL 假指令是用來指定模式的大小，如下：
 ; ┌─────────┬────────────────────────┬───────────────────────┐
 ; │ .MODEL  │     .CODE Segment      │    .DATA Segment      │
 ; ├─────────┼────────────────────────┴───────────────────────┤
 ; │ TINY    │ .CODE & .DATA 共用一個區段，且大小不得超過 64K　　│
 ; │ SMALL   │         < 64K          │         < 64K         │
 ; │ MEDIUM  │         > 64K          │         < 64K         │
 ; │ COMPACT │         < 64K          │         > 64K         │
 ; │ LARGE   │         > 64K          │         > 64K         │
 ; │ HUGE    │         > 64K          │         > 64K         │
 ; └─────────┴────────────────────────┴───────────────────────┘
 ;
 ; .CODE, .STACK, .DATA, .EXTRA 則是代表每乙個 Segment 的開始區段。
 ;
 ; main: .... END main main 函式的開始和結束；END 以後的指令均不會再被組譯。
 ;
