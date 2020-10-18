#ifndef TAREFA_HPP
#define TAREFA_HPP

#include <iostream>
#include <string>

using namespace std; 

class Tarefa{
    private: 
        int horaInicial;
        int minInical; 
        int horaFinal;
        int minFinal;   
        string descricao; 
        bool realizada;
    public:
        Tarefa(int hI, int mI, int hF, int mF, string descricao);
};
#endif