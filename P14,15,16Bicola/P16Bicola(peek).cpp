/*LA DOCUMENTACI�N DEL PROGRAMA SE ENCUENTRA AQU� MISMO A MODO DE COMENTARIOS.
Se incluyen las librer�as necesarias: librer�a iostream para poder ingresar(cout) y leer(cin) datos;
librer�a stdlib para usar la funci�n system("cls") para limpiar la pantalla. Tambi�n se incluye el tama�o que tendr� la bicola.*/
#include<iostream>
#include<stdlib.h>
#define TAM 10
using namespace std; //para el uso de lenguaje est�ndar.

//Se crea la clase Bicola
class Bicola
{
	public:
	int bc[TAM]; //array que contiene el tama�o de la bicola.
	int front = 0; //variable front de la cola.
	int rear = 0; //variable rear de la cola.
	
	/*El m�todo insertarRear ser� para ingresar un elemento desde el final de la cola. �ste se lleva a cabo ya sea una bicola con entrada o salida restringida. 
	Si el front es igual a el tama�o de la bicola a la mitad, se considera que la bicola ya est� llena.*/
	void insertarRear(int item) 
	{
		if(front == TAM/2)
		{
			cout<<"Cola llena!"<<endl;
			return;
		}
		else //Si no, se pide al usuario que ingrese el elemento a la cola el cual se guarda en la variable item y se acomoda como front por ser el �nico elemento por el momento.
		{
			cout<<"Ingresa el elemento a la cola: ";
			cin>>item;
			bc[front] = item;
			front++;
		}
		cout<<"Elemento "<<item<<" insertado correctamente"<<endl;
	}
	/*El m�todo insertarFront ser� para ingresar un elemento desde el inicio de la cola. �ste se lleva a cabo ya sea una bicola con salida restringida. 
	Si el front es igual a el tama�o de la bicola a la mitad, se considera que la bicola ya est� llena.*/
	void insertarFront(int item)
	{
		if(front == TAM/2)
		{
			cout<<"Cola llena!"<<endl;
			return;
		}
		else //Si no, se pide al usuario que ingrese el elemento a la cola el cual se guarda en la variable item y se acomoda como rear por ser el �nico elemento por el momento y por el lado por el cual se ingres�..
		{
			cout<<"Ingresa el elemento a la cola: ";
			cin>>item;
			rear--;
			bc[rear] = item;
		}
		cout<<"Elemento "<<item<<" insertado correctamente"<<endl;
	}
	//El m�toddo eliminarFront ser� para eliminar un elemento por el frente de la cola. 
	int eliminarFront()
	{
    int deleted; //se crear una variable de eliminado.
    //Condici�n si front y rear son iguales, no hay elementos y la cola est� vac�a.
    if(front == rear)
    {
        cout<<"Bicola vac�a! No hay elementos que eliminar."<<endl;
        return 0;
    }
     //si no, pasa restarle -1 a rear para moverlo y se regresa el valor eliminado.
     rear++;
     deleted = bc[rear-1];
     return deleted;
	}
	//El m�toddo eliminarRear ser� para eliminar un elemento por el final de la cola. 
	int eliminarRear()
	{
    int deleted;
    //se crear una variable de eliminado.
    //Condici�n si front y rear son iguales, no hay elementos y la cola est� vac�a.
    if(front == rear)
    {
        cout<<"Bicola vac�a! No hay elementos que eliminar."<<endl;
        return 0;
     }
     //si no, pasa restarle +1 a front para moverlo y se regresa el valor eliminado.
     front--;
     deleted = bc[front+1];
     return deleted;
	}
	/*El m�todo de peekAll muestra todos los elementos de la bicola mediante un ciclo for.*/
	void peekAll()
	{
    if(front == rear)
    {
        cout<<"Bicola vac�a! No hay elementos que eliminar."<<endl;
        return;
     }else{
        cout<<"Los elementos de la bicola son: "<<endl;
        for(int i=rear; i < front; i++)
        {
          cout<<bc[i];
        }
		}
	}
	//El m�todo de peekFirst muestra la cabeza de la bicola.
	void peekFirst()
	{
	if(front == rear)
    {
        cout<<"Bicola vac�a! No hay elementos que eliminar."<<endl;
        return;
    }else{
    	cout<<"Frente de la bicola: "<<front;
	}
	}
	//El m�todo peekLaste muestra el final de la bicola.
	void peekLast()
	{
	if(front == rear)
    {
        cout<<"Bicola vac�a! No hay elementos que eliminar."<<endl;
        return;
    }else{
    	cout<<"Final de la bicola: "<<rear;
	}
	}
	//El m�todo peekIndex permite al usuario seleccionar una posici�n para buscar un dato.
	void peekIndex(int op)
	{
		if(op>TAM or op==-1)
		{
			cout<<"Posicion inexistenten"<<endl;
			return;
		}else
		{
			cout<<bc[op]<<endl;
		}
	}
};
int main() //En la funci�n principal main(), se crean las variables a utilizar y la variable de tipo Bicola para poder llamar a los m�todos de la clase.
{
	Bicola BC;
	int op1, op2, dato;
	do
	{
		//Primero se le muestra al usuario las opciones para escoger una bicola ya sea con entrada o con salida restringida y en ambas opciones se le desplegar� un submen�.
		cout<<"1.Bicola-entrada restringida \n2.Bicola-salida restringida \n3.Salir \nTu opcion es: ";
		cin>>op1;
		switch(op1)
		{
			//Bicola con entrada restringida.
		case 1: //Si escoge la opci�n 1 de entrada restringida, solamente podr� insertar elementos por el final de la cola pero podr� eliminar tanto por frente como por detr�s.
		system("CLS");	
		cout<<"1.Insertar final \n2.Eliminar \n3.Mostrar \n4.Volver al menu principal \nTu opcion es: ";
		cin>>op2;
		switch(op2)
		{
			case 1:
			system("CLS");	
			BC.insertarRear(dato); //Se llama al m�todo insertarRear() implementado en la clase y se ejecuta el m�todo.
			break;
			case 2://Si escoge la opci�n 2, se le desplegar� un nuevo submen� que muestra opciones que permiten eliminar por el inicio o por el final.
			cout<<"1.Eliminar por el final \n2.Eliminar por el inicio \nTu opcion es: ";
			cin>>op2;
			switch(op2)
			{
				case 1:
					system("CLS"); //La opci�n 1, llama al m�todo de eliminar por el final.
					cout<<"Elemento eliminado"<<endl;
					dato = BC.eliminarRear();
				break;
				case 2:
					system("CLS"); //La opci�n 2, llama al m�todo de eliminar por el frente.
					cout<<"Elemento eliminado"<<endl;
					dato = BC.eliminarFront();
				break;	
				default: //En caso de que el usuario no seleccion� ninguna opci�n al ingresar un dato fuera del programa se le marcar� un error y �ste termina.
			    cout<<"Error!";
			    return 0;
			    break; 
			}	
			break;
			case 3: //El caso 3 despliega un nuevo submen� donde puede escoger que elemento mostrar.
			system("CLS");	
			cout<<"1.Frente de la cola \n\n2.Final de la cola \n\n3.Todos los elementos de la cola \n\n4.Posicion especifica \n\n5.Volver al menu principal \n\nTu opcion es: ";
			cin>>op2;
			switch(op2)
			{
				case 1: //Si escoge la opci�n 1, se lleva a cabo el m�todo peekFirst() implementado en la clase.
				system("cls");	
				BC.peekFirst();
				break;
				case 2: //Si escoge la opci�n 2, se lleva a cabo el m�todo peeklast() implementado en la clase.
				system("cls");	
				BC.peekLast();
				break;
				case 3: //Si escoge la opci�n 3, se lleva a cabo el m�todo peekAll() implementado en la clase.
				system("CLS");	
				BC.peekAll();
				break;
				case 4: //Si escoge la opci�n 4, se lleva a cabo el m�todo peekIndex() implementado en la clase pidiendo al usuario escoja la posici�n.
				system("CLS");
				cout<<"Escoge la posicion del elemento que deseas ver ";
				cout<<"[0]-[1]-[2]-[3]-[4]-[5]-[6]-[7]"<<endl;
				cin>>dato;	
				BC.peekIndex(dato);
				break;
			}
			break;	
			case 4:
			return main(); //regresa al men� principal.
			break;	
			default: //En caso de que el usuario no seleccion� ninguna opci�n al ingresar un dato fuera del programa se le marcar� un error y �ste termina.
			cout<<"Error!";
			return 0;
			break; 		
		}
		break;
		    //Bicola con salida restringida.
		case 2: //Si escoge la opci�n 2 de salida restringida, podr� insertar elementos por el final y por el frente de la cola pero solo eliminar por el final.
		system("CLS");
		cout<<"1.Insertar final \n2.Insertar frente \n3.Eliminar \n4.Mostrar \n5.Volver al menu principal \nTu opcion es:  ";
		cin>>op2;
		switch(op2)
		{
			case 1: //La opci�n 1 le permite insertar por el final de la cola llamando al m�todo insertarRear() implementado en la clase.
			system("CLS");
			BC.insertarRear(dato);
			break;
			case 2: //La opci�n 2 le permite insertar elementos por el frente de la cola llamando al m�todo insertarFront() implementado en la clase.
			system("CLS");
			BC.insertarFront(dato);	
			break;
			case 3:
			system("CLS");
			cout<<"Elemento eliminado"<<endl; //La opci�n 3, llama al m�todo de eliminar por el final.
			dato = BC.eliminarRear();
			break;	
			case 4: //el caso 4 despliega un nuevo submen� donde puede escoger que elemento mostrar.
			system("CLS");	
			cout<<"1.Frente de la cola \n\n2.Final de la cola \n\n3.Todos los elementos de la cola \n\n4.Posicion especifica \n\n5.Volver al menu principal \n\nTu opcion es: ";
			cin>>op2;
			switch(op2)
			{
				case 1: //Si escoge la opci�n 1, se lleva a cabo el m�todo peekFirst() implementado en la clase.
				system("cls");	
				BC.peekFirst();
				break;
				case 2: //Si escoge la opci�n 2, se lleva a cabo el m�todo peeklast() implementado en la clase.
				system("cls");	
				BC.peekLast();
				break;
				case 3: //Si escoge la opci�n 3, se lleva a cabo el m�todo peekAll() implementado en la clase.
				system("CLS");	
				BC.peekAll();
				break;
				case 4: //Si escoge la opci�n 4, se lleva a cabo el m�todo peekIndex() implementado en la clase pidiendo al usuario escoja la posici�n.
				system("CLS");
				cout<<"Escoge la posicion del elemento que deseas ver ";
				cout<<"[0]-[1]-[2]-[3]-[4]-[5]-[6]-[7]"<<endl;
				cin>>dato;	
				BC.peekIndex(dato);
				break;
			}
			break;	
			case 5: //regresa al men� principal.
			system("CLS");	
			return main();	
			break;	
			default: //En caso de que el usuario no seleccion� ninguna opci�n al ingresar un dato fuera del programa se le marcar� un error y �ste termina.
			cout<<"Error!";
			return 0;
			break; 
		}
		break;	
		case 3: //termina el programa.
		break;
		default: //En caso de que el usuario no seleccion� ninguna opci�n al ingresar un dato fuera del programa se le marcar� un error y �ste termina.
		cout<<"Error!";
		return 0;
		break; 
		}
	}while(op1!=3);
	return 0;
}
//Fin del programa.
