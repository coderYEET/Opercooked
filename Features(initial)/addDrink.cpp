#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int currentMenu = 1;
struct pesanDrink
{
    char menuName[255];
    int menuPrice;
    char typeMenu[255];
    char menuSize[2];
    char menuFlavor[50];
    int drinkTime;
    OrderTime orderTime;
};

struct pesanDrink orderDrink[100];

void addDrink();

void addDrink(){
    strcpy(orderDrink[currentMenu].typeMenu, "Drink");
    char namaMenu[255], flavor[255];
    int price;
    char size[2];

    getchar();
    //input nama drink
    do {   
        printf ("Input the name [at least 5 characters]: ");
        scanf ("%[^\n]", namaMenu); getchar();
    }while(strlen(namaMenu) < 5);

    strcpy(orderDrink[currentMenu].menuName, namaMenu);

    //input harga
    do {
        printf ("Input the price [10 - 500]: $ "); 
        scanf ("%d", &price); getchar();
    }while(price < 10 || price > 500);

    orderDrink[currentMenu].menuPrice = price;

    //input flavor
    int flag = 0;
    do {   
        printf ("Input the flavor ['Mint' | 'Mix Berry' | 'Cheese'](Case Sensitive): ");
        scanf ("%s", flavor); getchar();
        if (strcmp("Mint", flavor) == 0 || strcmp("Mix Berry", flavor) == 0 || strcmp("Cheese", flavor) == 0){
            flag = 1;
        }
    }while(flag == 0);
    strcpy(orderDrink[currentMenu].menuFlavor, flavor);

    //input size
    flag = 0;
    do {
        printf ("Insert the size [S | M | L](Case Sensitive): ");
        scanf ("%s", size); getchar();
        if (strcmp("S", size) == 0 || strcmp("M", size) == 0 || strcmp("L", size)==0){
            flag = 1;
        }
    }while(flag == 0);

    strcpy(orderDrink[currentMenu].menuSize, size);

    orderDrink[currentMenu].drinkTime = (rand() % 41) + 10;
    if (strcmp(flavor, "Mint") == 0){
        orderDrink[currentMenu].drinkTime += 10;
    }
    else if(strcmp(flavor, "Mix Berry") == 0){
        orderDrink[currentMenu].drinkTime += 20;
    }
    else if(strcmp(flavor, "Cheese") == 0){
        orderDrink[currentMenu].drinkTime += 30;
    }

    printf("Successfully added a new menu!");
    getchar();
    currentMenu++;
}
