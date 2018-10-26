/*LA DOCUMENTACIÓN DEL PROGRAMA SE ENCUENTRA AQUÍ MISMO A MODO DE COMENTARIOS.
Se incluyen las librerías necesarias: librería iostream para poder ingresar(cout) y leer(cin) datos; 
librería stdlib para usar la función system("cls") para limpiar la pantalla. Y la librería stdio.h para poder usar estructuras (struct)*/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std; //Se implementa para el uso de lenguaje estándar.

/*Se crea la estructura nodo que contendrá: 
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
    /*El método para mostrar cada uno de los nodos desde la raíz. Primero se crear un nuevo puntero de tipo nodo "n". n será igual a la raíz y mientras no sea NULL,
	se irá imprimiento en pantalla cada nodo. Aquí n apuntará a la posición de next para imprimir los nodos.*/
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
	/*El método para eliminar la raiz de la lista es el siguiente. Después de crear un puntero de tipo nodo "n" se iguala a la raíz. En este caso la raíz irá apuntando
	al nodo next para ir cambiando de posición y finalmente se irá eliminando n.*/
	void deleteRaiz()
    {
    	nodo *n = new nodo;
    	n=raiz;
    	raiz = raiz->next;
    	delete n;
	}
	/*El método para eliminar el último nodo o cola necesita dos nodos para funcionar, ya que al eliminar la cola se necesita tomar el nodo anterior como la nueva cola.
	Primero se declaran los punteros de tipo nodo "act" y "ante". El nodo ante apuntará    */
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
	/*El método para eliminar algún dato en específico de la lista funciona de la siguiente manera: el método recibe una variable de tipo entero denominado "pos" por
	posición. Se crean dos punteros de tipo nodo "act" para referirse al nodo actual y "ante" para referirse al nodo anterior. El nodo actual será la raíz y dentro de un
	bucle for se irá buscando el elemento que el usuario desea eliminar.   */
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
int main()  //Dentro de la función principal main, se declaran las variables a utilizar dentro de un menú switch y una variable de tipo Lista para poder llamar a los métodos de la clase.
{
	int dato,op;
	Lista list1;
	do{ //El proceso se llevará a cabo hasta que el usuario desée terminarlo, todo esto gracias a un bucle do-while.
	//Las opciones que se le presentan al usuario son: 1.Insertar nodos, 2.Mostrar lista 3.Elimnar nodos y 4.Salir, su opción se guarda dentro de una variable int llamada "op".
	cout<<"1.Insertar nodos \n2.Mostrar lista \n3.Eliminar nodos \n4.Salir \nTu opcion es: ";
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
		case 2: //Si el usuario selecciona la opción 2, simplemente se mandará a llamar al método recorrer() implmentado en la clase Lista y se llevará a cabo imprimendo en pantalla los nodos.
		system("CLS");	
		cout<<"Los nodos de la lista son: "<<endl;
		list1.recorrer();
		cout<<"\n"<<endl;
		break;	
		case 3: /*Si el usuario selecciona la opción 3 de eliminar nodos, se le presentará un segundo submenú para que pueda escoger que tipo de nodo quiere eliminar,
		ya sea la raíz, la cola o algún nodo en específico de la lista.*/
			system("CLS");
			cout<<"1.Eliminar raiz \n2.Eliminar cola \n3.Eliminar un dato \n4.Volver al menu principal \nTu opcion es: ";
			cin>>op;
			switch(op)
			{
				case 1: //La opción 1 del submenú, manda un mensaje de que se eliminó la raíz y manda a llamar al método deleteRaiz() implementado en la clase.
				system("CLS");
				cout<<"Se elimino el nodo raiz "<<endl;
				list1.deleteRaiz();	
				break;
				case 2: //La opción 2 del submenú, manda un mensaje de que se eliminó la cola y manda a llamar al método deleteCola() implementado en la clase.
				system("CLS");
				cout<<"Se elimino el nodo cola de la lista"<<endl;
				list1.deleteCola();
				break;
				case 3: /*la opción 3, pregunta al usuario que nodo de la lista desea eliminar (si éste no existe simplemente se repite el proceso) y una vez ingresada
				su respuesta, se manda a llamar el método deleteIndex() recibiendo la variable auxiliar donde se guardó la respuesta del usuario.  */
				system("CLS");
				cout<<"Escoge el nodo que desees eliminar: ";
				cin>>dato;
				list1.deleteIndex(dato);
				break;
				case 4: //Si el usuario selecciona la opción 4, se le regresa al menú principal.
				system("CLS"); 
				return main();
				break;
				default: //En caso de que el usuario no seleccioné ninguna opción al ingresar un dato fuera del programa se le marcará un error y éste termina.
				cout<<"Error!"<<endl;
				return 0;
				break;	
			}
		break;	
		case 4://Si el usuario selecciona la opción 3, el programa termina.
		break;	
		default: //En caso de que el usuario no seleccioné ninguna opción al ingresar un dato fuera del programa se le marcará un error y éste termina.
		cout<<"Error!";
		return 0;
		break;	
	}
	}while(op!=4);
	return 0;
}
//Fin del programa.


