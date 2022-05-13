#include <iostream>
#include<string>
#include<fstream>
#include <iomanip>
using namespace std;

struct ngay
{
	int ngay, thang, nam;
};
typedef struct ngay DATE;

struct	CongTrinh {
	string MaCT;
	string TenCT;
	DATE TGKC;
	DATE TGKT;
	int GiaTriUocTinh;
};
typedef struct CongTrinh CONGTRINH;


struct nodeCongTrinh
{
	CONGTRINH data;
	struct nodeCongTrinh *pNext;
};
typedef struct nodeCongTrinh NODECONGTRINH;

struct listCongTrinh
{
	NODECONGTRINH *pHead;
	NODECONGTRINH *pTail;
};
typedef struct listCongTrinh LISTCONGTRINH;

void KhoiTaoDanhSachCongTrinh(LISTCONGTRINH &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

NODECONGTRINH *KhoiTaoNodeCongTrinh(CONGTRINH x)
{
	NODECONGTRINH *p = new NODECONGTRINH;
	if (p == NULL)
	{
		cout << "\nCap phat that bai !";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

void ThemDau_CongTrinh(LISTCONGTRINH &l, NODECONGTRINH *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void ThemCuoi_CongTrinh(LISTCONGTRINH &l, NODECONGTRINH *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void XoaSauNode_q(LISTCONGTRINH &l, NODECONGTRINH *q)
{
	for (NODECONGTRINH *k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.MaCT == q->data.MaCT)
		{
			NODECONGTRINH *g = k->pNext; 
			k->pNext = g->pNext; 
			delete g; 		
		}
	}
}

//-------------------------HAM DOC FILE---------------------------
void DocNgayThangNam(ifstream &filein, DATE &date)
{
	filein >> date.ngay;
	filein.seekg(1, 1);
	filein >> date.thang;
	filein.seekg(1, 1);
	filein >> date.nam;
}

void DocThongTinMotCongTrinh(ifstream &filein, CONGTRINH &ct)
{
	getline(filein, ct.MaCT, ',');
	filein.seekg(1, 1);
	getline(filein, ct.TenCT, ',');
	filein.seekg(1, 1);
	DocNgayThangNam(filein, ct.TGKC);
	filein.seekg(2, 1);
	DocNgayThangNam(filein, ct.TGKT);
	filein.seekg(2, 1);
	filein >> ct.GiaTriUocTinh;

	//tao bien tam de doc ky tu /n
	string temp;
	getline(filein, temp);
}

void XuatCongTrinh(CONGTRINH ct)
{
	cout << "\nMa cong trinh: " << ct.MaCT;
	cout << "\nTen cong trinh: " << ct.TenCT;
	cout << "\nNgay khoi cong: " << ct.TGKC.ngay << "/" << ct.TGKC.thang << "/" << ct.TGKC.nam;
	cout << "\nNgay ket thuc: " << ct.TGKT.ngay << "/" << ct.TGKT.thang << "/" << ct.TGKT.nam;
	cout << "\nGia tri uoc tinh: " << ct.GiaTriUocTinh;
}

void DocThongTinDanhSachCongTrinh(ifstream &filein, LISTCONGTRINH &l)
{
	while (!filein.eof())
	{
		CONGTRINH ct;
		DocThongTinMotCongTrinh(filein, ct);
		NODECONGTRINH *p = KhoiTaoNodeCongTrinh(ct);
		ThemCuoi_CongTrinh(l, p);
	}
}

void XuatDanhSachCongTrinh(LISTCONGTRINH l)
{
	int dem = 1;
	for (NODECONGTRINH *k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << "\n\n\t\t Cong Trinh Thu " << dem++;
		XuatCongTrinh(k->data);
	}

}

//-------------------------HAM GHI FILE---------------------------
void GhiThongTinMotCongTrinh(ofstream &fileout, CONGTRINH &ct)
{
	fileout << ct.MaCT << ", ";
	fileout << ct.TenCT << ", ";
	fileout << ct.TGKC.ngay << "/" << ct.TGKC.thang << "/" << ct.TGKC.nam << ", ";
	fileout << ct.TGKT.ngay << "/" << ct.TGKT.thang << "/" << ct.TGKT.nam << ", ";
	fileout << ct.GiaTriUocTinh;
}

void LuuFileDanhSachCongTrinh(LISTCONGTRINH l)
{
	ofstream fileout;
	fileout.open("C:/Users/anhtu/OneDrive/Desktop/congtrinh.txt", ios::out);

	for (NODECONGTRINH *k = l.pHead; k != NULL; k = k->pNext)
	{
		GhiThongTinMotCongTrinh(fileout, k->data);
		fileout << endl;
	}
	fileout.close();
}


//==================================DSLK - Do gia dung ====================================
struct	DoGiaDung {
	string MaDGD;
	string TenDGD;
	float GiaTien;
	float KhoiLuong;
};
typedef struct DoGiaDung DOGIADUNG;


struct nodeDoGiaDung
{
	DOGIADUNG data;
	struct nodeDoGiaDung *pNext;
};
typedef struct nodeDoGiaDung NODEDOGIADUNG;

struct listDoGiaDung
{
	NODEDOGIADUNG *pHead;
	NODEDOGIADUNG *pTail;
};
typedef struct listDoGiaDung LISTDOGIADUNG;

void KhoiTaoDanhSachDoGiaDung(LISTDOGIADUNG &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

NODEDOGIADUNG *KhoiTaoNodeDoGiaDung(DOGIADUNG x)
{
	NODEDOGIADUNG *p = new NODEDOGIADUNG;
	if (p == NULL)
	{
		cout << "\nCap phat that bai !";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

void ThemDau_DoGiaDung(LISTDOGIADUNG &l, NODEDOGIADUNG *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void ThemCuoi_DoGiaDung(LISTDOGIADUNG &l, NODEDOGIADUNG *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void XoaSauNodeDoGiaDung_q(LISTDOGIADUNG &l, NODEDOGIADUNG *q)
{
	for (NODEDOGIADUNG *k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.MaDGD == q->data.MaDGD)
		{
			NODEDOGIADUNG *g = k->pNext;
			k->pNext = g->pNext;
			delete g;
		}
	}
}

//-------------------------HAM DOC FILE DO GIA DUNG---------------------------

void DocThongTinMotDoGiaDung(ifstream &filein, DOGIADUNG &ct)
{
	getline(filein, ct.MaDGD, ',');
	filein.seekg(1, 1);
	getline(filein, ct.TenDGD, ',');
	filein.seekg(2, 1);
	filein >> ct.GiaTien;
	filein.seekg(2, 1);
	filein >> ct.KhoiLuong;

	//tao bien tam de doc ky tu /n
	string temp;
	getline(filein, temp);
}

void XuatDoGiaDung(DOGIADUNG ct)
{
	cout << "\nMa do gia dung: " << ct.MaDGD;
	cout << "\nTen do gia dung: " << ct.TenDGD;
	cout << "\nGia tien: " << ct.GiaTien;
	cout << "\nKhoi luong: " << ct.KhoiLuong;
}

void DocThongTinDanhSachDoGiaDung(ifstream &filein, LISTDOGIADUNG &l)
{
	while (!filein.eof())
	{
		DOGIADUNG ct;
		DocThongTinMotDoGiaDung(filein, ct);
		NODEDOGIADUNG *p = KhoiTaoNodeDoGiaDung(ct);
		ThemCuoi_DoGiaDung(l, p);
	}
}

void XuatDanhSachDoGiaDung(LISTDOGIADUNG l)
{
	int dem = 1;
	for (NODEDOGIADUNG *k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << "\n\n\t\t Cong Trinh Thu " << dem++;
		XuatDoGiaDung(k->data);
	}

}

//-------------------------HAM GHI FILE DO GIA DUNG---------------------------
void GhiThongTinMotDoGiaDung(ofstream &fileout, DOGIADUNG &ct)
{
	fileout << ct.MaDGD << ", ";
	fileout << ct.TenDGD << ", ";
	fileout << ct.GiaTien << ", ";
	fileout << ct.KhoiLuong;
}

void LuuFileDanhSachDoGiaDung(LISTDOGIADUNG l)
{
	ofstream fileout;
	fileout.open("C:/Users/anhtu/OneDrive/Desktop/dogiadung.txt", ios::out);

	for (NODEDOGIADUNG *k = l.pHead; k != NULL; k = k->pNext)
	{
		GhiThongTinMotDoGiaDung(fileout, k->data);
		fileout << endl;
	}
	fileout.close();
}


//=========================== HANG DOI UU TIEN ======================================
int N;

int SoSanhNgay(CONGTRINH a, CONGTRINH b)
{
	// 1: a< b	0:a=b	-1:a>b
	if (a.TGKT.nam < b.TGKT.nam)
	{
		return 1;
	}
	else if (a.TGKT.nam > b.TGKT.nam)
	{
		return -1;
	}
	else
	{
		if (a.TGKT.thang < b.TGKT.thang)
		{
			return 1;
		}
		else if (a.TGKT.thang > b.TGKT.thang)
		{
			return -1;
		}
		else
		{
			if (a.TGKT.ngay < b.TGKT.ngay)
			{
				return 1;
			}
			else if (a.TGKT.ngay > b.TGKT.ngay)
			{
				return -1;
			}
			else
			{
				return 0;
			}
		}
	}
}

void insert_element(CONGTRINH A[], CONGTRINH val)
{
	N = N + 1;
	int i = N;
	A[i] = val;
	while (i > 1 and SoSanhNgay(A[i / 2], A[i]) == -1)
	{
		swap(A[i / 2], A[i]);
		i = i / 2;
	}
}

void max_heap(CONGTRINH A[], int i)
{
	int largest;
	int left = 2 * i;
	int right = 2 * i + 1;
	if (left <= N and SoSanhNgay(A[left], A[i]) == 1)
		largest = left;
	else
		largest = i;
	if (right <= N and SoSanhNgay(A[right], A[largest]) == 1)
		largest = right;
	if (largest != i)
	{
		swap(A[i], A[largest]);
		max_heap(A, largest);
	}
}


int max_element(int A[])
{
	return A[1];
}

CONGTRINH pop_max_element(CONGTRINH A[])
{
	if (N == 0)
	{
		cout << "\tKhong the xoa phan tu, vi hang doi rong\n";
	}
	CONGTRINH max = A[1];
	A[1] = A[N];
	N = N - 1;
	max_heap(A, 1);
	return max;
}

void print_element(CONGTRINH A[]) {
	if (N <= 0) return;
	cout << "\t";
	for (int i = 1; i <= N; i++) {
		cout << A[i].MaCT << " ";
	}
	cout << endl;
}


//=========================== stack ======================================
struct stack
{
	NODECONGTRINH *pTop;
};
typedef struct stack STACK;


void KhoiTaoStack(STACK &s)
{
	s.pTop = NULL;
}


NODECONGTRINH *KhoiTaoNode(CONGTRINH x)
{
	NODECONGTRINH *p = new NODECONGTRINH();
	p->data = x;
	p->pNext = NULL;
	return p;
}


bool IsEmpty(STACK s)
{

	if (s.pTop == NULL)
	{
		return true;
	}
	return false;
}


bool Push(STACK &s, NODECONGTRINH *p)
{
	if (p == NULL)
	{
		return false;
	}
	if (IsEmpty(s) == true)
	{
		s.pTop = p;
	}
	else
	{
		p->pNext = s.pTop;
		s.pTop = p;
	}
	return true;
}


bool Pop(STACK &s, CONGTRINH &x)
{
	if (IsEmpty(s) == true)
	{
		return false;
	}
	else
	{
		NODECONGTRINH *p = s.pTop;
		x = p->data;
		s.pTop = s.pTop->pNext;
	}
	return true;
}


bool Top(STACK &s, CONGTRINH &x)
{
	if (IsEmpty(s) == true)
	{
		return false;
	}
	x = s.pTop->data;
	return true;
}

void NhapDanhSach(STACK &S) {
	int n;
	CONGTRINH x;
	cout << "\nNhap so cong trinh can nhap: "; cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << "Nhap phan tu thu " << i << ": ";
		cout << "\nMa cong trinh: "; cin >> x.MaCT;
		cout << "\nTen cong trinh: "; cin >> x.TenCT;
		cout << "\nNgay khoi cong: "; cout << "Ngay: "; cin >> x.TGKC.ngay; cout << "Thang: "; cin >> x.TGKC.thang; cout << "Nam: "; cin >> x.TGKC.nam;
		cout << "\nNgay ket thuc: "; cout << "Ngay: "; cin >> x.TGKT.ngay; cout << "Thang: "; cin >> x.TGKT.thang; cout << "Nam: "; cin >> x.TGKT.nam;
		cout << "\nGia tri uoc tinh: "; cin >> x.GiaTriUocTinh;
		Push(S, KhoiTaoNode(x));
	}
}

void TravelStack(STACK L) {
	NODECONGTRINH *p = L.pTop;
	while (p != NULL) {
		cout << "\n\nMa cong trinh: " << p->data.MaCT;
	/*	cout << "\nTen cong trinh: " << p->data.TenCT;
		cout << "\nNgay khoi cong: " << p->data.TGKC.ngay << "/" << p->data.TGKC.thang << "/" << p->data.TGKC.nam;
		cout << "\nNgay ket thuc: " << p->data.TGKT.ngay << "/" << p->data.TGKT.thang << "/" << p->data.TGKT.nam;
		cout << "\nGia tri uoc tinh: " << p->data.GiaTriUocTinh;*/
		p = p->pNext;
	}
}

void XuatStack(STACK s)
{
	while (IsEmpty(s) == false)
	{
		CONGTRINH x;
		Pop(s, x);
		cout << "\n\nMa cong trinh: " << x.MaCT;
		cout << "\nTen cong trinh: " << x.TenCT;
		cout << "\nNgay khoi cong: " << x.TGKC.ngay << "/" << x.TGKC.thang << "/" << x.TGKC.nam;
		cout << "\nNgay ket thuc: " << x.TGKT.ngay << "/" << x.TGKT.thang << "/" << x.TGKT.nam;
		cout << "\nGia tri uoc tinh: " << x.GiaTriUocTinh;
	}
}

//=============================== XEP LICH ============================
bool SoSanh(CONGTRINH a, CONGTRINH b)
{
	if (a.GiaTriUocTinh > b.GiaTriUocTinh)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void sapxepcongviec(CONGTRINH a[], CONGTRINH b[], int n,int length)
{
	for (int i = 0; i <= length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (a[i].GiaTriUocTinh < a[j].GiaTriUocTinh)
			{
				CONGTRINH tam = a[i];
				a[i] = a[j];
				a[j] = tam;
			}
		}
	}

	int count;
	int i = 0;
	length = sizeof a / sizeof(char);
	count = n;
	while (count != 0 && i < length)
	{
		int vitri = a[i].TGKT.thang;
		CONGTRINH tam = a[i];
		while (vitri != 0)
		{
			if (b[vitri].TGKT.thang < a[i].TGKT.thang)
			{
				b[vitri] = tam;
				count--;
				break;
			}
			else
			{
				vitri--;
			}
		}
		i++;
	}
}

//==================================Balo===============================
void sapxep(DOGIADUNG sp[], int n)
{
	for (int i = 0; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if ((sp[i].GiaTien / sp[i].KhoiLuong) < (sp[j].GiaTien / sp[j].KhoiLuong))
				swap(sp[i], sp[j]);
}


void greedy(DOGIADUNG sp[], DOGIADUNG spDuocChon[], int n, float w)
{
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (sp[i].KhoiLuong < w)
		{
			w = w - sp[i].KhoiLuong;
			spDuocChon[j] = sp[i];
			j++;
		}
	}
}


int main()
{

	int luachon;
	while (true)
	{
		system("cls");
		cout << "======CHAO MUNG DEN VOI NHOM 4=========\n";
		cout << " ======Danh Sach Chuc Nang=========\n";
		cout << " 1.Them cong trinh. \n";
		cout << " 2.Liet ke cong trinh. \n";
		cout << " 3.Xoa cong trinh. \n";
		cout << " 4.Them vat tu. \n";
		cout << " 5.Liet ket vat tu. \n";
		cout << " 6.Xoa vat tu. \n";
		cout << " 7.Them do gia dung. \n";
		cout << " 8.Liet ke do gia dung. \n";
		cout << " 9.Xoa do gia dung. \n";
		cout << " 10.In danh sach cong trinh uu tien. \n";
		cout << " 11.In thu tu cong trinh can giao hang. \n";
		cout << " 12.In danh sach cong trinh se nhan. \n";
		cout << " 13.In danh sach do gia dung trong 1 can phong. \n";
		cout << " 14.In Bao Cao. \n";
		cout << " 0.Thoat chuong trinh\n";

		cout << "Nhap lua chon: "; cin >> luachon;
		//di ktra lua chon
		if (luachon != 0 && luachon != 1 && luachon != 2 && luachon != 3 && luachon != 4 && luachon != 5 && luachon != 6 && luachon != 7 && luachon != 8 && luachon != 9 && luachon != 10 && luachon != 11 && luachon != 12 && luachon != 13 && luachon != 14)
		{
			cout << "Lua chon khong hop le.Kiem tra lai!!!!";
			system("pause");
		}
		else if (luachon == 1)
		{
			CONGTRINH ct;
			ifstream filein;
			LISTCONGTRINH l;
			KhoiTaoDanhSachCongTrinh(l);

			filein.open("C:/Users/anhtu/OneDrive/Desktop/congtrinh.txt", ios::in);
			DocThongTinDanhSachCongTrinh(filein, l);

			cout << "\nNhap thong tin cong trinh";
			cout << "\nMa cong trinh: "; cin >> ct.MaCT;
			cout << "\nTen cong trinh: "; cin >> ct.TenCT;
			cout << "\nNgay khoi cong: "; cout << "Ngay: "; cin >> ct.TGKC.ngay; cout << "Thang: "; cin >> ct.TGKC.thang; cout << "Nam: "; cin >> ct.TGKC.nam;
			cout << "\nNgay ket thuc: "; cout << "Ngay: "; cin >> ct.TGKT.ngay; cout << "Thang: "; cin >> ct.TGKT.thang; cout << "Nam: "; cin >> ct.TGKT.nam;
			cout << "\nGia tri uoc tinh: "; cin >> ct.GiaTriUocTinh;
			NODECONGTRINH *p = KhoiTaoNodeCongTrinh(ct);
			ThemCuoi_CongTrinh(l, p);
			XuatDanhSachCongTrinh(l);
			LuuFileDanhSachCongTrinh(l);
			system("pause");
		}
		else if (luachon == 2)
		{
			CONGTRINH ct;
			ifstream filein;
			LISTCONGTRINH l;
			KhoiTaoDanhSachCongTrinh(l);
			filein.open("C:/Users/anhtu/OneDrive/Desktop/congtrinh.txt", ios::in);
			DocThongTinDanhSachCongTrinh(filein, l);
			XuatDanhSachCongTrinh(l);
			filein.close();
			system("pause");
		}
		else if (luachon == 3)
		{
			ifstream filein;
			LISTCONGTRINH l;
			KhoiTaoDanhSachCongTrinh(l);

			filein.open("C:/Users/anhtu/OneDrive/Desktop/congtrinh.txt", ios::in);
			DocThongTinDanhSachCongTrinh(filein, l);
			

			string MaCT;
			cout << "Nhap ma cong trinh can xoa : "; cin >> MaCT;

			for (NODECONGTRINH *k = l.pHead; k != NULL; k = k->pNext)
			{
				NODECONGTRINH *g = k->pNext;
				if (g->data.MaCT == MaCT)
				{
					XoaSauNode_q(l, k);
				}
			}
			XuatDanhSachCongTrinh(l);
			LuuFileDanhSachCongTrinh(l);
			system("pause");
		}
		else if (luachon == 4)
		{
			cout << "\n";
			system("pause");
		}
		else if (luachon == 5)
		{
			cout << "\n";
			system("pause");
		}
		else if (luachon == 6)
		{
			cout << "\n";
			system("pause");
		}
		else if (luachon == 7)
		{
			DOGIADUNG ct;
			ifstream filein;
			LISTDOGIADUNG l;
			KhoiTaoDanhSachDoGiaDung(l);

			filein.open("C:/Users/anhtu/OneDrive/Desktop/dogiadung.txt", ios::in);
			DocThongTinDanhSachDoGiaDung(filein, l);
			XuatDanhSachDoGiaDung(l);

			cout << "\nNhap thong tin do gia dung";
			cout << "\nMa do gia dung: "; cin >> ct.MaDGD;
			cout << "\nTen do gia dung: "; cin >> ct.TenDGD;
			cout << "\nGia tien: "; cin >> ct.GiaTien;
			cout << "\nKhoi luong: "; cin >> ct.KhoiLuong;

			NODEDOGIADUNG *p = KhoiTaoNodeDoGiaDung(ct);
			ThemCuoi_DoGiaDung(l, p);
			XuatDanhSachDoGiaDung(l);
			LuuFileDanhSachDoGiaDung(l);
			system("pause");
		}
		else if (luachon == 8)
		{
			DOGIADUNG ct;
			ifstream filein;
			LISTDOGIADUNG l;
			KhoiTaoDanhSachDoGiaDung(l);
			filein.open("C:/Users/anhtu/OneDrive/Desktop/dogiadung.txt", ios::in);
			DocThongTinDanhSachDoGiaDung(filein, l);
			XuatDanhSachDoGiaDung(l);
			filein.close();
			system("pause");
		}
		else if (luachon == 9)
		{
			ifstream filein;
			LISTDOGIADUNG l;
			KhoiTaoDanhSachDoGiaDung(l);
	
			filein.open("C:/Users/anhtu/OneDrive/Desktop/dogiadung.txt", ios::in);
			DocThongTinDanhSachDoGiaDung(filein, l);


			string MaDGD;
			cout << "Nhap ma do gia dung  can xoa : "; cin >> MaDGD;

			for (NODEDOGIADUNG *k = l.pHead; k != NULL; k = k->pNext)
			{
				NODEDOGIADUNG *g = k->pNext;
				if (g->data.MaDGD == MaDGD)
				{
					XoaSauNodeDoGiaDung_q(l, k);
				}
			}
			XuatDanhSachDoGiaDung(l);
			LuuFileDanhSachDoGiaDung(l);
			system("pause");
		}
		else if (luachon == 10)
		{
			CONGTRINH A[20];
			ifstream filein;
			filein.open("C:/Users/anhtu/OneDrive/Desktop/congtrinh.txt", ios::in);
			int i = 0;
			while (!filein.eof())
			{
				CONGTRINH ct;
				getline(filein, ct.MaCT, ',');
				filein.seekg(1, 1);
				getline(filein, ct.TenCT, ',');
				filein.seekg(1, 1);
				DocNgayThangNam(filein, ct.TGKC);
				filein.seekg(2, 1);
				DocNgayThangNam(filein, ct.TGKT);
				filein.seekg(2, 1);
				filein >> ct.GiaTriUocTinh;
				string temp;
				getline(filein, temp);	
				insert_element(A, ct);
			}
			for (int i = 0; i <= 18; i++)
			{
				pop_max_element(A); 
				print_element(A);
			}
			filein.close();
			system("pause");
		}
		else if (luachon == 11)
		{
			STACK S;
			KhoiTaoStack(S);
			CONGTRINH ct;
			int n;
			cout << "Nhap so don hang can giao: "; cin >> n;
			for (int i = 1; i <= n; i++)
			{
				cout << "\nNhap thong tin cong trinh"<<i;
				cout << "\nMa cong trinh: "; cin >> ct.MaCT;
				cout << "Ten cong trinh: "; cin >> ct.TenCT;
				cout << "Ngay khoi cong: "; cout << "\nNgay: "; cin >> ct.TGKC.ngay; cout << "Thang: "; cin >> ct.TGKC.thang; cout << "Nam: "; cin >> ct.TGKC.nam;
				cout << "Ngay ket thuc: "; cout << "\nNgay: "; cin >> ct.TGKT.ngay; cout << "Thang: "; cin >> ct.TGKT.thang; cout << "Nam: "; cin >> ct.TGKT.nam;
				cout << "Gia tri uoc tinh: "; cin >> ct.GiaTriUocTinh;
				Push(S, KhoiTaoNode(ct));
			}
			TravelStack(S);
			system("pause");
		}
		else if (luachon == 12)
		{
			int n;
			cout << " Nhap so luong cong trinh cong ty muon nhan: "; cin >> n;
			CONGTRINH a[20], b[20];
			ifstream filein;
			filein.open("C:/Users/anhtu/OneDrive/Desktop/congtrinhchuanhan.txt", ios::in);
			int i = 0;
			while (!filein.eof())
			{
				CONGTRINH ct;
				getline(filein, ct.MaCT, ',');
				filein.seekg(1, 1);
				getline(filein, ct.TenCT, ',');
				filein.seekg(1, 1);
				DocNgayThangNam(filein, ct.TGKC);
				filein.seekg(2, 1);
				DocNgayThangNam(filein, ct.TGKT);
				filein.seekg(2, 1);
				filein >> ct.GiaTriUocTinh;
				string temp;
				getline(filein, temp);
				a[i] = ct;
				i++;
			}

			int length = i;
			CONGTRINH x;
			x.MaCT = "0"; x.TenCT = "0"; x.TGKC.ngay = 0; x.TGKC.thang = 0; x.TGKC.nam = 0; x.TGKT.ngay = 0; x.TGKT.thang = 0; x.TGKT.nam = 0; x.GiaTriUocTinh = 0;
			
			for (int i = 0; i < n; i++) {
				b[i] = x;
			}

			sapxepcongviec(a, b,n,length);
			int TongGiaTri = 0;

			cout << setw(10) << left << "Ma CT";
			cout << setw(20) << left << "Ten Cong Trinh";
			cout << setw(20) << left << "Ngay khoi cong";
			cout << setw(20) << left << "Ngay ket thuc";
			cout << setw(20) << left << "Gia tri uoc tinh" << endl;
			cout << setfill('-');
			cout << setw(90) << "-" << endl;
			cout << setfill(' ');

			for (int i = 0; i < n; i++) {
				if (b[i].MaCT == "0")
				{
				}
				else
				{
					cout << setw(10) << left << a[i].MaCT;
					cout << setw(20) << left << a[i].TenCT;
					cout << setw(1) << left << a[i].TGKC.ngay << "/" << a[i].TGKC.thang << "/" << a[i].TGKC.nam;
					cout << setw(15) << right << a[i].TGKT.ngay << "/" << a[i].TGKT.thang << "/" << a[i].TGKT.nam;
					cout << setw(15) << right << a[i].GiaTriUocTinh << endl << endl;
					TongGiaTri += a[i].GiaTriUocTinh;
				}
			}

			cout << setfill('-');
			cout << setw(90) << "-" << endl;
			cout << setfill(' ');
			cout << "TONG GIA TRI: " << setw(65) << right << TongGiaTri << endl;


			filein.close();
			system("pause");
		}
		else if (luachon == 13)
		{
			int W;
			DOGIADUNG sp[15],spDuocChon[15];
			ifstream filein;
			filein.open("C:/Users/anhtu/OneDrive/Desktop/dogiadung.txt", ios::in);
			int i = 0;
			while (!filein.eof())
			{
				DOGIADUNG ct;
				getline(filein, ct.MaDGD, ',');
				filein.seekg(1, 1);
				getline(filein, ct.TenDGD, ',');
				filein.seekg(1, 1);
				filein >> ct.GiaTien;
				filein.seekg(2, 1);
				filein >> ct.KhoiLuong;
				string temp;
				getline(filein, temp);
				sp[i] = ct;
				i++;
			}

			DOGIADUNG x;
			x.MaDGD = "0"; x.TenDGD = "0"; x.KhoiLuong = 0; x.GiaTien = 0;
			int lengtha = sizeof sp / sizeof(DOGIADUNG);
			int lengthb  = sizeof spDuocChon / sizeof(DOGIADUNG);

			for (int i = 0; i < lengthb; i++) {
				spDuocChon[i] = x;
			}

			float KhoiLuongLayDuoc;
			KhoiLuongLayDuoc = 0;

			cout << "Nhap khoi luong toi da ma phong co the chua duoc : \n";
			cin >> W;
			sapxep(sp, lengtha);
			greedy(sp,spDuocChon, i, W);

			cout << setw(10) << left << "Ma DGD";
			cout << setw(20) << left << "Ten DGD";
			cout << setw(20) << left << "Gia tien";
			cout << setw(20) << left << "Khoi luong" << endl;
			cout << setfill('-');
			cout << setw(90) << "-" << endl;
			cout << setfill(' ');


			for (int i = 0; i < lengthb; i++) {
				if (spDuocChon[i].MaDGD == "0")
				{
				}
				else
				{
					cout << setw(10) << left << spDuocChon[i].MaDGD;
					cout << setw(20) << left << spDuocChon[i].TenDGD;
					cout << setw(1) << left << spDuocChon[i].GiaTien;
					cout << setw(20) << right << spDuocChon[i].KhoiLuong << endl<<endl;
					KhoiLuongLayDuoc += spDuocChon[i].KhoiLuong;
				}
			}

			cout << "Voi khoi luong " << W << " gia tri lay duoc toi da la: " << KhoiLuongLayDuoc << endl;
			system("pause");
		}
		else if (luachon == 14)
		{
			CongTrinh ct;
			CongTrinh a[100];
			int m = 0;
			cout << setw(10) << left << "Ma CT";
			cout << setw(20) << left << "Ten Cong Trinh";
			cout << setw(20) << left << "Ngay khoi cong";
			cout << setw(20) << left << "Ngay ket thuc";
			cout << setw(20) << left << "Gia tri uoc tinh" << endl;
			cout << setfill('-');
			cout << setw(90) << "-" << endl;
			cout << setfill(' ');

			ifstream filein;
			LISTCONGTRINH l;
			KhoiTaoDanhSachCongTrinh(l);
			filein.open("C:/Users/anhtu/OneDrive/Desktop/congtrinh.txt", ios::in);
			int i = 0;
			while (!filein.eof())
			{
				CONGTRINH ct;
				getline(filein, ct.MaCT, ',');
				filein.seekg(1, 1);
				getline(filein, ct.TenCT, ',');
				filein.seekg(1, 1);
				DocNgayThangNam(filein, ct.TGKC);
				filein.seekg(2, 1);
				DocNgayThangNam(filein, ct.TGKT);
				filein.seekg(2, 1);
				filein >> ct.GiaTriUocTinh;

				string temp;
				getline(filein, temp);
				a[i] = ct;
				i++;
			}
			CongTrinh k;
			for (int i = 0; i <= 19; i++)
			{
				for (int j = i + 1; j < 19; j++)
				{
					if (a[i].TGKC.nam > a[j].TGKC.nam) {
						k = a[i];
						a[i] = a[j];
						a[j] = k;
					}
					if (a[i].TGKC.nam == a[j].TGKC.nam) {
						if (a[i].TGKC.thang > a[j].TGKC.thang) {
							k = a[i];
							a[i] = a[j];
							a[j] = k;
						}
						if (a[i].TGKC.thang == a[j].TGKC.thang) {
							if (a[i].TGKC.ngay > a[j].TGKC.ngay) {
								k = a[i];
								a[i] = a[j];
								a[j] = k;
							}
						}
					}

				}
			}
			for (int i = 0; i <= 19; i++) {
				cout << setw(10) << left << a[i].MaCT;
				cout << setw(20) << left << a[i].TenCT;
				cout << setw(1) << left << a[i].TGKC.ngay << "/" << a[i].TGKC.thang << "/" << a[i].TGKC.nam;
				cout << setw(15) << right << a[i].TGKT.ngay << "/" << a[i].TGKT.thang << "/" << a[i].TGKT.nam;
				cout << setw(15) << right << a[i].GiaTriUocTinh << endl << endl;
			}

			filein.close();
			system("pause");
		}
		else 
		{
			break;
		}
	}

	cout << endl;
	system("pause");
	return 0;
}
