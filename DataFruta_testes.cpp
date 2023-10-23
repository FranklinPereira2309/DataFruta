#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Lista {
public:
    virtual void entradaDeDados() = 0;
    virtual void mostraMediana() = 0;
    virtual void mostraMenor() = 0;
    virtual void mostraMaior() = 0;
};

template <typename T>
class ListaGenerica : public Lista {
    vector<T> elementos;

public:
    void entradaDeDados() {
		system("clear");
        int numElementos;
        cout << "Quantos elementos vão existir na lista? ";
        cin >> numElementos;
        cin.ignore();

        for (int i = 0; i < numElementos; i++) {
            T elemento;
            cout << "Digite o elemento " << i + 1 << ": ";
    		cin >> elemento;
			cin.ignore();
            elementos.push_back(elemento);
        }
    }

    void mostraMediana() {
        if (elementos.empty()) {
            cout << "A lista está vazia." << endl;
            return;
        }

        
        sort(elementos.begin(), elementos.end());

        int tamanho = elementos.size();
        if (tamanho % 2 == 0) {
            T mediana1 = elementos[tamanho / 2 - 1];
            T mediana2 = elementos[tamanho / 2];
            cout << "Mediana: " << mediana1 << " e " << mediana2 << endl;
        } else {
            T mediana = elementos[tamanho / 2];
            cout << "Mediana: " << mediana << endl;
        }
    }

    void mostraMenor() {
        if (elementos.empty()) {
            cout << "A lista está vazia." << endl;
            return;
        }

        T menor = *min_element(elementos.begin(), elementos.end());
        cout << "Menor elemento: " << menor << endl;
    }

    void mostraMaior() {
        if (elementos.empty()) {
            cout << "A lista está vazia." << endl;
            return;
        }

        T maior = *max_element(elementos.begin(), elementos.end());
        cout << "Maior elemento: " << maior << endl;
    }
};

int main() {
    vector<Lista*> listaGeral;

    ListaGenerica<string> listaString;
	ListaGenerica<int> listaInteiros;
	
    listaString.entradaDeDados();
	listaInteiros.entradaDeDados();
    listaGeral.push_back(&listaString);
	listaGeral.push_back(&listaInteiros);
   
    for (Lista* l : listaGeral) {
        l->mostraMediana();
        l->mostraMenor();
        l->mostraMaior();
    }


    return 0;
}
