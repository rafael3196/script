#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bannerPrincipal(){
	int option;
	printf("##########################################\n");
	printf("####### SPECTACLES  - OSINT TOOLS ########\n");
	printf("##########################################\n");
	printf("OPTION - FUNCTION\n");
	printf("  1    - Email Identify\n");
	printf("  2    - ...\n");
	scanf("%i",&option);
	return option;
}

void emailIdentify(char host[100]){
	char cmd[150];
	sprintf(cmd,"wget -q %s",host);
	system(cmd);
	sprintf(cmd,"cat index.html | grep @ | sed 's/<br>//g' | sed 's/\t//g' | sed 's/<p>//g' | sed 's/%c//g' | sort > email.txt", ' ');
	system(cmd);
	system("cat email.txt");
	system("rm index.html* email.txt");
	printf("###########################\n");
	printf("Pressione Enter para continuar\n");
	system("read");
	main();
}

int main(){
	int option = bannerPrincipal();
	if(option == 1){
		printf("Insira o Host: ");
		char key[100];
		scanf("%s",&key);
		emailIdentify(key);
	}else{
		printf("Opção Invalida");
	}
}
