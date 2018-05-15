#include<stdio.h>
#include<stdlib.h>

int main(){
    int t;
    scanf("%d",&t);
    // n <= 10^5
    long int n;
    scanf("%ld",&n);
    //after check ;
    // how space and newlind read
    long int a[n];
    for (int i= 0; i < n; i++) {
       scanf("%ld",&a[i]);
    }
    int xor, b[n*n];

    for (int i= 0; i < n; i++) {
         for (int j= 0; i < n; i++) {
            int btmp = b[i*n + j +1] = a[i+1] + a[j+1];
             xor ^= btmp;
          }
          
    }
    //return xor      
    printf("%d",xor);
    return 0;
    
}
