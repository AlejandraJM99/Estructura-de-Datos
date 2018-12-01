#include<iostream>
#include<stdlib.h>
#include<ctime>
#define TAM 50
using namespace std;

void bubble(int [TAM]);
void quicksort(int [TAM], int, int);
void shellsort(int []);
void merge(int [], int, int, int);
void mergesort(int [], int, int);

int main()
{
	clock_t start;
	double duration;
	start = clock();
		
	int array[TAM], op;
	cout<<"Arreglo generado"<<endl;
	srand(time(0));
	for(int i = 0; i<TAM; i++)
	{
		array[i] = 1 + rand() % 999;
		cout<<" "<<array[i];
	}
	cout<<"\n\n\n";
	cout<<"1.Ordenar por bubblesort. \n2.Ordenar por quicksort. \n3.Ordenar por shellsort. \n4.Ordenar por mergesort.";
	cout<<"\n5.Salir. \n\nTu opcion es: ";
	cin>>op;
	do
	{
		switch(op)
		{
			case 1:
				system("cls");
				bubble(array);
				cout<<"Elementos ordenados por el metodo bubblesort"<<endl;
				for(int i = 0; i<TAM; i++)
				{
				cout<<array[i]<<" ";
				} 
				duration = (clock()-start)/(double) CLOCKS_PER_SEC;
				cout<<"\n\n\n";
				cout<<"La operacion tomo "<<duration<< "segundos"<<endl;
				system("pause");
			break;
			case 2:
				system("cls");
				quicksort(array, 0, 49);
				cout<<"Elementos ordenados por el metodo quicksort"<<endl;
				for(int i = 0; i<TAM; i++)
				{
				cout<<array[i]<<" ";
				}
				duration = (clock()-start)/(double) CLOCKS_PER_SEC;
				cout<<"\n\n\n";
				cout<<"La operacion tomo "<<duration<< "segundos"<<endl;
				system("pause");
			break;
			case 3:
				system("cls");
				shellsort(array); 
				cout<<"Elementos ordenados por el metodo shellsort"<<endl;
				for(int i = 0; i<TAM; i++)
				{
				cout<<array[i]<<" ";
				}
				duration = (clock()-start)/(double) CLOCKS_PER_SEC;
				cout<<"\n\n\n";
				cout<<"La operacion tomo "<<duration<< "segundos"<<endl;
				system("pause");
			break;
			case 4:
				system("cls");
				cout<<"Elementos ordenados por el metodo mergesort"<<endl;
				mergesort(array,0,49);
				for(int i=0;i<TAM;i++)
				{
				cout<<array[i]<<" "; 
				}
				duration = (clock()-start)/(double) CLOCKS_PER_SEC;
				cout<<"\n\n\n";
				cout<<"La operacion tomo "<<duration<< "segundos"<<endl;
				system("pause");		
			break;
			case 5:
			break;
			default: 
			cout<<"Error!";
		    return 0;
			break; 	
		}
	}while(op!=5);
}
void bubble(int array[TAM])
{
	int aux;
	for(int i=0;i<TAM;i++) 
    {
    	for(int act=0;act<TAM;act++) 
    	{
    		if(array[act]>array[act+1]) 
			{
    			aux=array[act]; 
    			array[act]=array[act+1]; 
    			array[act+1]=aux; 
			}
		}
	}
}
void quicksort(int array[TAM], int first, int last) 
{
	int pivote, centro, i, j, aux; 
	i = first; 
	j = last; 
	centro = ((first + last)/2); 
	pivote = array[centro]; 
	do	
	{
		while(array[i]<pivote) 
		{
			i++;
		}
		while(array[j]>pivote) 
		{
			j--;
		}
		if(i<=j)
		{
			aux = array[i]; 
			array[i] = array[j]; 
			array[j] = aux;
			i++; 
			j--;
		}
	}while(i<=j);
    
	if(first<j) 
	{
	quicksort(array,first,j); 
	}
	if(i<last)
	{
	quicksort(array,i,last);
	}
}
void shellsort(int array[]) 
{
	int saltos, i, aux; 
	bool b;
	saltos = TAM; 
	while(saltos>1) 
	{
		saltos=(saltos/2); 
		b = true;
		while(b==true) 
		{
			b=false;
			i = 0;
			while((i+saltos)<=TAM) 
			{
				if(array[i]>array[i+saltos]) 
				{
					aux = array[i];
					array[i] = array[i+saltos];
					array[i+saltos] = aux;
					b = true;
				}
				i++; 
			}
		}
	}
}
void merge(int array[], int p, int q, int r) 
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int k = p;
	int i = 0;
	int j = 0;
	int L[n1], R[n2]; 
	for(int i = 0; i < n1; i++)
	{
		L[i] = array[p+i]; 
	}
	for(int j = 0; j < n2; j++)
	{
		R[j] = array[q+1+j]; 
	}
	while(i < n1 and j < n2)
	{
		if(L[i]<=R[j]) 
		{
			array[k] = L[i];
			i++;
		}else
		{
			array[k] = R[j];
			j++; 
		}
		k++;
	}
	while(i<n1) 
	{
		array[k] = L[i];
		i++;
		k++;
	}
	while(j<n2) 
	{
		array[k] = R[j];
		j++;
		k++;
	}
}
void mergesort(int array[], int p, int r) 
{
	if(p<r) 
	{
		int q = ((p+r)/2); 
		mergesort(array,p,q); 
		mergesort(array,q+1,r); 
		merge(array,p,q,r); 
	}
}
