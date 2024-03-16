#include"player.h"
int width,height;
IMAGE image[3000][3000];
int init(char* filename)
{
	int success = decoder_init(filename);
	assert(!success);
	Frame f = decoder_get_frame();
	width = f.width;
	height = f.height;
	int index = 0;
	for (int i = 0; i < f.height;i++)                                                                                       {                                                                                                                               for (int j = 0; j < f.width; j++)                                                                                       {                                                                                                                               int r,g,b;                                                                                                              r = f.data[index++];
                        g = f.data[index++];
                        b = f.data[index++];
                        image[i][j].r = r;                                                                                                      image[i][j].g = g;                                                                                                      image[i][j].b = b;                                                                                                      image[i][j].gray = (r*30 + g*59 + b*11) / 100;                                                                  }                                                                                                                       if (f.linesize > 3*f.width)                                                                                             {
                        index+=f.linesize - 3*f.width;
                }
        }
        return success;
}

void Color()
{
        for (int i = 0; i < height;i++)
        {
                for (int j = 0; j < width; j++)
                {
                        printf("\033[38;2;%d;%d;%dm██",image[i][j].r,image[i][j].g,image[i][j].b);
                }
                printf("\n");
        }
}

void Gray()
{
	for (int i = 0; i < height;i++)                                                                                       {
                for (int j = 0; j < width; j++)
                {
                        printf("\033[38;2;%d;%d;%dm██",image[i][j].gray,image[i][j].gray,image[i][j].gray);
                }
                printf("\n");
        }
}
