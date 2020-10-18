#include "interfacePrincipal.hpp"


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

string InterfacePrincipal::getString(string mensagem) {
    string entrada;
    while(true) {
        cout << mensagem;
        getline(cin, entrada);
        if(entrada.empty() || entrada[0] == ' ')
            cout << endl << "Entrada inválida" << endl; 
        else
            break; 
    }
    return entrada;
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
    cout << "Cadastrando uma tarefa" << endl;
    string descricao = getString("Descreva a tarefa: ");
    cout << endl << "Horário de início da tarefa" << endl; 
    int hI = getInt("Hora (0 - 24): ");
    int mI = getInt("Minuto (0 - 60): ");
    cout << endl << "Horário de conclusão da tarefa" << endl;
    int hF = getInt("Hora (0 - 24): ");
    int mF = getInt("Minuto (0 - 60): ");
    system("clear||cls");
    Tarefa tarefa(hI,mI,hF,mF,descricao); 
    if(validarCadastro(tarefa)){
        tarefas.push_back(tarefa);
        cout << "Cadastro realizado com sucesso!!" << endl;
    }
    else
        cout << "Não foi possível cadastrar a tarefa. Por favor, verifique os dados" << endl << endl;
    
}

bool InterfacePrincipal::validarCadastro(Tarefa tarefa){
    if(tarefa.getHoraInicial() > tarefa.getHoraFinal())
        return false; 
    else if(tarefa.getHoraInicial() == tarefa.getHoraFinal()){
        if(tarefa.getMinInicial() > tarefa.getMinFinal())
            return false;
    }
    return true;
}

void InterfacePrincipal::divisaoTarefas() {

}
