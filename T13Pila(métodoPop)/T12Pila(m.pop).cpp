#include <iostream>
#include<stdlib.h>
using namespace std;
class Pila
{
	int arraypi[5], index; //tamaño de la pila e índice
	public:
	    Pila() //constructor
		{
			index = -1;
		}
		void push (int x) //para ingresar datos
		{
			if(index>5)
			{
			    system("CLS");
				cout<<"Pila llena!! No puedes agregar mas elementos."<<endl;
				return;
			}
			arraypi[++index]=x;
			cout<<"Elemento "<<x<<" ingresado"<<endl;
			cout<<"\n"<<endl;
		}
		void pop()
		{
			if(index<0)
			{
			    system("CLS");
				cout<<"Pila vacia!! No puedes sacar elementos."<<endl;
				return;
			}
			cout<<"Elemento "<<arraypi[index--]<<" eliminado"<<endl;
		}
		
};
int main()
{
	int op, op2;
	Pila pil;
	do
	{
		cout<<"1.Push(ingresar un elemento) \n2.Pop(quitar un elemento) \n3.Salir \nTu opcion es:  ";
		cin>>op;
		switch(op)
		{
			case 1:
			    system("CLS");
				cout<<"Ingresa un elemento: ";
				cin>>op2;
				system("CLS");
				pil.push(op2);
			break;
			case 2:
			    system("CLS");
				pil.pop();
			break;
			case 3:
			break;
		}
			
	}while(op!=3);
	return 0;
}



