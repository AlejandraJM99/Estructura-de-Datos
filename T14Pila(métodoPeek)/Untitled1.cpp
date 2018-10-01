#include <iostream>
using namespace std;

class NumNatu
{
	public:
	void imprimir(int n)
	{
		n=n-1;
	}
};

int main()
{
	NumNatu num;
    num.imprimir(100);
}


