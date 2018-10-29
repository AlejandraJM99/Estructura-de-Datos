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
		cout<<"Elemento "<<item<<" ingresado correctamente."<<endl;
	}
	/*El m�todo de recorrer permite mostrar la lista circular completa al usuario. Primero se implementa la condici�n de la lista vac�a si el ultimo elemento es igual a NULL. Si no 
	se cumple con la condici�n, se procede a crear el nuevo nodo "n" el cual ser� al ultimo accediendo a next. Para imprimir los nodos se implementa un ciclo while en el que mientras
	n sea diferente de ultimo se podr�n imprimir los nodos "next".*/
	void recorrer()
	{
	if (ultimo == NULL)
	{
	cout<<"Lista vacia! No hay nada que mostrar."<<endl;
	return;
    }
    nodo *n = new nodo;
    n = ultimo->next;
    cout<<"Los nodos de la lista circular son:  "<<endl;
    while (n!= ultimo)
    {

        cout<<n->data<<"->";
        n = n->next;
    }
    cout<<n->data<<endl;
	}
	/*El m�todo de buscar permite al usuario seleccionar un dato para ver su posici�n. Primero se implementa la condici�n de la cola vac�a cuando ultimo es NULL, si no se cumpla la 
	condici�n se procede a ejecutar el otro c�digo. Se crea un nuevo nodo y un contador, mientras que n sea diferente de �ltimo el contador aumenta para ir buscando las posiciones.
	n accede a next.*/
	void buscar(int item)
	{
		if (ultimo == NULL)
		{
		cout<<"Lista vacia! No hay nada que mostrar."<<endl;
		return;
		}
		nodo *n = new nodo;
		int contador = 0;
		n = ultimo->next;
		while (n!=ultimo)
		{
        contador++;
        if (n->data == item)    
        {
            cout<<"Elemento "<<item<<" en posicion "<<contador<<endl; 
            return;
        }
        n = n->next;
		}
		cout<<"Elemento "<<item<<" no encontrado."<<endl;
	}
	/*A continuaci�n se implementa el m�todo para eliminar nodos independientemente de la posici�n donde est�. Primero se declaran dos punteros a utilizar, n y s.*/
	void deleteNode(int item)
	{
		nodo *n, *s = new nodo;
		s = ultimo->next;
    /*Si solo hay un elemento en la lista, se implementa una condici�n la cual dice que si "ultimo" accediendo a next es igual al "ultimo" nodo y ultimo nodo es igual al �nico
	dato item introducido por el usuario, se considera a n como apuntando a NULL y se pasa a eliminar.*/
    if (ultimo->next == ultimo and ultimo->data == item)  
    {
        n = ultimo;
        ultimo = NULL;
        delete n;
        return;
    }
    /*Eliminar el primer nodo mediante una condici�n, si la variable s accediendo a la data del nodo es igual a item insertado por el usuario, se considera a n como s. ultimo accede
	a next y s accede a next como si fuera un �nico nodo. Se elimina n.*/
    if (s->data == item)  
    {
        n = s;
        ultimo->next = s->next;
        delete n;
        return;
    }
    while (s->next!=ultimo)
    {
	/*Eliminar cualquier otro elemento cuando s acceda a next y a su vez acceda a data del nodo. n y s ser�n iguales apuntando al nodo siguiente pasando del �ltimo nodo o el primero */
    if (s->next->data == item)    
    {
    n = s->next;
	s->next = n->next;
    delete n;
	cout<<"Elemento "<<item<<" eliminado."<<endl;
	return;
    }
    s = s->next;
    }
    /*Eliminar el �ltimo nodo cuando  next e item est�n accediendo a "ultimo"*/
    if (s->next->data == item)    
    {
	n = s->next;
	s->next = ultimo->next;
    delete n;		
	ultimo = s;
	return;
    } //Si no se cumple ninguna de las condiciones para eliminar, se procede a enviar un mensaje de que el elemento no fue encontrado.
    cout<<"Elemento "<<item<<" no encontrado."<<endl;
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
		cout<<"1.Crear/iniciar lista \n2.Insertar nodos \n3.Mostrar lista \n4.Buscar nodo \n5.Eliminar nodo \n6.Salir \nTu opcion es: "; //Se le presentan las opciones al usuario.
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
			case 3:  //La opci�n 3 muestra la lista completa al usuario llamando al m�todo recorrer() implementado en la clase.
			system("CLS");
			lc.recorrer();
			break;	
			case 4: //La opci�n 4 solicita al usuario ingresa el nodo a buscar para proporcionar su posici�n y al final se llama al m�todo buscar() implementado en la clase.
			system("CLS");	
			cout<<"Ingresa el dato a buscar: ";
			cin>>dato;	
			lc.buscar(dato);	
			break;
			case 5: //La opci�n 5 pide al usuario ingresar el nodo que desea eliminar y posteriormente se manda a llamar al m�todo deleteNode() implementado en la clase.
			cout<<"Elemento a eliminar: ";
			cin>>dato;
            lc.deleteNode(dato);
			break;	
			case 6: //La opci�n 6 termina el programa.
			break;	
			default: //En caso de que el usuario no seleccion� ninguna opci�n al ingresar un dato fuera del programa se le marcar� un error y �ste termina.
			cout<<"Error!";
		    return 0;
			break; 
		}	
	}while(op!=6);
	return 0;
}
//Fin del programa.
