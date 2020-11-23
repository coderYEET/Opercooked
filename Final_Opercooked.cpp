//kode final untuk program Opercooked
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//functions
void mainMenu();
void addMenu();
void viewCooking();
void viewOrder();
void order();
void addDessert();
void addDrink();

//data structures
struct OrderTime
{
    int year,month,date,hour,min,sec;
    char form[3];
};

struct pesanDessert
{
    char typeMenu[255];
    char menuName[255];
    char topping[255];
    double calories;
    int currentMenu = 1;
    int menuPrice;
    int dessertTime;
};

struct pesanDrink
{
    char menuName[255];
    int menuPrice;
    char typeMenu[255];
    char menuSize[2];
    char menuFlavor[50];
    int drinkTime;
    struct OrderTime orderTime;
};

struct histdessert
{
    char name[255];
    char topping[255];
    double callories;
    int price;
    struct OrderTime orderTime;
};

struct histdrink
{
    char name[255];
    char size[2];
    char flavor[255];
    int price;
    struct OrderTime orderTime;
};

//global variables or structures
int profit = 0;
int currentMenu = 1;
int totalDessert = 1;
int totalDrink = 1;
int totalHDessert = 0;
int totalHDrink = 0;
char menuName[100][255];
char typeMenu[100][255];
char topping[100][255];
char menuSize[100][3];
char menuFlavor[100][50];
double calories[100];
int menuPrice[100];
struct pesanDessert orderDessert[105];
struct pesanDrink orderDrink[100];
struct histdessert historyDessert[105];
struct histdrink historyDrink[105];
struct pesanDessert orderDessert[105];
struct pesanDrink orderDrink[105];

int main() {

	mainMenu();

	return 0;
}

void mainMenu() {
	int input;
	do {
		printf("\e[1;1H\e[2J");
		puts("Welcome to Opercooked");
		printf("Today's Profit: $ %d\n", profit);
		puts("===========================");
		puts("1. Add Dessert or Beverage");
		puts("2. View Cooking Process");
		puts("3. View Order History");
		puts("4. Order Dessert or Beverage");
		puts("5. Exit");
		printf(">> ");
		scanf("%d", &input);
		if(input == 1) {
			printf("\e[1;1H\e[2J");
			addMenu();
			getchar();
			getchar();
		}
		if(input == 2) {
			printf("\e[1;1H\e[2J");
			viewCooking();
			getchar();
			getchar();
		}
		if(input == 3) {
			printf("\e[1;1H\e[2J");
			viewOrder();
			getchar();
			getchar();
		}
		if(input == 4) {
			printf("\e[1;1H\e[2J");
			order();
			getchar();
			getchar();
		}
		if(input == 5) {
			printf("\e[1;1H\e[2J");
			break;
		}
	} while(input != 5);
}

void addMenu(){
	int input;
	do {
		printf("\e[1;1H\e[2J");
		puts("What do you want to add?");
		puts("1. Dessert");
		puts("2. Drink");
		printf("Choose: ");
		scanf("%d", &input);
		if(input == 1) {
			printf("\e[1;1H\e[2J");
			addDessert();
			getchar();
		}
		if(input == 2) {
			printf("\e[1;1H\e[2J");
			addDrink();
			getchar();
		}
	} while(input < 1 || input > 2);
}

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

void viewCooking(){
    printf("| No  | Type     | Name   | Price  | Time Left |\n--------------------------------------------------------------\n");
    int list=1;
    ///////////////////////////////////////////////////////////////////
    for (int i = 1; i <= totalDessert; ++i){
        if (orderDessert[i].dessertTime <= 0) continue;
        orderDessert[i].dessertTime -= 10;
        if (orderDessert[i].dessertTime <= 0){
            //Pindahin data ke struct history
            strcpy(historyDessert[totalHDessert].name, orderDessert[i].menuName);
            strcpy(historyDessert[totalHDessert].topping, orderDessert[i].topping);
            historyDessert[totalHDessert].callories = orderDessert[i].calories;
            historyDessert[totalHDessert].price = orderDessert[i].menuPrice;
            profit += orderDessert[i].menuPrice;
            //Tambahin order time tapi belum ada
        }
    }

    for (int i = 1; i <= totalDrink; ++i){
        if (orderDrink[i].drinkTime <= 0) continue;
        orderDrink[i].drinkTime -= 10;
        if (orderDrink[i].drinkTime <= 0){
            //Pindahin data ke struct history
            strcpy(historyDrink[totalHDrink].name, orderDrink[i].menuName);
            strcpy(historyDrink[totalHDrink].size, orderDrink[i].menuSize);
            strcpy(historyDrink[totalHDrink].flavor, orderDrink[i].menuFlavor);
            historyDrink[totalHDrink].price = orderDrink[i].menuPrice;
            profit += orderDrink[i].menuPrice;
            //Tambahin order time tapi belum ada
        }
    }
    ///////////////////////////////////////////////////////////////////
    printf("\t\tDISPLAY MENU\n\n");
    int idx=1;
    //print data dessert
    while(idx <= totalDessert)
    {
        if (orderDessert->dessertTime > 0)
        {
            printf(" %-4d| %-9s| %-21s| %-7d| %-10d\n", list, "Dessert", orderDessert[idx].menuName, orderDessert->menuPrice, orderDessert->dessertTime);
            list++;
        }
    }
    idx=1;
    //print data drink
    while (idx <= totalDrink)
    {
        if (orderDrink->drinkTime > 0)
        {
            printf(" %-4d| %-9s| %-21s| %-7d| %-10d\n", list, "Drink", orderDrink[idx].menuName, orderDrink->menuPrice, orderDrink->drinkTime);
            list++;
        }
    }
    printf("Press Enter to return main menu");
    getchar();
    //input function mainmenu nya
}

void viewOrder(){
    if(totalHDessert || totalHDrink){
        puts("| No  | Name                  | Price  | Topping    | Callories  | Flavor     | size  | Order Time              |");
        puts("-----------------------------------------------------------------------------------------------------------------");
        for(int i = 0; i < totalHDessert; i++){
            printf("| %-3d | %-21s | %-6d | %-10s | %-10.2lf | %-10s | %-5c | %d/%02d/%02d %02d:%02d:%02d %s |\n", i + 1, 
            historyDessert[i].name, historyDessert[i].price, historyDessert[i].topping, historyDessert[i].callories, "-", "-", 
            orderDessert[i].orderTime.year, orderDessert[i].orderTime.month, orderDessert[i].date, 
            orderDessert[i].orderTime.hour, orderDessert[i].orderTime.min, orderDessert[i].orderTime.sec, orderDessert[i].orderTime.form);
        }
        for(int i = 0; i < totalHDrink; i++){
            printf("| %-3d | %-21s | %-6d | %-10s | %-10.2lf | %-10s | %-5c | %d/%02d/%02d %02d:%02d:%02d %s |\n", i + totalHDessert + 1, 
            historyDrink[i].name, historyDrink[i].price, "-", "-", historyDrink[i].flavor, historyDrink[i].size, 
            orderDrink[i].orderTime.year, orderDrink[i].orderTime.month, orderDrink[i].date, 
            orderDrink[i].orderTime.hour, orderDrink[i].orderTime.min, orderDrink[i].orderTime.sec, orderDrink[i].orderTime.form);
        }
    }
    else{
        puts("There is no order history!");
        puts("");
        puts("Press enter to continue");
    }
    getchar();
}

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
//halo