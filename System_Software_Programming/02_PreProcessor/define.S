	.file	"define.c"
	.text
	.section	.rodata
.LC0:
	.string	"MAX(4, 6): %d \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$6, %esi                                # 這個很明顯地是把數值 6 ，儲存到 %esi (Source Index Register, 32-bit)；但不知道 4 會從哪兒傳進去....
	leaq	.LC0(%rip), %rax                        # %rip 是程式索引暫存器 (Index Program)，用來儲存下一行的指令位址。
	movq	%rax, %rdi
	movl	$0, %eax                                # 將數值 0 儲存到 eax 暫存器。函式的回傳值必須儲存在 eax 暫存器。
	call	printf@PLT                              # 呼叫函式：printf(); 
	movl	$0, %eax                                # 將數值 0 儲存到 eax 暫存器。函式的回傳值必須儲存在 eax 暫存器。
	popq	%rbp                                    # 因為前面有 "pushq  %rbp"，所以這兒有 "popq  %rbp"。Base Pointer Register 要歸位。
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.2.0"
	.section	.note.GNU-stack,"",@progbits
