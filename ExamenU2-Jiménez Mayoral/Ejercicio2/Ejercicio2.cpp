/*2.Realizar un programa que entregue el resultado de la ecuación
2^n, utilizar recursividad.*/
#include<iostream>
using namespace std;
double potencia(double exp)
{
	int base=2;
	if(exp==0)
	{
		return 1;
	}else
	{
		return base*(potencia(exp-1));
	}
}
int main()
{
	int base=2;
	double exp;
	cout<<"                                       POTENCIAS DE DOS"<<endl;
	cout<<"\nIngresa el valor del exponente: ";
	cin>>exp;
	cout<<"\nEl numero 2 elevado a la potencia "<<exp<<" es igual a "<<potencia(exp)<<endl;
	return 0;
}
