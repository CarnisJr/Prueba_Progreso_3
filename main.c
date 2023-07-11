#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BATMANMAXASIENTOSNORMALES 30
#define BATMANMAXASIENTOSVIP 15
#define BATMANMAXASIENTOS3D 5

#define AVENGERSMAXASIENTOSNORMALES 40
#define AVENGERSMAXASIENTOSVIP 20
#define AVENGERSMAXASIENTOS3D 10

#define PRECIONORMAL 8
#define PRECIOVIP 15
#define PRECIO3D 12

int main (void){

    //Usuarios y contraseñas
    char usuario1[10] = "Usuario1";
    char contrasenia1[10] = "usuario1";
    char usuario2[10] = "Usuario2";
    char contrasenia2[10] = "usuario2";
    char usuario3[10] = "Usuario3";
    char contrasenia3[10] = "usuario3";

    //VAriables para el login
    int errores = 0;
    char usuario[10], contrasenia[10];

    //Variables menu
    int selector, selectorPelicula, selectorSala, flag = 0;
    int cantEntradas;


    //Variables estadisticas
    float precioPagado = 0, precioAPagar = 0;
    int cantAsientosTotal;

    //lOGIN
       do
    {
        printf("Ingresa el usuario: ");
        scanf("%s", usuario);
        printf("Ingresa la contrasenia: ");
        scanf("%s", contrasenia);

        if(strcmp(usuario, usuario1) != 0 || strcmp(usuario2, usuario) != 0 || strcmp(contrasenia, contrasenia1) != 0 
            || strcmp(usuario3, usuario) != 0 || strcmp(contrasenia2, contrasenia) != 0 || strcmp(contrasenia3, contrasenia) != 0){
            errores++;
            flag = 1;
            printf("Usuario o contrasenia incorrectos, intento #%d\n", errores);
            if(errores == 3){

                printf("Imposible ingresar\n");
                exit(1);
            }
        }else{
            flag = 0;
        }

    } while (errores < 3 || flag == 0);
        
    //Menu
    do{

        printf("---MENU---\n\n");
        printf("1. Venta de entradas\n2. Estadisticas de venta\n3. Salir\n\n");
        scanf("%d", &selector);
        system("cls");

        switch (selector)
        {
        case 1:
            printf("---Venta de entradas---\n\n");

            //Seleccionar pelicula
            do
            {
                printf("---Peliculas en cartelera---\n\n");
                printf("1. Batman\n2. Avengers\n3. SALIR\n\n");
                scanf("%d", &selectorPelicula);
                system("cls");

                switch (selectorPelicula)
                {
                case 1:
                    printf("Pelicula Batman\n\n");
                    
                    do
                    {
                        printf("Elija el tipo de sala\n\n");
                        printf("1. Normal\n2. VIP\n3. 3D\n4. SALIR\n\n");
                        scanf("%d", &selectorSala);
                        system("cls");

                        switch (selectorSala)
                        {
                        case 1:
                            printf("Usted escogio la sala normal\nIngresa la cantidad de entradas a comprar: ");
                            scanf("%d", &cantEntradas);

                            if(cantEntradas > BATMANMAXASIENTOSNORMALES){
                                printf("No hay esa cantidad de asientos\n\n");
                                system("pause");
                                system("cls");
                            }else{

                                precioAPagar = cantEntradas * PRECIONORMAL;

                                if (precioAPagar < 80 && precioAPagar >= 40)
                                {
                                    precioAPagar = precioAPagar * 0.95;   
                                }else if( precioAPagar < 120 && precioAPagar >= 80){

                                    precioAPagar = precioAPagar * 0.90;   
                                }else if( precioAPagar >= 120){

                                    precioAPagar = precioAPagar * 0.85;   
                                }

                                precioPagado += precioAPagar;
                                cantAsientosTotal += cantEntradas;
                                printf("Precio a pagar: %.f\n", precioAPagar);
                                precioAPagar = 0;

                                
                            }

                            system("pause");
                            system("cls");

                            break;
                        case 2:
                            printf("Usted escogio la sala VIP\nIngresa la cantidad de entradas a comprar: ");
                            scanf("%d", &cantEntradas);
                            if(cantEntradas > BATMANMAXASIENTOSVIP){
                                printf("No hay esa cantidad de asientos\n\n");
                                system("pause");
                                system("cls");
                            }else{


                                precioAPagar = cantEntradas * PRECIOVIP;
                                if (precioAPagar < 80 && precioAPagar >= 40)
                                {
                                    precioAPagar = precioAPagar * 0.95;   
                                }else if( precioAPagar < 120 && precioAPagar >= 80){

                                    precioAPagar = precioAPagar * 0.90;   
                                }else if( precioAPagar >= 120){

                                    precioAPagar = precioAPagar * 0.85;   
                                }

                                precioPagado += precioAPagar;
                                cantAsientosTotal += cantEntradas;
                                printf("Precio a pagar: %.f", precioAPagar);
                                precioAPagar = 0;

                            }
                            
                            system("pause");
                            system("cls");

                            break;
                        case 3:
                            printf("Usted escogio la sala 3D\nIngresa la cantidad de entradas a comprar: ");
                            scanf("%d", &cantEntradas);
                            if(cantEntradas > BATMANMAXASIENTOS3D){
                                printf("No hay esa cantidad de asientos\n\n");
                                system("pause");
                                system("cls");
                            }else{

                                precioAPagar = cantEntradas * PRECIO3D;
                                if (precioAPagar < 80 && precioAPagar >= 40)
                                {
                                    precioAPagar = precioAPagar * 0.95;   
                                }else if( precioAPagar < 120 && precioAPagar >= 80){

                                    precioAPagar = precioAPagar * 0.90;   
                                }else if( precioAPagar >= 120){

                                    precioAPagar = precioAPagar * 0.85;   
                                }
                                
                                precioPagado += precioAPagar;
                                cantAsientosTotal += cantEntradas;
                                printf("Precio a pagar: %.f", precioAPagar);
                                precioAPagar = 0;
                            }
                            
                            system("pause");
                            system("cls");

                            break;
                        case 4:
                            printf("Saliendo...\n\n");
                            system("pause");
                            system("cls");
                            break;
                        default:
                            printf("Opcion no valida...\n\n");
                            system("pause");
                            system("cls");
                            break;
                        }
                    } while (selectorSala != 4);

                    break;
                case 2:

                    printf("Pelicula Avengers\n\n");
                    
                    do
                    {
                        printf("Elija el tipo de sala\n\n");
                        printf("1. Normal\n2. VIP\n3. 3D\n4. SALIR\n\n");
                        scanf("%d", &selectorSala);
                        system("cls");

                        switch (selectorSala)
                        {
                        case 1:
                            printf("Usted escogio la sala normal\nIngresa la cantidad de entradas a comprar: ");
                            scanf("%d", &cantEntradas);

                            if(cantEntradas > AVENGERSMAXASIENTOSNORMALES){
                                printf("No hay esa cantidad de asientos\n\n");
                                system("pause");
                                system("cls");
                            }else{


                                precioAPagar = cantEntradas * PRECIONORMAL;
                                if (precioAPagar < 80 && precioAPagar >= 40)
                                {
                                    precioAPagar = precioAPagar * 0.95;   
                                }else if( precioAPagar < 120 && precioAPagar >= 80){

                                    precioAPagar = precioAPagar * 0.90;   
                                }else if( precioAPagar >= 120){

                                    precioAPagar = precioAPagar * 0.85;   
                                }

                                precioPagado += precioAPagar;
                                cantAsientosTotal += cantEntradas;
                                printf("Precio a pagar: %.f", precioAPagar);
                                precioAPagar = 0;

                            }

                            system("pause");
                            system("cls");

                            break;
                        case 2:
                            printf("Usted escogio la sala VIP\nIngresa la cantidad de entradas a comprar: ");
                            scanf("%d", &cantEntradas);
                            if(cantEntradas > AVENGERSMAXASIENTOSVIP){
                                printf("No hay esa cantidad de asientos\n\n");
                                system("pause");
                                system("cls");
                            }else{

                                precioAPagar = cantEntradas * PRECIOVIP;
                                if (precioAPagar < 80 && precioAPagar >= 40)
                                {
                                    precioAPagar = precioAPagar * 0.95;   
                                }else if( precioAPagar < 120 && precioAPagar >= 80){

                                    precioAPagar = precioAPagar * 0.90;   
                                }else if( precioAPagar >= 120){

                                    precioAPagar = precioAPagar * 0.85;   
                                }

                                precioPagado += precioAPagar;
                                cantAsientosTotal += cantEntradas;
                                printf("Precio a pagar: %.f", precioAPagar);
                                precioAPagar = 0;

                            }
                            
                            system("pause");
                            system("cls");

                            break;
                        case 3:
                            printf("Usted escogio la sala 3D\nIngresa la cantidad de entradas a comprar: ");
                            scanf("%d", &cantEntradas);
                            if(cantEntradas > AVENGERSMAXASIENTOS3D){
                                printf("No hay esa cantidad de asientos\n\n");
                                system("pause");
                                system("cls");

                            }else{

                                precioAPagar = cantEntradas * PRECIO3D;
                                if (precioAPagar < 80 && precioAPagar >= 40)
                                {
                                    precioAPagar = precioAPagar * 0.95;   
                                }else if( precioAPagar < 120 && precioAPagar >= 80){

                                    precioAPagar = precioAPagar * 0.90;   
                                }else if( precioAPagar >= 120){

                                    precioAPagar = precioAPagar * 0.85;   
                                }
                                
                                precioPagado += precioAPagar;
                                cantAsientosTotal += cantEntradas;
                                printf("Precio a pagar: %.f", precioAPagar);
                                precioAPagar = 0;

                            }
                            
                            system("pause");
                            system("cls");

                            break;
                        case 4:
                            printf("Saliendo...\n\n");
                            system("pause");
                            system("cls");
                            break;
                        default:
                            printf("Opcion no valida...\n\n");
                            system("pause");
                            system("cls");
                            break;
                        }
                    } while (selectorSala != 4);

                    break;

                case 3: 
                    printf("Saliendo...\n\n");
                    system("pause");
                    system("cls");
                    break;
                default:
                    printf("Opcion no valida\n\n");
                    system("pause");
                    system("cls");
                    break;
                }
            } while (selectorPelicula != 3);
            

        case 2:
            printf("--Estadisticas de venta--\n\n");

            printf("Cantidad de entradas compradas: %d\n", cantAsientosTotal);
            printf("Dinero pagado: $%.f\n", precioPagado);
            system("pause");
            system("cls");

        
            break;

        case 3:
            printf("SALIENDO\n\n");
            system("pause");
            system("cls");

            break;

        default:
            printf("Opcion no valida\n\n");
            system("pause");
            system("cls");
            break;
        }  
    } while (selector != 3);
    



    return 0;
}