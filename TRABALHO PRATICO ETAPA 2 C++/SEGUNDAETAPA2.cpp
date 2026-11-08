
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    const int MAX_CONTAS = 100;
    const int MAX_MOVIMENTACOES = 500;

    int numeroConta[MAX_CONTAS];
    string nomeCliente[MAX_CONTAS];
    string cpf[MAX_CONTAS];
    int tipoConta[MAX_CONTAS];
    double saldo[MAX_CONTAS];
    bool contaAtiva[MAX_CONTAS];

    int contaMovimentacao[MAX_MOVIMENTACOES];
    char tipoMovimentacao[MAX_MOVIMENTACOES];
    double valorMovimentacao[MAX_MOVIMENTACOES];

    int quantidadeContas = 0;
    int quantidadeMovimentacoes = 0;

    int opcao;
    int numero;
    int indice;
    int indiceOrigem;
    int indiceDestino;
    int destino;

    double valor;

    cout << fixed << setprecision(2);

    do {

        cout << "\n========== SISTEMA BANCARIO ==========\n";
        cout << "1 - Cadastrar conta\n";
        cout << "2 - Listar contas\n";
        cout << "3 - Consultar conta\n";
        cout << "4 - Depositar\n";
        cout << "5 - Sacar\n";
        cout << "6 - Transferir\n";
        cout << "7 - Exibir extrato\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {

            case 1:

                if (quantidadeContas >= MAX_CONTAS) {
                    cout << "Limite de contas atingido!\n";
                    break;
                }

                cout << "\nDigite o numero da conta: ";
                cin >> numero;

                indice = -1;

                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numero) {
                        indice = i;
                    }
                }

                if (indice != -1) {
                    cout << "Numero de conta ja cadastrado!\n";
                    break;
                }

                numeroConta[quantidadeContas] = numero;

                cin.ignore();

                cout << "Nome do cliente: ";
                getline(cin, nomeCliente[quantidadeContas]);

                cout << "CPF: ";
                getline(cin, cpf[quantidadeContas]);

                cout << "Tipo de conta (1 - Corrente / 2 - Poupanca): ";
                cin >> tipoConta[quantidadeContas];

                cout << "Saldo inicial: R$ ";
                cin >> saldo[quantidadeContas];

                if (saldo[quantidadeContas] < 0 ||
                    (tipoConta[quantidadeContas] != 1 &&
                     tipoConta[quantidadeContas] != 2)) {

                    cout << "Dados invalidos! Cadastro cancelado.\n";
                    break;
                }

                contaAtiva[quantidadeContas] = true;

                quantidadeContas++;

                cout << "Conta cadastrada com sucesso!\n";

                break;


            case 2:

                cout << "\n========== CONTAS CADASTRADAS ==========\n";

                if (quantidadeContas == 0) {
                    cout << "Nenhuma conta cadastrada.\n";
                }

                for (int i = 0; i < quantidadeContas; i++) {

                    cout << "\nNumero: " << numeroConta[i];
                    cout << "\nCliente: " << nomeCliente[i];
                    cout << "\nCPF: " << cpf[i];
                    cout << "\nSaldo: R$ " << saldo[i];

                    cout << "\nTipo: ";

                    if (tipoConta[i] == 1) {
                        cout << "Corrente";
                    } else {
                        cout << "Poupanca";
                    }

                    cout << "\nSituacao: ";

                    if (contaAtiva[i]) {
                        cout << "Ativa\n";
                    } else {
                        cout << "Inativa\n";
                    }
                }

                break;


            case 3:

                cout << "\nDigite o numero da conta: ";
                cin >> numero;

                indice = -1;

                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numero) {
                        indice = i;
                        break;
                    }
                }

                if (indice == -1) {
                    cout << "Conta nao encontrada!\n";
                } else {

                    cout << "\nNumero: " << numeroConta[indice];
                    cout << "\nCliente: " << nomeCliente[indice];
                    cout << "\nCPF: " << cpf[indice];
                    cout << "\nSaldo: R$ " << saldo[indice];

                    cout << "\nSituacao: ";

                    if (contaAtiva[indice]) {
                        cout << "Ativa\n";
                    } else {
                        cout << "Inativa\n";
                    }
                }

                break;


            case 4:

                if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
                    cout << "Limite de movimentacoes atingido!\n";
                    break;
                }

                cout << "\nDigite o numero da conta: ";
                cin >> numero;

                indice = -1;

                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numero) {
                        indice = i;
                        break;
                    }
                }

                if (indice == -1 || !contaAtiva[indice]) {
                    cout << "Conta nao encontrada ou inativa!\n";
                    break;
                }

                cout << "Valor do deposito: R$ ";
                cin >> valor;

                if (valor <= 0) {
                    cout << "Valor invalido!\n";
                    break;
                }

                saldo[indice] = saldo[indice] + valor;

                contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indice];
                tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                valorMovimentacao[quantidadeMovimentacoes] = valor;

                quantidadeMovimentacoes++;

                cout << "Deposito realizado com sucesso!\n";

                break;


            case 5:

                if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
                    cout << "Limite de movimentacoes atingido!\n";
                    break;
                }

                cout << "\nDigite o numero da conta: ";
                cin >> numero;

                indice = -1;

                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numero) {
                        indice = i;
                        break;
                    }
                }

                if (indice == -1 || !contaAtiva[indice]) {
                    cout << "Conta nao encontrada ou inativa!\n";
                    break;
                }

                cout << "Valor do saque: R$ ";
                cin >> valor;

                if (valor <= 0) {
                    cout << "Valor invalido!\n";
                }
                else if (valor > saldo[indice]) {
                    cout << "Saldo insuficiente!\n";
                }
                else {

                    saldo[indice] = saldo[indice] - valor;

                    contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indice];
                    tipoMovimentacao[quantidadeMovimentacoes] = 'S';
                    valorMovimentacao[quantidadeMovimentacoes] = valor;

                    quantidadeMovimentacoes++;

                    cout << "Saque realizado com sucesso!\n";
                }

                break;


            case 6:

                if (quantidadeMovimentacoes > MAX_MOVIMENTACOES - 2) {
                    cout << "Espaco insuficiente para registrar a transferencia!\n";
                    break;
                }

                cout << "\nConta de origem: ";
                cin >> numero;

                indiceOrigem = -1;

                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numero) {
                        indiceOrigem = i;
                        break;
                    }
                }

                cout << "Conta de destino: ";
                cin >> destino;

                indiceDestino = -1;

                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == destino) {
                        indiceDestino = i;
                        break;
                    }
                }

                if (indiceOrigem == -1 || indiceDestino == -1) {
                    cout << "Uma das contas nao foi encontrada!\n";
                    break;
                }

                if (!contaAtiva[indiceOrigem] || !contaAtiva[indiceDestino]) {
                    cout << "Uma das contas esta inativa!\n";
                    break;
                }

                if (indiceOrigem == indiceDestino) {
                    cout << "Nao e possivel transferir para a mesma conta!\n";
                    break;
                }

                cout << "Valor da transferencia: R$ ";
                cin >> valor;

                if (valor <= 0) {
                    cout << "Valor invalido!\n";
                }
                else if (valor > saldo[indiceOrigem]) {
                    cout << "Saldo insuficiente!\n";
                }
                else {

                    saldo[indiceOrigem] = saldo[indiceOrigem] - valor;
                    saldo[indiceDestino] = saldo[indiceDestino] + valor;

                    contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indiceOrigem];
                    tipoMovimentacao[quantidadeMovimentacoes] = 'S';
                    valorMovimentacao[quantidadeMovimentacoes] = valor;

                    quantidadeMovimentacoes++;

                    contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indiceDestino];
                    tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                    valorMovimentacao[quantidadeMovimentacoes] = valor;

                    quantidadeMovimentacoes++;

                    cout << "Transferencia realizada com sucesso!\n";
                }

                break;


            case 7:

                cout << "\nDigite o numero da conta: ";
                cin >> numero;

                indice = -1;

                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numero) {
                        indice = i;
                        break;
                    }
                }

                if (indice == -1) {
                    cout << "Conta nao encontrada!\n";
                    break;
                }

                cout << "\n========== EXTRATO BANCARIO ==========\n";
                cout << "Cliente: " << nomeCliente[indice] << endl;
                cout << "Conta: " << numeroConta[indice] << endl;

                bool encontrou;
                encontrou = false;

                for (int i = 0; i < quantidadeMovimentacoes; i++) {

                    if (contaMovimentacao[i] == numero) {

                        encontrou = true;

                        if (tipoMovimentacao[i] == 'D') {
                            cout << "Deposito/Entrada: R$ ";
                        }
                        else if (tipoMovimentacao[i] == 'S') {
                            cout << "Saque/Saida: R$ ";
                        }

                        cout << valorMovimentacao[i] << endl;
                    }
                }

                if (!encontrou) {
                    cout << "Nenhuma movimentacao encontrada.\n";
                }

                cout << "Saldo atual: R$ " << saldo[indice] << endl;

                break;


            case 0:

                cout << "\nEncerrando o sistema...\n";
                break;


            default:

                cout << "Opcao invalida!\n";

        }

    } while (opcao != 0);

    return 0;
}
