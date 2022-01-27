	.file "ucode_thutuvaolop.pas"
# Begin asmlist al_procedures

.section .text.n_main
	.balign 16,0x90
.globl	PASCALMAIN
	.type	PASCALMAIN,@function
PASCALMAIN:
.globl	main
	.type	main,@function
main:
.Lc1:
	pushq	%rbp
.Lc3:
.Lc4:
	movq	%rsp,%rbp
.Lc5:
	leaq	-32(%rsp),%rsp
	movq	%rbx,-24(%rbp)
	movq	%r12,-16(%rbp)
	call	fpc_initializeunits
	call	fpc_get_input
	movq	%rax,%rbx
	leaq	-8(%rbp),%rsi
	movq	%rbx,%rdi
	call	fpc_read_text_sint
	call	fpc_iocheck
	movl	-8(%rbp),%eax
	movl	%eax,U_$P$PROGRAM_$$_N
	movq	%rbx,%rdi
	call	fpc_readln_end
	call	fpc_iocheck
	movl	U_$P$PROGRAM_$$_N,%r12d
	cmpl	$1,%r12d
	jge	.Lj3
	jmp	.Lj4
.Lj3:
	movl	$0,U_$P$PROGRAM_$$_I
	.balign 8,0x90
.Lj5:
	movl	U_$P$PROGRAM_$$_I,%eax
	leal	1(%eax),%eax
	movl	%eax,U_$P$PROGRAM_$$_I
	call	fpc_get_input
	movq	%rax,%rbx
	leaq	-8(%rbp),%rsi
	movq	%rbx,%rdi
	call	fpc_read_text_sint
	call	fpc_iocheck
	movl	-8(%rbp),%eax
	movl	%eax,U_$P$PROGRAM_$$_C
	movq	%rbx,%rdi
	call	fpc_read_end
	call	fpc_iocheck
	movl	U_$P$PROGRAM_$$_C,%edx
	movl	U_$P$PROGRAM_$$_I,%eax
	movl	%eax,U_$P$PROGRAM_$$_A(,%rdx,4)
	cmpl	U_$P$PROGRAM_$$_I,%r12d
	jle	.Lj7
	jmp	.Lj5
.Lj7:
.Lj4:
	movl	U_$P$PROGRAM_$$_N,%r12d
	cmpl	$1,%r12d
	jge	.Lj8
	jmp	.Lj9
.Lj8:
	movl	$0,U_$P$PROGRAM_$$_I
	.balign 8,0x90
.Lj10:
	movl	U_$P$PROGRAM_$$_I,%eax
	leal	1(%eax),%eax
	movl	%eax,U_$P$PROGRAM_$$_I
	call	fpc_get_output
	movq	%rax,%rbx
	movl	U_$P$PROGRAM_$$_I,%eax
	movslq	U_$P$PROGRAM_$$_A(,%rax,4),%rdx
	movq	%rbx,%rsi
	movl	$0,%edi
	call	fpc_write_text_sint
	call	fpc_iocheck
	movl	$32,%edx
	movq	%rbx,%rsi
	movl	$0,%edi
	call	fpc_write_text_char
	call	fpc_iocheck
	movq	%rbx,%rdi
	call	fpc_write_end
	call	fpc_iocheck
	cmpl	U_$P$PROGRAM_$$_I,%r12d
	jle	.Lj12
	jmp	.Lj10
.Lj12:
.Lj9:
	call	fpc_do_exit
	movq	-24(%rbp),%rbx
	movq	-16(%rbp),%r12
	movq	%rbp,%rsp
	popq	%rbp
	ret
.Lc2:
.Le0:
	.size	main, .Le0 - main

.section .text
# End asmlist al_procedures
# Begin asmlist al_globals

.section .bss
	.balign 4
	.type U_$P$PROGRAM_$$_A,@object
	.size U_$P$PROGRAM_$$_A,400000004
U_$P$PROGRAM_$$_A:
	.zero 400000004

.section .bss
	.balign 4
	.type U_$P$PROGRAM_$$_I,@object
	.size U_$P$PROGRAM_$$_I,4
