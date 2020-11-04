#include "../../../Include/Models/personagem/personagem.hpp"

Personagem::Personagem(int** pac, bool power1, bool ghost1, int width1, int height1)
{
    power = power1;
    ghost = ghost1;
    height = height1;
    width = width1;

    int mapa[1][1] = {{6}};
    // int **mapa = pac;
    imagem img;
    int factor = 30;
    int width = factor * 1;
    int height = factor * 1;
    img.width = width;
    img.height = height;
    img.r = (float*)malloc(sizeof(float) * img.width * img.height);
    img.g = (float*)malloc(sizeof(float) * img.width * img.height);
    img.b = (float*)malloc(sizeof(float) * img.width * img.height);
    int **mapa2 = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++)
    {
        mapa2[i] = (int *)malloc(width * sizeof(int));
    }

    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            for (int k = 0; k < factor; k++)
            {
                for (int l = 0; l < factor; l++)
                {
                    mapa2[factor * i + k][factor * j + l] = mapa[i][j];
                }
            }
        }
    }

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            int idx = i + (j * img.width);
            if (mapa2[j][i] == 0 || mapa2[j][i] == 3 || mapa2[j][i] == 4 || mapa2[j][i] == 5)
            {
                img.r[idx] = 0;
                img.g[idx] = 0;
                img.b[idx] = 0;
            }
            else if (mapa2[j][i] == 1)
            {
                img.r[idx] = 0;
                img.g[idx] = 0;
                img.b[idx] = 255;
            }
            else if (mapa2[j][i] == 2)
            {
                img.r[idx] = 200;
                img.g[idx] = 200;
                img.b[idx] = 200;
            }
            else {
                img.r[idx] = 0;
                img.g[idx] = 255;
                img.b[idx] = 0;
            }
        }
    }

    salvar_imagem("assets/pacman.jpg", &img);
    liberar_imagem(&img);
};

Personagem::~Personagem(){};

void Personagem::setTextura(std::shared_ptr<Textura> textura1)
{
    textura = textura1;
};
std::shared_ptr<Textura> Personagem::getTextura()
{
    return textura;
};
void Personagem::setPower()
{
    power = !power;
};
bool Personagem::getPower()
{
    return power;
};
bool Personagem::getGhost()
{
    return ghost;
};
void Personagem::setHeight(int height1)
{
    height = height1;
};
int Personagem::getHeight()
{
    return height;
};
void Personagem::setWidth(int width1)
{
    width = width1;
};
int Personagem::getWidth()
{
    return width;
};