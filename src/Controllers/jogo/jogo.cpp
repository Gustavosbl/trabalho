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

void Jogo::setBallsPositions(std::shared_ptr<CenarioJogo> cenarioJogo, std::vector<std::shared_ptr<Bolinha>> &bolinhas) {
    int cont = 0;
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 25; j++) {
            if (cenarioJogo->getMap()[i*30][j*30] == 3 || cenarioJogo->getMap()[i*30][j*30] == 6) {
                std::shared_ptr<Textura> textura = bolinhas[cont]->getTextura();
                textura->setTarget(j*30, i*30);
                bolinhas[cont]->setTextura(textura);
                cont++;
            }
        }
    }
}

void Jogo::setInitialPosition(std::shared_ptr<Personagem> personagem, std::shared_ptr<CenarioJogo> cenarioJogo) {
    int b = 0;
    for (unsigned long int i = 0; i < cenarioJogo->getHeight(); i++) {
        for (unsigned long int j = 0; j < cenarioJogo->getWidth(); j++) {
            if ((personagem->getGhost() == false && cenarioJogo->getMap()[i][j] == 4) || (personagem->getGhost() == true && cenarioJogo->getMap()[i][j] == 5)) {
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
    if (personagem->getGhost() == false) {
        if ((x != 0 || y != 0) && (x != oldX || y != oldY)) {
            std::shared_ptr<Textura> textura = personagem->getTextura();
            int tx = textura->getTarget().x;
            int ty = textura->getTarget().y;
            if ((mapa[ty+y][tx+x] == 3 || mapa[ty+y][tx+x] == 4 || mapa[ty+y][tx+x] == 6) && (mapa[ty+personagem->getHeight()-1+y][tx+x] == 3 || mapa[ty+personagem->getHeight()-1+y][tx+x] == 4 || mapa[ty+personagem->getHeight()-1+y][tx+x] == 6) && (mapa[ty+y][tx+personagem->getWidth()-1+x] == 3 || mapa[ty+y][tx+personagem->getWidth()-1+x] == 4 || mapa[ty+y][tx+personagem->getWidth()-1+x] == 6) && (mapa[ty+personagem->getHeight()-1+y][tx+personagem->getWidth()-1+x] == 3 || mapa[ty+personagem->getHeight()-1+y][tx+personagem->getWidth()-1+x] == 4 || mapa[ty+personagem->getHeight()-1+y][tx+personagem->getWidth()-1+x] == 6)) {
                textura->setTarget(tx+x, ty+y);
                personagem->setTextura(textura);    
                return 0;
            }
            else if ((mapa[ty+oldY][tx+oldX] == 3 || mapa[ty+oldY][tx+oldX] == 4 || mapa[ty+oldY][tx+oldX] == 6) && (mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] == 3 || mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] == 4 || mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] == 6) && (mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] == 3 || mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] == 4 || mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] == 6) && (mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] == 3 || mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] == 4 || mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] == 6)) {
                textura->setTarget(tx+oldX, ty+oldY);
                personagem->setTextura(textura); 
                return 1;
            }
        }
        else  {
            std::shared_ptr<Textura> textura = personagem->getTextura();
            int tx = textura->getTarget().x;
            int ty = textura->getTarget().y;
            if ((mapa[ty+oldY][tx+oldX] == 3 || mapa[ty+oldY][tx+oldX] == 4 || mapa[ty+oldY][tx+oldX] == 6) && (mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] == 3 || mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] == 4 || mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] == 6) && (mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] == 3 || mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] == 4 || mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] == 6) && (mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] == 3 || mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] == 4 || mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] == 6)) {
                textura->setTarget(tx+oldX, ty+oldY);
                personagem->setTextura(textura);    
                return 1;
            }
            return 0;
        }
    }
    else {
        if ((x != 0 || y != 0) && (x != oldX || y != oldY)) {
            std::shared_ptr<Textura> textura = personagem->getTextura();
            int tx = textura->getTarget().x;
            int ty = textura->getTarget().y;
            if ((mapa[ty+y][tx+x] >= 2 && mapa[ty+y][tx+x] <= 6) && (mapa[ty+personagem->getHeight()-1+y][tx+x] >= 2 && mapa[ty+personagem->getHeight()-1+y][tx+x] <= 6) && (mapa[ty+y][tx+personagem->getWidth()-1+x] >= 2 && mapa[ty+y][tx+personagem->getWidth()-1+x] <= 6) && (mapa[ty+personagem->getHeight()-1+y][tx+personagem->getWidth()-1+x] >= 2 && mapa[ty+personagem->getHeight()-1+y][tx+personagem->getWidth()-1+x] <= 6)) {
                textura->setTarget(tx+x, ty+y);
                personagem->setTextura(textura);    
                return 0;
            }
            else if ((mapa[ty+oldY][tx+oldX] >= 2 && mapa[ty+oldY][tx+oldX] <= 6) && (mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] >= 2 && mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] <= 6) && (mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] >= 2 && mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] <= 6) && (mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] >= 2 && mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] <= 6)) {
                textura->setTarget(tx+oldX, ty+oldY);
                personagem->setTextura(textura); 
                return 1;
            }
        }
        else  {
            std::shared_ptr<Textura> textura = personagem->getTextura();
            int tx = textura->getTarget().x;
            int ty = textura->getTarget().y;
            if ((mapa[ty+oldY][tx+oldX] >= 2 && mapa[ty+oldY][tx+oldX] <= 6) && (mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] >= 2 && mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] <= 6) && (mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] >= 2 && mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] <= 6) && (mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] >= 2 && mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] <= 6)) {
                textura->setTarget(tx+oldX, ty+oldY);
                personagem->setTextura(textura);    
                return 1;
            }
            return 0;
        }
    }
}

