/*3.Hacer un programa que lleve el control de versiones de un proyecto en una empresa, la estructura de datos debe controlar el número de migraciones
realizadas en el proyecto. Utilizar una pila para introducir las migraciones una poruna y obtener las migraciones una por una empezando por la migración 
más actual y terminando por la migración más antigua*/
#include <iostream>
#include<stdlib.h>
#include<string>
#define TAM 10000
using namespace std;
class Migracion
{
	string pila[TAM];
	int  index; 
	public:
	    Pila() 
		{
			index = -1;
		}
		void push (string fecha) 
		{
			if(index>TAM)
			{
			    system("CLS");
				cout<<"No hay espacio para agregar mas migraciones"<<endl;
				return;
			}
			pila[++index]=fecha;
			cout<<"Migracion "<<fecha<<" ingresada"<<endl;
		}
		void peekAll()
		{
			if(index<0)
			{
			    system("CLS");
				cout<<"No hay migraciones para mostrar"<<endl;
				return;
			}
			for(int i=index;i>=0;i--)
			{
				cout<<"\n";
				cout<<"Numero de migracion"<<"["<<i<<"]"<<" Fecha:"<<pila[i]<<" ";
			}
		}
};
int main()
{
	int op;
	string op2;
	Migracion pil;
	cout<<"                                         MIGRACIONES DEL PROYECTO"<<endl;
	do
	{
		cout<<"1.Ingresar una nueva migracion \n2.Mostrar migraciones \n3.Salir \nTu opcion es:  ";
		cin>>op;
		switch(op)
		{
			case 1:
			    system("CLS");
				cout<<"Ingresar fecha de la migracion (dia-mes-anio): ";
				cin>>op2;
				system("CLS");
				pil.push(op2);
			break;
			case 2:
				system("CLS");
				cout<<"Total de migraciones"<<endl;
				pil.peekAll();
				cout<<"\n"<<endl;
			break;
			case 3:
			break;	
	    }
	}while(op!=3);
}

