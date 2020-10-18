#include "tarefa.hpp"

Tarefa::Tarefa(int hI, int mI, int hF, int mF, string descricao){
    this->horaInicial = hI;
    this->horaFinal = hF;
    this->minInical = mI;
    this->minFinal= mF;
    this->descricao = descricao; 
    this->realizada = false; 
}

int Tarefa::getHoraInicial(){
    return horaInicial;
}

int Tarefa::getMinInicial(){
    return minInical;
}

int Tarefa::getHoraFinal(){
    return horaFinal; 
}

int Tarefa::getMinFinal(){
    return minFinal;
} 

void Tarefa::imprimir(){
    cout << "Tarefa: " << descricao << endl; 
    cout << "Horário de início: " << horaInicial << ":" << minInical << endl;
    cout << "Horário de término: " << horaFinal << ":" << minFinal << endl;
} 