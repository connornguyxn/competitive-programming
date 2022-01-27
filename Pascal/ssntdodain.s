	.file "ssntdodain.pas"
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
	movq	$2,%rcx
	idivq	%rcx
	testq	%rdx,%rdx
	je	.Lj10
	jmp	.Lj11
.Lj10:
	movb	$0,-12(%rbp)
	jmp	.Lj3
.Lj11:
	movb	$1,-12(%rbp)
	movl	$3,-16(%rbp)
	jmp	.Lj13
	.balign 8,0x90
.Lj12:
	movslq	-16(%rbp),%rcx
	movq	-8(%rbp),%rax
	cqto
	idivq	%rcx
	testq	%rdx,%rdx
	je	.Lj15
	jmp	.Lj16
.Lj15:
	movb	$0,-12(%rbp)
	jmp	.Lj3
.Lj16:
	movl	-16(%rbp),%eax
	leal	2(%eax),%eax
	movl	%eax,-16(%rbp)
.Lj13:
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
	jle	.Lj12
	jmp	.Lj14
.Lj14:
.Lj3:
	movb	-12(%rbp),%al
	movq	%rbp,%rsp
	popq	%rbp
	ret
.Lc2:
.Le0:
	.size	P$PROGRAM_$$_NTO$INT64$$BOOLEAN, .Le0 - P$PROGRAM_$$_NTO$INT64$$BOOLEAN

.section .text.n_p$program_$$_inter$shortstring$$int64
	.balign 16,0x90
.globl	P$PROGRAM_$$_INTER$SHORTSTRING$$INT64
	.type	P$PROGRAM_$$_INTER$SHORTSTRING$$INT64,@function
P$PROGRAM_$$_INTER$SHORTSTRING$$INT64:
.Lc6:
	pushq	%rbp
.Lc8:
.Lc9:
	movq	%rsp,%rbp
.Lc10:
	leaq	-288(%rsp),%rsp
	movq	%rdi,-8(%rbp)
	movq	-8(%rbp),%rax
	movq	%rax,%rdx
	movq	$255,%rsi
	leaq	-276(%rbp),%rdi
	call	fpc_shortstr_to_shortstr
	leaq	-276(%rbp),%rsi
	leaq	-8(%rbp),%rdx
	movq	$8,%rdi
	call	fpc_val_sint_shortstr
	movq	%rax,-16(%rbp)
	movl	-8(%rbp),%eax
	movl	%eax,-20(%rbp)
	movq	-16(%rbp),%rax
	movq	%rbp,%rsp
	popq	%rbp
	ret
.Lc7:
.Le1:
	.size	P$PROGRAM_$$_INTER$SHORTSTRING$$INT64, .Le1 - P$PROGRAM_$$_INTER$SHORTSTRING$$INT64

.section .text.n_p$program_$$_try$shortstring$longint
	.balign 16,0x90
.globl	P$PROGRAM_$$_TRY$SHORTSTRING$LONGINT
	.type	P$PROGRAM_$$_TRY$SHORTSTRING$LONGINT,@function
P$PROGRAM_$$_TRY$SHORTSTRING$LONGINT:
.Lc11:
	pushq	%rbp
.Lc13:
.Lc14:
	movq	%rsp,%rbp
.Lc15:
	leaq	-800(%rsp),%rsp
	movq	%rbx,-800(%rbp)
	movq	%rdi,-8(%rbp)
	movl	%esi,-16(%rbp)
	movq	-8(%rbp),%rax
	movq	%rax,%rdx
	movq	$255,%rsi
	leaq	-276(%rbp),%rdi
	call	fpc_shortstr_to_shortstr
	call	fpc_get_output
	movq	%rax,%rbx
	leaq	-276(%rbp),%rdx
	movq	%rbx,%rsi
	movl	$0,%edi
	call	fpc_write_text_shortstr
	call	fpc_iocheck
	movq	%rbx,%rdi
	call	fpc_writeln_end
	call	fpc_iocheck
	cmpl	$1,-16(%rbp)
	je	.Lj21
	jmp	.Lj22
.Lj21:
	movl	$0,-20(%rbp)
	.balign 8,0x90