int Jogo::localCharacterControl(std::shared_ptr<Personagem> personagem, std::vector<std::shared_ptr<Personagem>> &inimigos, std::vector<std::shared_ptr<Bolinha>> &bolinhas, std::shared_ptr<CenarioJogo> cenarioJogo, std::shared_ptr<Teclado> teclado, std::shared_ptr<int> x, std::shared_ptr<int> y) { 
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
    int i = setCharacterPosition(personagem, cenarioJogo, newX, newY, (*x), (*y));
    if (i == 0) {
        (*x) = newX;
        (*y) = newY;
    }
    int xpse = personagem->getTextura()->getTarget().x;
    int ypse = personagem->getTextura()->getTarget().y;
    int xpid = personagem->getTextura()->getTarget().x+29;
    int ypid = personagem->getTextura()->getTarget().y+29;
    for (int i = 0; i < inimigos.size(); i++) {
        int xise = inimigos[i]->getTextura()->getTarget().x;
        int yise = inimigos[i]->getTextura()->getTarget().y;
        int xiid = inimigos[i]->getTextura()->getTarget().x+29;
        int yiid = inimigos[i]->getTextura()->getTarget().y+29;


        if (((xpse <= xise && xpid >= xise) || (xpse <= xiid && xpid >= xiid)) && ((ypse <= yise && ypid >= yise) || (ypse <= yiid && ypid >= yiid))) {
            if (personagem->getPower() == true && personagem->getGhost() == false && inimigos[i]->getGhost() == true) {
                inimigos[i]->setLife(inimigos[i]->getLife()-1);
                return 0;
            }
            return 1;
        }
    }
    int cont = 0;
    for (int i = 0; i < bolinhas.size(); i++) {
        int xbse = bolinhas[i]->getTextura()->getTarget().x;
        int ybse = bolinhas[i]->getTextura()->getTarget().y;
        int xbid = bolinhas[i]->getTextura()->getTarget().x+29;
        int ybid = bolinhas[i]->getTextura()->getTarget().y+29;
        if (xbse == xpse && ybse == ypse) {
            if (bolinhas[i]->getDisplay() == true) {
                bolinhas[i]->setDisplay();
                personagem->setScore(personagem->getScore()+bolinhas[i]->getScore());
                if (bolinhas[i]->getPower() == true) {
                    personagem->setPower();
                }
                cont++;
            }
        }
    }
    if (cont == bolinhas.size()) return 2;
    return 0;
}

