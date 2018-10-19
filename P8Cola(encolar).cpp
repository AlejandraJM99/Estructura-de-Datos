/*LA DOCUMENTACIÓN DEL PROGRAMA SE ENCUENTRA AQUÍ MISMO A MODO DE COMENTARIOS.

Se incluyen las librerías necesarias: librería iostream para poder ingresar(cout) y leer(cin) datos; 
librería stdlib para usar la función system("cls") para limpiar la pantalla.*/
#include <iostream> 
#include<stdlib.h>
#define max 5 //se define el tamaño máximo que tendrá la cola.
using namespace std; //para el uso de lenguaje estándar.

/*Se crea la clase Cola donde se declara un array de tipo entero con el tamaño máximo defindo anteriormente.
Después, se declaran dos variables para referirse al final y frente de la cola, ambas inicializadas en cero.
Posteriormente, se comienzan a implementar los dos métodos a utilizar de manera pública.*/
class Cola
{
	int cola[max];
	int final=0, frente=0;
	public:
	void create() //El método create() funcionará para crear la cola e inicializarla en ceros.
	{
		int cola[max]={0};
	}
	/*El método encolar será para ingresar los elementos al arreglo. Éste recibe un entero denominado item(ingresado por el usuario)
	Para evitar un overflow, se debe crear una condición la cual si se cumple, detendrá el programa: Si el final de la cola, ya es igual al máximo del final, se debe lanzar
	un mensaje, de que la cola ya está llena y no se pueden ingresar más elementos, esto con el propósito de evitar un desbordamiento.
	Si la condición aún no se cumple, se ejecuta el método para ingresar los elementos, de tal manera que el final de cola aumenta porque se están ingresando los elementos.
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
//Dentro de la función principal main, se declaran las variables a utilizar dentro de un menú switch y una variable de tipo Cola para poder llamar a los métodos.
int main()
{
	int op, op2;
	Cola co;
	co.create();
   do{ //Dentro de un método do-while, se lleva a cabo un switch para poder mostrar al usuario las opciones del programa. 1.Encolar y 2.Salir del programa. Su opc se guarda en la variable op.
   cout<<"1.Encolar \n2.Salir"<<endl;
   cout<<"Tu opcion es: ";
   cin>>op;
   switch(op) //la función switch funciona con la elección del usuario.
   {
   case 1: //Si el usuario selecciona la opción 1.Encolar, se le pedirá ingresar el elemento a la cola que se guarda en la auxiliar op2 y se manda a llamar a la función encolar() para llevar a cabo el método.
        system("CLS");
        cout<<"Ingresa un valor a la cola: ";
        cin>>op2;
        co.encolar(op2);
   break;
   case 2: //si el usuario selecciona la opción 2.Salir, el programa termina.
   break;
   }
   }while(op !=2);
}
//Fin del programa.
