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
	setvbuf(stdout, buff, _IOFBF, sizeof(buff));
	int o, in = 1, need_resize = 0,need_color = 0, window, step;
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
				need_color = 1;
				break;
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
	changemode(1);
	do
	{
		int nosleep = 0;
		if(kbhit())
		{
			char ch = getchar();
			fflush(stdin);
			if (ch == ' ')
			{
				while(1)
				{
					usleep(1000);
					if(kbhit() && getchar()==' ')
						break;
				}
			}
			else if (ch == 'd' || ch == 'D')
				nosleep = 1;
		}
		system("clear");
		if (need_resize)
			resize(window, step);
	       	if(need_color)
			Color();
		else
			Gray();
		if (!nosleep)
			usleep(42000);
		getf();
	}while(!end());
	changemode(0);
	return 0;
}
