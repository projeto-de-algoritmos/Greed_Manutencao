#ifndef INTERFACEPRINCIPAL_HPP
#define INTERFACEPRINCIPAL_HPP

#include "tarefa.hpp"

#include <vector>

class InterfacePrincipal {
private:
    vector <Tarefa> tarefas;
public:
    InterfacePrincipal();
    void menuPrincipal();
    int getInt(string mensagem, int min, int max);
    string getString(string mensagem);
    void cadastroTarefa();
    bool validarCadastro(Tarefa tarefa);
    void divisaoTarefas();
    void spam(string mensagem);
    void imprimirTarefas();
    vector <vector <int>> intervalPartitioning();
};

#endif
