#include<stdio.h>
#include<getopt.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include"video_decoder.h"
static char *shortopts = "vhc";
int long_index;
static struct option long_options[] = 
{
	{"version", no_argument, NULL,'v'},
	{"help", no_argument, NULL, 'h'},
	{"color",no_argument,NULL,'c'},
	{NULL,0,NULL,0},
};
void Color()
{
	int success = decoder_init("/home/yan/dian_jy/dragon.mp4");
        assert(!success);
        Frame f = decoder_get_frame();
        //for (int i = 0; i < 70; i++)
        f = decoder_get_frame();
        int index = 0;
        for (int i = 0; i < f.height;i++)
        {
                for (int j = 0; j < f.width; j++)
                {                                                                                                                                                                                                        int r,g,b;
                        r = f.data[index++];
                        g = f.data[index++];
                        b = f.data[index++];
                        printf("\033[38;2;%d;%d;%dm██",r,g,b);
                }
                if (f.linesize > 3*f.width)
                {
                        index+=f.linesize - 3*f.width;
                }
                printf("\n");
        }
}
int main(int argc,char* argv[])
{
	int o;
	while((o=getopt_long(argc,argv,shortopts,long_options,&long_index))!=-1)
	{
		switch(o)
		{
			case 'v':
				printf("dian-player v1.1\n");
				break;
			case 'h':
				printf("usage: player [--version][-v][--help][-h]");
				break;
			case 'c':
				Color();
				break;
			case '?':
				printf("unknown option\n");
				printf("usage: player [--version][-v][--help][-h]");
				break;
		}
	}
	int success = decoder_init("/home/yan/dian_jy/dragon.mp4");
	assert(!success);
	Frame f = decoder_get_frame();
	//for (int i = 0; i < 70; i++)
	f = decoder_get_frame();
	int index = 0;
	for (int i = 0; i < f.height;i++)
	{
		for (int j = 0; j < f.width; j++)
		{
			int r,g,b;
			r = f.data[index++];	
			g = f.data[index++];
			b = f.data[index++];
			int gray = (r*30 + g*59 + b*11) / 100;
			printf("\033[38;2;%d;%d;%dm██",gray,gray,gray);
		}
		if (f.linesize > 3*f.width)
		{
			index+=f.linesize - 3*f.width; 
		}
		printf("\n");
	}
	return 0;
}
