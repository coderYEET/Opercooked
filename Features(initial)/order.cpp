#include <stdio.h>
#include <string.h>
#include <time.h>

void addDessertOrderTime(int totalDessert){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    orderDessert[totalDessert].orderTime.year = tm.tm_year + 1900;
    orderDessert[totalDessert].orderTime.month = tm.tm_mon + 1;
    orderDessert[totalDessert].orderTime.date = tm.tm_mday;
    orderDessert[totalDessert].orderTime.hour = tm.tm_hour;
    orderDessert[totalDessert].orderTime.min = tm.tm_min;
    orderDessert[totalDessert].orderTime.sec = tm.tm_sec;
    if (orderDessert[totalDessert].orderTime.hour > 12)
    {
        strcpy(orderDessert[totalDessert].orderTime.form, "PM");
        orderDessert[totalDessert].orderTime.hour -= 12;
    }
    else strcpy(orderDessert[totalDessert].orderTime.form, "AM");
    //printf("%d/%02d/%02d %02d:%02d:%02d %s\n", year, month, date, hour, min, sec, form);
}

void addDrinkOrderTime(int totalDrink){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    orderDrink[totalDrink].orderTime.year = tm.tm_year + 1900;
    orderDrink[totalDrink].orderTime.month = tm.tm_mon + 1;
    orderDrink[totalDrink].orderTime.date = tm.tm_mday;
    orderDrink[totalDrink].orderTime.hour = tm.tm_hour;
    orderDrink[totalDrink].orderTime.min = tm.tm_min;
    orderDrink[totalDrink].orderTime.sec = tm.tm_sec;
    if (orderDrink[totalDrink].orderTime.hour > 12)
    {
        strcpy(orderDrink[totalDrink].orderTime.form, "PM");
        orderDrink[totalDrink].orderTime.hour -= 12;
    }
    else strcpy(orderDrink[totalDrink].orderTime.form, "AM");
    //printf("%d/%02d/%02d %02d:%02d:%02d %s\n", year, month, date, hour, min, sec, form);
}

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
 char menuSize[3];
 char menuFlavor[50];
 int drinkTime;
 OrderTime orderTime;
};

struct pesanDessert
{
 char typeMenu[255];
 char menuName[255];
 char topping[255];
 double calories;
 int menuPrice;
 int dessertTime;
 OrderTime orderTime;
};

char menuName[100][255];
char typeMenu[100][255];
char topping[100][255];
char menuSize[100][3];
char menuFlavor[100][50];
double calories[100];
int menuPrice[100];
int currentMenu = 1;
int totalDessert = 1;
int totalDrink = 1;

struct pesanDessert orderDessert[105];
struct pesanDrink orderDrink[105];

void order();

void order(){
    
        if (strlen(menuName[1]) == 0)
        {
            puts("There is no Dessert or Drink on the list!");
            printf ("\nPress Enter to continue");
            getchar();
        }
        else if (strlen(menuName[1]))
        {
            printf ("| %-5s| %-20s| %-7s| %-12s| %-11s| %-11s| %-6s|\n","No", "Name", "Price", "Topping", "Callories", "Flavor", "size");
            puts ("---------------------------------------------------------------------------------------");
            //kalau dia dessert
            for (int i = 1; i < 100; i++)
            {
                if (strcmp(typeMenu[i], "Dessert") == 0)
                {
                    printf ("| %-5d| %-20s| %-7d| %-12s| %-11.2lf| %-11s| %-6s|\n", i, menuName[i], menuPrice[i], topping[i], calories[i], "-", "-");
                }
                //kalau dia drink
                if (strcmp(typeMenu[i], "Drink") == 0)
                {
                    printf ("| %-5d| %-20s| %-7d| %-12s| %-11.2lf| %-11s| %-6s|\n", i, menuName[i], menuPrice[i], "-", "-", menuFlavor[i], menuSize[i]);
                }
            }
            
            int input;
            while(1)
            {
                printf ("Choose a menu to order [1 - %d]: ", currentMenu - 1);
                scanf ("%d", &input); getchar();
                if (input >= 1 && input <= currentMenu - 1) break;
            }
            if (strcmp(typeMenu[input], "Dessert") == 0)
            {
                strcpy(orderDessert[totalDessert].typeMenu, typeMenu[input]);
                strcpy(orderDessert[totalDessert].menuName, menuName[input]);
                strcpy(orderDessert[totalDessert].topping, topping[input]);
                orderDessert[totalDessert].calories =  calories[input];
                orderDessert[totalDessert].menuPrice = menuPrice[input];
                orderDessert[totalDessert].dessertTime = dessertTime[input];
                addDessertOrderTime(totalDessert);
                totalDessert++;
            }
            else if (strcmp(typeMenu[input], "Drink") == 0)
            {
                strcpy(orderDrink[totalDrink].typeMenu, typeMenu[input]);
                strcpy(orderDrink[totalDrink].menuName, menuName[input]);
                strcpy(orderDrink[totalDrink].menuSize, menuSize[input]);
                strcpy(orderDrink[totalDrink].menuFlavor, menuFlavor[input]);
                orderDrink[totalDrink].menuPrice = menuPrice[input];
                orderDrink[totalDrink].drinkTime = drinkTime[input];
                addDrinkOrderTime(totalDrink);
                totalDrink++;
            }
            printf("\nSuccessfully add to order list!\n");
            printf ("Press Enter to continue"); getchar();
        }
}