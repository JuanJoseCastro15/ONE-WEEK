#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Audio.hpp>

using namespace std;


class Novia {
private:
    int Confianza, Amor, Felicidad;
public:
    Novia() : Confianza(105), Amor(70), Felicidad(105) {}
    void modificarAmor(int valor) {
        Amor += valor;
    }

    void modificarConfianza(int valor) {
        Confianza += valor;

        if (Confianza > 150)
            Confianza = 150;

        if (Confianza < 0)
            Confianza = 0;
    }

    void modificarFelicidad(int valor) {
        Felicidad += valor;

        if (Felicidad > 150)
            Felicidad = 150;

        if (Felicidad < 0)
            Felicidad = 0;
    }

    void actualizarAmor() {

        Amor = 70 + ((Confianza - 100) + (Felicidad - 100)) / 2;

        if (Amor > 100)
            Amor = 100;

        if (Amor < 0)
            Amor = 0;
    }

    void mostrar() {
        cout << "Confianza: " << Confianza << endl;
        cout << "Felicidad: " << Felicidad << endl;
        cout << "Amor: " << Amor << endl;
    }

    //agregue esta funcion para ver si te terminan depues de tomar una decision

    bool relacionTerminada() const {
        return Amor < 60;
    }

    int getAmor() const { return Amor; }
    int getConfianza() const { return Confianza; }
    int getFelicidad() const { return Felicidad; }
};


class Jugador {
protected:
    int Atractivo, Carisma, Lealtad;

public:
    Jugador(int A, int C, int L) : Atractivo(A), Carisma(C), Lealtad(L) {}

    virtual int calcularFelicidad(int impact) {

        // si la respuesta es mala, se respeta el castigo
        if (impact < 0) {
            return impact;
        }

        return impact + (Carisma / 10);
    }

    virtual int calcularConfianza(int impact) {

        if (impact < 0) {
            return impact;
        }

        return impact + (Lealtad / 10);
    }

    void aplicarImpacto(Novia& novia, int impact) {
        int cambioConf = calcularConfianza(impact);
        int cambioFeli = calcularFelicidad(impact);

        novia.modificarConfianza(cambioConf);
        novia.modificarFelicidad(cambioFeli);
        novia.actualizarAmor();
    }
};


class Otaku : public Jugador {
public:
    Otaku() : Jugador(30, 70, 5) {}

    int calcularFelicidad(int impact) override {

        // habilidad especial balanceada
        return (impact + Carisma) / 3;
    }
};


class Toxico : public Jugador {
public:
    Toxico() : Jugador(80, 30, 5) {}

    int calcularFelicidad(int impact) override {

        if (impact < 0) {
            return impact;
        }

        return impact + (Atractivo / 10);
    }
};
class Gymrat : public Jugador {
public:
    Gymrat() : Jugador(90, 50, 5) {}
    int calcularFelicidad(int impact) override {

        if (impact < 0) {
            return impact;
        }

        return impact + (Atractivo / 10);
    }
};
class NPC : public Jugador {
public:
    NPC() : Jugador(50, 50, 5) {}
    int calcularFelicidad(int impact) override {

        if (impact < 0) {
            return impact;
        }

        return impact + (Atractivo / 10);
    }
};



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




struct Escenario {
    string pregunta;
    string op1, op2, op3, op4;
    int imp1, imp2, imp3, imp4;

};