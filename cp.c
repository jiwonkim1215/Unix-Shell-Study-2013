#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  int fd1, fd2;
	ssize_t nread;
	char buffer[1024];

	if (argc != 3){
	  fprintf(stderr, "usage: mycp file1 file2\n");
	  exit(0);
	}

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_WRONLY | O_CREAT, 0644);
	
	if (fd1 < 0 || fd2 < 0){
	  perror("");
	  exit(-1);
	}

	while ((nread = read(fd1, buffer, 1024)) > 0) {
	  if (write(fd2, buffer, nread) < nread){
		close(fd1);
		close(fd2);
	  }
	}

	close(fd1);
	close(fd2);

	return 0;
}
