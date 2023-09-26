 #include <iostream>
using namespace std;

// Khai bao con tro Node
struct Node {
	int data;
	Node *next;
};

// Khai bao con tro kieu Node, muon tao bat ki con tro moi chi can "node (contromoi)" chu ko can "Node *(contromoi)"
typedef struct Node* node;

node makeNode(int x) {
	node tmp = new Node();
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}

void printDslk(node a) { 
	cout << "\n---------DSLK----------\n";
	while(a != NULL) {
		cout << a->data << " ";
		a = a->next;
	}
	cout << "\n-----------------------\n\n";
}

void insertFirst(node &a, int x) {
	node tmp = makeNode(x);
	if(a == NULL) a = tmp;
	else {
		tmp->next = a;
		a = tmp;
	}
}

int tinhTong(node &a) {
	int sum = 0;
	node p = a;
	while(p != NULL) {
		sum += p->data;
		p = p->next;
	}
	return sum;
}

int main() {
	node head = NULL;
	while(1) {
		int lc; cout << "Nhap lua chon: "; cin >> lc;
		if(lc == 0) break;
		else if(lc ==  1) {
			int x; cout << "Nhap phan tu: ";
			cin >> x;
			insertFirst(head, x);
		}
		else if(lc == 2) {
			printDslk(head);
		}
		else if(lc == 3) {
			cout << "Tong cac phan tu la: " << tinhTong(head) << endl;
		}
	}
	
	
	
	return 0;
}