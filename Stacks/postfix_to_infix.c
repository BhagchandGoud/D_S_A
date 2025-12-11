#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
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
    char str[] = "6435+*/9-";
    int n = strlen(str);
    for (int i = 0; i  < n; i++)
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
            char op[2] = {str[i], '\0'};
            strcat(temp, op);
                strcat(temp ,v1);


           pushVal(temp);
        }
       
    }

    printf("%s" ,val[top1]);
    return 0;
}