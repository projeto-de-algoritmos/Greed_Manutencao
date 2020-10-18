#include "interfacePrincipal.hpp"
#include "tarefa.hpp"

InterfacePrincipal::InterfacePrincipal() {
    system("clear||cls");
}

void InterfacePrincipal::menuPrincipal() {
    while(true) {
        cout << "(1) Cadastrar nova tarefa" << endl;
        cout << "(2) Calcular divisão das tarefas" << endl;
        cout << "(0) Finalizar" << endl;
        int opcao = getInt("");
        system("clear||cls");
        if(opcao == 1)
            cadastroTarefa();
        else if(opcao == 2)
            divisaoTarefas();
        else
            break;
    }
}

int InterfacePrincipal::getInt(string mensagem) {
    int valor;
    bool loop = true;
    while(loop) {
        cout << mensagem;
        loop = false;
        cin >> valor;
        if(cin.fail()) {
            cin.clear();
            cout << "Entrada inválida." << endl;
            loop = true;
        }
        cin.ignore(32767, '\n');
    }
    return valor;
}

void InterfacePrincipal::cadastroTarefa() {
    int hI, hF, mI, mN;
    string descricao; 

}

void InterfacePrincipal::divisaoTarefas() {

}
