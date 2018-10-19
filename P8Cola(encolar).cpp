/*LA DOCUMENTACI�N DEL PROGRAMA SE ENCUENTRA AQU� MISMO A MODO DE COMENTARIOS.

Se incluyen las librer�as necesarias: librer�a iostream para poder ingresar(cout) y leer(cin) datos; 
librer�a stdlib para usar la funci�n system("cls") para limpiar la pantalla.*/
#include <iostream> 
#include<stdlib.h>
#define max 5 //se define el tama�o m�ximo que tendr� la cola.
using namespace std; //para el uso de lenguaje est�ndar.

/*Se crea la clase Cola donde se declara un array de tipo entero con el tama�o m�ximo defindo anteriormente.
Despu�s, se declaran dos variables para referirse al final y frente de la cola, ambas inicializadas en cero.
Posteriormente, se comienzan a implementar los dos m�todos a utilizar de manera p�blica.*/
class Cola
{
	int cola[max];
	int final=0, frente=0;
	public:
	void create() //El m�todo create() funcionar� para crear la cola e inicializarla en ceros.
	{
		int cola[max]={0};
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
};
//Dentro de la funci�n principal main, se declaran las variables a utilizar dentro de un men� switch y una variable de tipo Cola para poder llamar a los m�todos.
int main()
{
	int op, op2;
	Cola co;
	co.create();
   do{ //Dentro de un m�todo do-while, se lleva a cabo un switch para poder mostrar al usuario las opciones del programa. 1.Encolar y 2.Salir del programa. Su opc se guarda en la variable op.
   cout<<"1.Encolar \n2.Salir"<<endl;
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
   case 2: //si el usuario selecciona la opci�n 2.Salir, el programa termina.
   break;
   }
   }while(op !=2);
}
//Fin del programa.
