#include <iostream>
using namespace std;

class Hangxe {
	private:
		string mahx, tenhx, nuochx;
		int namhx;
	public:
		Hangxe() {
			this->mahx = this->tenhx = this->nuochx = "";
			this->namhx = 0;
		}
		Hangxe(string ma, string ten, string nuoc, int nam) {
			ma = this->mahx;
			ten = this->tenhx;
			nuoc = this->nuochx;
			nam = this->namhx;	
		}
		~Hangxe(){};
		string getMa1() {
			return this->mahx;
		}
		void setMa1(string ma) {
			ma = this->mahx;
		}
		string getTen1() {
			return this->tenhx;
		}
		void setTen1(string ten) {
			ten = this->tenhx;
		}
		string getNuoc1() {
			return this->nuochx;
		}
		void setNuoc1(string nuoc) {
			nuoc = this->nuochx;
		}
		int getNam1() {
			return this->namhx;
		}
		void setNam1(int nam) {
			nam  = this->namhx;
		}
		void NhapHx();
		void XuatHx();
		friend istream & operator >> (istream &, Hangxe &);
		friend ostream & operator << (ostream &, Hangxe);
};

void Hangxe::NhapHx() {
	getline(cin, this->mahx);
	getline(cin, this->tenhx);
	getline(cin, this->nuochx);
	cin >> this->namhx;
	cin.ignore();
}

void Hangxe::XuatHx() {
	cout << this->mahx << "-" << this->tenhx << "-" << this->nuochx << "-" << this->namhx << endl;
}

istream &operator >> (istream &in, Hangxe &a) { 
	getline(in, a.mahx);
	getline(in, a.tenhx);
	getline(in, a.nuochx);
	in >> a.namhx;
	cin.ignore();
	return in;
}

ostream &operator << (ostream &out, Hangxe a) {
	out << a.mahx << "-" << a.tenhx << "-" << a.nuochx << "-" << a.namhx << endl;
	return out;
}

class PTGT : public Hangxe {
	private:
		string mapt, tenpt, loaipt;
		long long giapt;
		int hxe;
		Hangxe hx;
	public:
		PTGT(){
			this->mapt = this->tenpt = this->loaipt = "";
		}
		PTGT(string ma, string ten, string loai, long long gia, int hx) {
			ma = this->mapt;
			ten = this->tenpt;
			loai = this->loaipt;
			gia = this->giapt;
		}
		~PTGT() {};
		string getMa2() {
			return this->mapt;
		}
		void setMa2(string ma) {
			ma = this->mapt;
		}
		string getTen2() {
			return this->tenpt;
		}
		void setTen2(string ten) {
			ten = this->tenpt;
		}
		string getLoai() {
			return this->loaipt;
		} 
		void setLoai(string loai) {
			loai = this->loaipt;
		}
		long long getGia() {
			return this->giapt;
		}
		void setGia(long long gia) {
			gia = this->giapt;
		}
		Hangxe getHangxe() {
			return this->hx;
		}
		void setHangxe(Hangxe hxe) {
			hxe = this->hx;
		}
		void NhapPt(Hangxe hx[]);
		virtual void HienThi();
		PTGT operator + (PTGT a) {
			PTGT res;
			res.giapt = this->giapt + a.giapt;
			return res;
		}
};

void PTGT::NhapPt(Hangxe hx[]) {
	getline(cin, this->mapt);
	getline(cin, this->tenpt);
	getline(cin, this->loaipt);
	cin >> this->giapt;
	cin >> this->hxe;
	this->hx = hx[hxe];
	cin.ignore();
}

void PTGT::HienThi() {
	cout << this->mapt << "-" << this->tenpt << "-" << this->loaipt << "-" << this->giapt << "-" << this->hxe << endl;
}

class Oto : public PTGT {
	private:
		string teno, namo, mauo, loaio;
	public:
		Oto() {
			this->teno = this->namo = this->mauo = this->loaio = "";
		}
		Oto(string ten, string nam, string mau, string loai) {
			ten = this->teno;
			nam = this->namo;
			mau = this->mauo;
			loai = this->loaio;
		}
		~Oto() {};
		string getTencar() {
			return this->teno;
		}
		void setTencar(string ten) {
			ten = this->teno;
		}
		string getNamcar() {
			return this->namo;
		}
		void setNamcar(string nam) {
			nam  = this->namo;
		}
		string getMaucar() {
			return this->mauo;
		}
		void setMaucar(string mau) {
			mau = this->mauo;
		}
		string getLoaicar() {
			return this->loaio;
		}
		void setLoaicar(string loai) {
			loai = this->loaio;
		}
		long long giaOto() {
			long long phi = (0.072 * this->getGia()) + 500000 + 340000 + 480000 + 2160000;
			return this->getGia() + phi;
		}
		friend istream & operator >> (istream &, Oto &);
		friend ostream & operator << (ostream &, Oto);
		void NhapOto();
		void HienThi();
};

