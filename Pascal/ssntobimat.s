	.file "ssntobimat.pas"
# Begin asmlist al_procedures

.section .text.n_p$program_$$_nto$int64$$boolean
	.balign 16,0x90
.globl	P$PROGRAM_$$_NTO$INT64$$BOOLEAN
	.type	P$PROGRAM_$$_NTO$INT64$$BOOLEAN,@function
P$PROGRAM_$$_NTO$INT64$$BOOLEAN:
.Lc1:
	pushq	%rbp
.Lc3:
.Lc4:
	movq	%rsp,%rbp
.Lc5:
	leaq	-32(%rsp),%rsp
	movq	%rdi,-8(%rbp)
	cmpq	$2,-8(%rbp)
	jl	.Lj5
	jmp	.Lj6
.Lj5:
	movb	$0,-12(%rbp)
	jmp	.Lj3
.Lj6:
	movl	-8(%rbp),%eax
	subl	$2,%eax
	cmpl	$2,%eax
	jb	.Lj7
	cmpl	$3,%eax
	stc
	je	.Lj7
	cmpl	$5,%eax
	stc
	je	.Lj7
	clc
.Lj7:
	jc	.Lj8
	jmp	.Lj9
.Lj8:
	movb	$1,-12(%rbp)
	jmp	.Lj3
.Lj9:
	movq	-8(%rbp),%rax
	cqto
	movq	$6,%rcx
	idivq	%rcx
	cmpl	$1,%edx
	je	.Lj10
	cmpl	$5,%edx
	je	.Lj10
.Lj10:
	jne	.Lj11
	jmp	.Lj12
.Lj12:
	movq	-8(%rbp),%rax
	cqto
	movq	$2,%rcx
	idivq	%rcx
	testq	%rdx,%rdx
	je	.Lj11
	jmp	.Lj13
.Lj11:
	movb	$0,-12(%rbp)
	jmp	.Lj3
.Lj13:
	movb	$1,-12(%rbp)
	movl	$3,-16(%rbp)
	jmp	.Lj15
	.balign 8,0x90
.Lj14:
	movslq	-16(%rbp),%rcx
	movq	-8(%rbp),%rax
	cqto
	idivq	%rcx
	testq	%rdx,%rdx
	je	.Lj17
	jmp	.Lj18
.Lj17:
	movb	$0,-12(%rbp)
	jmp	.Lj3
.Lj18:
	movl	-16(%rbp),%eax
	leal	2(%eax),%eax
	movl	%eax,-16(%rbp)
.Lj15:
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
	jle	.Lj14
	jmp	.Lj16
.Lj16:
.Lj3:
	movb	-12(%rbp),%al
	movq	%rbp,%rsp
	popq	%rbp
	ret
.Lc2:
.Le0:
	.size	P$PROGRAM_$$_NTO$INT64$$BOOLEAN, .Le0 - P$PROGRAM_$$_NTO$INT64$$BOOLEAN

.section .text.n_main
	.balign 16,0x90
.globl	PASCALMAIN
	.type	PASCALMAIN,@function
PASCALMAIN:
.globl	main
	.type	main,@function
main:
.Lc6:
	pushq	%rbp
.Lc8:
.Lc9:
	movq	%rsp,%rbp
.Lc10:
	leaq	-16(%rsp),%rsp
	movq	%rbx,-8(%rbp)
	call	fpc_initializeunits
	call	fpc_get_input
	movq	%rax,%rbx
	movq	$U_$P$PROGRAM_$$_A,%rsi
	movq	%rbx,%rdi
	call	fpc_read_text_sint
	call	fpc_iocheck
	movq	%rbx,%rdi
	call	fpc_readln_end
	call	fpc_iocheck
	jmp	.Lj20
	.balign 8,0x90
.Lj19:
	movq	U_$P$PROGRAM_$$_A,%rdi
	call	P$PROGRAM_$$_NTO$INT64$$BOOLEAN
	testb	%al,%al
	jne	.Lj22
	jmp	.Lj23
.Lj22:
	call	fpc_get_output
	movq	%rax,%rbx
	movq	U_$P$PROGRAM_$$_A,%rdx
	movq	%rbx,%rsi
	movl	$0,%edi
	call	fpc_write_text_sint
	call	fpc_iocheck
	movq	%rbx,%rdi
	call	fpc_writeln_end
	call	fpc_iocheck
