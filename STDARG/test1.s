	.file	"test1.c"
	.text
	.globl	sum
	.def	sum;	.scl	2;	.type	32;	.endef
	.seh_proc	sum
sum:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movq	%r9, 40(%rbp)
	movl	16(%rbp), %eax
	movl	%eax, -4(%rbp)
	leaq	24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L2
.L3:
	movl	-8(%rbp), %eax
	addl	%eax, -4(%rbp)
.L2:
	movq	-16(%rbp), %rax
	leaq	8(%rax), %rdx
	movq	%rdx, -16(%rbp)
	movl	(%rax), %eax
	movl	%eax, -8(%rbp)
	cmpl	$0, -8(%rbp)
	jne	.L3
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "tong = %d\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	movl	$0, %r9d
	movl	$3, %r8d
	movl	$2, %edx
	movl	$1, %ecx
	call	sum
	movl	%eax, %edx
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (GNU) 11.4.0"
	.def	printf;	.scl	2;	.type	32;	.endef
