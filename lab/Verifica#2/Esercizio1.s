	.file	"Esercizio1.c"
	.section	.rodata
.LC0:
	.string	"clear"
.LC1:
	.string	"\nMENU"
.LC2:
	.string	"1. Inserisci prenotazione"
.LC3:
	.string	"2. Elimina prenotazione"
	.align 8
.LC4:
	.string	"3. Stampa prenotazioni in attesa"
	.align 8
.LC5:
	.string	"4. Calcola importo medio per prenotazione"
.LC6:
	.string	"\n0. Esci dal programma"
.LC7:
	.string	"\nSelezione: "
.LC8:
	.string	"%d"
.LC9:
	.string	"Negozio chiuso!"
.LC10:
	.string	"Nessuna prenotazione!"
.LC11:
	.string	"\nSOTTOMENU: ELIMINAZIONE"
	.align 8
.LC12:
	.string	"1. Elimina prenotazione pi\303\271 vecchia"
	.align 8
.LC13:
	.string	"2. Elimina prenotazione per ID"
.LC14:
	.string	"\n0. Torna al menu principale"
	.align 8
.LC15:
	.string	"\nL'importo medio delle prenotazioni in attesa \303\250 \342\202\254%.2f\n"
	.align 8
.LC16:
	.string	"\nNessuna prenotazione in attesa"
.LC17:
	.string	"\nSelezione non valida"
	.align 8
.LC18:
	.string	"Premere ENTER per tornare al menu"
.LC19:
	.string	"read"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	$0, -4(%rbp)
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_inizializza
	leaq	.LC0(%rip), %rdi
	call	system@PLT
	leaq	.LC0(%rip), %rdi
	call	system@PLT
