#include <iostream>

using namespace std;

int i=0;

float media = 0;

int main(){
    int count = 0;
    do{
        cout << "Digite um numero: ";
        cin >> i;
        count++;
        media += i;
    }while(i>=0);
    media-=i;
    media=media/(count-1);
    cout << "A media é: " << media << endl;

    return 0;
};

