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

    int difficultySelected = 0;
    bool isPlaying = true;

    while (isPlaying){
        cout << "Carregando.." << endl;

        int matrizOriginal[4][4] = {0};
        int matrizGabarito[4][4];
        int matrizJogo[4][4];

        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                matrizJogo[i][j] = -1;
            }
        }

        int tentativasRestantes = 0, tentativasUtilizadas = 0, paresEncontrados = 0;

        bool debugModeEnabled = true;

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

            if (difficultySelected < 0 || difficultySelected > 3){
                coord.X = 25;    coord.Y = 17;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                cout<<"Dificuldade invalida, digite novamente";
            }

            coord.X = 25;    coord.Y = 20;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"Herick Bittencourt e Vinicius Ribeiro";

            coord.X = 40;    coord.Y = 19;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"2022";

            /// DESENHO DA CARTA
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
            cin >> difficultySelected;
        }

        switch (difficultySelected){
        case 1:
            tentativasRestantes = 24;
            break;
        case 2:
            tentativasRestantes = 18;
            break;
        case 3:
            tentativasRestantes = 11;
            break;
        }

        int randX = 0, randY = 0;
        for (int i = 1; i <= 8; i++){
            system("cls");

            coord.X = 35;    coord.Y = 8;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<< "Aleatorizando número: " << i;
            int numbersPlaced = 0;
            do{
                randX = rand()%4;
                randY = rand()%4;
                if (matrizOriginal[randX][randY] == 0){
                    matrizOriginal[randX][randY] = i;
                    numbersPlaced++;
                }
            } while(numbersPlaced < 2);
        }

        system("cls");

        coord.X = 35;    coord.Y = 8;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<< "Aleatorizando matriz..";
        int tipoMatriz = 1 + rand()%4;

        switch (tipoMatriz){
        default:
            for (int i = 0; i < 4; i++){
                for (int j = 0; j < 4; j++){
                    matrizGabarito[i][j] = matrizOriginal[i][j];
                }
            }
            break;
        case 2:
            for (int i = 0; i < 4; i++){
                for (int j = 0; j < 4; j++){
                    matrizGabarito[i][j] = matrizOriginal[j][i];
                }
            }
            break;
        case 3:
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
        case 4:
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
        if (debugModeEnabled == true){
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

        while (paresEncontrados < 8 && tentativasRestantes > 0){
            coord.X = 53;    coord.Y = 8;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            for (int i = 0; i < 4; i++){
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

            coord.X = 51;    coord.Y = 2;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"Jogo da Memória";

            coord.X = 48;    coord.Y = 4;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"Jogadas realizadas: " << tentativasUtilizadas << "   ";

            coord.X = 47;    coord.Y = 5;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"Tentativas restantes: " << tentativasRestantes << "   ";

            int chosenCoordinates[2][2] = {0};

            for (int i = 0; i < 2; i++){
                for (int j = 0; j < 2; j++){
                    do {
                        coord.X = 45;    coord.Y = 17;
                        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                        cout<<"Escolha a ";
                        switch (j){
                        case 0:
                            cout << "linha da " << i+1 << "° carta ";
                            break;

                        case 1:
                            cout << "coluna da " << i+1 << "° carta";
                            break;
                        }

                        if (chosenCoordinates[i][j] < 0 || chosenCoordinates[i][j] > 4){
                            coord.X = 44;    coord.Y = 20;
                            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                            cout<<"Opção invalida, tente novamente";
                        } else {
                            coord.X = 44;    coord.Y = 20;
                            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                            cout<<"                                                  ";
                        }

                        coord.X = 58;    coord.Y = 18;
                        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                        cout<<"            ";
                        coord.X = 58;
                        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                        cin >> chosenCoordinates[i][j];
                    } while (chosenCoordinates[i][j] < 1 || chosenCoordinates[i][j] > 4);
                }
            }

            for (int i = 0; i < 2; i++){
                for (int j = 0; j < 2; j++){
                    chosenCoordinates[i][j]--;
                }
            }

            matrizJogo[chosenCoordinates[0][0]][chosenCoordinates[0][1]] = matrizGabarito[chosenCoordinates[0][0]][chosenCoordinates[0][1]];
            matrizJogo[chosenCoordinates[1][0]][chosenCoordinates[1][1]] = matrizGabarito[chosenCoordinates[1][0]][chosenCoordinates[1][1]];

            coord.X = 53;    coord.Y = 8;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            for (int i = 0; i < 4; i++){
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

            Sleep(500);

            matrizJogo[chosenCoordinates[0][0]][chosenCoordinates[0][1]] = -1;
            matrizJogo[chosenCoordinates[1][0]][chosenCoordinates[1][1]] = -1;

            if (matrizGabarito[chosenCoordinates[0][0]][chosenCoordinates[0][1]] == matrizGabarito[chosenCoordinates[1][0]][chosenCoordinates[1][1]]){
                if (chosenCoordinates[0][0] != chosenCoordinates[1][0] || chosenCoordinates[0][1] != chosenCoordinates[1][1]){
                    if (matrizJogo[chosenCoordinates[0][0]][chosenCoordinates[0][1]] == -1 && matrizJogo[chosenCoordinates[1][0]][chosenCoordinates[1][1]] == -1){
                        tentativasRestantes += 1000;
                        matrizJogo[chosenCoordinates[0][0]][chosenCoordinates[0][1]] = matrizGabarito[chosenCoordinates[0][0]][chosenCoordinates[0][1]];
                        matrizJogo[chosenCoordinates[1][0]][chosenCoordinates[1][1]] = matrizGabarito[chosenCoordinates[1][0]][chosenCoordinates[1][1]];
                    }
                }
            }
            tentativasRestantes--;
            tentativasUtilizadas++;
        }
        isPlaying = false;
    }
    return 0;
}
