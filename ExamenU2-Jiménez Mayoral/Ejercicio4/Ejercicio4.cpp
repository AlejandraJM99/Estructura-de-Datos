/*4.Hacer un programa que simule la fila de clientes de una tienda
de supermercado, considerando que solo hay una caja que está activa.
La fila solo puede tener como máximo 5 clientes.*/
#include<iostream>
#include<stdlib.h>
#define TAM 5
using namespace std;
class Fila
{
	int cola[TAM];
	int fin=0;
	int frente=0;
	public:
		void push(int cliente)
		{
			if(fin==TAM)
			{
				system("CLS");
				cout<<"Cliente "<<cliente<<", ya no hay lugar en la fila :("<<endl;
				return;
			}
			system("CLS");
			cola[fin++]=cliente;
			cout<<"El cliente numero "<<cliente<<" entro a la fila."<<endl;
		}
		void pop()
		{
		    if(frente==fin)
            {
                system("CLS");
                cout<<"Parece que no hay nadie en la fila!"<<endl;
                return;
            }
            system("CLS");
            cout<<"El cliente numero "<<cola[frente]<<" salio de la fila"<<endl;
            frente++;
		}
		void peek()
		{
		    if(frente==fin)
            {
                system("CLS");
                cout<<"Parece que no hay nadie en la fila!"<<endl;
                return;
            }
            system("CLS");
            cout<<"Los siguientes clientes estan en la fila "<<endl;
            for(int i=frente;i<fin;i++)
            {
                cout<<"Posicion: "<<i<<" Cliente: "<<cola[i]<<endl;
            }
		}
};
int main()
{
	int op;
	int op1;
	Fila co;
	cout<<"                                         Bienvenido al Supermercado"<<endl;
	do
	{
	cout<<"1.Pagar(entrar a la fila). \n2.Salir de la fila. \n3.Ver quienes estan en la fila. \n4.Irte a casa(salir del mercado)."<<endl;
	cout<<"\nQue vas a hacer? ";
	cin>>op;
	switch(op)
	{
		case 1:
			system("CLS");
			cout<<"Que numero de cliente entro a la fila? ";
			cin>>op1;
			co.push(op1);
		break;
		case 2:
		    system("CLS");
		    co.pop();
		break;
		case 3:
		    system("CLS");
		    co.peek();
        break;
        case 4:
        break;
	}
	}while(op!=4);
}


