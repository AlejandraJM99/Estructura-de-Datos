/*LA DOCUMENTACI�N DEL PROGRAMA SE ENCUENTRA AQU� MISMO A MODO DE COMENTARIOS.

Se incluyen las librer�as necesarias: librer�a iostream para poder ingresar(cout) y leer(cin) datos;
librer�a stdlib para usar la funci�n system("cls") para limpiar la pantalla, y la librer�a conio.h para poder utilizar la funci�n getch() que pausa el programa
para poder ver el resultado de la ejecuci�n. Por �ltimo se incluye el tama�o que tendr� el array el cual es de 5 posiciones.*/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#define TAM 5
using namespace std; //Para el uso de lenguaje est�ndar.

/*Se crea la clase ColaCircular donde se declara un array de tipo entero con el tama�o m�ximo defindo anteriormente cc[TAM].
Despu�s, se declaran dos variables de tipo entero para referirse al final(rear) y frente(front) de la cola, ambas inicializadas en -1 para posicionarlos fuera del array.
Posteriormente, se comienzan a implementar el primer a utilizar de manera p�blica.*/
class ColaCircular
{
	public:
	int cc[TAM]; //tama�o de la cola circular
	int front = -1;
	int rear = -1;

	//El m�todo push servir� para ingresar elementos a la cola circular. Se declara de tipo void y �ste recibir� un entero denominado como item proporcionado por el usuario.
	void push(int item)
	{
		/*Para que el m�todo funcione correctamente, se necesita contar una condici�n para evitar un desbordamiento de la cola en caso de que la cola ya est� llena y se
		quieran ingresar m�s elementos. Si el final de la cola es igual al tama�o m�ximo menos 1 (o sea, en la posici�n 4 del arreglo y front(frente) est� en la posici�n cero,
		se considera que la cola ya est� llena. Y se imprime en pantalla que la cola est� llena y no se pueden agregar m�s datos. */
		if(rear==TAM-1 and front ==0)
		{
			cout<<"Cola llena! no se pudo agregar el elemento"<<endl;
			return;
		}else //Si no se cumple la condici�n de la cola llena, se procede al proceso para insertar elementos a la cola.
		{
			//Si rear est� en la posici�n 4 y el frente es diferente de la posici�n 0, se considera a rear en posici�n -1.
			if(rear==TAM-1 and front !=0)
			{
				rear = -1;
			}
			//Despu�s se procede a insertar el valor de item ingresado por el usuario dentro del arreglo en la posici�n de rear y esta variable aumenta.
			cc[rear]=item;
			rear++;
			cout<<"Elemento "<<item<<" ingresado correctamente"<<endl; //Se manda un mensaje de confirmaci�n de que el elemento se ingres� correctamente.
		}
		//Para poder insertar a su vez un elemento en front se debe cumplir la condici�n de que front est� fuera de posiciones del array para poder ponerlo en posici�n 0.
		if(front == -1)
		{
			front =0;
		}

	}
};
//En la funci�n principal main() se declaran las variables a utilizar dentro de un men� y una variable de tipo ColaCircular para poder llamar a los m�todos de la clase.
int main()
{
	int op, item;
	ColaCircular cc;
	do //El programa se llevar� a cabo hasta que el usuario decida terminarlo que se logra gracias a un bucle do-while.
	{
		//Al iniciar el programa se le presentan al usuario dos opciones: 1.Encolar(meter elementos a la cola) y 2.Salir. Su opci�n se guarda en la variable op-
		cout<<"1.Encolar \n2.Salir \nTu opcion es: ";
		cin>>op;
		switch(op) //El switch funciona gracias a la opci�n del usuario.
		{
		/*Si se selecciona la opci�n 1.Encolar, se le pedir� al usuario que ingrese el dato a la cola guardado en la variable item. 
		Al final, simplemente se manda a llamar el m�tdo push() implementado en la clase.*/
		    case 1:
            system("CLS");
			cout<<"Ingresa elemento a la cola: ";
			cin>>item;
			cc.push(item);
			break;
			case 2: //Si el usuario selecciona la opci�n 2, el programa termina.
			break;
			default: //En caso de que el usuario no seleccion� ninguna opci�n al ingresar un dato fuera del programa se le marcar� un error y �ste termina.
			cout<<"Error!"<<endl;
			return 0;
			break;
		}
	}while(op!=2);
	return 0;
}
//Fin del programa.

