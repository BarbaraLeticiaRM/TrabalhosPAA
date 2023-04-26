#include <bits/stdc++.h>
using namespace std;

struct No {
    int valor;
    unique_ptr<No> esquerda;
    unique_ptr<No> direita;
};

void exibirEmOrdem(No* raiz) {
    if (raiz != nullptr) {
        exibirEmOrdem(raiz->esquerda.get());
        cout << raiz->valor << " ";
        exibirEmOrdem(raiz->direita.get());
    }
}

unique_ptr<No> inserirNo(unique_ptr<No> raiz, int valor) {
    if (raiz == nullptr) {
        unique_ptr<No> novoNo(new No);
        novoNo->valor = valor;
        novoNo->esquerda = nullptr;
        novoNo->direita = nullptr;
        return novoNo;
    }
    if (valor < raiz->valor) {
        raiz->esquerda = inserirNo(move(raiz->esquerda), valor);
    } else {
        raiz->direita = inserirNo(move(raiz->direita), valor);
    }
    return raiz;
}

unique_ptr<No> busca(unique_ptr<No> raiz, int chave) {
    if (raiz == nullptr || raiz->valor == chave) {
        return move(raiz);
    }
    else if (raiz->valor < chave) {
        return busca(raiz->direita, chave);
    }
    else {
        return busca(raiz->esquerda, chave);
    }
}

int main() {
    unique_ptr<No> raiz = nullptr;

    raiz = inserirNo(move(raiz), 50);
    raiz = inserirNo(move(raiz), 30);
    raiz = inserirNo(move(raiz), 20);
    raiz = inserirNo(move(raiz), 40);
    raiz = inserirNo(move(raiz), 70);
    raiz = inserirNo(move(raiz), 60);
    raiz = inserirNo(move(raiz), 80);

    exibirEmOrdem(raiz.get());
    cout << endl;

    unique_ptr<No> no = busca(65, move(raiz)); 
    if (no == nullptr) {
        cout << "Elemento não encontrado" << endl;
    } else {
        cout << "Elemento encontrado." << endl;
    }
    return 0;
}

