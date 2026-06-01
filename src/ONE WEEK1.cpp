#pragma execution_character_set("utf-8")
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Audio.hpp>
#include "Clases.h"
#include <random>
#include <ctime>

using namespace std;

struct Escenario {
	wstring pregunta;
	wstring op1, op2, op3, op4;
	int imp1, imp2, imp3, imp4;

};

vector<Escenario> cargarHistoria(int clase) {
	vector <Escenario> h;
	Escenario e0;
	e0.pregunta = L"Ring * Te llega un mensaje de tu novia * : Buenos días {NOMBRE}!!!"; //toxico =1, npc = 1, gymrat =2, otaku = 3

	e0.imp1 = 5;
	e0.imp2 = 3;
	e0.imp3 = 0;
	e0.imp4 = -5;


	if (clase == 0) { //TOXICO
		e0.op1 = L"Buenos días";
		e0.op2 = L"Buenos días bebé, como amaneciste?";
		e0.op3 = L"Buenos días amor";
		e0.op4 = L"Ok";
	}
	else if (clase == 1) { //NPC
		e0.op1 = L"Buenos días";
		e0.op2 = L"Buenos días, pensé en ti al despertar";
		e0.op3 = L"Buenos días princesa";
		e0.op4 = L"Buenos días, hasta que me hablas";
	}
	else if (clase == 2) { //GYMRAT
		e0.op1 = L"Buenos días";
		e0.op2 = L"Buenos días, pensé en ti";
		e0.op3 = L"Buenos días hermosa, hoy entreno amarte más";
		e0.op4 = L"Qué tienen de bueno? me duele todo";
	}
	else if (clase == 3) { //OTAKU
		e0.op1 = L"Buenos días OwO";
		e0.op2 = L"Cómo amaneció mi waifu pechocha";
		e0.op3 = L"Ohayooooo amor 7w7";
		e0.op4 = L"Te tardaste en decirme, bakaaa";
	}

	h.push_back(e0);

	//escena 2
	Escenario e1;
	e1.pregunta = L"Te he visto por aquí, pero no en clases * comienza a acercarse *\nCómo te llamas?";

	e1.imp1 = 0;
	e1.imp2 = -5;
	e1.imp3 = 0;
	e1.imp4 = -3;

	if (clase == 0) { //TOXICO
		e1.op1 = L"*solo la saluda con la mano*";
		e1.op2 = L"Hola, soy {NOMBRE}, pero puedes llamarme tu\nfuturo dueño";
		e1.op3 = L"A ok";
		e1.op4 = L"Qué te importa? *con tono misterioso*";
	}
	else if (clase == 1) { //NPC
		e1.op1 = L"Hola soy {NOMBRE}";
		e1.op2 = L"Hola soy {NOMBRE}, podría acostumbrarme a verte.";
		e1.op3 = L"*con sus manos hace un like*";
		e1.op4 = L"Hola, que lindo coincidir contigo";
	}
	else if (clase == 2) { //GYMRAT
		e1.op1 = L"Hola? Soy {NOMBRE}";
		e1.op2 = L"Mucho gusto soy {NOMBRE},y parece que he\nencontrado una nueva motivación";
		e1.op3 = L"eh?";
		e1.op4 = L"Hola, no creo que nos hayamos visto";
	}
	else if (clase == 3) { //OTAKU
		e1.op1 = L"Hola..*se sonroja*";
		e1.op2 = L"Soy {NOMBRE} pero puedo ser tu sempai 7w7";
		e1.op3 = L"...";
		e1.op4 = L"Ehh mmmm, eres una chica muy kawaii";
	}

	h.push_back(e1);

	Escenario e2;
	e2.pregunta = L"Qué le respondes a tu novia?...";

	e2.imp1 = 3;
	e2.imp2 = 0;
	e2.imp3 = -3;
	e2.imp4 = -5;

	if (clase == 0) { //TOXICO
		e2.op1 = L"Estoy contando los dias para verte preciosa";
		e2.op2 = L"Un año mas de peleas, yeeeeey";
		e2.op3 = L"Qué?, si este domingo estoy ocupado\n(ver tik tok)";
		e2.op4 = L"Es la champions?";
	}
	else if (clase == 1) { //NPC
		e2.op1 = L"Espero con ansias verte";
		e2.op2 = L"Me alegra celebrar un año";
		e2.op3 = L"Qué tiene el domingo?";
		e2.op4 = L"Para qué o qué?";
	}
	else if (clase == 2) { //GYMRAT
		e2.op1 = L"Así es, amor, ya ansío poder verte";
		e2.op2 = L"La serie de nuestra vida ha llegado\na una nueva repetición";
		e2.op3 = L"Se me olvidó, pero no se me olvidó entrenar";
		e2.op4 = L"Ando ocupado construyendo mi mejor version.";
	}
	else if (clase == 3) { //OTAKU
		e2.op1 = L"Me emociona mas que un evento de fortnite\n>.<";
		e2.op2 = L"Ya casi llega la fecha en donde empezó\nnuestro arco de amor";
		e2.op3 = L"El estreno de la nueva temporada de\nMy Dress-Up Darling?";
		e2.op4 = L"Sigue molestando y te anotaré\nen mi libreta >;v";
	}
	h.push_back(e2);

	Escenario e3;
	e3.pregunta = L"Hoy hace un poco mas de frío, parece que va a llover.\nMás vale que vaya bien abrigado.";

	e3.imp1 = 3;
	e3.imp2 = 1;
	e3.imp3 = 0;
	e3.imp4 = -5;

	if (clase == 0) { //TOXICO
		e3.op1 = L"La bufanda que hizo la tipa con la que ando";
		e3.op2 = L"Un abrigo para frio";
		e3.op3 = L"Mi camisa Gucci (Imitación de temu)";
		e3.op4 = L"Una camiseta con la frase\n“El pobre es pobre por que quiere”";
	}
	else if (clase == 1) { //NPC
		e3.op1 = L"La bufanda que me hizo mi novia";
		e3.op2 = L"Algo para calentar";
		e3.op3 = L"Mi confiable sudadera gris";
		e3.op4 = L" Ropa que aún no se ha lavado";
	}
	else if (clase == 2) { //GYMRAT
		e3.op1 = L"La bufanda que me hizo mi PR";
		e3.op2 = L"Blindado contra el frio";
		e3.op3 = L"Sudadera";
		e3.op4 = L"Un pans y un muscle fit";
	}
	else if (clase == 3) { //OTAKU
		e3.op1 = L"La bufanda que me hizo mi noviecita-chan";
		e3.op2 = L"Abrigadito y calientito";
		e3.op3 = L"Una camisa de Naruto";
		e3.op4 = L"Una camisa de una chica sacando la\nlengua y mirando hacia arriba";

	}

	h.push_back(e3);

	Escenario e4;
	e4.pregunta = L"Esta bajo un pequeño techo, mirando la lluvia como si no tuviera prisa.\nLevanta la mirada y me encuentra. Sonrie.";

	e4.imp1 = -3;
	e4.imp2 = -5;
	e4.imp3 = 0;
	e4.imp4 = 2;

	if (clase == 0) { //TOXICO
		e4.op1 = L"Acercarme mientras hago poses chistosas";
		e4.op2 = L"Acercarse y decir: Esperaste mucho por mi?";
		e4.op3 = L"Saludar rápido";
		e4.op4 = L"Hola... Alicia?";
	}
	else if (clase == 1) { //NPC
		e4.op1 = L"Acercarme con una sonrisa";
		e4.op2 = L"Acercarse y decir:Esperaba verte de nuevo";
		e4.op3 = L"Saludar con la mano al pasar.";
		e4.op4 = L"Tratar de alejarme, arrepentirme, acercarme ";
	}
	else if (clase == 2) { //GYMRAT
		e4.op1 = L"Acercarme lentamente";
		e4.op2 = L"Acercase y decir:\nCreo que te estas volviendo parte de mi rutina";
		e4.op3 = L"Saludar";
		e4.op4 = L"Acercarme y decir: Hola...tu...";
	}
	else if (clase == 3) { //OTAKU
		e4.op1 = L"Acercarme corriendo como naruto";
		e4.op2 = L"Acercarme y decir:\nEsto ya parece opening de Your Name";
		e4.op3 = L"Acercarme a Illeana-chan";
		e4.op4 = L"Acercarme haciendo pausas raras";

	}

	h.push_back(e4);

	Escenario e5;
	e5.pregunta = L"Qué le respondes a tu novia?";

	e5.imp1 = 5;
	e5.imp2 = 0;
	e5.imp3 = -5;
	e5.imp4 = -2;

	if (clase == 0) { //TOXICO
		e5.op1 = L"Obvio, con este y con cualquier clima";
		e5.op2 = L"No estaria mal";
		e5.op3 = L"*No responder*";
		e5.op4 = L"Gracias";
	}
	else if (clase == 1) { //NPC
		e5.op1 = L"Y también quiero verte mi vida";
		e5.op2 = L"Yo igual";
		e5.op3 = L"Dejarla en visto";
		e5.op4 = L"oks";
	}
	else if (clase == 2) { //GYMRAT
		e5.op1 = L"No cancelo entrenamiento...pero\npor ti hago una excepción";
		e5.op2 = L"Yo también";
		e5.op3 = L"*No responder*";
		e5.op4 = L"Eso suena a plan obligatorio";
	}
	else if (clase == 3) { //OTAKU
		e5.op1 = L"Yo también te quiero ver pinchecha hemocha,\nnya";
		e5.op2 = L"Chi amor UwU";
		e5.op3 = L"Dejarla en visto";
		e5.op4 = L"ok :/";

	}

	h.push_back(e5);

	Escenario e6;
	e6.pregunta = L"Hoy es un dia importante...\nQué le dices a tu novia?";

	e6.imp1 = 3;
	e6.imp2 = 4;
	e6.imp3 = -3;
	e6.imp4 = -5;

	if (clase == 0) { //TOXICO
		e6.op1 = L"Obvio me acordé";
		e6.op2 = L"Feliz día amor";
		e6.op3 = L"Ah, era hoy?";
		e6.op4 = L"Ni idea";
	}
	else if (clase == 1) { //NPC
		e6.op1 = L"Claro que me acordé";
		e6.op2 = L"Feliz día mi amor";
		e6.op3 = L"Perdón, olvidé la fecha";
		e6.op4 = L"¿Qué tenía hoy?";
	}
	else if (clase == 2) { //GYMRAT
		e6.op1 = L"Nunca olvidaría nuestro día";
		e6.op2 = L"Feliz día preciosa";
		e6.op3 = L"Andaba entrenando...";
		e6.op4 = L"No tuve tiempo";
	}
	else if (clase == 3) { //OTAKU
		e6.op1 = L"Nuestro evento canónico UwU";
		e6.op2 = L"Feliz día waifu";
		e6.op3 = L"Mi memoria filler falló";
		e6.op4 = L"No recuerdo ese arco";
	}

	h.push_back(e6);

	Escenario e7;
	e7.pregunta = L"Ella te pregunta si de verdad la amas...";

	e7.imp1 = 5;
	e7.imp2 = 2;
	e7.imp3 = -3;
	e7.imp4 = -5;

	if (clase == 0) { //TOXICO
		e7.op1 = L"Claro que sí";
		e7.op2 = L"Eres mía";
		e7.op3 = L"No sé";
		e7.op4 = L"Qué flojera";
	}
	else if (clase == 1) { //NPC
		e7.op1 = L"Muchísimo";
		e7.op2 = L"Siempre estaré contigo";
		e7.op3 = L"A veces lo dudo";
		e7.op4 = L"No me molestes";
	}
	else if (clase == 2) { //GYMRAT
		e7.op1 = L"Más que al gym";
		e7.op2 = L"Siempre";
		e7.op3 = L"Estoy confundido";
		e7.op4 = L"Estoy ocupado";
	}
	else if (clase == 3) { //OTAKU
		e7.op1 = L"Más que al anime";
		e7.op2 = L"Tú eres mi protagonista";
		e7.op3 = L"No sé...";
		e7.op4 = L"zzz";
	}

	h.push_back(e7);



	//Dia 3
	// Dentro de cargarHistoria(), después de e7

	Escenario e8;

	e8.pregunta = L"Buenos días <3\n"
		L"Ayer te sentí un poco raro...\n"
		L"Todo bien?";

	e8.imp1 = 5;
	e8.imp2 = 2;
	e8.imp3 = -2;
	e8.imp4 = -5;

	if (clase == 0) { //TOXICO

		e8.op1 = L"Todo bien amor, solo te extrañaba.";
		e8.op2 = L"Sí, solo fue un dia algo cansado.";
		e8.op3 = L"See...";
		e8.op4 = L"Nada que te importe.";

	}
	else if (clase == 1) { //NPC

		e8.op1 = L"Perdón amor, creo que solo estaba cansado.\nTe prometo que estoy bien.";
		e8.op2 = L"Todo bien, solo tuve un dia pesado.";
		e8.op3 = L"Sí, estoy bien.";
		e8.op4 = L"No pasa nada, no te preocupes.";

	}
	else if (clase == 2) { //GYMRAT

		e8.op1 = L"Todo bien preciosa,\nsolo ando destruido del gym.";
		e8.op2 = L"Solo tuve un dia pesado.";
		e8.op3 = L"Estoy bien.";
		e8.op4 = L"Nah, todo normal.";

	}
	else if (clase == 3) { //OTAKU

		e8.op1 = L"Todo bien mi waifu hermosa UwU";
		e8.op2 = L"Solo andaba sin energía ayer.";
		e8.op3 = L"Toy bien.";
		e8.op4 = L"Nada importante nya.";

	}
	h.push_back(e8);

	// =========================
	// DIA 3 - ESCENA 2
	// =========================

	Escenario e9;

	e9.pregunta = L"Illeana me mira directamente.\n"
		L"Me pasas tu numero?";

	e9.imp1 = -4;
	e9.imp2 = 2;
	e9.imp3 = 3;
	e9.imp4 = 0;

	if (clase == 0) { //TOXICO

		e9.op1 = L"Claro, te paso mi numero y lo que quieras.";
		e9.op2 = L"Eh... si quieres.";
		e9.op3 = L"Va, a mi novia le agradara\n que haga amistades.";
		e9.op4 = L"Bueno.";

	}
	else if (clase == 1) { // NPC

		e9.op1 = L"Claro, toma.";
		e9.op2 = L"Mmm... sí, supongo.";
		e9.op3 = L"Bueno, pero cobrare por mensaje.";
		e9.op4 = L"Eh... claro.";

	}
	else if (clase == 2) { // GYMRAT

		e9.op1 = L"Claro.";
		e9.op2 = L"Va, pero casi no reviso el cel.";
		e9.op3 = L"Solo si mandas memes fitness.";
		e9.op4 = L"Sí... toma.";

	}
	else if (clase == 3) { // OTAKU

		e9.op1 = L"Chi UwU";
		e9.op2 = L"Mmm... bueno nya.";
		e9.op3 = L"Solo si no haces spam.";
		e9.op4 = L"E-esta bien.";

	}

	h.push_back(e9);

	// =========================
	// DIA 3 - ESCENA 3
	// =========================

	Escenario e10;

	e10.pregunta = L"Qué respondes?";

	e10.imp1 = 5;
	e10.imp2 = -2;
	e10.imp3 = -3;
	e10.imp4 = -5;

	if (clase == 0) { //TOXICO

		e10.op1 = L"Obvio, feliz cumpleaños";
		e10.op2 = L"Feliz aniversario!";
		e10.op3 = L"El día que nos conocimos?";
		e10.op4 = L"Claro, era... este... ajá...";

	}
	else if (clase == 1) { //NPC

		e10.op1 = L"\"Obvio, feliz cumpleaños\"";
		e10.op2 = L"\"Feliz aniversario...\"";
		e10.op3 = L"\"El primer día que hablamos?\"";
		e10.op4 = L"\"Eh... era una cita cualquiera?\"";

	}
	else if (clase == 2) { //GYMRAT

		e10.op1 = L"\"Obvio, feliz cumpleaños\"";
		e10.op2 = L"\"Feliz aniversario preciosa\"";
		e10.op3 = L"\"Cuándo nos conocimos?\"";
		e10.op4 = L"\"Era una salida?\"";

	}
	else if (clase == 3) { //OTAKU

		e10.op1 = L"\"Obvio waifu, feliz cumpleaños UwU\"";
		e10.op2 = L"\"Feliz aniversario nya\"";
		e10.op3 = L"\"El inicio de nuestro arco?\"";
		e10.op4 = L"\"Era relleno?\"";

	}

	h.push_back(e10);

	//Dia 4
	//Escena1

	Escenario e11;

	e11.pregunta = L"";

	//Pendiente de cambios,
	e11.imp1 = 0;
	e11.imp2 = -2;
	e11.imp3 = -3;
	e11.imp4 = -5;

	if (clase == 0) { //TOXICO

		e11.op1 = L"Pues si tomar un licuado es desayunar,\nentonces sí.";
		e11.op2 = L"Y eso a ti qué te importa?";
		e11.op3 = L"De hecho no, ayer se me revolvió el estómago";
		e11.op4 = L"*ignorarla*";

	}
	else if (clase == 1) { //NPC

		e11.op1 = L"Sí, y tu?";
		e11.op2 = L"Lindo saber que te importa, creí que\nibas a estar muy ocupada";
		e11.op3 = L"No he tenido hambre, he tenido un día muy malo";
		e11.op4 = L"*Dejarla en visto*";

	}
	else if (clase == 2) { //GYMRAT

		e11.op1 = L"Sí, un licuado de proteína y 7 huevos\n revueltos :D";
		e11.op2 = L"¿Qué te importa?";
		e11.op3 = L"Últimamente se me revuelve el estómago";
		e11.op4 = L"*ignorarla*";

	}
	else if (clase == 3) { //OTAKU

		e11.op1 = L"Chi";
		e11.op2 = L"Todo bien, baka :/";
		e11.op3 = L"Me he sentido un poco down  T.T";
		e11.op4 = L"*Dejarla en visto*";

	}

	h.push_back(e11);

	//Escena2

	Escenario e12;

	e12.pregunta = L"Cómo te sentiste después de eso ?\n"
		L"Supongo que muy feo, terminarás con ella? No seas migajero {NOMBRE}.";

	//Pendiente de cambios
	e12.imp1 = -5;
	e12.imp2 = 4;
	e12.imp3 = 0;
	e12.imp4 = 2;

	if (clase == 0) { //TOXICO

		e12.op1 = L"Yo creo que sí, igual ya tengo a alguien más\nen mente";
		e12.op2 = L"Cómo por?, claro que no";
		e12.op3 = L"Tendré que pensarlo";
		e12.op4 = L"*Contemplar el panorama completo mientras\n"
			L"*mantiene una mirada fija a algún lugar*";
	}

	else if (clase == 1) { //NPC

		e12.op1 = L"Sí, creo que sí";
		e12.op2 = L"Han pasado muchas cosas, no creo que sea para tanto";
		e12.op3 = L"Hemos estado juntos mucho tiempo, debo pensarlo";
		e12.op4 = L"...";

	}
	else if (clase == 2) { //GYMRAT

		e12.op1 = L"Creo que sí ... fue bueno mientras duró";
		e12.op2 = L"Por supuesto que no";
		e12.op3 = L"Es una decisión difícil, debo pensarlo";
		e12.op4 = L"*Alza la vista al cielo pensando*";

	}
	else if (clase == 3) { //OTAKU

		e12.op1 = L"Chi UnU";
		e12.op2 = L"Baka, no creo que sea tanto";
		e12.op3 = L"No lo se Illeana-chan";
		e12.op4 = L"*hacer ruidos raros*";

	}

	h.push_back(e12);

	//Escena3

	Escenario e13;

	e13.pregunta = L"Te sientes culpable... decides buscarla";

	//Pendiente de cambios
	e13.imp1 = 0;
	e13.imp2 = 3;
	e13.imp3 = -4;
	e13.imp4 = -5;

	if (clase == 0) { //TOXICO

		e13.op1 = L"No puede ser, ni modo, toca disculparme";
		e13.op2 = L"Perfecto, tengo que llamarle para disculparme";
		e13.op3 = L"Mmm, ya me enojé luego lo intento arreglar";
		e13.op4 = L"Mejor intento pescar un nuevo pez,\n"
			L"Illeana suena a una buena opción";

	}
	else if (clase == 1) { //NPC

		e13.op1 = L"Ay no, debo mandarle mensaje";
		e13.op2 = L"Ay no, debo hablar con ella, debería marcarle";
		e13.op3 = L"Que desastre";
		e13.op4 = L"Debo... Debo hablar con alguien. Illeana quizá este libre";

	}
	else if (clase == 2) { //GYMRAT

		e13.op1 = L"Necesito mandarle mensaje, no quiero que\nestemos mal";
		e13.op2 = L"Necesito marcarle, es urgente";
		e13.op3 = L"*Te pones a hacer lagartijas*";
		e13.op4 = L"Ileana me comprende más, debería hablarle";

	}
	else if (clase == 3) { //OTAKU

		e13.op1 = L"Ooh oh, debo mandarle mensaje a mi sempai";
		e13.op2 = L"No puede ser, le debo marcar a mi novia-chan";
		e13.op3 = L"*te pones a ver anime*";
		e13.op4 = L"Debería buscar a Illeana-chan, ella sí me entiende";

	}

	h.push_back(e13);

	//Dia5 Escenario1

	Escenario e14;

	e14.pregunta = L"“Sé que la regue  y disculpame, actué por impulso y no pienso lo que hago.\n"
		L"Me quiero esforzar para que esto funcione, así que te aseguro que pondre\n"
		L"todo lo que pueda de mi parte. Quiero que sepas lo arrepentido que estoy.\n";

	e14.imp1 = 1;
	e14.imp2 = 2;
	e14.imp3 = 4;
	e14.imp4 = -5;

	if (clase == 0) { //TOXICO

		e14.op1 = L"Puedo demostrar cuan arrepentido estoy con\n un abrazo?";
		e14.op2 = L"*Le besas la frente*";
		e14.op3 = L"Me aceptas un beso?";
		e14.op4 = L"Bueno, ya hice mi trabajo, ya estamos bien,\n no?";

	}
	else if (clase == 1) { //NPC

		e14.op1 = L"Me aceptas un abrazo como disculpa?";
		e14.op2 = L"*le da un beso en la frente*";
		e14.op3 = L"Un beso de reconciliacion?";
		e14.op4 = L"Bueno, ya lo arreglamos, no?";

	}
	else if (clase == 2) { //GYMRAT

		e14.op1 = L"*Te acercas y la abrazas*";
		e14.op2 = L"*Te acercas y le das un beso en la frente*";
		e14.op3 = L"*Te acercas y la besas*";
		e14.op4 = L"Bueno, ya nos arreglamos, no?";

	}
	else if (clase == 3) { //OTAKU

		e14.op1 = L"Podrías perdonar a este terroncito de azúcar\n"
			L"con un abrazo";
		e14.op2 = L"*Le da un beso de manera kawaii*";
		e14.op3 = L"Un besito de reconciliación, waifu-chan?";
		e14.op4 = L"Ash, ya lo arreglamos baka?";

	}

	h.push_back(e14);

	//Dia5 Escenario2
	Escenario e15;

	e15.pregunta = L"Como de costumbre, milagrosamente te encontraste a Illeana.\n"
		L"Decides acercarte y comienzas a darle una explicación sobre lo ayer";

	e15.imp1 = -5;
	e15.imp2 = -3;
	e15.imp3 = 1;
	e15.imp4 = -5;

	if (clase == 0) { //TOXICO

		e15.op1 = L"Perdón por la aparición de mi novia\n"
			L"a veces es molesta";
		e15.op2 = L"Perdón por irme sin explicación";
		e15.op3 = L"Qué rollo con el pollo";
		e15.op4 = L"Oye, por tu culpa me tuve que disculpar";
	}
	else if (clase == 1) { //NPC

		e15.op1 = L"Discúlpame, no esperaba que apareciera";
		e15.op2 = L"No quise dejarte así, perdóname";
		e15.op3 = L"Así que... Cómo te fue con la tarea?";
		e15.op4 = L"Oye, ayer me metiste en un problemón";

	}
	else if (clase == 2) { //GYMRAT

		e15.op1 = L"Disculpa, mi novia a veces es así";
		e15.op2 = L"Perdón por dejarte plantada, no fue mi intención";
		e15.op3 = L"Ey, cómo estás? Todo bien?";
		e15.op4 = L"Sabes que me has metido en problemas";
	}
	else if (clase == 3) { //OTAKU

		e15.op1 = L"Perdón que mi novia nos interrumpiera Illeana-chan";
		e15.op2 = L"Perdón por dejarte plantada como árbol";
		e15.op3 = L"Ya viste YBC? 7w7";
		e15.op4 = L"Oi oi oi, me metiste en problemas";

	}

	h.push_back(e15);

	//Dia5 Escenario3
	Escenario e16;

	e16.pregunta = L"Llegando, notaste muchas flores bonitas, cuál escoges?";

	e16.imp1 = 2;
	e16.imp2 = -5;
	e16.imp3 = 5;
	e16.imp4 = -2;

	if (clase == 0) { //TOXICO

		e16.op1 = L"Rosas, un clásico";
		e16.op2 = L"Girasoles, el más barato";
		e16.op3 = L"Tulipanes, a algunos les gusta";
		e16.op4 = L"Flores beso, el nombre  y la apariencia se ven\n interesantes";

	}
	else if (clase == 1) { //NPC

		e16.op1 = L"La rosa es una flor muy clásica";
		e16.op2 = L"Los girasoles brindan mucha alegría";
		e16.op3 = L"Los tulipanes representan el amor\n perfecto, no?";
		e16.op4 = L"Es muy única";

	}
	else if (clase == 2) { //GYMRAT

		e16.op1 = L"Las rosas siempre son las mejores";
		e16.op2 = L"Unos brillantes girasoles estarían bien, no?";
		e16.op3 = L"Los tulipanes son bastante hermosos";
		e16.op4 = L"Las flores beso son tan buenas como \nel ejercicio";

	}
	else if (clase == 3) { //OTAKU

		e16.op1 = L"Supongo que las rosas le gustarán";
		e16.op2 = L"Los girasoles como la frase: gira, gira\n tu calzón";
		e16.op3 = L"Los tulipanes son hemochos uwu";
		e16.op4 = L"Es al más barata, podre usar lo demás\n para un manga";

	}

	h.push_back(e16);


	//Dia5 Escenario4
	Escenario e17;

	e17.pregunta = L"Le escribes";

	e17.imp1 = 2;
	e17.imp2 = 5;
	e17.imp3 = -1;
	e17.imp4 = -5;

	if (clase == 0) { //TOXICO

		e17.op1 = L"Ponte linda, mañana paso por ti a las 6pm";
		e17.op2 = L"Pide permiso para salir mañana a las 6pm";
		e17.op3 = L"Te tengo una sorpresa mañana a las 6pm,\n alístate";
		e17.op4 = L"Oye, mañana teníamos que hacer algo?";

	}
	else if (clase == 1) { //NPC

		e17.op1 = L"Prepárate. Mañana paso por ti a las 6 ;)";
		e17.op2 = L"Pide permiso porque mañana voy a pasar a\n las 6";
		e17.op3 = L"Te tengo un regalo :), mañana a las 6\n prepárate para ser sorprendida";
		e17.op4 = L"Entonces, mañana hay plan o no?";

	}
	else if (clase == 2) { //GYMRAT

		e17.op1 = L"Mañana tú y yo, 6pm, para que estés lista";
		e17.op2 = L"Oye, pide permiso, mañana pasaré por ti\n a las 6";
		e17.op3 = L"Tengo una sorpresa para ti, pero debes de\n estar lista a las 6";
		e17.op4 = L"Te parece si no voy al gym mañana y\n salimos? Cómo a las 6?";

	}
	else if (clase == 3) { //OTAKU

		e17.op1 = L"Sempaiiii, mañana a las 6 OwO";
		e17.op2 = L"Mañana paso por ti a las 6 , ponte\n guapa...";
		e17.op3 = L"Mañana desbloqueas evento exclusivo\n conmigo.";
		e17.op4 = L"Supongo que mañana continua esta situacion\n rara entre nosotros.";

	}

	h.push_back(e17);

	//Dia6 Escenario 1
	Escenario e18;

	e18.pregunta = L"*Llega el mesero a tomar su orden*,\n”Ya están listos para ordenar?”";

	e18.imp1 = 0;
	e18.imp2 = -2;
	e18.imp3 = 3;
	e18.imp4 = -5;

	if (clase == 0) { //TOXICO

		e18.op1 = L"Claro, quiero un rollo california en salsa chipotle";
		e18.op2 = L"Pues hemos estado como 10 minutos aqui,\nasi que, yo diria que sí";
		e18.op3 = L"Esta vez quiero que mi amor escoga por mi";
		e18.op4 = L"Al fin, mínimo compensas la tardanza con\nuna buena vista, seria un gohan";

	}
	else if (clase == 1) { //NPC

		e18.op1 = L"Si, nos gustarían los rollos especiales de San Valentín";
		e18.op2 = L"Desde hace como 10 minutos. Pero lo bueno que llegas";
		e18.op3 = L"Amm, si no sé que quieras amor...";
		e18.op4 = L"Con esos ojitos, te perdono la tardanza,\nvamos a querer unos rollos\"";

	}
	else if (clase == 2) { //GYMRAT

		e18.op1 = L"Claro, deseamos unos rollos especiales de San Valentín,\ncon extra proteina por favor\"";
		e18.op2 = L"Pensaba que estabas muy ocupado,\nmira quiero unos rollos San Valentín\n a las 6\"";
		e18.op3 = L"Manana desbloqueas evento exclusivo\n conmigo.\"";
		e18.op4 = L"Que bueno que llegas, vamos a ordenar\n unos rollos San Valentín\"";

	}
	else if (clase == 3) { //OTAKU

		e18.op1 = L"haiii, quiero crunchyroll para los dos";
		e18.op2 = L"Hazta que llegas maid-sama :'v";
		e18.op3 = L"Sii... que pida ella por mi...";
		e18.op4 = L"Creo que este restaurante tiene demasiado  fanservice 7w7";

	}

	h.push_back(e18);

	//Dia6 Escenario 2
	Escenario e19;

	e19.pregunta = L"“Sin darme cuenta, mi novia me estaba preguntando sobre quién era ella.\nN: “{NOMBRE} Acaso no es la chica del otro día?”";

	e19.imp1 = -1;
	e19.imp2 = 3;
	e19.imp3 = -3;
	e19.imp4 = -2;

	if (clase == 0) { //TOXICO

		e19.op1 = L"¿Sepa, tu la conoces de algo?";
		e19.op2 = L"Ah si, es una amiga de mi escuela";
		e19.op3 = L"Ah si, es mi besty";
		e19.op4 = L"*Te come la lengua el gato*";

	}
	else if (clase == 1) { //NPC

		e19.op1 = L"Ah, es ahm- una conocida";
		e19.op2 = L"Oh, una amiga de la escuela";
		e19.op3 = L"Es una...amiguita de la escuela";
		e19.op4 = L"*No responder*";

	}
	else if (clase == 2) { //GYMRAT

		e19.op1 = L"Sinceramente, no sé quien es, no la conozco";
		e19.op2 = L"Mira amor ella es Illeana, de la uni";
		e19.op3 = L"Ella es Illeana, es una amiguita de la universidad";
		e19.op4 = L"*No responder*";

	}
	else if (clase == 3) { //OTAKU

		e19.op1 = L"Ella? Nah, literalmente NPC genérico del fondo";
		e19.op2 = L"Es compa del server, nada mas.";
		e19.op3 = L"Ella solo es una amiguita, no le des mucha bola jeje";
		e19.op4 = L"*No responder*";

	}

	h.push_back(e19);

	//Dia6 Escenario 3
	Escenario e20;

	e20.pregunta = L"Illeana: Holaa feliz san valentín {NOMBRE},\nquién es ella??? *Qué respondes?*";
	e20.imp1 = 2;
	e20.imp2 = -2;
	e20.imp3 = -5;
	e20.imp4 = 5;

	if (clase == 0) { //TOXICO

		e20.op1 = L"Ella es mi novia";
		e20.op2 = L"Qué ondaaaa, como andas?";
		e20.op3 = L"Se podría decir que es mi mejor amiga";
		e20.op4 = L"Ella es mi mujer";

	}
	else if (clase == 1) { //NPC

		e20.op1 = L"Ella es mi novia";
		e20.op2 = L"Hola Illeana, no te había visto";
		e20.op3 = L"Es una amiga muy cercana";
		e20.op4 = L"Ah, Illeana, te presento al amor de mi vida";

	}
	else if (clase == 2) { //GYMRAT

		e20.op1 = L"Ileana, te presento a mi novia";
		e20.op2 = L"Ey Ileana, no había notado tu presencia";
		e20.op3 = L"Ella es una amiga";
		e20.op4 = L"Ella es mi novia, mi amor, mi reina, mi motivación para vivir";

	}
	else if (clase == 3) { //OTAKU

		e20.op1 = L"Es mi novia, la waifu oficial del canon";
		e20.op2 = L"Ahhh… cutscene incómoda... Skip...";
		e20.op3 = L"Es mi onichan nada mas";
		e20.op4 = L"Si, es ella... Mi personaje de rango S";

	}

	h.push_back(e20);

	Escenario e21;

	e21.pregunta = L"Hice reservación a las 6:00 , después de todo me toca invitarte.\nTe amo\n*Qué respondes?*";
	e21.imp1 = 2;
	e21.imp2 = -2;
	e21.imp3 = -5;
	e21.imp4 = 5;

	if (clase == 0) { //TOXICO

		e21.op1 = L"Te amo";
		e21.op2 = L"Ah ok";
		e21.op3 = L"...";
		e21.op4 = L"Yo igual";

	}
	else if (clase == 1) { //NPC

		e21.op1 = L"Te amo";
		e21.op2 = L"Gracias";
		e21.op3 = L"...";
		e21.op4 = L"Yo igual";

	}
	else if (clase == 2) { //GYMRAT

		e21.op1 = L"Te amo";
		e21.op2 = L"...Muchas gracias, me alegra que lo sientas así";
		e21.op3 = L"...";
		e21.op4 = L"Yo igual";

	}
	else if (clase == 3) { //OTAKU

		e21.op1 = L"Te amo";
		e21.op2 = L"Te lo agradezco";
		e21.op3 = L"...";
		e21.op4 = L"Yo también";

	}

	h.push_back(e21);
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
		mitilina.modificarConfianza(2);
	}

	else if (zonaCarta.contains(mousePos)) {
		regaloElegido = true;
		mitilina.modificarConfianza(2);
	}

	else if (zonaPastel.contains(mousePos)) {
		regaloElegido = true;
		mitilina.modificarFelicidad(2);
	}

	else if (zonaCollar.contains(mousePos)) {
		regaloElegido = true;
		mitilina.modificarFelicidad(2);
	}

	// si eligio cualquier regalo
	if (regaloElegido) {

		cout << "Le diste un regalo a tu novia." << endl;

<<<<<<< HEAD
<<<<<<< Updated upstream
        mitilina.mostrar();
=======
		
>>>>>>> Stashed changes
=======
		scene = siguienteScene;
	}
}
>>>>>>> b5a15ad3008740d684471c53614442e5e5cfb646

