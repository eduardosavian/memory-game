#include <iostream>
#include <locale.h>
#include <time.h>
#define TAMANHOMATRIZ  4 //Constante do tamanho da matriz

int main() {
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));

	int opcaoDoMenu = 0; //Declarando e inicializando os valores e matrizes

	int matrizDeJogo[TAMANHOMATRIZ][TAMANHOMATRIZ] = {};
	int matrizDeGabarito[TAMANHOMATRIZ][TAMANHOMATRIZ] = {};
	int matrizDeVerificacao[TAMANHOMATRIZ][TAMANHOMATRIZ] = {};

	int numeroDoTipoDeMatriz = 0;
	int numeroDeAcertos = 0;
	int numeroDeTentativas = 0;

	int posicaoDaLinhaDaTentativa1 = 0;
	int posicaoDaColunaDaTentativa1 = 0;
	int posicaoDaLinhaDaTentativa2 = 0;
	int posicaoDaColunaDaTentativa2 = 0;

	matrizDeJogo[0][0] = 2;
	matrizDeJogo[0][1] = 4;
	matrizDeJogo[0][2] = 8;
	matrizDeJogo[0][3] = 6;
	matrizDeJogo[1][0] = 1;
	matrizDeJogo[1][1] = 5;
	matrizDeJogo[1][2] = 7;
	matrizDeJogo[1][3] = 3;
	matrizDeJogo[2][0] = 5;
	matrizDeJogo[2][1] = 1;
	matrizDeJogo[2][2] = 6;
	matrizDeJogo[2][3] = 7;
	matrizDeJogo[3][0] = 4;
	matrizDeJogo[3][1] = 2;
	matrizDeJogo[3][2] = 8;
	matrizDeJogo[3][3] = 3;

	while (opcaoDoMenu != 3) {
		std::cout << " \nSelecione uma opção: \n\n 1-Jogar\n\n 2-Sobre\n\n 3-Fechar Jogo\n\n Escolha: ";
		std::cin >> opcaoDoMenu;
		system("cls");

		switch (opcaoDoMenu) {
		case 1:// Opcão da Matriz

			numeroDoTipoDeMatriz = rand() % 4;// Escolha aleatória do tipo de matriz

			switch (numeroDoTipoDeMatriz) {
			case 1:// Sem modificação
				for (int i = 0; i < TAMANHOMATRIZ; i++) {
					for (int j = 0; j < TAMANHOMATRIZ; j++) {
						matrizDeGabarito[i][j] = matrizDeJogo[i][j];
					}
				}
				break;
			case 2:// Transposta
				for (int i = 0; i < TAMANHOMATRIZ; i++) {
					for (int j = 0; j < TAMANHOMATRIZ; j++) {
						matrizDeGabarito[j][i] = matrizDeJogo[i][j];
					}
				}
				break;
			case 3:// Invertida por linha
				for (int i = 0; i < TAMANHOMATRIZ; i++) {
					for (int j = 0; j < TAMANHOMATRIZ; j++) {
						int numeroTemporario = matrizDeJogo[i][j];
						matrizDeGabarito[i][j] = matrizDeJogo[TAMANHOMATRIZ - i - 1][j];
					}
				}
				break;
			case 4:// Invertida por coluna
				for (int i = 0; i < TAMANHOMATRIZ; i++) {
					for (int j = 0; j < TAMANHOMATRIZ; j++) {
						int numeroTemporario = matrizDeJogo[i][j];
						matrizDeGabarito[i][j] = matrizDeJogo[i][TAMANHOMATRIZ - j - 1];
					}
				}
				break;
			}

			for (int i = 0; i < TAMANHOMATRIZ; i++) {//Configurar a matriz original para 0//
				for (int j = 0; j < TAMANHOMATRIZ; j++) {
					matrizDeJogo[i][j] = 0;
				}
			}

			// Print para ver o jogo e testar rápido

			/*std::cout << "\tJogo   \n\n   ";
			for (int i = 0; i < TAMANHOMATRIZ; i++) {
				for (int j = 0; j < TAMANHOMATRIZ; j++) {
					std::cout << "  " << matrizDeGabarito[i][j];
				}
				std::cout << "\n   ";
			}*/

			while (numeroDeAcertos < (TAMANHOMATRIZ * 2) && numeroDeTentativas < (TAMANHOMATRIZ * 6)) {//Loop do jogo enquanto não tiver acertado todos os pares (8), nem errado o número de tentativas (24)
				std::cout << "\n Você fez " << numeroDeTentativas << " tentativa(s) de 24 possíveis e possui " << numeroDeAcertos << " acerto(s).\n";
				std::cout << "\n\t   Jogo  \n   ";
				for (int i = 0; i < TAMANHOMATRIZ; i++) { //Loop para imprimir a matriz
					for (int j = 0; j < TAMANHOMATRIZ; j++) {
						std::cout << "   " << matrizDeJogo[i][j];
					}
					std::cout << "\n   ";
				}

				std::cout << "\n Selecione a linha(i) e a coluna (j) para virar duas posições dentre os números 1 a 4: \n Primeira posição de Linha: "; //Posições que o jogador vai escolher//
				std::cin >> posicaoDaLinhaDaTentativa1;
				std::cout << " Primeira posição de Coluna: ";
				std::cin >> posicaoDaColunaDaTentativa1;
				std::cout << " Segunda posição de linha: ";
				std::cin >> posicaoDaLinhaDaTentativa2;
				std::cout << " Segunda posição de Coluna: ";
				std::cin >> posicaoDaColunaDaTentativa2;

				posicaoDaLinhaDaTentativa1--; //Ajustando o index da posição relativa para o index em c++, começando em [0]
				posicaoDaColunaDaTentativa1--;
				posicaoDaLinhaDaTentativa2--;
				posicaoDaColunaDaTentativa2--;

				numeroDeTentativas++; //Aumentando o número de tentativas em 1

				matrizDeJogo[posicaoDaLinhaDaTentativa1][posicaoDaColunaDaTentativa1] = matrizDeGabarito[posicaoDaLinhaDaTentativa1][posicaoDaColunaDaTentativa1];
				matrizDeJogo[posicaoDaLinhaDaTentativa2][posicaoDaColunaDaTentativa2] = matrizDeGabarito[posicaoDaLinhaDaTentativa2][posicaoDaColunaDaTentativa2];
				system("cls");

				if ((posicaoDaLinhaDaTentativa1 == posicaoDaLinhaDaTentativa2 && posicaoDaColunaDaTentativa1 == posicaoDaColunaDaTentativa2) ||
					(matrizDeVerificacao[posicaoDaLinhaDaTentativa2][posicaoDaColunaDaTentativa2] == matrizDeGabarito[posicaoDaLinhaDaTentativa2][posicaoDaColunaDaTentativa2] || //Se 
						matrizDeVerificacao[posicaoDaLinhaDaTentativa1][posicaoDaColunaDaTentativa1] == matrizDeGabarito[posicaoDaLinhaDaTentativa1][posicaoDaColunaDaTentativa1])) {
					std::cout << "\n Jogada Inválida!";
				}
				else if (matrizDeGabarito[posicaoDaLinhaDaTentativa1][posicaoDaColunaDaTentativa1] == matrizDeGabarito[posicaoDaLinhaDaTentativa2][posicaoDaColunaDaTentativa2]) {
					matrizDeVerificacao[posicaoDaLinhaDaTentativa1][posicaoDaColunaDaTentativa1] = matrizDeJogo[posicaoDaLinhaDaTentativa1][posicaoDaColunaDaTentativa1];
					matrizDeVerificacao[posicaoDaLinhaDaTentativa2][posicaoDaColunaDaTentativa2] = matrizDeJogo[posicaoDaLinhaDaTentativa2][posicaoDaColunaDaTentativa2];

					numeroDeAcertos = numeroDeAcertos++; // Aumentando o número de acertos em 1
					std::cout << "\n Acertou!";
				}
				else {
					std::cout << "\n  Errou!\n\n  Jogo  \n\n  ";

					for (int i = 0; i < TAMANHOMATRIZ; i++) {
						for (int j = 0; j < TAMANHOMATRIZ; j++) {
							std::cout << "  " << matrizDeJogo[i][j];
						}
						std::cout << "\n  ";
					}
					std::cout << "\n  ";

					matrizDeJogo[posicaoDaLinhaDaTentativa1][posicaoDaColunaDaTentativa1] = 0;
					matrizDeJogo[posicaoDaLinhaDaTentativa2][posicaoDaColunaDaTentativa2] = 0;
				}

				system("pause");
				system("cls");
			}

			if (numeroDeAcertos == (TAMANHOMATRIZ * 2)) {
				std::cout << " Parabéns, você venceu o jogo! \n ";
			}
			else {
				std::cout << " Você perdeu, tente novamente! \n";
			}

			system("pause");
			system("cls");

		case 2:
			std::cout << " Jogo feito pelos estudantes da Universidade do Vale do Itajaí Eduardo Savian, João Dal bosco e Johann Waldrich em Novembro de 2021";
			std::cout << "\n\n Atividade da disciplina de Algoritmos e Programação do professor Rafael Ballottin Martins" << "\n\n";
		case 3:
			std::cout << "\n Você fechou o jogo! \n ";
			system("pause");
			break;
		default:
			std::cout << " Opção inválida! \n\n";
		}
	}
	return 0;
}
