#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int main(int argc, char* argv[]){
  struct stat buf;

	stat(argv[1], &buf);
	if (S_ISDIR(buf.st_mode)){
	   if (rmdir(argv[1]) != 0)
		printf("It cannot remove : not empty directory\n");
	}
	else
		printf("This is not directory\n");
}
