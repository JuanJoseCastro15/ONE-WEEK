#include <iostream>
using namespace std;

class Jugador {
protected:
    int Atractivo, Carisma;
public:
    Jugador (int Atractivo , int Carisma ) : Atractivo (Atractivo), Carisma (Carisma) {}
};

class Novia {
private:
    int Confianza, Amor, Felicidad;
public:
   int getConfianza() {
        return Confianza;
    }

   int getAmor() {
       return Amor;
   }

   int getFelicidad() {
       return Felicidad;
   }


};

<SFML / Graphics.hpp>

#include <SFML/Audio.hpp>

#include <iostream>

using namespace std;





class Game {

public:

    Jugador* jugador;

    Novia novia = Novia(70, 60);

    string textoactual;



    void opcion1() {

        novia.subirAmor(10);

        textoactual = jugador->opcionBuena();

    }

    void opcion2() {

        novia.bajarAmor(10);

        textoactual = jugador->opcionMala();

    }

};



class Jugador {

private:

    int atractivo;

    int carisma;

public:

    Jugador(int a, int car) { //constructor

        atractivo = a;

        carisma = car;

    }

    int getAtractivo() {

        return atractivo;

    }

    int getCarisma() {

        return carisma;

    }

    virtual string opcionBuena() {

        return "Le respondiste bonito";

    }

    virtual string opcionMala() {

        return "La ignoraste";

    }

};

class Gymrat : public Jugador {

    Gymrat() :Jugador(100, 80) {}

    string opcionBuena() override {

        return "Despues del gym salimos, te amo";

    }

    string opcionMala() override {

        return "La ignoraste...";

    }

};



class Otaku : public Jugador {

    Otaku() :Jugador(20, 50) {}

    string opcionBuena() {

        return "Te amo onichan daiski uwu";

    }

    string opcionMala() {

        return "La comparaste con tu waifu y se molesto";

    }

};

class Novia {

private:

    int amor;

    int confianza;

public:

    Novia(int a, int c) {

        amor = a;

        confianza = c;

    }

    int getAmor() {

        return amor;

    }



    int getConfianza() {

        return confianza;

    }



    void subirAmor(int cantidad) {

        amor += cantidad;

    }



    void bajarAmor(int cantidad) {

        amor -= cantidad;

    }

};

