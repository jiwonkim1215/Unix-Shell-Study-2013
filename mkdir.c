#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
  if(argc<2){
		printf("usage: mkdir directoryName\n");
		exit(0);
	}
	if(mkdir(argv[1],0755) != 0)
		printf("failure");
}

