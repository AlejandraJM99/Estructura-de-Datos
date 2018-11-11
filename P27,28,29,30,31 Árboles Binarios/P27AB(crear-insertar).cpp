/*LA DOCUMENTACIÓN DEL PROGRAMA SE ENCUENTRA AQUÍ MISMO A MODO DE COMENTARIOS
ÁRBOLES BINARIOS*/

/*Se incluyen las librerías necesarias para el programa: la librería iostream() para las operaciones de entrada cin() y de salida cout(). Y la librería stdlib.h para poder utilizar 
funciones como system("cls") para limpiar la pantalla. */
#include<iostream>
#include<stdlib.h>
using namespace std; //Función para el uso de lenguaje estándar.
	//Se crea la estructura nodo de tipo struct.
	struct nodo
	{
	int dato; //De tipo entero el dato o información que contendrá el nodo.
	nodo *der; //Un puntero que apunte al lado derecho.
	nodo *izq; //Un puntero que apunte al lado izquierdo.
	};
nodo *arbol = NULL; //Un puntero de tipo nodo llamado arbol para llevar a cabo la estructura del mismo.

class ArbolBin //Clase ArbolBin donde se implementarán los métodos a utilizar.
{
	//En la sección pública se van a crear los métodos.
	public:	
	nodo *crear(int n) //El primer método es de tipo nodo y servirá para crear nuevos nodos.
	{
		nodo *nuevo = new nodo(); //Se crea un nuevo nodo denominado como "nuevo".
		nuevo->dato = n; //En el nodo "nuevo" apunta a dato y es donde "n" guardará dicho dato proporcionado por el usuario.
		nuevo->der = NULL; //El puntero derecho (der) del nodo apunta a NULL puesto que apenas se insertó y aún no tiene hijos de ese lado.
		nuevo->izq = NULL; //El puntero izquierdo (izq) del nodo apunta a NULL puesto que apenas se insertó y aún no tiene hijos de ese lado.
		
		return nuevo;
	}
	void insertar(nodo *&arbol,int n) //El segundo método será el de insertar nodos. Éste recibe a árbol pasado por referencia porque cambiará de valores y un entero n.
	{
		nodo *nuevo = new nodo(); //Se crea un nuevo nodo denominado como "nuevo".
		//Para insertar los nodos primero se deben verificar algunas condiciones.
		
		//Si el árbol está vacío, o sea, es NULL, nuevo manda a llamar al método "crear" recibiendo el valor "n" y arbol ahora será igual a nuevo. Este dato sería la raíz.
		if(arbol == NULL)
		{
			nuevo=crear(n);
			arbol=nuevo;
		}else //Si el árbol ya no está vacío y ya tiene la respectiva raíz, se procede a insertar los hijos.
		{
			int raiz=arbol->dato; //Se crea un entero llamado "raiz" que será igual al árbol apuntando a dato ingresado.
			if(n<raiz) //Si n es menor igual que la raíz, este nodo pasará a insertarse del lado izquierdo.
			{
				insertar(arbol->izq,n);
			}else //Sino, se inserta del lado derecho.
			{
				insertar(arbol->der,n);
			}
		}
	}
};
int main() //Función principal main()
{
	ArbolBin AB; //Variable "AB" de la clase para poder llamar a los métodos.
	int num, op; //Variables a utilizar dentro de la función switch.
	do //Un ciclo do-while para repetir las opciones hasta que el usuario desée salir.
	{
		cout<<"1.Insertar nodos \n2.Salir \nTu opcion es: "; //Opciones que el usuario puede escoger.
		cin>>op; //Su opción se guarda en la variable op.
		switch(op) //El switch funciona con la variable op.
		{
			case 1: //Si se selecciona la opción 1.Insertar nodos, se le pide al usuario que ingrese la info de dicho nodo y se guarda en la variable num.
				system("CLS");
				cout<<"Ingresa un numero: ";
				cin>>num;
				AB.insertar(arbol,num); //Se manda a llamar a la función insertar(); implementada en la clase.
			break;
			case 2: 
            break;
			default: //En caso de que el usuario no seleccioné ninguna opción al ingresar un dato fuera del programa se le marcará un error y éste termina.
			cout<<"Error!";
		    return 0;
			break; 
		}
	}while(op!=2);
}
//Fin del programa.
