#include "../Include/Controllers/jogo/jogo.hpp"
#include <iostream>
#include <memory>

// int mapa[21][25] =
//         {
//             {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 1
//             {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1}, // 2
//             {1, 3, 1, 1, 1, 3, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 3, 1, 1, 1, 3, 1}, // 3
//             {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1}, // 4
//             {1, 3, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 3, 1}, // 5
//             {1, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 1}, // 6
//             {1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1}, // 7
//             {0, 0, 0, 0, 1, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 1, 0, 0, 0, 0}, // 8
//             {1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 2, 2, 2, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1}, // 9
//             {3, 3, 3, 3, 3, 3, 3, 3, 1, 5, 5, 5, 5, 5, 5, 5, 1, 3, 3, 3, 3, 3, 3, 3, 3}, // 10
//             {1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1}, // 11
//             {0, 0, 0, 0, 1, 3, 1, 3, 3, 3, 3, 3, 4, 3, 3, 3, 3, 3, 1, 3, 1, 0, 0, 0, 0}, // 12
//             {1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1}, // 13
//             {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1}, // 14
//             {1, 3, 1, 1, 1, 3, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 3, 1, 1, 1, 3, 1}, // 15
//             {1, 3, 3, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 1}, // 16
//             {1, 1, 1, 3, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 3, 1, 1, 1}, // 17
//             {1, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 1}, // 18
//             {1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1}, // 19
//             {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1}, // 20
//             {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}  // 21
//         };
// int pacman[1][1] = {{1}};

int ** mapa = (int**)malloc(sizeof(int*));
int ** pacman = (int**)malloc(sizeof(int*));

int main() {
    const unsigned int screenHeight = 630;
    const unsigned int screenWidth = 750;

    std::shared_ptr<View> view (new View(screenWidth, screenHeight));

    std::unique_ptr<Jogo> jogo (new Jogo());

    int stateSDL = jogo->setSDLInit();
    if (stateSDL > 0) return 1;

    int stateWindow = view->setWindow(); // Criando uma janela
    int stateRenderer = view->setRenderer(); // Inicializando o renderizador

    if (stateWindow + stateRenderer > 0) return 1;

    std::shared_ptr<Personagem> personagem (new Personagem(pacman, false, false, 30, 30));
    std::shared_ptr<CenarioJogo> cenarioJogo (new CenarioJogo(mapa));

    // char const *img1 = "../Assets/capi.png";
    // char const *img2 = "../Assets/park.jpeg";

    // std::shared_ptr<Textura> textura1 (new Textura(view->getRenderer(), img1, posX, posY)); // textura 1 (movel)
    // std::shared_ptr<Textura> textura2 (new Textura(view->getRenderer(), img2, posX, posY)); // textura 2 (fundo)
    
    // std::shared_ptr<Teclado> teclado (new Teclado()); // teclado


    // sistema->setTextura(1, textura1);
    // sistema->setTextura(2, textura2);

    // sistema->setTeclado(teclado);

    // sistema->calcularSistema2(speed, g); // (posicao inicial, posicao inicial, velocidade, intervalo de tempo, constante gravitacional)

    return 0;
}