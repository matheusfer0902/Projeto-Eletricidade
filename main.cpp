#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;


long double calcula_com_unidade(float componente, int unidade){
    switch (unidade)
    {
    case 1:
        return componente * 10000000000000000;
        break;

    case 2:
        return componente * 1000000000000000;
        break;

    case 3:
        return componente * 1000000000000;
        break;

    case 4:
        return componente * 1000000000;
        break;

    case 5:
        return componente * 1000000;
        break;

    case 6:
        return componente * 1000;
        break;

    case 7:
        return componente * 100;
        break;

    case 8:
        return componente * 10;
        break;

    case 9:
        return componente * 0.1;
        break;

    case 10:
        return componente * 0.01;
        break;

    case 11:
        return componente * 0.001;
        break;

    case 12:
        return componente * 0.000001;
        break;

    case 13:
        return componente * 0.000000001;
        break;

    case 14:
        return componente * 0.000000000001;
        break;

    case 15:
        return componente * 0.000000000000001;
        break;

    case 16:
        return componente * 0.000000000000000001;
        break;
    
    default:
        break;
    }
}

void exibe_menu(){
    cout << "1 - exa(E) \n"
    "2 - peta(P) \n"
    "3 - tera(T) \n"
    "4 - giga(G) \n"
    "5 - mega(M) \n"
    "6 - quilo(k) \n"
    "7 - hecto(h) \n"
    "8 - deca(da) \n"
    "9 - deci(d) \n"
    "10 - centi(c) \n"
    "11 - mili(m) \n"
    "12 - micro(μ) \n"
    "13 - nano(n) \n"
    "14 - pico(p) \n"
    "15 - femto(f) \n"
    "16 - atto(a)" << endl;
}

int main(){
    long double resistor = 0;
    long double capacitor = 0;
    long double indutor = 0;
    int unidade = 0;


    cout << "-- BEM VINDO -- \n"
    // Para o resistor
    "Digite o valor do resistor: ";
    cin >> resistor;

    cout << "Diga a unidade do resistor: " << endl;
    exibe_menu();

    cin >> unidade;

    resistor = calcula_com_unidade(resistor, unidade);

    cout << "Valor do resistor: " << resistor << endl;

    //para o capacitor
    cout << "Digite o valor do capacitor: ";
    cin >> capacitor;

    cout << "Diga a unidade do capacitor: " << endl;
    exibe_menu();

    cin >> unidade;

    capacitor = calcula_com_unidade(capacitor, unidade);

    cout << "Valor do capacitor: " << capacitor << endl;

    //para o indutor
    cout << "Digite o valor do indutor: ";
    cin >> indutor;

    cout << "Diga a unidade do indutor: " << endl;
    exibe_menu();

    cin >> unidade;

    indutor = calcula_com_unidade(indutor, unidade);

    cout << "Valor do indutor: " << indutor << endl;

    return 0;
    
}