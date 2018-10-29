/*LA DOCUMENTACIÓN DEL PROGRAMA SE ENCUENTRA AQUÍ MISMO A MODO DE COMENTARIOS.
Se incluyen las librerías necesarias: librería iostream para poder ingresar(cout) y leer(cin) datos;
librería stdlib para usar la función system("cls") para limpiar la pantalla. También se incluye el tamaño que tendrá la bicola.*/
#include<iostream>
#include<stdlib.h>
#define TAM 10
using namespace std; //para el uso de lenguaje estándar.

//Se crea la clase Bicola
class Bicola
{
	public:
	int bc[TAM]; //array que contiene el tamaño de la bicola.
	int front = 0; //variable front de la cola.
	int rear = 0; //variable rear de la cola.
	
	/*El método insertarRear será para ingresar un elemento desde el final de la cola. Éste se lleva a cabo ya sea una bicola con entrada o salida restringida. 
	Si el front es igual a el tamaño de la bicola a la mitad, se considera que la bicola ya está llena.*/
	void insertarRear(int item) 
	{
		if(front == TAM/2)
		{
			cout<<"Cola llena!"<<endl;
			return;
		}
		else //Si no, se pide al usuario que ingrese el elemento a la cola el cual se guarda en la variable item y se acomoda como front por ser el único elemento por el momento.
		{
			cout<<"Ingresa el elemento a la cola: ";
			cin>>item;
			bc[front] = item;
			front++;
		}
		cout<<"Elemento "<<item<<" insertado correctamente"<<endl;
	}
	/*El método insertarFront será para ingresar un elemento desde el inicio de la cola. Éste se lleva a cabo ya sea una bicola con salida restringida. 
	Si el front es igual a el tamaño de la bicola a la mitad, se considera que la bicola ya está llena.*/
	void insertarFront(int item)
	{
		if(front == TAM/2)
		{
			cout<<"Cola llena!"<<endl;
			return;
		}
		else //Si no, se pide al usuario que ingrese el elemento a la cola el cual se guarda en la variable item y se acomoda como rear por ser el único elemento por el momento y por el lado por el cual se ingresó..
		{
			cout<<"Ingresa el elemento a la cola: ";
			cin>>item;
			rear--;
			bc[rear] = item;
		}
		cout<<"Elemento "<<item<<" insertado correctamente"<<endl;
	}
};
int main() //En la función principal main(), se crean las variables a utilizar y la variable de tipo Bicola para poder llamar a los métodos de la clase.
{
	Bicola BC;
	int op1, op2, dato;
	do
	{
		//Primero se le muestra al usuario las opciones para escoger una bicola ya sea con entrada o con salida restringida y en ambas opciones se le desplegará un submenú.
		cout<<"1.Bicola-entrada restringida \n2.Bicola-salida restringida \n3.Salir \nTu opcion es: ";
		cin>>op1;
		switch(op1)
		{
		case 1: //Si escoge la opción 1 de entrada restringida, solamente podrá insertar elementos por el final de la cola.
		system("CLS");	
		cout<<"1.Insertar final \n2.Volver al menu principal \nTu opcion es: ";
		cin>>op2;
		switch(op2)
		{
			case 1:
			system("CLS");	
			BC.insertarRear(dato); //Se llama al método insertarRear() implementado en la clase y se ejecuta el método.
			break;	
			case 2:
			return main(); //regresa al menú principal.
			break;	
			default: //En caso de que el usuario no seleccioné ninguna opción al ingresar un dato fuera del programa se le marcará un error y éste termina.
			cout<<"Error!";
			return 0;
			break; 		
		}
		break;
		case 2: //Si escoge la opción 2 de salida restringida, podrá insertar elementos por el final y por el frente de la cola.
		system("CLS");
		cout<<"1.Insertar final \n2.Insertar frente \n3.Volver al menu principal \nTu opcion es:  ";
		cin>>op2;
		switch(op2)
		{
			case 1: //La opción 1 le permite insertar por el final de la cola llamando al método insertarRear() implementado en la clase.
			system("CLS");
			BC.insertarRear(dato);
			break;
			case 2: //La opción 2 le permite insertar elementos por el frente de la cola llamando al método insertarFront() implementado en la clase.
			system("CLS");
			BC.insertarFront(dato);	
			break;
			case 3: //regresa al menú principal.
			system("CLS");	
			return main();	
			break;	
			default: //En caso de que el usuario no seleccioné ninguna opción al ingresar un dato fuera del programa se le marcará un error y éste termina.
			cout<<"Error!";
			return 0;
			break; 
		}
		break;	
		case 3: //termina el programa.
		break;
		default: //En caso de que el usuario no seleccioné ninguna opción al ingresar un dato fuera del programa se le marcará un error y éste termina.
		cout<<"Error!";
		return 0;
		break; 
		}
	}while(op1!=3);
	return 0;
}


