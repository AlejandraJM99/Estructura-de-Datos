/*LA DOCUMENTACI�N DEL PROGRAMA SE ENCUENTRA AQU� MISMO A MODO DE COMENTARIOS.

LISTA DOBLEMENTE ENLAZADA
Se incluyen las librer�as necesarias: librer�a iostream para poder ingresar(cout) y leer(cin) datos; 
librer�a stdlib para usar la funci�n system("cls") para limpiar la pantalla. Y la librer�a conio.h para poder usar estructuras (struct)*/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std; //Para hacer uso del lenguaje est�ndar.

/*Se crea la estructura nodo que contendr�: 
1. Una variable de tipo entero denomidada como "data", la cual contendr� el elemento o informaci�n del nodo.
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
	//En la secci�n privada de la clase, se crean dos punteros denominados first(primero) y last(ultimo)
	private:
		nodo *first;
		nodo *last;
	//En la secci�n p�blica se crean los m�todos a utilizar y se inicializan los punteros en NULL.	
	public:	
	ListaDoble()
	{
		first = NULL;
		last = NULL; 
	}
	/*El m�todo insertar() servir� para meter informaci�n a los nodos. Primero se crea un nuevo puntero denominado "nuevo"
	de tipo nodo. Despu�s se le pide al usuario que ingrese el n�mero que contendr� el nodo y �sta se almacena dentro de "nuevo"*/
	void insertar()
	{
		nodo *nuevo = new nodo;
		cout<<"Ingresa la info. que contendra el nodo: ";
		cin>>nuevo->data;
	/*Si la lista a�n no se ha creado, se procede a crear la cabeza de la lista. Esto se logra gracias a una condici�n:
	Si dato primero apunta a NULL (a nada) por ende la lista est� vac�a y se contin�a con la inserci�n del primer dato.*/
	if(first == NULL)
	{
		first = nuevo; //el primer(first) nodo pasa a ser el "nuevo" nodo.
		first->next=NULL; //primero tiene un apuntador siguiente(next) a NULL porque es el primero y �nico en la lista.
		first->atras=NULL; //tambi�n tiene un apuntador hacia atr�s(atr�s) que apunta a NULL por ser el primero y �nico en la lista.
		//Tiene los dos apuntadores hacia NULL por ser doblemente enlazada.
		last = first; //Entonces al ser el �nico nodo se considera como el primero(first) y el �ltimo(last).
	}
	//En caso de que la cabeza o ra�z de la lista ya est� insertada, se procede a almacenar los dem�s nodos.
	else
	{
		last->next=nuevo; //El �ltimo nodo apunta al nuevo nodo ingresado almancenado en "nuevo".
		nuevo->next=NULL; //El nuevo nodo apunta a NULL puesto que ahora es el �ltimo de la lista y no apunta a un nodo siguiente.
		nuevo->atras=last; //El puntero de atr�s del nuevo nodo apunta al �ltimo nodo que antes era el primero o cabeza.
		last=nuevo; //el �ltimo nodo insertado pasa a ser el nuevo y m�s reciente nodo.
	}
	cout<<"Nodo insertado correctamente!"<<endl;
	}	
	/*El m�todo mostrarDer imprimir� a partir de la cabeza de la lista hasta el final (first to last). Primero se crea un nuevo nodo llamado act de actual y �ste se iguala al primer nodo
	de la lista.*/
	void mostrarDer()
	{
		nodo *act = new nodo;
		act = first; //Actual pasa a ser el primer elemento.
		if(first != NULL) //Si el primer elemento no apunta a NULL, se ir�n imprimiendo los elementos.
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
	/*El m�todo mostrarIzq imprimir� a partir de la cola de la lista hasta el principio (last to firstt). Primero se crea un nuevo nodo llamado act de actual y �ste se iguala al �ltimo nodo
	de la lista.*/
	void mostrarIzq()
	{
		nodo *act = new nodo;
		act = last; //Actual pasa a ser el �ltimo elemento.
		if(first != NULL) //Si el primer elemento no apunta a NULL, se ir�n imprimiendo los elementos.
		{
			while(act!=NULL) //Mientras que el nodo act sea diferente de NULL, el nodo act pasa a ser el actual de atr�s para ir imprimiendo cada dato.
			{
				cout<<" "<<act->data;
				act=act->atras;
			}
		}else
		{
			cout<<"Lista vacia! No hay nada que mostrar"<<endl;
		}
	}
	//El m�todo buscar servir� para buscar un elemento en espec�fico de la lista preguntando al usuario.
	void buscar()
	{
		//Se declara un nuevo nodo actual act y �ste se igual al primero first.
		nodo *act = new nodo;
		act = first;
		//la variable encontrado de tipo bool funcionar� para cuando se encuentre el elemento solicitado.
		bool encontrado = false;
		int buscado = 0; //una variable de tipo entero llamado buscado igual a cero que ser� proporcionado por el usuario.
		cout<<"Ingresa el dato del nodo que buscas: ";
		cin>>buscado;
		//Con el siguiente m�todo se recorrer� la lista hasta encontrar el dato solicitado. Si el primer elemento no es NULL, se procede a buscar el dato.
		if(first!=NULL)
		{
			//Mientras que el act no sea null y el encontrado a�n no sea true, se buscar� el dato.
			while(act!=NULL and encontrado!=true)
			{
				//Si actual es igual a buscado, la variable encontrado pasa a ser true y el ciclo termina.
				if(act->data == buscado)
				{
				cout<<"La informacion "<<buscado<<" se ha encontrado en un nodo."<<endl;
				encontrado = true;
				} 
				act = act->next; //El nodo actual apunta a siguiente next para ir recorriendo y "visitando" cada nodo para encontrar la informaci�n solicitado.
			}
		if(!encontrado) //Si el dato proporcionado es diferente de encontrado, se informa que el dato no se encontr�.
		{
			cout<<"No se encontre nodo con esa informacion."<<endl;
		}
		}else //Si no se cumple nada de lo anterior, la lista est� vac�a.
		{
			cout<<"Lista vacia!"<<endl;
		}		
	}
	//El m�todo eliminar servir� para eliminar un nodo con la informaci�n que �ste contenga y ser� proporcionada por el usuario.
	void eliminar()
	{
		//Se utiliza el mismo c�digo de b�squeda para ir recorriendo la lista pero con algunas modificaciones.
		//Se declara un nuevo nodo actual act y �ste se igual al primero first.
		nodo *act = new nodo;
		act = first;
		nodo *anterior = new nodo;
		anterior = NULL;
		//la variable encontrado de tipo bool funcionar� para cuando se encuentre el elemento solicitado.
		bool encontrado = false;
		int buscado = 0; //una variable de tipo entero llamado buscado igual a cero que ser� proporcionado por el usuario.
		cout<<"Ingresa el dato del nodo a eliminar: ";
		cin>>buscado;
		//Con el siguiente m�todo se recorrer� la lista hasta encontrar el dato solicitado. Si el primer elemento no es NULL, se procede a buscar el dato.
		if(first!=NULL)
		{
			//Mientras que el act no sea null y el encontrado a�n no sea true, se buscar� el dato.
			while(act!=NULL and encontrado!=true)
			{
				//Si actual es igual a buscado, la variable encontrado pasa a ser true.
				if(act->data == buscado)
				{
				cout<<"La informacion "<<buscado<<" se ha encontrado en un nodo."<<endl;
				/*La primera condici�n funciona para eliminar la cabeza o ra�z de la lista. Si act igresado por el usuario
				es igual al primer nodo. */
			    if(act==first)
			    {
			      	first = first->next; //El primer nodo apunta al siguiente del mismo, entonces el first ser� el siguiente next
			      	first->atras=NULL; //El nuevo primero no debe apuntar a nada m�s que a NULL.
				}
				/*La segunda condici�n es para eliminar el �ltimo nodo de la lista. Esto se cumpla si el nodo act ingresado por el usuario
				es igual al �ltimo nodo de la lista.*/
				else if(act==last)
				{
					anterior->next=NULL; //El anterior siguiente del �ltimo nodo debe apuntar a NULL.
					last = anterior; //Se actualiza que el �ltimo dato ser� ahora el anterior.
				}
				//Para eliminar un nodo que no sea ni el primero ni el segundo.
				else
				{
					//no se debe apuntar al nodo que se desea eliminar para poder eliminarlo.
					anterior->next=act->next; //anterior siguiente debe hacer lo mismo que actual siguiente.
					act->next->atras = anterior; //se pasa a apuntar despu�s del nodo que se quiere eliminar y sale de la lista.
				} 
				cout<<"Nodo eliminado correctamente."<<endl;
				encontrado = true;
				} 
				anterior = act; //anterior har� lo mismo que haga act.
				act = act->next; //El nodo actual apunta a siguiente next para ir recorriendo y "visitando" cada nodo para encontrar la informaci�n solicitado.
			}
		if(!encontrado) //Si el dato proporcionado es diferente de encontrado, se informa que el dato no se encontr�.
		{
			cout<<"No se encontre nodo con esa informacion."<<endl;
		}
		}else //Si no se cumple nada de lo anterior, la lista est� vac�a.
		{
			cout<<"Lista vacia!"<<endl;
		}		
	}
};
//En la funci�n principal main() se mandar�n  llamar a los m�todos de la clase.
int main()
{ 
    //Se crean las variables a utilizar para almacenar respuestas y para llamar a los m�todos.
	int op;
	ListaDoble ld;
	do //Se repetir� hasta que el usuario des�e gracias al ciclo do-while.
	{
		cout<<"\n1.Insertar nodos. \n2.Mostrar lista \n3.Buscar nodo \n4.Eliminar nodo \n5.Salir \nTu opcion es: "; //Se le despliega un men� de opciones y su opci�n se guardar� en la variable op.
		cin>>op;
		switch(op)
		{
			case 1: //Si el usuario selecciona la opci�n 1.Insertar nodos, se llama al m�todo insertar() implementado en la clase.
			system("CLS");
			ld.insertar();	
			break;
			case 2: //Si el usuario selecciona la opci�n 2.Mostrar lista, se le desplegar� un submen� en el cual tendr� tres opciones.
			system("CLS");
			cout<<"1.Mostrar derecha->izquierda \n2.Mostrar derecha<-izquierda \n3.Volver al menu principal \nTu opcion es: ";
			cin>>op;
			switch(op)
			{
				case 1: //Si selecciona la opci�n 1, muestra la lista del lado derecho llamando mostrarDer().
				system("CLS");
				ld.mostrarDer();
				break;
				case 2: //Si selecciona la opci�n 2, muestra la lista del lado izquierdo llamando mostrarIzq().
				system("CLS");
				ld.mostrarIzq();
				break;
				case 3: //Si se selecciona la opci�n 3, se regresa al men� principal.
				system("CLS");
				return main();
				break;	
				default: //En caso de que el usuario no seleccion� ninguna opci�n al ingresar un dato fuera del programa se le marcar� un error y �ste termina.
				cout<<"Error!";
				return 0;
				break; 		
			}
			break;	
			case 3: //Si se selecciona la opci�n 3.Buscar, se llama al m�todo buscar() implementado en la clase y se ejecuta.
			system("cls");	
			ld.buscar();	
			break;
			case 4:  //Si se selecciona la opci�n 4, se llama al m�todo eliminar() implementado en la clase y se ejecuta.
			system("CLS");
			ld.eliminar();
			break;	
			case 5: //Si se selecciona la opci�n 5 el programa termina.
			break;	
			default: //En caso de que el usuario no seleccion� ninguna opci�n al ingresar un dato fuera del programa se le marcar� un error y �ste termina.
		    cout<<"Error!";
	    	return 0;
            break; 	
		}
	}while(op!=5);
}
//Fin del programa.
