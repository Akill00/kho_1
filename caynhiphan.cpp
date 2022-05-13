#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *pLeft; // node li�n ket b�n tr�i cua c�y <=> c�y con tr�i
	struct node *pRight; // node li�n ket b�n phai cua c�y <=> c�y con phai
};
typedef struct node NODE;
typedef NODE* TREE;

// khoi tao c�y
void KhoiTaoCay(TREE &t)
{
	t = NULL; // c�y rong
}

// h�m th�m phan tu x v�o c�y nhi ph�n
void ThemNodeVaoCay(TREE &t, int x)
{
	// neu c�y rong
	if (t == NULL)
	{
		NODE *p = new NODE; // khoi tao 1 c�i node de th�m v�o c�y
		p->data = x;// th�m du lieu x v�o data
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;// node p ch�nh l� node goc <=> x ch�nh l� node goc
	}
	else 
 	{
		// neu phan tu th�m v�o m� nho hon node goc ==> th�m n� v�o b�n tr�i
		if (t->data > x)
		{
			ThemNodeVaoCay(t->pLeft, x); // duyet qua tr�i de th�m phan tu x
		}
		else if (t->data < x) // neu phan tu th�m v�o m� lon hon node goc ==> th�m n� v�o b�n phai
		{
			ThemNodeVaoCay(t->pRight, x); // duyet qua phai de th�m phan tu x
		}
	}
}

// h�m xuat c�y nhi ph�n theo NLR
void Duyet_NLR(TREE t)
{ 
	// neu c�y c�n phan tu th� tiep tuc duyet
	if (t != NULL)
	{
		cout << t->data << " "; // xuat du lieu trong node
		Duyet_NLR(t->pLeft); // duyet qua tr�i
		Duyet_NLR(t->pRight); // duyet qua phai
	}
}



// h�m xuat c�y nhi ph�n theo LNR <=> xuat ra c�c phan tu tu b� den lon
void Duyet_LNR(TREE t)
{
	// neu c�y c�n phan tu th� tiep tuc duyet
	if (t != NULL)
	{
		Duyet_LNR(t->pLeft); // duyet qua tr�i
		cout << t->data << "  "; // xuat gi� tri cua node
		Duyet_LNR(t->pRight); // duyet qua phai
	}
}


// h�m xuat c�y nhi ph�n theo LRN
void Duyet_LRN(TREE t)
{
	/// neu c�y c�n phan tu th� tiep tuc duyet
	if (t != NULL)
	{
		Duyet_LRN(t->pLeft); // duyet qua tr�i
		Duyet_LRN(t->pRight); //  duyet qua phai
		cout << t->data << "  "; // xuat gi� tri cua node
	}
}


// h�m nhap du lieu
void Menu(TREE &t)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t =========== MENU ===========";
		cout << "\n1. Nhap du lieu";
		cout << "\n2. Duyet cay NLR";
		cout << "\n3. Duyet cay LNR";
		cout << "\n4. Duyet cay LRN";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t ============================";

		int luachon;

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon > 7)
		{
			cout << "\nLua chon khong hop le";
			system("pause");
		}
		else if (luachon == 1)
		{
			int x;
			cout << "\nNhap so nguyen x: ";
			cin >> x;
			ThemNodeVaoCay(t, x);
		}
		else if (luachon == 2)
		{
			cout << "\n\t\t DUYET CAY THEO NLR\n";
			Duyet_NLR(t);
			system("pause");
		}
	
		else if (luachon == 3)
		{
			cout << "\n\t\t DUYET CAY THEO LNR\n";
			Duyet_LNR(t);
			system("pause");
		}
		
		else if (luachon == 4)
		{
			cout << "\n\t\t DUYET CAY THEO LRN\n";
			Duyet_LRN(t);
			system("pause");
		}
		else
		{
			break;
		}
	}
	
}

int main()
{
	TREE t;
	KhoiTaoCay(t);
	Menu(t);

	system("pause");
	return 0;
}
