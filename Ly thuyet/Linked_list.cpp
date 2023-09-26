 #include <iostream>
using namespace std;

// Khai bao con tro Node
struct Node {
	int data;
	Node *next;
};

// Khai bao con tro kieu Node, muon tao bat ki con tro moi chi can "node (contromoi)" chu ko can "Node *(contromoi)"
typedef struct Node* node;

// Cap phat dong mot node moi voi du lieu la so nguyen x
node makeNode(int x) {
	node tmp = new Node();
	tmp->data = x;
	tmp->next = NULL; // nullptr
	return tmp;
}

// Kiem tra rong
bool empty (node a) {
	return a == NULL;
}

// Dem phan tu trong DSLK
int Size(node a) {
	int cnt = 0;
	while(a != NULL){
		++cnt;
		a = a->next; // gan dia chi nut tiep theo cho nut hien tai
	}
	return cnt;
}

// Them 1 phan tu vao dau DSLK
void insertFirst(node &a, int x) {
	node tmp = makeNode(x);
	if(a == NULL) a = tmp;
	else {
		tmp->next = a;
		a = tmp;
	}
}

// Them 1 phan tu vao cuoi DSLK
void insertLast(node &a, int x) {
	node tmp = makeNode(x);
	if(a == NULL) a = tmp;
	else {
		node p = a;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = tmp;
	}
}

// Them 1 phan tu vao giua
void insertMid(node &a, int x, int pos){
	node tmp = makeNode(x);
	int n = Size(a);
	if(pos <= 0 || pos > n + 1) cout << "Vi tri chen ko hop le!\n";
	if(pos == 1) {
		insertFirst(a, x); return;
	}
	else if(pos == n + 1) {
		insertLast(a, x); return;
	}
	node p = a;
	for(int i = 1; i < pos - 1; i++) {
		p = p->next;
	}
	tmp->next = p->next;
	p->next = tmp; 
}

// In ra man hinh DSLK
void printDslk(node a) { 
	cout << "\n---------DSLK----------\n";
	while(a != NULL) {
		cout << a->data << " ";
		a = a->next;
	}
	cout << "\n-----------------------\n\n";
}

// Xoa phan tu dau tien trong DSLK
void deleteFirst(node &a) {
	if(a == NULL) return;
	a = a->next;		
}

// Xoa phan tu cuoi cung trong DSLK
void deleteLast(node &a) {
	if(a == NULL) return;
	node truoc = NULL, sau = a;
	while(sau->next != NULL) {
		truoc = sau;
		sau = sau->next;
	}
	if(truoc == NULL) {
		a = NULL;
	}
	else {
		truoc->next = NULL;
	}
}

// Xoa phan tu o vi tri bat ki
void deleteMid(node &a, int pos) {
	if(pos <= 0 || pos > Size(a)) cout << "Vi tri xoa khong hop le.\n";
	node truoc = NULL, sau = a;
	for(int i = 1; i < pos; i++) {
		truoc = sau;
		sau = sau->next;
	}
	if(truoc == NULL) a = a->next;
	else truoc->next = sau->next;
}

// Sap xep cac phan tu trong DSLK
void sortList(node &a) {
	for(node p = a; p != NULL; p = p->next) {
		node min = p;
		for(node q = p->next; q != NULL; q = q->next) {
			if(min->data > q->data) min = q;
		}
		int tmp = min->data;
		min->data = p->data;
		p->data = tmp;
	}
}

int main() {
	node head = NULL;
	while(1) {
		cout << "-----------MENU---------------\n";
		cout << "1. Chen 1 phan tu vao dau DSLK.\n";
		cout << "2. Chen 1 phan tu vao cuoi DSLK.\n";
		cout << "3. Chen 1 phan tu vao vi tri bat ki.\n";
		cout << "4. In ra man hinh DSLK.\n";
		cout << "5. Xoa 1 phan tu o dau DSLK.\n";
		cout << "6. Xoa 1 phan tu o cuoi DSLK.\n";
		cout << "7. Xoa 1 phan tu vao vi tri bat ki.\n";
		cout << "8. Sap xep phan tu trong DSLK.\n";
		cout << "0. Thoat khoi MENU.\n";
		cout << "------------------------------\n";
		cout << "Nhap lua chon: ";
		int lc; cin >> lc;
		if(lc == 0) break;
		else if(lc == 1) {
			int x; 
			cout << "Nhap gia tri can chen: "; cin >> x;
			insertFirst(head, x);
		}
		else if(lc == 2) {
			int x; 
			cout << "Nhap gia tri can chen: "; cin >> x;
			insertLast(head, x);
		}
		else if(lc == 3) {
			int x, pos;
			cout << "Nhap gia tri can chen: "; cin >> x;
			cout << "Nhap vi tri can chen: "; cin >> pos;
			insertMid(head, x, pos);
		}
		else if(lc == 4) {
			printDslk(head);
		}
		else if(lc == 5) {
			cout << "Da xoa phan tu o dau\n";
			deleteFirst(head);
		}
		else if(lc == 6) {
			cout << "Da xoa phan tu o cuoi\n";
			deleteLast(head);
		}
		else if(lc ==  7) {
			int pos;
			cout << "Nhap vi tri can xoa: "; cin >> pos;
			deleteMid(head, pos);
		}
		else if(lc == 8) {
			sortList(head);
		}
	}
	return 0;
}