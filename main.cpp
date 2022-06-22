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
        int availableIndexes[1] = {1};

        bool debugModeEnabled = true;

        while (difficultySelected < 1 || difficultySelected > 3){
            system("cls");

            /// DESENHO DAS BORDAS
            cout<<"-------------------------------------------------------------------------------------------------------------------";
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            cout<<"-------------------------------------------------------------------------------------------------------------------";

            /// DESENHO DA CARTA
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
        }
        isPlaying = false;
    }
    return 0;
}