.Lj23:
	movl	-20(%rbp),%eax
	leal	1(%eax),%eax
	movl	%eax,-20(%rbp)
	movl	-20(%rbp),%eax
	movzbl	TC_$P$PROGRAM_$$_C1-1(,%rax,1),%eax
	shlq	$8,%rax
	orq	$1,%rax
	movw	%ax,-788(%rbp)
	leaq	-788(%rbp),%rcx
	leaq	-276(%rbp),%rdx
	movq	$255,%rsi
	leaq	-532(%rbp),%rdi
	call	fpc_shortstr_concat
	leaq	-532(%rbp),%rdi
	movl	-16(%rbp),%eax
	leal	1(%eax),%esi
	call	P$PROGRAM_$$_TRY$SHORTSTRING$LONGINT
	cmpl	$4,-20(%rbp)
	jge	.Lj25
	jmp	.Lj23
.Lj25:
	jmp	.Lj26
.Lj22:
	leaq	-276(%rbp),%rdi
	call	P$PROGRAM_$$_INTER$SHORTSTRING$$INT64
	movq	%rax,%rdi
	call	P$PROGRAM_$$_NTO$INT64$$BOOLEAN
	testb	%al,%al
	je	.Lj27
	jmp	.Lj28
.Lj27:
	jmp	.Lj19
.Lj28:
	movslq	U_$P$PROGRAM_$$_N,%rax
	leaq	1(%rax),%rax
	movslq	-16(%rbp),%rdx
	cmpq	%rdx,%rax
	je	.Lj29
	jmp	.Lj30
.Lj29:
	movl	U_$P$PROGRAM_$$_D,%eax
	leal	1(%eax),%eax
	movl	%eax,U_$P$PROGRAM_$$_D
	jmp	.Lj31
.Lj30:
	movl	$0,-20(%rbp)
	.balign 8,0x90
.Lj32:
	movl	-20(%rbp),%eax
	leal	1(%eax),%eax
	movl	%eax,-20(%rbp)
	movl	-20(%rbp),%eax
	movzbl	TC_$P$PROGRAM_$$_C-1(,%rax,1),%eax
	shlq	$8,%rax
	orq	$1,%rax
	movw	%ax,-788(%rbp)
	leaq	-788(%rbp),%rcx
	leaq	-276(%rbp),%rdx
	movq	$255,%rsi
	leaq	-532(%rbp),%rdi
	call	fpc_shortstr_concat
	leaq	-532(%rbp),%rdi
	movl	-16(%rbp),%eax
	leal	1(%eax),%esi
	call	P$PROGRAM_$$_TRY$SHORTSTRING$LONGINT
	cmpl	$4,-20(%rbp)
	jge	.Lj34
	jmp	.Lj32
.Lj34:
.Lj31:
.Lj26:
.Lj19:
	movq	-800(%rbp),%rbx
	movq	%rbp,%rsp
	popq	%rbp
	ret
.Lc12:
.Le2:
	.size	P$PROGRAM_$$_TRY$SHORTSTRING$LONGINT, .Le2 - P$PROGRAM_$$_TRY$SHORTSTRING$LONGINT

.section .text.n_main
	.balign 16,0x90
.globl	PASCALMAIN
	.type	PASCALMAIN,@function
PASCALMAIN:
.globl	main
	.type	main,@function
main:
.Lc16:
	pushq	%rbp
.Lc18:
.Lc19:
	movq	%rsp,%rbp
.Lc20:
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
	movl	%eax,U_$P$PROGRAM_$$_N
	movq	%rbx,%rdi
	call	fpc_readln_end
	call	fpc_iocheck
	movl	$0,U_$P$PROGRAM_$$_D
	movl	$1,%esi
	movq	$_$PROGRAM$_Ld1,%rdi
	call	P$PROGRAM_$$_TRY$SHORTSTRING$LONGINT
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
	call	fpc_get_output
	movq	%rax,%rbx
	movq	%rbx,%rdi
	call	fpc_writeln_end
	call	fpc_iocheck
	call	fpc_do_exit
	movq	-16(%rbp),%rbx
	movq	%rbp,%rsp
	popq	%rbp
	ret
.Lc17:
.Le3:
	.size	main, .Le3 - main

.section .text
# End asmlist al_procedures
# Begin asmlist al_globals

.section .bss
	.balign 4
	.type U_$P$PROGRAM_$$_N,@object
	.size U_$P$PROGRAM_$$_N,4
U_$P$PROGRAM_$$_N:
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
.Le4:
	.size	INITFINAL, .Le4 - INITFINAL

.section .data.n_FPC_THREADVARTABLES
	.balign 8
.globl	FPC_THREADVARTABLES
	.type	FPC_THREADVARTABLES,@object
FPC_THREADVARTABLES:
	.long	1
	.quad	THREADVARLIST_$SYSTEM$indirect
.Le5:
	.size	FPC_THREADVARTABLES, .Le5 - FPC_THREADVARTABLES

