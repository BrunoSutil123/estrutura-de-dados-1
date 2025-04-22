/*
1)

#include <stdio.h>

int Fat(int num);

int main() {
    
    printf("Fatorial é: %d", Fat(4));

    return 0;
}


int Fat(int num){
    
    if(num == 0){
        return 1;
    }
    
    return num * Fat(num - 1);
}
*/








/*
2)

#include <stdio.h>

int Soma(int N);

int main() {

    printf("Soma total: %d", Soma(4));

    return 0;
}

int Soma(int N){
    if(N==0){
        return 0;
    }
    
    return N + Soma(N-1);
}
*/








/*
3)

#include <stdio.h>
// a Sequencia de  Fibonacci segue a fórmula: F(n)=F(n-1)+F(n-2)
//Ou seja, cada número da sequência é a soma dos dois anteriores.

int Fib(int p);

int main() {
    int posicao = 4;
    
    printf("A %d° posição da Sequencia de  Fibonacci é: %d", posicao, Fib(posicao));

    return 0;
}

int Fib(int p){
    
    if(p == 0){
        return 0;
    }
    if(p == 1){
        return 1;
    }
    
    return Fib(p-1) + Fib(p-2);
}
*/








/*
4)

#include <stdio.h>

int Pot(int X, int Y);

int main() {
    
    printf("A potencia é: %d", Pot(2, 5));

    return 0;
}

int Pot(int X, int Y){
    
    if(Y == 0){
        return 1;
    }
    
    return X * Pot(X, Y - 1);
    
    
}

*/








/*
5)

#include <stdio.h>

int cont(int N);

int main() {

    cont(5);

    return 0;
}

int cont(int N){
    
    if(N == 0){
        return 1;
    }
    
    printf("%d\n", N);
    
    return cont(N-1);
    
}

*/








/*
6)

#include <stdio.h>

int Soma(int Num);

int main() {
    
    printf("A soma final é: %d", Soma(12345));

    return 0;
}

int Soma(int Num){
    
    if(Num == 0){
        return 0;
    }
    
    return Num %10 + Soma(Num / 10);
    
    
}

*/








/*
7)

#include <stdio.h>

// Declaração da função correta
void Inv(char *str, int inicio, int fim);

int main() {
    char palavra[] = "Amigo"; // String original

    int tamanho = 0;
    while (palavra[tamanho] != '\0') { // Descobrir o tamanho da string
        tamanho++;
    }

    Inv(palavra, 0, tamanho - 1); // Chamar a função recursiva

    printf("Palavra invertida: %s\n", palavra); // Mostrar o resultado

    return 0;
}

// Implementação da função correta
void Inv(char *Palavra, int I, int F) {
    if (I >= F) {
        return; // Se já chegou no meio, para.
    }

    // Troca os caracteres
    char temp = Palavra[I];
    Palavra[I] = Palavra[F];
    Palavra[F] = temp;

    // Chama a função novamente para continuar invertendo
    Inv(Palavra, I + 1, F - 1);
}


*/








/*
8)


#include <stdio.h>
#include <string.h>

int ehPalindromo(char str[], int inicio, int fim); 

int main() {
    char palavra[100];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    int tamanho = strlen(palavra); //converter string pra int

    if (ehPalindromo(palavra, 0, tamanho - 1)) {
        printf("1\n"); // É palíndromo
    } else {
        printf("0\n"); // Não é palíndromo 
    }

    return 0;
}


int ehPalindromo(char str[], int inicio, int fim) {
    if (inicio >= fim) {
        return 1; // Caso base: é palíndromo
    }
    if (str[inicio] != str[fim]) {
        return 0; // Não é palíndromo
    }
    // Chamada recursiva: avança o início e reduz o fim
    return ehPalindromo(str, inicio + 1, fim - 1);
}


*/








/*
9)

#include <stdio.h>

int MDC(int num1, int num2);

int main() {
    
    printf("MDC: %d", MDC(48, 18));

    return 0;
}


int MDC(int num1, int num2){
    
    if(num2 == 0){
        return num1;
    }
    
    return  MDC(num2, num1 % num2);
}


*/








/*
10)



#include <stdio.h>

int Multiplicação (int N1, int N2);

int main() {
    
    
    printf("Multiplicação: %d", Multiplicação(10, 5));

    return 0;
}

int Multiplicação (int N1, int N2){
    
    if(N2 == 0){
        return 0;
    }
    
    
    return N1 + Multiplicação(N1, N2 - 1);
}



*/








