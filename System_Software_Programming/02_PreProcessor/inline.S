	.file	"inline.c"
	.text
	.type	MIN, @function
MIN:                                                     # 這裡就定義內嵌 (inline)函式的地方。
.LFB0:                                                   # Local Function Beginning 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
                                                         # 上面這 4 行指令看起來 .... x86_64 的架構之下，暫存器無法對暫存器直接存取，必須要透過記憶體 (RAM)？
	cmpl	%eax, %edx                               # 開始做比較 .... 
	cmovle	%edx, %eax                               # 這個好像是 cmp + mov 的合併指令 .... 細節沒研究
	popq	%rbp                                     # 因為前面有 "pushq  %rbp"，所以這兒有 "popq  %rbp"。
	.cfi_def_cfa 7, 8
	ret                                              # 離開 MIN(); 函式。
	.cfi_endproc
.LFE0:                                                   # Local Function Ending 0
	.size	MIN, .-MIN
	.section	.rodata
.LC0:                                                    # Local Constant，區域變數
	.string	"MIN(3, 9): %d \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:                                                  # Local Function Beginning 1
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$9, %esi                                # 把數值 9 儲存到 %esi (Source Index Register, 32-bit)
	movl	$3, %edi                                # 把數值 3 儲存到 %esi (Source Destination Register, 32-bit)
	call	MIN                                     # 呼叫內嵌函式 MIN(); 
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax                        # %rip 是程式索引暫存器 (Index Program)，用來儲存下一行的指令位址。
	movq	%rax, %rdi
	movl	$0, %eax                                # 這個應該是設定內嵌函式 MIN() 的回傳位址。
	call	printf@PLT                              # 呼叫函式：printf(); 
	movl	$0, %eax                                # 這個應該是 print(); 的回傳位址。
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:                                                  # Local Function Ending 1
	.size	main, .-main
	.ident	"GCC: (GNU) 11.2.0"
	.section	.note.GNU-stack,"",@progbits