.section .data.n_FPC_RESOURCESTRINGTABLES
	.balign 8
.globl	FPC_RESOURCESTRINGTABLES
	.type	FPC_RESOURCESTRINGTABLES,@object
FPC_RESOURCESTRINGTABLES:
	.quad	0
.Le6:
	.size	FPC_RESOURCESTRINGTABLES, .Le6 - FPC_RESOURCESTRINGTABLES

.section .data.n_FPC_WIDEINITTABLES
	.balign 8
.globl	FPC_WIDEINITTABLES
	.type	FPC_WIDEINITTABLES,@object
FPC_WIDEINITTABLES:
	.quad	0
.Le7:
	.size	FPC_WIDEINITTABLES, .Le7 - FPC_WIDEINITTABLES

.section .data.n_FPC_RESSTRINITTABLES
	.balign 8
.globl	FPC_RESSTRINITTABLES
	.type	FPC_RESSTRINITTABLES,@object
FPC_RESSTRINITTABLES:
	.quad	0
.Le8:
	.size	FPC_RESSTRINITTABLES, .Le8 - FPC_RESSTRINITTABLES

.section .fpc.n_version
	.balign 16
	.type	__fpc_ident,@object
__fpc_ident:
	.ascii	"FPC 3.2.0 [2020/06/14] for x86_64 - Linux"
.Le9:
	.size	__fpc_ident, .Le9 - __fpc_ident

.section .data.n___stklen
	.balign 8
.globl	__stklen
	.type	__stklen,@object
__stklen:
	.quad	8388608
.Le10:
	.size	__stklen, .Le10 - __stklen

.section .data.n___heapsize
	.balign 8
.globl	__heapsize
	.type	__heapsize,@object
__heapsize:
	.quad	0
.Le11:
	.size	__heapsize, .Le11 - __heapsize

.section .data.n___fpc_valgrind
	.balign 8
.globl	__fpc_valgrind
	.type	__fpc_valgrind,@object
__fpc_valgrind:
	.byte	0
.Le12:
	.size	__fpc_valgrind, .Le12 - __fpc_valgrind

.section .data.n_FPC_RESLOCATION
	.balign 8
.globl	FPC_RESLOCATION
	.type	FPC_RESLOCATION,@object
FPC_RESLOCATION:
	.quad	0
.Le13:
	.size	FPC_RESLOCATION, .Le13 - FPC_RESLOCATION
# End asmlist al_globals
# Begin asmlist al_typedconsts

.section .data.n_TC_$P$PROGRAM_$$_C1
	.type	TC_$P$PROGRAM_$$_C1,@object
TC_$P$PROGRAM_$$_C1:
	.byte	50,51,53,55
.Le14:
	.size	TC_$P$PROGRAM_$$_C1, .Le14 - TC_$P$PROGRAM_$$_C1

.section .data.n_TC_$P$PROGRAM_$$_C
	.type	TC_$P$PROGRAM_$$_C,@object
TC_$P$PROGRAM_$$_C:
	.byte	49,51,55,57
.Le15:
	.size	TC_$P$PROGRAM_$$_C, .Le15 - TC_$P$PROGRAM_$$_C

.section .rodata.n__$PROGRAM$_Ld1
	.balign 8
.globl	_$PROGRAM$_Ld1
_$PROGRAM$_Ld1:
	.ascii	"\000\000"
.Le16:
	.size	_$PROGRAM$_Ld1, .Le16 - _$PROGRAM$_Ld1
# End asmlist al_typedconsts
# Begin asmlist al_dwarf_frame

.section .debug_frame
.Lc21:
	.long	.Lc23-.Lc22
.Lc22:
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
.Lc23:
	.long	.Lc25-.Lc24
.Lc24:
	.quad	.Lc21
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
.Lc25:
	.long	.Lc27-.Lc26
.Lc26:
	.quad	.Lc21
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
.Lc27:
	.long	.Lc29-.Lc28
.Lc28:
	.quad	.Lc21
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
.Lc29:
	.long	.Lc31-.Lc30
.Lc30:
	.quad	.Lc21
	.quad	.Lc16
	.quad	.Lc17-.Lc16
	.byte	4
	.long	.Lc18-.Lc16
	.byte	14
	.uleb128	16
	.byte	4
	.long	.Lc19-.Lc18
	.byte	5
	.uleb128	6
	.uleb128	4
	.byte	4
	.long	.Lc20-.Lc19
	.byte	13
	.uleb128	6
	.balign 4,0
.Lc31:
# End asmlist al_dwarf_frame
.section .note.GNU-stack,"",%progbits