/*
11)


#include <stdio.h>


int contarChar(char str[], char c);



int main() {
    char texto[100];
    char letra;

    printf("Digite uma string: ");
    scanf("%s", texto);

    printf("Digite o caractere a ser contado: ");
    scanf(" %c", &letra);  // o espaço antes de %c é pra ignorar o Enter anterior

    int resultado = contarChar(texto, letra);

    printf("O caractere '%c' aparece %d vezes.\n", letra, resultado);

    return 0;
}


int contarChar(char str[], char c) {
    if (str[0] == '\0') {
        return 0; // Caso base: fim da string
    }

    if (str[0] == c) {
        return 1 + contarChar(str + 1, c); // Soma e avança
    } else {
        return contarChar(str + 1, c); // Só avança
    }
}


*/








/*
12)

#include <stdio.h>

int SomaArray(int Num[], int tamanho, int posicao);

int main() {
    
    int numeros[] = {1, 2, 3, 4};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    printf("Soma: %d", SomaArray(numeros, tamanho, 0));

    return 0;
}


int SomaArray(int Num[], int tamanho, int posicao) {
    if (posicao == tamanho) {
        return 0; // Caso base: chegou ao fim
    }

    return Num[posicao] + SomaArray(Num, tamanho, posicao + 1); // Soma atual + recursão
}


*/








/*
13)

#include <stdio.h>

int ehPrimoAux(int n, int i) {
    if (n < 2) return 0;           // 0 e 1 não são primos
    if (i * i > n) return 1;       // Não encontrou divisor ? é primo
    if (n % i == 0) return 0;      // Achou divisor ? não é primo
    return ehPrimoAux(n, i + 1);   // Tenta o próximo divisor
}

int ehPrimo(int n) {
    return ehPrimoAux(n, 2);       // Começa testando do 2 pra cima
}

int main() {
    int numero;

    printf("Digite um número: ");
    scanf("%d", &numero);

    if (ehPrimo(numero)) {
        printf("%d é primo!\n", numero);
    } else {
        printf("%d não é primo.\n", numero);
    }

    return 0;
}


*/



------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- continuar daqui pra baixo



/*
14)


#include <stdio.h>

void decimalParaBinario(int n);

int main() {
    int numero;

    printf("Digite um número decimal: ");
    scanf("%d", &numero);

    if (numero == 0) {
        printf("0");
    } else {
        decimalParaBinario(numero);
    }

    printf("\n");
    return 0;
}

void decimalParaBinario(int n) {
    if (n > 0) {
        decimalParaBinario(n / 2);       // chamada recursiva
        printf("%d", n % 2);             // imprime o bit (resto da divisão por 2)
    }
}

*/








/*
15)

#include <stdio.h>

int VerificarPar(int Num, int cmc);

int main() {
    int numero;
    printf("Digite um número: ");
    scanf("%d", &numero);
    
    printf("\n Os pares de 0 até %d são:\n", numero);
    VerificarPar(numero, 0);

    return 0;
}

int VerificarPar(int Num, int cmc){
    
    
    if(cmc < Num){
       if(cmc % 2 == 0){
            printf("- %d \n", cmc);
            return VerificarPar(Num, cmc + 1);
        } else{
            return VerificarPar(Num, cmc + 1);
        }
    }
    
    
}
*/








/*
16)


#include <stdio.h>

int VerificarPar(int Num, int cmc);

int main() {
    int numero;
    printf("Digite um número: ");
    scanf("%d", &numero);
    
    printf("\n Os ímpares de 0 até %d são:\n", numero);
    VerificarPar(numero, 0);

    return 0;
}

int VerificarPar(int Num, int cmc){
    
    
    if(cmc < Num){
       if(cmc % 2 != 0){
            printf("- %d \n", cmc);
            return VerificarPar(Num, cmc + 1);
        } else{
            return VerificarPar(Num, cmc + 1);
        }
    }
    
    
}
*/








