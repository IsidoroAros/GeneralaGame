#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include <stdlib.h>
#include <conio.h>

using namespace std;

void tirarDados(int dados[], int cantDados, bool &azar);///asigna valores aleatorios a cada al vector, usar azar para tirar dados random o hacer cin

void mostrarVector(int v[], int tam);/// muestra lo que contiene cada una de las posiciones del vector

void cambioDados(int vec[], int tam, bool &azar); /// cambia los dados que el usuario desea

void menu(char *nombre1, char *nombre2, int &rondas,int &jugadores, bool &azar); /// muestra el menu en pantalla

void nombresJugadores(int cant_jug, char *nomb1, char *nomb2); /// segun la cantidad de jugadores pide uno o dos nombres

void tirosDeJugador(int &puntos_j1, char *nombre1, bool &azar, int &rondas, int *dadosJug, int &tiros_gen); /// si se decide jugar de a 1 se desarrolla el juego

void configurarPartida(int &rondas, bool &azar); /// configuracion de rondas y de partida aleatoria o no

void Evaluar_combinacion(char *nombJuga,int tiro[], int tam, int juegosJugador[], bool yaJugado[],int tiros_gen, int &puntos);

void Menu_combinaciones(char Nombre[], int tiro[], int Jugador[], bool Jugado[]);

void ordenarVector(int v[], int tam);

///------------------------------------------------------------------------------------------------------------------

void ordenarVector(int v[], int tam ){
    int i,j, posmin, aux;
    for(i=0;i<tam-1;i++){
        posmin=i;
        for(j=i+1;j<tam;j++){
            if(v[j]<v[posmin]) posmin=j;
        }
        aux=v[i];
        v[i]=v[posmin];
        v[posmin]=aux;
    }
}

void menu(char *nombre1, char *nombre2, int &rondas,int &jugadores, bool &azar){

    cout << endl;
    cout << "\t \t           ------------------BIENVENIDO A LA GENERALA------------------ \n";
    cout << endl;
    configurarPartida(rondas, azar);
    cout << "1 - UN JUGADOR\n";
    cout << "2- MULTIPLAYER\n";
    cin >> jugadores;
    cout << endl;
    nombresJugadores(jugadores, nombre1, nombre2);
    system("pause");
    system("cls");
}

void nombresJugadores(int jugadores, char *nombre1, char *nombre2){

   switch(jugadores){
    case 1:
        printf("Jugador 1: ");
        scanf("%s", nombre1);
    break;
    case 2:
        printf("Jugador 1: ");
        scanf("%s", nombre1);
        printf("Jugador 2: ");
        scanf("%s", nombre2);
    break;
    default:
        cout << "Ha superado el maximo de jugadores \n";
    break;
    }
}

void configurarPartida(int &rondas, bool &azar){

    int aleatorio;
    cout << "Rondas a jugar: ";
    cin >> rondas;
    cout << endl;
    cout << "¿Jugar con dados aleatorios? [1 - SI / 0 - NO]:\t";
    cin >> aleatorio;
    cout << endl;
        switch(aleatorio){
            case 1: azar = true;
            break;
            case 0: azar = false;
            break;
            default:
                cout << "OPCION INCORRECTA";
                cin >> aleatorio;
            break;
        }

}

