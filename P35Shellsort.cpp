/*LA DOCUMENTACIÓN DEL PROGRAMA SE ENCUENTRA AQUÍ MISMO A MODO DE COMENTARIOS
SHELLSORT 
Se declaran las librerías necesarias: la librería estándar iostream para ingresar(cout) y leer(cin) datos. Así también se define el tamaño que tendrá el arreglo el cual será de 15.*/
#include<iostream>
#define TAM 15
using namespace std;
void shellsort(int []); //se declara la función Shellsort que recibirá el arreglo.
int main()
{
	int array[TAM]; //Se crea el arreglo de tipo entero que tendrá el tamaño TAM definido anteriormente que es de 15.
	//Bucle para ingresar elementos por teclado. Se repite el proceso desde que i es igual a 0 hasta que sea menor a TAM, es decir, al tamaño del arreglo que es 15 y va aumentando hasta llegar al límite.
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
	//Se imprime en pantalla el texto de elementos ordenados para antes de llevar a cabo el método.
	cout<<"\n\nElementos ordenados"<<endl;
	shellsort(array); //Se llama al método para llevar a cabo las instrucciones que este contiene e imprimirá los elementos del array ya ordenados.
	return 0;
}
void shellsort(int array[]) //Método shellsort
{
	int saltos, i, aux; //Se declaran las variables a utilizar.
	bool b; //Y una variable booleana para facilitar el proceso.
	saltos = TAM; //Los saltos se inicializan con el tamaño del arreglo.
	while(saltos>1) //Mientras que el intervalo de saltos sea mayor a cero se llevan a cabo las instrucciones.
	{
		saltos=(saltos/2); //El intervalo de saltos estará definido dividiendo entre dos la variable saltos que anteriormente tenía el valor del tamaño del arreglo (15).
		b = true; //Y se inicializa la variable booleana como true.
		while(b==true) //Y mientras la variable sea true se ejecutan las instrucciones de ese ciclo.
		{
			b=false;
			i = 0;
			while((i+saltos)<=TAM) //Dentro de otro ciclo while, en el cual se comparan el elemento a distancia con el tamaño del arreglo se llevará a cabo una comparación.
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
