//LA DOCUMENTACIÓN DEL PROGRAMA SE ENCUENTRA AQUÍ MISMO A MODO DE COMENTARIOS
#include<iostream> //Se incluye la librería estándar iostream para ingresar(cout) y leer(cin) datos.
#define TAM 15 //Se define el tamaño que tendrá el arreglo con TAM, éste será de 15 elementos.
using namespace std;
void quicksort(int [TAM], int, int); //Se declara el método quicksort que se llevará a cabo para el proceso de ordenamiento. Esta recibe el arreglo y dos variables de tipo entero.
int main() //Función principal main()
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
	quicksort(array, 0, 14); //Se llama al método quicksort con los parámetros más importantes: el arreglo, la posición inicial 0, y la posición final 14.
	cout<<"\n\nElementos ordenados"<<endl; //Se implementa un ciclo for después de la llamada del método para imprimir los elementos del arreglo ya ordenados.
	for(int i=0; i<TAM;i++) //Desde i igual a 0 hasta que sea menor que TAM, se repite hasta llegar al límite.
	{
		cout<<array[i]<<" "; //Se imprime en pantalla los elementos en forma ascendente, de menor a mayor.
	}
}
void quicksort(int array[TAM], int first, int last) //El método quicksort recibe el arreglo y dos variables enteras que será la posición inicial y final. 
{
	int pivote, centro, i, j, aux; //variables a utilizar.
	i = first; //i tomará las posiciones de izquierda a derecha, es decir, de menor a mayor.
	j = last; //j tomará las posiciones de derecha a izquierda, es decir, de mayor a menor.
	centro = ((first + last)/2); //Esta parte será para dividir el arreglo y encontrar el centro del mismo para tomar el valor de esa posición como pivote.
	pivote = array[centro]; //El pivote es el valor en la posición del centro del arreglo.
	do	//Para recorrer el arreglo mientras i sea menor o igual que j.
	{
		while(array[i]<pivote) //Mientras el valor i sea menor que el pivote, i aumenta para ir buscando el siguiente elemento de izquierda a derecha.
		{
			i++;
		}
		while(array[j]>pivote) //Y mientras el valor de j sea mayor al pivote, j disminuye para ir cambiando de posición de derecha a izquierda.
		{
			j--;
		}
		//Para intercambiar los elementos al respectivo lado izquierdo o derecho dependiendo si son mayores o menores.
		if(i<=j)
		{
			aux = array[i]; //la aux. guardará el valor de la posición i.
			array[i] = array[j]; //ahora i pasa ser igual a la posición j para intercambiar.
			array[j] = aux;
			i++; //para avanzar en el arreglo.
			j--;
		}
	}while(i<=j);
    //condiciones para la posición de los indices.
	if(first<j) //si el primer elemento first es menor que la posición de j
	{
	quicksort(array,first,j); //la posición first será la posición 0 y la última será j.
	}
	if(i<last) //si la posición i es menor que last.
	{
	quicksort(array,i,last);//la primera posición ahora será i 0 y la ultima será last.
	}
}
//Fin del programa.


