#include <iostream>
using namespace std;

struct Node{
    double data;
    Node *next;
};

int n;
double t, x;

typedef struct Node *node;

node makeNode(double t) {
    node tmp = new Node();
    tmp->data = t;
    tmp->next = NULL;
    return tmp;
}

void insertFirst(node &head, double t) {
    node tmp = makeNode(t);
    if(head == NULL) head = tmp;
    else {
        tmp->next = head;
        head = tmp;
    }
}

void insertLast(node &head, double t) {
    node tmp = makeNode(t);
    if(head == NULL) head = tmp;
    else {
        node p = head;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = tmp;
    }
}

void inputList(node &head, int &n, double &t) {
    do{
        cout << "Nhap n = ";
        cin >> n;
    }while(n <= 0 || n >= 50);

    for(int i = 0; i < n; i++) {
        cout << "So thu " << i + 1 << ": ";
        cin >> t;
        insertLast(head, t);
    }
}

void outputList(node head) {
    cout << "Day so:";
    while(head != NULL) {
        cout << " " << head->data;
        head = head->next;
    }
}

void inputNumber(node &head, double &x) {
    cout << "Cho x = ";
    cin >> x;
    if(head == NULL) insertLast(head, x);
    else {
        insertFirst(head, x);
    }
}

int main() {
    node head = NULL;

    inputList(head, n, t);

    inputNumber(head, x);
    outputList(head);

    return 0;
}