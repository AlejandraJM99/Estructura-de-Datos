#include <iostream>
#include<stdlib.h>
using namespace std;
class Pila
{
    int arraypi[5], index;
    public:
    Pila()
    {
        index = -1;
    }
    void push(int x)
    {
        if(index>5)
        {
            system("CLS");
            cout<<"Pila llena!! No se pudieron agregar mas elementos"<<endl;
            return;
        }
        arraypi[++index]=x;
        cout<<"Elemento "<<x<<" ingresado"<<endl;
    }
};
int main()
{
    int op,op2;
    Pila pil;
    do
    {
        cout<<"1.Agregar elementos a la pila \n2.Salir"<<endl;
        cout<<"Tu opcion es: ";
        cin>>op;
        switch(op)
        {
        case 1:
            system("CLS");
            cout<<"Ingresa un elemento: ";
            cin>>op2;
            pil.push(op2);
        break;
        case 2:
        break;
        }
    }while(op!=2);
}

