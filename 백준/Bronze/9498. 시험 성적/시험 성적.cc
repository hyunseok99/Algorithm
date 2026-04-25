#include <stdio.h>

int main()
{
    int result;
    scanf("%d",&result);
    
    if(result>100 || result<0)
    {
        printf("점수를 잘못 입력했습니다.\n");
    }
    else if(result>=90)
    {
        printf("A");
    }
    else if(result>=80)
    {
        printf("B"); 
    }   
    else if (result>=70){
        printf("C");
    }
    else if (result>=60){
        printf("D");
    }
    else 
    {
        printf("F");
    }
    
    return 0;
}