/*
//1)

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista
typedef struct No {
    int valor;
    struct No* prox;
} No;

// Função para inserir no início da lista
void inserir_inicio(No** lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = *lista;
    *lista = novo;
}

// Função para inserir no fim da lista
void inserir_fim(No** lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        No* atual = *lista;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

// Função auxiliar para imprimir a lista (só pra visualizar se quiser)
void imprimir_lista(No* lista) {
    No* atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Exemplo de uso
int main() {
    No* lista = NULL;

    inserir_fim(&lista, 10);
    inserir_inicio(&lista, 5);
    inserir_fim(&lista, 20);
    inserir_inicio(&lista, 2);

    imprimir_lista(lista);

    return 0;
}

*/


//-------------------------------------------------------------


/*
//2)

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
typedef struct No {
    int valor;
    struct No* prox;
} No;

// Função para inserir no fim da lista
void inserir_fim(No** lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        No* atual = *lista;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

// Função para contar o número de nós
int contar_nos(No* lista) {
    int contador = 0;
    No* atual = lista;
    while (atual != NULL) {
        contador++;
        atual = atual->prox;
    }
    return contador;
}

int main() {
    No* lista = NULL;

    inserir_fim(&lista, 10);
    inserir_fim(&lista, 20);
    inserir_fim(&lista, 30);

    int total = contar_nos(lista);
    printf("Número de nós na lista: %d\n", total); // Saída: 3

    return 0;
}


*/


//-------------------------------------------------------------


/*
//3)

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
typedef struct No {
    int valor;
    struct No* prox;
} No;

// Função para inserir no fim da lista
void inserir_fim(No** lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        No* atual = *lista;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

// Função para buscar um elemento na lista
int buscar_elemento(No* lista, int valor) {
    No* atual = lista;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1; // Encontrado
        }
        atual = atual->prox;
    }
    return 0; // Não encontrado
}

int main() {
    No* lista = NULL;

    inserir_fim(&lista, 5);
    inserir_fim(&lista, 10);
    inserir_fim(&lista, 15);

    int valor_busca = 10;
    if (buscar_elemento(lista, valor_busca)) {
        printf("Valor %d encontrado na lista.\n", valor_busca);
    } else {
        printf("Valor %d não encontrado na lista.\n", valor_busca);
    }

    return 0;
}


*/



//-------------------------------------------------------------


/*
//4)

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
typedef struct No {
    int valor;
    struct No* prox;
} No;

// Função para inserir em uma posição específica (posição 0-indexada)
void inserir_posicao(No** lista, int valor, int posicao) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (posicao == 0) {
        novo->prox = *lista;
        *lista = novo;
        return;
    }

    No* atual = *lista;
    int i = 0;

    while (atual != NULL && i < posicao - 1) {
        atual = atual->prox;
        i++;
    }

    if (atual == NULL) {
        printf("Posição inválida!\n");
        free(novo);
        return;
    }

    novo->prox = atual->prox;
    atual->prox = novo;
}

// Função auxiliar para imprimir a lista
void imprimir_lista(No* lista) {
    No* atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int main() {
    No* lista = NULL;

    inserir_posicao(&lista, 10, 0); // Lista: 10
    inserir_posicao(&lista, 20, 1); // Lista: 10 -> 20
    inserir_posicao(&lista, 15, 1); // Lista: 10 -> 15 -> 20
    inserir_posicao(&lista, 5, 0);  // Lista: 5 -> 10 -> 15 -> 20

    imprimir_lista(lista);

    return 0;
}


*/



//-------------------------------------------------------------


/*
//5)

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
typedef struct No {
    int valor;
    struct No* prox;
} No;

// Função para inserir no fim da lista
void inserir_fim(No** lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        No* atual = *lista;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

// Função para remover a primeira ocorrência de um valor
void remover_valor(No** lista, int valor) {
    No* atual = *lista;
    No* anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == valor) {
            if (anterior == NULL) {
                *lista = atual->prox; // Removendo o primeiro nó
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("Valor %d removido.\n", valor);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("Valor %d não encontrado na lista.\n", valor);
}

// Função auxiliar para imprimir a lista
void imprimir_lista(No* lista) {
    No* atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int main() {
    No* lista = NULL;

    inserir_fim(&lista, 10);
    inserir_fim(&lista, 20);
    inserir_fim(&lista, 30);
    inserir_fim(&lista, 90);

    printf("Lista antes da remoção:\n");
    imprimir_lista(lista);

    remover_valor(&lista, 20);

    printf("Lista depois da remoção:\n");
    imprimir_lista(lista); 

    return 0;
}

*/




//-------------------------------------------------------------


/*
//6)

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
typedef struct No {
    int valor;
    struct No* prox;
} No;

void inserir_fim(No** lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        No* atual = *lista;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

void inverter_lista(No** lista) {
    No* anterior = NULL;
    No* atual = *lista;
    No* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }
    *lista = anterior;
}

void imprimir_lista(No* lista) {
    No* atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int main() {
    No* lista = NULL;

    inserir_fim(&lista, 1);
    inserir_fim(&lista, 2);
    inserir_fim(&lista, 3);
    inserir_fim(&lista, 4);

    printf("Lista original:\n");
    imprimir_lista(lista);

    inverter_lista(&lista);

    printf("Lista invertida:\n");
    imprimir_lista(lista);

    return 0;
}


*/



//-------------------------------------------------------------


