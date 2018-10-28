/*LA DOCUMENTACI�N DEL PROGRAMA SE ENCUENTRA AQU� MISMO A MODO DE COMENTARIOS.

Se incluyen las librer�as necesarias: librer�a iostream para poder ingresar(cout) y leer(cin) datos;
librer�a stdlib para usar la funci�n system("cls") para limpiar la pantalla, y la librer�a conio.h para poder utilizar la funci�n getch() que pausa el programa
para poder ver el resultado de la ejecuci�n. Por �ltimo se incluye el tama�o que tendr� el array el cual es de 5 posiciones.*/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#define TAM 5
using namespace std; //Para el uso de lenguaje est�ndar.
class ColaCircular //se crea la clase ColaCircular donde ir�n los m�todos.
{
	private: //De manera privada, se crea el arreglo que funcionar� de cola y este tiene el tama�o TAM definido anteriormente. As� como dos variables front y rear.
		int cc[TAM];
		int front, rear;
	/*De forma p�blica, se crea el constructor de la clase donde se inicializan los valores de front y rear en -1 para indicar que est� fuera de alguna posici�n 
	del arreglo.*/
	public:  
	ColaCircular()
	{
		front = -1;
		rear = -1;
	}
	//A continuaci�n se implementa el m�todo push() el cual servir� para ingresar los elementos a la cola. �ste recibir� un entero denominado item que ser� proporcionado por el usuario.
	void push(int item)
	{
		/*Para que el m�todo funcione correctamente, se necesita contar una condici�n para evitar un desbordamiento de la cola en caso de que la cola ya est� llena y se
		quieran ingresar m�s elementos. Si el final de la cola es igual al tama�o m�ximo menos 1 (o sea, en la posici�n 4 del arreglo y front(frente) est� en la posici�n cero,
		se considera que la cola ya est� llena. O si front es igual a la cola +1 (posici�n 5), tambi�n se considera como llena. 
		Se imprime en pantalla que la cola est� llena y no se pueden agregar m�s datos.*/
		if((front == 0 and rear == TAM - 1) or (front == rear + 1))
		{
			cout<<"Cola llena! No se pueden ingresar mas elementos."<<endl;
		}
		//Si no se cumple con la condici�n de cola llena, se procede a insertar el dato a la cola.
		else
		{
			/*Para insertar el primer elemento se requiere de una condici�n que dice que si front es -1, o sea, fuera de posici�n del arreglo, el primer dato ingresado
			se posicionar� en la casilla 0 de la cola y ser� considerado como el frente.*/
			if(front == -1)
			{
				front = 0;
			}
			/*Para insertar los datos sucesores del frente se emplea el uso de una formula que permite posicionar lo que ser�a el elemento rear (cola) del arreglo.
			rear funcionar� como un �ndice que se posicionar�  despu�s de sumarle 1, es decir, se ir� moviendo de casilla entre TAM que significa el tama�o total.
			cc[rear]=item nos indica que se posiciona rear ya que va despu�s de front tomando el lugar de item, que fue ingresado por el usuario.
			Finalmente se env�a un mensaje de confirmaci�n del elemento ingresado.*/
				rear = (rear + 1) % TAM;
				cc[rear]=item;
				cout<<"Elemento "<<item<<" insertado."<<endl;
		}
	}
};
//En la funci�n principal main() se declaran las variables a utilizar dentro de un men� y una variable de tipo ColaCircular para poder llamar a los m�todos de la clase.
int main()
{
	ColaCircular cc;
	int op, dato;
	do //El programa se llevar� a cabo hasta que el usuario decida terminarlo que se logra gracias a un bucle do-while.
	{
		//Al iniciar el programa se le presentan al usuario dos opciones: 1.Encolar(meter elementos a la cola) y 2.Salir. Su opci�n se guarda en la variable op.
		cout<<"1.Encolar \n2.Salir \nTu opcion es: ";
		cin>>op;
		switch(op) //La funci�n switch funciona gracias a la opci�n del usuario.
		{
			/*Si se selecciona la opci�n 1.Encolar, se le pedir� al usuario que ingrese el dato a la cola guardado en la variable dato. 
			Al final, simplemente se manda a llamar el m�tdo push() implementado en la clase.*/
			case 1:
			system("cls");	
			cout<<"Ingresa un elemento: ";
			cin>>dato;
			cc.push(dato);
			break;
			//Si se selecciona la opci�n 2.Salir, el programa termina.
			case 2:
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
