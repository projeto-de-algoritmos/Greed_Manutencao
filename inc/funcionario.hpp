#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <iostream>
#include <vector>

#include "tarefa.hpp"

using namespace std; 

class Funcionario{
private: 
    vector <Tarefa> listaTarefas; 
    int horaDisponivel;
    int minDisponivel; 

public: 
    Funcionario(Tarefa tarefa);
    int getHora();
    void setHora(int hora); 
    int getMin(); 
    void setMin(int min);  
    void imprimeTarefas(); 
    int totalTarefas(); 
};


#endif