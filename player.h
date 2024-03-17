#ifndef PLAYER_H
#define PLAYER_H
#include<stdio.h>
#include<stdlib.h>
#include"video_decoder.h"
#include<getopt.h>
#include<assert.h>
#include<string.h>
#include<unistd.h>
typedef struct _IMAGE
{
	int r,g,b,gray;
}IMAGE;
int init(char* filename);
void Color();
void Gray();
void resize(int w,int h);
int getf();




#endif
