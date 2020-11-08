#include "../../Models/teclado/teclado.hpp"
#include "../../Models/cenarioJogo/cenarioJogo.hpp"
#include "../../Models/personagem/personagem.hpp"
#include "../../Views/view.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>
#include <cstdlib>
#include <vector>

class Jogo{
    public:
        Jogo();
        ~Jogo();

        int setSDLInit();
        void setInitialPosition(std::shared_ptr<Personagem> personagem, std::shared_ptr<CenarioJogo> cenarioJogo);
        int setCharacterPosition(std::shared_ptr<Personagem> personagem, std::shared_ptr<CenarioJogo> cenarioJogo, int x, int y, int oldX, int oldY);
        int localCharacterControl(std::shared_ptr<Personagem> personagem, std::vector<std::shared_ptr<Personagem>> &inimigos, std::shared_ptr<CenarioJogo> cenarioJogo, std::shared_ptr<Teclado> teclado, std::shared_ptr<int> x, std::shared_ptr<int> y);
        void localNpcControl(std::shared_ptr<Personagem> personagem, std::shared_ptr<CenarioJogo> cenarioJogo, int *x, int *y, int i);
        void iniciarJogo(std::shared_ptr<CenarioJogo> cenarioJogo, std::shared_ptr<Personagem> personagem, std::vector<std::shared_ptr<Personagem>> &inimigos, std::shared_ptr<View> view, std::shared_ptr<Teclado> teclado, int multi);
};