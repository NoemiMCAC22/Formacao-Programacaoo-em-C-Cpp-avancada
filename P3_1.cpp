#include <iostream>
#include <string>

using namespace std;

class Pessoa {
    
    public:
        string nome, telefone;
        int idade;

        Pessoa();
        Pessoa(string n);
        Pessoa(string n, int id, string tel);
    
        string getNome();
        string getTelefone();
        int getIdade();

        void setNome(string nome);
        void setTelefone(string telefone);
        void setIdade(int idade);
}; 

string Pessoa::getNome() {
    return nome;
}

string Pessoa::getTelefone() {
    return telefone;
}

int Pessoa::getIdade() {
    return idade;
}

void Pessoa::setNome(string nome) {
    this->nome = nome;
}

void Pessoa::setTelefone(string telefone) {
    this->telefone = telefone;
}

void Pessoa::setIdade(int idade) {
    this->idade = idade;
}

Pessoa::Pessoa() { }

Pessoa::Pessoa(string n): nome(" Noemi ") { }

int main(void) {

    Pessoa p1 = Pessoa(" Noemi ");
    Pessoa p2 = Pessoa();

    printf(" %s\n", p1.nome.c_str());
    p2.setNome(" Noemi ");
    p2.setTelefone("Móvel");
    p2.setIdade(36);
    cout << " Nome = " << p2.getNome() << endl;
    cout << " Telefone = " << p2.getTelefone() << endl;
    cout << " Idade = " << p2.getIdade() << endl;

}
