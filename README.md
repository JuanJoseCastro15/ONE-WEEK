# ONE WEEK - Simulador de Citas (Visual Novel)

## Resumen del Proyecto
**ONE WEEK** es una novela visual interactiva y simulador de citas desarrollado en C++. El juego se basa en mecánicas de gestión de recursos y árboles de decisión distribuidos a lo largo de 7 "días" (ciclos lógicos).

El jugador selecciona entre 4 perfiles iniciales (Gymrat, Otaku, Tóxico, NPC/Chico Bueno), cada uno con estadísticas base de atractivo, confianza y carisma. A través de escenarios cotidianos (responder mensajes, citas, dar regalos, o decidir mentir/ser infiel), las decisiones del jugador afectan dinámicamente las métricas de la pareja ("amor", "felicidad", "confianza"). 

El motor lógico evalúa constantemente estas variables: si el nivel de amor se agota, la relación termina prematuramente. Dependiendo del histórico de elecciones y las estadísticas acumuladas, la narrativa se bifurca hacia 4 finales principales y 1 final oculto.


## Tecnologías y Entorno
* **Lenguaje:** C++ (Lógica orientada a objetos, gestión de memoria).
* **Motor Gráfico:** SFML (Simple and Fast Multimedia Library).
* **Entorno de Desarrollo (IDE):** Visual Studio (Compilador MSVC, configuración de subsistema GUI).
* **Control de Versiones:** Git y GitHub.


## Arquitectura del Equipo
Este proyecto fue un esfuerzo multidisciplinario. Aunque todos los miembros colaboraron en el diseño narrativo y el ensamblaje de los 7 días, la implementación técnica se dividió de la siguiente manera:

* **[David Vigueros](https://github.com/luisdvigueros-arch) | Lógica Core y Optimización:** Diseño de la arquitectura de clases (POO) del motor subyacente y optimización de las estructuras de datos para las escenas.
* **[Fatima Vazques](https://github.com/FatimaSof) | UI y Narrativa:** Programación de la interfaz gráfica integrando la librería SFML y redacción principal del guion lógico.
* **[Juan Castro](https://github.com/JuanJoseCastro15) | Build Engineering y Repositorio:** Administración de GitHub, configuración del proyecto en Visual Studio (rutas relativas, dependencias, enlazador) y empaquetado de versiones (Releases).
* **[Mia De La Crúz](https://github.com/MiaDeLaCruz25) | Arte 2D:** Creación, formato y optimización de las imágenes y *assets* visuales del juego.


## Instalación y Ejecución
Para jugar sin necesidad de configurar el entorno de desarrollo:
1. Dirígete a la pestaña de [Releases](AQUI_PON_EL_LINK) del repositorio.
2. Descarga el paquete `.zip` de la versión más reciente.
3. Extrae el contenido (incluye el ejecutable `.exe`, librerías `.dll` de SFML y la carpeta `assets/`).
4. Ejecuta el juego directamente.


## Compilación desde el Código Fuente (Plug-and-Play)
El repositorio está diseñado para una integración sin fricción, con rutas relativas y eventos post-compilación (post-build) ya configurados. No es necesario vincular dependencias manualmente.

**Prerrequisitos:**
* Visual Studio (Carga de trabajo: Desarrollo para el escritorio con C++).

**Pasos de compilación:**
1. Clona el repositorio: `git clone https://github.com/TU_USUARIO/TU_REPOSITORIO.git`
2. Abre el archivo de solución (`.sln`) en Visual Studio.
3. Asegúrate de configurar la plataforma en **Release** y **x64**.
4. Haz clic en **Compilar** (`Ctrl + Shift + B`).

*Nota Técnica:* El sistema de compilación está automatizado. Los eventos post-compilación se encargarán de mover las `.dll` de SFML necesarias y conectar la carpeta de `assets/` al directorio de salida `bin/`, dejando el entorno listo para ejecución inmediata.


## 💡 Evolución del Proyecto (Post-Mortem)
Debido a la naturaleza académica del proyecto, la narrativa se integró directamente en el código fuente. En un entorno de producción escalable, el siguiente paso sería:
* Desacoplar los diálogos y valores estadísticos a archivos de configuración externos (JSON o CSV).
* Implementar un *parser* dinámico en C++ que construya el árbol de decisiones en tiempo de ejecución, permitiendo a los escritores modificar la historia sin necesidad de recompilar los binarios.
