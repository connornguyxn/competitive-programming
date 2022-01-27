	.file "congphanso.pas"
# Begin asmlist al_procedures

.section .text.n_p$program_$$_ucln$int64$int64$$int64
	.balign 16,0x90
.globl	P$PROGRAM_$$_UCLN$INT64$INT64$$INT64
	.type	P$PROGRAM_$$_UCLN$INT64$INT64$$INT64,@function
P$PROGRAM_$$_UCLN$INT64$INT64$$INT64:
.Lc1:
	pushq	%rbp
.Lc3:
.Lc4:
	movq	%rsp,%rbp
.Lc5:
	leaq	-32(%rsp),%rsp
	movq	%rdi,-8(%rbp)
	movq	%rsi,-16(%rbp)
	jmp	.Lj6
	.balign 8,0x90
.Lj5:
	movq	-8(%rbp),%rax
	cqto
	idivq	-16(%rbp)
	movq	%rdx,-32(%rbp)
	movq	-16(%rbp),%rax
	movq	%rax,-8(%rbp)
	movq	-32(%rbp),%rax
	movq	%rax,-16(%rbp)
.Lj6:
	cmpq	$0,-16(%rbp)
	jne	.Lj5
	jmp	.Lj7
.Lj7:
	movq	-8(%rbp),%rax
	movq	%rax,-24(%rbp)
	jmp	.Lj3
.Lj3:
	movq	-24(%rbp),%rax
	movq	%rbp,%rsp
	popq	%rbp
	ret
.Lc2:
.Le0:
	.size	P$PROGRAM_$$_UCLN$INT64$INT64$$INT64, .Le0 - P$PROGRAM_$$_UCLN$INT64$INT64$$INT64

.section .text.n_p$program_$$_bcnn$int64$int64$$int64
	.balign 16,0x90
.globl	P$PROGRAM_$$_BCNN$INT64$INT64$$INT64
	.type	P$PROGRAM_$$_BCNN$INT64$INT64$$INT64,@function
P$PROGRAM_$$_BCNN$INT64$INT64$$INT64:
.Lc6:
	pushq	%rbp
.Lc8:
.Lc9:
	movq	%rsp,%rbp
.Lc10:
	leaq	-32(%rsp),%rsp
	movq	%rbx,-32(%rbp)
	movq	%rdi,-8(%rbp)
	movq	%rsi,-16(%rbp)
	movq	-8(%rbp),%rax
	movq	-16(%rbp),%rbx
	imulq	%rax,%rbx
	movq	-16(%rbp),%rsi
	movq	-8(%rbp),%rdi
	call	P$PROGRAM_$$_UCLN$INT64$INT64$$INT64
	movq	%rax,%rcx
	movq	%rbx,%rax
	cqto
	idivq	%rcx
	movq	%rax,-24(%rbp)
	jmp	.Lj8
.Lj8:
	movq	-24(%rbp),%rax
	movq	-32(%rbp),%rbx
	movq	%rbp,%rsp
	popq	%rbp
	ret
.Lc7:
.Le1:
	.size	P$PROGRAM_$$_BCNN$INT64$INT64$$INT64, .Le1 - P$PROGRAM_$$_BCNN$INT64$INT64$$INT64

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
	call	fpc_get_input
	movq	%rax,%rbx
	movq	$U_$P$PROGRAM_$$_A,%rsi
	movq	%rbx,%rdi
	call	fpc_read_text_sint
	call	fpc_iocheck
	movq	$U_$P$PROGRAM_$$_B,%rsi
	movq	%rbx,%rdi
	call	fpc_read_text_sint
	call	fpc_iocheck
	movq	%rbx,%rdi
	call	fpc_readln_end
	call	fpc_iocheck
	call	fpc_get_input
	movq	%rax,%rbx
	movq	$U_$P$PROGRAM_$$_C,%rsi
	movq	%rbx,%rdi
	call	fpc_read_text_sint
	call	fpc_iocheck
	movq	$U_$P$PROGRAM_$$_D,%rsi
	movq	%rbx,%rdi
	call	fpc_read_text_sint
	call	fpc_iocheck
	movq	%rbx,%rdi
	call	fpc_readln_end
	call	fpc_iocheck
	movq	U_$P$PROGRAM_$$_D,%rsi
	movq	U_$P$PROGRAM_$$_B,%rdi
	call	P$PROGRAM_$$_BCNN$INT64$INT64$$INT64
	movq	%rax,U_$P$PROGRAM_$$_MS
	movq	U_$P$PROGRAM_$$_MS,%rax
	cqto
	idivq	U_$P$PROGRAM_$$_B
	movq	%rax,%rcx
	movq	U_$P$PROGRAM_$$_A,%rax
	imulq	%rax,%rcx
	movq	U_$P$PROGRAM_$$_MS,%rax
	cqto
	idivq	U_$P$PROGRAM_$$_D
	movq	U_$P$PROGRAM_$$_C,%rdx
	imulq	%rdx,%rax
	leaq	(%rcx,%rax),%rax
	movq	%rax,U_$P$PROGRAM_$$_TS
	call	fpc_get_output
	movq	%rax,%rbx
	movq	U_$P$PROGRAM_$$_MS,%rsi
	movq	U_$P$PROGRAM_$$_TS,%rdi
	call	P$PROGRAM_$$_UCLN$INT64$INT64$$INT64
	movq	%rax,%rcx
	movq	U_$P$PROGRAM_$$_TS,%rax
	cqto
	idivq	%rcx
	movq	%rax,%rdx
	movq	%rbx,%rsi
	movl	$0,%edi
	call	fpc_write_text_sint
	call	fpc_iocheck
	movl	$32,%edx
	movq	%rbx,%rsi
	movl	$0,%edi
	call	fpc_write_text_char
	call	fpc_iocheck
	movq	U_$P$PROGRAM_$$_MS,%rsi
	movq	U_$P$PROGRAM_$$_TS,%rdi
	call	P$PROGRAM_$$_UCLN$INT64$INT64$$INT64
	movq	%rax,%rcx
	movq	U_$P$PROGRAM_$$_MS,%rax
	cqto
	idivq	%rcx
	movq	%rax,%rdx
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
	.balign 8
	.type U_$P$PROGRAM_$$_A,@object
	.size U_$P$PROGRAM_$$_A,8
U_$P$PROGRAM_$$_A:
	.zero 8

.section .bss
	.balign 8
	.type U_$P$PROGRAM_$$_B,@object
	.size U_$P$PROGRAM_$$_B,8
U_$P$PROGRAM_$$_B:
	.zero 8

.section .bss
	.balign 8
	.type U_$P$PROGRAM_$$_C,@object
	.size U_$P$PROGRAM_$$_C,8
U_$P$PROGRAM_$$_C:
	.zero 8

.section .bss
	.balign 8
	.type U_$P$PROGRAM_$$_D,@object
	.size U_$P$PROGRAM_$$_D,8
U_$P$PROGRAM_$$_D:
	.zero 8

.section .bss
	.balign 8
	.type U_$P$PROGRAM_$$_TS,@object
	.size U_$P$PROGRAM_$$_TS,8
U_$P$PROGRAM_$$_TS:
	.zero 8

.section .bss
	.balign 8
	.type U_$P$PROGRAM_$$_MS,@object
	.size U_$P$PROGRAM_$$_MS,8
U_$P$PROGRAM_$$_MS:
	.zero 8

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

