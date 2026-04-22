#include <SFML/Graphics.hpp>
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

    void modificarConfianza(int valor) {
        Confianza = Confianza + valor;
       
    }

    void modificarFelicidad(int valor) {
        Felicidad = Confianza + valor;
       
    }

    void actualizarAmor() {

        Amor = Amor + ((Confianza + Felicidad) / 30);
       
        
    }

    void mostrar() {
        cout << "Confianza: " << Confianza << endl;
        cout << "Felicidad: " << Felicidad << endl;
        cout << "Amor: " << Amor << endl;
    }
};


class Jugador {
protected:
    int Atractivo, Carisma, Lealtad;

public:
    Jugador(int A, int C, int L) : Atractivo(A), Carisma(C), Lealtad(L) {}


    virtual int  calcularFelicidad(int impact) {
        return(impact * Atractivo) / 3; // su habilidad especial
    }

    virtual int calcularCFelicidad(int impact) {
        return (impact * Carisma) / 3;
    }

    virtual int calcularConfianza(int impact) {
        return (impact * Lealtad) / 2;
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
    Otaku() : Jugador(3, 7, 5) {}

    int calcularFelicidad(int impact) override {
        return(impact * Atractivo) / 3; // su habilidad especial
    }

    int calcularCFelicidad(int impact) override {
        return (impact * Carisma) / 3;
    }

    int calcularConfianza(int impact) override {
        return (impact * Lealtad) / 2;
    }
};


class Toxico : public Jugador {
public:
    Toxico() : Jugador(8, 3, 5) {}

    int calcularFelicidad(int impact) override {
        return(impact * Atractivo) / 4; // su habilidad especial
    }

    int calcularCFelicidad(int impact) override {
        return (impact * Carisma) / 2;
    }

    int calcularConfianza(int impact) override {
        return (impact * Lealtad) / 2;
    }
};
class Gymrat : public Jugador {
public:
    Gymrat() : Jugador(9, 5, 5) {}
    int calcularFelicidad(int impact) override {
        return(impact * Atractivo) / 5; // su habilidad especial
    }

    int calcularCFelicidad(int impact) override {
        return (impact * Carisma) / 2;
    }

    int calcularConfianza(int impact) override {
        return (impact * Lealtad) / 2;
    }
};
class NPC : public Jugador {
public:
    NPC() : Jugador(5, 5, 5) {}
    int calcularFelicidad(int impact)  override {
        return(impact * Atractivo) / 5; // su habilidad especial
    }

    int calcularCFelicidad(int impact) override {
        return (impact * Carisma) / 2;
    }