/*
17)

#include <stdio.h>

int buscaElemento(int array[], int tamanho, int elemento);

int main() {
    int numeros[] = {2, 4, 6, 8};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    //sizeof(numeros) ? 4 elementos × 4 bytes = 16
    //sizeof(numeros[0]) ? 4 bytes
    //16 / 4 = 4 elementos
    
    int alvo = 6;

    if (buscaElemento(numeros, tamanho, alvo)) {
        
        printf("%d está presente no array.\n", alvo);
    } else {
        printf("%d não está presente no array.\n", alvo);
    }

    return 0;
}



int buscaElemento(int array[], int tamanho, int elemento) {
    if (tamanho == 0) {
        return 0; // não encontrou
    }

    if (array[0] == elemento) {
        return 1; // achou o elemento
    }

    return buscaElemento(array + 1, tamanho - 1, elemento); // chama recursivamente no resto do array
}

*/








/*
18)

#include <stdio.h>

int TamanhoString(char str[], int contador); 

int main() {
    char palavra[100];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);
    
    printf("Tamanho: %d\n", TamanhoString(palavra, 0));

    return 0;
}

int TamanhoString(char str[], int contador) {
    // Caso base: chegou no final da string
    if (str[contador] == '\0') {
        return 0;
    }

    // Chamada recursiva: soma 1 e avança o contador
    return 1 + TamanhoString(str, contador + 1);
}
*/








/*
19)

#include <stdio.h>

void TorreDeHanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 1) {
        printf("Mover disco 1 de %c para %c\n", origem, destino);
        return;
    }

    // Passo 1: move n-1 discos da origem para o auxiliar
    TorreDeHanoi(n - 1, origem, auxiliar, destino);

    // Passo 2: move o maior disco para o destino
    printf("Mover disco %d de %c para %c\n", n, origem, destino);

    // Passo 3: move os n-1 discos do auxiliar para o destino
    TorreDeHanoi(n - 1, auxiliar, destino, origem);
}

int main() {
    int n;

    printf("Quantos discos? ");
    scanf("%d", &n);

    TorreDeHanoi(n, 'A', 'C', 'B');

    return 0;
}

*/









//20) sequencias existentes

/*
#include <stdio.h>
#include <string.h>

void trocar(char *x, char *y);
void permutar(char str[], int inicio, int fim);


int main() {
    char palavra[100];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    int tamanho = strlen(palavra);

    printf("Permutações:\n");
    permutar(palavra, 0, tamanho - 1);

    return 0;
}


// Função auxiliar para trocar dois caracteres
void trocar(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Função recursiva para gerar permutações
void permutar(char str[], int inicio, int fim) {
    if (inicio == fim) {
        printf("%s\n", str);
    } else {
        for (int i = inicio; i <= fim; i++) {
            trocar(&str[inicio], &str[i]); // troca atual
            permutar(str, inicio + 1, fim);// recursão
            trocar(&str[inicio], &str[i]);// desfaz troca (backtrack)
        }
    }
}
*/










/*
21)

#include <stdio.h>

void combinar(int arr[], int n, int k, int index, int resultado[], int i);

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    int resultado[k]; // vetor auxiliar para armazenar as combinações

    printf("Combinações de tamanho %d:\n", k);
    combinar(arr, n, k, 0, resultado, 0);

    return 0;
}


void combinar(int arr[], int n, int k, int index, int resultado[], int i) {
    // Caso base: combinação de tamanho k formada
    if (index == k) {
        printf("{ ");
        for (int j = 0; j < k; j++) {
            printf("%d ", resultado[j]);
        }
        printf("}\n");
        return;
    }

    // Quando não há mais elementos para incluir
    if (i >= n) {
        return;
    }

    // Inclui o elemento atual
    resultado[index] = arr[i];
    combinar(arr, n, k, index + 1, resultado, i + 1);

    // Exclui o elemento atual e move para o próximo
    combinar(arr, n, k, index, resultado, i + 1);
}

*/









//22)
/*

#include <stdio.h>

void gerarSubconjuntos(int arr[], int aux[], int n, int indice, int pos);

int main() {
    int arr[] = {1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int aux[n]; // vetor auxiliar para guardar subconjuntos

    printf("Subconjuntos:\n");
    gerarSubconjuntos(arr, aux, n, 0, 0);

    return 0;
}



// Função recursiva para gerar subconjuntos
void gerarSubconjuntos(int arr[], int aux[], int n, int indice, int pos) {
    if (indice == n) {
        printf("{ ");
        for (int i = 0; i < pos; i++) {
            printf("%d ", aux[i]);
        }
        printf("}\n");
        return;
    }

    // Caso 1: não incluir o elemento atual
    gerarSubconjuntos(arr, aux, n, indice + 1, pos);

    // Caso 2: incluir o elemento atual
    aux[pos] = arr[indice];
    gerarSubconjuntos(arr, aux, n, indice + 1, pos + 1);
}


*/









