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
 # 2. EX: OpCode (Operation Code) -- "movl"，屬於「後置 (Postfix / Suffix)表示法」；可以分別區分為：b, w, l, q, s, d, t. 
 #    - b: Byte, 1 個字節，指的是 1 Byte (8 bit)；對應於 C 語言的資料型態：char
 #    - w: Word, 1 個字組 (即 2 個字節)，指的是 2 Byte (16 bit)；對應於 C 語言的資料型態：short
 #    - l: Long Word, 有兩種含意
 #         > 2 個字組 (即 4 個字節)，指的是 4 Byte (32 bit)；對應於 C 語言的資料型態：int
 #         > 4 個字組 (即 8 個字節)，指的是 8 Byte (64 bit)；對應於 C 語言的資料型態：float
 #    - q: Quad Word, 4 個字組 (即 8 個字節)，指的是 8 Byte (64 bit)；對應於 C 語言的資料型態：long, char *
 #    - s: Short / Single-Precision: 有兩種含意
 #        > 1 個字組 (即 2 個字節)，指的是 2 Byte (16 bit)；對應於 C 語言的資料型態：short
 #        > 2 個字組 (即 4 個字節)，指的是 4 Byte (32 bit)；對應於 C 語言的資料型態：float
 #    - d: Double-Precision, 8個字節，指的是8 Byte (64 bit)；；對應於 C 語言的資料型態：double
 #    - t: (不確定)
 #        > ExTended-Precision , 8 個字組 (即 16 個字節)，指的是 16 Byte (128 bit)；對應於 C 語言的資料型態：long double
 #        > Ten bytes, 80 bit 的 floating .... 
 #
 #    字節 == 位元組 (Byte) == 8 bit 
 #    字組 (WORD) == 2 個字節 == 2 位元組 == 16 bit 
 #    雙字組 (DWORD) == 2 個字組 == 4 個字節 == 4 位元組 == 32 bit
 #
 #    至於為何會有上述的規範？有其歷史包袱及因素。。。。。
 #
 # 3. '.' 開頭的，是 Assembly 的假指令，觀念類似於 GNU Makefile 的 ".PHONY"；主要目的是為了給 Assembler (組譯器) & Linker (連結器)看。
 #
 # 4. cfi: Call Frame Information (呼叫訊框資訊)；cfa: Canonical Frame Address (規範訊框位址)；
 #    這些是 DWARF (Debugging With Attributed Record Formats)，是一種調用訊息的格式。
 #
 # 5. %rsp (Stack Pointer Register，堆疊暫存器，指向堆疊的頂端)、%rbp (Base Pointer Register，堆疊基底暫存器，指向堆疊得底部)、push、pop 等等，這些東西和 Stack Session 有關；
 #    有可以稱做 Stack Frame (堆疊訊框)。
 #
 # 6. 堆疊的底部 ( %rbp 所指的地方)，是在記憶體位址"較高"的地方；而堆疊的頂端 ( %rsp 所指的地方)，是在記憶體位址"較低"的地方。所以，當有東西進來的時候 (push)，記憶體位址是向下減的
 #    。就某種程度上而言，是一個 LIFO (Last In First Out)的設計概念。
 # 
 # 7. 以下兩段程式碼，其實就只做一件事兒而已：
 #
 #    pushq %rbp               .cfi_def_cfa_offset 16 
 #    movq %rsp, %rbp    和    .cfi_offset 6, -16     
 #    subq $16, %rsp           .cfi_def_cfa_register 6
 #
 #    就是把整個 Stack Frame (.stack) 新增 16 Bytes；示意圖應該長得像這樣：
 #
 #    Stack Frame (Before)                         Stack Frame (After)
 #    High Memery Address                          High Memery Address
 #    ˍˍˍˍˍˍˍˍˍˍˍˍ                                 ˍˍˍˍˍˍˍˍˍˍˍˍ                      
 #    |ˍˍˍˍˍˍˍˍˍˍ| 0x2048 ----> Old %rbp           |ˍˍˍˍˍˍˍˍˍˍ| 0x2048
 #    |ˍˍˍˍˍˍˍˍˍˍ| 0x2040                          |ˍˍˍˍˍˍˍˍˍˍ| 0x2040               
 #    |ˍˍˍˍˍˍˍˍˍˍ| 0x2038                          |ˍˍˍˍˍˍˍˍˍˍ| 0x2038               
 #    |ˍˍˍˍˍˍˍˍˍˍ| 0x2030                          |ˍˍˍˍˍˍˍˍˍˍ| 0x2030               
 #    |ˍˍˍˍˍˍˍˍˍˍ| 0x2028                          |ˍˍˍˍˍˍˍˍˍˍ| 0x2028               
 #    |ˍˍˍˍˍˍˍˍˍˍ| 0x2020                          |ˍˍˍˍˍˍˍˍˍˍ| 0x2020               
 #    |ˍˍˍˍˍˍˍˍˍˍ| 0x2018                          |ˍˍˍˍˍˍˍˍˍˍ| 0x2018               
 #    |ˍˍˍˍˍˍˍˍˍˍ| 0x2010                          |ˍˍˍˍˍˍˍˍˍˍ| 0x2010               
 #    |ˍˍˍˍˍˍˍˍˍˍ| 0x2008                          |ˍˍˍˍˍˍˍˍˍˍ| 0x2008               
 #    |ˍˍˍˍˍˍˍˍˍˍ| 0x2000 ----> Old %rsp           |ˍˍˍˍˍˍˍˍˍˍ| 0x2000 ----> New %rbp
 #    |ˍˍˍˍˍˍˍˍˍˍ| 0x1FF8                          |ˍˍˍˍˍˍˍˍˍˍ| 0x1FF8               
 #    |ˍˍˍˍˍˍˍˍˍˍ| 0x1FF0                          |ˍˍˍˍˍˍˍˍˍˍ| 0x1FF0 ----> New %rsp 
 #
 #    Low Memery Address                           Low Memery Address
 #
