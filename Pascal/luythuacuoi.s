	.file "luythuacuoi.pas"
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
	leaq	-800(%rsp),%rsp
	movq	%rbx,-792(%rbp)
	movq	%r12,-784(%rbp)
	call	fpc_initializeunits
	call	fpc_get_input
	movq	%rax,%rbx
	movq	$U_$P$PROGRAM_$$_A,%r12
	movq	%r12,%rdi
	call	fpc_ansistr_decr_ref
	movq	%r12,%rsi
	movl	$0,%edx
	movq	%rbx,%rdi
	call	fpc_read_text_ansistr
	call	fpc_iocheck
	movq	%rbx,%rdi
	call	fpc_readln_end
	call	fpc_iocheck
	call	fpc_get_input
	movq	%rax,%rbx
	movq	$U_$P$PROGRAM_$$_N,%r12
	movq	%r12,%rdi
	call	fpc_ansistr_decr_ref
	movq	%r12,%rsi
	movl	$0,%edx
	movq	%rbx,%rdi
	call	fpc_read_text_ansistr
	call	fpc_iocheck
	movq	%rbx,%rdi
	call	fpc_readln_end
	call	fpc_iocheck
	movq	U_$P$PROGRAM_$$_A,%rdx
	movq	U_$P$PROGRAM_$$_A,%rax
	testq	%rax,%rax
	je	.Lj7
	movq	-8(%rax),%rax
.Lj7:
	movzbl	-1(%rdx,%rax,1),%eax
	shlq	$8,%rax
	orq	$1,%rax
	movw	%ax,-264(%rbp)
	leaq	-264(%rbp),%rsi
	leaq	-8(%rbp),%rdx
	movq	$4,%rdi
	call	fpc_val_sint_shortstr
	movl	%eax,U_$P$PROGRAM_$$_DU
	movl	-8(%rbp),%eax
	movl	%eax,U_$P$PROGRAM_$$_E
	movq	U_$P$PROGRAM_$$_N,%rax
	movq	U_$P$PROGRAM_$$_N,%rdx
	testq	%rdx,%rdx
	je	.Lj8
	movq	-8(%rdx),%rdx
.Lj8:
	subq	$1,%rdx
	movzbl	-1(%rax,%rdx,1),%eax
	shlq	$8,%rax
	orq	$1,%rax
	movw	%ax,-520(%rbp)
	leaq	-520(%rbp),%rcx
	movq	U_$P$PROGRAM_$$_N,%rax
	movq	U_$P$PROGRAM_$$_N,%rdx
	testq	%rdx,%rdx
	je	.Lj9
	movq	-8(%rdx),%rdx
.Lj9:
	movzbl	-1(%rax,%rdx,1),%eax
	shlq	$8,%rax
	orq	$1,%rax
	movw	%ax,-776(%rbp)
	leaq	-776(%rbp),%rdx
	movq	$255,%rsi
	leaq	-256(%rbp),%rdi
	call	fpc_shortstr_concat
	leaq	-256(%rbp),%rsi
	leaq	-264(%rbp),%rdx
	movq	$4,%rdi
	call	fpc_val_sint_shortstr
	movl	%eax,U_$P$PROGRAM_$$_NR
	movl	-264(%rbp),%eax
	movl	%eax,U_$P$PROGRAM_$$_E
	movslq	U_$P$PROGRAM_$$_DU,%rax
	movslq	U_$P$PROGRAM_$$_DU,%rdx
	imulq	%rdx,%rax
	cqto
	movq	$10,%rcx
	idivq	%rcx
	movl	%edx,U_$P$PROGRAM_$$_DU+4
	movslq	U_$P$PROGRAM_$$_DU+4,%rax
	movslq	U_$P$PROGRAM_$$_DU,%rdx
	imulq	%rdx,%rax
	cqto
	movq	$10,%rcx
	idivq	%rcx
	movl	%edx,U_$P$PROGRAM_$$_DU+8
	movslq	U_$P$PROGRAM_$$_DU+8,%rax
	movslq	U_$P$PROGRAM_$$_DU,%rdx
	imulq	%rdx,%rax
	cqto
	movq	$10,%rcx
	idivq	%rcx
	movl	%edx,U_$P$PROGRAM_$$_DU+12
	call	fpc_get_output
	movq	%rax,%rbx
	movslq	U_$P$PROGRAM_$$_NR,%rax
	subq	$1,%rax
	cqto
	movq	$4,%rcx
	idivq	%rcx
	movslq	U_$P$PROGRAM_$$_DU(,%rdx,4),%rdx
	movq	%rbx,%rsi
	movl	$0,%edi
	call	fpc_write_text_sint
	call	fpc_iocheck
	movq	%rbx,%rdi
	call	fpc_writeln_end
	call	fpc_iocheck
	call	fpc_do_exit
	movq	-792(%rbp),%rbx
	movq	-784(%rbp),%r12
	movq	%rbp,%rsp
	popq	%rbp
	ret
