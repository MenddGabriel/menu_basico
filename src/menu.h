#ifndef MENU_H
#define MENU_H


#define MENU_PRINCIPAL_TABLE(X) \
    X("Teste",                  _teste,         0) \
    X("Sair",                   sairPrograma,   0)


// Prototipos das Funcoes do menu (X-Macro)
#define X(texto, func, flag) void func();
MENU_PRINCIPAL_TABLE(X)
#undef X

void atualizaSeta(int antigo, int novo);
int selecionaOpcao(int total_opcoes);
void menu();

#endif