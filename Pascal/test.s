	.file "test.pas"
# Begin asmlist al_procedures

.section .text.n_p$program_$$_sangnto$boolar
	.balign 16,0x90
.globl	P$PROGRAM_$$_SANGNTO$BOOLAR
	.type	P$PROGRAM_$$_SANGNTO$BOOLAR,@function
P$PROGRAM_$$_SANGNTO$BOOLAR:
.Lc1:
	pushq	%rbp
.Lc3:
.Lc4:
	movq	%rsp,%rbp
.Lc5:
	leaq	-16(%rsp),%rsp
	movq	%rdi,-8(%rbp)
	movq	-8(%rbp),%rax
	movq	%rax,%rdi
	movb	$1,%dl
	movq	$1000000001,%rsi
	call	SYSTEM_$$_FILLCHAR$formal$INT64$BOOLEAN
	movq	-8(%rbp),%rax
	movb	$0,1(%rax)
	movl	$2,-12(%rbp)
	jmp	.Lj6
	.balign 8,0x90
.Lj5:
	jmp	.Lj9
	.balign 8,0x90
.Lj8:
	movl	-12(%rbp),%eax
	leal	1(%eax),%eax
	movl	%eax,-12(%rbp)
.Lj9:
	movq	-8(%rbp),%rdx
	movl	-12(%rbp),%eax
	cmpb	$0,(%rdx,%rax,1)
	jne	.Lj10
	jmp	.Lj8
.Lj10:
	movslq	-12(%rbp),%rcx
	movq	$1000000001,%rax
	cqto
	idivq	%rcx
	cmpl	$2,%eax
	jge	.Lj11
	jmp	.Lj12
.Lj11:
	movl	$1,-16(%rbp)
	.balign 8,0x90
.Lj13:
	movl	-16(%rbp),%edx
	leal	1(%edx),%edx
	movl	%edx,-16(%rbp)
	movq	-8(%rbp),%rsi
	movslq	-12(%rbp),%rcx
	movslq	-16(%rbp),%rdx
	imulq	%rdx,%rcx
	movb	$0,(%rsi,%rcx,1)
	cmpl	-16(%rbp),%eax
	jle	.Lj15
	jmp	.Lj13
.Lj15:
.Lj12:
	movl	-12(%rbp),%eax
	leal	1(%eax),%eax
	movl	%eax,-12(%rbp)
.Lj6:
	movslq	-12(%rbp),%rax
	cmpq	$31622,%rax
	jle	.Lj5
	jmp	.Lj7
.Lj7:
	movq	%rbp,%rsp
	popq	%rbp
	ret
.Lc2:
.Le0:
	.size	P$PROGRAM_$$_SANGNTO$BOOLAR, .Le0 - P$PROGRAM_$$_SANGNTO$BOOLAR

.section .text.n_p$program_$$_nto$int64$$boolean
	.balign 16,0x90
.globl	P$PROGRAM_$$_NTO$INT64$$BOOLEAN
	.type	P$PROGRAM_$$_NTO$INT64$$BOOLEAN,@function
P$PROGRAM_$$_NTO$INT64$$BOOLEAN:
.Lc6:
	pushq	%rbp
.Lc8:
.Lc9:
	movq	%rsp,%rbp
.Lc10:
	leaq	-32(%rsp),%rsp
	movq	%rdi,-8(%rbp)
	cmpq	$2,-8(%rbp)
	jl	.Lj18
	jmp	.Lj19
.Lj18:
	movb	$0,-12(%rbp)
	jmp	.Lj16
.Lj19:
	movl	-8(%rbp),%eax
	subl	$2,%eax
	cmpl	$2,%eax
	jb	.Lj20
	cmpl	$3,%eax
	stc
	je	.Lj20
	cmpl	$5,%eax
	stc
	je	.Lj20
	clc
.Lj20:
	jc	.Lj21
	jmp	.Lj22
.Lj21:
	movb	$1,-12(%rbp)
	jmp	.Lj16
.Lj22:
	movq	-8(%rbp),%rax
	cqto
	movq	$2,%rcx
	idivq	%rcx
	testq	%rdx,%rdx
	je	.Lj23
	jmp	.Lj24
.Lj23:
	movb	$0,-12(%rbp)
	jmp	.Lj16
