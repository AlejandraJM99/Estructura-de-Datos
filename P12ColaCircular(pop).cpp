/*LA DOCUMENTACIÓN DEL PROGRAMA SE ENCUENTRA AQUÍ MISMO A MODO DE COMENTARIOS.

Se incluyen las librerías necesarias: librería iostream para poder ingresar(cout) y leer(cin) datos;
librería stdlib para usar la función system("cls") para limpiar la pantalla, y la librería conio.h para poder utilizar la función getch() que pausa el programa
para poder ver el resultado de la ejecución. Por último se incluye el tamaño que tendrá el array el cual es de 5 posiciones.*/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#define TAM 5
using namespace std; //Para el uso de lenguaje estándar.

/*Se crea la clase ColaCircular donde se declara un array de tipo entero con el tamaño máximo defindo anteriormente cc[TAM].
Después, se declaran dos variables de tipo entero para referirse al final(rear) y frente(front) de la cola, ambas inicializadas en -1 para posicionarlos fuera del array.
Posteriormente, se comienzan a implementar el primer a utilizar de manera pública.*/
class ColaCircular
{
	public:
	int cc[TAM]; //tamaño de la cola circular
	int front = -1;
	int rear = -1;

	//El método push servirá para ingresar elementos a la cola circular. Se declara de tipo void y éste recibirá un entero denominado como item proporcionado por el usuario.
	void push(int item)
	{
		/*Para que el método funcione correctamente, se necesita contar una condición para evitar un desbordamiento de la cola en caso de que la cola ya esté llena y se
		quieran ingresar más elementos. Si el final de la cola es igual al tamaño máximo menos 1 (o sea, en la posición 4 del arreglo y front(frente) está en la posición cero,
		se considera que la cola ya está llena. Y se imprime en pantalla que la cola está llena y no se pueden agregar más datos. */
		if(rear==TAM-1 and front ==0)
		{
			cout<<"Cola llena! no se pudo agregar el elemento"<<endl;
		}else //Si no se cumple la condición de la cola llena, se procede al proceso para insertar elementos a la cola.
		{
			//Si rear está en la posición 4 y el frente es diferente de la posición 0, se considera a rear en posición -1.
			if(rear==TAM-1 and front !=0)
			{
				rear = -1;
			}
			//Después se procede a insertar el valor de item ingresado por el usuario dentro del arreglo en la posición de rear y esta variable aumenta.
			cc[rear]=item;
			rear++;
			cout<<"Elemento "<<item<<" ingresado correctamente"<<endl; //Se manda un mensaje de confirmación de que el elemento se ingresó correctamente.
		}
		//Para poder insertar a su vez un elemento en front se debe cumplir la condición de que front esté fuera de posiciones del array para poder ponerlo en posición 0.
		if(front == -1)
		{
			front =0;
		}
	}
	/*El método pop sirve para eliminar elementos de la cola. Este funciona siguiendo el orden FIFO donde el primer elemento en ingresar (first in) será también el primero
	en salir (first out). Para su correcto funcionamiento se requiere primeramente de una condición para evitar un underflow ocurrido por tratar de sacar elementos de la
	cola cuando esta está vacía. Si front y rear están en posición -1, o sea, fuera de la cola, se considera que la cola está vacía.*/
	void pop()
	{
		if(front == -1 and rear == -1)
		{
			cout<<"Cola vacia! No se pueden sacar elementos"<<endl;
		}
		/*Si la condición no se cumple, se procede a eliminar el elemento de la cola cumpliendo un par de condiciones. Si front es igual al tamaño (posición 5) se considera 
		a front en la posición 0, y si front-1 es igual que rear (posición 4) front y rear estarán en la posición -1. Para eliminar el elemento simplemente front irá aumentando para moverse d elugar. */
		else
		{
			if(front == TAM)
			{
			front = 0;
			}
			if(front-1 == rear)
			{
			front = rear = -1;
			}
			cout<<"Elemento eliminado: "<<cc[front++];
		}
	}
};
//En la función principal main() se declaran las variables a utilizar dentro de un menú y una variable de tipo ColaCircular para poder llamar a los métodos de la clase.
int main()
{
	int op, item;
	ColaCircular cc;
	do //El programa se llevará a cabo hasta que el usuario decida terminarlo que se logra gracias a un bucle do-while.
	{
		//Al iniciar el programa se le presentan al usuario tres opciones: 1.Encolar(meter elementos a la cola), 2.Sacar elementos y 3.Salir. Su opción se guarda en la variable op-
		cout<<"1.Encolar \n2.Sacar elementos \n3.Salir \nTu opcion es: ";
		cin>>op;
		switch(op) //El switch funciona gracias a la opción del usuario.
		{
		/*Si se selecciona la opción 1.Encolar, se le pedirá al usuario que ingrese el dato a la cola guardado en la variable item. 
		Al final, simplemente se manda a llamar el métdo push() implementado en la clase.*/
		    case 1:
            system("CLS");
			cout<<"Ingresa elemento a la cola: ";
			cin>>item;
			cc.push(item);
			break;
			//Si el usuario selecciona la opción 2.Sacar elementos, se manda a llamar al método pop() implementado en la clase ColaCircular.
			case 2:
			system("CLS");	
			cc.pop();	
			cout<<"\n";
			break;	
			case 3: //Si el usuario selecciona la opción 2, el programa termina.
			break;
			default: //En caso de que el usuario no seleccioné ninguna opción al ingresar un dato fuera del programa se le marcará un error y éste termina.
			cout<<"Error!"<<endl;
			return 0;
			break;
		}
	}while(op!=3);
	return 0;
}
//Fin del programa.

