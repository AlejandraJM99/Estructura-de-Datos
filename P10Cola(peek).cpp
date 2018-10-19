/*LA DOCUMENTACIÓN DEL PROGRAMA SE ENCUENTRA AQUÍ MISMO A MODO DE COMENTARIOS.

Se incluyen las librerías necesarias: librería iostream para poder ingresar(cout) y leer(cin) datos; 
librería stdlib para usar la función system("cls") para limpiar la pantalla, y la librería conio.h para poder utilizar la función getch() que pausa el programa
para poder ver el resultado de la ejecución.*/
#include <iostream>
#include<stdlib.h>
#include<conio.h>
#define max 5 //se define el tamaño máximo que tendrá el arreglo(cola)
using namespace std; //para el uso de lenguaje estándar

/*Se crea la clase Cola donde se declara un array de tipo entero con el tamaño máximo defindo anteriormente.
Después, se declaran dos variables para referirse al final y frente de la cola, ambas inicializadas en cero.
Posteriormente, se comienzan a implementar los dos métodos a utilizar de manera pública.*/
class Cola
{
	int cola[max];
	int final=0, frente=0;
	public:
	void create()
	{
		int cola[max]={0}; //El método create() funcionará para crear la cola e inicializarla en ceros.
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
	/*El siguiente método, será para imprimir en pantalla todos los elementos de la cola en el orden en que fueron ingresados siguiendo el orden FIFO.
	Cumple con la misma condición para evitar un underflow en caso de querer mostrar elementos si ésta está vacía. Finalmente, mediante un ciclo for, imprime cada uno de
	los datos de la cola y su respectiva posición.*/
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
	/*El método de userpeek será para que el usuario seleccione una posición de la cola. Cuenta con la condición para no mostrar elementos cuando no hay elementos en la pila
	y para no mostrar elementos cuando la posición está fuera del arreglo de la cola. Si la condición no se cumple, se procede a ejecutar el método que muestra
	el número de posición que escogió el usuario.*/
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
//Dentro de la función principal main, se declaran las variables a utilizar dentro de un menú switch y una variable de tipo Cola para poder llamar a los métodos.
int main()
{
	int op, op2, op3;
	Cola co;
	co.create();
   do{ //Dentro de un método do-while, se lleva a cabo un switch para poder mostrar al usuario las opciones del programa. 1.Encolar, 2.Peek(mostrar elementos) y 3.Salir del programa. Su opc se guarda en la variable op.
   cout<<"1.Encolar \n2.Peek(mostrar elementos) \n3.Salir"<<endl;
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
        
        //Si se selecciona la opción 2, se despliega un submenu el cual muestra tres opciones: 1.peekall, 2.userpeek y 3.volver al menu principal
    case 2: 
    system("CLS");
	cout<<"1.peekall \n2.userpeek \n3.Volver al menu principal"<<endl;
	cout<<"Tu opcion es: ";
	cin>>op3;
	system("CLS");
	switch(op3)
	{
		//Si se selecciona la opcion 1 del submenu, se ejecuta el método peekAll que mostrará al usuario todos los elementos de la cola.
	case 1:
		system("CLS");
		cout<<"los elementos de la cola son"<<endl;
		co.peekAll();
		getch();
		    system("CLS");
		return main();
	break;
	case 2: //si se selecciona la opción 2 del submenu, se ejecuta el método userpeek.
		co.userpeek();
		getch();
		system("CLS");
		return main();	
	break;
	case 3: //la opción 3 regresa al usuario al menú principal y se termina el submenú.
		return main();
	break;	
	}  
	case 3: //opción 3 del menú principal y termina el programa.
	break;
    }
}while(op!=3);
return 0;
}
//Fin del programa
