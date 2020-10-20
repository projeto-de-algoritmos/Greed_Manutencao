#ifndef INTERFACEPRINCIPAL_HPP
#define INTERFACEPRINCIPAL_HPP

#include "tarefa.hpp"
#include "funcionario.hpp"

#include <vector>
#include <queue>

class InterfacePrincipal {
private:
    vector <Tarefa> tarefas;
    typedef struct comparar {
        bool operator()(Funcionario &a, Funcionario &b) {
            if(a.getHoraDisponivel() == b.getHoraDisponivel()) {
                if(a.getMinDisponivel() == b.getMinDisponivel())
                    return a.totalTarefas() > b.totalTarefas();
                else
                    return a.getMinDisponivel() > b.getMinDisponivel(); 
            } else
                return a.getHoraDisponivel() > b.getHoraDisponivel(); 
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
    void intervalPartitioning();
    Funcionario iniciaLista(Tarefa tarefa);
    void atualiza(priority_queue <Funcionario, vector <Funcionario>, comparar> &distribuicao, Tarefa tarefa);
    void insere(priority_queue <Funcionario, vector <Funcionario>, comparar> &distribuicao, Tarefa tarefa);
    void imprimirTarefas(priority_queue <Funcionario, vector <Funcionario>, comparar> &distribuicao); 
    void deletarTarefas();  
};

#endif
