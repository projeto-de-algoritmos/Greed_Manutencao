#ifndef INTERFACEPRINCIPAL_HPP
#define INTERFACEPRINCIPAL_HPP

#include <iostream>

using namespace std;

class InterfacePrincipal {
public:
    InterfacePrincipal();
    void menuPrincipal();
    int getInt(string mensagem);
    void cadastroTarefa();
    void divisaoTarefas();
};

#endif
