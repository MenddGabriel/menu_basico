#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

void posicionaCursorNaTela(int x, int y) {
	printf("\033[%d;%dH", y + 1, x + 1);
}

void limpaTela() {
	printf(LIMPA_TELA);
}

void limparBuffer()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void pausar()
{
	printf("\nPressione qualquer tecla para continuar...");
	limparBuffer();
	getchar();
}

void sairPrograma()
{
	exit(0);
}
