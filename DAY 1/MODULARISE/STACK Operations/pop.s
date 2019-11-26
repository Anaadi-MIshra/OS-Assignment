	.file	"pop.c"
	.text
	.comm	buffer,40,32
	.comm	top,4,4
	.section	.rodata
.LC0:
	.string	"Stack is underflow"
	.text
	.globl	pop
	.type	pop, @function
pop:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	top(%rip), %eax
	cmpl	$-1, %eax
	jne	.L2
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	jmp	.L1
.L2:
	movl	top(%rip), %eax
	subl	$1, %eax
	movl	%eax, top(%rip)
.L1:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	pop, .-pop
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
