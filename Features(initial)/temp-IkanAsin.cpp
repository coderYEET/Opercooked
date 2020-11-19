#include <stdio.h>
#include <string.h>

int profit = 0;
char menuName[100][255];
int menuPrice[100];
char topping[100][255];
double calories[100];
int currentMenu = 1;
char typeMenu[100][255];
char menuSize[100];
char menuFlavor[100][50];

void addMenu();
void addDesert();
void order();

int main(){

    // Main Menu
    while(1)
    {
        for (int i = 0; i < 50; i++) puts("");        
        puts("Welcome to Opercooked");
        printf("Today Profit: $ %d\n", profit);
        puts("========================");
        puts("1. Add Dessert or Beverage");
        puts("2. View Cooking Process");
        puts("3. View Order History");
        puts("4. Order Dessert or Beverage");
        puts("5. Exit");
        int inputMenu;
        printf(">> ");
        scanf ("%d", &inputMenu); getchar();
        for (int i = 0; i < 50; i++) puts("");
        if (inputMenu == 1) addMenu();
        else if (inputMenu == 4) order();
        else if (inputMenu == 5) break;    
    }

    return 0;
}

void addMenu(){

    //pilih mau nambah dessert ato drink
    while(1)
    {
        puts ("What do you want to add?");
        puts("1. Dessert");
        puts("2. Drink");
        printf ("Choose: ");
        int choose;
        scanf ("%d", &choose); getchar();
        if (choose == 1) addDesert(); break;
        for (int i = 0; i < 50; i++) puts("");        
    }


}

void addDesert(){
    strcpy(typeMenu[currentMenu], "Dessert");
    char namaMenu[255], toppingMenu[255];
    int price;
    double calorie;

    //input nama dessert
    while(1)
    {
    printf ("Input the name [at least 5 characters]: ");
    scanf ("%[^\n]", namaMenu); getchar();
    if (strlen(namaMenu) >= 5) break;
    }
    strcpy(menuName[currentMenu], namaMenu);

    //input harga
    while(1)
    {
        printf ("Input the price [10 - 500]: "); 
        scanf ("%d", &price); getchar();
        if (price >= 10 && price <= 500) break;
    }
    menuPrice[currentMenu] = price;

    //input topping
    while(1)
    {
        printf ("Input the topping ['Caramel' | 'Honey' | 'Syrup'](Case Insensitive): ");
        scanf ("%s", toppingMenu); getchar();
        if (toppingMenu[0] > 'Z') toppingMenu[0] -= 32;
        for (int i = 1; i < strlen(toppingMenu); i++)
        {
            if (toppingMenu[i] < 'a') toppingMenu[i] += 32;
        }
        if (strcmp("Caramel", toppingMenu) == 0 || strcmp("Honey", toppingMenu) == 0 || strcmp("Syrup", toppingMenu) == 0) break;
    }
    strcpy(topping[currentMenu], toppingMenu);

    //input kalori
    while(1)
    {
        printf ("Insert calories [1.00 - 99.00]: ");
        scanf ("%lf", &calorie); getchar();
        if (calorie >= 1.00 && calorie <= 99.00) break;
    }
    calories[currentMenu] = calorie;
    printf("Successfully added a new menu!");
    getchar();
    currentMenu++;
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
            
            while(1)
            {
            printf ("Choose a menu to order [1 - %d]: ", currentMenu - 1);
            int input;
            scanf ("%d", &input); getchar();
            if (input >= 1 && input <= currentMenu - 1) break;
            }
            printf("\nSuccessfully add to order list!\n");
            printf ("Press Enter to continue"); getchar();
        }
    
}
