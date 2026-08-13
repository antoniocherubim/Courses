#include <iostream>

using namespace std;

int main() {
    int input;
    cout << "Digite um número inteiro: ";
    cin >> input;
    int count = 0;
    int numero = 0;
    int aux = 1;
    do{
        numero = numero + aux;
        aux = numero - aux;
        cout << numero << endl;
        count++;

    }while (count < input);

    return 0;
}
