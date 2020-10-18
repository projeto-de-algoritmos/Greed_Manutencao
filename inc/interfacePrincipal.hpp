#ifndef INTERFACEPRINCIPAL_HPP
#define INTERFACEPRINCIPAL_HPP

#include <iostream>
#include <vector> 

using namespace std;

class InterfacePrincipal {
private: 
    vector <Tarefa> tarefas; 
public:
    InterfacePrincipal();
    void menuPrincipal();
    int getInt(string mensagem);
    string getString(string mensagem);
    void cadastroTarefa();
    void divisaoTarefas();
};

#endif