######

	.file	"main.c"                                # 檔案名稱："main.c"；GDB可能會用到。
	.text                                           # 內文段
	.section	.rodata                         # 區段包含一個 .rodate (唯獨的資料段)；這一塊記憶體的資料只能唯讀。
.LC0:                                                   # Local Constant，區域變數
	.string	"signed int i = %d \n"                  # 儲存在字串表的內容："signed int i = %d \n"
	.text                                           # 內文段
	.globl	main                                    # 我們在全域段，定義了一個叫 "main" 的東西；
	.type	main, @function                         # 而 main 的類型 (Type)是一個函式 (Function)
main:                                                   # 函式開始 .... 
.LFB0:                                                  # Local Function Beginning；從０開始，與 .LFE 成對出現。
	.cfi_startproc                                  # 定義函式的開始，開始做一些初始化；與 cfi_endproc 成對出現。
	pushq	%rbp                                    # 把舊的 %rbp 的內容，送到 Stack Frame；為何是 pushq ？猜測 %rbp 是 64-bit 的暫存器 .... 
	.cfi_def_cfa_offset 16                          # 定義 CFA 偏移了 16 Bytes；
	.cfi_offset 6, -16                              # R6 暫存器 (即 %rbp)，往 Stack 頂端偏移１６ Bytes；因為 Stack 的頂端，是在記憶體位址較低的地方，所以用減號。
	movq	%rsp, %rbp                              # 把「舊的」%rsp 的內容設定給 %rbp ；
	.cfi_def_cfa_register 6                         # 把 R6 (%rbp)定義為新的 CFA (這裡指的應為 CFA 的底部)
	subq	$16, %rsp                               # 而「新的」%rsp 的內容，則是原本的內容減１６之後，再存回 %rsp。 
	movl	$-1, -4(%rbp)                           # 把數值 -1 儲存在 Base Pointer Register - 4 Byte 的位址上；即：singed int i = -1; 
	movl	-4(%rbp), %eax                          # 再把暫存器 %rbp 裡的"值" (記憶體位址)，減４，再把這個位址移到 %eax 暫存器。
	movl	%eax, %esi                              # 把 %eax (Adder Register)的內容，移動到 %esi (Source Index Register)。
	leaq	.LC0(%rip), %rax                        # 
	movq	%rax, %rdi                              # 把 rax 的內容，移動至 rdi (Destination Index Register)。
	movl	$0, %eax                                # 把數值 0 ，設定給 eax 
	call	printf@PLT                              # 呼叫函式：printf(); 
	movl	$0, %eax                                # 將數值 0 儲存到 eax 暫存器。函式的回傳值必須儲存在 eax 暫存器。
	leave                                           # 離開函式.... 
	.cfi_def_cfa 7, 8                               # 把 R7 (%rdi) + 8 Bytes
	ret                                             # return 0
	.cfi_endproc                                    # 定義函式的結束
.LFE0:                                                  # Local Function Ending
	.size	main, .-main                            # main() 函式的大小；而 .-main 是 main()函式大小的值，這玩意兒最後會組譯成目的檔 (*.o)。
	.ident	"GCC: (GNU) 11.2.0"                     # GNU gcc 編譯器喜歡留下一些訊息；但這條訊息會被當成一種註解，在最後的目標檔 (*.o)並不會有它。
	.section	.note.GNU-stack,"",@progbits
	# GNU GCC 在其中寫入程式碼可以容納不可執行堆疊 (Stack)的特殊部份。這是正常情況的操作。但某些特殊用途 (非標準C)需要對疊的部份可以被執行。
	# 在現代處理器上，核心可以建立一個不可執行的堆疊 (如果有設計師嘗試將堆疊上的某些數據當為程式碼執行，則會觸發異常 (Exception)的堆疊）；
	# 這被一些人視為"安全功能”，因為將程式碼放在堆疊上是利用緩衝區溢出的常用方法。
	# 此段的語意為：「"可執行"的文件，將被標記為與"不可執行"的堆疊相容」，核心將很樂意提供這樣的堆疊 (Stack)。
