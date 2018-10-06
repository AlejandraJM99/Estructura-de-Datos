/* 1.Realizar un programa que entregue el resultado de sumar 
1+2+3+4+5+6+7+8+9 utilizando recursividad. */
#include<iostream>
#include<conio.h>
using namespace std;
int suma(int n)
{
	int sum=0;
	if(n==1)
	{
    sum = 1;
	}else
	{
		sum=n+suma(n-1);
	}
	return sum;
}
int main()
{
	int num = 9;
	cout<<"El total de la suma de 1+2+3+4+5+6+7+8+9 es: "<<suma(num)<<endl;
	getch();
	return 0;
}
