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
	//El método buscar servirá para buscar un elemento en específico de la lista preguntando al usuario.
	void buscar()
	{
		//Se declara un nuevo nodo actual act y éste se igual al primero first.
		nodo *act = new nodo;
		act = first;
		//la variable encontrado de tipo bool funcionará para cuando se encuentre el elemento solicitado.
		bool encontrado = false;
		int buscado = 0; //una variable de tipo entero llamado buscado igual a cero que será proporcionado por el usuario.
		cout<<"Ingresa el dato del nodo que buscas: ";
		cin>>buscado;
		//Con el siguiente método se recorrerá la lista hasta encontrar el dato solicitado. Si el primer elemento no es NULL, se procede a buscar el dato.
		if(first!=NULL)
		{
			//Mientras que el act no sea null y el encontrado aún no sea true, se buscará el dato.
			while(act!=NULL and encontrado!=true)
			{
				//Si actual es igual a buscado, la variable encontrado pasa a ser true y el ciclo termina.
				if(act->data == buscado)
				{
				cout<<"La informacion "<<buscado<<" se ha encontrado en un nodo."<<endl;
				encontrado = true;
				} 
				act = act->next; //El nodo actual apunta a siguiente next para ir recorriendo y "visitando" cada nodo para encontrar la información solicitado.
			}
		if(!encontrado) //Si el dato proporcionado es diferente de encontrado, se informa que el dato no se encontró.
		{
			cout<<"No se encontre nodo con esa informacion."<<endl;
		}
		}else //Si no se cumple nada de lo anterior, la lista está vacía.
		{
			cout<<"Lista vacia!"<<endl;
		}		
	}
	//El método eliminar servirá para eliminar un nodo con la información que éste contenga y será proporcionada por el usuario.
	void eliminar()
	{
		//Se utiliza el mismo código de búsqueda para ir recorriendo la lista pero con algunas modificaciones.
		//Se declara un nuevo nodo actual act y éste se igual al primero first.
		nodo *act = new nodo;
		act = first;
		nodo *anterior = new nodo;
		anterior = NULL;
		//la variable encontrado de tipo bool funcionará para cuando se encuentre el elemento solicitado.
		bool encontrado = false;
		int buscado = 0; //una variable de tipo entero llamado buscado igual a cero que será proporcionado por el usuario.
		cout<<"Ingresa el dato del nodo a eliminar: ";
		cin>>buscado;
		//Con el siguiente método se recorrerá la lista hasta encontrar el dato solicitado. Si el primer elemento no es NULL, se procede a buscar el dato.
		if(first!=NULL)
		{
			//Mientras que el act no sea null y el encontrado aún no sea true, se buscará el dato.
			while(act!=NULL and encontrado!=true)
			{
				//Si actual es igual a buscado, la variable encontrado pasa a ser true.
				if(act->data == buscado)
				{
				cout<<"La informacion "<<buscado<<" se ha encontrado en un nodo."<<endl;
				/*La primera condición funciona para eliminar la cabeza o raíz de la lista. Si act igresado por el usuario
				es igual al primer nodo. */
			    if(act==first)
			    {
			      	first = first->next; //El primer nodo apunta al siguiente del mismo, entonces el first será el siguiente next
			      	first->atras=NULL; //El nuevo primero no debe apuntar a nada más que a NULL.
				}
				/*La segunda condición es para eliminar el último nodo de la lista. Esto se cumpla si el nodo act ingresado por el usuario
				es igual al último nodo de la lista.*/
				else if(act==last)
				{
					anterior->next=NULL; //El anterior siguiente del último nodo debe apuntar a NULL.
					last = anterior; //Se actualiza que el último dato será ahora el anterior.
				}
				//Para eliminar un nodo que no sea ni el primero ni el segundo.
				else
				{
					//no se debe apuntar al nodo que se desea eliminar para poder eliminarlo.
					anterior->next=act->next; //anterior siguiente debe hacer lo mismo que actual siguiente.
					act->next->atras = anterior; //se pasa a apuntar después del nodo que se quiere eliminar y sale de la lista.
				} 
				cout<<"Nodo eliminado correctamente."<<endl;
				encontrado = true;
				} 
				anterior = act; //anterior hará lo mismo que haga act.
				act = act->next; //El nodo actual apunta a siguiente next para ir recorriendo y "visitando" cada nodo para encontrar la información solicitado.
			}
		if(!encontrado) //Si el dato proporcionado es diferente de encontrado, se informa que el dato no se encontró.
		{
			cout<<"No se encontre nodo con esa informacion."<<endl;
		}
		}else //Si no se cumple nada de lo anterior, la lista está vacía.
		{
			cout<<"Lista vacia!"<<endl;
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
		cout<<"\n1.Insertar nodos. \n2.Mostrar lista \n3.Buscar nodo \n4.Eliminar nodo \n5.Salir \nTu opcion es: "; //Se le despliega un menú de opciones y su opción se guardará en la variable op.
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
			case 3: //Si se selecciona la opción 3.Buscar, se llama al método buscar() implementado en la clase y se ejecuta.
			system("cls");	
			ld.buscar();	
			break;
			case 4:  //Si se selecciona la opción 4, se llama al método eliminar() implementado en la clase y se ejecuta.
			system("CLS");
			ld.eliminar();
			break;	
			case 5: //Si se selecciona la opción 5 el programa termina.
			break;	
			default: //En caso de que el usuario no seleccioné ninguna opción al ingresar un dato fuera del programa se le marcará un error y éste termina.
		    cout<<"Error!";
	    	return 0;
            break; 	
		}
	}while(op!=5);
}
//Fin del programa.
