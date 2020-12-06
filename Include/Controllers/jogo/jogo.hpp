#include "../../Models/teclado/teclado.hpp"
#include "../../Models/cenarioJogo/cenarioJogo.hpp"
#include "../../Models/personagem/personagem.hpp"
#include "../../Models/bolinha/bolinha.hpp"
#include "../../Views/view.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include "./json.hpp"
#include <memory>
#include <cstdlib>
#include <vector>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
using nlohmann::json;
using boost::asio::ip::udp;

class Jogo{
    public:
        Jogo();
        ~Jogo();

        int setSDLInit();
        void setBallsPositions(std::shared_ptr<CenarioJogo> cenarioJogo, std::vector<std::shared_ptr<Bolinha>> &bolinhas);
        void setInitialPosition(std::shared_ptr<Personagem> personagem, std::shared_ptr<CenarioJogo> cenarioJogo);
        int setCharacterPosition(std::shared_ptr<Personagem> personagem, std::shared_ptr<CenarioJogo> cenarioJogo, int x, int y, int oldX, int oldY);
        int localCharacterControl(std::shared_ptr<Personagem> personagem, std::vector<std::shared_ptr<Personagem>> &inimigos, std::vector<std::shared_ptr<Bolinha>> &bolinhas, std::shared_ptr<CenarioJogo> cenarioJogo, std::shared_ptr<Teclado> teclado, std::shared_ptr<int> x, std::shared_ptr<int> y, std::shared_ptr<int> cont);
        void localNpcControl(std::shared_ptr<Personagem> personagem, std::shared_ptr<CenarioJogo> cenarioJogo, int *x, int *y, int i);
        void iniciarJogo(std::shared_ptr<CenarioJogo> cenarioJogo, std::shared_ptr<Personagem> personagem, std::vector<std::shared_ptr<Personagem>> &inimigos, std::vector<std::shared_ptr<Bolinha>> &bolinhas, std::shared_ptr<View> view, std::shared_ptr<Teclado> teclado, int multi);
};