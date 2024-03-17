#include"player.h"
#define row 3000
#define col 3000
int width,height;
IMAGE image[row+5][col+5];
IMAGE sumimage[row+5][col+5];
int init(char* filename)
{
	int success = decoder_init(filename);
	assert(!success);
	Frame f = decoder_get_frame();
	width = f.width;
	height = f.height;
	int index = 0; 
	for (int i = 1; i <= f.height;i++)
	{
		for (int j = 1; j <= f.width; j++)
		{  
			int r,g,b;
			r = f.data[index++];
                        g = f.data[index++];
                        b = f.data[index++];
                        image[i][j].r = r;
			image[i][j].g = g;
			image[i][j].b = b;
			image[i][j].gray = (r*30 + g*59 + b*11) / 100;
			sumimage[i][j].r = sumimage[i-1][j].r + sumimage[i][j-1].r - sumimage[i-1][j-1].r + image[i][j].r;
			sumimage[i][j].g = sumimage[i-1][j].g + sumimage[i][j-1].g - sumimage[i-1][j-1].g + image[i][j].g;
			sumimage[i][j].b = sumimage[i-1][j].b + sumimage[i][j-1].b - sumimage[i-1][j-1].b + image[i][j].b;
			sumimage[i][j].gray = sumimage[i-1][j].gray + sumimage[i][j-1].gray - sumimage[i-1][j-1].gray + image[i][j].gray;
		}
		if (f.linesize > 3*f.width)  
		{
                        index+=f.linesize - 3*f.width;
                }
        }
        return success;
}
int getf()
{
	Frame f = decoder_get_frame();
        width = f.width;
        height = f.height;
        int index = 0;
        for (int i = 1; i <= f.height;i++)
        {
                for (int j = 1; j <= f.width; j++)
                {
                        int r,g,b;
                        r = f.data[index++];
                        g = f.data[index++];
                        b = f.data[index++];
                        image[i][j].r = r;
                        image[i][j].g = g;
                        image[i][j].b = b;
                        image[i][j].gray = (r*30 + g*59 + b*11) / 100;
                        sumimage[i][j].r = sumimage[i-1][j].r + sumimage[i][j-1].r - sumimage[i-1][j-1].r + image[i][j].r;
                        sumimage[i][j].g = sumimage[i-1][j].g + sumimage[i][j-1].g - sumimage[i-1][j-1].g + image[i][j].g;
                        sumimage[i][j].b = sumimage[i-1][j].b + sumimage[i][j-1].b - sumimage[i-1][j-1].b + image[i][j].b;
                        sumimage[i][j].gray = sumimage[i-1][j].gray + sumimage[i][j-1].gray - sumimage[i-1][j-1].gray + image[i][j].gray;
                }
                if (f.linesize > 3*f.width)
                {
                        index+=f.linesize - 3*f.width;
                }
        }
}
void Color()
{	
        for (int i = 1; i <= height;i++)
        {
                for (int j = 1; j <= width; j++)
                {			
                        printf("\033[38;2;%d;%d;%dm██",image[i][j].r,image[i][j].g,image[i][j].b);
                }
                printf("\n");
        }
	fflush(stdout);
}

void Gray()
{
	for (int i = 1; i <= height;i++)                                                                                       {
                for (int j = 1; j <= width; j++)
                {
                        printf("\033[38;2;%d;%d;%dm██",image[i][j].gray,image[i][j].gray,image[i][j].gray);
                }
                printf("\n");
        }
}

void resize(int win, int step)
{
	memset(image,0,sizeof(image));
	height = height / step;
	width = width / step;
	for (int i = 1, x_index = 1; i <= height; i++, x_index += step)
	{
		for (int j = 1, y_index = 1; j <= width; j++, y_index += step)
		{
			image[i][j].g = (sumimage[x_index + win - 1][y_index + win - 1].g - sumimage[x_index - 1][y_index + win - 1].g - sumimage[x_index + win -1][y_index - 1].g + sumimage[x_index - 1][y_index - 1].g) / (win * win);
			image[i][j].r = (sumimage[x_index + win - 1][y_index + win - 1].r - sumimage[x_index - 1][y_index + win - 1].r - sumimage[x_index + win -1][y_index - 1].r + sumimage[x_index - 1][y_index - 1].r) / (win * win);
			image[i][j].b = (sumimage[x_index + win - 1][y_index + win - 1].b - sumimage[x_index - 1][y_index + win - 1].b - sumimage[x_index + win -1][y_index - 1].b + sumimage[x_index - 1][y_index - 1].b) / (win * win);
			image[i][j].gray = (sumimage[x_index + win - 1][y_index + win - 1].gray - sumimage[x_index - 1][y_index + win - 1].gray - sumimage[x_index + win -1][y_index - 1].gray + sumimage[x_index - 1][y_index - 1].gray) / (win * win);
		}
	}
}