U_$P$PROGRAM_$$_I:
	.zero 4

.section .bss
	.balign 4
	.type U_$P$PROGRAM_$$_N,@object
	.size U_$P$PROGRAM_$$_N,4
U_$P$PROGRAM_$$_N:
	.zero 4

.section .bss
	.balign 4
	.type U_$P$PROGRAM_$$_C,@object
	.size U_$P$PROGRAM_$$_C,4
U_$P$PROGRAM_$$_C:
	.zero 4

.section .data.n_INITFINAL
	.balign 8
.globl	INITFINAL
	.type	INITFINAL,@object
INITFINAL:
	.quad	1,0
	.quad	INIT$_$SYSTEM
	.quad	0
.Le1:
	.size	INITFINAL, .Le1 - INITFINAL

.section .data.n_FPC_THREADVARTABLES
	.balign 8
.globl	FPC_THREADVARTABLES
	.type	FPC_THREADVARTABLES,@object
FPC_THREADVARTABLES:
	.long	1
	.quad	THREADVARLIST_$SYSTEM$indirect
.Le2:
	.size	FPC_THREADVARTABLES, .Le2 - FPC_THREADVARTABLES

.section .data.n_FPC_RESOURCESTRINGTABLES
	.balign 8
.globl	FPC_RESOURCESTRINGTABLES
	.type	FPC_RESOURCESTRINGTABLES,@object
FPC_RESOURCESTRINGTABLES:
	.quad	0
.Le3:
	.size	FPC_RESOURCESTRINGTABLES, .Le3 - FPC_RESOURCESTRINGTABLES

.section .data.n_FPC_WIDEINITTABLES
	.balign 8
.globl	FPC_WIDEINITTABLES
	.type	FPC_WIDEINITTABLES,@object
FPC_WIDEINITTABLES:
	.quad	0
.Le4:
	.size	FPC_WIDEINITTABLES, .Le4 - FPC_WIDEINITTABLES

.section .data.n_FPC_RESSTRINITTABLES
	.balign 8
.globl	FPC_RESSTRINITTABLES
	.type	FPC_RESSTRINITTABLES,@object
FPC_RESSTRINITTABLES:
	.quad	0
.Le5:
	.size	FPC_RESSTRINITTABLES, .Le5 - FPC_RESSTRINITTABLES

.section .fpc.n_version
	.balign 16
	.type	__fpc_ident,@object
__fpc_ident:
	.ascii	"FPC 3.2.0 [2020/06/14] for x86_64 - Linux"
.Le6:
	.size	__fpc_ident, .Le6 - __fpc_ident

.section .data.n___stklen
	.balign 8
.globl	__stklen
	.type	__stklen,@object
__stklen:
	.quad	8388608
.Le7:
	.size	__stklen, .Le7 - __stklen

.section .data.n___heapsize
	.balign 8
.globl	__heapsize
	.type	__heapsize,@object
__heapsize:
	.quad	0
.Le8:
	.size	__heapsize, .Le8 - __heapsize

.section .data.n___fpc_valgrind
	.balign 8
.globl	__fpc_valgrind
	.type	__fpc_valgrind,@object
__fpc_valgrind:
	.byte	0
.Le9:
	.size	__fpc_valgrind, .Le9 - __fpc_valgrind

.section .data.n_FPC_RESLOCATION
	.balign 8
.globl	FPC_RESLOCATION
	.type	FPC_RESLOCATION,@object
FPC_RESLOCATION:
	.quad	0
.Le10:
	.size	FPC_RESLOCATION, .Le10 - FPC_RESLOCATION
# End asmlist al_globals
# Begin asmlist al_dwarf_frame

.section .debug_frame
.Lc6:
	.long	.Lc8-.Lc7
.Lc7:
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
.Lc8:
	.long	.Lc10-.Lc9
.Lc9:
	.quad	.Lc6
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
.Lc10:
# End asmlist al_dwarf_frame
.section .note.GNU-stack,"",%progbits

