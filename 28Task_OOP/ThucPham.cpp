//#include <iostream>
//using namespace std;
//
//class Thucpham{
//	private:
//		string ten;
//		long int gia;
//		long int thanhtien;
//	public:
//		Thucpham(){
//			this->ten= "";
//			this->gia = 0;
//			this->thanhtien = 0;
//		}
//		~Thucpham() {};
//		void setTen(string ten){
//			this->ten = ten;
//		}
//		string getTen(){
//			return this->ten;
//		}
//
//		void setGia(long int gia){
//			this->gia = gia;
//        }
//		long int getGia(){
//			return this->gia;
//		}
//
//		void setThanhtien(long int thanhtien){
//			this->thanhtien = thanhtien;
//		}
//		long int getThanhtien(){
//			return this->thanhtien;
//		}
//		friend Thucpham operator + (Thucpham a, Thucpham b){
//			Thucpham res;
//            res.setThanhtien(a.getThanhtien() + b.getThanhtien()); 
//			return res;
//		}
//		void nhapTP(){
//            getline(cin, this->ten); 
//            cin>> this->gia;
//		}
//};
//
//class TPKHOP: public Thucpham {
//	private:
//		int khoiluong;
//	public:
//		TPKHOP(){
//			this->khoiluong = 0;
//		}
//		~TPKHOP() {};
//		void setKhoiluong(int khoiluong){
//			this->khoiluong = khoiluong;
//		}
//		long int getKhoiluong(){
//			return this->khoiluong;
//		}
//		friend istream & operator >> (istream &in, TPKHOP &a) {
//			a.nhapTP();
//			in >> a.khoiluong;
//			a.setThanhtien(a.getKhoiluong() * a.getGia());
//			return in;
//		}
//		friend ostream & operator << (ostream &out, TPKHOP a) {
//			out << "-" << a.getTen() << "-" << a.getGia() << "-" << a.getKhoiluong() << endl;
//			return out;
//		}
//};
//
//class TPHOP: public Thucpham {
//	private:
//		int sohop;
//	public:
//		TPHOP(){
//			this->sohop = 0;
//		}
//		~TPHOP() {};
//		void setSohop(int sohop) {
//			this->sohop = sohop;
//		}
//		int getSohop(){
//			return this->sohop;
//		}
//		friend istream & operator >> (istream &in, TPHOP &a) {
//			a.nhapTP();
//			in >> a.sohop;
//			a.setThanhtien(a.getSohop() * a.getGia());
//			return in;
//		}
//		friend ostream & operator << (ostream &out, TPHOP a) {
//			out << "-" << a.getTen() << "-" << a.getGia() << "-" << a.getSohop() << endl;
//			return out;
//		}
//        
//};
//
//long int tinhtien(Thucpham ds[], int n) {
//	long int sum = 0;
//	for(int i = 0; i < n; i++) {
//		sum += ds[i].getThanhtien();
//	}
//	return sum;
//}
//
//int main(){
//	Thucpham ds[100];
//	TPHOP ds_hop[100];
//	TPKHOP ds_khop[100];
//	int type = 0, j = 0, k = 0;
//
//	int n;
//	cin >> n;
//	
//	for(int i = 0; i < n; i++){
//		cin >> type; 
//		cin.ignore();
//
//		if(type == 0){
//			cin >> ds_hop[j];
//			ds[i] = ds_hop[j];
//			j++;
//		}
//		else {
//			cin >> ds_khop[k];
//			ds[i] = ds_khop[k];
//			k++;
//		}
//	}
//	
//	for(int i = 0; i < j; i++) {
//		cout << "0" << ds_hop[i];
//	}
//	for(int i = 0; i < k; i++) {
//		cout << "1" << ds_khop[i];
//	}
//
//	long int res = tinhtien(ds, n);
//	cout << "====" << endl;
//	cout << res << endl;
//	
//	return 0;
//}

#include <iostream>
#include <iostream>
#include <string>
using namespace std;
class thucpham{
	private:
		string ten;
		float gia;
		
	public:
		thucpham(){
		}
		thucpham(string Ten, float Gia)
		{
			this->ten= Ten; this->gia= Gia; 
		}
		// set + get
		string getTen()
		{
			return this->ten;
		}
		virtual void nhap()
		{
			// tuong tac voi nguoi dung
			cout<< "ten san pham: "; getline(cin, this->ten);
			cout<< "Gia san pham: "; cin>> this->gia;
			
		}
		//virtual void xuat() const=0;
		
		virtual void xuat(){
			cout<< " San pham: "<< ten<<"; gia: "<< gia<<endl;
		}
		
};
class TPHOP: public thucpham{
	private:
		int soluong;
	public:
		TPHOP():thucpham(){
			soluong =0;
		}
		TPHOP(string Ten, float Gia, int Soluong):thucpham(Ten,Gia){
			soluong = Soluong;
		}
		void nhap(){
			thucpham::nhap();
			cout<< " so luong "; cin>>soluong;
		}
		void xuat() {
			thucpham::xuat();
			cout<< " so luong = "<< soluong<<endl;
		}
};
class TPKHOP: public thucpham{
	private:
		int khoiluong;
	public:
		TPKHOP():thucpham(){
			khoiluong =0;
		}
		TPKHOP(string Ten, float Gia, int Khoiluong):thucpham(Ten,Gia){
			khoiluong = Khoiluong;
		}
		void nhap(){
			thucpham::nhap();
			cout<< " Khoi luong "; cin>>khoiluong;
		}
		void xuat() 
		{
			thucpham::xuat();
			cout<< " Khoi luong = "<< khoiluong<<endl;
		}
};
void hienthi_danhsach(thucpham *pointer,int n)
{
	int i;
	for(i=0; i< n; i++)
		(pointer+i)->xuat();
}
void nhap_danhsach(thucpham *pointer,int n)
{
	int i;
	for(i=0; i< n; i++)
		(pointer+i)->nhap();
}
int main(int argc, char** argv) {
	TPHOP dstph[100];
	int n=2;
	int i;
	thucpham *pointer; // con tro thuoc lop cha
	pointer = dstph; // tro vao dia chi doi tuong thuoc lop con
	nhap_danhsach(pointer,n);
	pointer = dstph;
	hienthi_danhsach(pointer,n);
		
	return 0;
}
