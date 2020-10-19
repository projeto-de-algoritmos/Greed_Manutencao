#ifndef INTERFACEPRINCIPAL_HPP
#define INTERFACEPRINCIPAL_HPP

#include "tarefa.hpp"

#include <vector>
#include <queue>

class InterfacePrincipal {
private:
    vector <Tarefa> tarefas;
    typedef struct comparar {
        bool operator()(vector <Tarefa> &a, vector <Tarefa> &b) {
            if(a.back().getHoraFinal() < b.back().getHoraFinal())
                return false;
            else if(a.back().getHoraFinal() == b.back().getHoraFinal())
                return a.back().getMinFinal() > b.back().getMinFinal();
            else
                return true;
        }
    }comparar;
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
    void intervalPartitioning(vector <Tarefa> &tarefas, priority_queue <vector <Tarefa>, vector <vector <Tarefa>>, comparar> &distribuicao);
};

#endif
