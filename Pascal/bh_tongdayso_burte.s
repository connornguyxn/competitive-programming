	.file "bh_tongdayso_burte.pas"
# Begin asmlist al_procedures

.section .text.n_p$program_$$_f$longint$longint$$longint
	.balign 16,0x90
.globl	P$PROGRAM_$$_F$LONGINT$LONGINT$$LONGINT
	.type	P$PROGRAM_$$_F$LONGINT$LONGINT$$LONGINT,@function
P$PROGRAM_$$_F$LONGINT$LONGINT$$LONGINT:
.Lc1:
	pushq	%rbp
.Lc3:
.Lc4:
	movq	%rsp,%rbp
.Lc5:
	leaq	-32(%rsp),%rsp
	movl	%edi,-8(%rbp)
	movl	%esi,-16(%rbp)
	cmpl	$2,-8(%rbp)
	je	.Lj5
	jmp	.Lj6
.Lj5:
	movl	-16(%rbp),%eax
	movl	%eax,-20(%rbp)
	jmp	.Lj3
.Lj6:
	movl	$2,-24(%rbp)
	jmp	.Lj8
	.balign 8,0x90
.Lj7:
	movl	-24(%rbp),%eax
	leal	1(%eax),%eax
	movl	%eax,-24(%rbp)
.Lj8:
	movslq	-8(%rbp),%rax
	movslq	-24(%rbp),%rcx
	cqto
	idivq	%rcx
	testq	%rdx,%rdx
	je	.Lj7
	jmp	.Lj9
.Lj9:
	movl	-16(%rbp),%eax
	leal	1(%eax),%esi
	movl	-24(%rbp),%edi
	call	P$PROGRAM_$$_F$LONGINT$LONGINT$$LONGINT
	movl	%eax,-20(%rbp)
	jmp	.Lj3
.Lj3:
	movl	-20(%rbp),%eax
	movq	%rbp,%rsp
	popq	%rbp
	ret
.Lc2:
.Le0:
	.size	P$PROGRAM_$$_F$LONGINT$LONGINT$$LONGINT, .Le0 - P$PROGRAM_$$_F$LONGINT$LONGINT$$LONGINT

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
	movq	%rbx,-16(%rbp)
	call	fpc_initializeunits
	call	fpc_get_input
	movq	%rax,%rbx
	leaq	-8(%rbp),%rsi
	movq	%rbx,%rdi
	call	fpc_read_text_sint
	call	fpc_iocheck
	movl	-8(%rbp),%eax
	movl	%eax,U_$P$PROGRAM_$$_A
	leaq	-8(%rbp),%rsi
	movq	%rbx,%rdi
	call	fpc_read_text_sint
	call	fpc_iocheck
	movl	-8(%rbp),%eax
	movl	%eax,U_$P$PROGRAM_$$_B
	movq	%rbx,%rdi
	call	fpc_readln_end
	call	fpc_iocheck
	movl	U_$P$PROGRAM_$$_B,%ebx
	cmpl	U_$P$PROGRAM_$$_A,%ebx
	jge	.Lj10
	jmp	.Lj11
.Lj10:
	movl	U_$P$PROGRAM_$$_A,%eax
	leal	-1(%eax),%eax
	movl	%eax,U_$P$PROGRAM_$$_I
	.balign 8,0x90
.Lj12:
	movl	U_$P$PROGRAM_$$_I,%eax
	leal	1(%eax),%eax
	movl	%eax,U_$P$PROGRAM_$$_I
	movl	U_$P$PROGRAM_$$_I,%edi
	movl	$1,%esi
	call	P$PROGRAM_$$_F$LONGINT$LONGINT$$LONGINT
	addl	U_$P$PROGRAM_$$_D,%eax
	movl	%eax,U_$P$PROGRAM_$$_D
	cmpl	U_$P$PROGRAM_$$_I,%ebx
	jle	.Lj14
	jmp	.Lj12
.Lj14:
.Lj11:
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
	movq	-16(%rbp),%rbx
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
	.balign 4
	.type U_$P$PROGRAM_$$_A,@object
	.size U_$P$PROGRAM_$$_A,4
U_$P$PROGRAM_$$_A:
	.zero 4

.section .bss
	.balign 4
	.type U_$P$PROGRAM_$$_B,@object
	.size U_$P$PROGRAM_$$_B,4
U_$P$PROGRAM_$$_B:
	.zero 4

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

