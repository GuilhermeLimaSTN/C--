#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Produto {
public:
    string nome;
    int quantidade;
    double preco;

    Produto(string nome, int quantidade, double preco)
        : nome(nome), quantidade(quantidade), preco(preco) {}

    void exibir() const {
        cout << "Nome: " << nome << ", Quantidade: " << quantidade 
             << ", Preço: R$" << preco << endl;
    }
};

class Funcionario {
public:
    string nome;
    string cargo;

    Funcionario(string nome, string cargo) : nome(nome), cargo(cargo) {}

    void exibir() const {
        cout << "Funcionário: " << nome << ", Cargo: " << cargo << endl;
    }
};

class Estoque {
public:
    vector<Produto> produtos;

    void adicionarProduto(const Produto& produto) {
        produtos.push_back(produto);
    }

    bool atualizarEstoque(const string& nome, int qtd, bool entrada) {
        for (auto& produto : produtos) {
            if (produto.nome == nome) {
                entrada ? produto.quantidade += qtd : produto.quantidade -= qtd;
                return true;
            }
        }
        return false;
    }

    void listarProdutos() const {
        if (produtos.empty())
            cout << "Estoque vazio!\n";
        else
            for (const auto& produto : produtos) produto.exibir();
    }
};

int main() {
    Estoque estoque;
    vector<Funcionario> funcionarios;
    int opcao;

    do {

        cout << "\n==== Sistema de Estoque ====" << endl;
        cout << "1. Adicionar Produto" << endl;
        cout << "2. Listar Produtos" << endl;
        cout << "3. Entrada Estoque" << endl;
        cout << "4. Saída Estoque" << endl;
        cout << "5. Adicionar Funcionário" << endl;
        cout << "6. Listar Funcionários" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha: ";
        cin >> opcao;
        

        switch (opcao) {
        case 1: {
            string nome;
            int quantidade;
            double preco;
            cout << "Nome: "; cin >> nome;
            cout << "Quantidade: "; cin >> quantidade;
            cout << "Preço: "; cin >> preco;
            estoque.adicionarProduto(Produto(nome, quantidade, preco));
            break;
        }
        case 2:
            estoque.listarProdutos();
            break;
        case 3: {
            string nome;
            int qtd;
            cout << "Nome do produto: "; cin >> nome;
            cout << "Quantidade: "; cin >> qtd;
            if (estoque.atualizarEstoque(nome, qtd, true))
                cout << "Estoque atualizado!\n";
            else
                cout << "Produto não encontrado!\n";
            break;
        }
        case 4: {
            string nome;
            int qtd;
            cout << "Nome do produto: "; cin >> nome;
            cout << "Quantidade: "; cin >> qtd;
            if (estoque.atualizarEstoque(nome, qtd, false))
                cout << "Estoque atualizado!\n";
            else
                cout << "Produto não encontrado!\n";
            break;
        }
        case 5: {
            string nome, cargo;
            cout << "Nome: "; cin >> nome;
            cout << "Cargo: "; cin >> cargo;
            funcionarios.emplace_back(nome, cargo);
            break;
        }
        case 6:
            if (funcionarios.empty())
                cout << "Nenhum funcionário cadastrado.\n";
            else
                for (const auto& func : funcionarios) func.exibir();
            break;
        case 0:
            cout << "Sistema encerrado.\n";
            break;
        default:
            cout << "Opção inválida!\n";
        }
    } while (opcao != 0);

    return 0;
}
