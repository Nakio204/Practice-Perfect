#include <iostream>
using namespace std;

struct sinhVien{
	string name;
	int id;
	double gpa;
};

struct SV{
	sinhVien s;
	SV *next;
};

typedef struct SV* sv;

sv makeNode() {
	sinhVien s;
	cin.ignore();
	cout << "Nhap ten sinh vien: "; getline(cin, s.name);
	cout << "Nhap ID: "; cin >> s.id;
	cout << "Nhap GPA: "; cin >> s.gpa;
	sv tmp = new SV();
	tmp->s = s;
	tmp->next = NULL;
	return tmp;
}

bool empty(sv a) {
	return a == NULL;
}

int Size(sv a) {
	int cnt = 0;
	while(a != NULL) {
		++cnt;
		a = a->next; // Cau lenh quan trong
	}
	return cnt;
}

void insertF(sv &a) {
	sv tmp = makeNode();
	if(a == NULL) a = tmp;
	else {
		tmp->next = a;
		a = tmp;
	}
}

void insertL(sv &a) {
	sv tmp = makeNode();
	if(a == NULL) a = tmp;
	else {
		sv p = a;
		while(p->next != NULL) {
			p = p->next;
		}
		p->next = tmp;
	}
}

void insertM(sv &a, int pos) {
	sv tmp = makeNode();
	if(pos <= 0 || pos > Size(a) + 1) cout << "Vi tri ko hop le!\n";
	if(pos == 1) {
		insertF(a); return;
	}
	else if(pos == Size(a) + 1) {
		insertL(a); return;
	}
	sv p = a;
	for(int i = 1; i < pos - 1; i++) p = p->next;
	tmp->next = p->next;
	p->next = tmp;
}

void in(sinhVien s) {
	cout << "Ho ten sinh vien: " << s.name << endl;
	cout << "ID: " << s.id << endl;
	cout << "GPA: " << s.gpa << endl;
}

void deleteFirst(sv &a) {
	if (a == NULL) return;
	a = a->next;
}

void deleteLast(sv &a) {
	if(a == NULL) return;
	sv truoc = NULL, sau = a;
	while(sau->next != NULL) {
		truoc = sau;
		sau = sau->next;
	}
	if(truoc == NULL) a = NULL;
	else truoc->next = NULL;
}

void deleteMiddle(sv &a, int pos) {
	if(pos <= 0 || pos > Size(a) + 1) cout << "Vi tri chen ko hop le!\n";
	sv truoc = NULL, sau = a;
	for(int i = 1; i < pos; i++) {
		truoc = sau;
		sau = sau->next;
	}
	if(truoc == NULL) a = a->next;
	else truoc->next = sau->next;
}

void printDssv(sv a) {
	cout << "\n---------DSSV----------\n";
	while(a != NULL) {
		in(a->s);
		a = a->next;
	}
	cout << "-----------------------\n\n";
}

int main() {
	sv head = NULL;
	while(1) {
		cout << "-----------MENU---------------\n";
		cout << "1. Chen 1 sinh vien vao dau DSSV.\n";
		cout << "2. Chen 1 sinh vien vao cuoi DSSV.\n";
		cout << "3. Chen 1 sinh vien vao vi tri bat ki trong DSSV.\n";
		cout << "4. In ra man hinh DSSV\n";
		cout << "5. Xoa sinh vien o dau DSLK.\n";
		cout << "6. Xoa sinh vien o cuoi DSLK.\n";
		cout << "7. Xoa sinh vien o vi tri bat ki trong DSLK.\n";
		cout << "0. Thoat khoi MENU\n";
		cout << "------------------------------\n";
		cout << "Nhap lua chon: ";
		int lc; cin >> lc;
		if(lc == 0) break;
		else if(lc == 1) {
			insertF(head);
		}
		else if(lc == 2) {
			insertL(head);
		}
		else if(lc == 3) {
			int pos;
			cout << "Nhap vi tri can chen: "; cin >> pos;
			insertM(head, pos);
		}
		else if(lc == 4) {
			printDssv(head);
		}
		else if(lc == 5) {
			deleteFirst(head);
		}
		else if(lc == 6) {
			deleteLast(head);
		}
		else if(lc == 7) {
			int pos;
			cout << "Nhap vi tri can xoa: "; cin >> pos;
			deleteMiddle(head, pos);
		}
	}
	
	return 0;
}