.L18:
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	leaq	.LC3(%rip), %rdi
	call	puts@PLT
	leaq	.LC4(%rip), %rdi
	call	puts@PLT
	leaq	.LC5(%rip), %rdi
	call	puts@PLT
	leaq	.LC6(%rip), %rdi
	call	puts@PLT
	leaq	.LC7(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC8(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-20(%rbp), %eax
	cmpl	$4, %eax
	ja	.L2
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L4(%rip), %rax
	movl	(%rdx,%rax), %eax
	movslq	%eax, %rdx
	leaq	.L4(%rip), %rax
	addq	%rdx, %rax
	jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L4:
	.long	.L3-.L4
	.long	.L5-.L4
	.long	.L6-.L4
	.long	.L7-.L4
	.long	.L8-.L4
	.text
.L3:
	leaq	.LC9(%rip), %rdi
	call	puts@PLT
	movl	$0, %eax
	jmp	.L19
.L5:
	addl	$1, -4(%rbp)
	movl	-4(%rbp), %edx
	leaq	-16(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_inserisci_dati
	jmp	.L10
.L6:
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_isEnd
	testl	%eax, %eax
	je	.L11
	leaq	.LC10(%rip), %rdi
	call	puts@PLT
	jmp	.L10
.L11:
	leaq	.LC0(%rip), %rdi
	call	system@PLT
	leaq	.LC11(%rip), %rdi
	call	puts@PLT
	leaq	.LC12(%rip), %rdi
	call	puts@PLT
	leaq	.LC13(%rip), %rdi
	call	puts@PLT
	leaq	.LC14(%rip), %rdi
	call	puts@PLT
	leaq	.LC7(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC8(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-20(%rbp), %eax
	cmpl	$1, %eax
	je	.L13
	cmpl	$2, %eax
	je	.L14
	jmp	.L15
.L13:
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_elimina_testa
	jmp	.L15
.L14:
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_elimina_posizione
	nop
.L15:
	jmp	.L10
.L7:
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_stampa_tutto
	jmp	.L10
.L8:
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_cont
	testl	%eax, %eax
	je	.L16
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_media
	movss	%xmm0, -36(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_cont
	pxor	%xmm0, %xmm0
	cvtsi2ss	%eax, %xmm0
	movss	-36(%rbp), %xmm1
	divss	%xmm0, %xmm1
	movaps	%xmm1, %xmm0
	cvtss2sd	%xmm0, %xmm0
	leaq	.LC15(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	jmp	.L10
.L16:
	leaq	.LC16(%rip), %rdi
	call	puts@PLT
	jmp	.L10
.L2:
	leaq	.LC17(%rip), %rdi
	call	puts@PLT
	nop
.L10:
	leaq	.LC18(%rip), %rdi
	call	puts@PLT
	leaq	.LC19(%rip), %rdi
	call	system@PLT
	leaq	.LC0(%rip), %rdi
	call	system@PLT
	jmp	.L18
.L19:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.globl	_inizializza
	.type	_inizializza, @function
_inizializza:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$0, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	_inizializza, .-_inizializza
	.globl	_isEnd
	.type	_isEnd, @function
_isEnd:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L22
	movl	$1, %eax
	jmp	.L23
.L22:
	movl	$0, %eax
.L23:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	_isEnd, .-_isEnd
	.section	.rodata
.LC20:
	.string	"Numero articoli: "
	.align 8
.LC21:
	.string	"Numero di articoli non valido [MAX %d]: "
.LC22:
	.string	"Totale: \342\202\254"
.LC23:
	.string	"%f"
.LC24:
	.string	"Importo non valido, riprova: "
	.text
	.globl	_inserisci_dati
	.type	_inserisci_dati, @function
_inserisci_dati:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movq	%rdi, -72(%rbp)
	movl	%esi, -76(%rbp)
	movl	$0, %edi
	call	time@PLT
	movq	%rax, -56(%rbp)
	leaq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	localtime@PLT
	movq	%rax, -8(%rbp)
	movl	-76(%rbp), %eax
	movl	%eax, -48(%rbp)
	movq	-8(%rbp), %rax
	movl	12(%rax), %eax
	movl	%eax, -44(%rbp)
	movq	-8(%rbp), %rax
	movl	16(%rax), %eax
	addl	$1, %eax
	movl	%eax, -40(%rbp)
	movq	-8(%rbp), %rax
	movl	20(%rax), %eax
	addl	$1900, %eax
	movl	%eax, -36(%rbp)
	movq	-8(%rbp), %rax
	movl	8(%rax), %eax
	movl	%eax, -32(%rbp)
	movq	-8(%rbp), %rax
	movl	4(%rax), %eax
	movl	%eax, -28(%rbp)
	leaq	.LC20(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-48(%rbp), %rax
	addq	$24, %rax
	movq	%rax, %rsi
	leaq	.LC8(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	jmp	.L25
.L26:
	movl	$10, %esi
	leaq	.LC21(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-48(%rbp), %rax
	addq	$24, %rax
	movq	%rax, %rsi
	leaq	.LC8(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
.L25:
	movl	-24(%rbp), %eax
	testl	%eax, %eax
	jle	.L26
	movl	-24(%rbp), %eax
	cmpl	$10, %eax
	jg	.L26
	leaq	.LC22(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-48(%rbp), %rax
	addq	$28, %rax
	movq	%rax, %rsi
	leaq	.LC23(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	jmp	.L27
.L28:
	leaq	.LC24(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-48(%rbp), %rax
	addq	$28, %rax
	movq	%rax, %rsi
	leaq	.LC23(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
.L27:
	movss	-20(%rbp), %xmm1
	pxor	%xmm0, %xmm0
	ucomiss	%xmm1, %xmm0
	jnb	.L28
	movq	-72(%rbp), %rax
	pushq	-24(%rbp)
	pushq	-32(%rbp)
	pushq	-40(%rbp)
	pushq	-48(%rbp)
	movq	%rax, %rdi
	call	_inserisci
	addq	$32, %rsp
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	_inserisci_dati, .-_inserisci_dati
	.globl	_inserisci
	.type	_inserisci, @function
_inserisci:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_isEnd
	testl	%eax, %eax
	je	.L30
	movl	$40, %edi
	call	malloc@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	16(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	24(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	32(%rbp), %rdx
	movq	%rdx, 16(%rax)
	movq	40(%rbp), %rdx
	movq	%rdx, 24(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 32(%rax)
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, (%rax)
	jmp	.L29
.L30:
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	addq	$32, %rax
	pushq	40(%rbp)
	pushq	32(%rbp)
	pushq	24(%rbp)
	pushq	16(%rbp)
	movq	%rax, %rdi
	call	_inserisci
	addq	$32, %rsp
.L29:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	_inserisci, .-_inserisci
	.section	.rodata
.LC26:
	.string	"PRENOTAZIONE RIMOSSA: "
	.text
	.globl	_elimina_testa
	.type	_elimina_testa, @function
_elimina_testa:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_isEnd
	testl	%eax, %eax
	je	.L33
	leaq	.LC10(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L32
.L33:
	leaq	.LC26(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_stampa
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	32(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
.L32:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	_elimina_testa, .-_elimina_testa
	.section	.rodata
	.align 8
.LC27:
	.string	"ID prenotazione da eliminare: "
.LC28:
	.string	"L'ID %d non esiste!\n"
	.text
	.globl	_elimina_posizione
	.type	_elimina_posizione, @function
_elimina_posizione:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	$0, -16(%rbp)
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	leaq	.LC27(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC8(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movq	-8(%rbp), %rax
	movl	(%rax), %edx
	movl	-20(%rbp), %eax
	cmpl	%eax, %edx
	jne	.L38
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_elimina_testa
	jmp	.L35
.L41:
	movq	-8(%rbp), %rax
	movl	(%rax), %edx
	movl	-20(%rbp), %eax
	cmpl	%eax, %edx
	je	.L44
	movq	-8(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	32(%rax), %rax
	movq	%rax, -8(%rbp)
.L38:
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_isEnd
	testl	%eax, %eax
	je	.L41
	jmp	.L40
.L44:
	nop
.L40:
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_isEnd
	testl	%eax, %eax
	je	.L42
	movl	-20(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC28(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L35
.L42:
	movq	-8(%rbp), %rax
	movq	32(%rax), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, 32(%rax)
	leaq	.LC26(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_stampa
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
.L35:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	_elimina_posizione, .-_elimina_posizione
	.section	.rodata
.LC29:
	.string	"Prenotazioni in attesa: %d\n"
	.text
	.globl	_stampa_tutto
	.type	_stampa_tutto, @function
_stampa_tutto:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	$0, -4(%rbp)
	movl	$10, %edi
	call	putchar@PLT
	jmp	.L46
.L47:
	addl	$1, -4(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_stampa
	movq	-24(%rbp), %rax
	movq	32(%rax), %rax
	movq	%rax, -24(%rbp)
.L46:
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_isEnd
	testl	%eax, %eax
	je	.L47
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC29(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	_stampa_tutto, .-_stampa_tutto
	.section	.rodata
	.align 8
.LC30:
	.string	"N.%d %d/%d/%d %d.%d: %d elementi, \342\202\254%.2f\n"
	.text
	.globl	_stampa
	.type	_stampa, @function
_stampa:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movss	28(%rax), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movq	-8(%rbp), %rax
	movl	24(%rax), %edi
	movq	-8(%rbp), %rax
	movl	20(%rax), %esi
	movq	-8(%rbp), %rax
	movl	16(%rax), %r9d
	movq	-8(%rbp), %rax
	movl	12(%rax), %r8d
	movq	-8(%rbp), %rax
	movl	8(%rax), %ecx
	movq	-8(%rbp), %rax
	movl	4(%rax), %edx
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	pushq	%rdi
	pushq	%rsi
	movl	%eax, %esi
	leaq	.LC30(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	addq	$16, %rsp
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	_stampa, .-_stampa
	.globl	_media
	.type	_media, @function
_media:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_isEnd
	testl	%eax, %eax
	je	.L50
	pxor	%xmm0, %xmm0
	jmp	.L51
.L50:
	movq	-8(%rbp), %rax
	movss	28(%rax), %xmm1
	movss	%xmm1, -12(%rbp)
	movq	-8(%rbp), %rax
	movq	32(%rax), %rax
	movq	%rax, %rdi
	call	_media
	addss	-12(%rbp), %xmm0
.L51:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	_media, .-_media
	.globl	_cont
	.type	_cont, @function
_cont:
.LFB12:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_isEnd
	testl	%eax, %eax
	je	.L53
	movl	$0, %eax
	jmp	.L54
.L53:
	movq	-8(%rbp), %rax
	movq	32(%rax), %rax
	movq	%rax, %rdi
	call	_cont
	addl	$1, %eax
.L54:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	_cont, .-_cont
	.ident	"GCC: (Debian 6.3.0-18) 6.3.0 20170516"
	.section	.note.GNU-stack,"",@progbits
