#ifndef INTERFACE_H
#define INTERFACE_H

#define KEY_ENTER 13
#define ARROW_UP 72
#define ARROW_DOWN 80

#define LIMPA_TELA "\033[2J\033[H"

#define COR_PRETA     "\033[30m"
#define COR_VERMELHA  "\033[31m"
#define COR_VERDE     "\033[32m"
#define COR_AMARELA   "\033[33m"
#define COR_AZUL      "\033[34m"
#define COR_MAGENTA   "\033[35m"
#define COR_CIANO     "\033[36m"
#define COR_BRANCA    "\033[37m"

#define FUNDO_PRETA     "\033[40m"
#define FUNDO_VERMELHA  "\033[41m"
#define FUNDO_VERDE     "\033[42m"
#define FUNDO_AMARELA   "\033[43m"
#define FUNDO_AZUL      "\033[44m"
#define FUNDO_MAGENTA   "\033[45m"
#define FUNDO_CIANO     "\033[46m"
#define FUNDO_BRANCA    "\033[47m"

#define NEGRITO    "\033[1m"
#define SUBLINHADO "\033[4m"
#define REVERSO    "\033[7m"

#define RESET_COR  "\033[0m"

typedef void (*MenuFunc)();
typedef struct {
    const char* texto;
    MenuFunc func;
} MenuItem;

// Prototipos auxiliares
void posicionaCursorNaTela(int x, int y);
void limpaTela();
void limparBuffer();
void pausar();

#endif