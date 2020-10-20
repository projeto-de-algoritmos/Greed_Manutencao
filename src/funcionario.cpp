#include "funcionario.hpp"

int Funcionario::getHoraDisponivel(){
    return horaDisponivel;
}

int Funcionario::getMinDisponivel(){
    return minDisponivel;
}

void Funcionario::adicionarTarefa(Tarefa tarefa) {
    listaTarefas.push_back(tarefa); 
    this->horaDisponivel = tarefa.getHoraFinal();
    this->minDisponivel = tarefa.getMinFinal();
}

void Funcionario::imprimeTarefas(){
    for(Tarefa t: listaTarefas){
        t.imprimir(); 
        cout << endl;
    }
}

int Funcionario::totalTarefas() {
    return listaTarefas.size();
}
