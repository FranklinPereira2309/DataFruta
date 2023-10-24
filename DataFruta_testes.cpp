#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Data {
    int dia, mes, ano;

public:
    int compararCom(const Data& outraData) const {
        if (ano < outraData.ano)
            return -1;
        else if (ano > outraData.ano)
            return 1;
        else {
            if (mes < outraData.mes)
                return -1;
            else if (mes > outraData.mes)
                return 1;
            else {
                if (dia < outraData.dia)
                    return -1;
                else if (dia > outraData.dia)
                    return 1;
                else
                    return 0;
            }
        }
    }

    static int compara(Data d1, Data d2) {
        return d1.compararCom(d2);
    }

    Data(int _dia, int _mes, int _ano) {
        dia = _dia;
        mes = _mes;
        ano = _ano;
    }

     int getDia() const {
        return dia;
    }

    int getMes() const {
        return mes;
    }

    int getAno() const {
        return ano;
    }

    string toString() {
        string ret = "";
        ret.append(to_string(dia));
        ret.append("/");
        ret.append(to_string(mes));
        ret.append("/");
        ret.append(to_string(ano));
        return ret;
    }
};

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
    void entradaDeDados() override {
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

    void mostraMediana() override {
        if (elementos.empty()) {
            cout << "A lista está vazia." << endl;
            return;
        }

        sort(elementos.begin(), elementos.end());

        int tamanho = elementos.size();
        if (tamanho % 2 != 0) {
            T mediana1 = elementos[tamanho / 2];
            cout << "Mediana: " << mediana1 << endl;
        } else {
            T mediana2 = elementos[tamanho / 2 - 1];
            cout << "Mediana: " << mediana2 << endl;
        }
    }

    void mostraMenor() override {
        if (elementos.empty()) {
            cout << "A lista está vazia." << endl;
            return;
        }

        T menor = *min_element(elementos.begin(), elementos.end());
        cout << "Menor elemento: " << menor << endl;
    }

    void mostraMaior() override {
        if (elementos.empty()) {
            cout << "A lista está vazia." << endl;
            return;
        }

        T maior = *max_element(elementos.begin(), elementos.end());
        cout << "Maior elemento: " << maior << endl;
    }
};

class gerarData : public Lista {
    vector<Data> dados;

public:
    void entradaDeDados() override {
        int dia, mes, ano;

        int numElementos;
        cout << "Quantos elementos vão existir na lista? ";
        cin >> numElementos;
        cin.ignore();

        for (int i = 0; i < numElementos; i++) {
            
            cout << "Digite a data " << i + 1 << " (dia mês ano): ";
            cin >> dia >> mes >> ano;

            Data data(dia, mes, ano);

            dados.push_back(data);
        }
        
    }

    void mostraMediana() override {
         if (dados.empty()) {
        cout << "A lista de datas está vazia." << endl;
        return;
    }

    
    sort(dados.begin(), dados.end(), Data::compara);

    int tamanho = dados.size();

    
    if (tamanho % 2 != 0) {
        Data mediana = dados[tamanho / 2];
        cout << "Mediana: " << mediana.toString() << endl;
    } else {
        
        Data mediana1 = dados[(tamanho - 1) / 2];
        Data mediana2 = dados[tamanho / 2];

        
        int dia = (mediana1.getDia() + mediana2.getDia()) / 2;
        int mes = (mediana1.getMes() + mediana2.getMes()) / 2;
        int ano = (mediana1.getAno() + mediana2.getAno()) / 2;

        Data mediana(dia, mes, ano);
        cout << "Mediana: " << mediana.toString() << endl;
    }
    }

    void mostraMenor() override {
        if (dados.empty()) {
            cout << "A lista de datas está vazia." << endl;
            return;
        }

    Data menor = dados[0]; 

    for (const Data& data : dados) {
        if (data.compararCom(menor) < 0) {
            menor = data; 
        }
    }

    cout << "Menor data: " << menor.toString() << endl;
    }

    void mostraMaior() override {
        if (dados.empty()) {
            cout << "A lista de datas está vazia." << endl;
            return;
        }

    Data maior = dados[0]; 

    for (const Data& data : dados) {
        if (data.compararCom(maior) > 0) {
            maior = data; 
        }
    }

    cout << "Maior data: " << maior.toString() << endl;
}
};

int main() {
    vector<Lista*> listaGeral;

    gerarData listaData;
    ListaGenerica<string> listaString;
    ListaGenerica<int> listaInteiros;

    listaData.entradaDeDados();
    listaString.entradaDeDados();
    listaInteiros.entradaDeDados();

    listaGeral.push_back(&listaData);
    listaGeral.push_back(&listaString);
    listaGeral.push_back(&listaInteiros);

    for (Lista* l : listaGeral) {
        l->mostraMediana();
        l->mostraMenor();
        l->mostraMaior();
    }

    return 0;
}
