#include <iostream>

using namespace std;

int main()
{
    double y, x1, x2;
    
    cin>>x1;
    cin>>x2;
    
    y = (exp(-x1)) + exp(-x2)) / 2;
    
    cout<<y;

    return 0;
}
