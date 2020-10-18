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
    imprimirHora("início", horaInicial, minInical); 
    imprimirHora("término", horaFinal, minFinal);
} 

void Tarefa::imprimirHora(string tipoHorario, int hr, int min){
    cout << "Horário de " << tipoHorario << ": "; 
    if(hr < 10)
        cout << "0"; 
    cout << hr << ":"; 
    if(min < 10)
        cout << "0"; 
    cout << min << endl;
}