#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int currentMenu = 1;

struct pesanDessert
{
    int ID;
    char typeMenu[255];
    char menuName[255];
    char topping[255];
    double calories;
    int menuPrice;
    int dessertTime;
};

pesanDessert *addDessert(char *menuName, char *topping, double calories, int menuPrice, int dessertTime)
{
    pesanDessert *newDessert = (pesanDessert *)malloc(sizeof(pesanDessert));

    newDessert->ID = currentMenu;
    strcpy(newDessert->typeMenu, "Dessert");
    strcpy(newDessert->menuName, menuName);
    strcpy(newDessert->topping, topping);
    newDessert->calories = calories;
    newDessert->menuPrice = menuPrice;
    newDessert->dessertTime = dessertTime;

    return newDessert;
}

void printDessert(pesanDessert *data)
{
    printf("ID : %d\n", data->ID);
    printf("Type Menu : %s\n", data->typeMenu);
    printf("Menu Name : %s\n", data->menuName);
    printf("Topping : %s\n", data->topping);
    printf("Calories : %.02lf\n", data->calories);
    printf("Price : $ %d\n", data->menuPrice);
    printf("Order Time : %d\n", data->dessertTime);
}

void deleteDessert(pesanDessert *data)
{
    free(data);
}

// pesanDessert orderDessert[105];

int main()
{
    // strcpy(orderDessert[currentMenu].typeMenu, "Dessert");
    char namaMenu[255], toppingMenu[255];
    int price;
    double calorie;

    //input nama dessert
    do
    {
        printf("Input the name [at least 5 characters]: ");
        scanf("%[^\n]", namaMenu);
        getchar();
    } while (strlen(namaMenu) < 5);
    // strcpy(orderDessert[currentMenu].menuName, namaMenu);

    //input harga
    do
    {
        printf("Input the price [10 - 500]: $ ");
        scanf("%d", &price);
        getchar();
    } while (price < 10 || price > 500);
    // orderDessert[currentMenu].menuPrice = price;

    //input topping
    int flag = 0;
    do
    {
        printf("Input the topping ['Caramel' | 'Honey' | 'Syrup'](Case Insensitive): ");
        scanf("%s", toppingMenu);
        getchar();
        if (toppingMenu[0] > 'Z')
            toppingMenu[0] -= 32;
        if (strcmp("Caramel", toppingMenu) == 0 || strcmp("Honey", toppingMenu) == 0 || strcmp("Syrup", toppingMenu) == 0)
        {
            flag = 1;
        }
    } while (flag == 0);
    // strcpy(orderDessert[currentMenu].topping, toppingMenu);

    //input kalori
    do
    {
        printf("Insert calories [1.00 - 99.00]: ");
        scanf("%lf", &calorie);
        getchar();
    } while (calorie < 1.00 || calorie > 99.00);
    // orderDessert[currentMenu].calories = calorie;

    //Mencari dessertTime
    //random waktu pembuatan dessert
    srand(time(0));
    int totaltime = (rand() % 40) + 50;

    if (strcmp(toppingMenu, "Caramel") == 0)
    {
        totaltime += 10;
    }
    else if (strcmp(toppingMenu, "Honey") == 0)
    {
        totaltime += 15;
    }
    else if (strcmp(toppingMenu, "Syrup") == 0)
    {
        totaltime += 20;
    }
    // orderDessert[currentMenu].dessertTime = totaltime;

    //create data dari inputan
    pesanDessert *Dessert = addDessert(namaMenu, toppingMenu, calorie, price, totaltime);
    printf("\nSuccessfully added a new menu!");
    getchar();

    //print data inputan
    printDessert(Dessert);
    currentMenu++;

    //delete data
    deleteDessert(Dessert);
}