#include "interfacePrincipal.hpp"

#include <algorithm>

InterfacePrincipal::InterfacePrincipal() {
    system("clear||cls");
}

void InterfacePrincipal::menuPrincipal() {
    while(true) {
        cout << "(1) Cadastrar nova tarefa" << endl;
        cout << "(2) Deletar todas as tarefas" << endl;
        cout << "(3) Visualizar tarefas" << endl;
        cout << "(4) Calcular divisão das tarefas" << endl;
        cout << "(0) Finalizar" << endl;
        int opcao = getInt("", 0, 4);
        system("clear||cls");
        if(opcao == 1)
            cadastroTarefa();
        else if(opcao == 2)
            deletarTarefas();
        else if(opcao == 3)
            imprimirTarefas();
        else if(opcao == 4)
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

int InterfacePrincipal::getInt(string mensagem, int min, int max) {
    int valor;
    bool loop = true;
    while(loop) {
        cout << mensagem;
        loop = false;
        cin >> valor;
        if(cin.fail() || valor > max || valor < min) {
            cin.clear();
            cout << "Entrada inválida." << endl;
            loop = true;
        }
        cin.ignore(32767, '\n');
    }
    return valor;
}

void InterfacePrincipal::spam(string mensagem) {
    system("clear||cls");
    cout << mensagem << endl << endl;
}

void InterfacePrincipal::cadastroTarefa() {
    cout << "Cadastrando uma tarefa" << endl << endl;
    string descricao = getString("Descreva a tarefa: ");
    cout << endl << "Horário de início da tarefa" << endl;
    int hI = getInt("Hora (0 - 23): ", 0, 23);
    int mI = getInt("Minuto (0 - 59): ", 0, 59);
    cout << endl << "Horário de conclusão da tarefa" << endl;
    int hF = getInt("Hora (0 - 23): ", 0, 24);
    int mF = getInt("Minuto (0 - 59): ", 0, 59);
    Tarefa tarefa(hI,mI,hF,mF,descricao); 
    if(validarCadastro(tarefa)){
        tarefas.push_back(tarefa);
        spam("Tarefa cadastrada com sucesso!"); 
    }
    else
        spam("Não foi possível cadastrar a tarefa. Por favor, verifique os dados");
}

void InterfacePrincipal::deletarTarefas() {
    if(tarefas.empty()) {
        spam("Nenhuma tarefa está cadastrada");
        return;
    }
    string resposta = getString("Deletar todas as tarefas permanentemente? (S) Sim, (N) Não: ");
    if(resposta[0] == 'S' || resposta[0] == 's') {
        tarefas.clear();
        spam("Todas as tarefas foram deletadas");
    } else
        spam("Operação cancelada");
}

bool InterfacePrincipal::validarCadastro(Tarefa tarefa) {
    if(tarefa.getHoraInicial() > tarefa.getHoraFinal())
        return false; 
    else if(tarefa.getHoraInicial() == tarefa.getHoraFinal()){
        if(tarefa.getMinInicial() >= tarefa.getMinFinal())
            return false;
    }
    return true;
}

void InterfacePrincipal::imprimirTarefas() {
    if(tarefas.size() == 0)
        spam("Não há tarefas cadastradas");
    else {
        string volta; 
        for(Tarefa t:tarefas){
            t.imprimir(); 
            cout << "----------------------------------------" << endl;
        }
        cout << "(0) Voltar" << endl; 
        cin >> volta;
        system("clear||cls");
    }
}

void InterfacePrincipal::divisaoTarefas() {
    if(tarefas.empty()) {
        spam("É necessário cadastrar tarefas");
        return;
    }
    vector <Tarefa> tarefas;
    priority_queue <vector <Tarefa>, vector <vector <Tarefa>>, comparar> distribuicao;
    intervalPartitioning(tarefas, distribuicao);
    int qtdeDivisoes = distribuicao.size();
    for(int i = 0; i < qtdeDivisoes; i++) {
        cout << "___Divisão " << i << "___" << endl << endl;
        vector <Tarefa> secao = distribuicao.top();
        distribuicao.pop();
        int qtdeTarefas = secao.size();
        for(int j = 0; j < qtdeTarefas; j++) {
            secao[j].imprimir();
            cout << endl;
        }
        cout << "----------------------------------------" << endl << endl;
    }
    cout << "(0) Voltar" << endl; 
    string volta;
    cin >> volta;
    system("clear||cls");
}

bool ordenarInicioAntes(Tarefa a, Tarefa b) {
    if(a.getHoraInicial() == b.getHoraInicial())
        return a.getMinInicial() <= b.getMinInicial();
    else
        return a.getHoraInicial() < b.getHoraInicial();
}

void InterfacePrincipal::intervalPartitioning(vector <Tarefa> &tarefas, priority_queue <vector <Tarefa>, vector <vector <Tarefa>>, comparar> &distribuicao) {
    tarefas = this->tarefas;
    sort(tarefas.begin(), tarefas.end(), ordenarInicioAntes);
    int qtdeTarefas = tarefas.size();
    vector <Tarefa> secao;
    secao.push_back(tarefas[0]);
    distribuicao.push(secao);
    for(int i = 1; i < qtdeTarefas; i++) {
        Tarefa topo = distribuicao.top().back();
        if(topo.getHoraFinal() < tarefas[i].getHoraInicial() || (topo.getHoraFinal() == tarefas[i].getHoraInicial() && topo.getMinFinal() <= tarefas[i].getMinInicial())) {
            secao = distribuicao.top();
            distribuicao.pop();
            secao.push_back(tarefas[i]);
            distribuicao.push(secao);
        } else {
            secao = vector <Tarefa>();
            secao.push_back(tarefas[i]);
            distribuicao.push(secao);
        }
    }
}

void InterfacePrincipal::intervalPartitioning(){
    sort(tarefas.begin(), tarefas.end(), ordenarInicioAntes); 
    priority_queue <vector <Tarefa>, vector <Funcionario>, comparar> distribuicao;
    

}