/*
//7)

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
typedef struct No {
    int valor;
    struct No* prox;
} No;

void inserir_fim(No** lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        No* atual = *lista;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}


No* encontrar_meio(No* lista) {
    if (lista == NULL) return NULL;

    No* lento = lista;
    No* rapido = lista;

    while (rapido != NULL && rapido->prox != NULL) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }

    return lento;
}

void imprimir_lista(No* lista) {
    No* atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int main() {
    No* lista = NULL;

    inserir_fim(&lista, 10);
    inserir_fim(&lista, 20);
    inserir_fim(&lista, 30);
    inserir_fim(&lista, 40);
    inserir_fim(&lista, 50);

    printf("Lista:\n");
    imprimir_lista(lista);

    No* meio = encontrar_meio(lista);
    if (meio != NULL) {
        printf("Nó do meio: %d\n", meio->valor);
    } else {
        printf("Lista vazia.\n");
    }

    return 0;
}


*/



//-------------------------------------------------------------


/*
//8)

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct PilhaNo {
    int valor;
    struct PilhaNo* prox;
} PilhaNo;

void inserir_fim(No** lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        No* atual = *lista;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

void push(PilhaNo** topo, int valor) {
    PilhaNo* novo = (PilhaNo*)malloc(sizeof(PilhaNo));
    novo->valor = valor;
    novo->prox = *topo;
    *topo = novo;
}

int pop(PilhaNo** topo) {
    if (*topo == NULL) {
        printf("Pilha vazia!\n");
        return -1; 
    }
    PilhaNo* temp = *topo;
    int valor = temp->valor;
    *topo = temp->prox;
    free(temp);
    return valor;
}

void imprimir_lista(No* lista) {
    No* atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

void imprimir_reverso_com_pilha(No* lista) {
    PilhaNo* pilha = NULL;

    No* atual = lista;
    while (atual != NULL) {
        push(&pilha, atual->valor);
        atual = atual->prox;
    }

    printf("Lista em ordem reversa:\n");
    while (pilha != NULL) {
        int v = pop(&pilha);
        printf("%d -> ", v);
    }
    printf("NULL\n");
}

int main() {
    No* lista = NULL;

    inserir_fim(&lista, 1);
    inserir_fim(&lista, 2);
    inserir_fim(&lista, 3);
    inserir_fim(&lista, 4);

    printf("Lista normal:\n");
    imprimir_lista(lista);

    imprimir_reverso_com_pilha(lista);

    return 0;
}
*/




//-------------------------------------------------------------


/*
//9)

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;  // Índice do topo da pilha (-1 quando vazia)
} Pilha;

void inicializar(Pilha* p) {
    p->topo = -1;
}

int esta_vazia(Pilha* p) {
    return (p->topo == -1);
}

int push(Pilha* p, int valor) {
    if (p->topo == MAX - 1) {
        printf("Erro: pilha cheia!\n");
        return 0; // Falha ao inserir
    }
    p->topo++;
    p->dados[p->topo] = valor;
    return 1; // Sucesso
}

int pop(Pilha* p, int* valor) {
    if (esta_vazia(p)) {
        printf("Erro: pilha vazia!\n");
        return 0; // Falha ao remover
    }
    *valor = p->dados[p->topo];
    p->topo--;
    return 1; // Sucesso
}

int topo(Pilha* p, int* valor) {
    if (esta_vazia(p)) {
        printf("Erro: pilha vazia!\n");
        return 0; // Falha
    }
    *valor = p->dados[p->topo];
    return 1; // Sucesso
}

int main() {
    Pilha pilha;
    int valor;

    inicializar(&pilha);

    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 30);

    if (topo(&pilha, &valor)) {
        printf("Topo da pilha: %d\n", valor);
    }

    while (!esta_vazia(&pilha)) {
        if (pop(&pilha, &valor)) {
            printf("Pop: %d\n", valor);
        }
    }

    pop(&pilha, &valor);

    return 0;
}

*/



//-------------------------------------------------------------


/*
//10)

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

int esta_vazia(No* topo) {
    return (topo == NULL);
}

void push(No** topo, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: falha na alocação de memória\n");
        return;
    }
    novo->valor = valor;
    novo->prox = *topo;
    *topo = novo;
}

int pop(No** topo, int* valor) {
    if (esta_vazia(*topo)) {
        printf("Erro: pilha vazia\n");
        return 0; // Falha
    }
    No* temp = *topo;
    *valor = temp->valor;
    *topo = temp->prox;
    free(temp);
    return 1; // Sucesso
}

int topo(No* topo_pilha, int* valor) {
    if (esta_vazia(topo_pilha)) {
        printf("Erro: pilha vazia\n");
        return 0; // Falha
    }
    *valor = topo_pilha->valor;
    return 1; // Sucesso
}

int main() {
    No* pilha = NULL;
    int valor;

    push(&pilha, 100);
    push(&pilha, 200);
    push(&pilha, 300);

    if (topo(pilha, &valor)) {
        printf("Topo da pilha: %d\n", valor);
    }

    while (!esta_vazia(pilha)) {
        if (pop(&pilha, &valor)) {
            printf("Pop: %d\n", valor);
        }
    }

    pop(&pilha, &valor);

    return 0;
}


*/




//-------------------------------------------------------------


/*
//11)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = -1;
}

int esta_vazia(Pilha* p) {
    return (p->topo == -1);
}

int push(Pilha* p, char c) {
    if (p->topo == MAX - 1) {
        return 0; // pilha cheia
    }
    p->dados[++(p->topo)] = c;
    return 1;
}

int pop(Pilha* p, char* c) {
    if (esta_vazia(p)) {
        return 0; // pilha vazia
    }
    *c = p->dados[(p->topo)--];
    return 1;
}

int verificar_balanceamento(const char* expr) {
    Pilha pilha;
    inicializar(&pilha);

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[') {
            push(&pilha, c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (esta_vazia(&pilha)) {
                return 0; // fecha sem abrir
            }
            char topo;
            pop(&pilha, &topo);
            // Verifica correspondência
            if ((c == ')' && topo != '(') ||
                (c == '}' && topo != '{') ||
                (c == ']' && topo != '[')) {
                return 0; // não corresponde
            }
        }
        
    }

    return esta_vazia(&pilha);
}

int main() {
    char expr1[] = "({[]})";
    char expr2[] = "({[})";

    printf("Expressao \"%s\" %s\n", expr1, verificar_balanceamento(expr1) ? "balanceada" : "nao balanceada");
    printf("Expressao \"%s\" %s\n", expr2, verificar_balanceamento(expr2) ? "balanceada" : "nao balanceada");

    return 0;
}


*/


