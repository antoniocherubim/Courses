#include <iostream>
#include <ctime>
using namespace std;

int input=0;
int aleatorio=0;

int main(){
    srand(time(NULL));
    rand();
    aleatorio = rand()%10;
    do{
        cout << "Digite um numero: ";
        cin >> input;
        if(input>aleatorio){
            cout << "O numero é maior que o sorteado" << endl;
        }else if(input<aleatorio){
            cout << "O numero é menor que o sorteado" << endl;
        }else{
            cout << "Parabens, voce acertou!" << endl;
        }
    }while(input!=aleatorio);

    return 0;
};