#include <iostream>

using namespace std;

char jogo[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

int main() {
    do{
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << "[" << jogo[i][j] << "] ";
            }
            cout << "\n";
        }
        int linha, coluna;
        cout << "Jogador 1, entre com a linha (0-2): ";
        cin >> linha;
        cout << "Jogador 1, entre com a coluna (0-2): ";
        cin >> coluna;
        if (jogo[linha][coluna] == ' ') {
            jogo[linha][coluna] = 'X';
        } else {
            cout << "Posição já ocupada. Tente novamente." << endl;
            continue;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << "[" << jogo[i][j] << "] ";
            }
            cout << "\n";
        }
        cout << "Jogador 2, entre com a linha (0-2): ";
        cin >> linha;
        cout << "Jogador 2, entre com a coluna (0-2): ";
        cin >> coluna;
        if (jogo[linha][coluna] == ' ') {
            jogo[linha][coluna] = 'O';
        } else {
            cout << "Posição já ocupada. Tente novamente." << endl;
            continue;
        }

    }while();
    return 0;
}
