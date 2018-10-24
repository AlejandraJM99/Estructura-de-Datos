/*LA DOCUMENTACI�N DEL PROGRAMA SE ENCUENTRA AQU� MISMO A MODO DE COMENTARIOS.

Se incluyen las librer�as necesarias: librer�a iostream para poder ingresar(cout) y leer(cin) datos; 
librer�a stdlib para usar la funci�n system("cls") para limpiar la pantalla. Y la librer�a stdio.h para poder usar estructuras (struct)*/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;//para el uso de lenguaje est�ndar.
class Lista //A continuaci�n se crea la clase Lista que incluir� la estructura del nodo y los respectivos m�todos.
{
	private: //de forma privada se crear la estructura del nodo
		struct nodo //estructura nodo.
		{
			int dato; //dato por el usuario.
			nodo *next; //puntero para anotar al siguiente nodo.
		};
	//se crean punteros del mismo tipo de la estructura nodo
		nodo*raiz=NULL; //ra�z de la lista.
		nodo*temp=NULL; //nodo temporal.
		nodo*act=NULL; //nodo actual.

	public: //en la secci�n p�blica se declaran las funciones a implementar.
	void agregar(int item) //1er m�todo para agregar los elementos
	{
		/*Para poder agregar elementos es necesario crear un nuevo nodo y el puntero n que ser� el encargado de apuntar al enlace sigueinte y al dato introducido.*/
		nodo *n = new nodo;
		n->next = NULL;
		n->dato = item;

		if(raiz!=NULL) //Para agregar la ra�z, se debe verificar que est� vac�a, si es as�, el nodo actual (a�adido recientemente) pasa a ser la ra�z.
		{
			act = raiz;
			while(act->next != NULL) //Mientras que el nodo actual apuntando al siguiente sea diferente de vac�o, el nodo actual ligar� apuntando al siguiente para ir almacenando los datos.
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
	void mostrar() //2do m�todo para imprimir la lista en pantalla.
	{
		act = raiz; //el dato m�s actual ser� la ra�z.
		while(act != NULL) //Y mientras el dato no sea igual NULL o est� vac�o, se imprime cada dato de la lista.
		{
			cout<<act->dato<<endl;
			act = act->next;
		}
	}
};
//Dentro de la funci�n principal main, se declaran las variables a utilizar dentro de un men� switch y una variable de tipo Lista para poder llamar a los m�todos.
int main()
{
	int dato,op;
	Lista list1;
	do{ //Dentro de un m�todo do-while, se lleva a cabo un switch para poder mostrar al usuario las opciones del programa y terminar hasta que �l decida. 1.Agregar 2.Mostrar 3.Salir del programa. Su opc se guarda en la variable op.
	cout<<"1.Insertar dato \n2.Mostrar \n3.Salir"<<endl;
	cout<<"Tu opcion es: ";
	cin>>op;

		switch(op) //la funci�n switch funciona con la elecci�n del usuario.
		{
			case 1: //si el usuario seleeciona 1.Insertar dato, se le pedir� agregar un elemento que se guardar� en la variable aux. dato y simplemente manda a llamar al m�todo de agregar implementado en la clase
			system("cls");
			cout<<"Ingresa un elemento a la lista: ";
			cin>>dato;
			list1.agregar(dato);
			cout<<"Elemento "<<dato<<" agregado a la lista"<<endl; //se imprime en pantalla una confirmaci�n de que el elemento se ingres� correctamente.
			break;
			case 2: //si el usuario selecciona 2.Mostrar, se manda a llamar al m�todo de mostrar() implementado en la clase Lista y posteriormente se imprimen todos los datos de la lista.
            system("cls");
            cout<<"Los elementos de la lista son: "<<endl;
			list1.mostrar();
			cout<<"Presiona cualquier tecla para regresar"<<endl;
			getch();
			system("CLS");
			return main();
			break;
			case 3: //si el usuario selecciona la opci�n 3.Salir, el programa termina.
			break;
		}
	}while(op!=3);
	return 0;
}
//Fin del programa.
