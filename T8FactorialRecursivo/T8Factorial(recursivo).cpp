#include<iostream>
#include<conio.h>
using namespace std;
int factorial(int);
int main()
{	
    int n;
    cout<<"Ingresa un numero: ";
    cin>>n;
	cout<<"Factorial: "<<factorial(n)<<endl;
	getch();
	
	return 0;
}
int factorial(int n)
{
	if(n==0)
	{
		n = 1;
	}
	else{
		n = n*factorial(n-1);
	}
	return n;
}


