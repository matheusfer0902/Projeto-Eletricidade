#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <cmath>
#include <stdlib.h>

using namespace std;


long double calcula_com_unidade(long double componente, int unidade){
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
    
    case 17:
        return componente * 1;
    
    default:
        break;
    }
}

void exibe_menu_unidade(){
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
    "16 - atto(a) \n"
    "17 - Usar padrao (SI). " << endl;
}

long double calcula_sigma(long double resistor, long double capacitor){
    return 1/(2*resistor*capacitor);
}

long double calcula_omega0(long double indutor, long double capacitor){
    return 1/(sqrt(indutor*capacitor));
}

long double calcula_omegaD(long double sigma, long double omega0){
    return sqrt((omega0*omega0)-(sigma*sigma));
}

void exibe_tipo_circuito(long double sigma, long double omega0){
    if((sigma*sigma) > (omega0*omega0)){
        cout << "Circuito super amortecido" << endl;
    } else if ((sigma*sigma) == (omega0*omega0)){
        cout << "Circuito criticamente amortecido" << endl;
    } else {
        cout << "Circuito subamortecido" << endl;
    }
}

int testa_subamortecido(long double sigma, long double omega0){
    if((omega0*omega0) > (sigma*sigma)){
        return 1;
    } else { 
        return 0;
    }
}

void exibe_sigma_omega0_omegaD(long double sigma, long double omega0, long double omegaD){
    cout << "Valor de sigma: " << sigma << endl;
    cout << "Valor de omega_0: " << omega0 << endl;
    if(testa_subamortecido(sigma, omega0)){
        cout << "Valor de omega_D: " << omegaD << endl;
    }
}

long double calcula_corrente_resistor(long double resistor, long double tensao){
    return (tensao)/(resistor);
}

long double calcula_corrente_capacitor(long double corrente_resistor, long double corrente_indutor){
    corrente_resistor = corrente_resistor - 2*corrente_resistor;
    if(corrente_indutor < 0 && corrente_resistor < 0){
        return (corrente_indutor + corrente_resistor);
    } else if(corrente_indutor > 0 && corrente_resistor > 0){
        return corrente_indutor + corrente_resistor;
    } else if (corrente_indutor < 0 && corrente_resistor > 0){
        return corrente_resistor - corrente_indutor;
    } else if (corrente_indutor > 0 && corrente_resistor < 0){
        return corrente_indutor + corrente_resistor;
    } else if (corrente_indutor == 0 && corrente_resistor != 0){
        return corrente_resistor;
    } else if (corrente_indutor != 0 && corrente_resistor ==0){
        return corrente_indutor;
    }
}

long double calculo_para_b2(long double corrente_capacitor, long double capacitor, long double b1, long double omegaD, long double sigma){
    long double primeira_parte = (corrente_capacitor/capacitor);
    long double multi = (b1*sigma) - 2*(b1*sigma);
    if(multi < 0){
        if(multi < primeira_parte){
            return (primeira_parte + multi)/omegaD;
        } else {
            return (multi + primeira_parte)/omegaD;
        }
    } else if (multi == 0 && primeira_parte != 0){
        return primeira_parte/omegaD;
    } else if (multi != 0 && primeira_parte == 0){
        return multi/omegaD;
    } else if (multi == primeira_parte){
        return 0;
    }
    /*if(multi < 0 && primeira_parte < 0){
        if(multi < primeira_parte){
            return (primeira_parte - multi)/omegaD;
        } else {
            return (multi - primeira_parte)/omegaD;
        }
    } else if (multi > 0 && primeira_parte > 0){
        return (multi + primeira_parte)/omegaD;
    } else if (multi < 0 && primeira_parte > 0){
        return (primeira_parte - multi)/omegaD;
    } else if (multi > 0 && primeira_parte < 0){
        return (multi - primeira_parte)/omegaD;
    } else if (multi == 0 && primeira_parte != 0){
        return primeira_parte/omegaD;
    } else if (multi != 0 && primeira_parte == 0){
        return multi/omegaD;
    } else if (multi == primeira_parte){
        return 0;
    }*/
}

void exibe_b1_b2(long double b1, long double b2, long double sigma, long double omegaD){
    if(b1 < 0){
        if(b2 < 0){
            cout << "v(t) = e^(-" << sigma << "t) * ( -" << b1 << "cos(" << omegaD << "t) - " << b2 << "sen(" << omegaD << "t)) (V)" << endl;
        } else if(b2 > 0){
            cout << "v(t) = e^(-" << sigma << "t) * ( -" << b1 << "cos(" << omegaD << "t) + " << b2 << "sen(" << omegaD << "t)) (V)" << endl;
        } else if(b2 == 0) {
            cout << "v(t) = e^(-" << sigma << "t ) * ( - " << b1 << "cos(" << omegaD << "t)) (V)" << endl;
        }
    } else if(b1 == 0){
        if(b2 < 0){
            cout << "v(t) = e^(-" << sigma << "t) * ( -" << b2 << "sen(" << omegaD << "t)) (V)" << endl;
        } else if(b2 > 0){
            cout << "v(t) = e^(-" << sigma << "t) * ( " << b2 << "sen(" << omegaD << "t)) (V)" << endl;
        } else if (b2 == 0){
            cout << "b1 e b2 sao 0" << endl;
        }
    } else if( b1 > 0){
        if(b2 < 0){
            cout << "v(t) = e^(-" << sigma << "t) * ( " << b1 << "cos(" << omegaD << "t) - " << b2 << "sen(" << omegaD << "t)) (V)" << endl;
        } else if(b2 > 0){
            cout << "v(t) = e^(-" << sigma << "t) * ( " << b1 << "cos(" << omegaD << "t) + " << b2 << "sen(" << omegaD << "t)) (V)" << endl;
        } else if (b2 == 0){
            cout << "v(t) = e^(+" << sigma << "t) * ( " << b1 << "cos(" << omegaD << "t)) (V)" << endl;
        }
            
    }
}

