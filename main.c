#include<stdlib.h>
#include <stdio.h>
#include "binaryFile.h"

int main()
{
    /* code */
    int key;
    while (1)
    {    
        printf("1.insert()\n2.display()\n3.search()\n4.delete()\n5.exit()\n");
        printf("Enter the key => ");
        scanf("%d",&key);
        if (key == 1)
        {
            insert();
        }
        else if (key == 2)
        {
            display();
        }
        else if (key == 3)
        {
            search();
        }
        else if (key == 4)
        {
            delete();
        }
        else if (key == 5)
        {
            break;
            printf("THANK YOU\n");
        }
    }
    
    return 0;
}
