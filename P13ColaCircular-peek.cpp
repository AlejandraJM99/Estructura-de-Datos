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
	/*A continuaci�n se implementa el m�todo pop() el cual servir� para eliminar los elementos a la cola en el orden FIFO, donde el primer elemento insertado, ser� el primero en ser 
	eliminado. Este m�todo requiere de un entero que servir� de auxiliar como el elemento a eliminar denominado como item tambi�n.*/
	void pop(int item)
	{
		/*Para que el m�todo funcione correctamente, se requiere de una condici�n para evitar un underflow en caso de querer sacar elementos cuakdo la cola est� vac�a. Esta condici�n
		se�ala que si front es igual a -1, la cola est� vac�a. Esto quiere decir que el frente de la cola no est� posicionado en la casilla 0 del array y est� fuera del mismo. Y si 
		no hay un front logicamente no hay un rear que le siga.*/
		if(front == -1)
		{
			cout<<"Cola vacia! No hay elementos que sacar"<<endl;
		}
		//Si no se cumple con la condici�n de la cola vac�a, se procede a eliminar el primer elemento de la cola.
		else
		{
			item = cc[front];
			//Cuando se terminan de eliminar los elementos, se vuelven a inicializar los valores de front y rear en -1 para posicionarlos fuera del array.
            if(front == rear)
			{
                front = -1;
                rear = -1;
            } 
            /*Si a�n no se terminan de eliminar los elementos de la cola se contin�a con el proceso de abstracci�n. Este proceso implementa la misma formula que se utiliz� al meter
			elementos a la cola, pero con un cambio donde ahora el elemento que se ir� moviendo de posici�n ser� el frente de la cola. Tras sumarle +1 su nueva posici�n se implementa
			puesto que al eliminar el valor de adelante, el siguiente debe pasar a ser el nuevo front.
			Al final se imprime un mensaje donde se confirma el elemento eliminado. */
            else 
			{
                front=(front+1) % TAM;
            }
            cout<<"Elemento eliminado: "<<item<<endl;
		}
	}
	//Los m�todos para mostrar los elementos de la cola son los siguientes.
	/*El primer m�todo muestra el primer elemento de la cola (front) pero no sin antes comprobar que la cola no est� vac�a. La condici�n es la misma donde si front = -1, la cola est�
	vac�a. Si no se cumple la condici�n, se procede a imprimir en pantalla el dato de la posici�n 0 o front del array.*/
	void peekFirst()
	{
		if(front == -1)
		{
			cout<<"Cola vacia! No hay elementos que mostrar."<<endl;
		}
		else
		{
			cout<<"Frente de la cola: "<<cc[front]<<endl;
		}
	}
	/*El segundo m�todo muestra el �ltimo elemento de la cola (rear) pero no sin antes comprobar que la cola no est� vac�a. La condici�n es la misma donde si front = -1, la cola est�
	vac�a. Si no se cumple la condici�n, se procede a imprimir en pantalla el dato de la posici�n 4 o rear del array.*/
	void peekLast()
	{
		if(front == -1)
		{
			cout<<"Cola vacia! No hay elementos que mostrar."<<endl;
		}
		else
		{
			cout<<"Final de la cola: "<<cc[rear]<<endl;
		}
	}
	/*El tercer m�todo muestra todos los elementos de la cola (front) pero no sin antes comprobar que la cola no est� vac�a. La condici�n es la misma donde si front = -1, la cola est�
	vac�a. Si no se cumple la condici�n, se procede a imprimir en pantalla los elementos mediante un ciclo for en el que se declara una variable de tipo entero i que servir� de �ndice.
	i ser� igual que front y se lleva a cabo mientras i sea diferente de rear e i ir� moviendose gracias a la formula ya utilizada.*/
	void peekAll()
	{
		if(front == -1)
		{
			cout<<"Cola vacia! No hay elementos que mostrar."<<endl;
		}
		else
		{
			cout<<"Los elementos de la cola son: "<<endl;
			for(int i = front; i != rear; i = (i+1) % TAM)
			{
				cout<<" "<<cc[i];
				cout<<"\n";
			}
		}
	}
	/*El cuarto y �ltimo m�todo permite al usuario elegir la posici�n del elemento que des�e ver. Para ello se primero se cumplen una serie de condiciones: Si el usuario elige
	una posici�n mayor al tama�o del array o menor qu�, se imprime que est� fuera de rango.
	Si el usuario escoge posici�n 0 se imprime front, si escoge posici�n 4 se imprime rear y si escoge una posici�n diferente d�, su opci�n imprime el dato que busca.*/
	void peekIndex(int op)
	{
		if(op>TAM or op==-1)
		{
			cout<<"Fuera de rango, no hay nada que mostrar"<<endl;
			return;
		}
		else
		{
		if(op == 0)
		{
			cout<<cc[front]<<endl;
		}
		}
		if(op == 4)
		{
			cout<<cc[rear]<<endl;
		}
		else
		{
		cout<<cc[op]<<endl;
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
		//Al iniciar el programa se le presentan al usuario tres opciones: 1.Encolar(meter elementos a la cola), 2.Eliminar(sacar elementos), 3.Mostrar y 4.Salir. Su opci�n se guarda en la variable op.
		cout<<"1.Encolar \n2.Eliminar \n3.Mostrar cola circular \n4.Salir \nTu opcion es: ";
		cin>>op;
		switch(op) //La funci�n switch funciona gracias a la opci�n del usuario.
		{
			/*Si se selecciona la opci�n 1.Encolar, se le pedir� al usuario que ingrese el dato a la cola guardado en la variable dato. 
			Al final, simplemente se manda a llamar el m�tdo push() implementado en la clase.*/
			case 1:
			system("CLS");	
			cout<<"Ingresa un elemento: ";
			cin>>dato;
			cc.push(dato);
			break;
			//Si se selecciona la opci�n 2.Eliminar, simplemente se manda a llamar al m�todo pop() y �ste ejecuta todo el proceso desarrollado en la clase.
			case 2:
			system("CLS");	
			cc.pop(dato);
			break;	
			//Si escoge la opci�n 3.Mostrar cola circular, se desplegar� un submen� donde el usuario puede elegir de entre otras 5 opciones.
			case 3:
			system("CLS");	
			cout<<"1.Frente de la cola \n\n2.Final de la cola \n\n3.Todos los elementos de la cola \n\n4.Posicion especifica \n\n5.Volver al menu principal \n\nTu opcion es: ";
			cin>>op;
			switch(op)
			{
				case 1: //Si escoge la opci�n 1, se lleva a cabo el m�todo peekFirst() implementado en la clase.
				system("cls");	
				cc.peekFirst();
				break;
				case 2: //Si escoge la opci�n 2, se lleva a cabo el m�todo peeklast() implementado en la clase.
				system("cls");	
				cc.peekLast();
				break;
				case 3: //Si escoge la opci�n 3, se lleva a cabo el m�todo peekAll() implementado en la clase.
				system("CLS");	
				cc.peekAll();
				break;
				case 4: //Si escoge la opci�n 4, se lleva a cabo el m�todo peekIndex() implementado en la clase pidiendo al usuario escoja la posici�n.
				system("CLS");
				cout<<"Escoge la posicion del elemento que deseas ver ";
				cout<<"[0]-[1]-[2]-[3]-[4]"<<endl;
				cin>>dato;	
				cc.peekIndex(dato);
				break;
				case 5: //Si escoge la opci�n 5, se regresa al men� principal.
				system("CLS");	
				return main();
				break;	
				default: //En caso de que el usuario no seleccion� ninguna opci�n al ingresar un dato fuera del programa se le marcar� un error y �ste termina.
				cout<<"Error!"<<endl;
				return 0;
				break;	
			}
			break;	
			case 4: //La opci�n 4 termina el programa.
			break;	
			default: //En caso de que el usuario no seleccion� ninguna opci�n al ingresar un dato fuera del programa se le marcar� un error y �ste termina.
			cout<<"Error!"<<endl;
			return 0;
			break;
		}
	}while(op!=4);
	return 0;
}
//Fin del programa.