//-------------------------------------------------------------

/*
//12)

#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = -1;
}

int esta_vazia(Pilha* p) {
    return (p->topo == -1);
}

int push(Pilha* p, char c) {
    if (p->topo == MAX - 1) {
        return 0; // pilha cheia
    }
    p->dados[++(p->topo)] = c;
    return 1;
}

int pop(Pilha* p, char* c) {
    if (esta_vazia(p)) {
        return 0; // pilha vazia
    }
    *c = p->dados[(p->topo)--];
    return 1;
}

void inverter_string(const char* original, char* invertida) {
    Pilha pilha;
    inicializar(&pilha);

    int len = strlen(original);

    // Empilha todos os caracteres
    for (int i = 0; i < len; i++) {
        push(&pilha, original[i]);
    }

    // Desempilha para inverter
    int i = 0;
    char c;
    while (pop(&pilha, &c)) {
        invertida[i++] = c;
    }
    invertida[i] = '\0'; // termina string
}

int main() {
    char s[] = "hello";
    char inv[MAX];

    inverter_string(s, inv);

    printf("Original: %s\n", s);
    printf("Invertida: %s\n", inv);

    return 0;
}


*/


//-------------------------------------------------------------


/*
//13)

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = -1;
}

int esta_vazia(Pilha* p) {
    return (p->topo == -1);
}

int push(Pilha* p, char c) {
    if (p->topo == MAX - 1) {
        return 0; // pilha cheia
    }
    p->dados[++(p->topo)] = c;
    return 1;
}

int pop(Pilha* p, char* c) {
    if (esta_vazia(p)) {
        return 0; // pilha vazia
    }
    *c = p->dados[(p->topo)--];
    return 1;
}

int eh_palindromo(const char* s) {
    Pilha pilha;
    inicializar(&pilha);

    int len = strlen(s);

    // Empilha todos os caracteres (ignorando espaços e considerando minúsculas)
    for (int i = 0; i < len; i++) {
        if (isalpha(s[i])) {
            push(&pilha, tolower(s[i]));
        }
    }

    // Compara desempilhando com a string original (ignorando espaços e case)
    for (int i = 0; i < len; i++) {
        if (isalpha(s[i])) {
            char c;
            pop(&pilha, &c);
            if (tolower(s[i]) != c) {
                return 0; // não é palíndromo
            }
        }
    }
    return 1; // é palíndromo
}

int main() {
    char str1[] = "Radar";
    char str2[] = "Hello";

    printf("\"%s\" %s palindromo\n", str1, eh_palindromo(str1) ? "e" : "nao e");
    printf("\"%s\" %s palindromo\n", str2, eh_palindromo(str2) ? "e" : "nao e");

    return 0;
}


*/


//-------------------------------------------------------------


/*
//14)

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

No* novo_no(int valor) {
    No* n = (No*) malloc(sizeof(No));
    if (!n) {
        printf("Erro de memória\n");
        exit(1);
    }
    n->valor = valor;
    n->prox = NULL;
    return n;
}

int esta_vazia(No* topo) {
    return (topo == NULL);
}

void push(No** topo, int valor) {
    No* n = novo_no(valor);
    n->prox = *topo;
    *topo = n;
}

int pop(No** topo, int* valor) {
    if (esta_vazia(*topo)) return 0;
    No* temp = *topo;
    *valor = temp->valor;
    *topo = temp->prox;
    free(temp);
    return 1;
}

int topo(No* topo_pilha, int* valor) {
    if (esta_vazia(topo_pilha)) return 0;
    *valor = topo_pilha->valor;
    return 1;
}

void imprimir_pilha(No* topo) {
    printf("Pilha: ");
    No* temp = topo;
    while(temp) {
        printf("%d ", temp->valor);
        temp = temp->prox;
    }
    printf("\n");
}

void ordenar_pilha(No** pilha) {
    No* aux = NULL; // pilha auxiliar
    int temp;

    while (pop(pilha, &temp)) {
        int aux_topo;
        while (!esta_vazia(aux) && topo(aux, &aux_topo) && aux_topo > temp) {
            int val;
            pop(&aux, &val);
            push(pilha, val);
        }
        push(&aux, temp);
    }

    while (pop(&aux, &temp)) {
        push(pilha, temp);
    }
}

int main() {
    No* pilha = NULL;

    push(&pilha, 30);
    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 40);
    push(&pilha, 5);

    printf("Antes da ordenacao:\n");
    imprimir_pilha(pilha);

    ordenar_pilha(&pilha);

    printf("Depois da ordenacao:\n");
    imprimir_pilha(pilha);

    return 0;
}

*/



//-------------------------------------------------------------


