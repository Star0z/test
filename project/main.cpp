#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x,y;
    
    cin>>x;
    
    y = 1 - x;
    
    cout<<floor((1 - y) * 10);
    
    return 0;
    
}
