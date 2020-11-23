#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct pesanDessert{
    char typeMenu[255];
    char menuName[255];
    char topping[255];
    double calories;
    int currentMenu = 1;
    int menuPrice;
    int dessertTime;
};

int currentMenu = 1;
pesanDessert orderDessert[105];

void addDessert();

void addDessert(){
    strcpy(orderDessert[currentMenu].typeMenu, "Dessert");
    char namaMenu[255], toppingMenu[255];
    int price;
    double calorie;

    //input nama dessert
    getchar();
    do {
        printf ("Input the name [at least 5 characters]: ");
        scanf ("%[^\n]", namaMenu); getchar();
    }while(strlen(namaMenu) < 5);
    strcpy(orderDessert[currentMenu].menuName, namaMenu);

    //input harga
    do {
        printf ("Input the price [10 - 500]: $ "); 
        scanf ("%d", &price); getchar();
    }while(price < 10 || price > 500);
    orderDessert[currentMenu].menuPrice = price;

    //input topping
    int flag = 0;
    do {
        printf ("Input the topping ['Caramel' | 'Honey' | 'Syrup'](Case Insensitive): ");
        scanf ("%s", toppingMenu); getchar();
        if (toppingMenu[0] > 'Z') toppingMenu[0] -= 32;
        if(strcmp("Caramel", toppingMenu) == 0 || strcmp("Honey", toppingMenu) == 0 || strcmp("Syrup", toppingMenu) == 0){
            flag = 1;
        }
    }while(flag == 0);
    strcpy(orderDessert[currentMenu].topping, toppingMenu);

    //input kalori
    do {
        printf ("Insert calories [1.00 - 99.00]: ");
        scanf ("%lf", &calorie); getchar();
    }while(calorie < 1.00 || calorie > 99.00);
    orderDessert[currentMenu].calories = calorie;

    //Mencari dessertTime
    //random waktu pembuatan dessert
    srand(time(0));
    int totaltime = (rand() % 40)+50;

    if(strcmp(toppingMenu, "Caramel") == 0){
        totaltime += 10;
    }
    else if(strcmp(toppingMenu, "Honey") == 0){
        totaltime += 15;
    }
    else if(strcmp(toppingMenu, "Syrup") == 0){
        totaltime += 20;
    }

    orderDessert[currentMenu].dessertTime = totaltime;

    printf("\nSuccessfully added a new menu!");
    getchar();
    currentMenu++;
}