/*
//15)

#include <stdio.h>
#define MAX 100

typedef struct {
    int fila[MAX];
    int inicio;
    int fim;
    int tamanho;
} Fila;

void inicializar(Fila* f) {
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}

int esta_vazia(Fila* f) {
    return (f->tamanho == 0);
}

int esta_cheia(Fila* f) {
    return (f->tamanho == MAX);
}

int enfileirar(Fila* f, int valor) {
    if (esta_cheia(f)) {
        printf("Fila cheia!\n");
        return 0;
    }
    f->fim = (f->fim + 1) % MAX;
    f->fila[f->fim] = valor;
    f->tamanho++;
    return 1;
}

int desenfileirar(Fila* f, int* valor) {
    if (esta_vazia(f)) {
        printf("Fila vazia!\n");
        return 0;
    }
    *valor = f->fila[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return 1;
}

int frente(Fila* f, int* valor) {
    if (esta_vazia(f)) {
        printf("Fila vazia!\n");
        return 0;
    }
    *valor = f->fila[f->inicio];
    return 1;
}

int main() {
    Fila f;
    inicializar(&f);

    enfileirar(&f, 10);
    enfileirar(&f, 20);
    enfileirar(&f, 30);

    int val;

    if (frente(&f, &val))
        printf("Elemento da frente: %d\n", val);

    desenfileirar(&f, &val);
    printf("Elemento removido: %d\n", val);

    if (frente(&f, &val))
        printf("Elemento da frente agora: %d\n", val);

    return 0;
}


*/


//-------------------------------------------------------------


/*
//16)

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Fila;

void inicializar(Fila* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

int esta_vazia(Fila* f) {
    return (f->inicio == NULL);
}

void enfileirar(Fila* f, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    if (!novo) {
        printf("Erro de memória!\n");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = NULL;

    if (esta_vazia(f)) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int desenfileirar(Fila* f, int* valor) {
    if (esta_vazia(f)) {
        return 0;
    }
    No* temp = f->inicio;
    *valor = temp->valor;
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL) { // fila ficou vazia
        f->fim = NULL;
    }
    free(temp);
    return 1;
}

int frente(Fila* f, int* valor) {
    if (esta_vazia(f)) {
        return 0;
    }
    *valor = f->inicio->valor;
    return 1;
}

int main() {
    Fila f;
    inicializar(&f);

    enfileirar(&f, 100);
    enfileirar(&f, 200);
    enfileirar(&f, 300);

    int val;

    if (frente(&f, &val))
        printf("Elemento da frente: %d\n", val);

    if (desenfileirar(&f, &val))
        printf("Elemento removido: %d\n", val);

    if (frente(&f, &val))
        printf("Elemento da frente agora: %d\n", val);

    return 0;
}


*/


//-------------------------------------------------------------


/*
//17)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char bin[100];
    struct No* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Fila;

void inicializar(Fila* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

int esta_vazia(Fila* f) {
    return (f->inicio == NULL);
}

void enfileirar(Fila* f, const char* str) {
    No* novo = (No*) malloc(sizeof(No));
    strcpy(novo->bin, str);
    novo->prox = NULL;

    if (esta_vazia(f)) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int desenfileirar(Fila* f, char* str_out) {
    if (esta_vazia(f))
        return 0;

    No* temp = f->inicio;
    strcpy(str_out, temp->bin);
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL)
        f->fim = NULL;
    free(temp);
    return 1;
}

void gerar_binarios(int N) {
    Fila f;
    inicializar(&f);

    enfileirar(&f, "1");

    for (int i = 0; i < N; i++) {
        char atual[100];
        desenfileirar(&f, atual);

        printf("%s\n", atual);

        char bin0[100], bin1[100];
        sprintf(bin0, "%s0", atual);
        sprintf(bin1, "%s1", atual);

        enfileirar(&f, bin0);
        enfileirar(&f, bin1);
    }
}

int main() {
    int N = 10;
    printf("Primeiros %d números binários:\n", N);
    gerar_binarios(N);
    return 0;
}


*/


//-------------------------------------------------------------


/*
//18)

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// ---------- Fila com Array ----------
typedef struct {
    int dados[MAX];
    int inicio, fim, tamanho;
} Fila;

void inicializar_fila(Fila* f) {
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}

int fila_vazia(Fila* f) {
    return f->tamanho == 0;
}

int fila_cheia(Fila* f) {
    return f->tamanho == MAX;
}

void enfileirar(Fila* f, int valor) {
    if (fila_cheia(f)) {
        printf("Fila cheia!\n");
        return;
    }
    f->fim = (f->fim + 1) % MAX;
    f->dados[f->fim] = valor;
    f->tamanho++;
}

int desenfileirar(Fila* f, int* valor) {
    if (fila_vazia(f))
        return 0;
    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return 1;
}

void imprimir_fila(Fila* f) {
    int i, count = f->tamanho;
    int idx = f->inicio;
    while (count--) {
        printf("%d ", f->dados[idx]);
        idx = (idx + 1) % MAX;
    }
    printf("\n");
}

// ---------- Pilha com Array ----------
typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void inicializar_pilha(Pilha* p) {
    p->topo = -1;
}

int pilha_vazia(Pilha* p) {
    return p->topo == -1;
}

int pilha_cheia(Pilha* p) {
    return p->topo == MAX - 1;
}

void push(Pilha* p, int valor) {
    if (pilha_cheia(p)) {
        printf("Pilha cheia!\n");
        return;
    }
    p->dados[++p->topo] = valor;
}

int pop(Pilha* p, int* valor) {
    if (pilha_vazia(p))
        return 0;
    *valor = p->dados[p->topo--];
    return 1;
}

// ---------- Inversão dos primeiros K elementos ----------
void inverter_primeiros_k(Fila* f, int k) {
    if (k <= 0 || k > f->tamanho) {
        printf("Valor de K inválido!\n");
        return;
    }

    Pilha p;
    inicializar_pilha(&p);

    for (int i = 0; i < k; i++) {
        int val;
        desenfileirar(f, &val);
        push(&p, val);
    }

    while (!pilha_vazia(&p)) {
        int val;
        pop(&p, &val);
        enfileirar(f, val);
    }

    int resto = f->tamanho - k;
    for (int i = 0; i < resto; i++) {
        int val;
        desenfileirar(f, &val);
        enfileirar(f, val);
    }
}

// ---------- Main com exemplo ----------
int main() {
    Fila f;
    inicializar_fila(&f);

    enfileirar(&f, 1);
    enfileirar(&f, 2);
    enfileirar(&f, 3);
    enfileirar(&f, 4);
    enfileirar(&f, 5);

    printf("Fila original: ");
    imprimir_fila(&f);

    inverter_primeiros_k(&f, 3);

    printf("Fila após inverter os 3 primeiros: ");
    imprimir_fila(&f);

    return 0;
}


*/