    int calcularConfianza(int impact) override {
        return (impact * Lealtad) / 2;
    }

};
enum TipoImpacto {
    CARISMA, ATRACTIVO, LEALTAD
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
    TipoImpacto tipo; // esto es para identificar el caso para ayudar a identificar la funcion por medio del enum

};

vector<Escenario> cargarHistoria(int clase) {
    vector <Escenario> h;
    Escenario e1;
    e1.pregunta = "Ring * Te llega un mensaje de tu novia * : Buenos dias!!!"; //toxico =1, npc = 1, gymrat =2, otaku = 3

    e1.imp1 = 5;
    e1.imp2 = 3;
    e1.imp3 = 0;
    e1.imp4 = -5;

    e1.tipo = CARISMA;
    



    if (clase == 0) { // TOXICO
        e1.op1 = "Buenos dias";
        e1.op2 = "Buenos dias bebe, como amaneciste?";
        e1.op3 = "Buenos dias amor";
        e1.op4 = "Ok";
    }
    else if (clase == 1) { // NPC
        e1.op1 = "Buenos dias";
        e1.op2 = "Buenos dias, pense en ti al despertar";
        e1.op3 = "Buenos dias princesa";
        e1.op4 = "Buenos dias, hasta que me hablas";
    }
    else if (clase == 2) { // GYMRAT
        e1.op1 = "Buenos dias";
        e1.op2 = "Buenos dias, pense en ti";
        e1.op3 = "Buenos dias hermos, hoy entreno amarte mas";
        e1.op4 = "Que tienen de bueno? me duele todo";
    }
    else if (clase == 3) { // OTAKU
        e1.op1 = "Buenos dias OwO";
        e1.op2 = "Como amanecio mi waifu pechocha";
        e1.op3 = "Ohayooooo amor 7w7";
        e1.op4 = "Te tardaste en decirme, bakaaa";
    }

    h.push_back(e1);

    //escena 2
    Escenario e2;
    e2.pregunta = "Te he visto por aqui, pero no en clases * comienza a acercarse *\nComo te llamas?";

    e2.imp1 = 0;
    e2.imp2 = -5;
    e2.imp3 = 0;
    e2.imp4 = -3;
    e2.tipo = ATRACTIVO;


    if (clase == 0) { // TOXICO
        e2.op1 = "*solo la saluda con la mano*";
        e2.op2 = "Hola, soy ..., pero puedes llamarme tu\nfuturo duenio";
        e2.op3 = "A ok";
        e2.op4 = "Que te importa? *con tono misterioso*";
    }
    else if (clase == 1) { // NPC
        e2.op1 = "Hola soy...";
        e2.op2 = "Hola soy..., podria acostrumbrarme a verte.";
        e2.op3 = "*con sus manos hace un like*";
        e2.op4 = "Hola, que lindo coincidir contigo";
    }
    else if (clase == 2) { // GYMRAT
        e2.op1 = "Hola? Soy ...";
        e2.op2 = "Mucho gusto soy ...,y parece que he\nencontrado una nueva motivacion";
        e2.op3 = "eh?";
        e2.op4 = "Hola, no creo que nos hayamos visto";
    }
    else if (clase == 3) { // OTAKU
        e2.op1 = "Hola..*se sonroja*";
        e2.op2 = "Soy...pero puedo ser tu sempai 7w7";
        e2.op3 = "...";
        e2.op4 = "Ehh mmmm, eres una chica muy kawaii";
    }

    h.push_back(e2);

    Escenario e3;
    e3.pregunta = "Que le respondes a tu novia?...";

    e3.imp1 = 3;
    e3.imp2 = 0;
    e3.imp3 = -3;
    e3.imp4 = -5;
    e3.tipo = LEALTAD;

    if (clase == 0) { // TOXICO
        e3.op1 = "Estoy contando los dias para verte preciosa";
        e3.op2 = "Un anio mas de peleas, yeeeeey";
        e3.op3 = "Que?, si este domingo estoy ocupado (ver tik tok)";
        e3.op4 = "Es la champions?";
    }
    else if (clase == 1) { // NPC
        e3.op1 = "Espero con ansias verte";
        e3.op2 = "Me alegra celebrar un anio";
        e3.op3 = "Que tiene el domingo?";
        e3.op4 = "Para que o que?";
    }
    else if (clase == 2) { // GYMRAT
        e3.op1 = "Así es, amor, ya ansío poder verte";
        e3.op2 = "La serie de nuestra vida ha llegado\na una nueva repeticion";
        e3.op3 = "Se me olvido, pero no se me olvido entrenar";
        e3.op4 = "Ando ocupado construyendo mi mejor version.";
    }
    else if (clase == 3) { // OTAKU
        e3.op1 = "Me emociona mas que un evento de fortnite\n>.<";
        e3.op2 = "Ya casi llega la fecha en donde empezo\nnuestro arco de amor";
        e3.op3 = "El estreno de la nueva temporada de\nMy Dress-Up Darling?";
        e3.op4 = "Sigue molestando y te anotare\nen mi libreta >;v";
    }
    h.push_back(e3);
    return h;
}
    // funcion para que mis fondos esten bien puestos
   void  ajustar(sf::Sprite& s, sf::Texture& t) {
        s.setScale({1080.f / t.getSize().x,614.f / t.getSize().y});
        }


int main() {
    //crear ventana
    sf::RenderWindow ventana(sf::VideoMode({ 1080, 614 }), "ONE WEEK");

    Novia mitilina; //novia
    Jugador* miJugador = nullptr; //aqui se le guarda un espacio reservado a la memoria para que no se crashie

    int scene = 0;
    int escenarioActual = 0;
    vector<Escenario> historia;

   

    //musica
    sf::Music musica;
    if (!musica.openFromFile("Extras/Musica/musicalofi.mp3")) {
        return -1; }
    musica.setLooping(true);// que se repita
    musica.setVolume(25); // volumen
    musica.play(); //reproducir

    //fuentes
    sf::Font fuente;//cargar fuente
    if (!fuente.openFromFile("Extras/Fuentes/Cute Love.ttf")) { //si la fuente no se abre entonces cierra todo
        return -1;
    }

    //texto lore
    sf::Text textolore(fuente);//se carga la fuente
    textolore.setCharacterSize(25);//tamano
    textolore.setFillColor(sf::Color::White);//color
    textolore.setPosition({ 150.f, 420.f });// posicion



    //texto opciones y pregunta
    sf::Text textoPregunta(fuente); //se carga la fuente
    textoPregunta.setCharacterSize(25); //tamano
    textoPregunta.setFillColor(sf::Color::White);//color
    textoPregunta.setPosition({ 300.f, 400.f }); // posicion

    sf::Text top1(fuente), top2(fuente), top3(fuente), top4(fuente); //cargar fuentes

    top1.setCharacterSize(22); //tamano
    top1.setFillColor(sf::Color::White); //color

    top2.setCharacterSize(22);
    top2.setFillColor(sf::Color::White);

    top3.setCharacterSize(22);
    top3.setFillColor(sf::Color::White);

    top4.setCharacterSize(22);
    top4.setFillColor(sf::Color::White);

    top1.setPosition({ 160.f, 490.f });
    top2.setPosition({ 550.f, 490.f });
    top3.setPosition({ 160.f, 560.f });
    top4.setPosition({ 550.f, 560.f });

    //  Textura y Sprites (fondos)

    //fondo jugar
    sf::Texture fondoinicio;
    fondoinicio.loadFromFile("Extras/fondos/inicio.jpeg");

    sf::Sprite bg0(fondoinicio);
    ajustar(bg0, fondoinicio); // funcion de ajustar

    //elige personaje
    sf::Texture personajes;
    personajes.loadFromFile("Extras/fondos/medescribencomo.jpeg");
    sf::Sprite bg1(personajes);
    ajustar(bg1, personajes);


    //dibujo de la novia 
    sf::Texture noviaboton;
    noviaboton.loadFromFile("Extras/fondos/noviacuadrocontinuar.png");

    sf::Sprite bg2(noviaboton);
    ajustar(bg2, noviaboton);

    sf::Texture fotonovia;
    fotonovia.loadFromFile("Extras/fondos/noviacontinuar.png");

    sf::Sprite bg3(fotonovia);
    ajustar(bg3, fotonovia);

    //textura mensaje de buenos dias con botones
    sf::Texture msjbuenosdias;
    msjbuenosdias.loadFromFile("Extras/fondos/buenosdiasopciones.jpeg");

    sf::Sprite bg4(msjbuenosdias);
    ajustar(bg4, msjbuenosdias);

    //textura dia 1

    sf::Texture dia1;
    dia1.loadFromFile("Extras/fondos/dia1.png");

    sf::Sprite bg5(dia1);
    ajustar(bg5, dia1);

    //pasillo
    sf::Texture pasillo;
    pasillo.loadFromFile("Extras/fondos/pasillocontinuar.png");

    sf::Sprite bg6(pasillo);
    ajustar(bg6, pasillo);
    

    //escema tulipanes
    
    sf::Texture tulipanes;
    tulipanes.loadFromFile("Extras/fondos/tulipanes.png");

    sf::Sprite bg7(tulipanes);
    ajustar(bg7, tulipanes);
    
    //escena illeana
    sf::Texture illeana;
    illeana.loadFromFile("Extras/fondos/illeanapasillo.png");

    sf::Sprite bg8(illeana);
    ajustar(bg8, illeana);

    //escena illeana con opciones
    sf::Texture illeanapasillo;
    illeanapasillo.loadFromFile("Extras/fondos/illeanapasillocuadro1.png");

    sf::Sprite bg9(illeanapasillo);
    ajustar(bg9, illeanapasillo);

    //escena del cuarto con un boton
    sf::Texture cuartocontexto;
    cuartocontexto.loadFromFile("Extras/fondos/cuartotexto.png");

    sf::Sprite bg10(cuartocontexto);
    ajustar(bg10, cuartocontexto);

    //escena de desicion sobre el domingo
    sf::Texture domingo;
    domingo.loadFromFile("Extras/fondos/fechaimportante1.png");

    sf::Sprite bg11(domingo);
    ajustar(bg11, domingo);

    //escena de cuarto con boton de continuar de noche
    sf::Texture cuartoscuro;
    cuartoscuro.loadFromFile("Extras/fondos/cuartosinluz.png");

    sf::Sprite bg12(cuartoscuro);
    ajustar(bg12, cuartoscuro);

    
    // boton invisible inicio

    sf::FloatRect zonaJugar({ 477.f, 400.f }, { 150.f, 60.f });

    //continuar arriba escena 1
    sf::FloatRect zonaContinuar0({ 795.f, 27.f }, { 250.f, 45.f });
    
 

    //boton continuar escena 2
                                //posicion          ancho y alto
    sf::FloatRect zonaContinuar({ 795.f, 540.f }, { 250.f, 45.f });

    //botones invisibles elige tu personaje
                            // X Y              ancho y alto
    sf::FloatRect zonaToxico({ 21.f, 450.f }, { 200.f, 80.f });
    sf::FloatRect zonaNPC({ 295.f, 450.f }, { 200.f, 80.f });
    sf::FloatRect zonaGym({ 590.f, 450.f }, { 200.f, 80.f });
    sf::FloatRect zonaOtaku({ 863.f, 450.f }, { 200.f, 80.f });

    // zonas de las 4 opciones de elejir el personaje
    sf::FloatRect zOp1({ 160.f, 485.f }, { 350.f, 60.f });
    sf::FloatRect zOp2({ 550.f, 485.f }, { 350.f, 60.f });
    sf::FloatRect zOp3({ 160.f, 555.f }, { 350.f, 60.f });
    sf::FloatRect zOp4({ 550.f, 555.f }, { 350.f, 60.f });



    //bucle 
    while (ventana.isOpen()) {

        // eventos
        while (auto event = ventana.pollEvent()) {
            // cerrar ventana en la tachita
            if (event->is<sf::Event::Closed>()) {
                ventana.close();
            }

            // click del mouse
            if (auto* mouseEvent = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mouseEvent->button == sf::Mouse::Button::Left) {

                    sf::Vector2i pixelPos = sf::Mouse::getPosition(ventana); //guarda donde presiono boton 
                    sf::Vector2f mousePos = ventana.mapPixelToCoords(pixelPos);//se guarda en la ventana comparandolo correctamente

                    // logica del menu principal
                    if (scene == 0) { //escena de presiona para jugar
                        if (zonaJugar.contains(mousePos)) {
                            scene = 1; // Cambiamos al juego
                        }
                    }
                    else if (scene == 1) { //elige su personaje
                        if (zonaToxico.contains(mousePos)) {
                            miJugador = new Toxico(); //creacion de clases, con el new es apra que sobreviban y no se borren en las escenas
                            historia = cargarHistoria(0);
                            scene = 2;
                        }
                        else if (zonaNPC.contains(mousePos)) {
                            miJugador = new NPC();
                            historia = cargarHistoria(1);
                            scene = 2;
                        }
                        else if (zonaGym.contains(mousePos)) {
                            miJugador = new Gymrat();
                            historia = cargarHistoria(2);
                            scene = 2;
                        }
                        else if (zonaOtaku.contains(mousePos)) {
                            miJugador = new Otaku();
                            historia = cargarHistoria(3);
                            scene = 2;
                        }
                    }
                    else if (scene == 2) { //escena introductoria
                        if (zonaContinuar0.contains(mousePos)) {
                            scene = 3;
                        }
                    }
                    else if (scene == 3) { //escena de foto de la novia
                        if (zonaContinuar.contains(mousePos)) {
                            scene = 4;
                        }

                    }
                    else if (scene == 4) { //escena de dia 1
                        if (zonaContinuar0.contains(mousePos)) {
                            scene = 5;
                        }

                    }
                    else if (scene == 5) {
                        int impactoElegido = -67; // variable centinela

                        // dependiendo el boton que eligio con su opcion se guarda el impacto -5,0,3,5
                        if (zOp1.contains(mousePos)) {
                            mitilina.mostrar(); //ver stats inciales
                            impactoElegido = historia[escenarioActual].imp1; // busca cuanto vale el impacto del struct 
                            scene = 6;
                        }
                        else if (zOp2.contains(mousePos)) {
                            mitilina.mostrar(); //ver stats inciales
                            impactoElegido = historia[escenarioActual].imp2;
                            scene = 6;
                        }
                        else if (zOp3.contains(mousePos)) {
                            mitilina.mostrar(); //ver stats inciales
                            impactoElegido = historia[escenarioActual].imp3;
                            scene = 6;
                        }
                        else if (zOp4.contains(mousePos)) {
                            mitilina.mostrar(); //ver stats inciales
                            impactoElegido = historia[escenarioActual].imp4;
                            scene = 6;
                        }

                        //esto es para saber si pico un boton
                        if (impactoElegido != -67) {
                            
                            //objeto mi jugador uso su funcion aplicarimpacto y le mando la novia y el impacto -5,0,3,5 que esta gaurdado arriba
                            miJugador->aplicarImpacto(mitilina, impactoElegido);

                            //para ver si funciona
                            mitilina.mostrar();

                            //avanzo en mi vector para que no se quede en los mismos dialogos
                            if (escenarioActual < historia.size() - 1) {
                                escenarioActual++;
                            }
                            
                        }


                    }
                    else if (scene == 6) {
                        if (zonaContinuar0.contains(mousePos)) {
                            scene= 7;
                        }

                    }
                    else if (scene == 7) {
                        if (zonaContinuar0.contains(mousePos)) {
                            scene =8;
                        }
                    }
                    else if (scene == 8) {
                        if (zonaContinuar0.contains(mousePos)) {
                            scene = 9;
                        }
                    }
                    else if (scene == 9) {
                        int impactoElegido = -67; // variable centinela

                        // dependiendo el boton que eligio con su opcion se guarda el impacto -5,0,3,5
                        if (zOp1.contains(mousePos)) {
                            mitilina.mostrar(); //ver stats inciales
                            impactoElegido = historia[escenarioActual].imp1;
                            scene = 10;
                        }
                        else if (zOp2.contains(mousePos)) {
                            mitilina.mostrar(); //ver stats inciales
                            impactoElegido = historia[escenarioActual].imp2;
                            scene = 10;
                        }
                        else if (zOp3.contains(mousePos)) {
                            mitilina.mostrar(); //ver stats inciales
                            impactoElegido = historia[escenarioActual].imp3;
                            scene = 10;
                        }
                        else if (zOp4.contains(mousePos)) {
                            mitilina.mostrar(); //ver stats inciales
                            impactoElegido = historia[escenarioActual].imp4;
                            scene = 10;
                        }

                        //esto es para saber si pico un boton
                        if (impactoElegido != -67) {

                            //objeto mi jugador uso su funcion aplicarimpacto y le mando la novia y el impacto -5,0,3,5 que esta gaurdado arriba
                            miJugador->aplicarImpacto(mitilina, impactoElegido);

                            //para ver si funciona
                            mitilina.mostrar();

                            //avanzo en mi vector para que no se quede en los mismos dialogos
                            if (escenarioActual < historia.size() - 1) {
                                escenarioActual++;
                            }

                        }
                    }
                    else if (scene == 10) {
                       if (zonaContinuar0.contains(mousePos)) {
                           scene = 11;
                       }
                    }
                    else if (scene == 11) {
                        if (zonaContinuar0.contains(mousePos)) {
                            scene = 12;
                        }
                    }
                    else if (scene == 12) {
                        int impactoCentinela = -67;

                        if (zOp1.contains(mousePos)) {
                            mitilina.mostrar(); //ver stats inciales
                            impactoCentinela = historia[escenarioActual].imp1;
                            scene = 13;
                        }
                        else if (zOp2.contains(mousePos)) {
                            mitilina.mostrar(); //ver stats inciales
                            impactoCentinela = historia[escenarioActual].imp2;
                            scene = 13;
                        }
                        else if (zOp3.contains(mousePos)) {
                            mitilina.mostrar(); //ver stats inciales
                            impactoCentinela = historia[escenarioActual].imp3;
                            scene = 13;
                        }
                        else if (zOp4.contains(mousePos)) {
                            mitilina.mostrar(); //ver stats inciales
                            impactoCentinela = historia[escenarioActual].imp4;
                            scene = 13;
                        }
                        if (impactoCentinela != -67) {
                            miJugador->aplicarImpacto(mitilina, impactoCentinela);
                            mitilina.mostrar();

                            if (escenarioActual < historia.size() - 1) {
                                escenarioActual++;
                            }
                        }
                    }
                    else if (scene == 13) {
                        if (zonaContinuar0.contains(mousePos)) {
                            scene = 14;
                        }
                    }
                }
            }
        }
    

    // mostrar los dibujos
    ventana.clear(sf::Color::Black);

    if (scene == 0) { // menu Principal
        ventana.draw(bg0);


    }
    else if (scene == 1) { //elije personaje
        ventana.draw(bg1);
    }
    else if (scene == 2) { //foto de la novia con texto
        ventana.draw(bg2);
        textolore.setString("Tengo una bella novia. Describiria a mi novia como una chica muy alegre,\ndivertida y personalmente, muy linda.\nComenzamos a andar desde la prepa, pero ahora que comenzamos la universidad\nla he notado un poco rara, lastimosamente no quedamos en la misma universidad pero\nal menos puedo verla despues de clases. Y asi empezamos nuestra primera semana a\ndistancia,no creo que nos vaya tan mal... eso espero...");
        ventana.draw(textolore);
    }
    else if (scene == 3) {
        ventana.draw(bg3);
    }
    else if (scene == 4) {
        ventana.draw(bg5);
    }
    else if (scene == 5 && !historia.empty()) {
        ventana.draw(bg4);

        textoPregunta.setString(historia[escenarioActual].pregunta);
        top1.setString(historia[escenarioActual].op1);
        top2.setString(historia[escenarioActual].op2);
        top3.setString(historia[escenarioActual].op3);
        top4.setString(historia[escenarioActual].op4);

        ventana.draw(textoPregunta);
        ventana.draw(top1); 
        ventana.draw(top2);
        ventana.draw(top3); 
        ventana.draw(top4);


    }
    else if (scene == 6) {
        ventana.draw(bg6);
        textolore.setString("Despues de responder el mensaje, guardo el celular y empiezo a caminar hacia\nmi primera clase.\nEl aire se siente distinto , nueva universidad, nueva rutina, un nuevo comienzo.\n\n*vibra el celular: mensaje de la novia*");
        ventana.draw(textolore);
    }
    else if (scene == 7) {
        ventana.draw(bg7);
        textolore.setString("Sonrei un poco y segui caminando.\nLa amo...");
        ventana.draw(textolore);
    }
    else if (scene == 8) {
        ventana.draw(bg8);
        textolore.setString("\nJusto cuando estoy por entrar al salon pero algo me interrumpe...\nUna chica esta recargada sobre la pared sonriendo ligeramente.");
        ventana.draw(textolore);
    }
    else if (scene == 9) {
        ventana.draw(bg9);
        textoPregunta.setString(historia[escenarioActual].pregunta);
        top1.setString(historia[escenarioActual].op1);
        top2.setString(historia[escenarioActual].op2);
        top3.setString(historia[escenarioActual].op3);
        top4.setString(historia[escenarioActual].op4);

        ventana.draw(textoPregunta);
        ventana.draw(top1); 
        ventana.draw(top2);
        ventana.draw(top3); 
        ventana.draw(top4);
    }
    else if (scene == 10) {
        ventana.draw(bg6);
        textolore.setString("Intercambiamos unas palabras antes de que tenga que entrar a clase.\n No fue nada, pero tampoco nada.\nCamino a mi asiento intentando no pensar demasiado en eso.\nDejo mi mochila y comienzo a poner atencion a la clase. ");
        ventana.draw(textolore);
    }
    else if (scene == 11) {
        ventana.draw(bg10);
        textolore.setString("Fue un dia bastante pesado...\n*ring ring* El celular esta sonando, deberia revisarlo");
        ventana.draw(textolore);
    }
    else if (scene == 12) {
        ventana.draw(bg11);

        textoPregunta.setString(historia[escenarioActual].pregunta);
        top1.setString(historia[escenarioActual].op1);
        top2.setString(historia[escenarioActual].op2);
        top3.setString(historia[escenarioActual].op3);
        top4.setString(historia[escenarioActual].op4);

        ventana.draw(textoPregunta);
        ventana.draw(top1); 
        ventana.draw(top2);
        ventana.draw(top3);
        ventana.draw(top4);
    }
    else if (scene == 13) {
        ventana.draw(bg12);
        textolore.setString("Dejo el celular y me recuesto.\nEl dia fue pesado y apenas es lunes...\nNo puedo dejar de pensar en ella.\nEl proximo dia sera mejor.");
        ventana.draw(textolore);
    }
    else if (scene == 14) {
        textolore.setString("Aqui deberia ir el menu de si el jugador quiere continuar\n o quiere hacer alguna actividad extra para\n corregir sus decisiones");
        ventana.draw(textolore);
    }

    ventana.display();
}
        return 0;
    }

  
