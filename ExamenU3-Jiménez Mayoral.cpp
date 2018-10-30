/*LA DOCUMENTACION DEL PROGRAMA SE ENCUENTRA AQUÍ MISMO A MODO DE COMENTARIOS

Examen U3: El conjunto de datos siguientes debe ser incluido en una doblemente enlazada 1, 2, 3, 4, 5, 6, 7, 8, 9.
Realizar lo siguiente:
Leer la lista de izquierda a derecha.
Leer la lista de derecha a izquierda.
Insertar: 10, 11, 13
Eliminar: 8, 1
Leer Raiz
Leer Final de lista lado derecho y lado izquierdo.
Buscar: 0, 7, 8, 1.

Se incluyen las librerías necesarias: librería iostream para poder ingresar(cout) y leer(cin) datos;
librería stdlib.h para usar la función system("cls") para limpiar la pantalla. */
#include<iostream>
#include<stdlib.h>

using namespace std; //Para hacer uso del lenguaje estándar.

/*Se crea la estructura nodo que contendrá:
1. Una variable de tipo entero denomidada como "data", la cual contendrÃ¡ el elemento o información del nodo.
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
	/*El método insertar() servirá para meter información a los nodos. Éste recibe un entero denominado item. Primero se crea un nuevo puntero denominado "nuevo"
	de tipo nodo. Después se le pide al usuario que ingrese el número que contendrá el nodo y esta se almacena dentro de "nuevo y será igual a item"*/
	void insertar(int item)
	{
		nodo *nuevo = new nodo;
		nuevo->data = item;
	/*Si la lista aún no se ha creado, se procede a crear la cabeza de la lista. Esto se logra gracias a una condición:
	Si dato primero apunta a NULL (a nada) por ende la lista está vacía y se continúa con la inserción del primer dato.*/
	if(first == NULL)
	{
		first = nuevo; //el primer(first) nodo pasa a ser el "nuevo" nodo.
		first->next=NULL; //primero tiene un apuntador siguiente(next) a NULL porque es el primero y último en la lista.
		first->atras=NULL; //también tiene un apuntador hacia atrás que apunta a NULL por ser el primero y Ãºnico en la lista.
		//Tiene los dos apuntadores hacia NULL por ser doblemente enlazada.
		last = first; //Entonces al ser el único nodo se considera como el primero(first) y el último(last).

	}
	//En caso de que la cabeza o raÃ­z de la lista ya estÃ© insertada, se procede a almacenar los demás nodos.
	else
	{

		last->next=nuevo; //El último nodo apunta al nuevo nodo ingresado almancenado en "nuevo".
		nuevo->next=NULL; //El nuevo nodo apunta a NULL puesto que ahora es el último de la lista y no apunta a un nodo siguiente.
		nuevo->atras=last; //El puntero de atrás del nuevo nodo apunta al último nodo que antes era el primero o cabeza.
		last=nuevo; //el último nodo insertado pasa a ser el nuevo y más reciente nodo.

	}

	}
	/*El método mostrarDer imprimirá a partir de la cabeza de la lista hasta el final (first to last). Primero se crea un nuevo nodo llamado act de actual y éste se iguala al primer nodo
	de la lista.*/

	void mostrarDer()
	{
		nodo *act = new nodo;
		act = first; //Actual pasa a ser el primer elemento.
		if(first != NULL) //Si el primer elemento no apunta a NULL, se irán imprimiendo los elementos.
		{
			while(act) //Mientras que el nodo act sea diferente de NULL, el nodo act pasa a ser el actual siguiente para ir imprimiendo cada dato.
			{
				cout<<" "<<act->data;
				act=act->next;
			}
		}else
		{
			cout<<"Lista vacia! No hay nada que mostrar"<<endl;
		}
	}
	/*El método mostrarIzq imprimirá a partir de la cola de la lista hasta el principio (last to first). Primero se crea un nuevo nodo llamado act de actual y éste se iguala al último nodo
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
	//El método buscar servirá para buscar un elemento en específico de la lista, recibe como parámetro un entero llamado buscado que servirá en la busque de el elemento.
	void buscar(int buscado)
	{
		//Se declara un nuevo nodo actual act y éste se igual al primero first.
		nodo *act = new nodo;
		act = first;
		//la variable encontrado de tipo bool funcionará para cuando se encuentre el elemento solicitado.
		bool encontrado = false;


		//Con el siguiente método se recorrerá la lista hasta encontrar el dato solicitado. Si el primer elemento no es NULL, se procede a buscar el dato.
		if(first!=NULL)
		{
			//Mientras que el act no sea null y el encontrado aÃºn no sea true, se buscará el dato.
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
			cout<<"No se encontro nodo con esa informacion."<<endl;
		}
		}else //Si no se cumple nada de lo anterior, la lista esta vacía.
		{
			cout<<"Lista vacia!"<<endl;
		}
	}
	//El metodo eliminar servirá para eliminar un nodo con la información que éste contenga y recibirá un entero buscado para buscar el elemento a eliminar.
	void eliminar(int buscado)
	{
		//Se utiliza el mismo código de búsqueda para ir recorriendo la lista pero con algunas modificaciones.
		//Se declara un nuevo nodo actual act y éste se igual al primero first.
		nodo *act = new nodo;
		act = first;
		nodo *anterior = new nodo;
		anterior = NULL;
		//la variable encontrado de tipo bool funcionará para cuando se encuentre el elemento solicitado.
		bool encontrado = false;

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
			      	first = first->next; //El primer nodo apunta al siguiente del mismo, entonces el first serÃ¡ el siguiente next
			      	first->atras=NULL; //El nuevo primero no debe apuntar a nada mÃ¡s que a NULL.
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

int main ()
{
	ListaDoble ld; //Se crea una variable del mismo tipo de la clase para llamar a los métodos llamado ld.
	
	//La variable ld llama al método insertar.
	ld.insertar(1);
	ld.insertar(2);
	ld.insertar(3);
	ld.insertar(4);
	ld.insertar(5);
	ld.insertar(6);
	ld.insertar(7);
	ld.insertar(8);
	ld.insertar(9);
    cout<<endl;
    
    //ld.mostrar llama a los métodos para mostrarlos ya sea de izquierda a derecha o viceversa.
	ld.mostrarDer();
	cout<<endl;
	ld.mostrarIzq();
	cout<<endl;

    //insertar
	ld.insertar(10);
	ld.insertar(11);
	ld.insertar(13);

    //ld.eliminar llama al método eliminar.
	ld.eliminar(8);
	ld.eliminar(1);
	
	//ld.buscar busca el elemento solicitado
	ld.buscar(1);

	ld.mostrarDer();
	cout<<endl;
	ld.mostrarIzq();
	cout<<endl;
     
    cout<<endl;
	ld.buscar(0);
	ld.buscar(7);
	ld.buscar(8);
	ld.buscar(1);
}
