#ifndef TAREFA_HPP
#define TAREFA_HPP

#include <iostream>

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
        int getHoraInicial();
        int getMinInicial();
        int getHoraFinal();
        int getMinFinal(); 
        void imprimir();
        void imprimirHora(string tipoHora, int hr, int min);
        
};
#endif