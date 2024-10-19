#include "lista.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <chrono>  // Biblioteca para medir tempo
using namespace std;
using namespace std::chrono;

int *GerarLista(int tamanho, int pre_ordenacao) {
  int *lista = (int *)malloc((tamanho) * sizeof(int));

  if (pre_ordenacao == 1) {
    for (int i = 0; i < tamanho; i++) {
      lista[i] = tamanho - i;
    }
    return lista;
  }

  int min, max;
  cout << "\nDigite o valor minimo: ";
  cin >> min;
  cout << "\nDigite o valor maximo: ";
  cin >> max;

  for (int i = 0; i < tamanho; i++) {
    lista[i] = GeradorNumAleatorio(min, max);
  }
  return lista;
}

int GeradorNumAleatorio(int min, int max) {
  static bool initialized = false;
  if (!initialized) {
    srand(static_cast<unsigned int>(time(0)));
    initialized = true;
  }
  return rand() % (max - min + 1) + min;
}

void imprimirLista(int* lista, int n) {
    cout << "\n[";
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            cout << lista[i] << ", ";
        } else {
            cout << lista[i];
        }
    }
    cout << "]\n";
}

void bubble_sort(int* Lista, int n, int* comparacoes, int* trocas) {
  int aux;
  for (int k = 0; k < n - 1; k++) {
    for (int j = 0; j < n - 1 - k; j++) {
      (*comparacoes)++;
      if (Lista[j] > Lista[j + 1]) {
        aux = Lista[j];
        Lista[j] = Lista[j + 1];
        Lista[j + 1] = aux;
        (*trocas)++;
      }
    }
  }
}

void quickSort(int* a, int esquerda, int direita, int *comparacoes, int *trocas) {
  int i, j, x, y;
  i = esquerda;
  j = direita;
  x = a[(esquerda + direita) / 2];
  while (i <= j) {
    while (a[i] < x && i < direita) {
      i++;
      (*comparacoes)++;
    }
    while (a[j] > x && j > esquerda) {
      j--;
      (*comparacoes)++;
    }
    if (i <= j) {
      y = a[i];
      a[i] = a[j];
      a[j] = y;
      (*trocas)++;
      i++;
      j--;
    }
  }
  if (j > esquerda) {
    quickSort(a, esquerda, j, comparacoes, trocas);
  }
  if (i < direita) {
    quickSort(a, i, direita, comparacoes, trocas);
  }
}

void merge(int* arr, int esquerda, int meio, int direita, int* trocas, int* comparacoes) {
  int i, j, k;
  int n1 = meio - esquerda + 1;
  int n2 = direita - meio;

  int* L = new int[n1];
  int* R = new int[n2];

  for (i = 0; i < n1; i++) {
    L[i] = arr[esquerda + i];
  }
  for (j = 0; j < n2; j++) {
    R[j] = arr[meio + 1 + j];
  }

  i = 0;
  j = 0;
  k = esquerda;

  while (i < n1 && j < n2) {
    (*comparacoes)++;
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    (*trocas)++;  // Conta a cópia como uma troca, conforme solicitado
    k++;
  }

  // Copia os elementos restantes de L[], se houver
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
    (*trocas)++;  // Conta a cópia como uma troca
  }

  // Copia os elementos restantes de R[], se houver
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
    (*trocas)++;  // Conta a cópia como uma troca
  }

  delete[] L;
  delete[] R;
}

void mergeSort(int* arr, int esquerda, int direita, int* trocas, int* comparacoes) {
  if (esquerda < direita) {
    int meio = esquerda + (direita - esquerda) / 2;

    mergeSort(arr, esquerda, meio, trocas, comparacoes);
    mergeSort(arr, meio + 1, direita, trocas, comparacoes);

    merge(arr, esquerda, meio, direita, trocas, comparacoes);
  }
}






void radixsort(int* vetor, int tamanho, int* comparacoes, int* trocas) {
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    // Encontra o maior elemento no vetor (para determinar o número de dígitos)
    for (i = 0; i < tamanho; i++) {
        (*comparacoes)++;  // Comparação para encontrar o maior
        if (vetor[i] > maior)
            maior = vetor[i];
    }

    // Loop para cada dígito
    while (maior / exp > 0) {
        int bucket[10] = { 0 };

        // Conta a frequência dos dígitos
        for (i = 0; i < tamanho; i++) {
            (*comparacoes)++;  // Comparação para acessar o bucket
            bucket[(vetor[i] / exp) % 10]++;
        }

        // Atualiza o bucket para armazenar as posições corretas
        for (i = 1; i < 10; i++) {
            (*comparacoes)++;  // Comparação no loop
            bucket[i] += bucket[i - 1];
        }

        // Ordena os elementos temporariamente em b[] baseado no dígito atual
        for (i = tamanho - 1; i >= 0; i--) {
            (*comparacoes)++;  // Comparação no loop
            b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
            (*trocas)++;  // Troca ao inserir no vetor temporário
        }

        // Copia os elementos ordenados de volta para o vetor original
        for (i = 0; i < tamanho; i++) {
            (*comparacoes)++;  // Comparação no loop
            vetor[i] = b[i];
            (*trocas)++;  // Troca ao atualizar o vetor original
        }

        exp *= 10;
    }

    free(b);
}

void ordenarLista(int* lista, int opcao_Alg, int n) {
  int comparacoes = 0;
  int trocas = 0;

  auto start = high_resolution_clock::now();
  if(opcao_Alg == 1){
    bubble_sort(lista, n, &comparacoes, &trocas);
  } else if(opcao_Alg == 2){
    quickSort(lista, 0, n - 1, &comparacoes, &trocas);
  } else if(opcao_Alg == 3){
    mergeSort(lista, 0, n - 1, &trocas, &comparacoes);
  } else if(opcao_Alg == 4){
    radixsort(lista, n, &comparacoes, &trocas);}

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>(stop - start);

  cout << "Tempo de execução: " << duration.count() << " µs" << endl;
  cout << "Número de Comparações: " << comparacoes << " || Número de trocas: " << trocas << endl;
}
