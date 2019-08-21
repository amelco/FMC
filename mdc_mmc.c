#include <stdio.h>

typedef enum { false, true } bool;

int euclides(int a,   int b,    // numeros de entrada
             int* pa, int* pb)  // ponteiros de saida (novos a e b)
{   
    int q=0, r=0, aux=0;
    if (b>a) {
        aux=a;
        a=b;
        b=aux;
    }
    if (a%b==0) {
        printf("Os numeros nao podem ser divisiveis.\n"); 
        return false;
    }
    // printf("MDC(%d, %d)\n", a, b);
    q = a/b;
    r = a%b;
    // printf("a = %6d  b = %6d  q = %6d  r = %6d\n", a, b, q, r);
    *pa = b;
    *pb = r;
    return true;
}

int mdc(int a,   int b) 
{   
    int pa=0, pb=0;
    do {
        if (!euclides(a, b, &pa, &pb)) return false;
        a = pa;
        b = pb;
    } while (a%b > 0);
    return pb;

}

int mmc(int a, int b){
    if (!mdc(a, b)) return false;
    return a*b/mdc(a, b);
}

int isPrime(int a){
    int i;
    if (a < 2) return false;
    for (i=2; i*i<=a; i++){
        if (a%i == 0) return false;
    }
    return true;
}

int main(){
    int a, b;
    printf("Calcula MDC e mmc entre 2 números e verifica se sao primos\nDigite 2 números inteiros\n");
    scanf("%d %d", &a, &b);

    printf("MDC(%d, %d) = %d\n", a, b, mdc(a, b));
    printf("mmc(%d, %d) = %d\n", a, b, mmc(a, b));
    
    if (isPrime(a)) printf("%d é primo\n", a);
    if (isPrime(b)) printf("%d é primo\n", b);
    
    return 0;
}
