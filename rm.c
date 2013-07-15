#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
  struct stat buf;
	
	stat(argv[1], &buf);
	
	if (S_ISREG(buf.st_mode))
	  unlink(argv[1]);
	else
	  printf("It can not remove, except regular file.\n");
}
