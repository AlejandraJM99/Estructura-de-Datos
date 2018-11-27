/*LA DOCUMENTACI�N DEL PROGRAMA SE ENCUENTRA AQU� MISMO A MODO DE COMENTARIOS
SHELLSORT 
Se declaran las librer�as necesarias: la librer�a est�ndar iostream para ingresar(cout) y leer(cin) datos. As� tambi�n se define el tama�o que tendr� el arreglo el cual ser� de 15.*/
#include<iostream>
#define TAM 15
using namespace std;
void shellsort(int []); //se declara la funci�n Shellsort que recibir� el arreglo.
int main()
{
	int array[TAM]; //Se crea el arreglo de tipo entero que tendr� el tama�o TAM definido anteriormente que es de 15.
	//Bucle para ingresar elementos por teclado. Se repite el proceso desde que i es igual a 0 hasta que sea menor a TAM, es decir, al tama�o del arreglo que es 15 y va aumentando hasta llegar al l�mite.
	for(int i=0;i<TAM;i++)
	{
		cout<<"Ingresa un elemento al arreglo: "; //Cada vez se imprime en pantalla la solicitud para ingresar elementos.
		cin>>array[i]; //Los elementos se guardan en la variable i.
	}
	//Para imprimir los elementos en forma como se ingresaron, se utiliza nuevamente un bucle for el cual lleva los mismos datos del for anterior pero esta vez solo para imprimir i.
	cout<<"\n\nElementos no ordenados"<<endl;
	for(int i=0;i<TAM;i++)
	{
		cout<<array[i]<<" "; //Se imprime en pantalla los elementos en el orden que se ingresaron.
	}	
	//Se imprime en pantalla el texto de elementos ordenados para antes de llevar a cabo el m�todo.
	cout<<"\n\nElementos ordenados"<<endl;
	shellsort(array); //Se llama al m�todo para llevar a cabo las instrucciones que este contiene e imprimir� los elementos del array ya ordenados.
	return 0;
}
void shellsort(int array[]) //M�todo shellsort
{
	int saltos, i, aux; //Se declaran las variables a utilizar.
	bool b; //Y una variable booleana para facilitar el proceso.
	saltos = TAM; //Los saltos se inicializan con el tama�o del arreglo.
	while(saltos>1) //Mientras que el intervalo de saltos sea mayor a cero se llevan a cabo las instrucciones.
	{
		saltos=(saltos/2); //El intervalo de saltos estar� definido dividiendo entre dos la variable saltos que anteriormente ten�a el valor del tama�o del arreglo (15).
		b = true; //Y se inicializa la variable booleana como true.
		while(b==true) //Y mientras la variable sea true se ejecutan las instrucciones de ese ciclo.
		{
			b=false;
			i = 0;
			while((i+saltos)<=TAM) //Dentro de otro ciclo while, en el cual se comparan el elemento a distancia con el tama�o del arreglo se llevar� a cabo una comparaci�n.
			{
				if(array[i]>array[i+saltos]) //Si el primer elemento del arreglo a comparar es mayor que el elemento a la distancia del salto, se procede a intercambiar de lado dicho valor.
				{
					aux = array[i];
					array[i] = array[i+saltos];
					array[i+saltos] = aux;
					b = true;
				}
				i++; //i aumenta para seguir buscando elementos que se van a comparar.
			}
		}
	}
	//Un bucle for para imprimir en orden los elementos.
	for(int i=0;i<TAM;i++)
	{
		cout<<array[i]<<" "; 
	}
}
//Fin del programa.
