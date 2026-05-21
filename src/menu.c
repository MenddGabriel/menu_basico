#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "menu.h"
#include "interface.h"

static int flag_sair_global = 0;

int teclaPressionada() {
	int ch = _getch();
	if (ch == 0 || ch == 224)
		ch = _getch();
	return ch;
}

#define CONTAR_OPCOES(texto, func, flag) + 1
#define IMPRIMIR_OPCOES(texto, func, flag) printf("[ ] %s\n", texto);

#define EXECUTAR_OPCOES(texto, func, flag) \
	if (opcao == atual++) { \
		func(); \
		if (flag) flag_sair_global = 1; \
	}

#define RODAR_MENU_GENERICO(titulo, TABELA) \
	do { \
		int total_opcoes = 0 + TABELA(CONTAR_OPCOES); \
		limpaTela(); \
		printf(NEGRITO COR_VERDE"\n===== %s =====\n"RESET_COR, titulo); \
		TABELA(IMPRIMIR_OPCOES); \
		int opcao = selecionaOpcao(total_opcoes); \
		int atual = 1; \
		flag_sair_global = 0; \
		TABELA(EXECUTAR_OPCOES); \
	} while(0);



void menu() {
	while (1) {
		RODAR_MENU_GENERICO("ATIVIDADE FILA", MENU_PRINCIPAL_TABLE);
	}
}


int selecionaOpcao(int total_opcoes) {

	int tecla = 0;
	int select = 0;
	int selectAntigo = 0;
	int selectFinal = total_opcoes - 1;

	atualizaSeta(select, select);

	while (1) {

		posicionaCursorNaTela(0, 12);

		if (_kbhit())
		{
			tecla = teclaPressionada();
		}
		else
		{
			Sleep(10);
			continue;
		}

		if (tecla == ARROW_DOWN || tecla == ARROW_UP) {
			selectAntigo = select;

			if (tecla == ARROW_DOWN) {
				select = (select >= selectFinal) ? 0 : select + 1;
			}
			else {
				select = (select <= 0) ? selectFinal : select - 1;
			}

			atualizaSeta(selectAntigo, select);
		}

		if (tecla == KEY_ENTER) {
			return select + 1;
		}
	}
}

void atualizaSeta(int antigo, int novo) {

	int y_inicial = 2;
	int x_seta = 1;

	posicionaCursorNaTela(x_seta, y_inicial + antigo);
	printf(" ");

	posicionaCursorNaTela(x_seta, y_inicial + novo);
	printf(NEGRITO COR_AMARELA ">" RESET_COR);
}
void _teste() {
	printf("Funcao de teste!\n");
	pausar();
}
