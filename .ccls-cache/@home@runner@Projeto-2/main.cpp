#include <iostream>
#include <string>
#include "lista.h"
using namespace std;

int main() {

  int opcao = 0;

  while (opcao != 2) {

    cout << "Bem-Vindo so sistema em c++ de ordenação de listas e análise de "
            "complexidade\n";
    cout << "Deseja fazer o que?\n";
    cout << "1 - Iniciar testes de ordenação\n";
    cout << "2 - Sair do programa\n";
    cout << "Sua opção? : ";
    cin >> opcao;

    cin.ignore();

    (void)system("clear");

    switch (opcao) {
    case 1: {

      int opcao_tam = 0, opcao_preordenacao = 0;

      while (true) {
        cout << "Iniciando testes de ordenação\n";
        cout << "1° Fase: Escolha do tamanho da Lista\n";
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
        cout << "1 - Lista com 10 elementos\n";
        cout << "2 - Lista com 100 elementos\n";
        cout << "3 - Lista com 1.000 elementos\n";
        cout << "4 - Lista com 10.000 elementos\n";
        cout << "Sua opção? : ";
        cin >> opcao_tam;

        cin.ignore();
        if (opcao_tam <= 4 && opcao_tam >= 1) {
          break;
        }
        (void)system("clear");
      }

      int tamanhos[4] = {10, 100, 1000, 10000};
      int tamanho = tamanhos[opcao_tam - 1];

      (void)system("clear");

      cout << "Tamanho da lista: " << tamanho << endl << "\n";


      while (true) {
        cout << "2° Fase: Escolha do Pré-Ordenacao da lista\n";
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
        cout << "1 - Lista em ordem decrescente (Comecando em TAM escolhido ate 1) (Pior Caso)\n";
        cout << "2 - Lista completamente desordenada com valores aleatorios (Caso medio)\n";
        cout << "Sua opção? : ";
        cin >> opcao_preordenacao;

        cin.ignore();
        if (opcao_preordenacao <= 2 && opcao_preordenacao >= 1) {
          break;
        }
      }

      int* lista = GerarLista(tamanho, opcao_preordenacao);

      int opcao_imprimir;
      cout <<"Deseja imprimir a lista? (0 para não, 1 para sim): ";
      cin >> opcao_imprimir;

      cout << "\n";
      if(opcao_imprimir){
        (void)system("clear");
        imprimirLista(lista, tamanho);
        cout << "\n\n";
      }

      int opcao_Alg=0;
      while (true) {

        cout << "3° Fase: Escolha do algoritmo de ordenação da lista\n";
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
        cout << "1 - Bubble Sort\n";
        cout << "2 - Quick Sort\n";
        cout << "3 - Merge Sort\n";
        cout << "4 - Radix Sort\n";
        cout << "Sua opção? : ";
        cin >> opcao_Alg;

        cin.ignore();
        if (opcao_Alg <= 4 && opcao_Alg >= 1) {
          break;
        }
      }


      ordenarLista(lista,opcao_Alg, tamanho);

      cout << "\nOrdenação Completa!";
      cout << "\nDeseja imprimir a lista? (0 para não, 1 para sim): ";
      cin >> opcao_imprimir;
      if(opcao_imprimir){
        cout << "\n";
        imprimirLista(lista, tamanho);
        cout << "\n";
      }


      break;
    }

    case 2: {

      cout << "Obrigado por usar o programa!!\n";
      opcao =2;
      break;
    }
    }
  }
  return 0;
}