//-------------------------------------------------------------


/*
//19)

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

No* criar_no(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;
    return novo;
}

void inserir_fim(No** lista, int valor) {
    No* novo = criar_no(valor);
    if (*lista == NULL) {
        *lista = novo;
        return;
    }
    No* temp = *lista;
    while (temp->prox != NULL)
        temp = temp->prox;
    temp->prox = novo;
}

int detectar_ciclo(No* lista) {
    No* lento = lista;
    No* rapido = lista;

    while (rapido != NULL && rapido->prox != NULL) {
        lento = lento->prox;
        rapido = rapido->prox->prox;

        if (lento == rapido)
            return 1; // Ciclo detectado
    }
    return 0; // Não há ciclo
}

void liberar_lista(No* lista) {
    while (lista != NULL) {
        No* temp = lista;
        lista = lista->prox;
        free(temp);
    }
}

// ---------- Exemplo de uso ----------
int main() {
    No* lista = NULL;

    inserir_fim(&lista, 1);
    inserir_fim(&lista, 2);
    inserir_fim(&lista, 3);
    inserir_fim(&lista, 4);
    inserir_fim(&lista, 5);

    No* temp = lista;
    No* segundo = lista->prox;
    while (temp->prox != NULL)
        temp = temp->prox;
    temp->prox = segundo; // Criando ciclo

    if (detectar_ciclo(lista))
        printf("Ciclo detectado na lista.\n");
    else
        printf("Nenhum ciclo na lista.\n");

    return 0;
}


*/


//-------------------------------------------------------------


/*
//20)

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

No* criar_no(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;
    return novo;
}

void inserir_fim(No** lista, int valor) {
    No* novo = criar_no(valor);
    if (*lista == NULL) {
        *lista = novo;
        return;
    }
    No* temp = *lista;
    while (temp->prox != NULL)
        temp = temp->prox;
    temp->prox = novo;
}

void imprimir_lista(No* lista) {
    while (lista != NULL) {
        printf("%d ", lista->dado);
        lista = lista->prox;
    }
    printf("\n");
}

No* unir_listas_ordenadas(No* l1, No* l2) {
    No* resultado = NULL;
    No** ult_ptr = &resultado;

    while (l1 != NULL && l2 != NULL) {
        if (l1->dado <= l2->dado) {
            *ult_ptr = criar_no(l1->dado);
            l1 = l1->prox;
        } else {
            *ult_ptr = criar_no(l2->dado);
            l2 = l2->prox;
        }
        ult_ptr = &((*ult_ptr)->prox);
    }

    while (l1 != NULL) {
        *ult_ptr = criar_no(l1->dado);
        l1 = l1->prox;
        ult_ptr = &((*ult_ptr)->prox);
    }

    while (l2 != NULL) {
        *ult_ptr = criar_no(l2->dado);
        l2 = l2->prox;
        ult_ptr = &((*ult_ptr)->prox);
    }

    return resultado;
}

void liberar_lista(No* lista) {
    while (lista != NULL) {
        No* temp = lista;
        lista = lista->prox;
        free(temp);
    }
}

// ----------- Exemplo de uso ------------
int main() {
    No* lista1 = NULL;
    No* lista2 = NULL;

    inserir_fim(&lista1, 1);
    inserir_fim(&lista1, 3);
    inserir_fim(&lista1, 5);

    inserir_fim(&lista2, 2);
    inserir_fim(&lista2, 4);
    inserir_fim(&lista2, 6);

    printf("Lista 1: ");
    imprimir_lista(lista1);
    printf("Lista 2: ");
    imprimir_lista(lista2);

    No* unida = unir_listas_ordenadas(lista1, lista2);

    printf("Lista unida e ordenada: ");
    imprimir_lista(unida);

    liberar_lista(lista1);
    liberar_lista(lista2);
    liberar_lista(unida);

    return 0;
}


*/


//-------------------------------------------------------------


/*
//21)

#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da lista
typedef struct No {
    int dado;
    struct No* prox;
} No;

// Cria um novo nó
No* criar_no(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;
    return novo;
}

// Insere no final da lista
void inserir_fim(No** lista, int valor) {
    No* novo = criar_no(valor);
    if (*lista == NULL) {
        *lista = novo;
        return;
    }
    No* temp = *lista;
    while (temp->prox != NULL)
        temp = temp->prox;
    temp->prox = novo;
}

// Imprime a lista
void imprimir_lista(No* lista) {
    while (lista != NULL) {
        printf("%d ", lista->dado);
        lista = lista->prox;
    }
    printf("\n");
}

// Remove todas as ocorrências de um valor
void remover_todas_ocorrencias(No** lista, int valor) {
    No* atual = *lista;
    No* anterior = NULL;

    while (atual != NULL) {
        if (atual->dado == valor) {
            No* temp = atual;
            if (anterior == NULL) {  // Remoção no início
                *lista = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            atual = atual->prox;
            free(temp);
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
}

// Libera a memória da lista
void liberar_lista(No* lista) {
    while (lista != NULL) {
        No* temp = lista;
        lista = lista->prox;
        free(temp);
    }
}

// ----------- Exemplo de uso ------------
int main() {
    No* lista = NULL;

    inserir_fim(&lista, 1);
    inserir_fim(&lista, 2);
    inserir_fim(&lista, 3);
    inserir_fim(&lista, 2);
    inserir_fim(&lista, 4);
    inserir_fim(&lista, 2);

    printf("Lista original: ");
    imprimir_lista(lista);

    remover_todas_ocorrencias(&lista, 2);

    printf("Lista após remover todas as ocorrências de 2: ");
    imprimir_lista(lista);

    liberar_lista(lista);
    return 0;
}


*/


