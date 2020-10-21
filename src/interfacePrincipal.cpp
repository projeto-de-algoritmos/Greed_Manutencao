#include "interfacePrincipal.hpp"

#include <algorithm>

InterfacePrincipal::InterfacePrincipal() {
    intervaloHora = 0;
    intervaloMin = 0;
    system("clear||cls");
}

void InterfacePrincipal::menuPrincipal() {
    while(true) {
        cout << "(1) Cadastrar nova tarefa" << endl;
        cout << "(2) Deletar todas as tarefas" << endl;
        cout << "(3) Visualizar tarefas" << endl;
        cout << "(4) Definir intervalo mínimo (Atual: " << formatarIntervalo() << ")" << endl;
        cout << "(5) Calcular divisão das tarefas" << endl;
        cout << "(0) Finalizar" << endl;
        int opcao = getInt("", 0, 5);
        system("clear||cls");
        if(opcao == 1)
            cadastroTarefa();
        else if(opcao == 2)
            deletarTarefas();
        else if(opcao == 3)
            imprimirTarefas();
        else if(opcao == 4)
            definirIntervalo();
        else if(opcao == 5)
            divisaoTarefas();
        else
            break;
    }
}

string InterfacePrincipal::formatarIntervalo() {
    string intervalo = "";
    if(intervaloHora < 10)
        intervalo += "0"; 
    intervalo += to_string(intervaloHora) + ":"; 
    if(intervaloMin < 10)
        intervalo += "0"; 
    intervalo += to_string(intervaloMin);
    return intervalo;
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

void InterfacePrincipal::definirIntervalo() {
    cout << "Intervalo mínimo entre duas tarefas" << endl;
    intervaloHora = getInt("Hora (0 - 23): ", 0, 23);
    intervaloMin = getInt("Minuto (0 - 59): ", 0, 59);
    spam("O intervalo mínimo foi definido para " + formatarIntervalo());
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
    int hF = getInt("Hora (0 - 23): ", 0, 23);
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

void InterfacePrincipal::divisaoTarefas(){
    if(tarefas.empty()) {
        spam("É necessário cadastrar tarefas");
        return;
    }
    intervalPartitioning();
}

bool ordenarInicioAntes(Tarefa a, Tarefa b) {
    if(a.getHoraInicial() == b.getHoraInicial())
        return a.getMinInicial() <= b.getMinInicial();
    else
        return a.getHoraInicial() < b.getHoraInicial();
}

void InterfacePrincipal::intervalPartitioning() {
    vector <Tarefa> tarefas = this->tarefas;
    sort(tarefas.begin(), tarefas.end(), ordenarInicioAntes);
    priority_queue <Funcionario, vector <Funcionario>, comparar> distribuicao;
    distribuicao.push(iniciaLista(tarefas[0]));
    int qntdTarefas = tarefas.size();
    for(int i = 1; i < qntdTarefas; i++) {
        Funcionario topo = distribuicao.top();
        if(Disponivel(topo, tarefas[i]))
            atualiza(distribuicao, tarefas[i]);
        else
            insere(distribuicao, tarefas[i]);
    }
    imprimirTarefas(distribuicao);
}

bool InterfacePrincipal::Disponivel(Funcionario topo, Tarefa tarefa){
    int horaRealDisponivel, minRealDisponivel;
    horaRealDisponivel = topo.getHoraDisponivel() + intervaloHora; 
    minRealDisponivel = topo.getMinDisponivel() + intervaloMin; 
    if(minRealDisponivel > 59){
        horaRealDisponivel++; 
        minRealDisponivel = minRealDisponivel%60;
    } 
    if(horaRealDisponivel > 23) 
        return false; 
    else if(tarefa.getHoraInicial() > horaRealDisponivel || (tarefa.getHoraInicial() == horaRealDisponivel && tarefa.getMinInicial() >= minRealDisponivel))
        return true;
    return false;
}

Funcionario InterfacePrincipal::iniciaLista(Tarefa tarefa){
    Funcionario funcionario;
    funcionario.adicionarTarefa(tarefa);
    return funcionario; 
}

void InterfacePrincipal::atualiza( priority_queue <Funcionario, vector <Funcionario>, comparar> &distribuicao, Tarefa tarefa){
    Funcionario topo = distribuicao.top();
    distribuicao.pop();
    topo.adicionarTarefa(tarefa);
    distribuicao.push(topo);
}
void InterfacePrincipal::insere( priority_queue <Funcionario, vector <Funcionario>, comparar> &distribuicao, Tarefa tarefa){
    Funcionario aux;
    aux.adicionarTarefa(tarefa);
    distribuicao.push(aux);
}

void InterfacePrincipal::imprimirTarefas(priority_queue <Funcionario, vector <Funcionario>, comparar> &distribuicao) {
    int qtdeParticoes = distribuicao.size();
    for(int i = 0; i < qtdeParticoes; i++) {
        cout << "__Funcionário " << i + 1 << "__"<< endl << endl;
        Funcionario funcionario = distribuicao.top();
        distribuicao.pop();
        funcionario.imprimeTarefas();
        cout << "----------------------------------------" << endl << endl;
    }
    cout << "(0) Voltar" << endl; 
    string volta;
    cin >> volta;
    system("clear||cls");
}