//esta funcion busca todos lugares donde este {NOMBRE} y los reemplaza por el nombre del jugador, para que no se vea tan raro en el texto
std::wstring reemplazarNombre(
	std::wstring texto,
	const std::wstring& nombreJugador
) {
	size_t pos = texto.find(L"{NOMBRE}");

	while (pos != std::wstring::npos) {
		texto.replace(pos, 8, nombreJugador);
		pos = texto.find(L"{NOMBRE}", pos + nombreJugador.size());
	}

	return texto;
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
	int escenarioActual,
	const std::wstring& nombreJugador //agrega el nombre del jugador para que se pueda usar en las preguntas y opciones
) {
	if (historia.empty()) {
		return;
	}

	if (escenarioActual < 0 || escenarioActual >= historia.size()) {
		return;
	}
	pregunta.setString(
		reemplazarNombre(
			historia[escenarioActual].pregunta,
			nombreJugador
		)
	);

	op1.setString(
		reemplazarNombre(
			historia[escenarioActual].op1,
			nombreJugador
		)
	);

	op2.setString(
		reemplazarNombre(
			historia[escenarioActual].op2,
			nombreJugador
		)
	);

	op3.setString(
		reemplazarNombre(
			historia[escenarioActual].op3,
			nombreJugador
		)
	);

	op4.setString(
		reemplazarNombre(
			historia[escenarioActual].op4,
			nombreJugador
		)
	);

	ventana.draw(pregunta);
	ventana.draw(op1);
	ventana.draw(op2);
	ventana.draw(op3);
	ventana.draw(op4);
}
struct SceneData {
	sf::Sprite* fondo = nullptr;

