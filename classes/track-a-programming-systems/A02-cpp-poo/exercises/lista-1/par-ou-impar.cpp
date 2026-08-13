#include <iostream>

using namespace std;

int valor=0;

int main(){
    do{
        cout << "Digite um numero: ";
        cin >> valor;
        
        if (valor%2==0){
            cout << "O numero é par" << endl;
        }else{
            cout << "O numero é impar" << endl;
        }
    }while(valor!=0);

    return 0;
};