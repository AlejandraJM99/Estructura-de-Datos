/*LA DOCUMENTACIÓN DEL PROGRAMA SE ENCUENTRA AQUÍ MISMO A MODO DE COMENTARIOS.

Se incluyen las librerías necesarias: librería iostream para poder ingresar(cout) y leer(cin) datos; 
librería stdlib para usar la función system("cls") para limpiar la pantalla. Y la librería stdio.h para poder usar estructuras (struct)*/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;//para el uso de lenguaje estándar.
class Lista //A continuación se crea la clase Lista que incluirá la estructura del nodo y los respectivos métodos.
{
	private: //de forma privada se crear la estructura del nodo
		struct nodo //estructura nodo.
		{
			int dato; //dato por el usuario.
			nodo *next; //puntero para anotar al siguiente nodo.
		};
	//se crean punteros del mismo tipo de la estructura nodo
		nodo*raiz=NULL; //raíz de la lista.
		nodo*temp=NULL; //nodo temporal.
		nodo*act=NULL; //nodo actual.

	public: //en la sección pública se declaran las funciones a implementar.
	void agregar(int item) //1er método para agregar los elementos
	{
		/*Para poder agregar elementos es necesario crear un nuevo nodo y el puntero n que será el encargado de apuntar al enlace sigueinte y al dato introducido.*/
		nodo *n = new nodo;
		n->next = NULL;
		n->dato = item;

		if(raiz!=NULL) //Para agregar la raíz, se debe verificar que esté vacía, si es así, el nodo actual (añadido recientemente) pasa a ser la raíz.
		{
			act = raiz;
			while(act->next != NULL) //Mientras que el nodo actual apuntando al siguiente sea diferente de vacío, el nodo actual ligará apuntando al siguiente para ir almacenando los datos.
			{
				act = act->next;
			}
			act->next = n;
		}else
		{
			raiz = n;
		}
		return;
	}
	void mostrar() //2do método para imprimir la lista en pantalla.
	{
		act = raiz; //el dato más actual será la raíz.
		while(act != NULL) //Y mientras el dato no sea igual NULL o esté vacío, se imprime cada dato de la lista.
		{
			cout<<act->dato<<endl;
			act = act->next;
		}
	}
};
//Dentro de la función principal main, se declaran las variables a utilizar dentro de un menú switch y una variable de tipo Lista para poder llamar a los métodos.
int main()
{
	int dato,op;
	Lista list1;
	do{ //Dentro de un método do-while, se lleva a cabo un switch para poder mostrar al usuario las opciones del programa y terminar hasta que él decida. 1.Agregar 2.Mostrar 3.Salir del programa. Su opc se guarda en la variable op.
	cout<<"1.Insertar dato \n2.Mostrar \n3.Salir"<<endl;
	cout<<"Tu opcion es: ";
	cin>>op;

		switch(op) //la función switch funciona con la elección del usuario.
		{
			case 1: //si el usuario seleeciona 1.Insertar dato, se le pedirá agregar un elemento que se guardará en la variable aux. dato y simplemente manda a llamar al método de agregar implementado en la clase
			system("cls");
			cout<<"Ingresa un elemento a la lista: ";
			cin>>dato;
			list1.agregar(dato);
			cout<<"Elemento "<<dato<<" agregado a la lista"<<endl; //se imprime en pantalla una confirmación de que el elemento se ingresó correctamente.
			break;
			case 2: //si el usuario selecciona 2.Mostrar, se manda a llamar al método de mostrar() implementado en la clase Lista y posteriormente se imprimen todos los datos de la lista.
            system("cls");
            cout<<"Los elementos de la lista son: "<<endl;
			list1.mostrar();
			cout<<"Presiona cualquier tecla para regresar"<<endl;
			getch();
			system("CLS");
			return main();
			break;
			case 3: //si el usuario selecciona la opción 3.Salir, el programa termina.
			break;
		}
	}while(op!=3);
	return 0;
}
//Fin del programa.
