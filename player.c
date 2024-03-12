#include<stdio.h>
#include<getopt.h>
#include<string.h>
#include<stdlib.h>
static char *shortopts = "vh";
int main(int argc,char* argv[])
{
	int o;
	while((o=getopt(argc,argv,shortopts))!=-1)
	{
		switch(o)
		{
			case 'v':
				printf("dian-player v1.0\n");
				break;
			case 'h':
				break;
			case '?':
				printf("error optopt: %c\n", optopt);
                		printf("error opterr: %d\n", opterr);
				break;
		}
	}
	return 0;
}
