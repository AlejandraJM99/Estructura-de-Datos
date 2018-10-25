/*LA DOCUMENTACIÓN DEL PROGRAMA SE ENCUENTRA AQUÍ MISMO A MODO DE COMENTARIOS.
Se incluyen las librerías necesarias: librería iostream para poder ingresar(cout) y leer(cin) datos; 
librería stdlib para usar la función system("cls") para limpiar la pantalla. Y la librería stdio.h para poder usar estructuras (struct)*/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std; //Se implementa para el uso de lenguaje estándar.

/*Se crea la estructura node que contendrá: 
1. Una variable de tipo entero denomidada como "data", la cual contendrá el elemento o información del nodo.
2. Un puntero de tipo node "next" el cual apunta al siguiente nodo de la lista. */
struct nodo 
{
	int data;
	nodo *next;
};
class Lista //Se crea la clase Lista.
{
	private: //En la sección privada de la clase se crean dos punteros de tipo node: uno será la raíz de la lista y el otro la cola.
		nodo *raiz;
		nodo *cola;
	public: //En la sección pública de la clase, se crea el constructor el cual se encargará de inicializar los valores de de raíz y cola como nulos.
	Lista()
	{
		raiz = NULL;
		cola = NULL;
	}	
	/*El primer método será crear un nuevo nodo, éste recibe un entero que se denominará como item y será auxiliar del data para almacenar la información.
	Se necesita un crear un puntero de tipo nodo para crear el nuevo nodo llamado "n". Una vez creado, n se encargará de acceder al dato que contenga el nodo.
	A su vez, n apunta a next igual a NULL para referenciarlo como el último nodo de la lista. */
	void insertar(int item)
	{
		nodo *n = new nodo;
		n->next=NULL;
		n->data=item; 
	/*Se crea una condición para ingresar datos o una raiz. Si raíz es diferente de NULL, el último nodo "cola" pasa a ser la raíz y se pueden ingresar nodos después dé.
	Y mientras la cola apuntando a next no sea NULL, se irán agregando los nodos como n.*/
	if(raiz != NULL) 
	{
		cola = raiz;
		while(cola->next!=NULL)
		{
			cola = cola->next;
		}
		cola ->next = n;
	}else //Sino, el valor ingresado será la raíz.
	{
		raiz = n;
	}
    }
};
int main() //Dentro de la función principal main, se declaran las variables a utilizar dentro de un menú switch y una variable de tipo Lista para poder llamar a los métodos de la clase.
{
	int dato,op;
	Lista list1;
	do{ //El proceso se llevará a cabo hasta que el usuario desée terminarlo, todo esto gracias a un bucle do-while.
	//Las opciones que se le presentan al usuario son: 1.Insertar nodos y 2.Salir, su opción se guarda dentro de una variable int llamada "op".
	cout<<"1.Insertar nodos \n2.Salir \nTu opcion es: ";
	cin>>op;
	switch(op) //La función switch funciona con la opción del usuario almacenada en la variable op.
	{
		case 1: //Si el usuario selecciona la opción 1, se le pedirá que vaya ingresando nodos a lista. Esto se logra con la llamada del metodo insertar() implementado en la clase Lista.
		system("CLS");
		cout<<"Ingresa un nodo a la lista: ";
		cin>>dato;
		list1.insertar(dato);
		cout<<"Nodo "<<dato<<" ingresado correctamente."<<endl;	//Un mensaje para confirmar que se agregó el nodo correctamente.
		break;	
		case 2: //Si el usuario selecciona la opción 2, el programa termina.
		break;	
		default: //En caso de que el usuario no seleccioné ninguna opción al ingresar un dato fuera del programa se le marcará un error y éste termina.
		cout<<"Error!";
		return 0;
		break;	
	}
	}while(op!=2);
	return 0;
}
//Fin del programa
