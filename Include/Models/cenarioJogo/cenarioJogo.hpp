#include <iostream>
#include <memory>
#include "../textura/textura.hpp"
#include "../../Controllers/imageprocessing/imageprocessing.hpp"

class CenarioJogo {
    private:
        std::shared_ptr<Textura> textura;
        int **map;
    public:
        CenarioJogo(int** mapa1);
        ~CenarioJogo();
        void setMap(int** mapa1);
        int** getMap();
        void setTextura(std::shared_ptr<Textura> textura1);
        std::shared_ptr<Textura> getTextura();
};