//-------------------------------------------------------------


/*
//22)

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista
typedef struct No {
    int dado;
    struct No* prox;
} No;

// Cria um novo nó
No* criar_no(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;
    return novo;
}

int comprimento(No* lista) {
    int cont = 0;
    while (lista != NULL) {
        cont++;
        lista = lista->prox;
    }
    return cont;
}

No* encontrar_intersecao(No* lista1, No* lista2) {
    int len1 = comprimento(lista1);
    int len2 = comprimento(lista2);

    // Alinha os ponteiros
    int diff = len1 - len2;
    if (diff < 0) {
        while (diff++) lista2 = lista2->prox;
    } else {
        while (diff--) lista1 = lista1->prox;
    }

    while (lista1 != NULL && lista2 != NULL) {
        if (lista1 == lista2) {
            return lista1; // Intersecção encontrada
        }
        lista1 = lista1->prox;
        lista2 = lista2->prox;
    }

    return NULL; // Sem intersecção
}

// ----------- Exemplo de uso ------------
int main() {
   

    No* comum = criar_no(6);
    comum->prox = criar_no(7);

    No* lista1 = criar_no(1);
    lista1->prox = criar_no(2);
    lista1->prox->prox = criar_no(3);
    lista1->prox->prox->prox = comum;

    No* lista2 = criar_no(4);
    lista2->prox = criar_no(5);
    lista2->prox->prox = comum;

    No* intersecao = encontrar_intersecao(lista1, lista2);

    if (intersecao != NULL) {
        printf("Intersecao encontrada no valor: %d\n", intersecao->dado);
    } else {
        printf("Nenhuma intersecao encontrada.\n");
    }

    // Liberar memória
    free(lista1->prox->prox); // 3
    free(lista1->prox);       // 2
    free(lista1);             // 1
    free(lista2->prox);       // 5
    free(lista2);             // 4
    free(comum->prox);        // 7
    free(comum);              // 6

    return 0;
}


*/


//-------------------------------------------------------------


/*
//23)

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

No* criar_no(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;
    return novo;
}

void inserir_fim(No** lista, int valor) {
    No* novo = criar_no(valor);
    if (*lista == NULL) {
        *lista = novo;
    } else {
        No* temp = *lista;
        while (temp->prox != NULL)
            temp = temp->prox;
        temp->prox = novo;
    }
}

void imprimir_lista(No* lista) {
    while (lista != NULL) {
        printf("%d ", lista->dado);
        lista = lista->prox;
    }
    printf("\n");
}

int tamanho_lista(No* lista) {
    int cont = 0;
    while (lista != NULL) {
        cont++;
        lista = lista->prox;
    }
    return cont;
}

void rotacionar_lista(No** lista, int k) {
    if (*lista == NULL || k == 0) return;

    int tamanho = tamanho_lista(*lista);
    k = k % tamanho;
    if (k == 0) return;

    No* atual = *lista;
    for (int i = 1; i < tamanho - k; i++) {
        atual = atual->prox;
    }

    No* nova_cabeca = atual->prox;
    atual->prox = NULL;

    No* temp = nova_cabeca;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }

    temp->prox = *lista;
    *lista = nova_cabeca;
}

// ----------- Exemplo de uso ------------
int main() {
    No* lista = NULL;

    inserir_fim(&lista, 1);
    inserir_fim(&lista, 2);
    inserir_fim(&lista, 3);
    inserir_fim(&lista, 4);
    inserir_fim(&lista, 5);

    printf("Lista original: ");
    imprimir_lista(lista);

    int k = 2;
    rotacionar_lista(&lista, k);

    printf("Lista rotacionada por %d: ", k);
    imprimir_lista(lista);

    while (lista != NULL) {
        No* temp = lista;
        lista = lista->prox;
        free(temp);
    }

    return 0;
}


*/


//-------------------------------------------------------------


/*
//24)

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = -1;
}

int esta_vazia(Pilha* p) {
    return p->topo == -1;
}

int esta_cheia(Pilha* p) {
    return p->topo == MAX - 1;
}

void push(Pilha* p, int valor) {
    if (esta_cheia(p)) {
        printf("Erro: Pilha cheia\n");
        return;
    }
    p->dados[++(p->topo)] = valor;
}

int pop(Pilha* p) {
    if (esta_vazia(p)) {
        printf("Erro: Pilha vazia\n");
        return INT_MIN;
    }
    return p->dados[(p->topo)--];
}

int topo(Pilha* p) {
    if (esta_vazia(p)) {
        printf("Erro: Pilha vazia\n");
        return INT_MIN;
    }
    return p->dados[p->topo];
}

// ------------ PILHA COM MÍNIMO ------------

typedef struct {
    Pilha dados;
    Pilha minimos;
} PilhaComMinimo;

void inicializar_pilha_min(PilhaComMinimo* p) {
    inicializar(&p->dados);
    inicializar(&p->minimos);
}

void push_min(PilhaComMinimo* p, int valor) {
    push(&p->dados, valor);
    if (esta_vazia(&p->minimos) || valor <= topo(&p->minimos)) {
        push(&p->minimos, valor);
    }
}

void pop_min(PilhaComMinimo* p) {
    int valor_removido = pop(&p->dados);
    if (valor_removido == topo(&p->minimos)) {
        pop(&p->minimos);
    }
}

int obter_minimo(PilhaComMinimo* p) {
    return topo(&p->minimos);
}

int topo_min(PilhaComMinimo* p) {
    return topo(&p->dados);
}

// ------------- Exemplo de uso -------------

int main() {
    PilhaComMinimo pilha;
    inicializar_pilha_min(&pilha);

    push_min(&pilha, 5);
    push_min(&pilha, 3);
    push_min(&pilha, 7);
    push_min(&pilha, 2);

    printf("Topo: %d\n", topo_min(&pilha));
    printf("Mínimo: %d\n", obter_minimo(&pilha));

    pop_min(&pilha);
    printf("Após pop:\n");
    printf("Topo: %d\n", topo_min(&pilha));
    printf("Mínimo: %d\n", obter_minimo(&pilha));

    return 0;
}


*/


