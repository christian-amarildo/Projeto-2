#include "lista.h" // Inclui a biblioteca 'lista.h' que provavelmente contém definições relacionadas às listas
#include <cstdlib> // Inclui a biblioteca para funções de manipulação de memória, rand, srand, etc.
#include <ctime>   // Inclui a biblioteca para manipulação de tempo (necessária para a função de semente aleatória)
#include <iostream> // Inclui a biblioteca para entrada e saída padrão
#include <chrono>   // Inclui a biblioteca para medir o tempo de execução das funções
using namespace std;
using namespace std::chrono;

// Função para gerar uma lista de inteiros de acordo com o tamanho e tipo de pré-ordenação especificados
int *GerarLista(int tamanho, int pre_ordenacao) {
    // Aloca memória para a lista dinamicamente
    int *lista = (int *)malloc((tamanho) * sizeof(int));

    // Se a lista deve ser pré-ordenada em ordem decrescente
    if (pre_ordenacao == 1) {
        for (int i = 0; i < tamanho; i++) {
            lista[i] = tamanho - i; // Preenche a lista com valores decrescentes
        }
        return lista; // Retorna a lista gerada
    }

    // Variáveis para definir os limites dos valores aleatórios
    int min, max;
    cout << "\nDigite o valor minimo: ";
    cin >> min; // Solicita ao usuário o valor mínimo
    cout << "\nDigite o valor maximo: ";
    cin >> max; // Solicita ao usuário o valor máximo

    // Gera valores aleatórios dentro do intervalo especificado para preencher a lista
    for (int i = 0; i < tamanho; i++) {
        lista[i] = GeradorNumAleatorio(min, max); // Chama a função que gera números aleatórios
    }
    return lista; // Retorna a lista gerada
}

// Função para gerar um número aleatório entre min e max
int GeradorNumAleatorio(int min, int max) {
    static bool initialized = false; // Variável estática para verificar se srand já foi inicializado
    if (!initialized) {
        srand(static_cast<unsigned int>(time(0))); // Inicializa a semente aleatória com o tempo atual
        initialized = true; // Marca como inicializado para evitar reinicializações
    }
    return rand() % (max - min + 1) + min; // Retorna um número aleatório dentro do intervalo [min, max]
}

// Função para imprimir a lista
void imprimirLista(int* lista, int n) {
    cout << "\n[";
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            cout << lista[i] << ", "; // Imprime o valor com vírgula e espaço
        } else {
            cout << lista[i]; // Imprime o último valor sem vírgula
        }
    }
    cout << "]\n";
}

// Função que implementa o algoritmo de ordenação Bubble Sort
void bubble_sort(int* Lista, int n, int* comparacoes, int* trocas) {
    int aux;
    for (int k = 0; k < n - 1; k++) { // Itera sobre a lista
        for (int j = 0; j < n - 1 - k; j++) { // Compara elementos adjacentes
            (*comparacoes)++; // Conta uma comparação
            if (Lista[j] > Lista[j + 1]) { // Se o elemento atual é maior que o próximo
                aux = Lista[j]; // Troca os elementos
                Lista[j] = Lista[j + 1];
                Lista[j + 1] = aux;
                (*trocas)++; // Conta uma troca
            }
        }
    }
}

// Função que implementa o algoritmo de ordenação Quick Sort
void quickSort(int* a, int esquerda, int direita, int *comparacoes, int *trocas) {
    int i, j, x, y;
    i = esquerda;
    j = direita;
    x = a[(esquerda + direita) / 2]; // Pivô é o elemento central
    while (i <= j) {
        while (a[i] < x && i < direita) { // Encontra um elemento maior que o pivô
            i++;
            (*comparacoes)++; // Conta a comparação
        }
        while (a[j] > x && j > esquerda) { // Encontra um elemento menor que o pivô
            j--;
            (*comparacoes)++; // Conta a comparação
        }
        if (i <= j) { // Troca elementos
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            (*trocas)++; // Conta a troca
            i++;
            j--;
        }
    }
    if (j > esquerda) { // Recursão para a sublista da esquerda
        quickSort(a, esquerda, j, comparacoes, trocas);
    }
    if (i < direita) { // Recursão para a sublista da direita
        quickSort(a, i, direita, comparacoes, trocas);
    }
}

