#include "../../../Include/Models/personagem/personagem.hpp"

Personagem::Personagem(int** pac, bool power1, bool ghost1, int width1, int height1, char const* path)
{
    power = power1;
    ghost = ghost1;
    height = height1;
    width = width1;
    life = 2;
    score = 0;
    if (ghost1 == true) life = 0;

    // int mapa[1][1] = {{6}};
    int **mapa = pac;
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

    int r = rand() % 256;
    int g = rand() % 256;
    int b = rand() % 256;

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            int idx = i + (j * img.width);
            img.r[idx] = r;
            img.g[idx] = g;
            img.b[idx] = b;
        }
    }

    salvar_imagem(path, &img);
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
void Personagem::setLife(int life1){
    life = life1;
};
int Personagem::getLife(){
    return life;
};
void Personagem::setScore(unsigned long int score1){
    score = score1;
};
unsigned long int Personagem::getScore(){
    return score;
};