#include <iostream>

using namespace std;

int main() {
    int input = 0;
    
    do{
        srand(time(NULL));
        int vitoria = (rand() % 10)%2;
        int aleatorio = rand() % 10;
        cout << "Digite um numero: ";
        cin >> input;
        if (input >= 0) {
            if (((aleatorio + input) % 2) == vitoria) {
                cout << "Parabens, voce ganhou!" << endl;
            } else {
                cout << "Voce perdeu!" << endl;
            }
        } else {
            cout << "Jogo encerrado!" << endl;
        }
    }while (input >= 0);
    
    return 0;
}