/*LA DOCUMENTACI�N DEL PROGRAMA SE ENCUENTRA AQU� MISMO A MODO DE COMENTARIOS.

Se incluyen las librer�as necesarias: librer�a iostream para poder ingresar(cout) y leer(cin) datos; 
librer�a stdlib para usar la funci�n system("cls") para limpiar la pantalla, y la librer�a conio.h para poder utilizar la funci�n getch() que pausa el programa
para poder ver el resultado de la ejecuci�n.*/
#include <iostream>
#include<stdlib.h>
#include<conio.h>
#define max 5 //se define el tama�o m�ximo que tendr� el arreglo(cola)
using namespace std; //para el uso de lenguaje est�ndar

/*Se crea la clase Cola donde se declara un array de tipo entero con el tama�o m�ximo defindo anteriormente.
Despu�s, se declaran dos variables para referirse al final y frente de la cola, ambas inicializadas en cero.
Posteriormente, se comienzan a implementar los dos m�todos a utilizar de manera p�blica.*/
class Cola
{
	int cola[max];
	int final=0, frente=0;
	public:
	void create()
	{
		int cola[max]={0}; //El m�todo create() funcionar� para crear la cola e inicializarla en ceros.
	}
	/*El m�todo encolar ser� para ingresar los elementos al arreglo. �ste recibe un entero denominado item(ingresado por el usuario)
	Para evitar un overflow, se debe crear una condici�n la cual si se cumple, detendr� el programa: Si el final de la cola, ya es igual al m�ximo del final, se debe lanzar
	un mensaje, de que la cola ya est� llena y no se pueden ingresar m�s elementos, esto con el prop�sito de evitar un desbordamiento.
	Si la condici�n a�n no se cumple, se ejecuta el m�todo para ingresar los elementos, de tal manera que el final de cola aumenta porque se est�n ingresando los elementos.
	Finalmente, se imprime en pantalla un mensaje para mostrar al usuario que su item se introdujo correctamente. */
	void encolar(int item)
	{
		if(final==max)
		{
        system("CLS");
        cout<<"Cola llena!! No puedes agregar mas elementos."<<endl;
        return;
		}
		cola[final++]=item;
        cout<<"Elemento ingresado: "<<item<<endl;
	}
	/*El siguiente m�todo, ser� para imprimir en pantalla todos los elementos de la cola en el orden en que fueron ingresados siguiendo el orden FIFO.
	Cumple con la misma condici�n para evitar un underflow en caso de querer mostrar elementos si �sta est� vac�a. Finalmente, mediante un ciclo for, imprime cada uno de
	los datos de la cola y su respectiva posici�n.*/
	void peekAll() 
	{
		if(frente==final)
		{
			system("CLS");
			cout<<"Cola vacia!! No hay elementos."<<endl;
			return;
		}
		for(int i=frente;i<final;i++)
		{
			cout<<"Posicion: "<<i<<" Elemento: "<<cola[i]<<endl;
		}
	}
	/*El m�todo de userpeek ser� para que el usuario seleccione una posici�n de la cola. Cuenta con la condici�n para no mostrar elementos cuando no hay elementos en la pila
	y para no mostrar elementos cuando la posici�n est� fuera del arreglo de la cola. Si la condici�n no se cumple, se procede a ejecutar el m�todo que muestra
	el n�mero de posici�n que escogi� el usuario.*/
	void userpeek()
	{
		int op;
		system("CLS");
		cout<<"Escoge la posicion del elemento que quieres ver [0]-[1]-[2]-[3]-[4]: "<<endl;
		cin>>op;
		if(frente==final)
		{
			system("CLS");
			cout<<"Cola vacia!! No hay elementos."<<endl;
			return;
		}
		if(op > final)
		{
			
			system("CLS");
			cout<<"Posicion no valida"<<endl;
			return;
		}else
		{
			cout<<"El elemento de la posicion "<<op<<" es "<<cola[op];
			return;
		}
	}	
};
//Dentro de la funci�n principal main, se declaran las variables a utilizar dentro de un men� switch y una variable de tipo Cola para poder llamar a los m�todos.
int main()
{
	int op, op2, op3;
	Cola co;
	co.create();
   do{ //Dentro de un m�todo do-while, se lleva a cabo un switch para poder mostrar al usuario las opciones del programa. 1.Encolar, 2.Peek(mostrar elementos) y 3.Salir del programa. Su opc se guarda en la variable op.
   cout<<"1.Encolar \n2.Peek(mostrar elementos) \n3.Salir"<<endl;
   cout<<"Tu opcion es: ";
   cin>>op; 
   switch(op) //la funci�n switch funciona con la elecci�n del usuario.
   {
   case 1: //Si el usuario selecciona la opci�n 1.Encolar, se le pedir� ingresar el elemento a la cola que se guarda en la auxiliar op2 y se manda a llamar a la funci�n encolar() para llevar a cabo el m�todo.
        system("CLS");
        cout<<"Ingresa un valor a la cola: ";
        cin>>op2;
        co.encolar(op2);
        break;
        
        //Si se selecciona la opci�n 2, se despliega un submenu el cual muestra tres opciones: 1.peekall, 2.userpeek y 3.volver al menu principal
    case 2: 
    system("CLS");
	cout<<"1.peekall \n2.userpeek \n3.Volver al menu principal"<<endl;
	cout<<"Tu opcion es: ";
	cin>>op3;
	system("CLS");
	switch(op3)
	{
		//Si se selecciona la opcion 1 del submenu, se ejecuta el m�todo peekAll que mostrar� al usuario todos los elementos de la cola.
	case 1:
		system("CLS");
		cout<<"los elementos de la cola son"<<endl;
		co.peekAll();
		getch();
		    system("CLS");
		return main();
	break;
	case 2: //si se selecciona la opci�n 2 del submenu, se ejecuta el m�todo userpeek.
		co.userpeek();
		getch();
		system("CLS");
		return main();	
	break;
	case 3: //la opci�n 3 regresa al usuario al men� principal y se termina el submen�.
		return main();
	break;	
	}  
	case 3: //opci�n 3 del men� principal y termina el programa.
	break;
    }
}while(op!=3);
return 0;
}
//Fin del programa
