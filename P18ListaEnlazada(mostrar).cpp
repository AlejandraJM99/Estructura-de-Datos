#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
class Lista
{
	private:
		struct nodo //estructura nodo.
		{
			int dato; //dato por el usuario.
			nodo *next; //puntero para anotar al siguiente nodo.
		};

		//typedef struct nodo *nodoptr; //se crea un puntero que contiene los mismos datos de la estructura y se puede utilizar para crear punteros del mismo tipo más fácil y rápido.
		nodo*raiz=NULL; //raíz de la lista.
		nodo*temp=NULL; //nodo temporal.
		nodo*act=NULL; //nodo actual.

	public: 	//en la sección pública se declaran las funciones.
	 //constructor
	/*void agregar(int item); //agrega datos
	void eliminar(int delitem); //elimina datos
	void mostrar(); //imprime datos*/

	void agregar(int item) //1ra. función para agregar los elementos
	{
		nodo *n = new nodo;
		n->next = NULL;
		n->dato = item;

		if(raiz!=NULL)
		{
			act = raiz;
			while(act->next != NULL)
			{
				act = act->next;
			}
			act->next = n;
		}else
		{
			raiz = n;
		}
		return;
	}
	void mostrar() //imprimir los elementos
	{
		act = raiz;
		while(act != NULL)
		{
			cout<<act->dato<<endl;
			act = act->next;
		}
	}
};
int main()
{
	int dato,op;
	Lista list1;
	do{
	cout<<"1.Insertar dato \n2.Mostrar \n3.Salir"<<endl;
	cout<<"Tu opcion es: ";
	cin>>op;

		switch(op)
		{
			case 1:
			system("cls");
			cout<<"Ingresa un elemento a la lista: ";
			cin>>dato;
			list1.agregar(dato);
			cout<<"Elemento "<<dato<<" agregado a la lista"<<endl;
			break;
			case 2:
            system("cls");
            cout<<"Los elementos de la lista son: "<<endl;
			cout<<"raiz"<<list1.mostrar();
			cout<<"Presiona cualquier tecla para regresar"<<endl;
			getch();
			system("CLS");
			return main();
			break;

			case 3:
			break;
		}
	}while(op!=3);
	return 0;
}
