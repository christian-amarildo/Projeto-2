#include <iostream>  // Biblioteca para entrada e saída padrão
#include <string>    // Biblioteca para manipulação de strings
#include "lista.h"   // Inclui o header 'lista.h', que contém os protótipos das funções utilizadas no programa
using namespace std;

int main() {
    int opcao = 0;  // Variável para armazenar a opção escolhida pelo usuário no menu principal

    // Loop principal do programa que continua até que o usuário escolha a opção de sair
    while (opcao != 2) {
        cout << "Bem-Vindo ao sistema em C++ de ordenação de listas e análise de complexidade\n";
        cout << "Deseja fazer o que?\n";
        cout << "1 - Iniciar testes de ordenação\n";
        cout << "2 - Sair do programa\n";
        cout << "Sua opção? : ";
        cin >> opcao;  // Lê a opção do usuário

        cin.ignore();  // Limpa o buffer do cin para evitar problemas com a leitura subsequente

        (void)system("clear");  // Limpa a tela (usando o comando "clear" no sistema)

        switch (opcao) {
        case 1: {  // Caso o usuário escolha iniciar os testes de ordenação
            int opcao_tam = 0, opcao_preordenacao = 0;  // Variáveis para armazenar as opções do tamanho e da pré-ordenação

            while (true) {
                cout << "Iniciando testes de ordenação\n";
                cout << "1° Fase: Escolha do tamanho da Lista\n";
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
                cout << "1 - Lista com 10 elementos\n";
                cout << "2 - Lista com 100 elementos\n";
                cout << "3 - Lista com 1.000 elementos\n";
                cout << "4 - Lista com 10.000 elementos\n";
                cout << "Sua opção? : ";
                cin >> opcao_tam;  // Lê a escolha do tamanho da lista

                cin.ignore();  // Limpa o buffer do cin
                if (opcao_tam <= 4 && opcao_tam >= 1) {  // Verifica se a opção é válida
                    break;  // Sai do loop se a opção estiver correta
                }
                (void)system("clear");  // Limpa a tela e repete o loop
            }

            // Array que armazena os possíveis tamanhos das listas
            int tamanhos[4] = {10, 100, 1000, 10000};
            int tamanho = tamanhos[opcao_tam - 1];  // Seleciona o tamanho com base na escolha do usuário

            (void)system("clear");  // Limpa a tela

            cout << "Tamanho da lista: " << tamanho << endl << "\n";  // Exibe o tamanho escolhido

            while (true) {
                cout << "2° Fase: Escolha do Pré-Ordenacao da lista\n";
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
                cout << "1 - Lista em ordem decrescente (Comecando em TAM escolhido ate 1) (Pior Caso)\n";
                cout << "2 - Lista completamente desordenada com valores aleatorios (Caso medio)\n";
                cout << "Sua opção? : ";
                cin >> opcao_preordenacao;  // Lê a escolha de pré-ordenação

                cin.ignore();  // Limpa o buffer do cin
                if (opcao_preordenacao <= 2 && opcao_preordenacao >= 1) {  // Verifica se a opção é válida
                    break;  // Sai do loop se a opção estiver correta
                }
            }

            // Gera a lista com base no tamanho e na pré-ordenação escolhidos
            int* lista = GerarLista(tamanho, opcao_preordenacao);

            int opcao_imprimir;
            cout << "Deseja imprimir a lista? (0 para não, 1 para sim): ";
            cin >> opcao_imprimir;  // Pergunta se o usuário deseja imprimir a lista gerada

            cout << "\n";
            if(opcao_imprimir){
                (void)system("clear");  // Limpa a tela
                imprimirLista(lista, tamanho);  // Imprime a lista se o usuário escolheu a opção 1
                cout << "\n\n";
            }

            int opcao_Alg = 0;  // Variável para armazenar a escolha do algoritmo de ordenação
            while (true) {
                cout << "3° Fase: Escolha do algoritmo de ordenação da lista\n";
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
                cout << "1 - Bubble Sort\n";
                cout << "2 - Quick Sort\n";
                cout << "3 - Merge Sort\n";
                cout << "4 - Radix Sort\n";
                cout << "Sua opção? : ";
                cin >> opcao_Alg;  // Lê a escolha do algoritmo de ordenação

                cin.ignore();  // Limpa o buffer do cin
                if (opcao_Alg <= 4 && opcao_Alg >= 1) {  // Verifica se a opção é válida
                    break;  // Sai do loop se a opção estiver correta
                }
            }

            // Chama a função para ordenar a lista usando o algoritmo escolhido
            ordenarLista(lista, opcao_Alg, tamanho);

            cout << "\nOrdenação Completa!";
            cout << "\nDeseja imprimir a lista? (0 para não, 1 para sim): ";
            cin >> opcao_imprimir;  // Pergunta se o usuário deseja imprimir a lista ordenada
            if(opcao_imprimir){
                cout << "\n";
                imprimirLista(lista, tamanho);  // Imprime a lista ordenada se o usuário escolheu a opção 1
                cout << "\n";
            }

            break;  // Sai do case 1 após finalizar o processo de ordenação
        }

        case 2: {  // Caso o usuário escolha sair do programa
            cout << "Obrigado por usar o programa!!\n";  // Mensagem de despedida
            opcao = 2;  // Atualiza a variável para sair do loop principal
            break;  // Sai do case 2
        }
        }
    }
    return 0;  // Retorna 0 indicando que o programa terminou com sucesso
}
