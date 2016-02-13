#include<iostream>

int main()
{

    int a = 10,count = 0;
    while(a)
    {
        if(a & 0x1)
        {
            count++;
        }
            a = a >> 1;
    }

    if( (count % 2) == 0)
    {
        std::cout<<"Even Parity"<<std::endl;
    }
    else
    {
        std::cout<<"Odd partiy"<<std::endl;
    }

   return 0; 
}
