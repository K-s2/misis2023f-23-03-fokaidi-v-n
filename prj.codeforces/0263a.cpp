#include <iostream>
#include <vector>
int main()
{
    int a = 34, i, x, y;
    for (i = 0; i<= 25; i++)
    {
        std::cin>>a;
        if (a == 1){
            x = (i/5);
            y = (i%5);
            break;
        }
        
    }
    std::cout<<(abs(2 - x) + abs(2- y));
}
