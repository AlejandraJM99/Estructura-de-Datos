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
	//El siguiente método será para mostrar el árbol. NOTA: Este método se buscó en internet porque no sabía como hacerlo ni como usar el contador :)
	void mostrar(nodo *arbol, int c) //El método mostrar recibe dos parámetros, el puntero arbol y un entero "c" por contador para dar espacios entre nodo y nodo.
	{
		if(arbol == NULL) //Primero se verifica si el árbol está vacía, si es así, simplemente se regresa el menú principal.
		{
			return;
		}else //Si el árbol no está vacío se procede a mostrar los elementos de tal manera que primero se imprima el lado derecho. Se va imprimir de forma horizontal.
		{
			/*Para mostrar el árbol por el lado derecho: llama a la función mostrar() y ésta apunta a "der"
			y el contador "c" aumenta en 1. El bucle for servirá para separar espacios gracias al contador e ir
			imprimiendo los nodos.*/
			mostrar(arbol->der,c+1); 
			for(int i=0;i<c;i++)
			{
				cout<<" ";
			}
			cout<<arbol->dato<<endl; //Se imprime el dato del árbol.
			mostrar(arbol->izq,c+1); //Ahora se imprime el lado izquierdo.
		}
	}
	/*El recorrido InOrden funciona de la siguiente manera:
	1.Visitar el subárbol izquierdo.
	2.Visitar la raíz.
	3.Visitar el subárbol derecho.*/
	void InOrden(nodo *arbol)
	{
		//Si arbol es diferente de NULL, o sea, el árbol no está vacio se procede a imprimir los elementos del árbol.
		if(arbol!=NULL)
		{
			InOrden(arbol->izq); //Se llama a la función InOrden con arbol apuntando al lado izquierdo izq.
			cout<<arbol->dato<<" "; //Se imprime un espacio entre nodo y nodo y la raiz.
			InOrden(arbol->der); //Se llama a la función InOrden con arbol apuntando al lado derecho der.
		}
	}
	/*El recorrido PreOrden funciona de la siguiente manera:
	1.Visitar la raíz.
	2.Visitar el subárbol izquierdo.
	3.Visitar el subárbol derecho.*/
	void PreOrden(nodo *arbol)
	{   
	    //Si arbol es diferente de NULL, o sea, el árbol no está vació se procede a imprimir los elementos del árbol en el respectivo orden.
	    if(arbol != NULL)
	    {    
		    cout<<arbol->dato<<" "; //Se imprime el espacio entre nodo y nodo y la raiz.
		    PreOrden(arbol->izq); //Se llama a la función PreOrden con arbol apuntando al lado izquierdo izq.
		    PreOrden(arbol->der); //Se llama a la función PreOrden con arbol apuntando al lado derecho der.
	    }
	}
	/*El recorrido PostOrden funciona de la siguiente manera:
	1.Visitar el subárbol izquierdo.
	2.Visitar el subárbol derecho.
	3.Visitar la raíz.*/
	void PostOrden(nodo *arbol)
	{
		//Si arbol es diferente de NULL, o sea, el árbol no está vació se procede a imprimir los elementos del árbol en el respectivo orden.
		if(arbol!=NULL)
		{
			PostOrden(arbol->izq); //Se llama a la función PostOrden con arbol apuntando al lado izquierdo izq.
			PostOrden(arbol->der); //Se llama a la función PreOrden con arbol apuntando al lado derecho der.
			cout<<arbol->dato<<" "; //Se imprime el espacio entre nodo y nodo y la raiz.
		}
	}
};
int main() //Función principal main()
{
	ArbolBin AB; //Variable "AB" de la clase para poder llamar a los métodos.
	int num, op, c=0; //Variables a utilizar dentro de la función switch.
	do //Un ciclo do-while para repetir las opciones hasta que el usuario desée salir.
	{
		cout<<"\n1.Insertar nodos \n2.Mostrar arbol \n3.Recorrido \n4.Salir \nTu opcion es: "; //Opciones que el usuario puede escoger.
		cin>>op; //Su opción se guarda en la variable op.
		switch(op) //El switch funciona con la variable op.
		{
			case 1: //Si se selecciona la opción 1.Insertar nodos, se le pide al usuario que ingrese la info de dicho nodo y se guarda en la variable num.
				system("CLS");
				cout<<"Ingresa un numero: ";
				cin>>num;
				AB.insertar(arbol,num); //Se manda a llamar a la función insertar(); implementada en la clase.
			break; //Si se selecciona la opción 2.Mostrar arbol, se manda a llamar al método mostrar() implementado en la clase.
			case 2: 
			    system("CLS");
			    cout<<"Arbol completo"<<endl;
			    cout<<"\n\n";
			    AB.mostrar(arbol,c);
            break;	
            case 3: //Si se escoge la opción 3, se despliega un nuevo submenú con opciones para recorrer los árboles. La opción del usuario se guarda nuevamente en la variable op.
                system("CLS");
                //Las opciones de recorridos son 1.InOrden, 2.PreOrden y 3.PostOrden.
                cout<<"Escoge el tipo de recorrido a mostrar \n1.InOrden \n2.PreOrden \n3.PostOrden \nTu opcion es: "; 
                cin>>op;
                switch(op)
                {
                	case 1: //Si se selecciona la opción 1, se manda a llamar al método InOrden() implementado en la clase.
                		system("CLS");
                		cout<<"Recorrido del arbol en InOrden"<<endl;
                		AB.InOrden(arbol);
                	break;
					case 2: //Si se selecciona la opción 2, se manda a llamar al método PreOrden() implementado en la clase.
						system("CLS");
						cout<<"Recorrido del arbol en PreOrden"<<endl;
						AB.PreOrden(arbol);
					break;
					case 3: //Si se selecciona la opción 3, se manda a llamar al método PostOrden() implementado en la clase.
						system("CLS");
						cout<<"Recorrido del arbol en PostOrden"<<endl;
						AB.PostOrden(arbol);
					break;
					default: //En caso de que el usuario no seleccioné ninguna opción al ingresar un dato fuera del programa se le marcará un error y éste termina.
			        cout<<"Error!";
		            return 0;
			        break;	
				}
			case 4:
			break;	
            break;	
			default: //En caso de que el usuario no seleccioné ninguna opción al ingresar un dato fuera del programa se le marcará un error y éste termina.
			cout<<"Error!";
		    return 0;
			break; 
		}
	}while(op!=4); 
}
//Fin del programa.
