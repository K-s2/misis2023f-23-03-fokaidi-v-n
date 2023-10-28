#include <iostream>
int main()
{
    int w, a1, a2, a3, a4, i;
    std::cin>>w;
    a1 = w%10;
    a2 = (w%100)/10;
    a3 = (w%1000)/100;
    a4 = (w/1000);
    for (i = w + 1; i <= 12346; i++)
    {
        a1 = i%10;
        a2 = (i%100)/10;
        a3 = (i%1000)/100;
        a4 = (i/1000);
        if (a1 != a2 and a1!= a3 and a1 != a4 and a2 != a3 and a2 != a4 and a3 != a4)
        {
            std::cout << i;
            break;
        }
    }
    
}
