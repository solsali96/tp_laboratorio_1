#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void menu()
{
    int opcion;
    int a;
    int b;
    int suma;
    int resta;
    int mult;
    float div;
    int r1;
    int r2;
    int flagA = 0;
    int flagB = 0;
    int flagCuentas = 0;

    do
    {
        printf("Bienvenido! \n\nMenu de opciones\n\n");
        if(flagA == 0)
        {
            printf("1. Ingresar 1er operando : (A)\n");
        }
        else
        {
            printf("1. Ingresar 1er operando : (A=%d)\n",a);
        }

        if(flagB == 0)
        {
            printf("2. Ingresar 2do operando : (B)\n");
        }
        else
        {
            printf("2. Ingresar 2do operando : (B=%d)\n",b);
        }

        printf("3. Calcular todas las operaciones\n");
        printf("4. Informar resultados\n");
        printf("5. Salir\n");
        printf("\nElija una opcion : ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            a = pedirNumero("\nIngrese el primer numero : ");
            flagA = 1;
            flagCuentas = 0;
            printf("\n");
            break;
        case 2:
            b = pedirNumero("\nIngrese el segundo numero : ");
            flagB = 1;
            printf("\n");
            flagCuentas = 0;
            break;
        case 3:
            if(flagA == 0 || flagB == 0)
            {
                printf("\nIngrese los dos operandos antes de continuar\n\n");
            }
            else
            {
                printf("\nRealizando calculos...\n\n");
                suma = sumar(a,b);
                resta = restar(a,b);
                div = dividir(a,b);
                mult = multiplicar(a,b);
                r1 = factorial(a);
                r2 = factorial(b);
                flagCuentas = 1;
            }

            break;
        case 4:
            if(flagCuentas == 0)
            {
                printf("\nDebe realizar los calculos antes de mostrarlos\n\n");
            }
            else
            {
                printf("\nResultados :\n\n");
                printf("a) El resultado de %d+%d es: %d\n",a,b,suma);
                printf("b) El resultado de %d-%d es: %d\n",a,b,resta);

                if(div == 0)
                {
                    printf("No se puede dividir por cero\n");
                }
                else
                {
                    printf("c) El resultado de %d/%d es: %f\n",a,b,div);
                }

                printf("d) El resultado de %d*%d es: %d\n",a,b,mult);

                if(a > 12)
                {
                    printf("e) El resultado del factorial excede el permitido (12!)\n");
                }
                else
                {
                    if(a < 0)
                    {
                        printf("e) No se puede sacar el factorial de un numero negativo(%d)\n",a);
                    }
                    else
                    {
                        printf("e) El factorial de %d es: %d\n",a,r1);
                    }

                }

                if(b > 12)
                {
                    printf("Y El resultado del factorial excede el permitido (12!)\n\n");
                }
                else
                {
                    if(b < 0)
                    {
                        printf("Y No se puede sacar el factorial de un numero negativo (%d)\n\n",b);
                    }
                    else
                    {
                        printf("Y el factorial de %d es: %d\n\n",b,r2);
                    }

                }


            }

            break;
        case 5:
            printf("\nHasta luego!\n\n");
            break;
        default:
            printf("\nOpcion incorrecta, intente nuevamente\n\n");
        }

        system("pause");
        system("cls");

    }
    while (opcion != 5);

}

int pedirNumero(char mensaje[])
{
    int numero;
    printf("%s",mensaje);
    scanf("%d",&numero);

    return numero;
}

int sumar(int a,int b)
{
    int resp;
    resp = a + b;

    return resp;
}

int restar(int a,int b)
{
    int resp;
    resp = a - b;

    return resp;
}

float dividir(int a,int b)
{
    float resp;
    if(a == 0 || b == 0)
    {
        resp = 0;
    }
    else
    {
        resp = (float)a / b;
    }

    return resp;
}

int multiplicar(int a,int b)
{
    int resp;
    resp = a * b;

    return resp;
}


int factorial(int n)
{
    int resp;
    if(n < 0)
    {
        resp = 0;
    }
    else
    {
        if(n == 0)
        {
            resp = 1;
        }
        else
        {
            resp = n * factorial(n-1);
        }
    }

    return resp;
}
