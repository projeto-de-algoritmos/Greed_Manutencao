#include "funcionario.hpp"

Funcionario::Funcionario(Tarefa tarefa){
    listaTarefas.push_back(tarefa); 
}

int Funcionario::getHora(){
    return horaDisponivel;
}

void Funcionario::setHora(int hora){
    this->horaDisponivel = hora;
}

int Funcionario::getMin(){
    return minDisponivel;
}

void Funcionario::setMin(int min){
    this->minDisponivel = minDisponivel;
}  

void Funcionario::imprimeTarefas(){
    for(Tarefa t: listaTarefas)
        t.imprimir(); 
}

int Funcionario::totalTarefas() {
    return listaTarefas.size();
}