/*
23)


#include <stdio.h>

void merge(int arr[], int inicio, int meio, int fim);
void mergeSort(int arr[], int inicio, int fim);
void imprimirArray(int arr[], int tamanho);



// Função principal
int main() {
    int arr[] = {5, 3, 8, 1};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    imprimirArray(arr, tamanho);

    mergeSort(arr, 0, tamanho - 1);

    printf("Array ordenado: ");
    imprimirArray(arr, tamanho);

    return 0;
}



// Função para mesclar dois subarrays ordenados
void merge(int arr[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int L[n1], R[n2]; // Subarrays temporários

    // Copia os dados para os subarrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[inicio + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

    // Mescla os subarrays L[] e R[] em arr[]
    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Função recursiva para aplicar o Merge Sort
void mergeSort(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, fim);

        // Mescla as duas metades
        merge(arr, inicio, meio, fim);
    }
}

// Função auxiliar para imprimir o array
void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

*/








/*
24)

#include <stdio.h>

void trocar(int *a, int *b);
int particionar(int arr[], int inicio, int fim);
void quickSort(int arr[], int inicio, int fim);
void imprimirArray(int arr[], int tamanho);


int main() {
    int arr[] = {9, 2, 5, 1, 7};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    imprimirArray(arr, tamanho);

    quickSort(arr, 0, tamanho - 1);

    printf("Array ordenado: ");
    imprimirArray(arr, tamanho);

    return 0;
}





// Função para trocar dois elementos
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de partição (coloca o pivô na posição correta)
int particionar(int arr[], int inicio, int fim) {
    int pivo = arr[fim]; // último elemento como pivô
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (arr[j] < pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }

    trocar(&arr[i + 1], &arr[fim]);
    return i + 1; // nova posição do pivô
}

// Função recursiva do Quick Sort
void quickSort(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        int posicaoPivo = particionar(arr, inicio, fim);

        // Ordena antes e depois do pivô
        quickSort(arr, inicio, posicaoPivo - 1);
        quickSort(arr, posicaoPivo + 1, fim);
    }
}

// Função para imprimir o array
void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}






*/








/*
25)
#include <stdio.h>

int buscaBinaria(int arr[], int inicio, int fim, int valor);

int main() {
    int array[] = {1, 3, 5, 7, 9};
    int tamanho = sizeof(array) / sizeof(array[0]);
    int alvo = 5;

    int resultado = buscaBinaria(array, 0, tamanho - 1, alvo);

    if (resultado != -1) {
        printf("Elemento %d encontrado no índice %d\n", alvo, resultado);
    } else {
        printf("Elemento %d não encontrado no array\n", alvo);
    }

    return 0;
}


int buscaBinaria(int arr[], int inicio, int fim, int valor) {
    if (inicio > fim) {
        return -1; // Não encontrado
    }

    int meio = (inicio + fim) / 2;

    if (arr[meio] == valor) {
        return meio; // Valor encontrado
    } else if (arr[meio] < valor) {
        return buscaBinaria(arr, meio + 1, fim, valor); // Buscar na metade direita
    } else {
        return buscaBinaria(arr, inicio, meio - 1, valor); // Buscar na metade esquerda
    }
}


*/






/*
26)

#include <stdio.h>

int exponenciacaoRapida(int x, int n);

int main() {
    int base = 3;
    int expoente = 4;

    int resultado = exponenciacaoRapida(base, expoente);

    printf("%d^%d = %d\n", base, expoente, resultado);

    return 0;
}


int exponenciacaoRapida(int x, int n) {
    if (n == 0) {
        return 1;
    }

    if (n % 2 == 0) {
        int meio = exponenciacaoRapida(x, n / 2);
        return meio * meio;
    } else {
        return x * exponenciacaoRapida(x, n - 1);
    }
}

*/










/*
27)
#include <stdio.h>

#define MAX 100


void encontrarCaminhos(int x, int y, int x2, int y2, int caminho[MAX][2], int passo);

int main() {
    int caminho[MAX][2];
    printf("Caminhos da posição (0,0) até (2,2):\n");
    encontrarCaminhos(0, 0, 2, 2, caminho, 0);
    return 0;
}

void encontrarCaminhos(int x, int y, int x2, int y2, int caminho[MAX][2], int passo) {
    if (x > x2 || y > y2) return;

    caminho[passo][0] = x;
    caminho[passo][1] = y;

    // Chegou no destino
    if (x == x2 && y == y2) {
        for (int i = 0; i <= passo; i++) {
            printf("(%d,%d)", caminho[i][0], caminho[i][1]);
            if (i != passo) printf(" -> ");
        }
        printf("\n");
        return;
    }

    // Ir para direita
    encontrarCaminhos(x, y + 1, x2, y2, caminho, passo + 1);

    // Ir para baixo
    encontrarCaminhos(x + 1, y, x2, y2, caminho, passo + 1);
}

*/