void tirosDeJugador(int &puntos_j1, char *nombre1, bool &azar, int &rondas, int *dadosJug, int &tiros_gen){

    const int dados=5, limite=6, nombres=20, juegosPosibles = 11;
    bool consulta_dados, jugado[juegosPosibles]={false};
    int tiros=0, i,j, cant_jug;

            tiros=1, tiros_gen=0; /// reseteo de los tiros de generala y tiros de las rondas
    while(tiros!=4){
        switch(tiros){
            case 1:
                tirarDados(dadosJug,dados,azar);
                mostrarVector(dadosJug, dados);
                cout << endl;
                cout << "¿Desea volver a tirar los dados? (1 para si, 0 para no) \n";
                cin >> consulta_dados;
                system("pause");
                    if(consulta_dados==0){
                            tiros=4;
                            tiros_gen=1;
                            break;
                            } /// cortar los tiros de la ronda
                    if(consulta_dados==1){
                        tiros=2;
                        break;
                            }
                        break;
            case 2:
                mostrarVector(dadosJug, dados);
                cout << endl << endl << endl << endl;
                cambioDados(dadosJug, dados, azar);
                mostrarVector(dadosJug, dados);
                cout << endl;
                cout << "¿Desea cambiar los dados una vez mas? (1 para si, 0 para no) \n" << endl;
                cin >> consulta_dados;
                    if(consulta_dados==0){
                            tiros_gen=2;
                            tiros=4;
                            break;
                            } /// cortar los tiros de la ronda
                    if(consulta_dados==1){
                        tiros=3;
                        tiros_gen=3;
                            break;
                        }
            case 3:
                cout << endl;
                mostrarVector(dadosJug,dados);
                cout << endl << endl << endl << endl;
                cambioDados(dadosJug, dados, azar);
                tiros=4;
                tiros_gen=3;
                    break;
            default:
                    break;
            }/// final switch tiros
            system("cls");
        }
    }


void Evaluar_combinacion(char *nombJuga,int tiro[], int tam, int juegosJugador[], bool yaJugado[],int tiros_gen, int &puntos){
    const int t0=11;
    int Turno[t0]={0},y, I, Men, Max, t=0;

    ///cout<<"\n3 - ORDENO DE MENOR A MAYOR ";
    ordenarVector(tiro,tam);

        /// evaluacion de combinaciones posibles
        /// A=A=A=A=A SERVIDO
    if((tiro[0]==tiro[1]&&tiro[1]==tiro[2]&&tiro[2]==tiro[3]&&tiro[3]==tiro[4]) && tiros_gen<=1){
        Turno[11]+=100;
        }
    if((tiro[0]==tiro[1]&&tiro[1]==tiro[2]&&tiro[2]==tiro[3]&&tiro[3]==tiro[4]) && tiros_gen>1){
        Turno[9]+=50;
        } ///A=A=A=A=A
    if(( (tiro[0]==tiro[1]) && (tiro[2]==tiro[3]&&tiro[3]==tiro[4]) &&(tiro[0]!=tiro[2]) )||((tiro[0]==tiro[1]&&tiro[1]==tiro[2]) && (tiro[3]==tiro[4])&&(tiro[2]!=tiro[3]))){
        Turno[7]+=30;
        } /// A=A y B=B=B
    if(((tiro[1]==tiro[2]&&tiro[2]==tiro[3]&&tiro[3]==tiro[4])&&(tiro[4]!=tiro[0]))||((tiro[1]==tiro[2]&& tiro[2]==tiro[3]&&tiro[3]==tiro[0])&&(tiro[0]!= tiro[4]))){
        Turno[8]+=40;
        }  /// A y B=B=B=B
    if((tiro[0]==1&&tiro[1]==2&&tiro[2]==3&&tiro[3]==4&&tiro[4]==5)||(tiro[0]==2&&tiro[1]==3&&tiro[2]==4&&tiro[3]==5&&tiro[4]==6)){
        Turno[6]+=25;
        }

    for(int y=0; y<t0; y++){
        if(tiro[y]==1) {Turno[0]+=tiro[y];}
        if(tiro[y]==2) {Turno[1]+=tiro[y];}
        if(tiro[y]==3) {Turno[2]+=tiro[y];}
        if(tiro[y]==4) {Turno[3]+=tiro[y];}
        if(tiro[y]==5) {Turno[4]+=tiro[y];}
        if(tiro[y]==6) {Turno[5]+=tiro[y];}
    }
    /// BUSCO EL MAYOR RESULTADO DESCARTANDO EL jUGADO O YA COMPLETADO
    for(int z=0; z<t0; z++){
        if((z==0) && (yaJugado[z]==0)){
            Max=Turno[z];
            I=z;
        }
        else{
        if((Turno[z]>Max) && (yaJugado[z]==0)){
                Max=Turno[z];
                I=z;
                }
            }
        }

        juegosJugador[I]=Turno[I];
        yaJugado[I]=true;

        switch(I){
            case 0: cout<<"COMBINACION DE UNO" << endl; break;
            case 1: cout<<"COMBINACION DE DOS"<< endl; break;
            case 2: cout<<"COMBINACION DE TRES"<< endl; break;
            case 3: cout<<"COMBINACION DE CUATRO"<< endl; break;
            case 4: cout<<"COMBINACION DE CINCO"<< endl; break;
            case 5: cout<<"COMBINACION DE SEIS"<< endl; break;
            case 6: cout<<"ESCALERA"<< endl; break;
            case 7: cout<<"FULL"<< endl; break;
            case 8: cout<<"POKER"<< endl; break;
            case 9: cout<<"GENERALA"<< endl; break;
            case 11: cout<<"GENERALA SERVIDA"<< endl; break;
            }

        puntos+=juegosJugador[I];
        Menu_combinaciones(nombJuga,tiro,juegosJugador,yaJugado);

    system("pause");
    system("CLS");
}


