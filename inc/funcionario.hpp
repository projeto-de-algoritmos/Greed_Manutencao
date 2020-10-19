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
    void setHora(int hora); 
    void setMin(int min);  
    void imprimeTarefas(); 
};


#endif