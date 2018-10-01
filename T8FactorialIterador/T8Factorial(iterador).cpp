#include<iostream>

using namespace std;
int main()
{
	int num, fact=1;
	cout<<"Introduce un numero: ";
	cin>>num;
	
	for(int i=1;i<=num;i++)
	{
		fact = fact * i;
	}
	cout<<"Factorial: "<<fact<<endl;
	return 0;
}
