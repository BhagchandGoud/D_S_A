#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    char str[] = "aabacbebebe";
    int strLength = strlen(str);
    int start =0 ,end = 0;
    int k =3 ;
    while (end < strLength)
    {
        int window_size  = end-start+1;
        
        
        if (window_size < k)
        {
            end++;
        }
        else if (window_size == k)
        {
            int count = 0;
           for (int i = start; i <= end; i++)
           {
            if ((unsigned char)str[i])
            {
                    count++;
            }
           }
           start++,end++;
                 printf("%d " ,count);
        }
    }
    return 0;
}