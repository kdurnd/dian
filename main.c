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
	int o, in = 1;
	while((o=getopt_long(argc,argv,shortopts,long_options,&long_index))!=-1)
	{
		switch(o)
		{
			case 'v':
				printf("dian-player v1.1\n");
				break;
			case 'h':
				printf("usage: player [--color][-c][-f <filename>] [--version][-v][--help][-h]");
				break;
			case 'c':
				assert(!in);
				Color();
				break;
			/*case 'r':
				assert(!in);
				if(optind==argc || atoi(argv[optind-1]) || atoi(argv[optind]))
				resize(atoi(argv[optind-1]), atoi(argv[optind]));
				break;*/
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
	Gray();
	return 0;
}
