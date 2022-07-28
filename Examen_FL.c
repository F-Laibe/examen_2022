#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include <semaphore.h>

// ()___()
// (° x °)
// (u___u)
//  U   U

typedef struct Cubo
{
int hash;
}bloque;

bloque operacion[10];
int contGlobal = 0;

void *facto1(void* Operation_1)
{
    int numero = (int) operacion[contGlobal].hash;
    int a=1;
    for(int i=1;i<numero;i++)
    {
        a=a*i;
    }
    printf("a=%d\n",a);
    pthread_exit (( void *) a ) ;
}

void *facto2(void* Operation_2)
{
    int numero2 = (int) operacion[contGlobal].hash +1;
    int b=1;
    for(int i=1;i<=numero2;i++)
    {
        b=b*i;
    }
    printf("b=%d\n",b);
    pthread_exit (( void *) b ) ;
}
void *facto3(void* ase)
{
    int numero3 = (int) operacion[contGlobal].hash +2;
    int c=1;
    for(int i=1;i<numero3;i++){
        c=c*i;
    }
    printf("c=%d\n",c);
    pthread_exit (( void *) c ) ;
}

int Other()
{
    int a,b,c;
    pthread_t t1, t2, t3;
    pthread_create(t1, NULL, &facto1, (void*)operacion[contGlobal].hash);
    pthread_create(t1, NULL, &facto2, (void*)operacion[contGlobal].hash);
    pthread_create(t1, NULL, &facto3, (void*)operacion[contGlobal].hash);
    pthread_join(&facto1, (void**)  &a);
    pthread_join(&facto2, (void**)  &b);
    pthread_join(&facto3, (void**)  &c);
    int nuevoHash=a+b+c;
    return nuevoHash;
}

int main()
{
    pid_t pid;
    srand(getpid());
    int cantProcesos,i,menu,hashNuevo;
    operacion[contGlobal].hash = rand() %9 +1;
    printf("Inserte la cantidad de operaciones que desea:\n");
    scanf("%d",&cantProcesos);
    for(i=0;i<cantProcesos;i++)
    {
        pid = forOperation_2();
        if(pid==0){
            exit(Other());
        }
    }
    hashNuevo = WEXITSTATUS((int)Other);
    operacion[contGlobal+1].hash=hashNuevo;
    printf("Se ha creado la transacción. Hash anterior: %d. Hash actual: %d\n",operacion[contGlobal].hash,operacion[contGlobal+1].hash);
    contGlobal++;
}