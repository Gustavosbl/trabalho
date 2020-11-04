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
    int b = 0;
    for (unsigned long int i = 0; i < cenarioJogo->getHeight(); i++) {
        for (unsigned long int j = 0; j < cenarioJogo->getWidth(); j++) {
            if (personagem->getGhost() == false && cenarioJogo->getMap()[i][j] == 4) {
                printf("i = %d; j = %d; num = %d\n", i, j, cenarioJogo->getMap()[i][j]);
                std::shared_ptr<Textura> textura = personagem->getTextura();
                textura->setTarget(j, i);
                personagem->setTextura(textura);
                b = 1;
                break;
            }
        }
        if (b == 1) break;
    }
}

int Jogo::setCharacterPosition(std::shared_ptr<Personagem> personagem, std::shared_ptr<CenarioJogo> cenarioJogo, int x, int y, int oldX, int oldY){
    int **mapa = cenarioJogo->getMap();
    if (personagem->getGhost() == false && (x != 0 || y != 0) && (x != oldX || y != oldY)) {
        std::shared_ptr<Textura> textura = personagem->getTextura();
        int tx = textura->getTarget().x;
        int ty = textura->getTarget().y;
        if ((mapa[ty+y][tx+x] == 3 || mapa[ty+y][tx+x] == 4) && (mapa[ty+personagem->getHeight()-1+y][tx+x] == 3 || mapa[ty+personagem->getHeight()-1+y][tx+x] == 4) && (mapa[ty+y][tx+personagem->getWidth()-1+x] == 3 || mapa[ty+y][tx+personagem->getWidth()-1+x] == 4) && (mapa[ty+personagem->getHeight()-1+y][tx+personagem->getWidth()-1+x] == 3 || mapa[ty+personagem->getHeight()-1+y][tx+personagem->getWidth()-1+x] == 4)) {
            textura->setTarget(tx+x, ty+y);
            personagem->setTextura(textura);    
            return 0;
        }
        else if ((mapa[ty+oldY][tx+oldX] == 3 || mapa[ty+oldY][tx+oldX] == 4) && (mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] == 3 || mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] == 4) && (mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] == 3 || mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] == 4) && (mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] == 3 || mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] == 4)) {
            textura->setTarget(tx+oldX, ty+oldY);
            personagem->setTextura(textura); 
            return 1;
        }
    }
    else  {
        std::shared_ptr<Textura> textura = personagem->getTextura();
        int tx = textura->getTarget().x;
        int ty = textura->getTarget().y;
        if ((mapa[ty+oldY][tx+oldX] == 3 || mapa[ty+oldY][tx+oldX] == 4) && (mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] == 3 || mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] == 4) && (mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] == 3 || mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] == 4) && (mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] == 3 || mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] == 4)) {
            textura->setTarget(tx+oldX, ty+oldY);
            personagem->setTextura(textura);    
            return 1;
        }
        else {
            return 0;
        }
    }
}


void Jogo::iniciarJogo(std::shared_ptr<CenarioJogo> cenarioJogo, std::shared_ptr<Personagem> personagem, std::shared_ptr<View> view, std::shared_ptr<Teclado> teclado) {

    SDL_Event event;

    setInitialPosition(personagem, cenarioJogo);
    
    bool rodando = true;

    int x = 0;
    int y = 0;
    while(rodando) {
        int newX = 0;
        int newY = 0;
        
        teclado->updateState();
        if ((teclado->getState())[SDL_SCANCODE_UP]) {
            newX = 0; 
            newY = -1;
        }
        else if ((teclado->getState())[SDL_SCANCODE_DOWN]) {
            newX = 0; 
            newY = 1;
        }
        else if ((teclado->getState())[SDL_SCANCODE_RIGHT]) {
            newX = 1; 
            newY = 0;
        }
        else if ((teclado->getState())[SDL_SCANCODE_LEFT]) {
            newX = -1; 
            newY = 0;
        }
        int i = setCharacterPosition(personagem, cenarioJogo, newX, newY, x, y);
        if (i == 0) {
            x = newX;
            y = newY;
        }
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                rodando = false;
            }
        }

        view->renderWindow(personagem->getTextura(), cenarioJogo->getTextura());


        SDL_Delay(10);
    }
};