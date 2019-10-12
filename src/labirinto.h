#ifndef LABIRINTO_H
#define LABIRINTO_H

#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "parede.h"

enum MAP_INFO{
	FREE_SPACE,
	WALL,
	BEGIN,
	END,
	ERROR
};

class labirinto{
	int height, width;
	int column_Begin, line_Begin;
	int column_End, line_End;
	std::vector<std::vector<MAP_INFO> > map;
private:
	void resize(int h,int w);


	/*Funcao que verifica quantas paredes existe a partir de uma posicao*/
	int check_num_wall(int column, int line);

	bool check_start_end(int column, int line);
public:

	labirinto(int h, int w);
	labirinto(char* filename);
	~labirinto(){
		height = 0;
		width = 0;
	}

	/*Funcao que escreve o labirinto criado em um arquivo */
	void write_labirinto(const char* filename);

	std::vector<MAP_INFO> operator [](int i){
		return map[i];
	}

	int operator [](std::pair<int, int> p){
		return map[p.first][p.second];
	}

	void gera_labirinto_manual(char* filename);
	void gera_labirinto_automatico(char* filename);

	void nova_geracao(int wallCount);

    int getHeight();
    int getWidth();
    	int getColumnBegin();
	int getLineBegin();
	int getColumnEnd();
	int getLineEnd();
	bool isFree(std::pair<int,int> coord);
	bool wallsAround(std::pair<int,int> coord);

	void setStart(std::pair<int, int> coord){map[coord.first][coord.second] = BEGIN;}
	void setEnd(std::pair<int,int> coord){map[coord.first][coord.second] = END;}
	parede create_wall(std::pair<int, int> start, std::pair<int, int> end);

	void print();
};

#endif
