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
    void modificarAmor(int valor) {

        Amor += valor;

        if (Amor > 100)
            Amor = 100;

        if (Amor < 0)
            Amor = 0;
    }
    void actualizarAmor() {

        Amor += ((Confianza - 100) + (Felicidad - 100)) / 50;

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

vector<Escenario> cargarHistoria(int clase) {
    vector <Escenario> h;
    Escenario e1;
    e1.pregunta = "Ring * Te llega un mensaje de tu novia * : Buenos dias!!!"; //toxico =1, npc = 1, gymrat =2, otaku = 3

    e1.imp1 = 5;
    e1.imp2 = 3;
    e1.imp3 = 0;
    e1.imp4 = -5;


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
        e1.op3 = "Buenos dias hermosa, hoy entreno amarte mas";
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

    if (clase == 0) { // TOXICO
        e3.op1 = "Estoy contando los dias para verte preciosa";
        e3.op2 = "Un anio mas de peleas, yeeeeey";
        e3.op3 = "Que?, si este domingo estoy ocupado\n(ver tik tok)";
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

    Escenario e4;
    e4.pregunta = "Hoy hace un poco mas de frío, parece que va a llover.\nMas vale que vaya bien abrigado.";

    e4.imp1 = 3;
    e4.imp2 = 1;
    e4.imp3 = 0;
    e4.imp4 = -5;

    if (clase == 0) { // TOXICO
        e4.op1 = "La bufanda que hizo la tipa con la que ando";
        e4.op2 = "Un abrigo para frio";
        e4.op3 = "Mi camisa Gucci (Imitacion de temu)";
        e4.op4 = "Una camiseta con la frase\n“El pobre es pobre por que quiere”";
    }
    else if (clase == 1) { // NPC
        e4.op1 = "La bufanda que me hizo mi novia";
        e4.op2 = "Algo para calentar";
        e4.op3 = "Mi confiable sudadera gris";
        e4.op4 = " Ropa que aún no se ha lavado";
    }
    else if (clase == 2) { // GYMRAT
        e4.op1 = "La bufanda que me hizo mi PR";
        e4.op2 = "Blindado contra el frio";
        e4.op3 = "Sudadera";
        e4.op4 = "Un pans y un muscle fit";
    }
    else if (clase == 3) { // OTAKU
        e4.op1 = "La bufanda que me hizo mi noviecita-chan";
        e4.op2 = "Abrigadito y calientito";
        e4.op3 = "Una camisa de Naruto";
        e4.op4 = "Una camisa de una chica sacando la\nlengua y mirando hacia arriba";

    }

    h.push_back(e4);

    Escenario e5;
    e5.pregunta = "Esta bajo un pequeño techo, mirando la lluvia como si no tuviera prisa.\nLevanta la mirada y me encuentra. Sonrie.";

    e5.imp1 = 3;
    e5.imp2 = 1;
    e5.imp3 = 0;
    e5.imp4 = -5;

    if (clase == 0) { // TOXICO
        e5.op1 = "Acercarme mientras hago poses chistosas";
        e5.op2 = "Acercarse y decir: Esperaste mucho por mi?";
        e5.op3 = "Saludar rápido";
        e5.op4 = "Hola… Alicia?";
    }
    else if (clase == 1) { // NPC
        e5.op1 = "Acercarme con una sonrisa";
        e5.op2 = "Acercarse y decir:Esperaba verte de nuevo";
        e5.op3 = "Saludar con la mano al pasar.";
        e5.op4 = "Tratar de alejarme, arrepentirme, acercarme ";
    }
    else if (clase == 2) { // GYMRAT
        e5.op1 = "Acercarme lentamente";
        e5.op2 = "Acercase y decir:\nCreo que te estas volviendo parte de mi rutina";
        e5.op3 = "Saludar";
        e5.op4 = "Acercarme y decir: Hola...tu...";
    }
    else if (clase == 3) { // OTAKU
        e5.op1 = "Acercarme corriendo como naruto";
        e5.op2 = "Acercarme y decir:\nEsto ya parece opening de Your Name";
        e5.op3 = "Acercarme a Illeana-chan";
        e5.op4 = "Acercarme haciendo pausas raras";

    }

    h.push_back(e5);

    Escenario e6;
    e6.pregunta = "Que le respondes a tu novia?";

    e6.imp1 = 5;
    e6.imp2 = 1;
    e6.imp3 = -2;
    e6.imp4 = -5;

    if (clase == 0) { // TOXICO
        e6.op1 = "Obvio, con este y con cualquier clima";
        e6.op2 = "No estaria mal";
        e6.op3 = "*No responder*";
        e6.op4 = "Gracias";
    }
    else if (clase == 1) { // NPC
        e6.op1 = "Y tambien quiero verte mi vida";
        e6.op2 = "Yo igual";
        e6.op3 = "Dejarla en visto";
        e6.op4 = "oks";
    }
    else if (clase == 2) { // GYMRAT
        e6.op1 = "No cancelo entrenamiento...pero\npor ti hago una excepcion";
        e6.op2 = "Yo tambien";
        e6.op3 = "*No responder*";
        e6.op4 = "Eso suena a plan obligatorio";
    }
    else if (clase == 3) { // OTAKU
        e6.op1 = "Yo tambien te quiero ver pinchecha hemocha,\nnya";
        e6.op2 = "Chi amor UwU";
        e6.op3 = "Dejarla en visto";
        e6.op4 = "ok :/";

    }

    h.push_back(e6);

    Escenario e7;
    e7.pregunta = "Hoy es un dia importante...\nQue le dices a tu novia?";

    e7.imp1 = 5;
    e7.imp2 = 2;
    e7.imp3 = -2;
    e7.imp4 = -5;

    if (clase == 0) { // TOXICO
        e7.op1 = "Obvio me acorde";
        e7.op2 = "Feliz dia amor";
        e7.op3 = "Ah era hoy?";
        e7.op4 = "Ni idea";
    }
    else if (clase == 1) { // NPC
        e7.op1 = "Claro que me acorde";
        e7.op2 = "Feliz dia mi amor";
        e7.op3 = "Perdon, olvide la fecha";
        e7.op4 = "Que tenia hoy?";
    }
    else if (clase == 2) { // GYMRAT
        e7.op1 = "Nunca olvidaria nuestro dia";
        e7.op2 = "Feliz dia preciosa";
        e7.op3 = "Andaba entrenando...";
        e7.op4 = "No tuve tiempo";
    }
    else if (clase == 3) { // OTAKU
        e7.op1 = "Nuestro evento canonico UwU";
        e7.op2 = "Feliz dia waifu";
        e7.op3 = "Mi memoria filler fallo";
        e7.op4 = "No recuerdo ese arco";
    }

    h.push_back(e7);

    Escenario e8;
    e8.pregunta = "Ella te pregunta si de verdad la amas...";

    e8.imp1 = 5;
    e8.imp2 = 2;
    e8.imp3 = -3;
    e8.imp4 = -5;

    if (clase == 0) {
        e8.op1 = "Claro que si";
        e8.op2 = "Eres mia";
        e8.op3 = "No se";
        e8.op4 = "Que flojera";
    }
    else if (clase == 1) {
        e8.op1 = "Muchisimo";
        e8.op2 = "Siempre estare contigo";
        e8.op3 = "A veces lo dudo";
        e8.op4 = "No me molestes";
    }
    else if (clase == 2) {
        e8.op1 = "Mas que al gym";
        e8.op2 = "Siempre";
        e8.op3 = "Estoy confundido";
        e8.op4 = "Estoy ocupado";
    }
    else if (clase == 3) {
        e8.op1 = "Mas que al anime";
        e8.op2 = "Tu eres mi protagonista";
        e8.op3 = "No se...";
        e8.op4 = "zzz";
    }

    h.push_back(e8);




    // Dentro de cargarHistoria(), después de e8

    Escenario e9;

    e9.pregunta = "Buenos días <3\n"
        "Ayer te sentí un poco raro...\n"
        "¿Todo bien?";

    e9.imp1 = 5;
    e9.imp2 = 2;
    e9.imp3 = -2;
    e9.imp4 = -5;

    if (clase == 0) { // TOXICO

        e9.op1 = "Todo bien amor, solo queria verte.";
        e9.op2 = "Si, solo tuve un mal dia.";
        e9.op3 = "Estoy bien.";
        e9.op4 = "No pasa nada.";

    }
    else if (clase == 1) { // NPC

        e9.op1 = "Perdon amor, creo que solo estaba cansado.\nTe prometo que estoy bien.";

        e9.op2 = "Todo bien, solo tuve un dia pesado.";

        e9.op3 = "Si estoy bien.";

        e9.op4 = "No pasa nada, no te preocupes.";

    }
    else if (clase == 2) { // GYMRAT

        e9.op1 = "Todo bien preciosa,\nsolo ando destruido del gym.";

        e9.op2 = "Solo tuve un dia pesado.";

        e9.op3 = "Estoy bien.";

        e9.op4 = "Nah, todo normal.";

    }
    else if (clase == 3) { // OTAKU

        e9.op1 = "Todo bien mi waifu hermosa UwU";

        e9.op2 = "Solo andaba sin energia ayer.";

        e9.op3 = "Toy bien.";

        e9.op4 = "Nada importante nya.";

    }
    h.push_back(e9);

    // =========================
    // DIA 3 - ESCENA 2
    // =========================

    Escenario e10;

    e10.pregunta = "Illeana me mira directamente.\n"
        "¿Me pasas tu numero?";

    e10.imp1 = -4;
    e10.imp2 = 2;
    e10.imp3 = 3;
    e10.imp4 = 0;

    if (clase == 0) { // TOXICO

        e10.op1 = "Claro.";
        e10.op2 = "Hmm... bueno.";
        e10.op3 = "Solo si no me ignoras despues.";
        e10.op4 = "Eh... si.";

    }
    else if (clase == 1) { // NPC

        e10.op1 = "Claro, toma.";
        e10.op2 = "Mmm... si, supongo.";
        e10.op3 = "Bueno, pero cobrare por mensaje.";
        e10.op4 = "Eh... claro.";

    }
    else if (clase == 2) { // GYMRAT

        e10.op1 = "Claro.";
        e10.op2 = "Va, pero casi no reviso el cel.";
        e10.op3 = "Solo si mandas memes fitness.";
        e10.op4 = "Si... toma.";

    }
    else if (clase == 3) { // OTAKU

        e10.op1 = "Chi UwU";
        e10.op2 = "Mmm... bueno nya.";
        e10.op3 = "Solo si no haces spam.";
        e10.op4 = "E-esta bien.";

    }

    h.push_back(e10);

    // =========================
    // DIA 3 - ESCENA 3
    // =========================

    Escenario e11;

    e11.pregunta = "¿Que respondes?";

    e11.imp1 = 5;
    e11.imp2 = -2;
    e11.imp3 = -3;
    e11.imp4 = -5;

    if (clase == 0) {

        e11.op1 = "\"Obvio, feliz cumpleaños\"";
        e11.op2 = "\"Feliz aniversario...\"";
        e11.op3 = "\"El dia que nos conocimos?\"";
        e11.op4 = "\"Era una salida normal, no?\"";

    }
    else if (clase == 1) {

        e11.op1 = "\"Obvio, feliz cumpleaños\"";
        e11.op2 = "\"Feliz aniversario...\"";
        e11.op3 = "\"El primer dia que hablamos?\"";
        e11.op4 = "\"Eh... era una cita cualquiera?\"";

    }
    else if (clase == 2) {

        e11.op1 = "\"Obvio, feliz cumpleaños\"";
        e11.op2 = "\"Feliz aniversario preciosa\"";
        e11.op3 = "\"Cuando nos conocimos?\"";
        e11.op4 = "\"Era una salida?\"";

    }
    else if (clase == 3) {

        e11.op1 = "\"Obvio waifu, feliz cumpleaños UwU\"";
        e11.op2 = "\"Feliz aniversario nya\"";
        e11.op3 = "\"El inicio de nuestro arco?\"";
        e11.op4 = "\"Era relleno?\"";

    }

    h.push_back(e11);


    return h;
}

void procesarRegalo(
    int& scene,
    int siguienteScene,
    Novia& mitilina,
    sf::Vector2f mousePos,
    sf::FloatRect zonaFlores,
    sf::FloatRect zonaCarta,
    sf::FloatRect zonaPastel,
    sf::FloatRect zonaCollar
) {

    bool regaloElegido = false;

    if (zonaFlores.contains(mousePos)) {
        regaloElegido = true;
    }

    else if (zonaCarta.contains(mousePos)) {
        regaloElegido = true;
    }

    else if (zonaPastel.contains(mousePos)) {
        regaloElegido = true;
    }

    else if (zonaCollar.contains(mousePos)) {
        regaloElegido = true;
    }

    // si eligio cualquier regalo
    if (regaloElegido) {

        mitilina.modificarAmor(3);

        cout << "Le diste un regalo a tu novia." << endl;

        mitilina.mostrar();

        scene = siguienteScene;
    }
}

// funcion para que mis fondos esten bien puestos
void ajustar(sf::Sprite& s, sf::Texture& t) {

    if (t.getSize().x == 0 || t.getSize().y == 0) {
        cout << "ERROR: textura invalida al ajustar sprite" << endl;
        return;
    }

    s.setScale({
        1080.f / static_cast<float>(t.getSize().x),
        614.f / static_cast<float>(t.getSize().y)
        });
}

void dibujarOpciones(
    sf::RenderWindow& ventana,
    sf::Text& pregunta,
    sf::Text& op1,
    sf::Text& op2,
    sf::Text& op3,
    sf::Text& op4,
    vector<Escenario>& historia,
    int escenarioActual
) {
    if (historia.empty()) {
        return;
    }

    if (escenarioActual < 0 || escenarioActual >= historia.size()) {
        return;
    }
    pregunta.setString(historia[escenarioActual].pregunta);

    op1.setString(historia[escenarioActual].op1);
    op2.setString(historia[escenarioActual].op2);
    op3.setString(historia[escenarioActual].op3);
    op4.setString(historia[escenarioActual].op4);

    ventana.draw(pregunta);
    ventana.draw(op1);
    ventana.draw(op2);
    ventana.draw(op3);
    ventana.draw(op4);
}
struct SceneData {
    sf::Sprite* fondo = nullptr;

    string texto = "";

    bool tieneOpciones = false;

    bool continuarArriba = false;
    bool continuarAbajo = false;

    int siguienteEscena = -1;

    int indiceHistoria = -1;
};
void renderizarEscena(
    sf::RenderWindow& ventana,
    SceneData& escena,
    sf::Text& textolore,
    sf::Text& textoPregunta,
    sf::Text& top1,
    sf::Text& top2,
    sf::Text& top3,
    sf::Text& top4,
    vector<Escenario>& historia,
    int escenarioActual
) {

    // dibujar fondo
    if (escena.fondo != nullptr) {
        ventana.draw(*escena.fondo);
    }

    // dibujar texto normal
    if (!escena.texto.empty()) {

        textolore.setString(escena.texto);
        ventana.draw(textolore);
    }

    // dibujar opciones
    if (
        escena.tieneOpciones &&
        escena.indiceHistoria >= 0 &&
        escena.indiceHistoria < historia.size()
        )
    {
        dibujarOpciones(
            ventana,
            textoPregunta,
            top1,
            top2,
            top3,
            top4,
            historia,
            escena.indiceHistoria
        );
    }
    else {

        textoPregunta.setString("");

        top1.setString("");
        top2.setString("");
        top3.setString("");
        top4.setString("");
    }
}

void procesarDecision(
    int& scene,
    int siguienteScene,
    int& escenarioActual,
    vector<Escenario>& historia,
    unique_ptr<Jugador>& miJugador,
    Novia& mitilina,
    sf::Vector2f mousePos,
    sf::FloatRect zOp1,
    sf::FloatRect zOp2,
    sf::FloatRect zOp3,
    sf::FloatRect zOp4
) {

    // validar historia
    if (escenarioActual < 0 || escenarioActual >= historia.size()) {
        cout << "ERROR: escenarioActual fuera de rango" << endl;
        return;
    }

    int impacto = -67;

    if (zOp1.contains(mousePos)) {
        impacto = historia[escenarioActual].imp1;
        scene = siguienteScene;
    }
    else if (zOp2.contains(mousePos)) {
        impacto = historia[escenarioActual].imp2;
        scene = siguienteScene;
    }
    else if (zOp3.contains(mousePos)) {
        impacto = historia[escenarioActual].imp3;
        scene = siguienteScene;
    }
    else if (zOp4.contains(mousePos)) {
        impacto = historia[escenarioActual].imp4;
        scene = siguienteScene;
    }

    if (impacto != -67) {

        cout << "Escenario actual: " << escenarioActual << endl;
        cout << "Scene actual: " << scene << endl;

        mitilina.mostrar();

        if (miJugador) {
            miJugador->aplicarImpacto(mitilina, impacto);
        }
        else {
            cout << "ERROR: miJugador es nullptr" << endl;
        }

        mitilina.mostrar();

        if (mitilina.relacionTerminada()) {
            scene = 199;
            return;
        }
    }
}

void cargarTextura(sf::Texture& textura, string ruta) {

    cout << "Intentando cargar: " << ruta << endl;

    if (!textura.loadFromFile(ruta)) {

        cout << " ERROR cargando: " << ruta << endl;
    }
    else {

        cout << " Cargada correctamente: " << ruta << endl;
    }
}



int main() {


    //crear ventana
    sf::RenderWindow ventana(sf::VideoMode({ 1080, 614 }), "ONE WEEK");

    Novia mitilina; //novia
    unique_ptr<Jugador> miJugador = nullptr; //aqui se le guarda un espacio reservado a la memoria para que no se crashie

    vector<SceneData> escenas(200);
    int escenarioActual = 0;
    vector<Escenario> historia;
    int scene = 0;


    //musica
    sf::Music musica;
    if (!musica.openFromFile("../assets/Musica/musicalofi.mp3")) {
        return -1;
    }
    musica.setLooping(true);// que se repita
    musica.setVolume(25); // volumen
    musica.play(); //reproducir

    //fuentes
    sf::Font fuente;//cargar fuente
    if (!fuente.openFromFile("../assets/Fuentes/Cute Love.ttf")) { //si la fuente no se abre entonces cierra todo
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
    textoPregunta.setPosition({ 150.f, 370.f }); // posicion

    sf::Text top1(fuente), top2(fuente), top3(fuente), top4(fuente); //cargar fuentes

    top1.setCharacterSize(20); //tamano
    top1.setFillColor(sf::Color::White); //color

    top2.setCharacterSize(20);
    top2.setFillColor(sf::Color::White);

    top3.setCharacterSize(20);
    top3.setFillColor(sf::Color::White);

    top4.setCharacterSize(20);
    top4.setFillColor(sf::Color::White);

    top1.setPosition({ 155.f, 480.f });
    top2.setPosition({ 545.f, 480.f });

    top3.setPosition({ 155.f, 555.f });
    top4.setPosition({ 545.f, 555.f });

    // ==========================
    // FONDOS Y TEXTURAS
    // ==========================

    // fondo jugar
    sf::Texture fondoinicio;
    cargarTextura(fondoinicio, "../assets/fondos/inicio.jpeg");

    sf::Sprite bg0(fondoinicio);
    ajustar(bg0, fondoinicio);

    // elige personaje
    sf::Texture personajes;
    cargarTextura(personajes, "../assets/fondos/medescribencomo.jpeg");

    sf::Sprite bg1(personajes);
    ajustar(bg1, personajes);

    // dibujo de la novia
    sf::Texture noviaboton;
    cargarTextura(noviaboton, "../assets/fondos/noviacuadrocontinuar.png");

    sf::Sprite bg2(noviaboton);
    ajustar(bg2, noviaboton);

    sf::Texture fotonovia;
    cargarTextura(fotonovia, "../assets/fondos/noviacontinuar.png");

    sf::Sprite bg3(fotonovia);
    ajustar(bg3, fotonovia);

    // textura mensaje de buenos dias con botones
    sf::Texture msjbuenosdias;
    cargarTextura(msjbuenosdias, "../assets/fondos/buenosdiasopciones.jpeg");

    sf::Sprite bg4(msjbuenosdias);
    ajustar(bg4, msjbuenosdias);

    // textura dia 1
    sf::Texture dia1;
    cargarTextura(dia1, "../assets/fondos/dia1.png");

    sf::Sprite bg5(dia1);
    ajustar(bg5, dia1);

    // pasillo
    sf::Texture pasillo;
    cargarTextura(pasillo, "../assets/fondos/pasillocontinuar.png");

    sf::Sprite bg6(pasillo);
    ajustar(bg6, pasillo);

    // escena tulipanes
    sf::Texture tulipanes;
    cargarTextura(tulipanes, "../assets/fondos/tulipanes.png");

    sf::Sprite bg7(tulipanes);
    ajustar(bg7, tulipanes);

    // escena illeana
    sf::Texture illeana;
    cargarTextura(illeana, "../assets/fondos/illeanapasillo.png");

    sf::Sprite bg8(illeana);
    ajustar(bg8, illeana);

    // escena illeana con opciones
    sf::Texture illeanapasillo;
    cargarTextura(illeanapasillo, "../assets/fondos/illeanapasillocuadro1.png");

    sf::Sprite bg9(illeanapasillo);
    ajustar(bg9, illeanapasillo);

    // escena del cuarto con un boton
    sf::Texture cuartocontexto;
    cargarTextura(cuartocontexto, "../assets/fondos/cuartotexto.png");

    sf::Sprite bg10(cuartocontexto);
    ajustar(bg10, cuartocontexto);

    // escena de decision sobre el domingo
    sf::Texture domingo;
    cargarTextura(domingo, "../assets/fondos/fechaimportante1.png");

    sf::Sprite bg11(domingo);
    ajustar(bg11, domingo);

    // escena de cuarto con boton de continuar de noche
    sf::Texture cuartoscuro;
    cargarTextura(cuartoscuro, "../assets/fondos/cuartosinluz.png");

    sf::Sprite bg12(cuartoscuro);
    ajustar(bg12, cuartoscuro);

    // fin del dia menu
    sf::Texture finmenu;
    cargarTextura(finmenu, "../assets/fondos/findiamenu.png");

    sf::Sprite bgMenu(finmenu);
    ajustar(bgMenu, finmenu);

    // escena de las 4 opciones de regalos
    sf::Texture regalos;
    cargarTextura(regalos, "../assets/fondos/Regalos.png");

    sf::Sprite bgRegalos(regalos);
    ajustar(bgRegalos, regalos);

    // escena del dia 2
    sf::Texture dia2;
    cargarTextura(dia2, "../assets/fondos/Dia2.png");

    sf::Sprite bg13(dia2);
    ajustar(bg13, dia2);

    // alarma del martes
    sf::Texture martes;
    cargarTextura(martes, "../assets/fondos/AlarmaMartes.jpeg");

    sf::Sprite bg14(martes);
    ajustar(bg14, martes);

    // cuarto lluvioso con opciones
    sf::Texture cuartolluvia;
    cargarTextura(cuartolluvia, "../assets/fondos/cuartolluvioso.jpeg");

    sf::Sprite bg15(cuartolluvia);
    ajustar(bg15, cuartolluvia);

    // dia de lluvia al inicio
    sf::Texture lluvia1;
    cargarTextura(lluvia1, "../assets/fondos/lluviacampus.png");

    sf::Sprite bg16(lluvia1);
    ajustar(bg16, lluvia1);

    // escena lluvia 2
    sf::Texture lluvia2;
    cargarTextura(lluvia2, "../assets/fondos/lluvia2.png");

    sf::Sprite bg17(lluvia2);
    ajustar(bg17, lluvia2);

    // lluvia con opciones
    sf::Texture lluviaop;
    cargarTextura(lluviaop, "../assets/fondos/Lluviaopciones.jpeg");

    sf::Sprite bg18(lluviaop);
    ajustar(bg18, lluviaop);

    // escena de lluvia 3
    sf::Texture lluvia3;
    cargarTextura(lluvia3, "../assets/fondos/lluvia3.png");

    sf::Sprite bg19(lluvia3);
    ajustar(bg19, lluvia3);

    // lluvia con girasoles
    sf::Texture lluviagira;
    cargarTextura(lluviagira, "../assets/fondos/lluviagirasoles.png");

    sf::Sprite bg20(lluviagira);
    ajustar(bg20, lluviagira);

    // celular en la lluvia con un mensaje
    sf::Texture telelluvia;
    cargarTextura(telelluvia, "../assets/fondos/telgirasoles.png");

    sf::Sprite bg21(telelluvia);
    ajustar(bg21, telelluvia);

    // escena del mensaje abierto con illeana
    sf::Texture mensajegirasol;
    cargarTextura(mensajegirasol, "../assets/fondos/mensajegira.png");

    sf::Sprite bg22(mensajegirasol);
    ajustar(bg22, mensajegirasol);

    // escena de los girasoles con opciones
    sf::Texture giraop;
    cargarTextura(giraop, "../assets/fondos/girasolesopciones.jpeg");

    sf::Sprite bg23(giraop);
    ajustar(bg23, giraop);

    // escena del pasillo con illeana avisandote del domingo
    sf::Texture pasIlleana;
    cargarTextura(pasIlleana, "../assets/fondos/pasilloilleana.png");

    sf::Sprite bg24(pasIlleana);
    ajustar(bg24, pasIlleana);
    // dia 3
    sf::Texture dia3;
    cargarTextura(dia3, "../assets/fondos/Dia3.jpeg");

    sf::Sprite bg25(dia3);
    ajustar(bg25, dia3);

    // mensaje de texto del miercoles
    sf::Texture mensajem;
    cargarTextura(mensajem, "../assets/fondos/Mensaje del miercoles.PNG");

    sf::Sprite bg26(mensajem);
    ajustar(bg26, mensajem);

    // mensaje de texto del miercoles completo
    sf::Texture mensajemcompleto;
    cargarTextura(mensajemcompleto, "../assets/fondos/Mensaje del miercoles completo.PNG");

    sf::Sprite bg27(mensajemcompleto);
    ajustar(bg27, mensajemcompleto);

    // mensaje de miercoles opciones
    sf::Texture mensajemopciones;
    cargarTextura(mensajemopciones, "../assets/fondos/Mensaje del miercoles opciones.PNG");

    sf::Sprite bg28(mensajemopciones);
    ajustar(bg28, mensajemopciones);

    // cuarto con el cel
    sf::Texture cuartoconcel;
    cargarTextura(cuartoconcel, "../assets/fondos/CuartoconCel.PNG");

    sf::Sprite bg29(cuartoconcel);
    ajustar(bg29, cuartoconcel);

    // Illeana pensando
    sf::Texture illeanapiensa;
    cargarTextura(illeanapiensa, "../assets/fondos/Illiana pensando.PNG");

    sf::Sprite bg30(illeanapiensa);
    ajustar(bg30, illeanapiensa);

    // Illeana pide numero
    sf::Texture illeananumero;
    cargarTextura(illeananumero, "../assets/fondos/Illiana te pide el numero.PNG");

    sf::Sprite bg31(illeananumero);
    ajustar(bg31, illeananumero);

    // Opciones numero
    sf::Texture illeananumop;
    cargarTextura(illeananumop, "../assets/fondos/Illiana te pide el numero opciones.PNG");

    sf::Sprite bg32(illeananumop);
    ajustar(bg32, illeananumop);

    // Illeana avergonzada
    sf::Texture illeanaApenada;
    cargarTextura(illeanaApenada, "../assets/fondos/Illiana avergonzada.PNG");

    sf::Sprite bg33(illeanaApenada);
    ajustar(bg33, illeanaApenada);

    // Mensaje de Illeana
    sf::Texture mensajeIlleana;
    cargarTextura(mensajeIlleana, "../assets/fondos/MensajedeIlliana.PNG");

    sf::Sprite bg34(mensajeIlleana);
    ajustar(bg34, mensajeIlleana);

    // Novia esperando en cafe
    sf::Texture cafe1;
    cargarTextura(cafe1, "../assets/fondos/Tu novia te espera en el cafe.PNG");

    sf::Sprite bg35(cafe1);
    ajustar(bg35, cafe1);

    // Novia cafe 2
    sf::Texture cafe2;
    cargarTextura(cafe2, "../assets/fondos/Noviaencafe2.PNG");

    sf::Sprite bg36(cafe2);
    ajustar(bg36, cafe2);

    // Novia cafe 1
    sf::Texture cafe3;
    cargarTextura(cafe3, "../assets/fondos/Noviaencafe1.PNG");

    sf::Sprite bg37(cafe3);
    ajustar(bg37, cafe3);

    // Opciones cafe
    sf::Texture cafeop;
    cargarTextura(cafeop, "../assets/fondos/Noviaencafeopciones.PNG");

    sf::Sprite bg38(cafeop);
    ajustar(bg38, cafeop);

    // Novia cafe 3
    sf::Texture cafe4;
    cargarTextura(cafe4, "../assets/fondos/Noviaencafe3.PNG");

    sf::Sprite bg39(cafe4);
    ajustar(bg39, cafe4);



   

    // Camino a la tienda
    sf::Texture CaminoaTienda;
    cargarTextura(CaminoaTienda, "../assets/fondos/Caminoatienda.png");

    sf::Sprite bg41(CaminoaTienda);
    ajustar(bg41, CaminoaTienda);

    // Novia con otro
    sf::Texture NoviaOtro;
    cargarTextura(NoviaOtro, "../assets/fondos/NoviaconOtro.png");

    sf::Sprite bg42(NoviaOtro);
    ajustar(bg42, NoviaOtro);

    // Novia con otro pero mas de cerca
    sf::Texture NoviaOtro2;
    cargarTextura(NoviaOtro2, "../assets/fondos/NoviaconOtro2.png");

    sf::Sprite bg43(NoviaOtro2);
    ajustar(bg43, NoviaOtro2);

    // Mejor se va
    sf::Texture MejorSeVa;
    cargarTextura(MejorSeVa, "../assets/fondos/mejorseVa.png");

    sf::Sprite bg44(MejorSeVa);
    ajustar(bg44, MejorSeVa);

    //Escenario 1
    // Nuevo mensaje 
    sf::Texture NuevoMensaje;
    cargarTextura(NuevoMensaje, "../assets/fondos/NuevoMensaje.png");

    sf::Sprite bg45(NuevoMensaje);
    ajustar(bg45, NuevoMensaje);

    // Nuevo mensaje 1
    sf::Texture NuevoMensaje1;
    cargarTextura(NuevoMensaje1, "../assets/fondos/NuevoMensaje1.png");

    sf::Sprite bg46(NuevoMensaje1);
    ajustar(bg46, NuevoMensaje1);

    // Nuevo mensaje Opciones
    sf::Texture NuevoMensajeOpciones;
    cargarTextura(NuevoMensajeOpciones, "../assets/fondos/mensajeOpciones.png");

    sf::Sprite bg47(NuevoMensajeOpciones);
    ajustar(bg47, NuevoMensajeOpciones);

    // Telefono en cama
    sf::Texture TelefonoEnCama;
    cargarTextura(TelefonoEnCama, "../assets/fondos/Telefonoencama.png");

    sf::Sprite bg48(TelefonoEnCama);
    ajustar(bg48, TelefonoEnCama);

    // Dia 4 Escenario 2
    // Illiana salida 1
    sf::Texture IllianaSalida1;
    cargarTextura(IllianaSalida1, "../assets/fondos/Illianasalida1.png");

    sf::Sprite bg49(IllianaSalida1);
    ajustar(bg49, IllianaSalida1);

    // Illiana salida 2
    sf::Texture IllianaSalida2;
    cargarTextura(IllianaSalida2, "../assets/fondos/Illianasalida2.png");

    sf::Sprite bg50(IllianaSalida2);
    ajustar(bg50, IllianaSalida2);

    // Novia lejos
    sf::Texture NoviaLejos;
    cargarTextura(NoviaLejos, "../assets/fondos/novialejos.png");

    sf::Sprite bg51(NoviaLejos);
    ajustar(bg51, NoviaLejos);

    // Novia triste
    sf::Texture NoviaTriste;
    cargarTextura(NoviaTriste, "../assets/fondos/noviatriste.png");

    sf::Sprite bg52(NoviaTriste);
    ajustar(bg52, NoviaTriste);

    // Novia huyendo
    sf::Texture Huyendo;
    cargarTextura(Huyendo, "../assets/fondos/huyendo.png");

    sf::Sprite bg53(Huyendo);
    ajustar(bg53, Huyendo);

    // Nuevo mensaje 1
    sf::Texture CuartoConTelefono;
    cargarTextura(CuartoConTelefono, "../assets/fondos/cuartoconcel.png");

    sf::Sprite bg54(CuartoConTelefono);
    ajustar(bg54, CuartoConTelefono);

    // Ver mensaje
    sf::Texture VerMensaje;
    cargarTextura(VerMensaje, "../assets/fondos/VerMensaje.png");

    sf::Sprite bg55(VerMensaje);
    ajustar(bg55, VerMensaje);

    //Escenario3
    // Mensajes opciones 1
    sf::Texture MensajeOpciones1;
    cargarTextura(MensajeOpciones1, "../assets/fondos/MensajeOpciones1.png");

    sf::Sprite bg56(MensajeOpciones1);
    ajustar(bg56, MensajeOpciones1);

    //Dia5
    
    //dia 5
    sf::Texture Dia6;
    cargarTextura(Dia6, "../assets/fondos/Dia6.jpeg");

    sf::Sprite bg57(Dia6);
    ajustar(bg57, Dia6);

    //Casanovia
    sf::Texture Casanovia;
    cargarTextura(Casanovia, "../assets/fondos/Casanovia.png");

    sf::Sprite bg58(Casanovia);
    ajustar(bg58, Casanovia);

    //Noviapuerta
    sf::Texture Noviapuerta;
    cargarTextura(Noviapuerta, "../assets/fondos/Noviapuerta.png");

    sf::Sprite bg59(Noviapuerta);
    ajustar(bg59, Noviapuerta);

    //Novia Uni
    sf::Texture noviaescuela;
    cargarTextura(noviaescuela, "../assets/fondos/noviaescuela.png");

    sf::Sprite bg60(noviaescuela);
    ajustar(bg60, noviaescuela);

    //IlleanaenojadaPasillo
    sf::Texture Pasilloenojada;
    cargarTextura(Pasilloenojada, "../assets/fondos/pasilloenojada.png");

    sf::Sprite bg61(Pasilloenojada);
    ajustar(bg61, Pasilloenojada);

    //Pasilloenojada
    sf::Texture Pasilloenojada2;
    cargarTextura(Pasilloenojada2, "../assets/fondos/Pasilloenojada2.png");

    sf::Sprite bg62(Pasilloenojada2);
    ajustar(bg62, Pasilloenojada2);

    //Floreria
    sf::Texture Floreria;
    cargarTextura(Floreria, "../assets/fondos/Floreria.png");

    sf::Sprite bg63(Floreria);
    ajustar(bg63, Floreria);

    //Nochecel
    sf::Texture Nochecel;
    cargarTextura(Nochecel, "../assets/fondos/Nochecel.png");

    sf::Sprite bg64(Nochecel);
    ajustar(bg64, Nochecel);


    //Mandarmensaje
    sf::Texture Mandarmensaje;
    cargarTextura(Mandarmensaje, "../assets/fondos/Mandarmensaje.png");

    sf::Sprite bg65(Mandarmensaje);
    ajustar(bg65, Mandarmensaje);

    //AlarmaLunes
    sf::Texture AlarmaLunes;
    cargarTextura(AlarmaLunes, "../assets/fondos/AlarmaLunes.png");

    sf::Sprite bg66(AlarmaLunes);
    ajustar(bg66, AlarmaLunes);

	//AlarmaMiercoles
    sf::Texture AlarmaMiercoles;
    cargarTextura(AlarmaMiercoles, "../assets/fondos/AlarmaMiercoles.png");
    sf::Sprite bg67(AlarmaMiercoles);
	ajustar(bg67, AlarmaMiercoles);

    //AlarmaViernes
    sf::Texture AlarmaViernes;
    cargarTextura(AlarmaViernes, "../assets/fondos/AlarmaViernes.png");
    sf::Sprite bg68(AlarmaViernes);
    ajustar(bg68, AlarmaViernes);

    //Dia 6

    //
    sf::Texture Dia5;
    cargarTextura(Dia5, "../assets/fondos/Dia5.jpeg");
    sf::Sprite bg69(Dia5);
    ajustar(bg69, Dia5);

    //AlarmaSabado
    sf::Texture AlarmaSabado;
    cargarTextura(AlarmaSabado, "../assets/fondos/AlarmaSabado.png");
    sf::Sprite bg70(AlarmaSabado);
    ajustar(bg70, AlarmaSabado);

    //Cuarto tarde
    sf::Texture CuartoTarde;
    cargarTextura(CuartoTarde, "../assets/fondos/Cuartotarde.png");
    sf::Sprite bg71(CuartoTarde);
    ajustar(bg71, CuartoTarde);

    //Llegando al sushi
    sf::Texture LlegandoSushi;
    cargarTextura(LlegandoSushi, "../assets/fondos/llegandosushi.png");
    sf::Sprite bg72(LlegandoSushi);
    ajustar(bg72, LlegandoSushi);

    //Saludo en el sushi
    sf::Texture SaludoSushi;
    cargarTextura(SaludoSushi, "../assets/fondos/Saludosushi.png");
    sf::Sprite bg73(SaludoSushi);
    ajustar(bg73, SaludoSushi);

    //Regalo en el sushi
    sf::Texture RegaloSushi;
    cargarTextura(RegaloSushi, "../assets/fondos/Regalosushi.png");
    sf::Sprite bg74(RegaloSushi);
    ajustar(bg74, RegaloSushi);

    //Felicidad en el sushi
    sf::Texture SushizFeliz;
    cargarTextura(SushizFeliz, "../assets/fondos/Sushifeliz.png");
    sf::Sprite bg75(SushizFeliz);
    ajustar(bg75, SushizFeliz);

    //Felicidad en la comida
    sf::Texture ComidaFeliz;
    cargarTextura(ComidaFeliz, "../assets/fondos/Comidafeliz.png");
    sf::Sprite bg76(ComidaFeliz);
    ajustar(bg76, ComidaFeliz);

    //Escenario 1 Dia6
    //Sushi Mesero
    sf::Texture SushiMesero;
    cargarTextura(SushiMesero, "../assets/fondos/Sushimesero.png");
    sf::Sprite bg77(SushiMesero);
    ajustar(bg77, SushiMesero);

    //Novia escucha
    sf::Texture NoviaEscucha;
    cargarTextura(NoviaEscucha, "../assets/fondos/Noviaescucha.png");
    sf::Sprite bg78(NoviaEscucha);
    ajustar(bg78, NoviaEscucha);

    //Novia escucha OP
    sf::Texture NoviaEscuchaOP;
    cargarTextura(NoviaEscuchaOP, "../assets/fondos/NoviaescuchaOP.png");
    sf::Sprite bg80(NoviaEscuchaOP);
    ajustar(bg80, NoviaEscuchaOP);

    //Novia enojada
    sf::Texture NoviaEnojada;
    cargarTextura(NoviaEnojada, "../assets/fondos/Noviaenojada.png");
    sf::Sprite bg81(NoviaEnojada);
    ajustar(bg81, NoviaEnojada);

    //Novia tensa
    sf::Texture Noviatensa;
    cargarTextura(Noviatensa, "../assets/fondos/Noviatensa.png");
    sf::Sprite bg83(Noviatensa);
    ajustar(bg83, Noviatensa);

    //Illiana llega
    sf::Texture Illeanallega;
    cargarTextura(Illeanallega, "../assets/fondos/Illeanallega.png");
    sf::Sprite bg84(Illeanallega);
    ajustar(bg84, Illeanallega);

    //Illiana llega OP
    sf::Texture IlleanallegaOP;
    cargarTextura(IlleanallegaOP, "../assets/fondos/Illeanallegaop.png");
    sf::Sprite bg85(IlleanallegaOP);
    ajustar(bg85, IlleanallegaOP);

    //Illiana se va
    sf::Texture IlleanaSeVa;
    cargarTextura(IlleanaSeVa, "../assets/fondos/Illeanaseva.png");
    sf::Sprite bg86(IlleanaSeVa);
    ajustar(bg86, IlleanaSeVa);

    sf::Texture menuSalir;
    cargarTextura(menuSalir, "../assets/fondos/menuSalir.jpeg");
    sf::Sprite menuS(menuSalir);
    ajustar(menuS, menuSalir);

// ==========================

// CONFIGURACION DE ESCENAS
// ==========================

    escenas[0] = {
        &menuS,
        "",
        false,
        false,
        false,
        1
    };


/*
    escenas[0] = {
        &bg0,
        "",
        false,
        false,
        false,
        1
    }; */

    escenas[1] = {
        &bg1,
        "",
        false,
        false,
        false,
        2
    };

    escenas[2] = {
        &bg2,
        "Tengo una bella novia. Describiria a mi novia como una chica muy alegre,\n"
        "divertida y personalmente, muy linda.\n"
        "Comenzamos a andar desde la prepa, pero ahora que comenzamos la universidad\n"
        "la he notado un poco rara, lastimosamente no quedamos en la misma universidad pero\n"
        "al menos puedo verla despues de clases. Y asi empezamos nuestra primera semana a\n"
        "distancia,no creo que nos vaya tan mal... eso espero...",
        false,
        true,
        false,
        3
    };

    escenas[3] = {
        &bg3,
        "",
        false,
        false,
        true,
        4
    };

    escenas[4] = {
        &bg5,
        "",
        false,
        true,
        false,
        5
    };

    escenas[5] = {
      &bg4,
     "",
     true,
     false,
     false,
     6,
     0
    };

    escenas[6] = {
        &bg6,
        "Despues de responder el mensaje, guardo el celular y empiezo a caminar hacia\n"
        "mi primera clase.\n"
        "El aire se siente distinto , nueva universidad, nueva rutina, un nuevo comienzo.\n\n"
        "*vibra el celular: mensaje de la novia*",
        false,
        true,
        false,
        7
    };

    escenas[7] = {
        &bg7,
        "Sonrei un poco y segui caminando.\nLa amo...",
        false,
        true,
        false,
        8
    };

    escenas[8] = {
        &bg8,
        "\nJusto cuando estoy por entrar al salon pero algo me interrumpe...\n"
        "Una chica esta recargada sobre la pared sonriendo ligeramente.",
        false,
        true,
        false,
        9
    };

    escenas[9] = {
 &bg9,
 "",
 true,
 false,
 false,
 10,
 1
    };

    escenas[10] = {
        &bg6,
        "Intercambiamos unas palabras antes de que tenga que entrar a clase.\n"
        "No fue nada, pero tampoco nada.\n"
        "Camino a mi asiento intentando no pensar demasiado en eso.\n"
        "Dejo mi mochila y comienzo a poner atencion a la clase.",
        false,
        true,
        false,
        11
    };

    escenas[11] = {
        &bg10,
        "Fue un dia bastante pesado...\n"
        "*ring ring* El celular esta sonando, deberia revisarlo",
        false,
        true,
        false,
        12
    };

    escenas[12] = {
     &bg11,
      "",
     true,
     false,
     false,
     13,
     2
    };
    escenas[13] = {
        &bg12,
        "Dejo el celular y me recuesto.\n"
        "El dia fue pesado y apenas es lunes...\n"
        "No puedo dejar de pensar en ella.\n"
        "El proximo dia sera mejor.",
        false,
        true,
        false,
        14
    };
    escenas[14] = {
 &bgMenu,
 "",
 false,
 false,
 false,
 15
    };

    escenas[15] = {
        &bg13,
        "",
        false,
        true,
        false,
        16
    };

    escenas[16] = {
        &bg14,
        "",
        false,
        false,
        false,
        17
    };

    escenas[17] = {
 &bg15,
 "",
 true,
 false,
 false,
 18,
 3
    };

    escenas[18] = {
    &bg16,
    "Llegando al campus con mi paraguas.\n"
    "La lluvia caia constante...\n"
    "de esas que no molestan, pero tampoco te dejan ignorarla.\n\n"
    "El ambiente era tranquilo.\n"
    "Demasiado tranquilo.\n\n",
    false,
    true,
    false,
    19
    };

    escenas[19] = {
        &bg17,
        "En mi camino me encuentro con Illeana.\n"
        "Parece que quedo atrapada por la lluvia.",
        false,
        true,
        false,
        20
    };

    escenas[20] = {
      &bg18,
     "",
     true,
     false,
     false,
     21,
     4
    };

    escenas[21] = {
        &bg19,
        "Tu: Otra vez tu\nIlleana: Creo que sí coincidimos después de todo\nSe acerca un poco a tu paraguas sin preguntar directamente",
        false,
        true,
        false,
        22
    };

    escenas[22] = {
        &bg20,
        "Empezamos a caminar juntos hacia clase, la conversación era tranquila,\ncon la lluvia llenando los silencios.\nEn el camino, pasamos por los jardines de la escuela y\nnos detuvimos junto a los girasoles.",
        false,
        true,
        false,
        23
    };

    escenas[23] = {
        &bg21,
        "",
        false,
        true,
        false,
        24
    };

    escenas[24] = {
        &bg22,
        "Es tu novia?",
        false,
        true,
        false,
        25
    };

    escenas[25] = {
     &bg23,
     "",
     true,
     false,
     false,
     26,
     5
    };

    escenas[26] = {
  &bg24,
  "Llegamos al edificio de clases y caminamos por el pasillo.\nAntes de entrar Illeana volteó hacia mi."
  "Oye…\nEl domingo…\nva a haber algo interesante cerca de aquí, deberías venir",
  false,
  true,
  false,
  27
    };

    escenas[27] = {
 &bgMenu,
 "",
 false,
 false,
 false,
 28
    };



    // =========================
 // DIA 3
 // =========================

    escenas[28] = {
        &bg25,
        "",
        false,
        true,
        false,
        29
    };

    escenas[29] = {
        &bg10,
        "Ay, parece que ya no esta lloviendo,\npero el ambiente sigue pesado...\n\n"
        "Como si algo se hubiera quedado desde ayer.",
        false,
        true,
        false,
        30
    };

    escenas[30] = {
        &bg26,
        "",
        false,
        true,
        false,
        31
    };

    escenas[31] = {
        &bg27,
        "Decido revisar mi celular y encuentro unos mensajes",
        false,
        true,
        false,
        32
    };

    escenas[32] = {
        &bg28,
        "",
        true,
        false,
        false,
        33,
        8
    };
    escenas[33] = {
&bg29,
"Guardo el celular.\n"
"No se por que...\n"
"pero esa pregunta se sintio mas pesada de lo normal.\n"
"Como si ella hubiera notado algo\n"
"que ni yo entiendo todavia.\n"
"Creo que es mejor alistarme para clases.",
    false,
    true,
    false,
    34
    };

    escenas[34] = {
        &bg6,
        "Al llegar al campus todo seguia normal.\n"
        "Caminaba tranquilo hasta mi salon de clases hasta que—",
        false,
        true,
        false,
        35
    };

    escenas[35] = {
        &bg24,
        "\"Hey\"",
        false,
        true,
        false,
        36
    };

    escenas[36] = {
        &bg24,
        "Illeana se me acerca como si ya fuera costumbre.\n"
        "Parece ser que ya somos amigos.\n"
        "\"Oye...\"\n",
        false,
        true,
        false,
        37
    };

    escenas[37] = {
        &bg30,
        "\"Estuve pensando en lo que te dije ayer\"",
        false,
        true,
        false,
        38
    };

    escenas[38] = { // borton corregido
        &bg31,
        "Lo del domingo...\n"
        "Creo que estaria mas facil si te paso\n"
        "la info por mensaje",
        false,
        true,
        false,
        39
    };

    escenas[39] = { //estoy aqui con las opciones
        &bg32,
        "",
        true,
        false,
        false,
        40,
        9
    };
    escenas[40] = {
&bg24,
"Dudo unos segundos antes de darle mi numero.\n\n"
"No deberia sentirse como algo importante...\n"
"pero aun asi,\n"
"siento una pequeña incomodidad en el pecho.",
    false,
    true,
    false,
    41
    };

    escenas[41] = {
        &bg33,
        "\"Gracias...\n"
        "No pense que dirias que si tan facil\"\n\n"
        "\"El domingo te mando la info\"",
        false,
        true,
        false,
        42
    };


    escenas[42] = {
&bg34,
"Me manda un mensaje para confirmar.\n"
"Antes de guardar el celular,\n"
"alcanzo a notar su foto de perfil.\n"
"Un girasol.\n"
"No se por que,pero me quedo pensando en eso.",
    false,
    true,
    false,
    43
    };

    escenas[43] = {
        &bg6,
        "Seguimos hablando hasta que empezaron las clases.\n"
        "Pero siento que algo cambio...\n"
        "y no se si fue para bien.",
        false,
        true,
        false,
        44
    };

    escenas[44] = {//mira a la novia en el cafe
        &bg35,
        "El dia pasa lento entre clases, apuntes y ruido...\n"
        "Solo espero a que llegue la tarde.",
        false,
        true,
        false,
        45
    };

    escenas[45] = {
        &bg36,
        "Al darse cuenta de mi presencia,\n"
        "se acerca con una sonrisa.\n"
        "De esas sonrisas que no se fingen.",
        false,
        true,
        false,
        46
    };
    escenas[46] = {
&bg37,
"\"¡Hey!\"\n"
"\"Pense que ibas a llegar tarde\"\n\n"
"\"Hoy es un dia importante...\"",
    false,
    true,
    false,
    47
    };

    escenas[47] = {
        &bg36,
        "\"Si te acordaste, verdad?\"",
        false,
        true,
        false,
        48
    };

    escenas[48] = {
        &bg38,
        "",
        true,
        false,
        false,
        49,
        10
    };

    escenas[49] = { //boton en el lugar equivocado
        &bg39,
        "Me mira unos segundos,\n"
        "con una mirada que no puedo descifrar.",
        false,
        true,
        false,
        50
    };

    escenas[50] = {
        &bg36,
        "Pero al final sonrie.\n"
        "Pasamos un buen rato en el cafe.",
        false,
        true,
        false,
        51
    };

    escenas[51] = {
    &bgMenu,
    "",
    false,
    false,
    false,
    52
    };
    escenas[52] = {
    &bgRegalos,
    "",
    false,
    false,
    false,
    -1
    };
    escenas[100] = {
        &bgRegalos,
        "",
        false,
        false,
        false,
        15
    };

    escenas[101] = {
        &bgRegalos,
        "",
        false,
        false,
        false,
        28
    };

    escenas[199] = {
 &bg12,
 "Ella decidio terminar contigo...\n\nGAME OVER",
 false,
 false,
 false,
 199
    };
    // boton invisible inicio

    sf::FloatRect zonaJugar({ 477.f, 400.f }, { 150.f, 60.f });

    //continuar arriba escena 1  arriba
    sf::FloatRect zonaContinuar0({ 795.f, 27.f }, { 250.f, 45.f });



    //boton continuar escena 2 abajo
                                //posicion          ancho y alto
    sf::FloatRect zonaContinuar({ 795.f, 540.f }, { 250.f, 45.f });

    //botones invisibles elige tu personaje
                            // X Y              ancho y alto
    sf::FloatRect zonaToxico({ 21.f, 450.f }, { 200.f, 80.f });
    sf::FloatRect zonaNPC({ 295.f, 450.f }, { 200.f, 80.f });
    sf::FloatRect zonaGym({ 590.f, 450.f }, { 200.f, 80.f });
    sf::FloatRect zonaOtaku({ 863.f, 450.f }, { 200.f, 80.f });

    // zonas de las 4 opciones de elejir el personaje
    sf::FloatRect zOp1({ 140.f, 470.f }, { 390.f, 75.f });
    sf::FloatRect zOp2({ 530.f, 470.f }, { 390.f, 75.f });

    sf::FloatRect zOp3({ 140.f, 545.f }, { 390.f, 75.f });
    sf::FloatRect zOp4({ 530.f, 545.f }, { 390.f, 75.f });


    //botones del menu del final del dia

    sf::FloatRect zonaContM({ 35.f, 463.f }, { 475.f, 80.f }); //zona de continuar
    sf::FloatRect zonaRegalos({ 565.f, 455.f }, { 475.f, 80.f }); //zona de regalos


    //botones de los regalos chocolate flores,carta, pastel collar
     //flores                   //X Y                   //ancho y alto
    sf::FloatRect zonaFlores({ 277.f, 125.f }, { 250.f, 150.f });

    //carta                        x y                ancho y alto
    sf::FloatRect zonaCarta({ 567.f, 125.f }, { 250.f, 150.f });



    //pastel                    x y                 ancho y alto
    sf::FloatRect zonaPastel({ 277.f,320.f }, { 250.f, 150.f });

    //collar                   x y                 ancho y alto
    sf::FloatRect zonaCollar({ 567.f,320.f }, { 250.f, 150.f });

    //boton de alarma 

    sf::FloatRect zonaAlarma1({ 500.f, 305.f }, { 105.f, 50.f });

    sf::FloatRect zonaAlarma2({ 470.f,490.f }, { 80.f, 30.f });



    //BOTONES MENU DE CONTINUAR Y SALIR

    sf::FloatRect zonaMenu({ 378.f, 310.f }, { 390.f, 65.f });
    sf::FloatRect zonaSalir({ 367.f, 440.f }, { 410.f, 65.f });






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

                            miJugador = make_unique<Toxico>();
                            historia = cargarHistoria(0);
                            scene = 2;
                        }

                        else if (zonaNPC.contains(mousePos)) {

                            miJugador = make_unique<NPC>();
                            historia = cargarHistoria(1);
                            scene = 2;
                        }

                        else if (zonaGym.contains(mousePos)) {

                            miJugador = make_unique<Gymrat>();
                            historia = cargarHistoria(2);
                            scene = 2;
                        }

                        else if (zonaOtaku.contains(mousePos)) {

                            miJugador = make_unique<Otaku>();
                            historia = cargarHistoria(3);
                            scene = 2;
                        }
                    }
                    if (scene < 0 || scene >= (int)escenas.size()) {
                        cout << "ERROR: scene fuera de rango" << endl;
                        scene = 0;
                        continue;
                    }
                    SceneData* actual = &escenas[scene];

                    // continuar arriba
                    if (actual->continuarArriba &&
                        zonaContinuar0.contains(mousePos)) {

                        if (
                            actual->siguienteEscena >= 0 &&
                            actual->siguienteEscena < (int)escenas.size()
                            ) {

                            scene = actual->siguienteEscena;
                        }
                        else {

                            cout << "ERROR: siguienteEscena invalida" << endl;
                        }
                        continue;
                    }

                    // continuar abajo
                    if (actual->continuarAbajo &&
                        zonaContinuar.contains(mousePos)) {

                        if (
                            actual->siguienteEscena >= 0 &&
                            actual->siguienteEscena < (int)escenas.size()
                            ) {

                            scene = actual->siguienteEscena;
                        }
                        else {

                            cout << "ERROR: siguienteEscena invalida" << endl;
                        }
                        continue;
                    }



                    // MENU DIA 1
                    // MENU DIA 1
                    if (scene == 14) {

                        if (zonaContM.contains(mousePos)) {
                            scene = 15;
                            continue;
                        }

                        else if (zonaRegalos.contains(mousePos)) {
                            scene = 100;
                            continue;
                        }
                    }
                    // ESCENA ALARMA
                    else if (scene == 16) {

                        if (zonaAlarma1.contains(mousePos)) {
                            scene = 17;
                            continue;
                        }

                        else if (zonaAlarma2.contains(mousePos)) {
                            scene = 17;
                            continue;
                        }
                    }

                    // MENU DIA 2
                    else if (scene == 27) {

                        if (zonaContM.contains(mousePos)) {
                            scene = 28;
                            continue;
                        }

                        else if (zonaRegalos.contains(mousePos)) {
                            scene = 101;
                            continue;
                        }
                    }
                    // MENU FINAL
                    else if (scene == 51) {

                        if (zonaContM.contains(mousePos)) {
                            scene = 52;
                            continue;
                        }

                        else if (zonaRegalos.contains(mousePos)) {
                            scene = 52;
                            continue;
                        }
                    }


                    // REGALOS DIA 1
                    else if (scene == 100) {

                        procesarRegalo(
                            scene,
                            15,
                            mitilina,
                            mousePos,
                            zonaFlores,
                            zonaCarta,
                            zonaPastel,
                            zonaCollar
                        );

                        continue;
                    }

                    // REGALOS FINAL
                    else if (scene == 101) {

                        procesarRegalo(
                            scene,
                            28,
                            mitilina,
                            mousePos,
                            zonaFlores,
                            zonaCarta,
                            zonaPastel,
                            zonaCollar
                        );

                        continue;
                    }

                    // ESCENAS NORMALES CON OPCIONES
                    else if (actual->tieneOpciones) {

                        escenarioActual = actual->indiceHistoria;

                        procesarDecision(
                            scene,
                            actual->siguienteEscena,
                            escenarioActual,
                            historia,
                            miJugador,
                            mitilina,
                            mousePos,
                            zOp1,
                            zOp2,
                            zOp3,
                            zOp4
                        );
                    }



                }
            }
        }

        // mostrar los dibujos
        ventana.clear(sf::Color::Black);

        if (scene < 0 || scene >= (int)escenas.size()) {
            cout << "ERROR: scene fuera de rango" << endl;
            scene = 0;
        }

        SceneData* actual = &escenas[scene];

        // ACTUALIZAR ESCENARIO
        if (actual->indiceHistoria >= 0) {
            escenarioActual = actual->indiceHistoria;
        }
 

        renderizarEscena(
            ventana,
            *actual,
            textolore,
            textoPregunta,
            top1,
            top2,
            top3,
            top4,
            historia,
            escenarioActual
        );

        ventana.display();
    }
    return 0;
}