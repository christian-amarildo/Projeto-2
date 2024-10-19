// Protótipo da função para gerar uma lista de inteiros
// Parâmetros:
// - int tamanho: o tamanho da lista a ser gerada
// - int opcao_preordenacao: especifica se a lista deve ser gerada de forma aleatória ou pré-ordenada (1 para decrescente, outro valor para aleatória)
// Retorna: um ponteiro para a lista de inteiros gerada
int* GerarLista(int tamanho, int opcao_preordenacao);

// Protótipo da função para gerar um número aleatório dentro de um intervalo
// Parâmetros:
// - int min: valor mínimo do intervalo
// - int max: valor máximo do intervalo
// Retorna: um número inteiro aleatório entre min e max (inclusive)
int GeradorNumAleatorio(int min, int max);

// Protótipo da função para imprimir uma lista de inteiros
// Parâmetros:
// - int* lista: ponteiro para o array que representa a lista
// - int tamanho: tamanho da lista
// Imprime a lista no formato "[elemento1, elemento2, ..., elementoN]"
void imprimirLista(int* lista, int tamanho);

// Protótipo da função para ordenar uma lista usando diferentes algoritmos
// Parâmetros:
// - int* lista: ponteiro para o array que representa a lista
// - int opcao_Alg: código que determina qual algoritmo de ordenação será usado (1 para Bubble Sort, 2 para Quick Sort, etc.)
// - int n: tamanho da lista
// Ordena a lista de acordo com o algoritmo especificado e exibe o tempo de execução e contagem de operações (comparações e trocas)
void ordenarLista(int* lista, int opcao_Alg, int n);
