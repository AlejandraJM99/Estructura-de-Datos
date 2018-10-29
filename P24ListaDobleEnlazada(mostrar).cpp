/*LA DOCUMENTACIÓN DEL PROGRAMA SE ENCUENTRA AQUÍ MISMO A MODO DE COMENTARIOS.

LISTA DOBLEMENTE ENLAZADA
Se incluyen las librerías necesarias: librería iostream para poder ingresar(cout) y leer(cin) datos; 
librería stdlib para usar la función system("cls") para limpiar la pantalla. Y la librería conio.h para poder usar estructuras (struct)*/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std; //Para hacer uso del lenguaje estándar.

/*Se crea la estructura nodo que contendrá: 
1. Una variable de tipo entero denomidada como "data", la cual contendrá el elemento o información del nodo.
2. Dos punteros de tipo node; "next" y "atras". */
struct nodo
{
	int data;
	nodo *next;
	nodo *atras;
}; 
//Se crea la clase ListaDoble.
class ListaDoble
{
	//En la sección privada de la clase, se crean dos punteros denominados first(primero) y last(ultimo)
	private:
		nodo *first;
		nodo *last;
	//En la sección pública se crean los métodos a utilizar y se inicializan los punteros en NULL.	
	public:	
	ListaDoble()
	{
		first = NULL;
		last = NULL; 
	}
	/*El método insertar() servirá para meter información a los nodos. Primero se crea un nuevo puntero denominado "nuevo"
	de tipo nodo. Después se le pide al usuario que ingrese el número que contendrá el nodo y ésta se almacena dentro de "nuevo"*/
	void insertar()
	{
		nodo *nuevo = new nodo;
		cout<<"Ingresa la info. que contendra el nodo: ";
		cin>>nuevo->data;
	/*Si la lista aún no se ha creado, se procede a crear la cabeza de la lista. Esto se logra gracias a una condición:
	Si dato primero apunta a NULL (a nada) por ende la lista está vacía y se continúa con la inserción del primer dato.*/
	if(first == NULL)
	{
		first = nuevo; //el primer(first) nodo pasa a ser el "nuevo" nodo.
		first->next=NULL; //primero tiene un apuntador siguiente(next) a NULL porque es el primero y único en la lista.
		first->atras=NULL; //también tiene un apuntador hacia atrás(atrás) que apunta a NULL por ser el primero y único en la lista.
		//Tiene los dos apuntadores hacia NULL por ser doblemente enlazada.
		last = first; //Entonces al ser el único nodo se considera como el primero(first) y el último(last).
	}
	//En caso de que la cabeza o raíz de la lista ya esté insertada, se procede a almacenar los demás nodos.
	else
	{
		last->next=nuevo; //El último nodo apunta al nuevo nodo ingresado almancenado en "nuevo".
		nuevo->next=NULL; //El nuevo nodo apunta a NULL puesto que ahora es el último de la lista y no apunta a un nodo siguiente.
		nuevo->atras=last; //El puntero de atrás del nuevo nodo apunta al último nodo que antes era el primero o cabeza.
		last=nuevo; //el último nodo insertado pasa a ser el nuevo y más reciente nodo.
	}
	cout<<"Nodo insertado correctamente!"<<endl;
	}	
	/*El método mostrarDer imprimirá a partir de la cabeza de la lista hasta el final (first to last). Primero se crea un nuevo nodo llamado act de actual y éste se iguala al primer nodo
	de la lista.*/
	void mostrarDer()
	{
		nodo *act = new nodo;
		act = first; //Actual pasa a ser el primer elemento.
		if(first != NULL) //Si el primer elemento no apunta a NULL, se irán imprimiendo los elementos.
		{
			while(act!=NULL) //Mientras que el nodo act sea diferente de NULL, el nodo act pasa a ser el actual siguiente para ir imprimiendo cada dato.
			{
				cout<<" "<<act->data;
				act=act->next;
			}
		}else
		{
			cout<<"Lista vacia! No hay nada que mostrar"<<endl; 
		}
	}
	/*El método mostrarIzq imprimirá a partir de la cola de la lista hasta el principio (last to firstt). Primero se crea un nuevo nodo llamado act de actual y éste se iguala al último nodo
	de la lista.*/
	void mostrarIzq()
	{
		nodo *act = new nodo;
		act = last; //Actual pasa a ser el último elemento.
		if(first != NULL) //Si el primer elemento no apunta a NULL, se irán imprimiendo los elementos.
		{
			while(act!=NULL) //Mientras que el nodo act sea diferente de NULL, el nodo act pasa a ser el actual de atrás para ir imprimiendo cada dato.
			{
				cout<<" "<<act->data;
				act=act->atras;
			}
		}else
		{
			cout<<"Lista vacia! No hay nada que mostrar"<<endl;
		}
	}
};
//En la función principal main() se mandarán  llamar a los métodos de la clase.
int main()
{ 
    //Se crean las variables a utilizar para almacenar respuestas y para llamar a los métodos.
	int op;
	ListaDoble ld;
	do //Se repetirá hasta que el usuario desée gracias al ciclo do-while.
	{
		cout<<"\n1.Insertar nodos. \n2.Mostrar lista \n3.Salir \nTu opcion es: "; //Se le despliega un menú de opciones y su opción se guardará en la variable op.
		cin>>op;
		switch(op)
		{
			case 1: //Si el usuario selecciona la opción 1.Insertar nodos, se llama al método insertar() implementado en la clase.
			system("CLS");
			ld.insertar();	
			break;
			case 2: //Si el usuario selecciona la opción 2.Mostrar lista, se le desplegará un submenú en el cual tendrá tres opciones.
			system("CLS");
			cout<<"1.Mostrar derecha->izquierda \n2.Mostrar derecha<-izquierda \n3.Volver al menu principal \nTu opcion es: ";
			cin>>op;
			switch(op)
			{
				case 1: //Si selecciona la opción 1, muestra la lista del lado derecho llamando mostrarDer().
				system("CLS");
				ld.mostrarDer();
				break;
				case 2: //Si selecciona la opción 2, muestra la lista del lado izquierdo llamando mostrarIzq().
				system("CLS");
				ld.mostrarIzq();
				break;
				case 3: //Si se selecciona la opción 3, se regresa al menú principal.
				system("CLS");
				return main();
				break;	
				default: //En caso de que el usuario no seleccioné ninguna opción al ingresar un dato fuera del programa se le marcará un error y éste termina.
				cout<<"Error!";
				return 0;
				break; 		
			}
			break;	
			case 3: //Si el usuario selecciona la opción 3.Salir, el programa termina.
			break;
			default: //En caso de que el usuario no seleccioné ninguna opción al ingresar un dato fuera del programa se le marcará un error y éste termina.
		    cout<<"Error!";
	    	return 0;
            break; 	
		}
	}while(op!=3);
}
//Fin del programa.