void Jogo::localNpcControl(std::shared_ptr<Personagem> personagem, std::shared_ptr<CenarioJogo> cenarioJogo, int *x, int *y, int i) { 
    int random0 = rand() % 100;
    int random1 = rand() % 2;
    int random2 = rand() % 2;
    int newX = 0;
    int newY = 0;
    std::shared_ptr<Textura> textura = personagem->getTextura();
    int tx = textura->getTarget().x;
    int ty = textura->getTarget().y;
    if (random0 == 0 || (x[i] == 0 && y[i] == 0)) {
        if (random1 == 0 && random2 == 0) {
            newX = -1;
            newY = 0;
        }
        else if (random1 == 0 && random2 == 1) {
            newX = 1;
            newY = 0;
        }
        else if (random1 == 1 && random2 == 0 && (cenarioJogo->getMap()[ty-1][tx] == 2 || cenarioJogo->getMap()[ty+30][tx] == 2 || cenarioJogo->getMap()[ty][tx] != 5)) {
            newX = 0;
            newY = -1;
        }
        else if (random1 == 1 && random2 == 1 && cenarioJogo->getMap()[ty][tx] != 2 && cenarioJogo->getMap()[ty+29][tx] != 2 && cenarioJogo->getMap()[ty+30][tx] != 2 && cenarioJogo->getMap()[ty][tx] != 5) {
            newX = 0;
            newY = 1;
        }
    }
    int j = setCharacterPosition(personagem, cenarioJogo, newX, newY, x[i], y[i]);
    if (j == 0) {
        x[i] = newX;
        y[i] = newY;
    }
}

void Jogo::iniciarJogo(std::shared_ptr<CenarioJogo> cenarioJogo, std::shared_ptr<Personagem> personagem, std::vector<std::shared_ptr<Personagem>> &inimigos, std::vector<std::shared_ptr<Bolinha>> &bolinhas, std::shared_ptr<View> view, std::shared_ptr<Teclado> teclado, int multi) {

    SDL_Event event;

    setBallsPositions(cenarioJogo, bolinhas);

    setInitialPosition(personagem, cenarioJogo);
    
    bool rodando = true;

    std::shared_ptr<int> x (new int);
    std::shared_ptr<int> y (new int);
    (*x) = 0;
    (*y) = 0;
    std::shared_ptr<int> x1 (new int);
    std::shared_ptr<int> y1 (new int);
    int *ix = (int*)malloc(inimigos.size()*sizeof(int));
    int *iy = (int*)malloc(inimigos.size()*sizeof(int));
    for (int i = 0; i < inimigos.size(); i++) {
        ix[i] = 0;
        iy[i] = 0;
        setInitialPosition(inimigos[i], cenarioJogo);
    }
    while(rodando) {
        int res = localCharacterControl(personagem, inimigos, bolinhas, cenarioJogo, teclado, x, y);
        if (res == 2) rodando = false;
        if(personagem->getLife() >= 0 && res == 1) {
            personagem->setLife(personagem->getLife()-1);
            if(personagem->getLife() >= 0) setInitialPosition(personagem, cenarioJogo);
            else {
                if (multi == 0) {
                    rodando = false; 
                }
            }
        }
        for (int i = 0; i < inimigos.size(); i++) {
            localNpcControl(inimigos[i], cenarioJogo, ix, iy, i);
        }
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                rodando = false;
            }
        }
        view->renderClear();
        view->renderBackground(cenarioJogo->getTextura());
        for (int i = 0; i < bolinhas.size(); i++) {
            printf("i = %d; j = %d; num = %d\n", bolinhas[i]->getTextura()->getTarget().y, bolinhas[i]->getTextura()->getTarget().x, i);
            if (bolinhas[i]->getDisplay() == true) view->renderCharacter(bolinhas[i]->getTextura());
        }
        for (int i = 0; i < inimigos.size(); i++) {
            if (inimigos[i]->getLife() >= 0) view->renderCharacter(inimigos[i]->getTextura());
        }
        if (personagem->getLife() >= 0) view->renderCharacter(personagem->getTextura());
        view->renderPresent();
        SDL_Delay(10);
    }
};