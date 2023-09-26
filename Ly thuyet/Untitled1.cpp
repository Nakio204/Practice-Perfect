#include <iostream>
#include <cmath>

using namespace std;

struct Node {
    int data;
    Node *pNext;
};

bool checkNguyento(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= int(sqrt(n)); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void createList(Node *&lk) {
    lk = NULL;
}

Node *createNode(int x) {
    Node *newNode = new Node;
    newNode->data = x;
    newNode->pNext = NULL;
    return newNode;
}

void insertLast(Node *&lk, int x) {
    Node *newNode = createNode(x);
    if (lk == NULL)
        lk = newNode;
    else {
        Node *current = lk;
        while (current->pNext != NULL) {
            current = current->pNext;
        }
        current->pNext = newNode;
    }
}

void soNguyenTo(Node *&lk, int n) {
    if (n >= 2) insertLast(lk, 2);
    for (int i = 3; i <= n; i++) {
        if (checkNguyento(i)) insertLast(lk, i);
    }
}

void outputList(Node *lk) {
    Node *runNode = lk;
    while (runNode != NULL) {
        cout << runNode->data << " ";
        runNode = runNode->pNext;
    }
}

int main() {
    int n;
    Node *lk;
    createList(lk);

    do {
        cout << "Cho N = ";
        cin >> n;
    } while (n < 10 || n >= 100);

    cout << "Danh sach lien ket: ";
    soNguyenTo(lk, n);
    outputList(lk);

    return 0;
}