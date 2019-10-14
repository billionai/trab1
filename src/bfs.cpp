#include "bfs.h"


bfsSearch::bfsSearch() : Search() { };

bfsSearch::~bfsSearch(){};

void bfsSearch::setMap(labirinto &map) {
    this->map = &map;
}

const std::deque<std::pair<int,int>> &bfsSearch::getSequenciaDeVisitados() const{
    return this->visitados;
}

std::vector<std::pair<int,int> > bfsSearch::executar(){
    std::vector<std::pair<int,int> > resp;
    std::queue<std::pair < int , int > > fila;
    std::pair<int ,int> auxNaoVisitado(-1,-1);
    std::vector<std::vector< std::pair<int , int > > > mapaVisitados(this->map->getHeight() , std::vector<std::pair<int , int> >(this->map->getWidth() , auxNaoVisitado));
    std::pair<int,int> atual(this->map->getStart());
    std::pair<int , int> inicio(atual);
    std::pair<int,int> fim(this->map->getEnd());
    mapaVisitados[atual.first][atual.second] = atual;
    while(atual != fim){
        this->visitados.push_back(atual);
        std::vector<std::pair<int , int> > auxFilhos(8 , {0,0});
        auxFilhos[0] = {atual.first-1 , atual.second};
        auxFilhos[1] = {atual.first-1 , atual.second-1};
        auxFilhos[2] = {atual.first , atual.second-1};
        auxFilhos[3] = {atual.first+1 , atual.second-1};
        auxFilhos[4] = {atual.first+1 , atual.second};
        auxFilhos[5] = {atual.first+1 , atual.second+1};
        auxFilhos[6] = {atual.first , atual.second+1};
        auxFilhos[7] = {atual.first-1 , atual.second+1};
        for(int i = 0; i < 8 ; i++){
            if( ( auxFilhos[i].first >= 0 && auxFilhos[i].first < this->map->getHeight() ) && ( auxFilhos[i].second >= 0 && auxFilhos[i].second < this->map->getWidth() ) ){
                if(mapaVisitados[auxFilhos[i].first ][ auxFilhos[i].second] == auxNaoVisitado){
                    if(this->map->operator[](auxFilhos[i]) != WALL){
                        mapaVisitados[auxFilhos[i].first ][ auxFilhos[i].second] = atual;
                        fila.push(auxFilhos[i]);
                    }
                }
            }
        }
        atual = fila.front();
        fila.pop();
    }
    while(atual != inicio){
        resp.push_back(atual);
        atual = mapaVisitados[atual.first][atual.second];
    }
    return resp;
}

void bfsSearch::reset(){
    this->visitados.clear();
}