.Lj24:
	movb	$1,-12(%rbp)
	movl	$3,-16(%rbp)
	jmp	.Lj26
	.balign 8,0x90
.Lj25:
	movslq	-16(%rbp),%rcx
	movq	-8(%rbp),%rax
	cqto
	idivq	%rcx
	testq	%rdx,%rdx
	je	.Lj28
	jmp	.Lj29
.Lj28:
	movb	$0,-12(%rbp)
	jmp	.Lj16
.Lj29:
	movl	-16(%rbp),%eax
	leal	2(%eax),%eax
	movl	%eax,-16(%rbp)
.Lj26:
	movslq	-16(%rbp),%rax
	fnstcw	-24(%rbp)
	fnstcw	-20(%rbp)
	orw	$3840,-24(%rbp)
	fildq	-8(%rbp)
	fsqrt
	fldcw	-24(%rbp)
	fistpq	-32(%rbp)
	fldcw	-20(%rbp)
	fwait
	cmpq	-32(%rbp),%rax
	jle	.Lj25
	jmp	.Lj27
.Lj27:
.Lj16:
	movb	-12(%rbp),%al
	movq	%rbp,%rsp
	popq	%rbp
	ret
.Lc7:
.Le1:
	.size	P$PROGRAM_$$_NTO$INT64$$BOOLEAN, .Le1 - P$PROGRAM_$$_NTO$INT64$$BOOLEAN

.section .text.n_main
	.balign 16,0x90
.globl	PASCALMAIN
	.type	PASCALMAIN,@function
PASCALMAIN:
.globl	main
	.type	main,@function
main:
.Lc11:
	pushq	%rbp
.Lc13:
.Lc14:
	movq	%rsp,%rbp
.Lc15:
	leaq	-16(%rsp),%rsp
	movq	%rbx,-8(%rbp)
	call	fpc_initializeunits
	movq	$U_$P$PROGRAM_$$_SNTO,%rax
	movq	%rax,%rdi
	call	P$PROGRAM_$$_SANGNTO$BOOLAR
	call	fpc_get_output
	movq	%rax,%rbx
	movslq	U_$P$PROGRAM_$$_D,%rdx
	movq	%rbx,%rsi
	movl	$0,%edi
	call	fpc_write_text_sint
	call	fpc_iocheck
	movq	%rbx,%rdi
	call	fpc_writeln_end
	call	fpc_iocheck
	call	fpc_do_exit
	movq	-8(%rbp),%rbx
	movq	%rbp,%rsp
	popq	%rbp
	ret
.Lc12:
.Le2:
	.size	main, .Le2 - main

.section .text
# End asmlist al_procedures
# Begin asmlist al_globals

.section .bss
	.type U_$P$PROGRAM_$$_SNTO,@object
	.size U_$P$PROGRAM_$$_SNTO,1000000001
U_$P$PROGRAM_$$_SNTO:
	.zero 1000000001

.section .bss
	.balign 4
	.type U_$P$PROGRAM_$$_I,@object
	.size U_$P$PROGRAM_$$_I,4
U_$P$PROGRAM_$$_I:
	.zero 4

.section .bss
	.balign 4
	.type U_$P$PROGRAM_$$_D,@object
	.size U_$P$PROGRAM_$$_D,4
U_$P$PROGRAM_$$_D:
	.zero 4

.section .data.n_INITFINAL
	.balign 8
.globl	INITFINAL
	.type	INITFINAL,@object
INITFINAL:
	.quad	1,0
	.quad	INIT$_$SYSTEM
	.quad	0
.Le3:
	.size	INITFINAL, .Le3 - INITFINAL

.section .data.n_FPC_THREADVARTABLES
	.balign 8
.globl	FPC_THREADVARTABLES
	.type	FPC_THREADVARTABLES,@object
FPC_THREADVARTABLES:
	.long	1
	.quad	THREADVARLIST_$SYSTEM$indirect
.Le4:
	.size	FPC_THREADVARTABLES, .Le4 - FPC_THREADVARTABLES

.section .data.n_FPC_RESOURCESTRINGTABLES
	.balign 8
.globl	FPC_RESOURCESTRINGTABLES
	.type	FPC_RESOURCESTRINGTABLES,@object
