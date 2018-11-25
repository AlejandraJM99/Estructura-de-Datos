/*LA DOCUMENTACIÓN DEL PROGRAMA SE ENCUENTRA AQUÍ MISMO A MODO DE COMENTARIOS

BÚSQUEDA SECUENCIAL */

/*Se declaran las librerías necesarias: la librería estándar iostream para ingresar(cout) y leer(cin) datos y la librería stdlib para usar la función de cls para limpiar la pantalla.
Así también se define el tamaño que tendrá el arreglo el cual será de 15.*/
#include<iostream>
#include<stdlib.h>
#define TAM 15
using namespace std;
int main()
{
	int array[TAM], dato, i=0; //se declaran de tipo entero, el arreglo, el dato que proporcionará el usuario y un iterador i.
	bool n = false; //también de tipo booleano se declara una variable inicializada en false.
	//Bucle para ingresar elementos por teclado. Se repite el proceso desde que i es igual a 0 hasta que sea menor a TAM, es decir, al tamaño del arreglo que es 15.
	for(int i=0;i<TAM;i++)
	{
		cout<<"Ingresa un elemento al arreglo: "; //Cada vez se imprime en pantalla la solicitud para ingresar elementos.
		cin>>array[i]; //Los elementos se guardan en la variable i.
	}
	system("CLS"); //Función para limpiar la pantalla.
	cout<<"Ingresa el elemento que deseas buscar: "; //Se le pide al usuario que ingrese el elemento que está buscando y se guarda en la variable dato.
	cin>>dato;
	while((n == false) and (i<TAM)) //Mientras que n siga siendo falso e i sea menor al tamaño del arreglo se ejecuta las instrucciones.
	{
		//Una condición para cuando el elemento i sea igual al dato proporcionado por el usuario, n pasa a ser true y a las condiciones.
		if(array[i]==dato) 
		{
			n = true;
		}
		i++; //para que el iterador siga buscando en las posiciones del arreglo.
	}
	//Condición para cuando no se encuentre el elemento. Si n sigue siendo false, entonces el elemento no está en el arreglo.
	if(n == false)
	{
		cout<<"Elemento no encontrado."<<endl; //Se imprime un mensaje de que el elemento no está dentro del arreglo.
	}
	else if(n == true) //si no se cumple la condición anterior, se procede a comparar si n ya es true. Si es así, entonces ya se encontró el elemento solicitado.
	{
		/*Se imprime el mensaje de que se encontró el elemento y su posición en el arreglo en i-1 puesto que sigue aumentando tras encontrar el elemento
		por el ++ y si se le resta 1, da la posición original del elemento y no una más..*/
		cout<<"El elemento se encontro en el arreglo en la posicion "<<"["<<i-1<<"]"<<endl; 
	}
	return 0;
}
//Fin del programa.

