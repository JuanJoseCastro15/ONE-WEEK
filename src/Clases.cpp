#include <memory>
#include <iostream>
#include <string>
#include "Clases.h"

using namespace std;


Novia::Novia() : Confianza(105), Amor(70), Felicidad(105) {}

void Novia::modificarAmor(int valor) {
    Amor += valor;
}

void Novia::modificarConfianza(int valor) {
    Confianza += valor;

    if (Confianza > 150)
        Confianza = 150;

    if (Confianza < 0)
        Confianza = 0;
}

void Novia::modificarFelicidad(int valor) {
    Felicidad += valor;

    if (Felicidad > 150)
        Felicidad = 150;

    if (Felicidad < 0)
        Felicidad = 0;
}

void Novia::modificarFelicidad() {
    Felicidad += 1;
}

void Novia::actualizarAmor() {

    Amor = 70 + ((Confianza - 100) + (Felicidad - 100)) / 2;

    if (Amor > 100)
        Amor = 100;

    if (Amor < 0)
        Amor = 0;
}


void Novia::mostrarEstado() const {
    std::cout << "Amor: " << Amor << " | Confianza: " << Confianza << " | Felicidad: " << Felicidad << std::endl;
}

//agregue esta funcion para ver si te terminan depues de tomar una decision
bool Novia::relacionTerminada() const {
    return Amor < 60;
}

int Novia::getAmor() const { return Amor; }
int Novia::getConfianza() const { return Confianza; }
int Novia::getFelicidad() const { return Felicidad; }

Jugador::Jugador(int A, int C, int L) : Atractivo(A), Carisma(C), Lealtad(L) {}

int Jugador::calcularFelicidadC(int impact) {

    // si la respuesta es mala, se respeta el castigo
    if (impact < 0) {
        return impact;
    }

    return impact + (Carisma / 10);
}

int Jugador::calcularFelicidadA(int impact) {

    // si la respuesta es mala, se respeta el castigo
    if (impact < 0) {
        return impact;
    }

    return impact + (Atractivo / 10);
}

int Jugador::calcularConfianza(int impact) {

    if (impact < 0) {
        return impact;
    }

    return impact + (Lealtad / 10);
}

void Jugador::aplicarImpactoCarisma(Novia& novia, int impact) // funcion para aplicar correctamente el valor y hacer el cambio a la novia 
{
    int cambio = calcularFelicidadC(impact);

    novia.modificarFelicidad(cambio);
    novia.actualizarAmor();
}
void Jugador::aplicarImpactoAtractivo(Novia& novia, int impact)
{
    int cambio = calcularFelicidadA(impact);

    novia.modificarFelicidad(cambio);
    novia.actualizarAmor();
}
void Jugador::aplicarImpactoConfianza(Novia& novia, int impact) 
{
    int cambio = calcularConfianza(impact);

    novia.modificarConfianza(cambio);

    novia.actualizarAmor();
}


Otaku::Otaku() : Jugador(30, 70, 5) {}

int Otaku::calcularFelicidadC(int impact) {

   //cout << "*** Otaku::calcularFelicidadC ***" << endl;
    if (impact < 0) {
        return impact;
    } 

    return impact + (Carisma / 3);
}

int Otaku::calcularFelicidadA(int impact) {

   //cout << "*** Otaku::calcularFelicidadA ***" << endl;

    if (impact < 0) {
        return impact;
    }

    return impact + (Atractivo / 3);
}

int Otaku::calcularConfianza(int impact) {

   //cout << "*** Otaku::calcularConfianza ***" << endl;

    if (impact < 0) {
        return impact;
    }

    return impact + (Lealtad / 3);
}
Toxico::Toxico() : Jugador(80, 30, 5) {}

int Toxico::calcularFelicidadC(int impact) {

    //cout << "*** Toxico::calcularFelicidadC ***" << endl;

    if (impact < 0) {
        return impact;
    }

    return impact + (Carisma / 10);
}

int Toxico::calcularFelicidadA(int impact) {

    //cout << "*** Toxico::calcularFelicidadA ***" << endl;

    if (impact < 0) {
        return impact;
    }

    return impact + (Atractivo / 10);
}

int Toxico::calcularConfianza(int impact) {

   //cout << "*** Toxico::calcularConfianza ***" << endl;

    if (impact < 0) {
        return impact;
    }

    return impact + (Lealtad / 10);
}
Gymrat::Gymrat() : Jugador(90, 50, 5) {}

int Gymrat::calcularFelicidadC(int impact) {

    //cout << "*** Gymrat::calcularFelicidadC ***" << endl;

    if (impact < 0) {
        return impact;
    }

    return impact + (Carisma / 10);
}

int Gymrat::calcularFelicidadA(int impact) {

    //cout << "*** Gymrat::calcularFelicidadA ***" << endl;

    if (impact < 0) {
        return impact;
    }

    return impact + (Atractivo / 10);
}

int Gymrat::calcularConfianza(int impact) {

    //cout << "*** Gymrat::calcularConfianza ***" << endl;

    if (impact < 0) {
        return impact;
    }

    return impact + (Lealtad / 10);
}
NPC::NPC() : Jugador(50, 50, 5) {}

int NPC::calcularFelicidadC(int impact) {

    //cout << "*** NPC::calcularFelicidadC ***" << endl;

    if (impact < 0) {
        return impact;
    }

    return impact + (Carisma / 10);
}

int NPC::calcularFelicidadA(int impact) {

    //cout << "*** NPC::calcularFelicidadA ***" << endl;

    if (impact < 0) {
        return impact;
    }

    return impact + (Atractivo / 10);
}

int NPC::calcularConfianza(int impact) {

    //cout << "*** NPC::calcularConfianza ***" << endl;

    if (impact < 0) {
        return impact;
    }

    return impact + (Lealtad / 10);
}

// otaku carisma 70, atractivo 30, lealtad 5
// Toxico carisma 30, atractivo 80, lealtad 5
// Gymrat carisma 50, atractivo 90, lealtad 5
// NPC carisma 50, atractivo 50, lealtad 5
// Amor = Amor + ((confianza + felicidad) / tiempo);
// Amor = 70, solo de 0 a 100
// Confianza = 105, Felicidad 105; solo de 0 a 150.
// normalmente confianza sube 4,2,0,-4.
// felicidad puede subir 4,5,9,10,0,-4,-5,-9,-10.
//funcion otaku especial es porque tiene bajas medidas para felicidad con atractivo
//impacto en respuestas 5, 3, 0, -5