#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	char cmd[150];
	sprintf(cmd,"wget -q %s",argv[1]);
	system(cmd);
	sprintf(cmd,"cat index.html | grep @ | sed 's/<br>//g' | sed 's/\t//g' | sed 's/<p>//g' | sed 's/%c//g' | sort > email.txt", ' ');
	system(cmd);
	system("rm index.html*");
	return 0;
}
