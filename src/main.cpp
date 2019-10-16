#include "labirinto.h"
#include <iostream>
#include <string>

int main(int argc, char **argv){
	int height, width;
	srand(time(NULL));
	if(argc == 2){
		//printf("uso: %s <arquivo>\n",argv[0]);
		//ESTA AQUI PARA DEBUG
		int h,w;
		srand(atoi(argv[0]));
		labirinto l(30,30);
		l.nova_geracao(30);
		l.print();
		/*
		printf("would you like to print it? If so enter the name, otherwise, enter no\n");
		std::string name, no="no";
		std::cin >> name;
		if(name != no){
			name = "../mapas/" + name;
			l.write_labirinto(name.c_str());
		}
		*/
		return 0;
	}
	else if(argc > 2){
		if(argv[1][0] == '1'){//Opcao de criar labirinto manualmente
			printf("digite numero de colunas e linhas\n");
			scanf("%d %d", &height, &width);
			labirinto l( height, width);
			l.gera_labirinto_manual(argv[2]);
			l.print();
		}else if(argv[1][0] == '2'){//Opcao de criar labirinto automatico
	//  	printf("digite numero de colunas e linhas\n");
	//  	scanf("%d %d", &height, &width);
			labirinto l( 50, 50);
			l.nova_geracao(atoi(argv[2]));
			l.print();
		}else if(argv[1][0] == '3'){//Opcao de abrir um labirinto e rodar um algoritimo sobre ele
			labirinto l(argv[2]);
			l.print();
		}
	}else{
		labirinto l(30,30);
		l.nova_geracao(30);
		l.print();
	}
	return 0;
}