int main() {

    // Escena inicial = 0 . elige personaje = 1, dos botones simulando decicion = 2.

    int scene = 0;

    Game juego;

    Gymrat gym;

    Otaku otaku;

    // Crear ventana

    sf::RenderWindow window(sf::VideoMode({ 900, 1000 }), "One Week - SFML 3.0");



    //cargar musica

    sf::Music musica;

    if (!musica.openFromFile("musicalofi.mp3")) return -1;



    // crear textos

    sf::Font fuente;

    if (!fuente.openFromFile("arialceb.ttf"))

        return -1;

    musica.setLooping(true);

    musica.setVolume(50);

    musica.play();



    sf::Text texto(fuente);

    texto.setString("PRESIONA PARA JUGAR"); //que dice

    texto.setCharacterSize(40); //tamano

    texto.setFillColor(sf::Color::White); //color

    texto.setPosition({ 100.f, 600.f }); //donde aparece



    // ===== CONFIGURACIÓN DE BOTONES =====

    //boton de inicio para jugar

    sf::RectangleShape bottoninicio({ 200.f, 60.f });

    bottoninicio.setPosition({ 350.f, 800.f });

    bottoninicio.setFillColor(sf::Color::Blue);

    bottoninicio.setOutlineThickness(2);

    bottoninicio.setOutlineColor(sf::Color::White);



    // Botón amarillo (Izquierda arriba en el Menú)

    sf::RectangleShape b1({ 200.f, 60.f });

    b1.setPosition({ 200.f, 725.f });

    b1.setFillColor(sf::Color::Yellow);

    b1.setOutlineThickness(2);

    b1.setOutlineColor(sf::Color::White);



    // Botón amarillo (derecha arriba en el Menú)

    sf::RectangleShape b2({ 200.f, 60.f });

    b2.setPosition({ 500.f, 725.f });

    b2.setFillColor(sf::Color::Yellow);

    b2.setOutlineThickness(2);

    b2.setOutlineColor(sf::Color::White);



    // Botón amarillo (Izquierda abajo en el Menú)

    sf::RectangleShape b3({ 200.f, 60.f });

    b3.setPosition({ 200.f, 800.f });

    b3.setFillColor(sf::Color::Yellow);

    b3.setOutlineThickness(2);

    b3.setOutlineColor(sf::Color::White);



    // Botón amarillo (derecha abajo en el Menú)

    sf::RectangleShape b4({ 200.f, 60.f });

    b4.setPosition({ 500.f, 800.f });

    b4.setFillColor(sf::Color::Yellow);

    b4.setOutlineThickness(2);

    b4.setOutlineColor(sf::Color::White);



    /////////////////////////////////////////

    // 

    // Botón Verde (Izquierda en el Menú)

    sf::RectangleShape button({ 200.f, 60.f });

    button.setPosition({ 200.f, 800.f });

    button.setFillColor(sf::Color::Green);

    button.setOutlineThickness(2);

    button.setOutlineColor(sf::Color::White);



    // Botón Magenta (Derecha en el Menú)

    sf::RectangleShape button2({ 200.f, 60.f });

    button2.setPosition({ 500.f, 800.f });

    button2.setFillColor(sf::Color::Magenta);

    button2.setOutlineThickness(2);

    button2.setOutlineColor(sf::Color::White);



    // Botón Regreso (Se usa en Escena 1 y 2)

    sf::RectangleShape btnBack({ 200.f, 60.f });

    btnBack.setPosition({ 350.f, 800.f });

    btnBack.setFillColor(sf::Color::Red);

    btnBack.setOutlineThickness(2);

    btnBack.setOutlineColor(sf::Color::White);



    // ===== CARGA DE TEXTURAS Y SPRITES =====



    sf::Texture inicio;

    if (!inicio.loadFromFile("ventanaverde.jpg")) return -1;

    sf::Sprite backround0(inicio);





    sf::Texture elijeper;

    if (!elijeper.loadFromFile("castillo.jpg")) return -1;

    sf::Sprite backround1(elijeper);



    sf::Texture darkfantasy;

    if (!darkfantasy.loadFromFile("fantasyfondo.png")) return -1;

    sf::Sprite background(darkfantasy);



    sf::Texture goldenbrown;

    if (!goldenbrown.loadFromFile("ventana.jpg")) return -1;

    sf::Sprite background2(goldenbrown);



    sf::Texture negro;

    if (!negro.loadFromFile("tumbas.jpg")) return -1;

    sf::Sprite background3(negro);



    //corregir escalas de las texturas de fondo



    backround0.setScale({

        900.f / backround0.getTexture().getSize().x,

        1000.f / backround0.getTexture().getSize().y

        });



    backround1.setScale({

        900.f / backround1.getTexture().getSize().x,

        1000.f / backround1.getTexture().getSize().y

        });



    background.setScale({

        900.f / background.getTexture().getSize().x,

        1000.f / background.getTexture().getSize().y

        });



    background2.setScale({

        900.f / background2.getTexture().getSize().x,

        1000.f / background2.getTexture().getSize().y

        });



    background3.setScale({

        900.f / background3.getTexture().getSize().x,

        1000.f / background3.getTexture().getSize().y

        });



    // ===== BUCLE PRINCIPAL =====

    while (window.isOpen()) {



        // Gestión de Eventos

        while (auto event = window.pollEvent()) {



            if (event->is<sf::Event::Closed>()) {

                window.close();

            }



            // Gestión de Clics

            if (auto* mouseEvent = event->getIf<sf::Event::MouseButtonPressed>()) {

                if (mouseEvent->button == sf::Mouse::Button::Left) {



                    // Obtener posición real del mouse en el mundo

                    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

                    sf::Vector2f mousePos = window.mapPixelToCoords(pixelPos);



                    // LÓGICA DE ESCENAS 

                    if (scene == 0) {

                        if (bottoninicio.getGlobalBounds().contains(mousePos)) {

                            scene = 1;

                        }

                    }

                    else if (scene == 1) {

                        if (b1.getGlobalBounds().contains(mousePos)) {

                            scene = 2;

                            juego.jugador = &gym;

                        }

                        else if (b2.getGlobalBounds().contains(mousePos)) {

                            scene = 2;

                            juego.jugador = &otaku;

                        }

                        else if (b3.getGlobalBounds().contains(mousePos)) {

                            scene = 2;

                        }

                        else if (b4.getGlobalBounds().contains(mousePos)) {

                            scene = 2;

                        }

                    }

                    else if (scene == 2) {

                        if (button.getGlobalBounds().contains(mousePos)) {

                            scene = 3;

                            juego.opcion1();



                        }

                        else if (button2.getGlobalBounds().contains(mousePos)) {

                            scene = 4;

                            juego.opcion2();



                        }

                    }

                    else if (scene == 3 || scene == 4) {

                        // En ambas escenas el botón rojo regresa al menú

                        if (btnBack.getGlobalBounds().contains(mousePos)) {

                            scene = 2;

                        }

                    }



                }

            }

        }



        // ===== RENDERIZADO =====

        window.clear();

        if (scene == 0) {



            window.draw(backround0);

            window.draw(bottoninicio);

            window.draw(texto);



        }

        else if (scene == 1) {

            window.draw(backround1);

            texto.setString("ELIGE UN PERSONAJE PARA JUGAR: ");

            window.draw(texto);

            window.draw(b1);

            window.draw(b2);

            window.draw(b3);

            window.draw(b4);

        }

        else if (scene == 2) {

            window.draw(background);

            window.draw(button);

            window.draw(button2);

        }

        else if (scene == 3) {

            window.draw(background2);

            window.draw(btnBack);

        }

        else if (scene == 4) {

            window.draw(background3);

            window.draw(btnBack);

        }



        window.display();

    }



    return 0;

}


int main()
{
    std::cout << "Hello World!\n";
}
