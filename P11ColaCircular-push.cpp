/*LA DOCUMENTACIÓN DEL PROGRAMA SE ENCUENTRA AQUÍ MISMO A MODO DE COMENTARIOS.

Se incluyen las librerías necesarias: librería iostream para poder ingresar(cout) y leer(cin) datos;
librería stdlib para usar la función system("cls") para limpiar la pantalla, y la librería conio.h para poder utilizar la función getch() que pausa el programa
para poder ver el resultado de la ejecución. Por último se incluye el tamaño que tendrá el array el cual es de 5 posiciones.*/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#define TAM 5
using namespace std; //Para el uso de lenguaje estándar.
class ColaCircular //se crea la clase ColaCircular donde irán los métodos.
{
	private: //De manera privada, se crea el arreglo que funcionará de cola y este tiene el tamaño TAM definido anteriormente. Así como dos variables front y rear.
		int cc[TAM];
		int front, rear;
	/*De forma pública, se crea el constructor de la clase donde se inicializan los valores de front y rear en -1 para indicar que está fuera de alguna posición 
	del arreglo.*/
	public:  
	ColaCircular()
	{
		front = -1;
		rear = -1;
	}
	//A continuación se implementa el método push() el cual servirá para ingresar los elementos a la cola. Éste recibirá un entero denominado item que será proporcionado por el usuario.
	void push(int item)
	{
		/*Para que el método funcione correctamente, se necesita contar una condición para evitar un desbordamiento de la cola en caso de que la cola ya esté llena y se
		quieran ingresar más elementos. Si el final de la cola es igual al tamaño máximo menos 1 (o sea, en la posición 4 del arreglo y front(frente) está en la posición cero,
		se considera que la cola ya está llena. O si front es igual a la cola +1 (posición 5), también se considera como llena. 
		Se imprime en pantalla que la cola está llena y no se pueden agregar más datos.*/
		if((front == 0 and rear == TAM - 1) or (front == rear + 1))
		{
			cout<<"Cola llena! No se pueden ingresar mas elementos."<<endl;
		}
		//Si no se cumple con la condición de cola llena, se procede a insertar el dato a la cola.
		else
		{
			/*Para insertar el primer elemento se requiere de una condición que dice que si front es -1, o sea, fuera de posición del arreglo, el primer dato ingresado
			se posicionará en la casilla 0 de la cola y será considerado como el frente.*/
			if(front == -1)
			{
				front = 0;
			}
			/*Para insertar los datos sucesores del frente se emplea el uso de una formula que permite posicionar lo que sería el elemento rear (cola) del arreglo.
			rear funcionará como un índice que se posicionará  después de sumarle 1, es decir, se irá moviendo de casilla entre TAM que significa el tamaño total.
			cc[rear]=item nos indica que se posiciona rear ya que va después de front tomando el lugar de item, que fue ingresado por el usuario.
			Finalmente se envía un mensaje de confirmación del elemento ingresado.*/
				rear = (rear + 1) % TAM;
				cc[rear]=item;
				cout<<"Elemento "<<item<<" insertado."<<endl;
		}
	}
};
//En la función principal main() se declaran las variables a utilizar dentro de un menú y una variable de tipo ColaCircular para poder llamar a los métodos de la clase.
int main()
{
	ColaCircular cc;
	int op, dato;
	do //El programa se llevará a cabo hasta que el usuario decida terminarlo que se logra gracias a un bucle do-while.
	{
		//Al iniciar el programa se le presentan al usuario dos opciones: 1.Encolar(meter elementos a la cola) y 2.Salir. Su opción se guarda en la variable op.
		cout<<"1.Encolar \n2.Salir \nTu opcion es: ";
		cin>>op;
		switch(op) //La función switch funciona gracias a la opción del usuario.
		{
			/*Si se selecciona la opción 1.Encolar, se le pedirá al usuario que ingrese el dato a la cola guardado en la variable dato. 
			Al final, simplemente se manda a llamar el métdo push() implementado en la clase.*/
			case 1:
			system("cls");	
			cout<<"Ingresa un elemento: ";
			cin>>dato;
			cc.push(dato);
			break;
			//Si se selecciona la opción 2.Salir, el programa termina.
			case 2:
			break;	
			default: //En caso de que el usuario no seleccioné ninguna opción al ingresar un dato fuera del programa se le marcará un error y éste termina.
			cout<<"Error!"<<endl;
			return 0;
			break;
		}
	}while(op!=2);
	return 0;
}
//Fin del programa.
