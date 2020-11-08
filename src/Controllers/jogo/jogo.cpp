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
            if ((personagem->getGhost() == false && cenarioJogo->getMap()[i][j] == 4) || (personagem->getGhost() == true && cenarioJogo->getMap()[i][j] == 5)) {
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
    if (personagem->getGhost() == false) {
        if ((x != 0 || y != 0) && (x != oldX || y != oldY)) {
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
            return 0;
        }
    }
    else {
        if ((x != 0 || y != 0) && (x != oldX || y != oldY)) {
            std::shared_ptr<Textura> textura = personagem->getTextura();
            int tx = textura->getTarget().x;
            int ty = textura->getTarget().y;
            if ((mapa[ty+y][tx+x] >= 2 && mapa[ty+y][tx+x] <= 5) && (mapa[ty+personagem->getHeight()-1+y][tx+x] >= 2 && mapa[ty+personagem->getHeight()-1+y][tx+x] <= 5) && (mapa[ty+y][tx+personagem->getWidth()-1+x] >= 2 && mapa[ty+y][tx+personagem->getWidth()-1+x] <= 5) && (mapa[ty+personagem->getHeight()-1+y][tx+personagem->getWidth()-1+x] >= 2 && mapa[ty+personagem->getHeight()-1+y][tx+personagem->getWidth()-1+x] <= 5)) {
                textura->setTarget(tx+x, ty+y);
                personagem->setTextura(textura);    
                return 0;
            }
            else if ((mapa[ty+oldY][tx+oldX] >= 2 && mapa[ty+oldY][tx+oldX] <= 5) && (mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] >= 2 && mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] <= 5) && (mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] >= 2 && mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] <= 5) && (mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] >= 2 && mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] <= 5)) {
                textura->setTarget(tx+oldX, ty+oldY);
                personagem->setTextura(textura); 
                return 1;
            }
        }
        else  {
            std::shared_ptr<Textura> textura = personagem->getTextura();
            int tx = textura->getTarget().x;
            int ty = textura->getTarget().y;
            if ((mapa[ty+oldY][tx+oldX] >= 2 && mapa[ty+oldY][tx+oldX] <= 5) && (mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] >= 2 && mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] <= 5) && (mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] >= 2 && mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] <= 5) && (mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] >= 2 && mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] <= 5)) {
                textura->setTarget(tx+oldX, ty+oldY);
                personagem->setTextura(textura);    
                return 1;
            }
            return 0;
        }
    }
}

int Jogo::localCharacterControl(std::shared_ptr<Personagem> personagem, std::vector<std::shared_ptr<Personagem>> &inimigos, std::shared_ptr<CenarioJogo> cenarioJogo, std::shared_ptr<Teclado> teclado, std::shared_ptr<int> x, std::shared_ptr<int> y) { 
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
    for (int i = 0; i < inimigos.size(); i++) {
        int xise = inimigos[i]->getTextura()->getTarget().x;
        int yise = inimigos[i]->getTextura()->getTarget().y;
        // int xisd = inimigos[i]->getTextura()->getTarget().x+29;
        // int yisd = inimigos[i]->getTextura()->getTarget().y;
        // int xiie = inimigos[i]->getTextura()->getTarget().x;
        // int yiie = inimigos[i]->getTextura()->getTarget().y+29;
        int xiid = inimigos[i]->getTextura()->getTarget().x+29;
        int yiid = inimigos[i]->getTextura()->getTarget().y+29;

        int xpse = personagem->getTextura()->getTarget().x;
        int ypse = personagem->getTextura()->getTarget().y;
        // int xpsd = personagem->getTextura()->getTarget().x+29;
        // int ypsd = personagem->getTextura()->getTarget().y;
        // int xpie = personagem->getTextura()->getTarget().x;
        // int ypie = personagem->getTextura()->getTarget().y+29;
        int xpid = personagem->getTextura()->getTarget().x+29;
        int ypid = personagem->getTextura()->getTarget().y+29;

        if (((xpse <= xise && xpid >= xise) || (xpse <= xiid && xpid >= xiid)) && ((ypse <= yise && ypid >= yise) || (ypse <= yiid && ypid >= yiid))) {
            return 1;
        }
    }
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

void Jogo::iniciarJogo(std::shared_ptr<CenarioJogo> cenarioJogo, std::shared_ptr<Personagem> personagem, std::vector<std::shared_ptr<Personagem>> &inimigos, std::shared_ptr<View> view, std::shared_ptr<Teclado> teclado, int multi) {

    SDL_Event event;

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
    std::vector<std::shared_ptr<Textura>> it;
    for (int i = 0; i < inimigos.size(); i++) {
        ix[i] = 0;
        iy[i] = 0;
        it.push_back(inimigos[i]->getTextura());
        setInitialPosition(inimigos[i], cenarioJogo);
    }
    while(rodando) {
        if(localCharacterControl(personagem, inimigos, cenarioJogo, teclado, x, y) == 1) rodando = false; 
        for (int i = 0; i < inimigos.size(); i++) {
            localNpcControl(inimigos[i], cenarioJogo, ix, iy, i);
        }
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                rodando = false;
            }
        }

        view->renderWindow(personagem->getTextura(), it, cenarioJogo->getTextura());

        SDL_Delay(10);
    }
};