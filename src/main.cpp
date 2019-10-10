#include "labirinto.h"
#include "interface_init.h"
#include "interface_labirinto.h"


int main(int argc, char **argv){


	if(argc < 2){
		printf("uso: %s <arquivo>",argv[0]);
        return 1;
	}
    InterfaceInit inicializador;
	labirinto l(argv[1]);
    InterfaceLabirinto lab(0 , 0 , LINES-5 , COLS, l);
    lab.refresh();
    lab.definiPosicao(1 , 2 , GREEN_BLUE);
    lab.refresh();

	l.print();
	return 0;
}
