
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>


int global=0;

void pene_aleatorio(int matriu[][10],int files,int columnes,int parelles)/*******/
{
    int i,p,x,y,g,h,ocupado; int taula[parelles*2]; srand(time(NULL));
    for (p=0; p<(parelles*2); p++)
        {
            if ((p)<(parelles))
            {
                taula[p]= p+1;
            }
            else
            {
                taula[p]=p+1-parelles;
            }
        }
    for (i=0;i<(parelles*2);i++)
        {
            ocupado=0;
            while (ocupado!=1)
                {
                x=rand()%files;
                y=rand()%columnes;
                g=x;
                h=y;
                if (matriu[g][h]==0)
                {
                    matriu[g][h]=taula[i];
                    ocupado=ocupado+1;
                }
                }
        }
}

void poner_ceros(int matriu[][10],int files,int columnes)/*****/
{
    int f,c;
    for (f=0;f<files;f++)
        {
            for (c=0;c<columnes;c++)
            {
                matriu[f][c]=00;
            }
        }
}

void cambiar_numeros(int matriu[][10],int files,int columnes,int x,int y)/*************/
{
    int f,c;
    for (f=0;f<files;f++)
        {
            for (c=0;c<columnes;c++)
            {
                if ((matriu[f][c]==x)||(matriu[f][c]==y))
                {
                    matriu[f][c]=-1;
                }
            }
        }
}

void poner_numeros(int matriu[][10],int files,int columnes)/**************/
{
    int f,c,p;p=1;
    for (f=0;f<files;f++)
        {
            for (c=0;c<columnes;c++)
            {
               matriu[f][c]=p;
               p=p+1;
            }
        }
}

void mostrar_tabla (int matriz[][10], int F, int C)/*************/
{
    int i, j, valor=-1;

    for (i=0; i<F; i++)
    {
        for (j=0; j<C; j++)
        {
            valor=matriz[i][j];
            printf("|%2.i|", valor);
        }
        printf("\n");
    }
}


int mostrar_parejas(int uno[][10],int dos[][10],int ceros[][10],int P,int F, int C)/*********/
    {
        int n1, n2, i, j, x, y, contar=0, m, n;
        int pasar;

        mostrar_tabla(uno, F, C);

        printf("\nQue pareja de números quieres seleccionar(separa por espacios)?");
        scanf("%d", &n1);
        scanf("%d", &n2);
        system("cls");

        while ((n1<1)||(n1>P*2)||(n2<1)||(n2>P*2)||(n1==n2))
        {
            printf("Error.Que pareja de números quieres seleccionar(separa por espacios)?");
            scanf("%d", &n1);
            scanf("%d", &n2);
            system("cls");
        }
        for(i=0; i<F; i++)
        {
            for(j=0; j<C; j++)
            {
                if (uno[i][j]==n1)
                    {
                        ceros[i][j]=dos[i][j];
                        x=dos[i][j];
                        m=uno[i][j];
                    }
                if (uno[i][j]==n2)
                    {
                        ceros[i][j]=dos[i][j];
                        y=dos[i][j];
                        n=uno[i][j];
                    }
            }
        }
        mostrar_tabla(ceros, F, C); scanf("%d", &pasar); system("cls");
        if(x==y)
        {
            contar++;
            cambiar_numeros(uno, F, C, m, n);
            global++;
        }
        return contar;
    }


int game_over (int numeros[][10], int F, int C)/*************/
{
    int i, j=0, boolea=1; //joc finalitza

    for (i=0; i<F; i++)
    {
        while (j<C)
        {
            if (numeros[i][j]!=(-1))
            {
                boolea=0; //joc segueix
            }
             j++;
        }
        j=0;
    }
    return (boolea);
}

void siguiente_tirada(int uno[][10],int dos[][10],int ceros[][10],int P,int F, int C, int *j1_2, int *j2_2)/***************************/
{
    bool guay=true, guay2=true;
    int contar, fin=0;
    while (fin==0)
    {
        guay=true;
        guay2=true;

       while(guay)
       {
           printf("jugador 1\n");
           printf("Tabla de posiciones de las cartas:\n");
           contar=0;
           contar=mostrar_parejas(uno, dos, ceros, P, F, C);
           poner_ceros(ceros, F, C);
           *j1_2=*j1_2+contar;
           if((global==P)||(contar==0))
           {
             guay=false;
           }
           fin=game_over(uno, F, C);
       }
    if (fin==0)
    {
        while(guay2)
        {
            printf("jugador 2\n");
            printf("Tabla de posiciones en las cartas:\n");
            contar=0;
           contar=mostrar_parejas(uno, dos, ceros, P, F, C);
           poner_ceros(ceros, F, C);
           *j2_2=*j2_2+contar;
           if((contar==0)||(global==P))
           {
             guay2=false;
           }
           fin=game_over(uno, F, C);
        }
    }
    }
}

void crear_matriz(int x, int *fil, int *col)/*:)*/
{
    int z, y;
    z=x*2;
    y=sqrt(z);
    if((y*y)==z){

       *fil=y;
       *col=y;

}   else

    while(z%y!=0){
        y++;

    }

    *fil=y;
    *col=z/y;

 }



int guanyador (int contador1, int contador2)/***************/
{
    int guanyador=0;

    if (contador1>contador2) guanyador=1;
    else guanyador=2;
    return (guanyador); //a l'hora d'escriure el guanyador en el main, escriure "jugador" abans del resultat en plan escriure("el guanyador es el jugador: ", guanyador)
}