// Função auxiliar para o Merge Sort que mescla duas sublistas ordenadas
void merge(int* arr, int esquerda, int meio, int direita, int* trocas, int* comparacoes) {
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    // Cria arrays temporários
    int* L = new int[n1];
    int* R = new int[n2];

    // Copia os dados para os arrays temporários
    for (i = 0; i < n1; i++) {
        L[i] = arr[esquerda + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[meio + 1 + j];
    }

    i = 0; // Índice inicial do primeiro subarray
    j = 0; // Índice inicial do segundo subarray
    k = esquerda; // Índice inicial do array mesclado

    // Mescla os arrays temporários de volta ao array original
    while (i < n1 && j < n2) {
        (*comparacoes)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        (*trocas)++; // Conta a cópia como uma troca
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        (*trocas)++; // Conta a cópia como uma troca
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        (*trocas)++; // Conta a cópia como uma troca
    }

    delete[] L;
    delete[] R;
}

// Função que implementa o algoritmo Merge Sort
void mergeSort(int* arr, int esquerda, int direita, int* trocas, int* comparacoes) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        mergeSort(arr, esquerda, meio, trocas, comparacoes); // Ordena a primeira metade
        mergeSort(arr, meio + 1, direita, trocas, comparacoes); // Ordena a segunda metade

        merge(arr, esquerda, meio, direita, trocas, comparacoes); // Mescla as duas metades
    }
}

// Função que implementa o algoritmo Radix Sort
void radixsort(int* vetor, int tamanho, int* comparacoes, int* trocas) {
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    // Encontra o maior elemento no vetor (para determinar o número de dígitos)
    for (i = 0; i < tamanho; i++) {
        (*comparacoes)++;
        if (vetor[i] > maior)
            maior = vetor[i];
    }

    // Loop para cada dígito
    while (maior / exp > 0) {
        int bucket[10] = { 0 };

        // Conta a frequência dos dígitos
        for (i = 0; i < tamanho; i++) {
            (*comparacoes)++;
            bucket[(vetor[i] / exp) % 10]++;
        }

        // Atualiza o bucket para armazenar as posições corretas
        for (i = 1; i < 10; i++) {
            (*comparacoes)++;
            bucket[i] += bucket[i - 1];
        }

        // Ordena os elementos temporariamente em b[] baseado no dígito atual
        for (i = tamanho - 1; i >= 0; i--) {
            (*comparacoes)++;
            b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
            (*trocas)++;
        }

        // Copia os elementos ordenados de volta para o vetor original
        for (i = 0; i < tamanho; i++) {
            (*comparacoes)++;
            vetor[i] = b[i];
            (*trocas)++;
        }

        exp *= 10;
    }

    free(b);
}

// Função que escolhe o algoritmo de ordenação com base na opção fornecida
void ordenarLista(int* lista, int opcao_Alg, int n) {
    int comparacoes = 0;
    int trocas = 0;

    // Marca o início do tempo de execução
    auto start = high_resolution_clock::now();
    if(opcao_Alg == 1){
        bubble_sort(lista, n, &comparacoes, &trocas);
    } else if(opcao_Alg == 2){
        quickSort(lista, 0, n - 1, &comparacoes, &trocas);
    } else if(opcao_Alg == 3){
        mergeSort(lista, 0, n - 1, &trocas, &comparacoes);
    } else if(opcao_Alg == 4){
        radixsort(lista, n, &comparacoes, &trocas);
    }

    // Marca o fim do tempo de execução
    auto stop = high_resolution_clock::now();

    // Calcula a duração em microsegundos
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Tempo de execução: " << duration.count() << " µs" << endl;
    cout << "Número de Comparações: " << comparacoes << " || Número de trocas: " << trocas << endl;
}