.Lj23:
	movq	U_$P$PROGRAM_$$_A,%rcx
	movq	$7378697629483820647,%rax
	imulq	%rcx
	sarq	$2,%rdx
	shrq	$63,%rcx
	addq	%rcx,%rdx
	movq	%rdx,U_$P$PROGRAM_$$_A
.Lj20:
	cmpq	$0,U_$P$PROGRAM_$$_A
	jne	.Lj19
	jmp	.Lj21
.Lj21:
	call	fpc_do_exit
	movq	-8(%rbp),%rbx
	movq	%rbp,%rsp
	popq	%rbp
	ret
.Lc7:
.Le1:
	.size	main, .Le1 - main

.section .text
# End asmlist al_procedures
# Begin asmlist al_globals

.section .bss
	.balign 8
	.type U_$P$PROGRAM_$$_A,@object
	.size U_$P$PROGRAM_$$_A,8
U_$P$PROGRAM_$$_A:
	.zero 8

.section .data.n_INITFINAL
	.balign 8
.globl	INITFINAL
	.type	INITFINAL,@object
INITFINAL:
	.quad	1,0
	.quad	INIT$_$SYSTEM
	.quad	0
.Le2:
	.size	INITFINAL, .Le2 - INITFINAL

.section .data.n_FPC_THREADVARTABLES
	.balign 8
.globl	FPC_THREADVARTABLES
	.type	FPC_THREADVARTABLES,@object
FPC_THREADVARTABLES:
	.long	1
	.quad	THREADVARLIST_$SYSTEM$indirect
.Le3:
	.size	FPC_THREADVARTABLES, .Le3 - FPC_THREADVARTABLES

.section .data.n_FPC_RESOURCESTRINGTABLES
	.balign 8
.globl	FPC_RESOURCESTRINGTABLES
	.type	FPC_RESOURCESTRINGTABLES,@object
FPC_RESOURCESTRINGTABLES:
	.quad	0
.Le4:
	.size	FPC_RESOURCESTRINGTABLES, .Le4 - FPC_RESOURCESTRINGTABLES

.section .data.n_FPC_WIDEINITTABLES
	.balign 8
.globl	FPC_WIDEINITTABLES
	.type	FPC_WIDEINITTABLES,@object
FPC_WIDEINITTABLES:
	.quad	0
.Le5:
	.size	FPC_WIDEINITTABLES, .Le5 - FPC_WIDEINITTABLES

.section .data.n_FPC_RESSTRINITTABLES
	.balign 8
.globl	FPC_RESSTRINITTABLES
	.type	FPC_RESSTRINITTABLES,@object
FPC_RESSTRINITTABLES:
	.quad	0
.Le6:
	.size	FPC_RESSTRINITTABLES, .Le6 - FPC_RESSTRINITTABLES

.section .fpc.n_version
	.balign 16
	.type	__fpc_ident,@object
__fpc_ident:
	.ascii	"FPC 3.2.0 [2020/06/14] for x86_64 - Linux"
.Le7:
	.size	__fpc_ident, .Le7 - __fpc_ident

.section .data.n___stklen
	.balign 8
.globl	__stklen
	.type	__stklen,@object
__stklen:
	.quad	8388608
.Le8:
	.size	__stklen, .Le8 - __stklen

.section .data.n___heapsize
	.balign 8
.globl	__heapsize
	.type	__heapsize,@object
__heapsize:
	.quad	0
.Le9:
	.size	__heapsize, .Le9 - __heapsize

.section .data.n___fpc_valgrind
	.balign 8
.globl	__fpc_valgrind
	.type	__fpc_valgrind,@object
__fpc_valgrind:
	.byte	0
.Le10:
	.size	__fpc_valgrind, .Le10 - __fpc_valgrind

.section .data.n_FPC_RESLOCATION
	.balign 8
.globl	FPC_RESLOCATION
	.type	FPC_RESLOCATION,@object
FPC_RESLOCATION:
	.quad	0
.Le11:
	.size	FPC_RESLOCATION, .Le11 - FPC_RESLOCATION
# End asmlist al_globals
# Begin asmlist al_dwarf_frame

.section .debug_frame
.Lc11:
	.long	.Lc13-.Lc12
.Lc12:
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
.Lc13:
	.long	.Lc15-.Lc14
.Lc14:
	.quad	.Lc11
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
.Lc15:
	.long	.Lc17-.Lc16
.Lc16:
	.quad	.Lc11
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
.Lc17:
# End asmlist al_dwarf_frame
.section .note.GNU-stack,"",%progbits

