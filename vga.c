#include <stdio.h>
#include <math.h>

typedef enum { false, true } bool;

int size = 3;   // 3 dimensions

// Distancia entre dois pontos p1 e p2
double dist_points(double p1[], double p2[])
{
    double d=0;
    for (int i=0; i<size; i++)
        d += pow(p2[i]-p1[i], 2.0);
    return sqrt(d);
}

// Componentes do vetor v através
//   das coordenadas de dois pontos p1 e p2
void vector(double p1[], double p2[], double v[])
{
    for (int i=0; i<size; i++)
       v[i] = p2[i] - p1[i];
}

// Módulo (magnitude) do vetor v)
double mod_vector(double v[])
{
    double m=0;
    m = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
    return m;
}

// Soma entre v1 e v2
void sum_vector(double v1[], double v2[], double vr[])
{
    for (int i=0; i<size; i++)
        vr[i] = v1[i] + v2[i];
}

// Produto entre um escalar e um vetor
void escXvector(double esc, double v[], double vr[])
{
    for (int i=0; i<size; i++)
        vr[i] = esc*v[i];
}

// vetor unitario
void unit_vector(double v[], double u[])
{
    double mod = mod_vector(v);
    for (int i=0; i<size; i++)
        u[i] = v[i] / mod;
}

// produto escalar entre vetores
double prod_esc(double v1[], double v2[])
{
    double r=0;
    for (int i=0; i<size; i++)
        r += v1[i]*v2[i];
    return r;

}

int main(){
    double v1[3] = {1,2,3};
    double v2[3] = {4,5,6};
    double vr1[3], vr2[3], vr3[3], vu[3];
    double d, m, r;

    printf("Digite as componentes de 2 vetores em 3 dimensoes\nVetor A: ");
    //scanf("%d %d %d", &v1[0], &v1[1], &v1[2]);
    printf("Vetor B: ");
    //scanf("%d %d %d", &v2[0], &v2[1], &v2[2]);
    printf("\n");
    d = dist_points(v1, v2);
    r = prod_esc(v1, v2);
    m = mod_vector(v1);
    vector(v1, v2, vr1);
    sum_vector(v1, v2, vr2);
    escXvector(10, v1, vr3);
    unit_vector(v1, vu);
    
    printf("       Vetor  Vetor soma   esc*Vetor Vetor unit.\n");
    for (int i=0; i<size; i++){
        printf("%10.3lf  %10.3lf  %10.3lf  %10.3lf  \n", vr1[i], vr2[i], vr3[i], vu[i]);
    }
    printf("\n");
    printf("Distancia entre pontos:         %.3lf\n", d);
    printf("Modulo de vA:                   %.3lf\n", m);
    printf("Produto escalar:                %.3lf\n", r);

    return 0;
}
