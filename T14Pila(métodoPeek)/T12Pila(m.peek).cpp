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
		void peek() //ultima opcion del usuario
		{
			if(index<0)
			{
			    system("CLS");
				cout<<"Pila vacia"<<endl;
				return;
			}
			cout<<"El ultimo elemento ingresado es: "<<arraypi[index]<<endl;
		}
		void userpeek() //eleccion del usuario
		{
			int op;
			system("CLS");
			cout<<"Escoge la posicion del elemento que deseas ver"<<endl;
			cout<<"[0]-[1]-[2]-[3]-[4]-[5]"<<endl;
			cout<<"Tu opcion es: ";
			cin>>op;
			if(index < op)
			{
			    system("CLS");
				cout<<"Posicion vacia de la pila"<<endl;
				return;
			}
			if(op > 5)
			{
			    system("CLS");
				cout<<"Seleccion fuera de rango"<<endl;
				return;
			}
			cout<<arraypi[op];
			return;
		}
		void Allpeek()
		{
			if(index<0)
			{
			    system("CLS");
				cout<<"Pila vacía"<<endl;
				return;
			}
			for(int i=index;i>=0;i--)
			{
				cout<<arraypi[i]<<" ";
			}
		}
};
int main()
{
	int op, op2, op3;
	Pila pil;
	do
	{
		cout<<"1.Push(ingresar un elemento) \n2.Peek(mostrar los elementos) \n3.Salir \nTu opcion es:  ";
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
				cout<<"1.Peek(ultimo elemento) \n2.userPeek(escoge un elemento) \n3.Allpeek(todos los elementos) \nTu opcion es: ";
				cin>>op3;
				switch(op3)
				{
					case 1:
                    system("CLS");
					pil.peek();
	                cout<<"\n"<<endl;
					break;
					case 2:
                    system("CLS");
					pil.userpeek();
                    cout<<"\n"<<endl;
					break;
					case 3:
					system("CLS");
					cout<<"Los elementos de la pila son: ";
					pil.Allpeek();
					cout<<"\n"<<endl;
					break;
				}
			break;
			case 3:
			break;
		}
	}while(op!=3);
	return 0;
}


