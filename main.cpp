#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <locale>

using namespace std;

int main()
{
    ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, A SEGUIR.
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    COORD coord;
    ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, ACIMA.

    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int difficultySelected = 0; /// Dificuldade maior = Menos tempo de revelação das cartas
    bool isPlaying = true; /// Loop principal
    bool debugModeEnabled = false; /// Informa geração de tabela ao começar o jogo

    while (isPlaying){
        cout << "Carregando.." << endl;

        int matrizOriginal[4][4] = {0};
        int matrizGabarito[4][4];
        int matrizJogo[4][4];

        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                matrizJogo[i][j] = -1; /// Valores não encontrados são definidos como -1 inicialmente
            }
        }
        /// TO-DO: será que tem problema definir a matrizJogo com {0}?

        int tentativasRestantes = 24, tentativasUtilizadas = 0, paresEncontrados = 0;

        while (difficultySelected < 1 || difficultySelected > 3){
            system("cls");

            /// DESENHO DAS BORDAS
            cout<<"-------------------------------------------------------------------------------------------------------------------";
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            cout<<"-------------------------------------------------------------------------------------------------------------------";

            /// DESENHO DO MENU
            coord.X = 35;    coord.Y = 8;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"Jogo da Memória";

            coord.X = 32;    coord.Y = 9;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"Escolha uma dificuldade:";

            coord.X = 37;    coord.Y = 11;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"1 - Fácil";

            coord.X = 37;    coord.Y = 12;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"2 - Médio";

            coord.X = 37;    coord.Y = 13;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"3 - Dificil";

            if (difficultySelected < 0 || difficultySelected > 3){ /// AVISO DE ENTRADA DE DADOS INVALIDA
                coord.X = 25;    coord.Y = 17;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                cout<<"Dificuldade invalida, digite novamente";
            }

            if (debugModeEnabled == false){ /// AVISO DE DEBUG ATIVADO
                coord.X = 1;    coord.Y = 1;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                cout<<"          ";
            } else {
                coord.X = 1;    coord.Y = 1;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                cout<<"MODO DEBUG";
            }

            coord.X = 25;    coord.Y = 20;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"Herick Bittencourt e Vinicius Ribeiro";

            coord.X = 40;    coord.Y = 19;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"2022";

            /// DESENHO DA CARTA (ASCII Art do Menu)
            coord.X = 80;    coord.Y = 1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<" _______________________ " << endl;

            coord.Y = coord.Y+1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"|       ________        |" << endl;

            coord.Y = coord.Y+1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"|   _jgN########Ngg_    |" << endl;

            coord.Y = coord.Y+1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"| _N##N@@""      ""9NN##Np_ |" << endl;

            coord.Y = coord.Y+1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"|d###P           N####p |" << endl;

            coord.Y = coord.Y+1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"| ^^               T####|" << endl;

            coord.Y = coord.Y+1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"|                  d###P|" << endl;

            coord.Y = coord.Y+1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"|               _g###@F |" << endl;

            coord.Y = coord.Y+1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"|              _gN##@P  |" << endl;

            coord.Y = coord.Y+1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"|             gN####F   |" << endl;

            coord.Y = coord.Y+1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"|            d###F      |" << endl;

            for (int i = 0; i < 3; i++){
                coord.Y = coord.Y+1;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                cout<<"|           0###F       |" << endl;
            }

            coord.Y = coord.Y+1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"|           \"NN@'       |" << endl;

            coord.Y = coord.Y+1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"|                       |" << endl;

            coord.Y = coord.Y+1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"|            ___        |" << endl;

            coord.Y = coord.Y+1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"|           q###r       |" << endl;

            coord.Y = coord.Y+1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"|            \"\"         |" << endl;

            coord.Y = coord.Y+1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"|_______________________|" << endl;

            coord.X = 42;    coord.Y = 15;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cin >> difficultySelected; /// ENTRADA DE DADOS

            if (difficultySelected == 256){ /// LEITURA PARA DEBUG MODE
                difficultySelected = 0;
                if (debugModeEnabled == false){
                    debugModeEnabled = true;
                } else {
                    debugModeEnabled = false;
                }
            }
        }

        int randX = 0, randY = 0;
        for (int i = 1; i <= 8; i++){ /// POSICIONAMENTO ALEATÓRIO DE PARES NA MATRIZ ORIGINAL
            system("cls");

            coord.X = 35;    coord.Y = 8;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<< "Aleatorizando número: " << i;
            int numbersPlaced = 0;
            do{
                randX = rand()%4;
                randY = rand()%4;
                if (matrizOriginal[randX][randY] == 0){ /// Coordenada livre?
                    matrizOriginal[randX][randY] = i;
                    numbersPlaced++;
                }
            } while(numbersPlaced < 2); /// Repita até que seja colocado duas vezes
        }

        system("cls");

        coord.X = 35;    coord.Y = 8;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<< "Aleatorizando matriz..";
        int tipoMatriz = 1 + rand()%4;

        switch (tipoMatriz){ /// CRIAÇÃO DA MATRIZ GABARITO
        default: /// Normal
            for (int i = 0; i < 4; i++){
                for (int j = 0; j < 4; j++){
                    matrizGabarito[i][j] = matrizOriginal[i][j];
                }
            }
            break;
        case 2: /// Transposta
            for (int i = 0; i < 4; i++){
                for (int j = 0; j < 4; j++){
                    matrizGabarito[i][j] = matrizOriginal[j][i];
                }
            }
            break;
        case 3: /// Invertida por linha
            for (int i = 0; i < 4; i++){
                for (int j = 0; j < 4; j++){
                    switch (i){
                    case 0:
                        matrizGabarito[3][j] = matrizOriginal[i][j];
                        break;
                    case 1:
                        matrizGabarito[2][j] = matrizOriginal[i][j];
                        break;
                    case 2:
                        matrizGabarito[1][j] = matrizOriginal[i][j];
                        break;
                    case 3:
                        matrizGabarito[0][j] = matrizOriginal[i][j];
                        break;
                    }
                }
            }
            break;
        case 4: /// Invertida por coluna
            for (int i = 0; i < 4; i++){
                for (int j = 0; j < 4; j++){
                    switch (j){
                    case 0:
                        matrizGabarito[i][3] = matrizOriginal[i][j];
                        break;
                    case 1:
                        matrizGabarito[i][2] = matrizOriginal[i][j];
                        break;
                    case 2:
                        matrizGabarito[i][1] = matrizOriginal[i][j];
                        break;
                    case 3:
                        matrizGabarito[i][0] = matrizOriginal[i][j];
                        break;
                    }
                }
            }
            break;
        }

        system("cls");
        if (debugModeEnabled == true){ /// DEMONSTRAÇÃO DA GERAÇÃO
            cout << "Tipo de matriz gabarito: " << tipoMatriz << endl << endl << "Original: " << endl;
            for (int i = 0; i < 4; i++){
                for (int j = 0; j < 4; j++){
                    cout << matrizOriginal[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl << "Modificada: " << endl;
            for (int i = 0; i < 4; i++){
                for (int j = 0; j < 4; j++){
                    cout << matrizGabarito[i][j] << " ";
                }
                cout << endl;
            }
            system("pause");
            system("cls");
        }

        /// DESENHO DAS BORDAS
        cout<<"-------------------------------------------------------------------------------------------------------------------";
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"-------------------------------------------------------------------------------------------------------------------";

        /// DESENHO DA TABELA
        coord.X = 50;    coord.Y = 6;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<" ______________ " << endl;

        for (int i = 0; i < 8; i++){
            coord.Y = coord.Y+1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"|              |" << endl;
        }

        coord.Y = coord.Y+1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<"|______________|" << endl;

        string errorType = "";
        while (paresEncontrados < 8 && tentativasRestantes > 0){ /// LOOP DO JOGO
            coord.X = 53;    coord.Y = 8;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            for (int i = 0; i < 4; i++){ /// DESENHO DAS CARTAS
                for (int j = 0; j < 4; j++){
                    if (matrizJogo[i][j] == -1){ /// CARTA CUJO PAR NÃO FOI ENCONTRADO
                        cout << "?  ";
                    } else { /// CARTA COM PAR ENCONTRADO
                        cout << matrizJogo[i][j] << "  ";
                    }
                }
                coord.Y += 2; /// POSICIONAMENTO DAS CARTAS A CADA LINHA
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            }

            /// DESENHO DA UI (User Interface)
            coord.X = 51;    coord.Y = 2;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"Jogo da Memória";

            coord.X = 48;    coord.Y = 4;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"Jogadas realizadas: " << tentativasUtilizadas << "   ";

            coord.X = 47;    coord.Y = 5;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"Tentativas restantes: " << tentativasRestantes << "   ";

            coord.X = 48;    coord.Y = 20;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"Pares encontrados: " << paresEncontrados;

            int chosenCoordinates[2][2] = {0}; /// MATRIZ DE ESCOLHA DAS CARTAS (Cada linha = 1 carta)
            if (errorType != ""){ /// DISPLAY DE AVISOS EXTRAS, CASO EXISTAM
                coord.X = 70;    coord.Y = 11;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                cout << "                                             "; /// LIMPEZA DA ÁREA DE AVISOS (EVITAR SOBREPOSIÇÃO)

                coord.X = 70;    coord.Y = 11;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                cout << errorType;
                errorType = "";
            }
            for (int i = 0; i < 2; i++){ /// ESCOLHA DE CARTAS
                for (int j = 0; j < 2; j++){
                    do { /// LOOP DE ESCOLHA DA COORDENADA
                        coord.X = 45;    coord.Y = 17;
                        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                        cout<<"Escolha a ";
                        switch (j){ /// DISPLAY BASEADO NA COLUNA SENDO LIDA PELO FOR LOOP
                        case 0:
                            cout << "linha da " << i+1 << "° carta ";
                            break;

                        case 1:
                            cout << "coluna da " << i+1 << "° carta";
                            break;
                        }

                        if (chosenCoordinates[i][j] < 0 || chosenCoordinates[i][j] > 4){ /// DISPLAY DE ESCOLHA INVALIDA
                            coord.X = 70;    coord.Y = 11;
                            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                            cout << "                                             ";

                            coord.X = 70;    coord.Y = 11;
                            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                            cout << "Opção invalida, tente novamente";
                        }

                        coord.X = 58;    coord.Y = 18;
                        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                        cout<<"            "; /// Limpeza da área de entrada de dados no display

                        coord.X = 58;
                        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                        while(kbhit()) getch(); /// Solução para buffer não-intencional

                        cin >> chosenCoordinates[i][j];
                    } while (chosenCoordinates[i][j] < 1 || chosenCoordinates[i][j] > 4);
                }
            }

            /// Correção das entradas de dados p/ evitar Buffer Overflow (https://pt.wikipedia.org/wiki/Transbordamento_de_dados)
            for (int i = 0; i < 2; i++){
                for (int j = 0; j < 2; j++){
                    chosenCoordinates[i][j]--;
                }
            }

            /// DEFINIÇÃO DAS COORDENADAS ESCOLHIDAS (Legibilidade) (https://cdn.discordapp.com/attachments/798379839878201374/989876654740471808/unknown.png)
            int Escolha_1x = chosenCoordinates[0][0];
            int Escolha_1y = chosenCoordinates[0][1];
            int Escolha_2x = chosenCoordinates[1][0];
            int Escolha_2y = chosenCoordinates[1][1];

            /// Buffer para os valores da matriz jogo (evita bug de "desrevelação")
            int OriginalValues[2] = {matrizJogo[Escolha_1x][Escolha_1y], matrizJogo[Escolha_2x][Escolha_2y]};

            /// REVELAÇÃO DAS CARTAS
            matrizJogo[Escolha_1x][Escolha_1y] = matrizGabarito[Escolha_1x][Escolha_1y];
            matrizJogo[Escolha_2x][Escolha_2y] = matrizGabarito[Escolha_2x][Escolha_2y];

            coord.X = 53;    coord.Y = 8;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            for (int i = 0; i < 4; i++){ /// RE-DESENHANDO CARTAS (REVELANDO AS CARTAS ESCOLHIDAS)
                for (int j = 0; j < 4; j++){
                    if (matrizJogo[i][j] == -1){
                        cout << "?  ";
                    } else {
                        cout << matrizJogo[i][j] << "  ";
                    }
                }
                coord.Y += 2;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            }

            coord.X = 70;    coord.Y = 13;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout << "Revelando..";
            switch (difficultySelected){ /// Dificuldade -> Tempo de revelação
            case 1:
                Sleep(2000);
                break;
            case 2:
                Sleep(1500);
                break;
            case 3:
                Sleep(1250);
                break;
            }
            coord.X = 70;    coord.Y = 13;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout << "           ";

            /// REVERTER REVELAÇÃO
            matrizJogo[Escolha_1x][Escolha_1y] = OriginalValues[0];
            matrizJogo[Escolha_2x][Escolha_2y] = OriginalValues[1];

            /// RESULTADO
            if (matrizGabarito[Escolha_1x][Escolha_1y] == matrizGabarito[Escolha_2x][Escolha_2y]){ /// Cartas escolhidas são pares?
                if (Escolha_1x != Escolha_2x || Escolha_1y != Escolha_2y){ /// Cartas são diferentes?
                    if (matrizJogo[Escolha_1x][Escolha_1y] == -1 && matrizJogo[Escolha_2x][Escolha_2y] == -1){ /// Cartas são pares novos?
                        paresEncontrados++;
                        errorType = "Você encontrou um par! :)";
                        matrizJogo[Escolha_1x][Escolha_1y] = matrizGabarito[Escolha_1x][Escolha_1y];
                        matrizJogo[Escolha_2x][Escolha_2y] = matrizGabarito[Escolha_2x][Escolha_2y];
                    } else {
                        errorType = "Esse par escolhido já foi revelado!";
                    }

                } else {
                    errorType = "Você não pode escolher a mesma carta!";
                }

            } else {
                errorType = "Você não achou o par :(";
            }

            /// CONTAR TENTATIVA FEITA
            tentativasRestantes--;
            tentativasUtilizadas++;
        }
        /// JOGO ENCERRADO

        system("cls");
        /// DESENHO DAS BORDAS
        cout<<"-------------------------------------------------------------------------------------------------------------------";
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"-------------------------------------------------------------------------------------------------------------------";

        coord.Y = 8;
        if (paresEncontrados >= 8){ /// CONCLUSÃO
            coord.X = 51;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"Você encontrou todos os pares!";
        } else {
            coord.X = 45;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"Você não encontrou todos os pares :(";
        }

        /// DESENHO DAS ESCOLHAS
        coord.X = 51;    coord.Y = 9;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<"O que deseja fazer?";

        coord.Y = 11;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<"1 - Tentar denovo";

        coord.Y++;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<"2 - Voltar ao menu";

        coord.Y++;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<"3 - Sair";

        int endChosenOption = 0;

        do { /// LOOP DE ESCOLHA FINAL
            coord.X = 60;    coord.Y += 2;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout << "         ";

            coord.X = 60;    coord.Y += 2;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            while(kbhit()) getch(); /// Solução para buffer não-intencional
            cin >> endChosenOption;

            if (endChosenOption < 0 || endChosenOption > 3) {
                coord.X = 70;    coord.Y = 11;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                cout << "Opção invalida, tente novamente";
            }
        } while (endChosenOption < 1 || endChosenOption > 3);

        switch (endChosenOption){
        case 2: /// Voltar ao menu
            difficultySelected = 0;
            debugModeEnabled = false;
            break;
        case 3: /// Sair
            isPlaying = false;
            break;
        }
    }
    return 0;
}
