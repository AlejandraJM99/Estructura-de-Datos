/*LA DOCUMENTACI�N DEL PROGRAMA SE ENCUENTRA AQU� MISMO A MODO DE COMENTARIOS.
Se incluyen las librer�as necesarias: librer�a iostream para poder ingresar(cout) y leer(cin) datos; 
librer�a stdlib para usar la funci�n system("cls") para limpiar la pantalla. Y la librer�a stdio.h para poder usar estructuras (struct)*/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std; //Se implementa para el uso de lenguaje est�ndar.

/*Se crea la estructura node que contendr�: 
1. Una variable de tipo entero denomidada como "data", la cual contendr� el elemento o informaci�n del nodo.
2. Un puntero de tipo node "next" el cual apunta al siguiente nodo de la lista. */
struct nodo 
{
	int data;
	nodo *next;
};
class Lista //Se crea la clase Lista.
{
	private: //En la secci�n privada de la clase se crean dos punteros de tipo node: uno ser� la ra�z de la lista y el otro la cola.
		nodo *raiz;
		nodo *cola;
	public: //En la secci�n p�blica de la clase, se crea el constructor el cual se encargar� de inicializar los valores de de ra�z y cola como nulos.
	Lista()
	{
		raiz = NULL;
		cola = NULL;
	}	
	/*El primer m�todo ser� crear un nuevo nodo, �ste recibe un entero que se denominar� como item y ser� auxiliar del data para almacenar la informaci�n.
	Se necesita un crear un puntero de tipo nodo para crear el nuevo nodo llamado "n". Una vez creado, n se encargar� de acceder al dato que contenga el nodo.
	A su vez, n apunta a next igual a NULL para referenciarlo como el �ltimo nodo de la lista. */
	void insertar(int item)
	{
		nodo *n = new nodo;
		n->next=NULL;
		n->data=item; 
	/*Se crea una condici�n para ingresar datos o una raiz. Si ra�z es diferente de NULL, el �ltimo nodo "cola" pasa a ser la ra�z y se pueden ingresar nodos despu�s d�.
	Y mientras la cola apuntando a next no sea NULL, se ir�n agregando los nodos como n.*/
	if(raiz != NULL) 
	{
		cola = raiz;
		while(cola->next!=NULL)
		{
			cola = cola->next;
		}
		cola ->next = n;
	}else //Sino, el valor ingresado ser� la ra�z.
	{
		raiz = n;
	}
    }
};
int main() //Dentro de la funci�n principal main, se declaran las variables a utilizar dentro de un men� switch y una variable de tipo Lista para poder llamar a los m�todos de la clase.
{
	int dato,op;
	Lista list1;
	do{ //El proceso se llevar� a cabo hasta que el usuario des�e terminarlo, todo esto gracias a un bucle do-while.
	//Las opciones que se le presentan al usuario son: 1.Insertar nodos y 2.Salir, su opci�n se guarda dentro de una variable int llamada "op".
	cout<<"1.Insertar nodos \n2.Salir \nTu opcion es: ";
	cin>>op;
	switch(op) //La funci�n switch funciona con la opci�n del usuario almacenada en la variable op.
	{
		case 1: //Si el usuario selecciona la opci�n 1, se le pedir� que vaya ingresando nodos a lista. Esto se logra con la llamada del metodo insertar() implementado en la clase Lista.
		system("CLS");
		cout<<"Ingresa un nodo a la lista: ";
		cin>>dato;
		list1.insertar(dato);
		cout<<"Nodo "<<dato<<" ingresado correctamente."<<endl;	//Un mensaje para confirmar que se agreg� el nodo correctamente.
		break;	
		case 2: //Si el usuario selecciona la opci�n 2, el programa termina.
		break;	
		default: //En caso de que el usuario no seleccion� ninguna opci�n al ingresar un dato fuera del programa se le marcar� un error y �ste termina.
		cout<<"Error!";
		return 0;
		break;	
	}
	}while(op!=2);
	return 0;
}
//Fin del programa