	std::wstring texto = L"";

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
	int escenarioActual,
	const std::wstring& nombreJugador
) {

	// dibujar fondo
	if (escena.fondo != nullptr) {
		ventana.draw(*escena.fondo);
	}

	// dibujar texto normal
	if (!escena.texto.empty()) {

		textolore.setString(
			reemplazarNombre(escena.texto, nombreJugador)
		);
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
			escena.indiceHistoria,
			nombreJugador
		);
	}
	else {

		textoPregunta.setString(L"");

		top1.setString(L"");
		top2.setString(L"");
		top3.setString(L"");
		top4.setString(L"");
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

		bool afectaFelicidad = (escenarioActual == 0 ||
			escenarioActual == 2 ||
			escenarioActual == 4 ||
			escenarioActual == 6 ||
			escenarioActual == 8 ||
			escenarioActual == 10 ||
			escenarioActual == 12 ||
			escenarioActual == 14 ||
			escenarioActual == 16 ||
			escenarioActual == 18 ||
			escenarioActual == 20 
			);
		if (afectaFelicidad) {

			mitilina.modificarFelicidad(impacto);
			mitilina.actualizarAmor();
		}
		else {

			mitilina.modificarConfianza(impacto);
			mitilina.actualizarAmor();
		}

<<<<<<< HEAD
<<<<<<< Updated upstream
       mitilina.mostrar();
=======
		
>>>>>>> Stashed changes

        if (mitilina.relacionTerminada()) {
            scene = 199;
            return;
        }
    }
