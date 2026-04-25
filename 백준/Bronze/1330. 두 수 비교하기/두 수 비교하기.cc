#include <stdio.h>

int main()
{
    int A;
    int B;
    scanf("%d %d",&A,&B);
    if((-10000<=A<=10000)&&(-10000<=B<=10000))
    {
        if(A>B)
            printf(">");
        else
        {
            if(A<B)
                printf("<");
            else printf("==");
        }
    }else printf("error");
    
    return 0;
}