/*LA DOCUMENTACI�N DEL PROGRAMA SE ENCUENTRA AQU� MISMO A MODO DE COMENTARIOS.

Se incluyen las librer�as necesarias: librer�a iostream para poder ingresar(cout) y leer(cin) datos; 
librer�a stdlib para usar la funci�n system("cls") para limpiar la pantalla. Y la librer�a conio.h para poder usar estructuras (struct)*/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std; //Para el uso de lenguaje est�ndar.

/*Se crea la estructura nodo que contendr�: 
1. Una variable de tipo entero denomidada como "data", la cual contendr� el elemento o informaci�n del nodo.
2. Un puntero de tipo node "next" el cual apunta al siguiente nodo de la lista.*/
struct nodo
{
	int data;
	nodo *next;
};
class ListaC //Se crea la clase Lista.
{
	//En la secci�n privada de la clase, se crea un puntero de tipo nodo llamado "ultimo".
	private:
		nodo *ultimo;
	//En la secci�n p�blica de la clase, se incluyen los m�todos a utilizar y se crea el constructor para incializar el nodo "ultimo" en vac�o.	
	public:
	ListaCC() //constructor 
	{
		ultimo = NULL;
	}
	/*El primer m�todo para llevar a cabo correctamente la ejecuci�n del programa es crear la lista. Este m�todo recibe un entero denominado item que ser� proporcionado por el usuario.
	Despu�s es necesario crear un nuevo nodo temporal al que se denominar� como "n", �ste permitir� acceder a la informaci�n o data del nodo guardando el item.
	Si "ultimo" es NULL, se toma como n y se posiciona despu�s de crear la lista. Si no se cumple la condici�n, n accede a next y ser� igual que ultimo accendiendo a la iformaci�n
	que hay en next. ultimo acceder� a next igualado a n y finalmente ultimo ser� igual que n.*/
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
	/*El siguiente m�todo ser� para insertar elementos al principio de la lista o despu�s de la raiz. Pero es importante una condici�n que indique cuando la lista no se ha creada, 
	si el �ltimo nodo se�ala es NULL, se mandar� un mensaje de que primero se debe crear la lista. Si no se involucra la condici�n, se pasa a crear un nodo temporal "n" el cual accede a la info de data y de next y se posiciona.
	n siempre acceder a next y es igual que si ultimo accediera a next puesto que el final y el inicio siempre est�n ligados. */
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
/*En la funci�n principal main() se crea un switch para llevar poder llamar a las funciones de la clase, a su vez se crea una variable del mismo tipo de la clase para llamar a 
los m�todos, as� como las variables para poder guardar las opciones del usuario.*/
int main()
{
	ListaC lc;
	int op, dato;
	do //El men� se puede repetir hasta que el usuario decida gracias al bucle do-while.
	{
		cout<<"1.Crear/iniciar lista \n2.Insertar nodos \n3.Salir \nTu opcion es: "; //Se le presentan las opciones al usuario.
		cin>>op;
		switch(op)
		{
			case 1: //La opci�n 1 le permite crear la lista llamando al m�todo create().
			system("CLS");	
			cout<<"Ingresar primer nodo para crear la lista: ";
			cin>>dato;
			lc.create(dato);	
			cout<<"Lista creada correctamente."<<endl;
			break;
			case 2: //La opci�n 2 funciona para ir insertado cada unos de los nodos a la lista y posteriormente llama al m�todo addNode.
			system("CLS");
			cout<<"Inserta nodo: ";
			cin>>dato;
			lc.addNode(dato);
			break;
			case 3: //La opci�n 3 permite terminar el programa.
			break;	
			default: //En caso de que el usuario no seleccion� ninguna opci�n al ingresar un dato fuera del programa se le marcar� un error y �ste termina.
			cout<<"Error!";
		    return 0;
			break; 
		}	
	}while(op!=3);
	return 0;
}
//Fin del programa.

