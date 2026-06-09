# SFML

Para ubicar un píxel en la pantalla, utilizamos un sistema de coordenadas cartesianas bidimensional. Las posiciones de los píxeles se determinan mediante dos valores. La coordenada X es el valor horizontal del píxel, donde el 0 se encuentra en el extremo izquierdo de la pantalla. La coordenada Y es el valor vertical del píxel y el 0 se encuentra en la parte superior.
Con SFML dibujamos directamente sobre los píxeles. Permite trabajar con objetos gráficos como líneas, figuras geométricas, imágenes y sprites.
Las ventanas de SFML se definen mediante la clase sf::Window. Se puede crear una ventana y abrirla directamente durante la construcción escribiendo:
sf::Window window; window.create(sf::VideoMode(800, 600), "My window");
VideoMode define el tamaño interior de la ventana, excluyendo la barra de título y los bordes. El título de la ventana es una cadena de texto que aparece en la parte superior.
Para poder interactuar con la aplicación, controlar cuándo se cierra o se abre la ventana y actualizar el contenido, se debe crear un bucle. Este bucle se encarga de verificar eventos utilizando pollEvent() para capturar los eventos que se producen mientras la aplicación está abierta. Se utiliza un while para procesarlos uno por uno. pollEvent() devuelve un evento si hay uno pendiente, o false si no lo hay. Un ejemplo es sf::Event::Closed, que se dispara cuando el usuario intenta cerrar la ventana.

## Sprites y texturas
La clase encargada de las texturas en SFML es sf::Texture. Dado que su función principal es cargarse y mapearse a entidades gráficas, la mayoría de sus funciones se centran en cargarla y actualizarla. Por ejemplo:
 sf::Texture texture; texture.loadFromFile("image.png");.
Los píxeles de una imagen en SFML permanecen en la memoria de la GPU, lo que garantiza que las operaciones sobre ellos sean lo más rápidas posible. Usar la menor cantidad posible de texturas es una buena estrategia, ya que cambiar la textura actual es una operación costosa para la tarjeta gráfica.

## Música
La música en SFML se transmite en streaming en lugar de cargarse completamente en la memoria, lo que evita saturarla y reduce los tiempos de carga. Puedes pausarla, reproducirla, detenerla, consultar parámetros como frecuencia y canales, y modificar propiedades como el tono, volumen o posición.
Como flujo de sonido, la música se reproduce en su propio hilo para no bloquear el resto del programa, lo que permite continuar con otras tareas después de llamar a play(). Un ejemplo sería: 
sf::Music music; 
music.openFromFile("musical.ogg"); 
music.setPosition({0, 1, 10}); 
music.setPitch(2); 
music.setVolume(50); 
music.setLoop(true); 
music.play();.

## Fuentes
Para trabajar con fuentes se incluye la librería con:
#include <SFML/Graphics/Font.hpp>. 
Las fuentes se pueden cargar desde un archivo, desde memoria o desde un flujo personalizado. Una vez cargada, una instancia de sf::Font proporciona información como métricas globales, métricas por glifo y representación en píxeles de los caracteres.
La clase sf::Text permite mostrar texto con opciones como tamaño, estilo, color, posición y rotación. Es importante destacar que sf::Text no copia la fuente, solo mantiene una referencia a ella. Un ejemplo sería: 
sf::Font font; 
font.loadFromFile("arial.ttf"); 
sf::Text text1; 
text1.setFont(font); 
text1.setCharacterSize(30); 
text1.setStyle(sf::Text::Regular);.

## Botones
Primero se crea la figura del botón y luego se define su posición: 
sf::RectangleShape shape({200.f, 100.f}); 
shape.setPosition({100.f, 50.f});. 
Para dibujarlo se usa:
window.draw(shape);.
Para detectar si el mouse se encuentra sobre el botón, se obtiene la posición del cursor y los límites de la figura: 
float mouse_x = sf::Mouse::getPosition(window).x;
float mouse_y = sf::Mouse::getPosition(window).y; 
float x1 = shape.getPosition().x; 
float y1 = shape.getPosition().y; 
float x2 = x1 + shape.getSize().x; 
float y2 = y1 + shape.getSize().y;. 
Con estos valores se puede verificar si el cursor está dentro del área del botón.

## Null y New
Null, denota a un puntero literal. Es un valor tipo std::nullptr_t. Se utiliza para representar que un puntero no apunta a un objeto válido. Representa la ausencia de dirección.
New crea e inicializa objetos con duración dinámica de almacenamiento. La expresión intenta asignar almacenamiento y luego intenta construir e inicializar un único objeto sin nombre o un array de objetos en el almacenamiento asignado. La expresión devuelve un puntero prevale al objeto construido o, si se ha construido un array de objetos, un puntero al elemento inicial del array. 
En nuestro caso, utilizamos null en la creación del objeto miJugador para indiciar que aún no apunta a ningún objeto, ya que aun no sabemos qué tipo de jugador es. Cuando se elige al personaje, por ejemplo Otaku(); usamos el new para asignar Otaku() a miJugador. Esta fue una práctica recomendada por alguien externo.

## GITHUB
Fue una combinación de mentorías por parte del grupo estudiantil Bin Code sumado a una asistencia guiada por agentes virtuales, aplicando una metodología iterativa con experimentación práctica. 
Gracias a videos y a las instrucciones de la profesora en los documentos referenciados, utilizamos los comandos git add, git commit m-, git push source/branch. Nos basamos en el video para crear las carpetas. Las carpetas fueron creadas directamente en las computadoras para luego ser subidas a github. El proceso para subir las carpetas fue similar al de subir los documentos. Fue un proceso colaborativo entre todo el equipo.

## Referencias: 
cppreference.com. (s. f.). new (C++ language). https://en.cppreference.com/cpp/language/new
cppreference.com. (s. f.). nullptr (C++ language). https://en.cppreference.com/cpp/language/nullptr
GitHub. (8 de julio de 2024). How to upload files and folders to GitHub: GitHub for beginners [Archivo de Vídeo]. YouTube. https://www.youtube.com/watch?v=tlu5e0TxSzo 
Deprogame. (2025, febrero 5). Crear ventanas en SFML: Ejemplo y explicación detallada. https://deprogame.blogspot.com/2025/02/crear-ventanas-en-sfml-ejemplo-y.html
SFML. (s. f.). Documentation for SFML 3.0.2. https://www.sfml-dev.org/documentation/3.0.2/
SFML. (s. f.). Annotated class list (SFML 3.0.2). https://www.sfml-dev.org/documentation/3.0.2/annotated.html
SFML. (s. f.). sf::Font class reference. https://www.sfml-dev.org/documentation/3.0.2/classsf_1_1Font.html
SFML. (s. f.). sf::Music class reference. https://www.sfml-dev.org/documentation/3.0.2/classsf_1_1Music.html
SFML. (s. f.). Sprites and textures tutorial. https://www.sfml-dev.org/tutorials/3.0/graphics/sprite/#using-sftexture-with-opengl-code
YouTube. (s. f.). SFML tutorial video. https://youtu.be/s2g0mPxZnvM
YouTube. (s. f.). SFML tutorial video. https://www.youtube.com/watch?v=7QBUqLdCV1g
YouTube. (s. f.). SFML tutorial video. https://youtu.be/RSM7qAMbIJI