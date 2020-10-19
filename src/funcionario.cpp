#include "funcionario.hpp"

Funcionario::Funcionario(){}

int Funcionario::getHora(){
    return horaDisponivel;
}

int Funcionario::getMin(){
    return minDisponivel;
}

void Funcionario::adicionarTarefa(Tarefa tarefa){
    listaTarefas.push_back(tarefa); 
    this->horaDisponivel = tarefa.getHoraFinal();
    this->minDisponivel = tarefa.getMinFinal();
}

void Funcionario::imprimeTarefas(){
    for(Tarefa t: listaTarefas)
        t.imprimir(); 
}

int Funcionario::totalTarefas() {
    return listaTarefas.size();
}