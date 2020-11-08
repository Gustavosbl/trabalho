#include "../Include/Controllers/jogo/jogo.hpp"
#include <string>
#include <iostream>
#include <memory>
#include <vector> 

int mapa1[21][25] =
        {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 1
            {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1}, // 2
            {1, 3, 1, 1, 1, 3, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 3, 1, 1, 1, 3, 1}, // 3
            {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1}, // 4
            {1, 3, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 3, 1}, // 5
            {1, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 1}, // 6
            {1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1}, // 7
            {0, 0, 0, 0, 1, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 1, 0, 0, 0, 0}, // 8
            {1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 2, 2, 2, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1}, // 9
            {3, 3, 3, 3, 3, 3, 3, 3, 1, 5, 5, 5, 5, 5, 5, 5, 1, 3, 3, 3, 3, 3, 3, 3, 3}, // 10
            {1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1}, // 11
            {0, 0, 0, 0, 1, 3, 1, 3, 3, 3, 3, 3, 4, 3, 3, 3, 3, 3, 1, 3, 1, 0, 0, 0, 0}, // 12
            {1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1}, // 13
            {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1}, // 14
            {1, 3, 1, 1, 1, 3, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 3, 1, 1, 1, 3, 1}, // 15
            {1, 3, 3, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 1}, // 16
            {1, 1, 1, 3, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 3, 1, 1, 1}, // 17
            {1, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 1}, // 18
            {1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1}, // 19
            {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1}, // 20
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}  // 21
        };

int main() {
    int **mapa = (int**)malloc(21*sizeof(int*));
    for (int i = 0; i < 21; i++) {
        mapa[i] = (int*)malloc(25*sizeof(int));
        for (int j = 0; j < 25; j++) {
            mapa[i][j] = mapa1[i][j];
        }
    }
    int **pacman = (int**)malloc(sizeof(int*));
    pacman[0] = (int*)malloc(sizeof(int));
    pacman[0][0] = 6;

    int **npc1 = (int**)malloc(sizeof(int*));
    npc1[0] = (int*)malloc(sizeof(int));
    npc1[0][0] = 6;

    const unsigned int screenHeight = 630;
    const unsigned int screenWidth = 750;

    std::shared_ptr<View> view (new View(screenWidth, screenHeight));

    std::unique_ptr<Jogo> jogo (new Jogo());

    int stateSDL = jogo->setSDLInit();
    if (stateSDL > 0) return 1;

    int stateWindow = view->setWindow(); // Criando uma janela
    int stateRenderer = view->setRenderer(); // Inicializando o renderizador

    if (stateWindow + stateRenderer > 0) return 1;
    
    char const *img1 = "./assets/pacman.jpg";
    char const *img2 = "./assets/mapinha.jpg";
    std::shared_ptr<Personagem> personagem (new Personagem(pacman, false, false, 30, 30, img1));
    std::shared_ptr<CenarioJogo> cenarioJogo (new CenarioJogo(mapa));
    std::shared_ptr<Textura> textura2 (new Textura(view->getRenderer(), img2, 0, 0)); // textura 2 (fundo)
    std::shared_ptr<Textura> textura1 (new Textura(view->getRenderer(), img1, 0, 0)); // textura 1 (movel)
    personagem->setTextura(textura1);
    cenarioJogo->setTextura(textura2);

    std::vector<std::shared_ptr<Personagem>> inimigos;
    char buffer2[100] = ".jpg";
    for (int i = 0; i < 5; i++) {
        char buffer[100] = "./assets/npc";
        std::string num = std::to_string(i);
        strcat(buffer, num.c_str());
        strcat(buffer, buffer2);
        std::shared_ptr<Personagem> inimigo (new Personagem(npc1, true, true, 30, 30, buffer));
        std::shared_ptr<Textura> textura12 (new Textura(view->getRenderer(), buffer, 0, 0));
        inimigo->setTextura(textura12);
        inimigos.push_back(inimigo);
    }
    
    std::shared_ptr<Teclado> teclado (new Teclado()); // teclado
    
    jogo->iniciarJogo(cenarioJogo, personagem, inimigos, view, teclado, 0);

    return 0;
}