int calcula_circuito(long double sigma, long double omega0, long double omegaD, long double vc_0, long double il_0, long double resistor, long double capacitor, long double indutor){
    const long double epsilon = 4.94065645841247E-324;
    
    if((omega0*omega0) > (sigma*sigma)){ // subamortecido
        
        long double corrente_resistor = 0;
        long double corrente_capacitor = 0;
        
        long double b1 = vc_0, b2 = 0;
        corrente_resistor = calcula_corrente_resistor(resistor, vc_0);
        corrente_capacitor = calcula_corrente_capacitor(corrente_resistor, il_0);
        cout << "Corrente capacitor: " << corrente_capacitor << endl;
        b2 = calculo_para_b2(corrente_capacitor, capacitor, b1, omegaD, sigma);

        cout << "Valor de b1: " << b1 << endl;
        cout << "Valor de b2: " << b2 << endl;
        exibe_b1_b2(b1, b2, sigma, omegaD);

    } else if((omega0*omega0) == (sigma*sigma)){ // criticamente amortecido

    } else { // super amortecido

    }
}

void saida(long double sigma, long double omega0, long double omegaD, long double vc_0, long double il_0, long double resistor, long double capacitor, long double indutor){
    cout << "Autores: Matheus Ferreira, Matheus Mendonca" << endl;
    exibe_tipo_circuito(sigma, omega0);
    exibe_sigma_omega0_omegaD(sigma, omega0, omegaD);
    calcula_circuito(sigma, omega0, omegaD, vc_0, il_0, resistor, capacitor, indutor);
}

int main(){
    long double resistor = 0;
    long double capacitor = 0;
    long double indutor = 0;
    int unidade = 0;

    long double v_c0 = 0;
    long double i_l0 = 0;

    long double sigma = 0;
    long double omega0 = 0;
    long double omegaD = 0;

    cout << "-- BEM VINDO -- \n"
    // Para o resistor
    "Digite o valor do resistor: ";
    cin >> resistor;

    if(resistor != 0){
        cout << "Diga a unidade do resistor: " << endl;
        exibe_menu_unidade();
        cin >> unidade;

        if(unidade < 1 || unidade > 17){
            cout << "digite um valor valido. (numero entre 1 e 17)" << endl;
            return -1;
        }

        resistor = calcula_com_unidade(resistor, unidade);
    }

    system("clear||cls");

    //para o capacitor
    cout << "Digite o valor do capacitor: ";
    cin >> capacitor;

    if(capacitor != 0){
        cout << "Diga a unidade do capacitor: " << endl;
        exibe_menu_unidade();
        cin >> unidade;

        if(unidade < 1 || unidade > 17){
            cout << "digite um valor valido. (numero entre 1 e 17)" << endl;
            return -1;
        }

        capacitor = calcula_com_unidade(capacitor, unidade);
    }

    system("clear||cls");

    //para o indutor
    cout << "Digite o valor do indutor: ";
    cin >> indutor;

    if(indutor != 0){
        cout << "Diga a unidade do indutor: " << endl;
        exibe_menu_unidade();
        cin >> unidade;

        if(unidade < 1 || unidade > 17){
            cout << "digite um valor valido. (numero entre 1 e 17)" << endl;
            return -1;
        }

        indutor = calcula_com_unidade(indutor, unidade);
    }

    system("clear||cls");

    //v_c(0) no capacitor
    cout << "Digite o valor da tensao inicial do capacitor v_c(0): ";
    cin >> v_c0;

    if(v_c0 != 0){
        cout << "Diga a unidade da tensao inicial: " << endl;
        exibe_menu_unidade();
        cin >> unidade;

        if(unidade < 1 || unidade > 17){
            cout << "digite um valor valido. (numero entre 1 e 17)" << endl;
            return -1;
        }

        v_c0 = calcula_com_unidade(v_c0, unidade);
    }

    system("clear||cls");

    //i_l(0) no indutor
    cout << "Digite o valor da corrente inicial do indutor i_l(0): ";
    cin >> i_l0;

    if(i_l0 != 0){
        cout << "Diga a unidade da corrente inicial: " << endl;
        exibe_menu_unidade();
        cin >> unidade;

        if(unidade < 1 || unidade > 17){
            cout << "digite um valor valido. (numero entre 1 e 17)" << endl;
            return -1;
        }

        i_l0 = calcula_com_unidade(i_l0, unidade);
    }

    system("clear||cls");

    sigma = calcula_sigma(resistor, capacitor);
    omega0 = calcula_omega0(indutor, capacitor);
    omegaD = calcula_omegaD(sigma, omega0);

    saida(sigma, omega0, omegaD, v_c0, i_l0, resistor, capacitor, indutor);

    return 0;
    
}