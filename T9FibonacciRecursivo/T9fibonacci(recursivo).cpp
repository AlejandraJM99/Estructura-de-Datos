//fibonacci(recursivo)
#include<iostream>
#include<conio.h>

using namespace std;

int fibonacci(int n);

int main()
{
	int num, i;
	cout<<"Ingresa el numero de elementos: ";
	cin>>num;
	
	for(i=1; i<=num; i++)
	{
		cout<<" "<<fibonacci(i);
	}
	return 0;
	getch();	
}
int fibonacci(int n)
{
	if(n==0 or n==1)
	{
		return n;
	}
	else{
		return(fibonacci(n-1)+fibonacci(n-2));
	}
}
