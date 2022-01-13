	.file	"main.c"
	.section	.rodata
.LC2:
	.string	"2 ^ 10 = %f \n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
	fldl	.LC0
	fstpl	24(%esp)
	fldl	.LC1
	fstpl	24(%esp)
	movl	$.LC2, %eax
	fldl	24(%esp)
	fstpl	4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	971968279
	.long	1075881136
	.align 8
.LC1:
	.long	0
	.long	1083179008
	.ident	"GCC: (GNU) 4.4.5 20101112 (Red Hat 4.4.5-2)"
	.section	.note.GNU-stack,"",@progbits