int main()
{
    int matriz_zero[10][10];int matriz_valores[10][10];int matriz_numeros[10][10], parejas, fil, col, jugador1=0, jugador2=0, putoamott;         //esto guapos es para comprobar el mostrar_tabla aaaaaaaaaaand guess what? IT WORKS!
    int pasar, x; bool buclesico=true;

    printf("||     ||          _____                            __________       ||||   \n");
    printf("||     ||         /     \\        ||               ||          ||    ||||   \n");
    printf("||     ||        /       \\       ||               ||          ||     ||||   \n");
    printf("||     ||       /         \\      ||               ||          ||    ||||   \n");
    printf("||     ||      /           \\     ||               ||          ||     ||||   \n");
    printf("||-----||     |             |    ||               ||----------||    ||||  \n");
    printf("||     ||      \\           /     ||               ||          ||     ||||   \n");
    printf("||     ||       \\         /      ||               ||          ||           \n");
    printf("||     ||        \\       /       ||               ||          ||    ****   \n");
    printf("||     ||         \\_____/         _____________   ||          ||     ****   \n");
    printf(" \n");
    printf("                      _____   ______  __     ____   ___      ____     __ \n");
    printf("      || ||     ||  //       ||    | || \\  ||    | ||   \\   ||       /    \n");
    printf("      || ||     || ||        ||    | ||  | ||    | ||   ||  ||      |    \n");
    printf(" ||   || ||     || || _____  ||____| ||  | ||    | ||___/   ||===    \\   \n");
    printf("  \\   // ||     ||  \\     || ||    | || /  ||    | ||   \\   ||        | \n");
    printf("   \\__//  \\____//    \\___//  ||    | ||/   ||____| ||    \\  ||____  __/    \n");

    printf("\nMenu:\n");
    printf("1: Instrucciones\n");
    printf("2: Jugar\n");
    printf("3: Salir\n");
    printf("Selecciona la opcion\n\n");
    scanf("%i", &x);
    while(buclesico)
    {
    switch (x)
    {
        case 1: //instrucciones

            printf("1: La consola te pedira el numero de parejas con el que se formara la tabla para jugar, deben ser entre 3 y 50.\n\n");
            printf("2: Para avanzar por el juego debes introducir cualquier numero y darle a la tecla 'intro'.\n\n");
            printf("3: Aparecera la tabla con las parejas descubiertas, cuando estes listo para empezar, avanza.\n\n");
            printf("4: Las parejas se esconderan, selecciona las posiciones (indicadas con numeros) de la pareja que deseas descubrir.\n\n");
            printf("5: Cuando aciertes una pareja esta aparecera con -1 en la tabla.\n\n");
            printf("6: Una vez todas las parejas hayan sido descubiertas el juego terminara y te indicara el ganador.\n\n");
            printf("7: Avanza por los diferentes mensajes finales ;)\n\n");
            scanf("%d", &pasar); system("cls");
         break;
        case 2: //jugar

    printf("\nCuantas parejas quieres?");
    scanf("%d", &parejas);
    while((parejas<3)||(parejas>50))
    {
        printf("El numero de parejas va de 3 a 50, por favor elije un valor entre esos.");scanf("%d", &parejas);
    }
    system("cls");


    crear_matriz(parejas, &fil, &col);
    poner_ceros(matriz_zero, fil, col);
    poner_numeros(matriz_numeros, fil, col);
    poner_ceros(matriz_valores,fil, col);
    pene_aleatorio(matriz_valores, fil, col, parejas);
    printf("Tabla con los valores de las cartas:\n");

    mostrar_tabla(matriz_valores, fil, col);
    printf("\nEmpieza el jugador uno\n");
    scanf("%d", &pasar); system("cls");
    siguiente_tirada(matriz_numeros, matriz_valores, matriz_zero, parejas, fil, col, &jugador1, &jugador2);
    putoamott=guanyador(jugador1, jugador2);
    printf("Enhorabuena!! El ganador es el jugador: \t%d", putoamott);
    printf("\nEres el puto am@ tio, gracias por jugar a este juego!!");
    scanf("%d", &pasar); system("cls");
    printf("AUTODESTRUCIÓN EN...");
    scanf("%d", &pasar); system("cls");
    printf("3");
    scanf("%d", &pasar); system("cls");
    printf("2");
    scanf("%d", &pasar); system("cls");
    printf("1");
scanf("%d", &pasar); system("cls");
    printf("Que noo!! te trollie JAJAJAJA como se siente que una maquina te la lie? :P");
scanf("%d", &pasar); system("cls");
    printf("Porque sigues aqui? tio, que se ha acabado ya, vete!");
scanf("%d", &pasar); system("cls");
    printf("No te aburres? Vete a jugar al LoL o... a tocarte...");
scanf("%d", &pasar); system("cls");
    printf("Enfin, yo me voy, adios, te dejo con tu vida taaaaaaaan interesante :D");
    scanf("%d", &pasar); system("cls");

            break;
        case 3:

             return 0;
            break;
            }


    printf("\nMenu:\n");
    printf("1: Instrucciones\n");
    printf("2: Jugar\n");
    printf("3: Salir\n");
    printf("Selecciona la opcion\n\n");
    scanf("%i", &x);
    }
return 0;
}

