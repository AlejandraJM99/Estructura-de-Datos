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
		cout<<"Elemento "<<item<<" ingresado correctamente."<<endl;
	}
	/*El método de recorrer permite mostrar la lista circular completa al usuario. Primero se implementa la condición de la lista vacía si el ultimo elemento es igual a NULL. Si no 
	se cumple con la condición, se procede a crear el nuevo nodo "n" el cual será al ultimo accediendo a next. Para imprimir los nodos se implementa un ciclo while en el que mientras
	n sea diferente de ultimo se podrán imprimir los nodos "next".*/
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
	/*El método de buscar permite al usuario seleccionar un dato para ver su posición. Primero se implementa la condición de la cola vacía cuando ultimo es NULL, si no se cumpla la 
	condición se procede a ejecutar el otro código. Se crea un nuevo nodo y un contador, mientras que n sea diferente de último el contador aumenta para ir buscando las posiciones.
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
	/*A continuación se implementa el método para eliminar nodos independientemente de la posición donde esté. Primero se declaran dos punteros a utilizar, n y s.*/
	void deleteNode(int item)
	{
		nodo *n, *s = new nodo;
		s = ultimo->next;
    /*Si solo hay un elemento en la lista, se implementa una condición la cual dice que si "ultimo" accediendo a next es igual al "ultimo" nodo y ultimo nodo es igual al único
	dato item introducido por el usuario, se considera a n como apuntando a NULL y se pasa a eliminar.*/
    if (ultimo->next == ultimo and ultimo->data == item)  
    {
        n = ultimo;
        ultimo = NULL;
        delete n;
        return;
    }
    /*Eliminar el primer nodo mediante una condición, si la variable s accediendo a la data del nodo es igual a item insertado por el usuario, se considera a n como s. ultimo accede
	a next y s accede a next como si fuera un único nodo. Se elimina n.*/
    if (s->data == item)  
    {
        n = s;
        ultimo->next = s->next;
        delete n;
        return;
    }
    while (s->next!=ultimo)
    {
	/*Eliminar cualquier otro elemento cuando s acceda a next y a su vez acceda a data del nodo. n y s serán iguales apuntando al nodo siguiente pasando del último nodo o el primero */
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
    /*Eliminar el último nodo cuando  next e item estén accediendo a "ultimo"*/
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
/*En la función principal main() se crea un switch para llevar poder llamar a las funciones de la clase, a su vez se crea una variable del mismo tipo de la clase para llamar a 
los métodos, así como las variables para poder guardar las opciones del usuario.*/
int main()
{
	ListaC lc;
	int op, dato;
	do //El menú se puede repetir hasta que el usuario decida gracias al bucle do-while.
	{
		cout<<"1.Crear/iniciar lista \n2.Insertar nodos \n3.Mostrar lista \n4.Buscar nodo \n5.Eliminar nodo \n6.Salir \nTu opcion es: "; //Se le presentan las opciones al usuario.
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
			case 3:  //La opción 3 muestra la lista completa al usuario llamando al método recorrer() implementado en la clase.
			system("CLS");
			lc.recorrer();
			break;	
			case 4: //La opción 4 solicita al usuario ingresa el nodo a buscar para proporcionar su posición y al final se llama al método buscar() implementado en la clase.
			system("CLS");	
			cout<<"Ingresa el dato a buscar: ";
			cin>>dato;	
			lc.buscar(dato);	
			break;
			case 5: //La opción 5 pide al usuario ingresar el nodo que desea eliminar y posteriormente se manda a llamar al método deleteNode() implementado en la clase.
			cout<<"Elemento a eliminar: ";
			cin>>dato;
            lc.deleteNode(dato);
			break;	
			case 6: //La opción 6 termina el programa.
			break;	
			default: //En caso de que el usuario no seleccioné ninguna opción al ingresar un dato fuera del programa se le marcará un error y éste termina.
			cout<<"Error!";
		    return 0;
			break; 
		}	
	}while(op!=6);
	return 0;
}
//Fin del programa.