//-------------------------------------------------------------


/*
//25)

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo1;  // Topo da Pilha 1
    int topo2;  // Topo da Pilha 2
} DuasPilhas;

void inicializar(DuasPilhas* p) {
    p->topo1 = -1;
    p->topo2 = MAX;
}

void push1(DuasPilhas* p, int valor) {
    if (p->topo1 + 1 == p->topo2) {
        printf("Erro: espaço insuficiente\n");
        return;
    }
    p->dados[++(p->topo1)] = valor;
}

void push2(DuasPilhas* p, int valor) {
    if (p->topo2 - 1 == p->topo1) {
        printf("Erro: espaço insuficiente\n");
        return;
    }
    p->dados[--(p->topo2)] = valor;
}

int pop1(DuasPilhas* p) {
    if (p->topo1 == -1) {
        printf("Erro: Pilha 1 vazia\n");
        return INT_MIN;
    }
    return p->dados[(p->topo1)--];
}

int pop2(DuasPilhas* p) {
    if (p->topo2 == MAX) {
        printf("Erro: Pilha 2 vazia\n");
        return INT_MIN;
    }
    return p->dados[(p->topo2)++];
}

int topo1(DuasPilhas* p) {
    if (p->topo1 == -1) return INT_MIN;
    return p->dados[p->topo1];
}

int topo2(DuasPilhas* p) {
    if (p->topo2 == MAX) return INT_MIN;
    return p->dados[p->topo2];
}

// ------------- Exemplo de uso -------------

int main() {
    DuasPilhas pilhas;
    inicializar(&pilhas);

    push1(&pilhas, 10);
    push1(&pilhas, 20);
    push2(&pilhas, 100);
    push2(&pilhas, 200);

    printf("Topo da Pilha 1: %d\n", topo1(&pilhas));
    printf("Topo da Pilha 2: %d\n", topo2(&pilhas));

    printf("Pop Pilha 1: %d\n", pop1(&pilhas));
    printf("Pop Pilha 2: %d\n", pop2(&pilhas));

    return 0;
}


*/


//-------------------------------------------------------------


/*
//26)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = -1;
}

int esta_vazia(Pilha* p) {
    return p->topo == -1;
}

void push(Pilha* p, int valor) {
    if (p->topo < MAX - 1) {
        p->dados[++(p->topo)] = valor;
    } else {
        printf("Erro: Pilha cheia\n");
    }
}

int pop(Pilha* p) {
    if (!esta_vazia(p)) {
        return p->dados[(p->topo)--];
    } else {
        printf("Erro: Pilha vazia\n");
        return 0;
    }
}

int avaliar_posfixa(const char* expressao) {
    Pilha pilha;
    inicializar(&pilha);

    char copia[strlen(expressao) + 1];
    strcpy(copia, expressao);

    char* token = strtok(copia, " ");
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&pilha, atoi(token));
        } else {
            int b = pop(&pilha);
            int a = pop(&pilha);
            int resultado = 0;

            switch (token[0]) {
                case '+': resultado = a + b; break;
                case '-': resultado = a - b; break;
                case '*': resultado = a * b; break;
                case '/': resultado = a / b; break;
                default:
                    printf("Operador inválido: %s\n", token);
                    return 0;
            }
            push(&pilha, resultado);
        }
        token = strtok(NULL, " ");
    }

    return pop(&pilha);
}

// ---------------------- Exemplo de uso ----------------------

int main() {
    const char* expressao = "3 4 + 2 *"; // (3 + 4) * 2 = 14
    int resultado = avaliar_posfixa(expressao);
    printf("Resultado da expressão pós-fixa: %d\n", resultado);
    return 0;
}


*/


//-------------------------------------------------------------


/*
//27)

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = -1;
}

int esta_vazia(Pilha* p) {
    return p->topo == -1;
}

void push(Pilha* p, int valor) {
    if (p->topo < MAX - 1) {
        p->dados[++(p->topo)] = valor;
    } else {
        printf("Erro: pilha cheia\n");
    }
}

int pop(Pilha* p) {
    if (!esta_vazia(p)) {
        return p->dados[(p->topo)--];
    } else {
        printf("Erro: pilha vazia\n");
        exit(1);
    }
}

int topo(Pilha* p) {
    if (!esta_vazia(p)) {
        return p->dados[p->topo];
    } else {
        printf("Erro: pilha vazia\n");
        exit(1);
    }
}

// ---------------------- Fila com duas pilhas ----------------------

typedef struct {
    Pilha entrada;
    Pilha saida;
} Fila;

void inicializar_fila(Fila* f) {
    inicializar(&f->entrada);
    inicializar(&f->saida);
}

int esta_vazia_fila(Fila* f) {
    return esta_vazia(&f->entrada) && esta_vazia(&f->saida);
}

void transferir(Pilha* origem, Pilha* destino) {
    while (!esta_vazia(origem)) {
        push(destino, pop(origem));
    }
}

void enfileirar(Fila* f, int valor) {
    push(&f->entrada, valor);
}

int desenfileirar(Fila* f) {
    if (esta_vazia(&f->saida)) {
        if (esta_vazia(&f->entrada)) {
            printf("Erro: fila vazia\n");
            exit(1);
        }
        transferir(&f->entrada, &f->saida);
    }
    return pop(&f->saida);
}

int frente(Fila* f) {
    if (esta_vazia(&f->saida)) {
        if (esta_vazia(&f->entrada)) {
            printf("Erro: fila vazia\n");
            exit(1);
        }
        transferir(&f->entrada, &f->saida);
    }
    return topo(&f->saida);
}

// ---------------------- Exemplo de uso ----------------------

int main() {
    Fila f;
    inicializar_fila(&f);

    enfileirar(&f, 10);
    enfileirar(&f, 20);
    enfileirar(&f, 30);

    printf("Frente da fila: %d\n", frente(&f));     // 10
    printf("Desenfileirado: %d\n", desenfileirar(&f)); // 10
    printf("Frente agora: %d\n", frente(&f));       // 20
    printf("Desenfileirado: %d\n", desenfileirar(&f)); // 20
    printf("Desenfileirado: %d\n", desenfileirar(&f)); // 30

    return 0;
}
*/


