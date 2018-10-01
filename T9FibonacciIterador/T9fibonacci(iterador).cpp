//fibonacci(iterador)
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	int num,x=0, y=1,z=1;
	cout<<"Introduce n-esimo termino de la funcion: ";
	cin>>num;
	cout<<"1 ";
	for(int i=1;i<num;i++)
	{
		z = x+y;
		cout<<z<<" ";
		x = y;
		y = z;
	}
	getch();
	return 0;
}
