#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include <conio.h>
#include <stdlib.h>
#include "funcionesJuego.h"


using namespace std;

int main(){

    setlocale(LC_ALL, "spanish");
    system("color 4B");

    /// declaracion de variables globales

    const int nombres = 20, juegos=10, dados=5, limite=6;
    bool azar, jugadoJ1[juegos]={false},jugadoJ2[juegos]={false};
    int cant_jug, puntos_jug1=0, puntos_jug2=0, rondas, r;
    int juegosJ1[juegos]={0},juegosJ2[juegos]={0}, dadosTUno[dados]={},dadosTDos[dados]={}, tiros_gen1=0,tiros_gen2=0;
    char nombre1[nombres], nombre2[nombres];

    /// Configuración de la partida

    menu(nombre1, nombre2, rondas, cant_jug, azar);

    switch(cant_jug){
    case 1:
        for(r=0;r<rondas;r++){
                tiros_gen1=0;
                cout << "RONDA:\t " << r+1 << "\t de " << nombre1 << endl<< endl<< endl<< endl;
                /// tiro los dados y consigo un vector final
            tirosDeJugador(puntos_jug1,nombre1,azar,rondas,dadosTUno,tiros_gen1);
                cout << endl;
                cout << endl;
            /// evaluo que juegos se arman con esos dados
            Evaluar_combinacion(nombre1,dadosTUno,dados,juegosJ1,jugadoJ1,tiros_gen1,puntos_jug1);
        }
        break;
    case 2:
        for(r=0;r<rondas;r++){
            tiros_gen1=0, tiros_gen2=0;;
                cout << "RONDA:\t " << r+1 << "\t de " << nombre1 << endl<< endl<< endl<< endl;
            tirosDeJugador(puntos_jug1,nombre1,azar,rondas,dadosTUno,tiros_gen1);
                cout << endl;
                cout << endl;
            Evaluar_combinacion(nombre1,dadosTUno,dados,juegosJ1,jugadoJ1,tiros_gen1,puntos_jug1);

            ///---------------- TIRADA JUGADOR 2 -----------------

                cout << "RONDA:\t " << r+1 << "\t de " << nombre2 << endl<< endl<< endl<< endl;
            tirosDeJugador(puntos_jug2,nombre2,azar,rondas,dadosTDos,tiros_gen2);
                cout << endl;
                cout << endl;
            Evaluar_combinacion(nombre2,dadosTDos,dados,juegosJ2,jugadoJ2,tiros_gen2,puntos_jug2);
        }
        break;
    default: cout << "Exceso de jugadores\n";
        break;
    } /// final switch

    if(puntos_jug1>puntos_jug2){
        cout << "GANO: " << nombre1 << " con un total de: " << puntos_jug1 << " puntos.";
    }

    if(puntos_jug1<puntos_jug2){
        cout << "GANO: " << nombre2 << " con un total de: " << puntos_jug2;
    }

return 0;
}