//-------------------------------------------------------------


/*
//28)

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

No* novo_no(int valor) {
    No* no = (No*)malloc(sizeof(No));
    no->valor = valor;
    no->prox = NULL;
    return no;
}

void inserir_fim(No** lista, int valor) {
    No* no = novo_no(valor);
    if (*lista == NULL) {
        *lista = no;
    } else {
        No* temp = *lista;
        while (temp->prox) {
            temp = temp->prox;
        }
        temp->prox = no;
    }
}

void imprimir_lista(No* lista) {
    while (lista) {
        printf("%d ", lista->valor);
        lista = lista->prox;
    }
    printf("\n");
}

No* inverter_grupos(No* cabeca, int K) {
    No* atual = cabeca;
    No* anterior = NULL;
    No* proximo = NULL;
    int count = 0;

    No* temp = cabeca;
    for (int i = 0; i < K; i++) {
        if (!temp) return cabeca;
        temp = temp->prox;
    }

    // Inverte K nós
    while (atual != NULL && count < K) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
        count++;
    }

    // Chamada recursiva para o restante da lista
    if (proximo != NULL) {
        cabeca->prox = inverter_grupos(proximo, K);
    }

    return anterior; // novo início da sublista
}

// ------------------------ Exemplo de uso ------------------------

int main() {
    No* lista = NULL;

    inserir_fim(&lista, 1);
    inserir_fim(&lista, 2);
    inserir_fim(&lista, 3);
    inserir_fim(&lista, 4);
    inserir_fim(&lista, 5);

    int K = 2;

    printf("Original: ");
    imprimir_lista(lista);

    lista = inverter_grupos(lista, K);

    printf("Invertida em grupos de %d: ", K);
    imprimir_lista(lista);

    return 0;
}
*/


//-------------------------------------------------------------


/*
//29)

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

No* novo_no(int valor) {
    No* no = (No*)malloc(sizeof(No));
    no->valor = valor;
    no->prox = NULL;
    return no;
}

void inserir_fim(No** lista, int valor) {
    No* no = novo_no(valor);
    if (*lista == NULL) {
        *lista = no;
    } else {
        No* temp = *lista;
        while (temp->prox)
            temp = temp->prox;
        temp->prox = no;
    }
}

No* inverter_lista(No* cabeca) {
    No* anterior = NULL;
    No* atual = cabeca;
    No* proximo = NULL;
    while (atual) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }
    return anterior;
}

int eh_palindromo(No* cabeca) {
    if (!cabeca || !cabeca->prox) return 1;

    No* lento = cabeca;
    No* rapido = cabeca;
    while (rapido->prox && rapido->prox->prox) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }

    No* segunda_metade = inverter_lista(lento->prox);

    No* p1 = cabeca;
    No* p2 = segunda_metade;
    int palindromo = 1;
    while (p2) {
        if (p1->valor != p2->valor) {
            palindromo = 0;
            break;
        }
        p1 = p1->prox;
        p2 = p2->prox;
    }

    lento->prox = inverter_lista(segunda_metade);

    return palindromo;
}

void imprimir_lista(No* lista) {
    while (lista) {
        printf("%d ", lista->valor);
        lista = lista->prox;
    }
    printf("\n");
}

// ------------------------ Exemplo de uso ------------------------

int main() {
    No* lista = NULL;

    inserir_fim(&lista, 1);
    inserir_fim(&lista, 2);
    inserir_fim(&lista, 3);
    inserir_fim(&lista, 2);
    inserir_fim(&lista, 1);

    printf("Lista: ");
    imprimir_lista(lista);

    if (eh_palindromo(lista))
        printf("É palíndromo.\n");
    else
        printf("Não é palíndromo.\n");

    return 0;
}


*/



//-------------------------------------------------------------


/*
//30)

#include <stdio.h>

#define MAX 100

int trapping_rain_water(int altura[], int n) {
    int stack[MAX];
    int topo = -1;
    int agua = 0;
    int i = 0;

    while (i < n) {
        // Enquanto há água acumulada (vales)
        while (topo != -1 && altura[i] > altura[stack[topo]]) {
            int fundo = stack[topo--];

            if (topo == -1) break;

            int distancia = i - stack[topo] - 1;
            int altura_limite = (altura[i] < altura[stack[topo]] ? altura[i] : altura[stack[topo]]) - altura[fundo];
            agua += distancia * altura_limite;
        }

        // Empilha índice atual
        stack[++topo] = i;
        i++;
    }

    return agua;
}

// -------------------------- Teste --------------------------

int main() {
    int altura[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(altura) / sizeof(altura[0]);

    int resultado = trapping_rain_water(altura, n);
    printf("Água retida: %d\n", resultado); // Esperado: 6

    return 0;
}


*/
