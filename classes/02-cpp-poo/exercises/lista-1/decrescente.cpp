#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, e, n;
    int count=0;
    
    do{
        cout << "Digite um número inteiro positivo: ";
        cin >> n;
        if (count==0){
            a=n;
        }else if (count==1){
            if (n>a){
                b=a;
                a=n;
            }else{ 
                b=n;
            };
        }else if (count==2){
            if (n>a){
                c=b;
                b=a;
                a=n;
            }else if (n>b){
                c=b;
                b=n;
            }else{
                c=n;
            }
        }else if (count==3){
            if (n>a){
                d=c;
                c=b;
                b=a;
                a=n;
            }else if (n>b){
                d=c;
                c=b;
                b=n;
            }else if (n>c){
                d=c;
                c=n;
            }else{
                d=n;
            }
        }else if (count==4){
            if (n>a){
                e=d;
                d=c;
                c=b;
                b=a;
                a=n;
            }else if (n>b){
                e=d;
                d=c;
                c=b;
                b=n;
            }else if (n>c){
                e=d;
                d=c;
                c=n;
            }else if (n>d){
                e=d;
                d=n;
            }else{
                e=n;
            }
        }
        count++;
    }while(count<5);

    cout << "Os números em ordem decrescente são: " << a << ", " << b << ", " << c << ", " << d << ", " << e << endl;
    return 0;
}