.Lc2:
.Le0:
	.size	main, .Le0 - main

.section .text.n_p$program_$$_init_implicit$
	.balign 16,0x90
.globl	INIT$_$P$PROGRAM
	.type	INIT$_$P$PROGRAM,@function
INIT$_$P$PROGRAM:
.globl	P$PROGRAM_$$_init_implicit$
	.type	P$PROGRAM_$$_init_implicit$,@function
P$PROGRAM_$$_init_implicit$:
.Lc6:
	pushq	%rbp
.Lc8:
.Lc9:
	movq	%rsp,%rbp
.Lc10:
	movq	%rbp,%rsp
	popq	%rbp
	ret
.Lc7:
.Le1:
	.size	P$PROGRAM_$$_init_implicit$, .Le1 - P$PROGRAM_$$_init_implicit$

.section .text.n_p$program_$$_finalize_implicit$
	.balign 16,0x90
.globl	PASCALFINALIZE
	.type	PASCALFINALIZE,@function
PASCALFINALIZE:
.globl	FINALIZE$_$P$PROGRAM
	.type	FINALIZE$_$P$PROGRAM,@function
FINALIZE$_$P$PROGRAM:
.globl	P$PROGRAM_$$_finalize_implicit$
	.type	P$PROGRAM_$$_finalize_implicit$,@function
P$PROGRAM_$$_finalize_implicit$:
.Lc11:
	pushq	%rbp
.Lc13:
.Lc14:
	movq	%rsp,%rbp
.Lc15:
	movq	$U_$P$PROGRAM_$$_A,%rax
	movq	%rax,%rdi
	call	fpc_ansistr_decr_ref
	movq	$U_$P$PROGRAM_$$_N,%rdi
	call	fpc_ansistr_decr_ref
	movq	%rbp,%rsp
	popq	%rbp
	ret
.Lc12:
.Le2:
	.size	P$PROGRAM_$$_finalize_implicit$, .Le2 - P$PROGRAM_$$_finalize_implicit$

.section .text
# End asmlist al_procedures
# Begin asmlist al_globals

.section .bss
	.balign 4
	.type U_$P$PROGRAM_$$_DU,@object
	.size U_$P$PROGRAM_$$_DU,16
U_$P$PROGRAM_$$_DU:
	.zero 16

.section .bss
	.balign 8
	.type U_$P$PROGRAM_$$_A,@object
	.size U_$P$PROGRAM_$$_A,8
U_$P$PROGRAM_$$_A:
	.zero 8

.section .bss
	.balign 8
	.type U_$P$PROGRAM_$$_N,@object
	.size U_$P$PROGRAM_$$_N,8
U_$P$PROGRAM_$$_N:
	.zero 8

.section .bss
	.balign 4
	.type U_$P$PROGRAM_$$_E,@object
	.size U_$P$PROGRAM_$$_E,4
U_$P$PROGRAM_$$_E:
	.zero 4

.section .bss
	.balign 4
	.type U_$P$PROGRAM_$$_NR,@object
	.size U_$P$PROGRAM_$$_NR,4
U_$P$PROGRAM_$$_NR:
	.zero 4

.section .data.n_INITFINAL
	.balign 8
.globl	INITFINAL
	.type	INITFINAL,@object
INITFINAL:
	.quad	2,0
	.quad	INIT$_$SYSTEM
	.quad	0
	.quad	INIT$_$P$PROGRAM
	.quad	FINALIZE$_$P$PROGRAM
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

