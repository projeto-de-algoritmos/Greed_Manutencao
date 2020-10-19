#include "funcionario.hpp"

Funcionario::Funcionario(Tarefa tarefa){
    listaTarefas.push_back(tarefa); 
}

void Funcionario::setHora(int hora){
    this->horaDisponivel = hora;
}

void Funcionario::setMin(int min){
    this->minDisponivel = minDisponivel;
}  

void Funcionario::imprimeTarefas(){
    for(Tarefa t: listaTarefas)
        t.imprimir(); 
}