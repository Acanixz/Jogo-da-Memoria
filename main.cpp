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

    int difficultySelected = 0;
    bool isPlaying = true;
    while (isPlaying){
        cout << "Carregando.." << endl;

        int MatrizOriginal[4][4] = {0};

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

        coord.X = 25;    coord.Y = 20;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<"Herick Bittencourt e Vinicius Ribeiro";

        coord.X = 40;    coord.Y = 19;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<"2022";

        coord.X = 70;    coord.Y = 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<" _______________________ " << endl;

        coord.X = 70;    coord.Y = coord.Y+1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<"|       ________        |" << endl;

        coord.X = 70;    coord.Y = coord.Y+1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<"|   _jgN########Ngg_    |" << endl;

        coord.X = 70;    coord.Y = coord.Y+1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<"| _N##N@@""      ""9NN##Np_ |" << endl;

        coord.X = 70;    coord.Y = coord.Y+1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<"|d###P           N####p |" << endl;

        coord.X = 70;    coord.Y = coord.Y+1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<"| ^^               T####|" << endl;

        coord.X = 70;    coord.Y = coord.Y+1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<"|                  d###P|" << endl;

        coord.X = 70;    coord.Y = coord.Y+1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<"|               _g###@F |" << endl;

        coord.X = 70;    coord.Y = coord.Y+1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<"|              _gN##@P  |" << endl;

        coord.X = 70;    coord.Y = coord.Y+1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<"|             gN####F   |" << endl;

        coord.X = 70;    coord.Y = coord.Y+1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<"|            d###F      |" << endl;

        for (int i = 0; i < 3; i++){
            coord.X = 70;    coord.Y = coord.Y+1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<"|           0###F       |" << endl;
        }

        coord.X = 70;    coord.Y = coord.Y+1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<"|           \"NN@'       |" << endl;

        coord.X = 70;    coord.Y = coord.Y+1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<"|                       |" << endl;

        coord.X = 70;    coord.Y = coord.Y+1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<"|            ___        |" << endl;

        coord.X = 70;    coord.Y = coord.Y+1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<"|           q###r       |" << endl;

        coord.X = 70;    coord.Y = coord.Y+1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<"|            \"\"         |" << endl;

        coord.X = 70;    coord.Y = coord.Y+1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<"|_______________________|" << endl;

        isPlaying = false;
    }
    return 0;
}
