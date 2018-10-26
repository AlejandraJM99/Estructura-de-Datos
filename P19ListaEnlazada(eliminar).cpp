/*LA DOCUMENTACI�N DEL PROGRAMA SE ENCUENTRA AQU� MISMO A MODO DE COMENTARIOS.
Se incluyen las librer�as necesarias: librer�a iostream para poder ingresar(cout) y leer(cin) datos; 
librer�a stdlib para usar la funci�n system("cls") para limpiar la pantalla. Y la librer�a stdio.h para poder usar estructuras (struct)*/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std; //Se implementa para el uso de lenguaje est�ndar.

/*Se crea la estructura nodo que contendr�: 
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
    /*El m�todo para mostrar cada uno de los nodos desde la ra�z. Primero se crear un nuevo puntero de tipo nodo "n". n ser� igual a la ra�z y mientras no sea NULL,
	se ir� imprimiento en pantalla cada nodo. Aqu� n apuntar� a la posici�n de next para imprimir los nodos.*/
	void recorrer()
	{
		nodo *n = new nodo;
		n = raiz;
		while(n!=NULL)
		{
			cout<<n->data<<"\t";
			n = n->next;
		}
	}
	/*El m�todo para eliminar la raiz de la lista es el siguiente. Despu�s de crear un puntero de tipo nodo "n" se iguala a la ra�z. En este caso la ra�z ir� apuntando
	al nodo next para ir cambiando de posici�n y finalmente se ir� eliminando n.*/
	void deleteRaiz()
    {
    	nodo *n = new nodo;
    	n=raiz;
    	raiz = raiz->next;
    	delete n;
	}
	/*El m�todo para eliminar el �ltimo nodo o cola necesita dos nodos para funcionar, ya que al eliminar la cola se necesita tomar el nodo anterior como la nueva cola.
	Primero se declaran los punteros de tipo nodo "act" y "ante". El nodo ante apuntar�    */
	void deleteCola()
	{
		nodo *act = new nodo;
		nodo *ante = new nodo;
		act=raiz;
		while(act->next != NULL)
		{
			ante=act;
			act=act->next; 
			 
		}
		cola = ante;
		ante->next=NULL;
		delete act;
	}
	/*El m�todo para eliminar alg�n dato en espec�fico de la lista funciona de la siguiente manera: el m�todo recibe una variable de tipo entero denominado "pos" por
	posici�n. Se crean dos punteros de tipo nodo "act" para referirse al nodo actual y "ante" para referirse al nodo anterior. El nodo actual ser� la ra�z y dentro de un
	bucle for se ir� buscando el elemento que el usuario desea eliminar.   */
	void deleteIndex(int pos)
	{
		nodo *act = new nodo;
		nodo *ante = new nodo;
		act=raiz;
		for(int i=1; i<pos; i++)
		{
			ante = act;
			act = act ->next;
		}
		ante ->next=act->next;
	}
};
int main()  //Dentro de la funci�n principal main, se declaran las variables a utilizar dentro de un men� switch y una variable de tipo Lista para poder llamar a los m�todos de la clase.
{
	int dato,op;
	Lista list1;
	do{ //El proceso se llevar� a cabo hasta que el usuario des�e terminarlo, todo esto gracias a un bucle do-while.
	//Las opciones que se le presentan al usuario son: 1.Insertar nodos, 2.Mostrar lista 3.Elimnar nodos y 4.Salir, su opci�n se guarda dentro de una variable int llamada "op".
	cout<<"1.Insertar nodos \n2.Mostrar lista \n3.Eliminar nodos \n4.Salir \nTu opcion es: ";
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
		case 2: //Si el usuario selecciona la opci�n 2, simplemente se mandar� a llamar al m�todo recorrer() implmentado en la clase Lista y se llevar� a cabo imprimendo en pantalla los nodos.
		system("CLS");	
		cout<<"Los nodos de la lista son: "<<endl;
		list1.recorrer();
		cout<<"\n"<<endl;
		break;	
		case 3: /*Si el usuario selecciona la opci�n 3 de eliminar nodos, se le presentar� un segundo submen� para que pueda escoger que tipo de nodo quiere eliminar,
		ya sea la ra�z, la cola o alg�n nodo en espec�fico de la lista.*/
			system("CLS");
			cout<<"1.Eliminar raiz \n2.Eliminar cola \n3.Eliminar un dato \n4.Volver al menu principal \nTu opcion es: ";
			cin>>op;
			switch(op)
			{
				case 1: //La opci�n 1 del submen�, manda un mensaje de que se elimin� la ra�z y manda a llamar al m�todo deleteRaiz() implementado en la clase.
				system("CLS");
				cout<<"Se elimino el nodo raiz "<<endl;
				list1.deleteRaiz();	
				break;
				case 2: //La opci�n 2 del submen�, manda un mensaje de que se elimin� la cola y manda a llamar al m�todo deleteCola() implementado en la clase.
				system("CLS");
				cout<<"Se elimino el nodo cola de la lista"<<endl;
				list1.deleteCola();
				break;
				case 3: /*la opci�n 3, pregunta al usuario que nodo de la lista desea eliminar (si �ste no existe simplemente se repite el proceso) y una vez ingresada
				su respuesta, se manda a llamar el m�todo deleteIndex() recibiendo la variable auxiliar donde se guard� la respuesta del usuario.  */
				system("CLS");
				cout<<"Escoge el nodo que desees eliminar: ";
				cin>>dato;
				list1.deleteIndex(dato);
				break;
				case 4: //Si el usuario selecciona la opci�n 4, se le regresa al men� principal.
				system("CLS"); 
				return main();
				break;
				default: //En caso de que el usuario no seleccion� ninguna opci�n al ingresar un dato fuera del programa se le marcar� un error y �ste termina.
				cout<<"Error!"<<endl;
				return 0;
				break;	
			}
		break;	
		case 4://Si el usuario selecciona la opci�n 3, el programa termina.
		break;	
		default: //En caso de que el usuario no seleccion� ninguna opci�n al ingresar un dato fuera del programa se le marcar� un error y �ste termina.
		cout<<"Error!";
		return 0;
		break;	
	}
	}while(op!=4);
	return 0;
}
//Fin del programa.