void tirarDados(int dados[], int cantDados, bool &azar){
    int i;
    srand(time(NULL));
if (azar==true){
  for( i=0; i<cantDados; i++ ){
        dados[i]=1+(rand()%(6-1));
        }
    }
if(azar==false){
    for(i=0;i<cantDados;i++){
        cout << "Dado N" << i+1 << ":\t";
        cin >> dados[i];
        }
    }
}

void mostrarVector(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        cout << "Dado N" << i+1 << "\t" << v[i] << "\t"; /// \t sirve para tabular
    }
}

void cambioDados(int vec[], int tam, bool &azar){

    int i,dado, cambio_dado;
    if(azar==false){
    for(i=0;i<tam;i++){
        cout << "\t \t¿Desea volver a tirar el dado " << i+1 << "? (1 para si, 0 para no)\n";
        cin >> cambio_dado;
        if(cambio_dado==1){
        cout << "Dado " << i+1 << ":" << endl;
        cin >> vec[i];
                }
        }
    }
    if(azar==true){
    srand(time(NULL));
    for(i=0;i<tam;i++){
        cout << "\t \tDesea volver a tirar el dado " << i+1 << "? (1 para si, 0 para no)\n";
        cin >> cambio_dado;
        if(cambio_dado==1){
          vec[i]=1+(rand()%(6-1));
            }
        }
    }
    return;
}


void Menu_combinaciones(char Nombre[], int tiro[], int Jugador[], bool Jugado[]){

    int tama = 5;
    cout<<"\n Jugador: "<<Nombre << "\t";
    mostrarVector(tiro, tama);
    cout << endl << endl;
    cout<<"\n\t----------------------------------------------------";
    cout<<"\n\t     JUEGOS    |       PUNTAJE       |     JUGADO        ";
    cout<<"\n\t----------------------------------------------------\n";
    cout << endl;
    cout<<"\n\t    uno                    "<<Jugador[0]<<"\t\t"<<Jugado[0];
    cout<<"\n\t    dos                    "<<Jugador[1]<<"\t\t"<<Jugado[1];
    cout<<"\n\t    tres                   "<<Jugador[2]<<"\t\t"<<Jugado[2];
    cout<<"\n\t    cuatro                 "<<Jugador[3]<<"\t\t"<<Jugado[3];
    cout<<"\n\t    cinco                  "<<Jugador[4]<<"\t\t"<<Jugado[4];
    cout<<"\n\t    seis                   "<<Jugador[5]<<"\t\t"<<Jugado[5];
    cout<<"\n\t    escalera               "<<Jugador[6]<<"\t\t"<<Jugado[6];
    cout<<"\n\t    full                   "<<Jugador[7]<<"\t\t"<<Jugado[7];
    cout<<"\n\t    poker                  "<<Jugador[8]<<"\t\t"<<Jugado[8];
    cout<<"\n\t    generala               "<<Jugador[9]<<"\t\t"<<Jugado[9];
    cout<<"\n\t    g_servida              "<<Jugador[11]<<"\t\t"<<Jugado[11];
    cout << endl << endl << endl;
    system("PAUSE");
    system("CLS");
}



