//LA DOCUMENTACI�N DEL PROGRAMA SE ENCUENTRA AQU� MISMO A MODO DE COMENTARIOS.
//M�todo Burbuja
#include<iostream> //Se incluye la librer�a est�ndar iostream para ingresar(cout) y leer(cin) datos.
#define TAM 10 //Se define el tama�o que tendr� el arreglo con TAM, �ste ser� de 10.
using namespace std;
//Funci�n principal main.
int main()
{
	//Se declaran dos variables de tipo entero: array, que ser� para el arreglo de tama�o TAM. Y aux, una variable auxiliar. 
	int array[TAM], aux;
	
	//Bucle para ingresar elementos por teclado. Se repite el proceso desde que i es igual a 0 hasta que sea menor a TAM, es decir, al tama�o del arreglo que es 10.
	for(int i=0;i<TAM;i++)
	{
	cout<<"Ingresa un elemento al arreglo: "; //El proceso repite este mensaje para ingresar hasta que el arreglo est� lleno.
	cin>>array[i];
    }
    //Para ordenar los elementos se necesitan dos bucles for anidados.
    for(int i=0;i<TAM;i++) //El primero para ir recorriendo el arreglo.
    {
    	for(int act=0;act<TAM;act++) //En este bucle, se declara una variable llamada act haciendo referencia al elemento actual del arreglo.
    	{
    		if(array[act]>array[act+1]) //Se necesita una condici�n para ir comparando los elementos. Si el elemento actual act es mayor que el siguiente, es decir act+1, se procede a utilizar la variable auxiliar.
    		{
    			//Para el intercambio de elementos.
    			aux=array[act]; //Ahora aux ser� el elemento actual.
    			array[act]=array[act+1]; //Y el elemento act ser� el elemento siguiente (act+1).
    			array[act+1]=aux; //El elemento siguiente ser� el auxiliar para volver a repetir todo el ciclo hasta el final.
			}
		}
	}
	//Para imprimir los elementos ordenados, basta con utilizar un bucle for de nuevo.
	cout<<"\nNumeros ordenados: "<<endl;
	for(int i=0; i<TAM; i++)
	{
		cout<<array[i]<<" ";
	}
	return 0;
}
//Fin del programa.