FPC_RESOURCESTRINGTABLES:
	.quad	0
.Le5:
	.size	FPC_RESOURCESTRINGTABLES, .Le5 - FPC_RESOURCESTRINGTABLES

.section .data.n_FPC_WIDEINITTABLES
	.balign 8
.globl	FPC_WIDEINITTABLES
	.type	FPC_WIDEINITTABLES,@object
FPC_WIDEINITTABLES:
	.quad	0
.Le6:
	.size	FPC_WIDEINITTABLES, .Le6 - FPC_WIDEINITTABLES

.section .data.n_FPC_RESSTRINITTABLES
	.balign 8
.globl	FPC_RESSTRINITTABLES
	.type	FPC_RESSTRINITTABLES,@object
FPC_RESSTRINITTABLES:
	.quad	0
.Le7:
	.size	FPC_RESSTRINITTABLES, .Le7 - FPC_RESSTRINITTABLES

.section .fpc.n_version
	.balign 16
	.type	__fpc_ident,@object
__fpc_ident:
	.ascii	"FPC 3.2.0 [2020/06/14] for x86_64 - Linux"
.Le8:
	.size	__fpc_ident, .Le8 - __fpc_ident

.section .data.n___stklen
	.balign 8
.globl	__stklen
	.type	__stklen,@object
__stklen:
	.quad	8388608
.Le9:
	.size	__stklen, .Le9 - __stklen

.section .data.n___heapsize
	.balign 8
.globl	__heapsize
	.type	__heapsize,@object
__heapsize:
	.quad	0
.Le10:
	.size	__heapsize, .Le10 - __heapsize

.section .data.n___fpc_valgrind
	.balign 8
.globl	__fpc_valgrind
	.type	__fpc_valgrind,@object
__fpc_valgrind:
	.byte	0
.Le11:
	.size	__fpc_valgrind, .Le11 - __fpc_valgrind

.section .data.n_FPC_RESLOCATION
	.balign 8
.globl	FPC_RESLOCATION
	.type	FPC_RESLOCATION,@object
FPC_RESLOCATION:
	.quad	0
.Le12:
	.size	FPC_RESLOCATION, .Le12 - FPC_RESLOCATION
# End asmlist al_globals
# Begin asmlist al_dwarf_frame

.section .debug_frame
.Lc16:
	.long	.Lc18-.Lc17
.Lc17:
	.long	-1
	.byte	1
	.byte	0
	.uleb128	1
	.sleb128	-4
	.byte	16
	.byte	12
	.uleb128	7
	.uleb128	8
	.byte	5
	.uleb128	16
	.uleb128	2
	.balign 4,0
.Lc18:
	.long	.Lc20-.Lc19
.Lc19:
	.quad	.Lc16
	.quad	.Lc1
	.quad	.Lc2-.Lc1
	.byte	4
	.long	.Lc3-.Lc1
	.byte	14
	.uleb128	16
	.byte	4
	.long	.Lc4-.Lc3
	.byte	5
	.uleb128	6
	.uleb128	4
	.byte	4
	.long	.Lc5-.Lc4
	.byte	13
	.uleb128	6
	.balign 4,0
.Lc20:
	.long	.Lc22-.Lc21
.Lc21:
	.quad	.Lc16
	.quad	.Lc6
	.quad	.Lc7-.Lc6
	.byte	4
	.long	.Lc8-.Lc6
	.byte	14
	.uleb128	16
	.byte	4
	.long	.Lc9-.Lc8
	.byte	5
	.uleb128	6
	.uleb128	4
	.byte	4
	.long	.Lc10-.Lc9
	.byte	13
	.uleb128	6
	.balign 4,0
.Lc22:
	.long	.Lc24-.Lc23
.Lc23:
	.quad	.Lc16
	.quad	.Lc11
	.quad	.Lc12-.Lc11
	.byte	4
	.long	.Lc13-.Lc11
	.byte	14
	.uleb128	16
	.byte	4
	.long	.Lc14-.Lc13
	.byte	5
	.uleb128	6
	.uleb128	4
	.byte	4
	.long	.Lc15-.Lc14
	.byte	13
	.uleb128	6
	.balign 4,0
.Lc24:
# End asmlist al_dwarf_frame
.section .note.GNU-stack,"",%progbits

