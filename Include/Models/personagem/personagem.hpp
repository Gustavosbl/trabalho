#include <iostream>
#include <memory>
#include "../textura/textura.hpp"
#include "../../Controllers/imageprocessing/imageprocessing.hpp"

class Personagem {
    private:
        std::shared_ptr<Textura> textura;
        bool power, ghost;
        int height, width;
    public:
        Personagem(int** pac, bool power1, bool ghost1, int width1, int height1);
        ~Personagem();
        void setTextura(std::shared_ptr<Textura> textura1);
        std::shared_ptr<Textura> getTextura();
        void setPower();
        bool getPower();
        bool getGhost();
        void setHeight(int height1);
        int getHeight();
        void setWidth(int width1);
        int getWidth();
};