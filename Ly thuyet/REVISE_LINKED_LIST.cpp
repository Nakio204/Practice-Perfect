#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

typedef struct Node *node;

int n, x, pos;

node makeNode(int x) {
	node tmp = new Node();
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}

int Size(node head) {
	int cnt = 0;
	while(head != NULL){
		++cnt;
		head = head->next;
	}
	return cnt;
}

void insertFirst(node &head, int x) {
	node tmp = makeNode(x);
	if(head == NULL) head = tmp;
	else {
		tmp->next = head;
		head = tmp;
	}
}

void insertLast(node &head, int x) {
	node tmp = makeNode(x);
	if(head == NULL) head = tmp;
	else {
		node p = head;
		while(p->next != NULL) p = p->next;
		p->next = tmp;
	}
}

void insertMid(node &head, int x, int pos) {
	node tmp = makeNode(x);
	if(pos <= 0 || pos > Size(head)) cout << "Vi tri chen ko hop le!";
	else if(pos == 1) insertFirst(head, x);
	else if(pos == Size(head)) insertLast(head, x);
	else {
		node p = head;
		for(int i = 1; i < pos - 1; i++) {
			p = p->next;
		}
		tmp->next = p->next;
		p->next = tmp;
	}
}

void input(node &head, int &n, int &t) {
	do {
		cout << "Nhap N = ";
		cin >> n;
	} while(n < 5 || n > 100);
	
	for(int i = 0; i < n; i++) {
		cout << "Phan tu thu " << i + 1 << ": ";
		cin >> t;
		insertLast(head, t);
	}
}

void output(node head) {
	cout << "Danh sach:";
	while(head != NULL) {
		cout << " " << head->data;
		head = head->next;
	}
}
  
int main() {
	node head = NULL;
	
	input(head, n, x);
	output(head);
	
	cout << "\nNhap vi tri can chen: ";
	cin >> pos;
	cout << "Nhap gia tri can chen: ";
	cin >> x;
	insertMid(head, x, pos);
	output(head);
	
	return 0;
}