#include <iostream>
#include <ctime>
using namespace std;


int main(){
    int tentativa=0;
    int corte=100;
    srand(time(NULL));
    int aleatorio = rand()%corte;
    int minimo = 0;
    int maximo = corte - 1;
    do{
        tentativa=rand()%(maximo-minimo+1)+minimo;
        cout << "Tentativa: " << tentativa << endl;
        if(tentativa>aleatorio){
            cout << "O numero é menor que a tentativa" << endl;
            maximo = tentativa - 1;
        }else if(tentativa<aleatorio){
            cout << "O numero é maior que a tentativa" << endl;
            minimo = tentativa + 1;
        }else{
            cout << "Parabens, voce acertou! O número era " << aleatorio << endl;
        }
    }while(tentativa!=aleatorio);

    return 0;
};
