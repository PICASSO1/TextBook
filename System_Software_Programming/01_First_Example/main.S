###
 # File Name: main.S
 #
 # CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 #
 # Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 #
 # Version: 1.0.0.build042322
 #
 # Date: 2022 / 04 / 23
 #
 # Description: 
 # 1. 由一個簡單地 *.c 檔編譯成組合語言，並觀察及瞭解其內容。
 #
 # 2. EX: OpCode (Operation Code) -- "movl"，屬於「後置 (Postfix / Suffix)表示法」；可以分別區分為：b, w, l, qs, d, t. 
 #    - b: Byte, 1個字節，指的是1 Byte (8 bit)；對應於 C 語言的資料型態：char
 #    - w: Word, 2個字節，指的是2 Byte (16 bit)；對應於 C 語言的資料型態：short
 #    - l: Long Word, 4個字節，指的是4 Byte (32 bit)；對應於 C 語言的資料型態：int
 #    - q: Quad Word, 8個字節，指的是8 Byte (64 bit)；對應於 C 語言的資料型態：long, char *
 #    - s: , Single-Precision, 4個字節，指的是4 Byte (32 bit)；；對應於 C 語言的資料型態：float
 #    - d: , Double-Precision, 8個字節，指的是8 Byte (64 bit)；；對應於 C 語言的資料型態：double
 #    - t: , ExTended-Precision, 16個字節，指的是16 Byte (128 bit)；；對應於 C 語言的資料型態：long double
 #
 #    至於為何「2個字節 (Byte)」又名「1個字組 (Word)」，有其歷史包袱。。。。。
 #
 # 3. '.' 開頭的，是 Assembly 的假指令，觀念類似於 GNU Makefile 的 ".PHONY"；主要目的是為了給 Assembler (組譯器) & Linker (連結器)看。
 #
 # 4. cfi: Call Frame Information (呼叫訊框資訊)；cfa: Canonical Frame Address (規範訊框位址)；
 #    這些是 DWARF (Debugging With Attributed Record Formats)，是一種調用訊息的格式。
 #
######

	.file	"main.c"                                           # 檔案名稱："main.c"
	.text                                                          # 內文段
	.section	.rodata                                     # 區段
.LC0:
	.string	"signed int i = %d \n"                # 儲存在字串表的內容："signed int i = %d \n"
	.text                                                          # 內文段
	.globl	main                                             # 全域段
	.type	main, @function                         # 
main:                                                            # 主程式開始
.LFB0:
	.cfi_startproc                                          # 定義函式的開始；開始做一些初始化
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$-1, -4(%rbp)                            # 把數值 -1 儲存在 Base Pointer Register - 4 Byte 的位址上；即：singed int i = -1; 
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT                                   # 呼叫函式：printf(); 
	movl	$0, %eax                                   # 將數值 0 儲存到 eax 暫存器。函式的回傳值必須儲存在 eax 暫存器。
	leave
	.cfi_def_cfa 7, 8
	ret                                                         # return 0
	.cfi_endproc                                        # 定義函式的結束
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.2.0"
	.section	.note.GNU-stack,"",@progbits
