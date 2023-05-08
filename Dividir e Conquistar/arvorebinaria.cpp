#include <bits/stdc++.h>
using namespace std;

struct No {
    int valor;
    unique_ptr<No> esquerda;
    unique_ptr<No> direita;
};

//Inserção em árvore binária:
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

//Tamanho de uma árvore binária:
int size(unique_ptr<No>& raiz) {3
    if (raiz == nullptr) {
        return 0;
    } else {
        return 1 + size(raiz->esquerda) + size(raiz->direita);
    }
}

//Caminhamento inOrder:
void inOrder(unique_ptr<No>& atual) {
    if (atual != nullptr) {
      inOrder(atual->esquerda);
      cout << atual->valor << " ";
      inOrder(atual->direita);
    }
}

//Caminhamento postOrder:
void posOrder(unique_ptr<No>& atual) {
    if (atual != NULL) {
      posOrder(atual->esquerda);
      posOrder(atual->direita);
      cout << atual->valor << " ";
    }
  }

//Caminhamento preOrder:
void preOrder(unique_ptr<No>& atual) {
    if (atual != NULL) {
      cout << atual->valor << " ";
      preOrder(atual->esquerda);
      preOrder(atual->direita);
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

    // calculando o tamanho da árvore binária
    int tree_size = size(raiz);
    cout << "Tamanho da árvore binária: " << tree_size << endl;

    //Caminhamento inOrder:
    cout << "Caminhamento inOrder: ";
    inOrder(raiz);
    cout << endl;

    //Caminhamento preOrder:
    cout << "Caminhamento preOrder: ";
    preOrder(raiz);
    cout << endl;

    //Caminhamento posOrder:
    cout << "Caminhamento posOrder: ";
    posOrder(raiz);
    cout << endl;

    return 0;
}

