#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <iostream>
#include <vector>

#include "tarefa.hpp"

using namespace std;

class Funcionario {
private:
    vector <Tarefa> listaTarefas;
    int horaDisponivel;
    int minDisponivel;
public:
    int getHoraDisponivel();
    int getMinDisponivel();
    void adicionarTarefa(Tarefa tarefa);
    void imprimeTarefas();
    int totalTarefas();
};

#endif