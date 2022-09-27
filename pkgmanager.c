#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <unistd.h>
#include <sys/types.h>

// TO DO
// everything
//
//
//



// reads a packages contents and prints them out.
void readPkg(char *path)
{
	FILE *fp;
	int c;

	fp = fopen(path, "r");
	if (fp) {
		while(1) {
			c = fgetc(fp);
			if( feof(fp) ) { 
				break ;
			}
			printf("%c", c);
		}
		fclose(fp);
	} else {
		printf("Invalid file location.\n");
	}
}

void getPkg() 
{
	// There should be a build directory in /var/tmp.	
}

int fetchPkg()
{
	// Implent curl to read the raw git content of tarot/tarot-pkgs.
	
	return 0;
}

void upgradeSys()
{

}


void updatePkg() 
{

}

void buildPkg() {
	fork();
	printf("Chicken wing");
}


int main(int argc, char *argv[])
{

	system("./tarot-pkgs/vim/build");

	return 0;
}
