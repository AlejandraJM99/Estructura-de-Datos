#include <iostream>
using namespace std;
int numnatu(int n)
{
    if(n<101)
    {
        cout<<n<<endl;
        return numnatu(n+1);
    }
}
int main()
{
    numnatu(1);
    return 0;
}
