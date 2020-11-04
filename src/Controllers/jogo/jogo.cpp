#include "../../../Include/Controllers/jogo/jogo.hpp"
#include <iostream>
#include <memory>
#include <cmath>

Jogo::Jogo() {};

Jogo::~Jogo(){};

int Jogo::setSDLInit() {
    if ( SDL_Init (SDL_INIT_VIDEO) < 0 ) {
        std::cout << SDL_GetError();
    return 1;
  }
  return 0;
}

void Jogo::setInitialPosition(std::shared_ptr<Personagem> personagem, std::shared_ptr<CenarioJogo> cenarioJogo) {
    int ** mapa = cenarioJogo->getMap();
    for (unsigned long int i = 0; i < sizeof(mapa); i++) {
        for (unsigned long int j = 0; j < sizeof(mapa[i]); j++) {
            if (personagem->getGhost() == false && mapa[i][j] == 4) {
                std::shared_ptr<Textura> textura = personagem->getTextura();
                textura->setTarget(j, i);
                personagem->setTextura(textura);
            }
        }
    }
}

void Jogo::setCharacterPosition(std::shared_ptr<Personagem> personagem, std::shared_ptr<CenarioJogo> cenarioJogo, int x, int y){
    int **mapa = cenarioJogo->getMap();
    if (personagem->getGhost() == false) {
        std::shared_ptr<Textura> textura = personagem->getTextura();
        int tx = textura->getTarget().x;
        int ty = textura->getTarget().y;
        if (mapa[ty+y][tx+x] == 3 || mapa[ty+y][tx+x] == 4) {
            textura->setTarget(tx+x, ty+y);
            personagem->setTextura(textura);
        }
    }
}


void Jogo::iniciarJogo(std::shared_ptr<CenarioJogo> cenarioJogo, std::shared_ptr<Personagem> personagem, std::shared_ptr<View> view, std::shared_ptr<Teclado> teclado, SDL_Event *event) {

    setInitialPosition(personagem, cenarioJogo);
    
    bool rodando = true;

    int x = 0;
    int y = 0;
    while(rodando) {

        teclado->updateState();
        if ((teclado->getState())[SDL_SCANCODE_UP]) {
            x = 0; 
            y = -1;
        };
        if ((teclado->getState())[SDL_SCANCODE_DOWN]) {
            x = 0; 
            y = 1;
        };
        if ((teclado->getState())[SDL_SCANCODE_RIGHT]) {
            x = 1; 
            y = 0;
        };
        if ((teclado->getState())[SDL_SCANCODE_LEFT]) {
            x = -1; 
            y = 0;
        };
        setCharacterPosition(personagem, cenarioJogo, x, y);
        while (SDL_PollEvent(event)) {
            if (event->type == SDL_QUIT) {
                rodando = false;
            }
        }

        // view->renderWindow(personagem->getTextura(), cenarioJogo->getTextura());


        SDL_Delay(10);
    }
};