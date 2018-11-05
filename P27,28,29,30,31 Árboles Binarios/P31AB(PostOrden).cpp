/*LA DOCUMENTACI�N DEL PROGRAMA SE ENCUENTRA AQU� MISMO A MODO DE COMENTARIOS
�RBOLES BINARIOS*/

/*Se incluyen las librer�as necesarias para el programa: la librer�a iostream() para las operaciones de entrada cin() y de salida cout(). Y la librer�a stdlib.h para poder utilizar 
funciones como system("cls") para limpiar la pantalla. */
#include<iostream>
#include<stdlib.h>
using namespace std; //Funci�n para el uso de lenguaje est�ndar.
	//Se crea la estructura nodo de tipo struct.
	struct nodo
	{
	int dato; //De tipo entero el dato o informaci�n que contendr� el nodo.
	nodo *der; //Un puntero que apunte al lado derecho.
	nodo *izq; //Un puntero que apunte al lado izquierdo.
	};
nodo *arbol = NULL; //Un puntero de tipo nodo llamado arbol para llevar a cabo la estructura del mismo.

class ArbolBin //Clase ArbolBin donde se implementar�n los m�todos a utilizar.
{
	//En la secci�n p�blica se van a crear los m�todos.
	public:	
	nodo *crear(int n) //El primer m�todo es de tipo nodo y servir� para crear nuevos nodos.
	{
		nodo *nuevo = new nodo(); //Se crea un nuevo nodo denominado como "nuevo".
		nuevo->dato = n; //En el nodo "nuevo" apunta a dato y es donde "n" guardar� dicho dato proporcionado por el usuario.
		nuevo->der = NULL; //El puntero derecho (der) del nodo apunta a NULL puesto que apenas se insert� y a�n no tiene hijos de ese lado.
		nuevo->izq = NULL; //El puntero izquierdo (izq) del nodo apunta a NULL puesto que apenas se insert� y a�n no tiene hijos de ese lado.
		
		return nuevo;
	}
	void insertar(nodo *&arbol,int n) //El segundo m�todo ser� el de insertar nodos. �ste recibe a �rbol pasado por referencia porque cambiar� de valores y un entero n.
	{
		nodo *nuevo = new nodo(); //Se crea un nuevo nodo denominado como "nuevo".
		//Para insertar los nodos primero se deben verificar algunas condiciones.
		
		//Si el �rbol est� vac�o, o sea, es NULL, nuevo manda a llamar al m�todo "crear" recibiendo el valor "n" y arbol ahora ser� igual a nuevo. Este dato ser�a la ra�z.
		if(arbol == NULL)
		{
			nuevo=crear(n);
			arbol=nuevo;
		}else //Si el �rbol ya no est� vac�o y ya tiene la respectiva ra�z, se procede a insertar los hijos.
		{
			int raiz=arbol->dato; //Se crea un entero llamado "raiz" que ser� igual al �rbol apuntando a dato ingresado.
			if(n<raiz) //Si n es menor igual que la ra�z, este nodo pasar� a insertarse del lado izquierdo.
			{
				insertar(arbol->izq,n);
			}else //Sino, se inserta del lado derecho.
			{
				insertar(arbol->der,n);
			}
		}
	}
	//El siguiente m�todo ser� para mostrar el �rbol. NOTA: Este m�todo se busc� en internet porque no sab�a como hacerlo ni como usar el contador :)
	void mostrar(nodo *arbol, int c) //El m�todo mostrar recibe dos par�metros, el puntero arbol y un entero "c" por contador para dar espacios entre nodo y nodo.
	{
		if(arbol == NULL) //Primero se verifica si el �rbol est� vac�a, si es as�, simplemente se regresa el men� principal.
		{
			return;
		}else //Si el �rbol no est� vac�o se procede a mostrar los elementos de tal manera que primero se imprima el lado derecho. Se va imprimir de forma horizontal.
		{
			/*Para mostrar el �rbol por el lado derecho: llama a la funci�n mostrar() y �sta apunta a "der"
			y el contador "c" aumenta en 1. El bucle for servir� para separar espacios gracias al contador e ir
			imprimiendo los nodos.*/
			mostrar(arbol->der,c+1); 
			for(int i=0;i<c;i++)
			{
				cout<<" ";
			}
			cout<<arbol->dato<<endl; //Se imprime el dato del �rbol.
			mostrar(arbol->izq,c+1); //Ahora se imprime el lado izquierdo.
		}
	}
	/*El recorrido InOrden funciona de la siguiente manera:
	1.Visitar el sub�rbol izquierdo.
	2.Visitar la ra�z.
	3.Visitar el sub�rbol derecho.*/
	void InOrden(nodo *arbol)
	{
		//Si arbol es diferente de NULL, o sea, el �rbol no est� vacio se procede a imprimir los elementos del �rbol.
		if(arbol!=NULL)
		{
			InOrden(arbol->izq); //Se llama a la funci�n InOrden con arbol apuntando al lado izquierdo izq.
			cout<<arbol->dato<<" "; //Se imprime un espacio entre nodo y nodo y la raiz.
			InOrden(arbol->der); //Se llama a la funci�n InOrden con arbol apuntando al lado derecho der.
		}
	}
	/*El recorrido PreOrden funciona de la siguiente manera:
	1.Visitar la ra�z.
	2.Visitar el sub�rbol izquierdo.
	3.Visitar el sub�rbol derecho.*/
	void PreOrden(nodo *arbol)
	{   
	    //Si arbol es diferente de NULL, o sea, el �rbol no est� vaci� se procede a imprimir los elementos del �rbol en el respectivo orden.
	    if(arbol != NULL)
	    {    
		    cout<<arbol->dato<<" "; //Se imprime el espacio entre nodo y nodo y la raiz.
		    PreOrden(arbol->izq); //Se llama a la funci�n PreOrden con arbol apuntando al lado izquierdo izq.
		    PreOrden(arbol->der); //Se llama a la funci�n PreOrden con arbol apuntando al lado derecho der.
	    }
	}
	/*El recorrido PostOrden funciona de la siguiente manera:
	1.Visitar el sub�rbol izquierdo.
	2.Visitar el sub�rbol derecho.
	3.Visitar la ra�z.*/
	void PostOrden(nodo *arbol)
	{
		//Si arbol es diferente de NULL, o sea, el �rbol no est� vaci� se procede a imprimir los elementos del �rbol en el respectivo orden.
		if(arbol!=NULL)
		{
			PostOrden(arbol->izq); //Se llama a la funci�n PostOrden con arbol apuntando al lado izquierdo izq.
			PostOrden(arbol->der); //Se llama a la funci�n PreOrden con arbol apuntando al lado derecho der.
			cout<<arbol->dato<<" "; //Se imprime el espacio entre nodo y nodo y la raiz.
		}
	}
};
int main() //Funci�n principal main()
{
	ArbolBin AB; //Variable "AB" de la clase para poder llamar a los m�todos.
	int num, op, c=0; //Variables a utilizar dentro de la funci�n switch.
	do //Un ciclo do-while para repetir las opciones hasta que el usuario des�e salir.
	{
		cout<<"\n1.Insertar nodos \n2.Mostrar arbol \n3.Recorrido \n4.Salir \nTu opcion es: "; //Opciones que el usuario puede escoger.
		cin>>op; //Su opci�n se guarda en la variable op.
		switch(op) //El switch funciona con la variable op.
		{
			case 1: //Si se selecciona la opci�n 1.Insertar nodos, se le pide al usuario que ingrese la info de dicho nodo y se guarda en la variable num.
				system("CLS");
				cout<<"Ingresa un numero: ";
				cin>>num;
				AB.insertar(arbol,num); //Se manda a llamar a la funci�n insertar(); implementada en la clase.
			break; //Si se selecciona la opci�n 2.Mostrar arbol, se manda a llamar al m�todo mostrar() implementado en la clase.
			case 2: 
			    system("CLS");
			    cout<<"Arbol completo"<<endl;
			    cout<<"\n\n";
			    AB.mostrar(arbol,c);
            break;	
            case 3: //Si se escoge la opci�n 3, se despliega un nuevo submen� con opciones para recorrer los �rboles. La opci�n del usuario se guarda nuevamente en la variable op.
                system("CLS");
                //Las opciones de recorridos son 1.InOrden, 2.PreOrden y 3.PostOrden.
                cout<<"Escoge el tipo de recorrido a mostrar \n1.InOrden \n2.PreOrden \n3.PostOrden \nTu opcion es: "; 
                cin>>op;
                switch(op)
                {
                	case 1: //Si se selecciona la opci�n 1, se manda a llamar al m�todo InOrden() implementado en la clase.
                		system("CLS");
                		cout<<"Recorrido del arbol en InOrden"<<endl;
                		AB.InOrden(arbol);
                	break;
					case 2: //Si se selecciona la opci�n 2, se manda a llamar al m�todo PreOrden() implementado en la clase.
						system("CLS");
						cout<<"Recorrido del arbol en PreOrden"<<endl;
						AB.PreOrden(arbol);
					break;
					case 3: //Si se selecciona la opci�n 3, se manda a llamar al m�todo PostOrden() implementado en la clase.
						system("CLS");
						cout<<"Recorrido del arbol en PostOrden"<<endl;
						AB.PostOrden(arbol);
					break;
					default: //En caso de que el usuario no seleccion� ninguna opci�n al ingresar un dato fuera del programa se le marcar� un error y �ste termina.
			        cout<<"Error!";
		            return 0;
			        break;	
				}
			case 4:
			break;	
            break;	
			default: //En caso de que el usuario no seleccion� ninguna opci�n al ingresar un dato fuera del programa se le marcar� un error y �ste termina.
			cout<<"Error!";
		    return 0;
			break; 
		}
	}while(op!=4); 
}
//Fin del programa.
