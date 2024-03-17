#include"player.h"
static char *shortopts = "vhcr:f:";
int long_index;
static struct option long_options[] = 
{
	{"version", no_argument, NULL,'v'},
	{"help", no_argument, NULL, 'h'},
	{"color",no_argument,NULL,'c'},
	{"resize", required_argument, NULL, 'r'},
	{NULL,0,NULL,0},
};
int main(int argc,char* argv[])
{
	char buff[16384];
	memset(buff, '\0', sizeof(buff));
	fprintf(stdout, "启用全缓冲\n");
	setvbuf(stdout, buff, _IOFBF, sizeof(buff));
	sleep(2);
	int o, in = 1, need_resize = 0, window, step;
	while((o=getopt_long(argc,argv,shortopts,long_options,&long_index))!=-1)
	{
		switch(o)
		{
			case 'v':
				printf("dian-player v1.1\n");
				break;
			case 'h':
				printf("usage: player [--color][-c][-f <filename>] [--version][-v][--help][-h]\n"
						"[--resize <window> <step>]");
				break;
			case 'c':
				assert(!in);
				do
				{
					if (need_resize)
						resize(window, step);
					Color();
					sleep(0.042);
					system("clear");
				}while(getf());
				return 0;
			case 'r':
				assert(!in);
				need_resize = 1;
				if(optind==argc || !atoi(argv[optind-1]) || !atoi(argv[optind]))
				{
					printf("resize failed\n");
					return 0;
				}
				window = atoi(argv[optind-1]);
			        step = atoi(argv[optind]);
				break;
			case 'f':
				in = init(optarg);
				break;
			case '?':
				printf("unknown option\n");
				printf("usage: player [--color][-c][-f <filename>] [--version][-v][--help][-h]");
				break;
		}
	}
	assert(!in);
	do
	{
		if (need_resize)
			resize(window, step); 
		Gray();
		sleep(0.042);
		system("clear");
		
	}while(getf());
	return 0;
}
