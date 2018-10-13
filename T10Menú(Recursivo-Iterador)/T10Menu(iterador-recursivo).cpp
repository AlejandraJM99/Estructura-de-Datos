#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
int numnatu(int n) //1.Numeros Naturales
{
    if(n<101)
    {
        cout<<n<<endl;
        return numnatu(n+1);
    }
}
int factorial(int n) //2.Factorial
{
	if(n==0)
	{
		n=1;
	}
	else
	{
		n = n*factorial(n-1);
	}
	return n;
}
int fibonacci(int n) //3.Fibonacci
{
	if(n==0 or n==1)
	{
		return n;
	}
	else{
		return(fibonacci(n-1)+fibonacci(n-2));
	}
}
int main()
{
	int op, opx, op1, op2, n;
	int x=0, y=1,z=1;
	int num, fact=1;
	cout<<"1.Numeros naturales \n2.Factoriales \n3.Fibonacci \n4.Salir"<<endl;
	cout<<"Tu opcion es: ";
	cin>>op;
	do
	{
		switch(op)
		{
			case 1: //NumerosNaturales
			system("CLS");
			cout<<"1.100 numeros naturales \n2.Volver al menu principal \nTu opcion es: ";
			cin>>opx;
			switch(opx)
			{
			case 1:
			system("CLS");
			cout<<"Los numeros naturales son: "<<endl;	
			numnatu(1);
			cout<<"Presiona cualquier tecla para regresar"<<endl;
			getch();
			system("CLS");
			return main();
			break;
			case 2:
			system("CLS");	
			return main();	
			break;
			}	
			case 2: //factoriales
			system("CLS");
			cout<<"1.Factorial con iteradores \n2.Factorial recursivo \n3.Volver al menu principal \nTu opcion es: ";
			cin>>op1;	
				switch(op1)
				{
					case 1:
					system("CLS");
					cout<<"Introduce un numero: ";
					cin>>num;
					for(int i=1; i<=num;i++)
					{
					fact = fact*i;
					}
					cout<<"El factorial del numero es: "<<fact<<endl;
					cout<<"Presiona cualquier tecla para regresar"<<endl;
					getch();
					system("CLS");
					return main();
					break;
					case 2:
					system("CLS");
					cout<<"Ingresa un numero: ";
					cin>>n;		
					cout<<"El factorial es "<<factorial(n)<<endl;
					cout<<"Presiona cualquier tecla para regresar"<<endl;
					getch();
					system("CLS");
					return main();	
					break;
					case 3:
					system("CLS");	
					return main();
					break;	
				}
			case 3: //Fibonacci
			system("CLS");
			cout<<"1.Fibonacci con iteradores \n2.Fibonacci recursivo \n3.Volver al menu \nTu opcion es: ";
			cin>>op2;
				switch(op2)
				{
					case 1:
					system("CLS");
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
					cout<<num<<endl;
					cout<<"Presiona cualquier tecla para regresar"<<endl;
					getch();
					system("CLS");
					return main();
					break;
					case 2:
					system("CLS");	
					cout<<"Ingresa el numero de elementos: ";
					cin>>num;
					for(int i=1; i<=num; i++)
					{
					cout<<fibonacci(i)<<endl;
					}
					cout<<"Presiona cualquier tecla para regresar"<<endl;
					getch();
					system("CLS");
					return main();	
					break;
					case 3:
					system("CLS");	
					return main();	
					break;	
				}
		}
	}while(op!=4);
}