void Oto::NhapOto() {
	getline(cin, this->teno);
	getline(cin, this->namo);
	getline(cin, this->mauo);
	getline(cin, this->loaio);
}

void Oto::HienThi() {
	cout << this->getMa2() << "-" << this->getTencar() << "-" << this->getNamcar() << "-" << this->getHangxe().getTen1() << "-" << this->getGia() << "-" << this->getMaucar() << endl;
}

istream & operator >> (istream &in, Oto &a) {
	getline(in, a.teno);
	getline(in, a.namo);
	getline(in, a.mauo);
	getline(in, a.loaio);
	return in;
}

ostream & operator << (ostream &out, Oto a) {
	out << a.getMa2() << "-" << a.getTencar() << "-" << a.getNamcar() << "-" << a.getHangxe() << "-" << a.getGia() << "-" << a.getMaucar() << endl;
	return out;
}

class Xemay : public PTGT {
	private:
		string tenbike, nambike, maubike, nlbike;
	public:
		Xemay() {
			this->tenbike = this->nambike = this->maubike = this->nlbike = "";
		}
		Xemay(string ten, string nam, string mau, string nl) {
			ten  = this->tenbike;
			nam = this->nambike;
			mau = this->maubike;
			nl = this->nlbike;
		}
		~Xemay() {};
		string getTenbike() {
			return this->tenbike;
		}
		string getNambike() {
			return this->nambike;
		}
		string getMaubike() {
			return this->maubike;
		}
		string getNl() {
			return this->nlbike;
		}
		void setTenbike(string ten) {
			ten = this->tenbike;
		}
		void setNambike(string nam) {
			nam = this->nambike;
		}
		void setMaubike(string mau) {
			mau = this->maubike;
		}
		void setNl(string nl) {
			nl = this->nlbike;
		}
		long long giaXemay() { 
			return this->getGia() + 500000;
		}
		void Nhapbike();
		void HienThi();
		friend istream & operator >> (istream &, Xemay &);
		friend ostream & operator << (ostream &, Xemay);
};

void Xemay::Nhapbike() {
	getline(cin, this->tenbike);
	getline(cin, this->nambike);
	getline(cin, this->maubike);
	getline(cin, this->nlbike);
}
void Xemay::HienThi() {
	cout << this->getMa2() << "-" << this->getTenbike() << "-" << this->getNambike() << "-" << this->getHangxe().getTen1() << "-" << this->getGia() << "-" << this->getMaubike() << endl;
}
istream & operator >> (istream &in, Xemay &a) {
	getline(in, a.tenbike);
	getline(in, a.nambike);
	getline(in, a.maubike);
	getline(in, a.nlbike);
	return in;
}
ostream & operator << (ostream &out, Xemay a) {
	out << a.getMa2() << "-" << a.getTenbike() << "-" << a.getNambike() << "-" << a.getHangxe() << "-" << a.getGia() << "-" << a.getMaubike() << endl;
	return out;
}

int main(){
    PTGT ds[100];
    Oto Car[100];
    Xemay Bike[100];
    int n, dshangxe, type = 0, j = 0, k = 0;
    long long res = 0;
    
    cin >> dshangxe;
    cin.ignore();
    Hangxe hangxe[dshangxe];
    for(int i = 0; i < dshangxe; i++) {
    	hangxe[i].NhapHx();
	}
	
	cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> type;
    	cin.ignore();
    	
        if(type == 0){
            Car[j].NhapPt(hangxe);
            Car[j].NhapOto();
            ds[i] = Car[j];
            j++;
        } else{
            Bike[k].NhapPt(hangxe);
            Bike[k].Nhapbike();
            ds[i] = Bike[k];
            k++;
        }
    }
    for(int i = 0; i < j; i++) {
		Car[i].HienThi();
		res += Car[i].giaOto();
    	for(int m = i; m < k; m++) {
    		Bike[m].HienThi();
    		res += Bike[m].giaXemay();
		} 
	}
	cout << "====\n";
	cout << res;
    
    return 0;
}