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
};
int main() //Funci�n principal main()
{
	ArbolBin AB; //Variable "AB" de la clase para poder llamar a los m�todos.
	int num, op; //Variables a utilizar dentro de la funci�n switch.
	do //Un ciclo do-while para repetir las opciones hasta que el usuario des�e salir.
	{
		cout<<"1.Insertar nodos \n2.Salir \nTu opcion es: "; //Opciones que el usuario puede escoger.
		cin>>op; //Su opci�n se guarda en la variable op.
		switch(op) //El switch funciona con la variable op.
		{
			case 1: //Si se selecciona la opci�n 1.Insertar nodos, se le pide al usuario que ingrese la info de dicho nodo y se guarda en la variable num.
				system("CLS");
				cout<<"Ingresa un numero: ";
				cin>>num;
				AB.insertar(arbol,num); //Se manda a llamar a la funci�n insertar(); implementada en la clase.
			break;
			case 2: 
            break;
			default: //En caso de que el usuario no seleccion� ninguna opci�n al ingresar un dato fuera del programa se le marcar� un error y �ste termina.
			cout<<"Error!";
		    return 0;
			break; 
		}
	}while(op!=2);
}
//Fin del programa.
