#ifndef INTERFACEPRINCIPAL_HPP
#define INTERFACEPRINCIPAL_HPP

#include "tarefa.hpp"
#include "funcionario.hpp"

#include <vector>
#include <queue>

class InterfacePrincipal {
private:
    vector <Tarefa> tarefas;
    typedef struct comparar{
        bool operator()(Funcionario a, Funcionario b) {
            if(a.getHora() == b.getHora()){
                if(a.getMin() == b.getMin()){
                    return (a.totalTarefas() > b.totalTarefas());
                }
                else
                    return a.getMin() > b.getMin(); 
            } else
                return a.getHora() > b.getHora(); 
        }
    }comparar;
    vector <Funcionario> funcionarios;
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
    void intervalPartitioning();
    void deletarTarefas();
    Funcionario iniciaLista();
};

#endif
