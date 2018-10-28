/*LA DOCUMENTACIÓN DEL PROGRAMA SE ENCUENTRA AQUÍ MISMO A MODO DE COMENTARIOS.

Se incluyen las librerías necesarias: librería iostream para poder ingresar(cout) y leer(cin) datos; 
librería stdlib para usar la función system("cls") para limpiar la pantalla. Y la librería conio.h para poder usar estructuras (struct)*/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std; //Para el uso de lenguaje estándar.

/*Se crea la estructura nodo que contendrá: 
1. Una variable de tipo entero denomidada como "data", la cual contendrá el elemento o información del nodo.
2. Un puntero de tipo node "next" el cual apunta al siguiente nodo de la lista.*/
struct nodo
{
	int data;
	nodo *next;
};
class ListaC //Se crea la clase Lista.
{
	//En la sección privada de la clase, se crea un puntero de tipo nodo llamado "ultimo".
	private:
		nodo *ultimo;
	//En la sección pública de la clase, se incluyen los métodos a utilizar y se crea el constructor para incializar el nodo "ultimo" en vacío.	
	public:
	ListaCC() //constructor 
	{
		ultimo = NULL;
	}
	/*El primer método para llevar a cabo correctamente la ejecución del programa es crear la lista. Este método recibe un entero denominado item que será proporcionado por el usuario.
	Después es necesario crear un nuevo nodo temporal al que se denominará como "n", éste permitirá acceder a la información o data del nodo guardando el item.
	Si "ultimo" es NULL, se toma como n y se posiciona después de crear la lista. Si no se cumple la condición, n accede a next y será igual que ultimo accendiendo a la iformación
	que hay en next. ultimo accederá a next igualado a n y finalmente ultimo será igual que n.*/
	void create(int item)
	{
		nodo *n = new nodo;
		n->data = item;
		if(ultimo == NULL)
		{
			ultimo = n;
			n->next=ultimo;
		}
		else
		{
			n->next = ultimo->next;
			ultimo->next = n;
			ultimo = n;
		}
	}
	/*El siguiente método será para insertar elementos al principio de la lista o después de la raiz. Pero es importante una condición que indique cuando la lista no se ha creada, 
	si el último nodo señala es NULL, se mandará un mensaje de que primero se debe crear la lista. Si no se involucra la condición, se pasa a crear un nodo temporal "n" el cual accede a la info de data y de next y se posiciona.
	n siempre acceder a next y es igual que si ultimo accediera a next puesto que el final y el inicio siempre están ligados. */
	void addNode(int item)
	{
		if(ultimo == NULL)
		{
			cout<<"Es necesario crear la lista primero."<<endl;
			return;
		}
		nodo *n = new nodo;
		n->data = item;
		n->next = ultimo->next;
		ultimo->next = n;
		cout<<"Elemento "<<item<<" ingresado correctamente.";
	}
};
/*En la función principal main() se crea un switch para llevar poder llamar a las funciones de la clase, a su vez se crea una variable del mismo tipo de la clase para llamar a 
los métodos, así como las variables para poder guardar las opciones del usuario.*/
int main()
{
	ListaC lc;
	int op, dato;
	do //El menú se puede repetir hasta que el usuario decida gracias al bucle do-while.
	{
		cout<<"1.Crear/iniciar lista \n2.Insertar nodos \n3.Salir \nTu opcion es: "; //Se le presentan las opciones al usuario.
		cin>>op;
		switch(op)
		{
			case 1: //La opción 1 le permite crear la lista llamando al método create().
			system("CLS");	
			cout<<"Ingresar primer nodo para crear la lista: ";
			cin>>dato;
			lc.create(dato);	
			cout<<"Lista creada correctamente."<<endl;
			break;
			case 2: //La opción 2 funciona para ir insertado cada unos de los nodos a la lista y posteriormente llama al método addNode.
			system("CLS");
			cout<<"Inserta nodo: ";
			cin>>dato;
			lc.addNode(dato);
			break;
			case 3: //La opción 3 permite terminar el programa.
			break;	
			default: //En caso de que el usuario no seleccioné ninguna opción al ingresar un dato fuera del programa se le marcará un error y éste termina.
			cout<<"Error!";
		    return 0;
			break; 
		}	
	}while(op!=3);
	return 0;
}
//Fin del programa.

