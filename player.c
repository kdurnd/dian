#include<stdio.h>
#include<getopt.h>
#include<string.h>
#include<stdlib.h>
#include"video_decoder.h"
static char *shortopts = "vht:";
int long_index;
static struct option long_options[] = 
{
	{"version", no_argument, NULL,'v'},
	{"help", no_argument, NULL, 'h'},
	{NULL,0,NULL,0},
};
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
			case 't':
				printf("%s\n", optarg);
				break;
			case '?':
				printf("unknown option\n");
				printf("usage: player [--version][-v][--help][-h]");
				break;
		}
	}
	return 0;
}
