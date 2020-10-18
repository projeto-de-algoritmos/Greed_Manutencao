#include "tarefa.hpp"

Tarefa::Tarefa(int hI, int mI, int hF, int mF, string descricao){
    this->horaInicial = hI;
    this->horaFinal = hF;
    this->minInical = mI;
    this->minFinal= mF;
    this->descricao = descricao; 
    this->realizada = false; 
}