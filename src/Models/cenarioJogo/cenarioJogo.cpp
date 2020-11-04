#include "../../../Include/Models/cenarioJogo/cenarioJogo.hpp"

CenarioJogo::CenarioJogo(int **mapa1)
{
    int mapa[21][25] =
        {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 1
            {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1}, // 2
            {1, 3, 1, 1, 1, 3, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 3, 1, 1, 1, 3, 1}, // 3
            {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1}, // 4
            {1, 3, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 3, 1}, // 5
            {1, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 1}, // 6
            {1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1}, // 7
            {0, 0, 0, 0, 1, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 1, 0, 0, 0, 0}, // 8
            {1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 2, 2, 2, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1}, // 9
            {3, 3, 3, 3, 3, 3, 3, 3, 1, 5, 5, 5, 5, 5, 5, 5, 1, 3, 3, 3, 3, 3, 3, 3, 3}, // 10
            {1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1}, // 11
            {0, 0, 0, 0, 1, 3, 1, 3, 3, 3, 3, 3, 4, 3, 3, 3, 3, 3, 1, 3, 1, 0, 0, 0, 0}, // 12
            {1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1}, // 13
            {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1}, // 14
            {1, 3, 1, 1, 1, 3, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 3, 1, 1, 1, 3, 1}, // 15
            {1, 3, 3, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 1}, // 16
            {1, 1, 1, 3, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 3, 1, 1, 1}, // 17
            {1, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 1}, // 18
            {1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1}, // 19
            {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1}, // 20
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}  // 21
        };
    // int **mapa = mapa1;
    imagem img;
    int factor = 30;
    int width = factor * 25;
    int height = factor * 21;
    img.width = width;
    img.height = height;
    img.r = (float *)malloc(sizeof(float) * img.width * img.height);
    img.g = (float *)malloc(sizeof(float) * img.width * img.height);
    img.b = (float *)malloc(sizeof(float) * img.width * img.height);
    int **mapa2 = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++)
    {
        mapa2[i] = (int *)malloc(width * sizeof(int));
    }

    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 25; j++)
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

    map = mapa2;

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
        }
    }

    salvar_imagem("mapinha.jpg", &img);
    liberar_imagem(&img);
};

CenarioJogo::~CenarioJogo(){};

void CenarioJogo::setMap(int **mapa)
{
    map = mapa;
}
int **CenarioJogo::getMap()
{
    return map;
}
void CenarioJogo::setTextura(std::shared_ptr<Textura> textura1)
{
    textura = textura1;
}
std::shared_ptr<Textura> CenarioJogo::getTextura()
{
    return textura;
}