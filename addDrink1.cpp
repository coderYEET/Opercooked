#include <stdio.h>
#include <string.h>


char menuName[100][255];
int menuPrice[100];
int currentMenu = 1;
char typeMenu[100][255];
char menuSize[100][2];
char menuFlavor[100][50];

void addDrink();

void addDrink(){
    strcpy(typeMenu[currentMenu], "Drink");
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
    strcpy(menuName[currentMenu], namaMenu);

    //input harga
    while(1)
    {
        fflush(stdin);
        printf ("Input the price [10 - 500]: $ "); 
        scanf ("%d", &price); getchar();
        if (price >= 10 && price <= 500) break;
    }
    menuPrice[currentMenu] = price;

    //input flavor
    while(1)
    {   
        fflush(stdin);
        printf ("Input the topping ['Mint' | 'Mix Berry' | 'Cheese'](Case Sensitive): ");
        scanf ("%s", toppingDrink); getchar();
        if (strcmp("Mint", toppingDrink) == 0 || strcmp("Mix Berry", toppingDrink) == 0 || strcmp("Cheese", toppingDrink) == 0) break;
    }
    strcpy(menuFlavor[currentMenu], toppingDrink);

    //input size
    while(1)
    {
        fflush(stdin);
        printf ("Insert the size [S | M | L](Case Sensitive): ");
        scanf ("%s", size); getchar();
        if (strcmp("S", size) == 0 || strcmp("M", size) == 0 || strcmp("L", size)==0) break;
    }
    strcpy(menuSize[currentMenu], size);
    printf("Successfully added a new menu!");
    getchar();
    currentMenu++;
}

