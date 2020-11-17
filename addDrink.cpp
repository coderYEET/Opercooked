#include <stdio.h>
#include <string.h>

struct OrderTime
{
    int year,month,date,hour,min,sec;
    char form[3];
};

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

int currentMenu = 1;

pesanDrink orderDrink[105];

void addDrink();

void addDrink(){
    
    strcpy(orderDrink[currentMenu].typeMenu, "Drink");
    char namaMenu[255], toppingDrink[255];
    int price;
    char size[2];
    
    //input nama drink
    while(1)
    {
    
        fflush(stdin);    
        printf ("Input the name [at least 5 characters]: ");
        scanf ("%[^\n]", namaMenu); getchar();
        if (strlen(namaMenu) >= 5) break;
    }
    strcpy(orderDrink[currentMenu].menuName, namaMenu);
    
    //input harga
    while(1)
    {
        fflush(stdin);
        printf ("Input the price [10 - 500]: $ "); 
        scanf ("%d", &price); getchar();
        if (price >= 10 && price <= 500) break;
    }
    orderDrink[currentMenu].menuPrice = price;

    //input flavor
    while(1)
    {   
        fflush(stdin);
        printf ("Input the topping ['Mint' | 'Mix Berry' | 'Cheese'](Case Sensitive): ");
        scanf ("%s", toppingDrink); getchar();
        if (strcmp("Mint", toppingDrink) == 0 || strcmp("Mix Berry", toppingDrink) == 0 || strcmp("Cheese", toppingDrink) == 0) break;
    }
    strcpy(orderDrink[currentMenu].menuFlavor, toppingDrink);

    //input size
    while(1)
    {
        fflush(stdin);
        printf ("Insert the size [S | M | L](Case Sensitive): ");
        scanf ("%s", size); getchar();
        if (strcmp("S", size) == 0 || strcmp("M", size) == 0 || strcmp("L", size)==0) break;
    }
    strcpy(orderDrink[currentMenu].menuSize, size);
    printf("Successfully added a new menu!");
    getchar();
    currentMenu++;
}