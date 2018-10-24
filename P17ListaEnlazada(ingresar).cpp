/*LA DOCUMENTACI�N DEL PROGRAMA SE ENCUENTRA AQU� MISMO A MODO DE COMENTARIOS.

Se incluyen las librer�as necesarias: librer�a iostream para poder ingresar(cout) y leer(cin) datos; 
librer�a stdlib para usar la funci�n system("cls") para limpiar la pantalla. Y la librer�a stdio.h para poder usar estructuras (struct)*/
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std; //para el uso de lenguaje est�ndar.
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

	public: //en la secci�n p�blica se crean los m�todos a implementar.
	void agregar(int item) //Funci�n para agregar elementos a la lista, el cual es de tipo void y recibir� un entero al que se denomina item y ser� dado por el usuario.
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
};
//Dentro de la funci�n principal main, se declaran las variables a utilizar dentro de un men� switch y una variable de tipo Lista para poder llamar a los m�todos.
int main()
{
	int dato,op;
	Lista list1;
	do{ //Dentro de un m�todo do-while, se lleva a cabo un switch para poder mostrar al usuario las opciones del programa. 1.Agregar y 2.Salir del programa. Su opc se guarda en la variable op.
	cout<<"1.Insertar dato \n2.Salir"<<endl;
	cout<<"Tu opcion es: ";
	cin>>op;

		switch(op) //la funci�n switch funciona con la elecci�n del usuario.
		{
			case 1: //si el usuario seleeciona 1.Insertar dato, se le pedir� agregar un elemento que se guardar� en la variable aux. dato y simplemente manda a llamar al m�todo de agregar implementado en la clase
			system("CLS");
			cout<<"Ingresa un elemento a la lista: ";
			cin>>dato;
			list1.agregar(dato); //Llamada al m�todo agregar();
			cout<<"Elemento "<<dato<<" agregado a la lista"<<endl; //se imprime en pantalla una confirmaci�n de que el elemento se ingres� correctamente.
			break;
			case 2://si el usuario selecciona la opci�n 2.Salir, el programa termina.
			break;
		}
	}while(op!=2);
	return 0;
}
//Fin del programa.
