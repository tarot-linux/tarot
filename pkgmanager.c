#include <stdio.h>
#include <curl/curl.h>


void readPkg(char* path)
{
	FILE * fp;
	int c;

	fp = fopen(path, "r");
	while(1) {
      		c = fgetc(fp);
      		if( feof(fp) ) { 
         		break ;
      		}
      		printf("%c", c);
   	}
	fclose(fp);
}

void getPkg() 
{
	
}

void fetchPkgInfo()
{

}


int fetchPkgInfo-GIT() 
{
	return 0;
}

int main(int argc, char *argv[])
{

	readPkg("vim/info");
	return 0;
}
