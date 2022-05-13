#include <iostream>
using namespace std;

int a[100], x[100];
int n;
int w;
int tong;
int temp;

void Try(int t);

int main ()
{
	temp=0;
	tong=0;
	cout<<"Nhap so luong mon hang: ";
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cout<<"Nhap khoi luong mon hang thu ["<<i+1<<"]: ";
		cin>>x[i];
	}
	cout<<"Nhap khoi luong balo co the chua: ";
	cin>>w;
	Try(0);
	return 0;
}

void Try(int t)
{
	if(t>=n)
	{
		for(int i=0; i<n; i++)
			tong+=(a[i]*x[i]);
		if(tong > temp && tong<=w)
		{
			temp=tong;
			system("cls");
			temp=tong;
			cout<<"Cac mon hang duoc chon la: "<<endl;
			for(int i=0; i<n; i++)
			{
				if(a[i]==1)
				{
					cout<<"mon hang "<<i<<": "<<x[i]<<endl;
				}
			}
		}
		tong=0;
	}
	else
		for(int j=0; j<=1; j++)
		{
			a[t]=j;
			t++;
			Try(t);
			t--;
			a[t]=0;
		}
}