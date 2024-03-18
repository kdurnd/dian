#ifndef PLAYER_H
#define PLAYER_H
#include<stdio.h>
#include<stdlib.h>
#include"video_decoder.h"
#include<getopt.h>
#include<assert.h>
#include<string.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <termios.h>
typedef struct _IMAGE
{
	int r,g,b,gray;
}IMAGE;
int init(char* filename);
void Color();
void Gray();
void resize(int w,int h);
int getf();
int kbhit();
void changemode(int dir);
int end();

#endif