/*
28)

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int posicaoSegura(int linha, int coluna, int n);
void imprimirTabuleiro(int n);
void resolverNQueens(int linha, int n);


int main() {
    int n;
    printf("Digite o valor de N (até 10): ");
    scanf("%d", &n);

    if (n > MAX || n < 1) {
        printf("Valor inválido.\n");
        return 1;
    }

    printf("\nSoluções para o problema das %d rainhas:\n\n", n);
    resolverNQueens(0, n);
    return 0;
}



int board[MAX]; // board[i] guarda a coluna da rainha na linha i

// Verifica se podemos colocar uma rainha na linha atual
int posicaoSegura(int linha, int coluna, int n) {
    for (int i = 0; i < linha; i++) {
        if (board[i] == coluna || abs(board[i] - coluna) == abs(i - linha))
            return 0;
    }
    return 1;
}

// Imprime o tabuleiro atual
void imprimirTabuleiro(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

// Tenta posicionar rainhas recursivamente
void resolverNQueens(int linha, int n) {
    if (linha == n) {
        imprimirTabuleiro(n); // Todas as rainhas foram colocadas com sucesso
        return;
    }

    for (int coluna = 0; coluna < n; coluna++) {
        if (posicaoSegura(linha, coluna, n)) {
            board[linha] = coluna;
            resolverNQueens(linha + 1, n); // Tenta próxima linha
        }
    }
}


*/











/*
29)
#include <stdio.h>

#define N 3
#define M 4


int valido(int x, int y);
int resolverLabirinto(int x, int y);
void imprimirCaminho();

int main() {
    if (resolverLabirinto(0, 0)) {
        imprimirCaminho();
    } else {
        printf("Nenhum caminho encontrado.\n");
    }

    return 0;
}


// Labirinto de exemplo (0 = caminho livre, 1 = parede)
int labirinto[N][M] = {
    {0, 0, 0, 0},
    {1, 1, 0, 1},
    {1, 1, 0, 0}
};


// Matriz para marcar o caminho
int caminho[N][M] = {0};

// Função para verificar se a posição é válida
int valido(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < M &&
            labirinto[x][y] == 0 && caminho[x][y] == 0);
}

// Função recursiva para encontrar o caminho
int resolverLabirinto(int x, int y) {
    if (x == N - 1 && y == M - 1) {
        caminho[x][y] = 1;
        return 1;
    }

    if (valido(x, y)) {
        caminho[x][y] = 1;

        if (resolverLabirinto(x, y + 1)) return 1;
        if (resolverLabirinto(x + 1, y)) return 1;
        if (resolverLabirinto(x, y - 1)) return 1;
        if (resolverLabirinto(x - 1, y)) return 1;

        caminho[x][y] = 0; // backtracking
    }

    return 0;
}

// Imprime o caminho
void imprimirCaminho() {
    printf("\nCaminho encontrado:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (caminho[i][j])
                printf("* ");
            else
                printf("%d ", labirinto[i][j]);
        }
        printf("\n");
    }
}

*/







/*
30)


#include <stdio.h>
#include <string.h>


void gerarParenteses(char *str, int pos, int abertos, int fechados, int n);


int main() {
    int n;
    printf("Digite o número de pares de parênteses: ");
    scanf("%d", &n);

    char str[2 * n + 1]; // string com tamanho suficiente
    gerarParenteses(str, 0, 0, 0, n);

    return 0;
}



void gerarParenteses(char *str, int pos, int abertos, int fechados, int n) {
    if (fechados == n) {
        str[pos] = '\0';
        printf("%s\n", str);
        return;
    }

    if (abertos < n) {
        str[pos] = '(';
        gerarParenteses(str, pos + 1, abertos + 1, fechados, n);
    }

    if (fechados < abertos) {
        str[pos] = ')';
        gerarParenteses(str, pos + 1, abertos, fechados + 1, n);
    }
}



*/
