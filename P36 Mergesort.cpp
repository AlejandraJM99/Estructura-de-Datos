/*LA DOCUMENTACIÓN DEL PROGRAMA SE ENCUENTRA AQUÍ MISMO A MODO DE COMENTARIOS

MERGESORT
Se declaran las librerías necesarias: la librería estándar iostream para ingresar(cout) y leer(cin) datos. Así también se define el tamaño que tendrá el arreglo el cual será de 15.*/
#include<iostream>
#include<ctime>
#define TAM 15
using namespace std;
void merge(int [], int, int, int);
void mergesort(int [], int, int);
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
	//Elementos ya ordenados, se llama la función mergesort con el array y el tamaño de éste y se imprimen los valores ya ordenados mediante otro bucle for.
	cout<<"\n\nElementos ordenados"<<endl;
	mergesort(array,0,14);
	for(int i=0;i<TAM;i++)
	{
		cout<<array[i]<<" "; 
	}		
}
//Método de ordenamiento mergesort
//División de elementos.
void merge(int array[], int p, int q, int r) //recibe el arreglo, la primera partición. el inicio de la segunda partición y el final de la segunda partición.
{
	//Se declaran dos variables para dividir en mitades el arreglo.
	int n1 = q - p + 1;
	int n2 = r - q;
	int k = p;
	int i = 0;
	int j = 0;
	//Y se crean dos arreglos temporales.
	int L[n1], R[n2]; //L para el lado izquierdo y R para el lado derecho.
	
	//A continuación se crean dos bucles for para pasar los elementos del arreglo principal en los subarreglos temporales.
	for(int i = 0; i < n1; i++)
	{
		L[i] = array[p+i]; //para el subarreglo de la izquierda.
	}
	for(int j = 0; j < n2; j++)
	{
		R[j] = array[q+1+j]; //para el subarreglo de la derecha.
	}
	//Para acomodar los valores en el arreglo principal.
	while(i < n1 and j < n2)
	{
		if(L[i]<=R[j]) //si el elemento del lado izquierdo es menor que el del derecho, se copia el valor de i en la posición k del arreglo final
		{
			array[k] = L[i];
			i++; //incrementa el indicador del lado izquierdo.
		}else
		{
			array[k] = R[j]; //Sino, r es menor y j incrementa y se posiciona en k.
			j++; //incrementa j.
		}
		k++;
	}
	while(i<n1) //Para acomodar los valores restantes del lado izquierdo.
	{
		array[k] = L[i];
		i++;
		k++;
	}
	while(j<n2) //Para acomodar los valores restantes del lado derecho.
	{
		array[k] = R[j];
		j++;
		k++;
	}
//Combinación
void mergesort(int array[], int p, int r) //Esta última función recibe el arreglo y las posiciones p y r.
{
	if(p<r) //Si p es menor que r, es decir, la primera partición menor que el final de la segunda.
	{
		//llamadas recursivas
		int q = ((p+r)/2); //Se divide en dos.
		mergesort(array,p,q); //Primero se arregla la primera subsecuencia.
		mergesort(array,q+1,r); //Después se arrgla la segunda subsecuencia.
		merge(array,p,q,r); //Por último se unen esas dos subsecuencias mediante el mergesort.
	}
}
