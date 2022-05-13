#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *pLeft; // node liên ket bên trái cua cây <=> cây con trái
	struct node *pRight; // node liên ket bên phai cua cây <=> cây con phai
};
typedef struct node NODE;
typedef NODE* TREE;

// khoi tao cây
void KhoiTaoCay(TREE &t)
{
	t = NULL; // cây rong
}

// hàm thêm phan tu x vào cây nhi phân
void ThemNodeVaoCay(TREE &t, int x)
{
	// neu cây rong
	if (t == NULL)
	{
		NODE *p = new NODE; // khoi tao 1 cái node de thêm vào cây
		p->data = x;// thêm du lieu x vào data
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;// node p chính là node goc <=> x chính là node goc
	}
	else 
 	{
		// neu phan tu thêm vào mà nho hon node goc ==> thêm nó vào bên trái
		if (t->data > x)
		{
			ThemNodeVaoCay(t->pLeft, x); // duyet qua trái de thêm phan tu x
		}
		else if (t->data < x) // neu phan tu thêm vào mà lon hon node goc ==> thêm nó vào bên phai
		{
			ThemNodeVaoCay(t->pRight, x); // duyet qua phai de thêm phan tu x
		}
	}
}

// hàm xuat cây nhi phân theo NLR
void Duyet_NLR(TREE t)
{ 
	// neu cây còn phan tu thì tiep tuc duyet
	if (t != NULL)
	{
		cout << t->data << " "; // xuat du lieu trong node
		Duyet_NLR(t->pLeft); // duyet qua trái
		Duyet_NLR(t->pRight); // duyet qua phai
	}
}



// hàm xuat cây nhi phân theo LNR <=> xuat ra các phan tu tu bé den lon
void Duyet_LNR(TREE t)
{
	// neu cây còn phan tu thì tiep tuc duyet
	if (t != NULL)
	{
		Duyet_LNR(t->pLeft); // duyet qua trái
		cout << t->data << "  "; // xuat giá tri cua node
		Duyet_LNR(t->pRight); // duyet qua phai
	}
}


// hàm xuat cây nhi phân theo LRN
void Duyet_LRN(TREE t)
{
	/// neu cây còn phan tu thì tiep tuc duyet
	if (t != NULL)
	{
		Duyet_LRN(t->pLeft); // duyet qua trái
		Duyet_LRN(t->pRight); //  duyet qua phai
		cout << t->data << "  "; // xuat giá tri cua node
	}
}


// hàm nhap du lieu
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
