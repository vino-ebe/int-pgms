#include<iostream>

enum color
{
    red,
    blue,
    yellow 
};

typedef struct numsandcolors
{
    int num;
    color c;
}numsandcolors;

int main()
{
    numsandcolors nc[5];

    nc[0].num = 1;
    nc[0].c = blue; 
    nc[1].num = 3;
    nc[1].c = red;
    nc[2].num = 4;
    nc[2].c = blue;
    nc[3].num = 6;
    nc[3].c = yellow;
    nc[4].num = 9;
    nc[4].c = red;

    int i = 0, j = 1;

    int redroot = 0, int blueroot = 0, int yellowroot = 0;

    while (j < 5)
    {
        if (nc[i].color > nc[j].color)
        {
            swap(nc, i, j);

            if (nc[i].color == red)
            {
                if (!redroot)
                {
                    redroot = i;
                }
                else
                {
                    // bubble up to next of redroot
                    if (i != redoot + 1)
                    {
                        swap(nc,i, redroot+1);
                    }
                }
            }

            if (nc[i].color == blue)
            {
                if (!blueroot)
                {
                    blueroot = i;
                }
            }
        }
        i++;
        j++;
    }


