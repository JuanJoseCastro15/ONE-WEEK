#pragma once

class Novia {
private:
    int Confianza, Amor, Felicidad;
public:
    Novia();

    void modificarAmor(int valor);

    void modificarConfianza(int valor);

    
    void modificarFelicidad(int valor);

    void modificarFelicidad();

    void actualizarAmor();

    //agregue esta funcion para ver si te terminan depues de tomar una decision

    bool relacionTerminada() const;

    int getAmor() const;
    int getConfianza() const;
    int getFelicidad() const;
};


class Jugador {
protected:
    int Atractivo, Carisma, Lealtad;

public:
    Jugador(int A, int C, int L);
    virtual ~Jugador() = default;

    virtual int calcularFelicidad(int impact);

    virtual int calcularConfianza(int impact);

    void aplicarImpacto(Novia& novia, int impact);

};


class Otaku : public Jugador {
public:
    Otaku();

    int calcularFelicidad(int impact);
};


class Toxico : public Jugador {
public:
    Toxico();

    int calcularFelicidad(int impact);
};

class Gymrat : public Jugador {
public:
    Gymrat();

    int calcularFelicidad(int impact);

};

class NPC : public Jugador {
public:
    NPC();
    int calcularFelicidad(int impact);
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