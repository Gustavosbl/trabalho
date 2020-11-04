#include <imageprocessing.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define XMAXSIZE 20
#define YMAXSIZE 20

int main()
{
    // int mapa[21][25] =
    //     {
    //         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 1
    //         {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1}, // 2
    //         {1, 3, 1, 1, 1, 3, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 3, 1, 1, 1, 3, 1}, // 3
    //         {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1}, // 4
    //         {1, 3, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 3, 1}, // 5
    //         {1, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 1}, // 6
    //         {1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1}, // 7
    //         {0, 0, 0, 0, 1, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 1, 0, 0, 0, 0}, // 8
    //         {1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 2, 2, 2, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1}, // 9
    //         {3, 3, 3, 3, 3, 3, 3, 3, 1, 5, 5, 5, 5, 5, 5, 5, 1, 3, 3, 3, 3, 3, 3, 3, 3}, // 10
    //         {1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1}, // 11
    //         {0, 0, 0, 0, 1, 3, 1, 3, 3, 3, 3, 3, 4, 3, 3, 3, 3, 3, 1, 3, 1, 0, 0, 0, 0}, // 12
    //         {1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1}, // 13
    //         {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1}, // 14
    //         {1, 3, 1, 1, 1, 3, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 3, 1, 1, 1, 3, 1}, // 15
    //         {1, 3, 3, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 1}, // 16
    //         {1, 1, 1, 3, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 3, 1, 1, 1}, // 17
    //         {1, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 1}, // 18
    //         {1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1}, // 19
    //         {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1}, // 20
    //         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}  // 21
    //     };
    int mapa[1][1] = {{6}}; 

    imagem img;
    int factor = 30;
    int width = factor*1;
    int height = factor*1;
    img.width = width;
    img.height = height;
    img.r = malloc(sizeof(float) * img.width * img.height);
    img.g = malloc(sizeof(float) * img.width * img.height);
    img.b = malloc(sizeof(float) * img.width * img.height);
    int **map = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++)
    {
        map[i] = (int *)malloc(width * sizeof(int));
    }
    // int map[height][width];

    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            for (int k = 0; k < factor; k++)
            {
                for (int l = 0; l < factor; l++)
                {
                    map[factor*i + k][factor*j + l] = mapa[i][j];
                }
            }
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            int idx = i + (j * img.width);
            if (map[j][i] == 0 || map[j][i] == 3 || map[j][i] == 4 || map[j][i] == 5)
            {
                img.r[idx] = 0;
                img.g[idx] = 0;
                img.b[idx] = 0;
            }
            else if (map[j][i] == 1)
            {
                img.r[idx] = 0;
                img.g[idx] = 0;
                img.b[idx] = 255;
            }
            else if (map[j][i] == 2)
            {
                img.r[idx] = 200;
                img.g[idx] = 200;
                img.b[idx] = 200;
            }
            else
            {
                img.r[idx] = 0;
                img.g[idx] = 255;
                img.b[idx] = 0;
            }
            // printf("%d ", map[i][j]);
        }
        // printf("\n");
    }

    salvar_imagem("mapinha.jpg", &img);
    liberar_imagem(&img);
}