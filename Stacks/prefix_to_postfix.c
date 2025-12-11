#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define max 100


char val[max][max];
int top1 = -1 ;

void *pushVal(char * num){
 strcpy(val[++top1] , num);
}




char *popVal(){
    return val[top1--];
}

int main(){
    char str[] = "-9/*+5346";
    int n = strlen(str);
    for (int i = n - 1; i >= 0; i--)
    {
       if (isdigit(str[i]))
       {
        char temp[2] = {str[i] , '\0'};
         pushVal(temp);
       }
       else{
    
           char* v1 = popVal();
           char* v2 = popVal();


           char temp[max] = "";

                strcat(temp , v2);
                strcat(temp ,v1);

                  char op[2] = {str[i], '\0'};
            strcat(temp, op);

           pushVal(temp);
        }
       
    }

    printf("%s" ,val[top1]);
    return 0;
}