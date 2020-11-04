#include "../../Models/teclado/teclado.hpp"
#include "../../Models/cenarioJogo/cenarioJogo.hpp"
#include "../../Models/personagem/personagem.hpp"
#include "../../Views/view.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>

class Jogo{
    public:
        Jogo();
        ~Jogo();

        int setSDLInit();
        void setInitialPosition(std::shared_ptr<Personagem> personagem, std::shared_ptr<CenarioJogo> cenarioJogo);
        void setCharacterPosition(std::shared_ptr<Personagem> personagem, std::shared_ptr<CenarioJogo> cenarioJogo, int x, int y);
        void iniciarJogo(std::shared_ptr<CenarioJogo> cenarioJogo, std::shared_ptr<Personagem> personagem, std::shared_ptr<View> view, std::shared_ptr<Teclado> teclado);
};