=======
		if (mitilina.relacionTerminada()) {
			scene = 199;
			return;
		}
	}
>>>>>>> b5a15ad3008740d684471c53614442e5e5cfb646
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

//Para ver si el jugador usa caracteres validos, ya que se modifico la fuente
bool esCaracterValido(wchar_t c) {
	// Permitir espacio
	if (c == L' ') return true;
	// Permitir letras estándar (A-Z y a-z)
	if ((c >= L'a' && c <= L'z') || (c >= L'A' && c <= L'Z')) return true;
	// Permitir Ñ y ñ
	if (c == L'ñ' || c == L'Ñ') return true;
	// Permitir vocales con acentos en español (áéíóú ÁÉÍÓÚ)
	if (c == L'á' || c == L'é' || c == L'í' || c == L'ó' || c == L'ú' ||
		c == L'Á' || c == L'É' || c == L'Í' || c == L'Ó' || c == L'Ú') return true;

	return false; // Cualquier otra cosa (números, símbolos raros) se ignora porque borre algunos
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
	if (!fuente.openFromFile("../assets/Fuentes/cute_love_regular.ttf")) { //si la fuente no se abre entonces cierra todo
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

	//nombreJugador
	std::wstring nombreJugador = L"";
	sf::Text textoNombre(fuente);
	textoNombre.setFont(fuente);//se carga la fuente
	textoNombre.setCharacterSize(25);//tamano
	textoNombre.setFillColor(sf::Color::White);//color
	textoNombre.setPosition({ 460.f, 300.f });// posicion

	//rectangulo del cursor
	sf::RectangleShape cajaTexto;
	cajaTexto.setSize({ 180.f, 25.f });
	cajaTexto.setFillColor(sf::Color(255, 214, 153));
	cajaTexto.setPosition({ 455.f, 305.f });

	sf::Clock relojCursor;//para que parpadee la linea del cursor
	bool mostrarCursor = true;

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
	cargarTextura(martes, "../assets/fondos/AlarmaMartes.png");

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

	//Dia 4
	// Alarma Jueves
	sf::Texture AlarmaJueves;
	cargarTextura(AlarmaJueves, "../assets/fondos/AlarmaJueves.PNG");

	sf::Sprite bg40(AlarmaJueves);
	ajustar(bg40, AlarmaJueves);

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

<<<<<<< HEAD
    //Illiana se va
    sf::Texture IlleanaSeVa;
    cargarTextura(IlleanaSeVa, "../assets/fondos/Illeanaseva.png");
    sf::Sprite bg86(IlleanaSeVa);
    ajustar(bg86, IlleanaSeVa);

    //Illiana se va
    sf::Texture pausa;
    cargarTextura(pausa, "../assets/fondos/Pausa.jpeg");
    sf::Sprite bg87(pausa);
    ajustar(bg87, pausa);

// ==========================
// CONFIGURACION DE ESCENAS
// ==========================
=======
	//Illiana se va
	sf::Texture IlleanaSeVa;
	cargarTextura(IlleanaSeVa, "../assets/fondos/Illeanaseva.png");
	sf::Sprite bg86(IlleanaSeVa);
	ajustar(bg86, IlleanaSeVa);
>>>>>>> b5a15ad3008740d684471c53614442e5e5cfb646

	//Nombredeugador
	sf::Texture NombredeJugador;
	cargarTextura(NombredeJugador, "../assets/fondos/NombreJugador.png");
	sf::Sprite bg87(NombredeJugador);
	ajustar(bg87, NombredeJugador);

	//comidaAmigos 
	sf::Texture ComidaAmigos;
	cargarTextura(ComidaAmigos, "../assets/fondos/ComidaAmigos.png");
	sf::Sprite bg88(ComidaAmigos);
	ajustar(bg88, ComidaAmigos);

	//carro
	sf::Texture Carro;
	cargarTextura(Carro, "../assets/fondos/Carro.png");
	sf::Sprite bg89(Carro);
	ajustar(bg89, Carro);

	//Dia7
	sf::Texture Dia4;
	cargarTextura(Dia4, "../assets/fondos/Dia4.jpeg");
	sf::Sprite bg90(Dia4);
	ajustar(bg90, Dia4);

	//Mensaje7
	sf::Texture Mensaje7;
	cargarTextura(Mensaje7, "../assets/fondos/Mensaje7.png");
	sf::Sprite bg91(Mensaje7);
	ajustar(bg91, Mensaje7);

	//Escenario21
	sf::Texture Escenario21;
	cargarTextura(Escenario21, "../assets/fondos/Escenario21.png");
	sf::Sprite bg92(Escenario21);
	ajustar(bg92, Escenario21);

	//ELIGE
	sf::Texture Elige;
	cargarTextura(Elige, "../assets/fondos/elige.png");
	sf::Sprite bg93(Elige);
	ajustar(bg93, Elige);

	//Noviabueno
	sf::Texture Noviabueno;
	cargarTextura(Noviabueno, "../assets/fondos/noviabueno.png");
	sf::Sprite bg94(Noviabueno);
	ajustar(bg94, Noviabueno);

	//noviasorpresa
	sf::Texture Noviasorpresa;
	cargarTextura(Noviasorpresa, "../assets/fondos/Noviasorpresa.png");
	sf::Sprite bg95(Noviasorpresa);
	ajustar(bg95, Noviasorpresa);

	//noviamalo
	sf::Texture Noviamalo;
	cargarTextura(Noviamalo, "../assets/fondos/noviamalo.png");
	sf::Sprite bg96(Noviamalo);
	ajustar(bg96, Noviamalo);

	//Illeananotanmalo
	sf::Texture Illeananotanmalo;
	cargarTextura(Illeananotanmalo, "../assets/fondos/Illeananotanmalo.png");
	sf::Sprite bg97(Illeananotanmalo);
	ajustar(bg97, Illeananotanmalo);

	//Illeanamalo
	sf::Texture Illeanamalo;
	cargarTextura(Illeanamalo, "../assets/fondos/Illeanamalo.png");
	sf::Sprite bg98(Illeanamalo);
	ajustar(bg98, Illeanamalo);

	//Pantallafinal
	sf::Texture Pantallafinal;
	cargarTextura(Pantallafinal, "../assets/fondos/Pantallafinal.png");
	sf::Sprite bg99(Pantallafinal);
	ajustar(bg99, Pantallafinal);

	//creditos
	sf::Texture creditos;
	cargarTextura(creditos, "../assets/fondos/creditos.png");
	sf::Sprite bg100(creditos);
	ajustar(bg100, creditos);

	//pausaconesc
	sf::Texture pausaconesc;
	cargarTextura(pausaconesc, "../assets/fondos/pausa.png");
	sf::Sprite bg101(pausaconesc);
	ajustar(bg101, pausaconesc);

	// ==========================
	// CONFIGURACION DE ESCENAS
	// ==========================

	escenas[0] = SceneData{
		&bg0,
		L"",
		false,
		false,
		false,
		1
	};

	escenas[1] = SceneData{
		&bg87,
		L"",
		false,
		false,
		false,
		1
	};

	escenas[2] = SceneData{
		&bg1,
		L"",
		false,
		false,
		false,
		3
	};

	escenas[3] = SceneData{
		&bg2,
		L"Tengo una bella novia. Describiría a mi novia como una chica muy alegre,\n"
		L"divertida y muy linda.\n"
		L"Comenzamos a andar desde la prepa, pero ahora que comenzamos la universidad\n"
		L"la he notado un poco rara, lastimosamente no quedamos en la misma universidad pero\n"
		L"al menos puedo verla despues de clases. Y asi empezamos nuestra primera semana a\n"
		L"distancia,no creo que nos vaya tan mal... Eso espero...",
		false,
		true,
		false,
		4
	};

	escenas[4] = SceneData{
		&bg3,
		L"",
		false,
		false,
		true,
		5
	};

	escenas[5] = SceneData{
		&bg5,
		L"",
		false,
		true,
		false,
		6
	};
	escenas[6] = SceneData{
	  &bg66,
	 L"",
	 false,
	 false,
	 false,
	 7
	};

	escenas[7] = SceneData{
	  &bg4,
	 L"",
	 true,
	 false,
	 false,
	 8,
	 0
	};

	escenas[8] = SceneData{
		&bg6,
		L"Después de responder el mensaje, guardo el celular y empiezo a caminar hacia\n"
		L"mi primera clase.\n"
		L"El aire se siente distinto , nueva universidad, nueva rutina, un nuevo comienzo.\n\n"
		L"*vibra el celular: mensaje de la novia*",
		false,
		true,
		false,
		9
	};

	escenas[9] = SceneData{
		&bg7,
		L"Sonreí un poco y seguí caminando.\nLa amo...",
		false,
		true,
		false,
		10
	};

	escenas[10] = SceneData{
		&bg8,
		L"\nJusto cuando estoy por entrar al salón pero algo me interrumpe...\n"
		L"Una chica esta recargada sobre la pared sonriendo ligeramente.",
		false,
		true,
		false,
		11
	};

	escenas[11] = SceneData{
 &bg9,
L"",
 true,
 false,
 false,
 12,
 1
	};

	escenas[12] = SceneData{
		&bg6,
		L"Intercambiamos unas palabras antes de que tenga que entrar a clase.\n"
		L"No fue nada, pero tampoco nada.\n"
		L"Camino a mi asiento intentando no pensar demasiado en eso.\n"
		L"Dejo mi mochila y comienzo a poner atención a la clase.",
		false,
		true,
		false,
		13
	};

	escenas[13] = SceneData{
		&bg10,
		L"Fue un día bastante pesado...\n"
		L"*ring ring* El celular esta sonando, debería revisarlo",
		false,
		true,
		false,
		14
	};

	escenas[14] = SceneData{
	 &bg11,
	  L"",
	 true,
	 false,
	 false,
	 15,
	 2
	};
	escenas[15] = SceneData{
		&bg12,
		L"Que día tan interesante. Primer día de uni, y de mi \n"
		L"nueva vida...\n"
		L"\n\n"
		L"Sencillamente perfecto.",
		false,
		true,
		false,
		16
	};
	escenas[16] = SceneData{
 &bgMenu,
 L"",
 false,
 false,
 false,
 17
	};

	escenas[17] = SceneData{
		&bg13,
		L"",
		false,
		true,
		false,
		18
	};

	escenas[18] = SceneData{
		&bg14,
		L"",
		false,
		false,
		false,
		19
	};

	escenas[19] = SceneData{
 &bg15,
 L"",
 true,
 false,
 false,
 20,
 3
	};

	escenas[20] = SceneData{
	&bg16,
	L"Llegando al campus con mi paraguas.\n"
	L"La lluvia caía constante...\n"
	L"de esas que no molestan, pero tampoco te dejan ignorarla.\n\n"
	L"El ambiente era tranquilo.\n"
	L"Demasiado tranquilo.\n\n",
	false,
	true,
	false,
	21
	};

	escenas[21] = SceneData{
		&bg17,
		L"En mi camino me encuentro con Illeana.\n"
		L"Parece que quedo atrapada por la lluvia.",
		false,
		true,
		false,
		22
	};

	escenas[22] = SceneData{
	  &bg18,
	 L"",
	 true,
	 false,
	 false,
	 23,
	 4
	};

	escenas[23] = SceneData{
		&bg19,
		L"Tu: Otra vez tú\nIlleana: Creo que sí coincidimos después de todo {NOMBRE}\nSe acerca un poco a tu paraguas sin preguntar directamente",
		false,
		true,
		false,
		24
	};

	escenas[24] = SceneData{
		&bg20,
		L"Empezamos a caminar juntos hacia clase, la conversación era tranquila,\ncon la lluvia llenando los silencios.\nEn el camino, pasamos por los jardines de la escuela y\nnos detuvimos junto a los girasoles.",
		false,
		true,
		false,
		25
	};

	escenas[25] = SceneData{
		&bg21,
		L"",
		false,
		true,
		false,
		26
	};

	escenas[26] = SceneData{
		&bg22,
		L"Es tu novia?",
		false,
		true,
		false,
		27
	};

	escenas[27] = SceneData{
	 &bg23,
	 L"",
	 true,
	 false,
	 false,
	 28,
	 5
	};

	escenas[28] = SceneData{
  &bg24,
  L"Llegamos al edificio de clases y caminamos por el pasillo.\nAntes de entrar Illeana volteó hacia mi.\n"
  L"'Oye...'\n"
  L"'El domingo va a haber algo interesante cerca de aquí, deberías venir'",
  false,
  true,
  false,
  29
	};

	escenas[29] = SceneData{
 &bgMenu,
 L"",
 false,
 false,
 false,
 30
	};



	// =========================
 // DIA 3
 // =========================

	escenas[30] = SceneData{
		&bg25,
		L"",
		false,
		true,
		false,
		31
	};

	escenas[31] = SceneData{
		&bg67,
		L"",
		false,
		false,
		false,
		32
	};

	escenas[32] = SceneData{
		&bg10,
		L"Ay, parece que ya no esta lloviendo,\npero el ambiente sigue pesado...\n\n"
		L"Como si algo se hubiera quedado desde ayer.",
		false,
		true,
		false,
		33
	};

	escenas[33] = SceneData{
		&bg26,
		L"",
		false,
		true,
		false,
		34
	};

	escenas[34] = SceneData{
		&bg27,
		L"Decido revisar mi celular y encuentro unos mensajes",
		false,
		true,
		false,
		35
	};

	escenas[35] = SceneData{
		&bg28,
		L"",
		true,
		false,
		false,
		36,
		8
	};
	escenas[36] = SceneData{
&bg29,
L"Guardo el celular.\n"
L"No sé por que...\n"
L"Pero esa pregunta se sintió más pesada de lo normal.\n"
L"Como si ella hubiera notado algo que ni yo entiendo todavía.\n"
L"Creo que es mejor alistarme para clases.",
	false,
	true,
	false,
	37
	};

	escenas[37] = SceneData{
		&bg6,
		L"Al llegar al campus todo seguía normal.\n"
		L"Caminaba tranquilo hasta mi salon de clases hasta que...",
		false,
		true,
		false,
		38
	};

	escenas[38] = SceneData{
		&bg24,
		L"Hey",
		false,
		true,
		false,
		39
	};

	escenas[39] = SceneData{
		&bg24,
		L"Illeana se me acerca como si ya fuera costumbre.\n"
		L"Parece ser que ya somos amigos.\n"
		L"\"Oye {NOMBRE}...\"\n",
		false,
		true,
		false,
		40
	};

	escenas[40] = SceneData{
		&bg30,
		L"Estuve pensando en lo que te dije ayer",
		false,
		true,
		false,
		41
	};

	escenas[41] = SceneData{ // borton corregido
		&bg31,
		L"Lo del domingo...\n"
		L"Creo que estaría más fácil si te paso\n"
		L"la info por mensaje",
		false,
		true,
		false,
		42
	};

	escenas[42] = SceneData{ //estoy aqui con las opciones
		&bg32,
		L"",
		true,
		false,
		false,
		43,
		9
	};
	escenas[43] = SceneData{
&bg24,
L"Dudo unos segundos antes de darle mi número.\n\n"
L"No debería sentirse como algo importante...pero aun así, siento una\n"
L"pequeña incomodidad en el pecho.",
	false,
	true,
	false,
	44
	};

	escenas[44] = SceneData{
		&bg33,
		L"\"Gracias {NOMBRE}... No pensé que dirías que sí tan fácil\"\n\n"
		L"\"El domingo te mando la info\"",
		false,
		true,
		false,
		45
	};


	escenas[45] = SceneData{
	&bg34,
	L"Me manda un mensaje para confirmar.\n"
	L"Antes de guardar el celular, alcanzo a notar su foto de perfil.\n"
	L"Un girasol.\n"
	L"No sé por qué, pero me quedo pensando en eso.",
	false,
	true,
	false,
	46
	};

	escenas[46] = SceneData{
		&bg6,
		L"Seguimos hablando hasta que empezaron las clases.\n"
		L"Pero siento que algo cambió...\n"
		L"Y no sé si fue para bien.",
		false,
		true,
		false,
		47
	};

	escenas[47] = SceneData{//mira a la novia en el cafe
		&bg35,
		L"El día pasa lento entre clases, apuntes y ruido...\n"
		L"Solo espero a que llegue la tarde.",
		false,
		true,
		false,
		48
	};

	escenas[48] = SceneData{
		&bg36,
		L"Al darse cuenta de mi presencia,\n"
		L"se acerca con una sonrisa.\n"
		L"De esas sonrisas que no se fingen.",
		false,
		true,
		false,
		49
	};
	escenas[49] = SceneData{
&bg37,
L"\"¡Hey!\"\n"
L"\"Pensé que ibas a llegar tarde\"\n\n"
L"\"Hoy es un día importante...\"",
	false,
	true,
	false,
	50
	};

	escenas[50] = SceneData{
		&bg36,
		L"\"Sí te acordaste, verdad?\"",
		false,
		true,
		false,
		51
	};

	escenas[51] = SceneData{
		&bg38,
		L"",
		true,
		false,
		false,
		52,
		10
	};

	escenas[52] = SceneData{ //boton en el lugar equivocado
		&bg39,
		L"Me mira unos segundos,\n"
		L"con una mirada que no puedo descifrar.",
		false,
		true,
		false,
		53
	};

	escenas[53] = SceneData{
		&bg36,
		L"Pero al final sonríe.\n"
		L"Pasamos un buen rato en el café.",
		false,
		true,
		false,
		54
	};

	escenas[54] = SceneData{
	&bgMenu,
	L"",
	false,
	false,
	false,
	55
	};

	escenas[55] = SceneData{
	&bgRegalos,
	L"",
	false,
	false,
	false,
	56
	};

	//Dia 4
	escenas[56] = SceneData{
		&bg40,
		L"",
		false,
		false,
		false,
		57
	};

	escenas[57] = SceneData{
		&bg10,
		L"Los jueves tengo clases por la tarde, así que mejor me voy temprano\n"
		L"a comprar la comida para cenar",
		false,
		true,
		false,
		58
	};

	escenas[58] = SceneData{
		&bg41,
		L"El camino es tranquilo, ando pensando en mis tareas de la semana cuando escucho\n"
		L"una risa conocida. Veo hacía la calle y ahí la veo...",
		false,
		true,
		false,
		59
	};

	escenas[59] = SceneData{
		&bg42,
		L"Mi novia con alguien más...",
		false,
		true,
		false,
		60
	};

	escenas[60] = SceneData{
		&bg43,
		L"Por un momento me quedo sin aire, parece muy cercana a ese chico.",
		false,
		true,
		false,
		61
	};

	escenas[61] = SceneData{
		&bg44,
		L"Mejor me voy a casa. no quiero hacer una escena",
		false,
		true,
		false,
		62
	};

	escenas[62] = SceneData{
		&bg10,
		L"Llego a la casa aun de malas.",
		false,
		true,
		false,
		63
	};

	escenas[63] = SceneData{
		&bg45,
		L"Estoy arreglandomé para las clases cuando me llega un mensaje de mi novia",
		false,
		true,
		false,
		64
	};

	escenas[64] = SceneData{
		&bg46,
		L"Hola amor, ya desayunaste?",
		false,
		true,
		false,
		65
	};

	escenas[65] = SceneData{
		&bg47,
		L"Qué le respondo?",
		true,
		false,
		false,
		66,
		11
	};

	escenas[66] = SceneData{
		&bg10,
		L"Escucho la voz de mi mamá desde la cocina y dejo mi telefono en la cama",
		false,
		true,
		false,
		67
	};

	escenas[67] = SceneData{
		&bg48,
		L"",
		false,
		true,
		false,
		68
	};

	escenas[68] = SceneData{
		&bg48,
		L"",
		false,
		true,
		false,
		69
	};

	escenas[69] = SceneData{
		&bg6,
		L"Llego la tarde y fuí a clases...",
		false,
		true,
		false,
		70
	};

	escenas[70] = SceneData{
		&bg30,
		L"Que estresante. \n"
		L"Como es costumbre, encontré a Illeana en el pasillo. Aún faltaba tiempo para\n"
		L"entrar a clases entonces nos quedamos platicando. Le conté sobre lo mal \n"
		L"que iba mi día. Entre ver a mi novia con alguien más y olvidar mi telefono \n"
		L"me la estaba pasando fatal. Incluso nos quedamos platicando en la salida.",
		false,
		true,
		false,
		71
	};

	escenas[71] = SceneData{
		&bg49,
		L"Cómo te sentiste despues de eso?\n"
		L"Supongo que muy feo, terminarás con ella?",
		false,
		true,
		false,
		72
	};

	escenas[72] = SceneData{
		&bg50,
		L"",
		true,
		false,
		false,
		73,
		12
	};

	escenas[73] = SceneData{
		&bg51,
		L"Voltee a ver el otro lado de la calle y para mi sorpresa, ahi estaba ella.",
		false,
		true,
		false,
		74
	};

	escenas[74] = SceneData{
		&bg52,
		L"Me veía con una mirada decepcionada, pues llevaba horas sin\n"
		L"contestarle y ademas estaba con alguien mas.",
		false,
		true,
		false,
		75
	};

	escenas[75] = SceneData{
		&bg53,
		L"Me di cuenta de lo mal que se veía y me consumieron las emociones.\n"
		L"Al ver a las dos, huí... Como buena gallina .",
		false,
		true,
		false,
		76
	};

	escenas[76] = SceneData{
		&bg29,
		L"Al llegar a casa, corrí a mi cuarto. Mi telefono estaba en mi cama",
		false,
		true,
		false,
		77
	};

	escenas[77] = SceneData{
		&bg55,
		L"... Ay no",
		false,
		true,
		false,
		78
	};

	escenas[78] = SceneData{
		&bg56,
		L"",
		true,
		false,
		false,
		79,
		13
	};

	escenas[79] = SceneData{
		&bg12,
		L"\"Ha sido un dia horroroso.\" \n"
		L"Luego de quedarme un rato despierto, mejor decidí, descansar,\n"
		L"es mejor arreglar esto con la mente despejada.",
		false,
		true,
		false,
		80,
	};

	escenas[80] = SceneData{
		&bgMenu,
		L"",
		false,
		false,
		false,
		81,
	};

	escenas[81] = SceneData{
		&bgRegalos,
		L"",
		false,
		false,
		false,
		82
	};
	//Dia 5
	escenas[82] = SceneData{
	  &bg57,
	  L"",
	  false,
	  true,
	  false,
	  83
	};

	escenas[83] = SceneData{
	 &bg68,
	 L"",
	 false,
	 false,
	 false,
	 84
	};

	escenas[84] = SceneData{
	  &bg10,
	  L"No me quiero levantar. Después de todo el caos el\n"
	  L"silencio pesa más que cualquier discusión. Pero debo \n"
	  L"arreglar las cosas. No es solo una amiga, es mi novia... \n"
	  L"Debo salir a buscarla.",
	  false,
	  true,
	  false,
	  85
	};

	escenas[85] = SceneData{
			&bg58,
			L"Llego a su casa, me abrio la puerta y decido explicarme",
			false,
			true,
			false,
			86
	};

	escenas[86] = SceneData{
			&bg59,
			L"",
			true,
			false,
			false,
			87,
			14
	};

	escenas[87] = SceneData{
			&bg60,
			L"Luego de hablar un tiempo, aceptó mi dísculpa.\n"
			L"Parecía feliz de que todo regresara a la \n"
			L"normalidad. Decidí acompañarla a la universidad\n y luego me fui a clase",
			false,
			true,
			false,
			88
	};

	escenas[88] = SceneData{
			&bg61,
			L"Como siempre, me encuentro con Illeana antes\n"
			L"de clases, pero parece que no está \n"
			L"de buenas. Debo acercarme y darle una explicación\n",
			false,
			true,
			false,
			89
	};

	escenas[89] = SceneData{
			&bg62,
			L"",
			true,
			false,
			false,
			90,
			15
	};

	escenas[90] = SceneData{
			&bg30,
			L"Luego de nuestra plática parece que nuestra relación cambio",
			false,
			true,
			false,
			91
	};

	escenas[91] = SceneData{
			&bg6,
			L"Pasaron las clases y me dí cuenta que faltaba un día para el 14 de\n"
			L"febrero y no he comprado nada de regalo... Debería ir a la florería\n",
			false,
			true,
			false,
			92
	};
	escenas[92] = SceneData{
			&bg63,
			L"",
			true,
			false,
			false,
			93,
			16
	};
	escenas[93] = SceneData{
			&bg12,
			L"Compré flores y fui caminando a mi casa.\n"
			L"Me siento bastante feliz. Busqué ropa decente y también mi perfume favorito. \n\n"
			L"Parece que ya todo está listo, ahora solo falta avisar\n",
			false,
			true,
			false,
			94
	};

	escenas[94] = SceneData{
			&bg64,
			L"",
			false,
			true,
			false,
			95
	};

	escenas[95] = SceneData{
			&bg65,
			L"",
			true,
			false,
			false,
			96,
			17
	};

	escenas[96] = SceneData{
			&bg12,
			L"Me recuesto tras terminar mis pendientes.\n"
			L"Por fin mañana será un día de descanso.\n"
			L"No puedo esperar.",
			false,
			true,
			false,
			97
	};
	escenas[97] = SceneData{
			&bgMenu,
			L"",
			false,
			false,
			false,
			98
	};
	escenas[98] = SceneData{
		   &bgRegalos,
		   L"",
		   false,
		   false,
		   false,
		   99
	};
	escenas[99] = SceneData{
		   &bg69,
		   L"",
		   false,
		   true,
		   false,
		   102
	};
	escenas[102] = SceneData{
		   &bg70,
		   L"",
		   false,
		   false,
		   false,
		   103
	};

	escenas[100] = SceneData{
		&bgRegalos,
		L"",
		false,
		false,
		false,
		15
	};

	escenas[101] = SceneData{
		&bgRegalos,
		L"",
		false,
		false,
		false,
		29
	};

	escenas[103] = SceneData{
		   &bg10,
		   L"Como quería estar libre para el día de hoy, estuve trabajando en todos mis\n pendientes por la noche terminando muy tarde. Así que hoy me levanté\n tarde para poder descansar bien, al fin y al cabo hoy es\n sabado y es 14 de febrero.",
		   false,
		   true,
		   false,
		   104
	};

	escenas[104] = SceneData{
		   &bg71,
		   L"Luego de unas horas me doy cuenta de que ya casi se acerca la hora de vernos,\nasí que comencé a alistarme. Tome todas mis cosas incluyendo el regalo y sali de casa.",
		   false,
		   true,
		   false,
		   105
	};

	escenas[105] = SceneData{
		   &bg72,
		   L"Mientras camino, reflexiono en lo caótica que ha sido la semana, y sin darme cuenta,\nhe llegado al lugar de encuentro.",
		   false,
		   true,
		   false,
		   106
	};

	escenas[106] = SceneData{
		   &bg73,
		   L"Yo: Hey amor!!! ¿Llevas mucho tiempo esperando?\nNovia: no, acabo de llegar.\n*le das las flores*",
		   false,
		   true,
		   false,
		   107
	};

	escenas[107] = SceneData{
		   &bg74,
		   L"Omggg que hermosas",
		   false,
		   true,
		   false,
		   108
	};

	escenas[108] = SceneData{
		   &bg75,
		   L"Yo: ¿Nos vamos?\nNovia:Si\n*Comenzamos a caminar hacia el sushi, mientras me contaba cómo fue su primera\n semana en la universidad*",
		   false,
		   true,
		   false,
		   109
	};

	escenas[109] = SceneData{
		   &bg76,
		   L"*Me contó que hizo muchas amigas y que\nla están saturando de proyectos pero aún así tiene tiempo para verme*",
		   false,
		   true,
		   false,
		   110
	};

	escenas[110] = SceneData{
		   &bg77,
		   L"",
		   true,
		   false,
		   false,
		   111,
		   18
	};

	escenas[111] = SceneData{
		   &bg76,
		   L"El mesero tomó su orden y se fue. Seguimos\nplaticando sobre la universidad y como nos estamos adaptando",
		   false,
		   true,
		   false,
		   112
	};

	escenas[112] = SceneData{
		   &bg78,
		   L"De repente escuchamos unos murmullos en la parte de atras.",
		   false,
		   true,
		   false,
		   113
	};

	escenas[113] = SceneData{
		&bg88,
		L"Volteo y era Illeana, celebrando con unas amigas\nque le estaban echando carrilla, me quedé congelado",
		false,
		true,
		false,
		114
	};


	escenas[114] = SceneData{
		   &bg80,
		   L"",
		   true,
		   false,
		   false,
		   115,
		   19
	};

	escenas[115] = SceneData{
		   &bg81,
		   L"Mi novia estuvo dudando pero le aseguré que no era nada.\nIgual ella decidió confiar. Llegaron nuestros alimentos y los disfrutamos.",
		   false,
		   true,
		   false,
		   116
	};

	escenas[116] = SceneData{
		   &bg81,
		   L"Cuando menos lo esperaba el ruido se escuchaba\nmás fuerte, volteo y noto que Illeana se está acercando a nosotros.",
		   false,
		   true,
		   false,
		   117
	};

	escenas[117] = SceneData{
		   &bg83,
		   L"Ay no",
		   false,
		   true,
		   false,
		   118
	};

	escenas[118] = SceneData{
		   &bg84,
		   L"Ileana: Holaaa, feliz san valentín",
		   false,
		   true,
		   false,
		   119
	};

	escenas[119] = SceneData{
		   &bg85,
		   L"",
		   true,
		   false,
		   false,
		   120,
		   20
	};

	escenas[120] = SceneData{
		   &bg86,
		   L"Illeana: Es lindo conocerte. En fin, {NOMBRE} espero poder verte mañana,\nluego te mando la ubicación más tarde, va?",
		   false,
		   true,
		   false,
		   121
	};

	escenas[121] = SceneData{
		   &bg81,
		   L"Después de ese incómodo momento,\nterminamos de comer y pagamos la cuenta.\nLa lleve a su casa.",
		   false,
		   true,
		   false,
		   122
	};

	escenas[122] = SceneData{
		   &bg89,
		   L"El camino se sintió tenso, apenas y me habló en el carro\n\n"
		   L"Novia: Mañana será nuestro aniversario, no quiero pelear, olvidemos esto por hoy.\n Nuestra conversación quedó en esas y regresé a mi casa",
		   false,
		   true,
		   false,
		   123
	};

	escenas[123] = SceneData{
		   &bg12,
		   L"Espero que mañana sea un mejor día.",
		   false,
		   true,
		   false,
		   124
	};

	escenas[124] = SceneData{
		&bgMenu,
		L"",
		false,
		false,
		false,
		125,
	};

	escenas[125] = SceneData{
		&bgRegalos,
		L"",
		false,
		false,
		false,
		126
	};

	escenas[126] = SceneData{
		&bg90,
		L"",
		false,
		true,
		false,
		127,
	};

	escenas[127] = SceneData{
		&bg10,
		L"... Me desperté con una mala sensación. Vi mi teléfono y tenía un par de mensajes;\nde Illiana y mi novia:",
		false,
		true,
		false,
		128
	};

	escenas[128] = SceneData{
		&bg91,
		L"Obviamente le contestaste a tu amor",
		false,
		true,
		false,
		129
	};

	escenas[129] = SceneData{
		&bg92,
		L"",
		true,
		false,
		false,
		130,
		21
	};

	escenas[130] = SceneData{
		&bg10,
		L"Apagué el celular y comencé a recapitular todo lo vivido",
		false,
		true,
		false,
		131
	};

	escenas[131] = SceneData{
		&bg20,
		L"Recordé mis conversaciones con Illenaa, conocerla...\n\n",
		false,
		true,
		false,
		132
	};


	escenas[132] = SceneData{
		&bg24,
		L"Nuestras conversaciones en clase\n\n",
		false,
		true,
		false,
		133
	};

	escenas[133] = SceneData{
	   &bg24,
	   L"Nuestras conversaciones en clase\n\n",
	   false,
	   true,
	   false,
	   134
	};
	escenas[134] = SceneData{
		&bg89,
		L"Recordé los pleitos con mi novia\n\n",
		false,
		true,
		false,
		135

	};
	escenas[135] = SceneData{
		&bg60,
		L"Pero también nuestros momentos felices\n\n",
		false,
		true,
		false,
		136
	};

	escenas[136] = SceneData{
		&bg10,
		L"“Amo mucho a mi novia pero últimamente siento que no es lo mismo, en cambio\n con Ileana siento que soy yo mismo y me\n quiere ser como soy...\n\nCon quién me voy?",
		false,
		true,
		false,
		137
	};

	escenas[137] = SceneData{
		&bg93,
		L"",
		false,
		false,
		false,
		138,
	};

	escenas[138] = SceneData{
		&bg94,
		L"Fui a la cita con mi novia, después de hablar arreglamos las cosas.\n Han pasado mucho tiempo desde entonces y por fin obtuvimos \n nuestro final feliz. ",
		false,
		true,
		false,
		143
	};
	escenas[139] = SceneData{
		&bg95,
		L"Pero cayó un meteorito en la boda y falleció. :(",
		false,
		true,
		false,
		143
	};
	escenas[140] = SceneData{
		&bg96,
		L"`Fui a la cita con mi novia, per peleamos toda la tarde.\n Por más que lo intentamos, no funcionó lo nuestro. \n Terminamos unas semanas depsués.",
		false,
		true,
		false,
		143
	};
	escenas[141] = SceneData{
		&bg97,
		L"Me fui con Illena y regresé a un texo en el celular.\n Habíamos terminado.\n Quizá era lo mejor..",
		false,
		true,
		false,
		143
	};
	escenas[142] = SceneData{
		&bg98,
		L"Me fui con Illeana, y ese mismo dia mi novia me termino. \n Con el tiempo me empareje con Illeana pero todo habia sido una broma\n que hizo con sus amigos. Me humillaron.",
		false,
		true,
		false,
		143
	};
	escenas[143] = SceneData{
	&bg99,
	L"",
	false,
	true,
	false,
	144
	};
	escenas[144] = SceneData{
		&bg100,
		L"",
		false,
		true,
		false,
		0
	};

	escenas[199] = SceneData{
 &bg12,
 L"Ella decidio terminar contigo...\n\nGAME OVER",
 false,
 false,
 false,
 199
	};
	// boton invisible inicio

	sf::FloatRect zonaJugar({ 477.f, 400.f }, { 150.f, 60.f });

	//continuar arriba escena 1  arriba
	sf::FloatRect zonaContinuar0({ 795.f, 27.f }, { 250.f, 45.f });

    // boton pausa
    sf::FloatRect zonaMenu({ 378.f, 310.f }, { 390.f, 65.f });  
    sf::FloatRect zonaSalir({ 367.f, 440.f }, { 410.f, 65.f });

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

	sf::RectangleShape debugRect;
	debugRect.setFillColor(sf::Color(0, 255, 0, 100)); // Verde semitransparente
	debugRect.setOutlineColor(sf::Color::Green);
	debugRect.setOutlineThickness(2.f);
	debugRect.setPosition(zonaAlarma1.position); // Accede directamente al sf::Vector2f de posición
	debugRect.setSize(zonaAlarma1.size);

	// // boton pausa
	sf::FloatRect zonaMenu({ 378.f, 310.f }, { 390.f, 65.f });
	sf::FloatRect zonaSalir({ 367.f, 440.f }, { 410.f, 65.f });

	bool paused = false; // Variable para controlar el estado de pausa

	//bucle 
	while (ventana.isOpen()) {

		// eventos
		while (auto event = ventana.pollEvent()) {
			// cerrar ventana en la tachita
			if (event->is<sf::Event::Closed>()) {
				ventana.close();
			}
			if (auto* keyEvent = event->getIf<sf::Event::KeyPressed>()) {
				if (keyEvent->code == sf::Keyboard::Key::Escape) {
					paused = !paused; // Alterna el estado de pausa
					continue; //no procesar mas eventos en este frame
				}
			}
			// Manejo de clics mientras el juego está pausado
			if (paused) {
				if (auto* mouseEvent = event->getIf<sf::Event::MouseButtonPressed>()) {
					if (mouseEvent->button == sf::Mouse::Button::Left) {
						sf::Vector2f mousePos = ventana.mapPixelToCoords(sf::Mouse::getPosition(ventana));

						if (zonaMenu.contains(mousePos)) {
							// Opción 1: Volver al menú principal (sin reiniciar estado)
							paused = false;
							continue;  // Salta el resto del procesamiento
						}
						else if (zonaSalir.contains(mousePos)) {
							ventana.close();   // Cierra la ventana (termina el juego)
							return 0;          // Sale del main (opcional)
						}
					}
				}
				continue;
			}

			if (!paused) {
				// click del mouse
				if (auto* mouseEvent = event->getIf<sf::Event::MouseButtonPressed>()) {
					if (mouseEvent->button == sf::Mouse::Button::Left) {

						sf::Vector2i pixelPos = sf::Mouse::getPosition(ventana); //guarda donde presiono boton 
						sf::Vector2f mousePos = ventana.mapPixelToCoords(pixelPos);//se guarda en la ventana comparandolo correctamente

					}
				}

			}
		

			if (scene == 1) {
				if (auto* textEvent = event->getIf<sf::Event::TextEntered>()) {
					//si presiona enter avanzamos de escena para linux y windows
					if (textEvent->unicode == '\r' || textEvent->unicode == '\n') {
						cout << "ENTER PRESIONADO" << endl;
						if (!nombreJugador.empty()) {
							scene = 2;
						}
					}
					//para que se borre si le da al backspace
					else if (textEvent->unicode == 8) {
						if (!nombreJugador.empty()) {
							nombreJugador.pop_back();
						}
					}
					else if (nombreJugador.size() < 12) {
						wchar_t caracterCasteado = static_cast<wchar_t>(textEvent->unicode);
						if (esCaracterValido(caracterCasteado)) {
							nombreJugador += caracterCasteado;
						}
					}
				}
			}

			// click del mouse
			if (auto* mouseEvent = event->getIf<sf::Event::MouseButtonPressed>()) {
				if (mouseEvent->button == sf::Mouse::Button::Left) {

					sf::Vector2i pixelPos = sf::Mouse::getPosition(ventana); //guarda donde presiono boton 
					sf::Vector2f mousePos = ventana.mapPixelToCoords(pixelPos);//se guarda en la ventana comparandolo correctamente

    bool paused = false;  // indica si el juego está pausado

					// logica del menu principal
					if (scene == 0) { //escena de presiona para jugar
						if (zonaJugar.contains(mousePos)) {
							scene = 1; // Cambiamos al juego
						}
					}
					else if (scene == 2) { //elige su personaje
						if (zonaToxico.contains(mousePos)) {

<<<<<<< HEAD
        // eventos
        while (auto event = ventana.pollEvent()) {
            // cerrar ventana en la tachita
            if (event->is<sf::Event::Closed>()) {
                ventana.close();
            }
            if (auto* keyEvent = event->getIf<sf::Event::KeyPressed>()) {
                if (keyEvent->code == sf::Keyboard::Key::Escape) {
                    paused = !paused;   // alterna pausa
                    continue;           // no procesar más eventos en este frame
                }
            }
            // Manejo de clics mientras el juego está pausado
            if (paused) {
                if (auto* mouseEvent = event->getIf<sf::Event::MouseButtonPressed>()) {
                    if (mouseEvent->button == sf::Mouse::Button::Left) {
                        sf::Vector2f mousePos = ventana.mapPixelToCoords(sf::Mouse::getPosition(ventana));

                        if (zonaMenu.contains(mousePos)) {
                            // Opción 1: Volver al menú principal (sin reiniciar estado)
                            paused = false;
                            scene = 0;
                            continue;  // Salta el resto del procesamiento
                        }
                        else if (zonaSalir.contains(mousePos)) {
                            ventana.close();   // Cierra la ventana (termina el juego)
                            return 0;          // Sale del main (opcional)
                        }
                    }
                }
            }
            if (!paused){
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
                        // ESCENA ALARMA Lunes
                        else if (scene == 5) {

                            if (zonaAlarma1.contains(mousePos)) {
                                scene = 6;
                                continue;
                            }

                            else if (zonaAlarma2.contains(mousePos)) {
                                scene = 6;
                                continue;
                            }
                        }

                        // MENU DIA 1
                        if (scene == 15) {

                            if (zonaContM.contains(mousePos)) {
                                scene = 16;
                                continue;
                            }

                            else if (zonaRegalos.contains(mousePos)) {
                                scene = 100;
                                continue;
                            }
                        }

                        // ESCENA ALARMA MARTES
                        else if (scene == 17) {

                            if (zonaAlarma1.contains(mousePos)) {
                                scene = 18;
                                continue;
                            }

                            else if (zonaAlarma2.contains(mousePos)) {
                                scene = 18;
                                continue;
                            }
                        }

                        // MENU DIA 2
                        else if (scene == 28) {

                            if (zonaContM.contains(mousePos)) {
                                scene = 29;
                                continue;
                            }

                            else if (zonaRegalos.contains(mousePos)) {
                                scene = 101;
                                continue;
                            }
                        }

                        // ESCENA ALARMA MIERCOLES
                        else if (scene == 30) {

                            if (zonaAlarma1.contains(mousePos)) {
                                scene = 31;
                                continue;
                            }

                            else if (zonaAlarma2.contains(mousePos)) {
                                scene = 31;
                                continue;
                            }
                        }
                        // MENU Dia 3
                        else if (scene == 53) {

                            if (zonaContM.contains(mousePos)) {
                                scene = 55;
                                continue;
                            }

                            else if (zonaRegalos.contains(mousePos)) {
                                scene = 54;
                                continue;
                            }
                        }

                        // ESCENA ALARMA Jueves
                        else if (scene == 55) {

                            if (zonaAlarma1.contains(mousePos)) {
                                scene = 56;
                                continue;
                            }

                            else if (zonaAlarma2.contains(mousePos)) {
                                scene = 56;
                                continue;
                            }
                        }

                        // MENU Dia 4
                        else if (scene == 79) {

                            if (zonaContM.contains(mousePos)) {
                                scene = 81;
                                continue;
                            }

                            else if (zonaRegalos.contains(mousePos)) {
                                scene = 80;
                                continue;
                            }
                        }

                        // ESCENA ALARMA Viernes
                        else if (scene == 82) {

                            if (zonaAlarma1.contains(mousePos)) {
                                scene = 83;
                                continue;
                            }

                            else if (zonaAlarma2.contains(mousePos)) {
                                scene = 83;
                                continue;
                            }
                        }

                        // MENU Dia 5
                        else if (scene == 96) {

                            if (zonaContM.contains(mousePos)) {
                                scene = 98;
                                continue;
                            }

                            else if (zonaRegalos.contains(mousePos)) {
                                scene = 97;
                                continue;
                            }
                        }

                        //Alarma Sabado (Dia 6)
                        else if (scene == 99) {

                            if (zonaAlarma1.contains(mousePos)) {
                                scene = 102;
                                continue;
                            }

                            else if (zonaAlarma2.contains(mousePos)) {
                                scene = 102;
                                continue;
                            }
                        }
                        //Menu dia 6
                        else if (scene == 122) {

                            if (zonaContM.contains(mousePos)) {
                                scene = -1;
                                continue;
                            }

                            else if (zonaRegalos.contains(mousePos)) {
                                scene = 123;
                                continue;
                            }
                        }
                        // REGALOS
                        else if (scene == 100) {

                            procesarRegalo(
                                scene,
                                16,
                                mitilina,
                                mousePos,
                                zonaFlores,
                                zonaCarta,
                                zonaPastel,
                                zonaCollar
                            );

                            continue;
                        }

                        else if (scene == 54) {

                            procesarRegalo(
                                scene,
                                55,
                                mitilina,
                                mousePos,
                                zonaFlores,
                                zonaCarta,
                                zonaPastel,
                                zonaCollar
                            );

                            continue;
                        }

                        else if (scene == 80) {

                            procesarRegalo(
                                scene,
                                81,
                                mitilina,
                                mousePos,
                                zonaFlores,
                                zonaCarta,
                                zonaPastel,
                                zonaCollar
                            );

                            continue;
                        }

                        else if (scene == 97) {

                            procesarRegalo(
                                scene,
                                98,
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
                                29,
                                mitilina,
                                mousePos,
                                zonaFlores,
                                zonaCarta,
                                zonaPastel,
                                zonaCollar
                            );

                            continue;
                        }

                        else if (scene == 123) {

                            procesarRegalo(
                                scene,
                                -1,
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
        } 
        // mostrar los dibujos
        ventana.clear(sf::Color::Black);
=======
							miJugador = make_unique<Toxico>();
							historia = cargarHistoria(0);
							scene = 3;
						}

						else if (zonaNPC.contains(mousePos)) {

							miJugador = make_unique<NPC>();
							historia = cargarHistoria(1);
							scene = 3;
						}

						else if (zonaGym.contains(mousePos)) {

							miJugador = make_unique<Gymrat>();
							historia = cargarHistoria(2);
							scene = 3;
						}

						else if (zonaOtaku.contains(mousePos)) {

							miJugador = make_unique<Otaku>();
							historia = cargarHistoria(3);
							scene = 3;
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
					// ESCENA ALARMA Lunes
					else if (scene == 6) {

						if (zonaAlarma1.contains(mousePos)) {
							scene = 7;
							mitilina.modificarFelicidad();
							continue;
						}

						else if (zonaAlarma2.contains(mousePos)) {
							scene = 7;
							mitilina.modificarFelicidad();
							continue;
						}
					}

					// MENU DIA 1
					if (scene == 16) {

						if (zonaContM.contains(mousePos)) {
							scene = 17;
							continue;
						}

						else if (zonaRegalos.contains(mousePos)) {
							scene = 100;
							continue;
						}
					}

					// ESCENA ALARMA MARTES
					else if (scene == 18) {

						if (zonaAlarma1.contains(mousePos)) {
							scene = 19;
							continue;
						}

						else if (zonaAlarma2.contains(mousePos)) {
							scene = 19;
							continue;
						}
					}

					// MENU DIA 2
					else if (scene == 29) {

						if (zonaContM.contains(mousePos)) {
							scene = 30;
							continue;
						}

						else if (zonaRegalos.contains(mousePos)) {
							scene = 101;
							continue;
						}
					}

					// ESCENA ALARMA MIERCOLES
					else if (scene == 31) {

						if (zonaAlarma1.contains(mousePos)) {
							scene = 32;
							continue;
						}

						else if (zonaAlarma2.contains(mousePos)) {
							scene = 32;
							continue;
						}
					}
					// MENU Dia 3
					else if (scene == 54) {

						if (zonaContM.contains(mousePos)) {
							scene = 56;
							continue;
						}

						else if (zonaRegalos.contains(mousePos)) {
							scene = 55;
							continue;
						}
					}

					// ESCENA ALARMA Jueves
					else if (scene == 56) {

						if (zonaAlarma1.contains(mousePos)) {
							scene = 57;
							continue;
						}

						else if (zonaAlarma2.contains(mousePos)) {
							scene = 57;
							continue;
						}
					}

					// MENU Dia 4
					else if (scene == 80) {

						if (zonaContM.contains(mousePos)) {
							scene = 82;
							continue;
						}

						else if (zonaRegalos.contains(mousePos)) {
							scene = 81;
							continue;
						}
					}

					// ESCENA ALARMA Viernes
					else if (scene == 83) {

						if (zonaAlarma1.contains(mousePos)) {
							scene = 84;
							continue;
						}

						else if (zonaAlarma2.contains(mousePos)) {
							scene = 84;
							continue;
						}
					}

					// MENU Dia 5
					else if (scene == 97) {

						if (zonaContM.contains(mousePos)) {
							scene = 99;
							continue;
						}

						else if (zonaRegalos.contains(mousePos)) {
							scene = 98;
							continue;
						}
					}

					//Alarma Sabado (Dia 6)
					else if (scene == 102) {

						if (zonaAlarma1.contains(mousePos)) {
							scene = 103;
							continue;
						}

						else if (zonaAlarma2.contains(mousePos)) {
							scene = 103;
							continue;
						}
					}
					//Menu dia 6
					else if (scene == 124) {

						if (zonaContM.contains(mousePos)) {
							scene = 126;
							continue;
						}

						else if (zonaRegalos.contains(mousePos)) {
							scene = 125;
							continue;
						}
					}
					// REGALOS
					else if (scene == 100) {

						procesarRegalo(
							scene,
							17,
							mitilina,
							mousePos,
							zonaFlores,
							zonaCarta,
							zonaPastel,
							zonaCollar
						);

						continue;
					}

					else if (scene == 55) {

						procesarRegalo(
							scene,
							56,
							mitilina,
							mousePos,
							zonaFlores,
							zonaCarta,
							zonaPastel,
							zonaCollar
						);

						continue;
					}

					else if (scene == 81) {

						procesarRegalo(
							scene,
							82,
							mitilina,
							mousePos,
							zonaFlores,
							zonaCarta,
							zonaPastel,
							zonaCollar
						);

						continue;
					}

					else if (scene == 98) {

						procesarRegalo(
							scene,
							99,
							mitilina,
							mousePos,
							zonaFlores,
							zonaCarta,
							zonaPastel,
							zonaCollar
						);
						continue;
					}
					// REGALOS 2
					else if (scene == 101) {

						procesarRegalo(
							scene,
							30,
							mitilina,
							mousePos,
							zonaFlores,
							zonaCarta,
							zonaPastel,
							zonaCollar
						);

						continue;
					}
					//Regalos6
					else if (scene == 125) {

						procesarRegalo(
							scene,
							126,
							mitilina,
							mousePos,
							zonaFlores,
							zonaCarta,
							zonaPastel,
							zonaCollar
						);

						continue;
					}
					//ELEGIR7
					else if (scene == 137) {
						
						if (zonaContM.contains(mousePos)) {
							if (mitilina.getAmor() >= 70) {
								scene = 141;
								continue;
							}
							else {
								scene = 142;
								continue;
							}
						}

						else if (zonaRegalos.contains(mousePos)) {
							if (mitilina.getAmor() >= 70) {
								static std::mt19937 generador(static_cast<unsigned int>(std::time(nullptr)));
								std::uniform_int_distribution<int> distribucion(1, 1000);
								int numeroSuerte = distribucion(generador);
								if (numeroSuerte == 1) {
									scene = 139; // Escena del final raro
								}
								else {
									scene = 138;
								}

								continue;
							}
							else {
								scene = 140;
								continue;
							}

						}

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

	
>>>>>>> b5a15ad3008740d684471c53614442e5e5cfb646

		//Para que e cursos paradee
		if (scene == 1) {
			if (relojCursor.getElapsedTime().asMilliseconds() > 500) {
				mostrarCursor = !mostrarCursor;
				relojCursor.restart(); //toma lo de arriba
			}
		}
		//Para que vaya apreciendo lo escrto jutno con el cursor
		if (mostrarCursor) {
			textoNombre.setString(nombreJugador + L"|");
		}
		else {
			textoNombre.setString(nombreJugador);
		}
		// mostrar los dibujos
		ventana.clear(sf::Color::Black);

		if (scene < 0 || scene >= (int)escenas.size()) {
			cout << "ERROR: scene fuera de rango" << endl;
			scene = 0;
		}

		SceneData* actual = &escenas[scene];

<<<<<<< HEAD
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
        if (paused) {
            ventana.draw(bg87);
        }
        ventana.display();
    }
    return 0;
}
=======
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
			escenarioActual,
			nombreJugador
		);
		if (scene == 1) {
			ventana.draw(cajaTexto);
			ventana.draw(textoNombre);
		}
		if (paused) {
			ventana.draw(bg101);
		}
		ventana.display();
	}
	return 0;
};
>>>>>>> b5a15ad3008740d684471c53614442e5e5cfb646
