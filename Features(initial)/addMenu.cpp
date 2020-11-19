#include <stdio.h>

void addMenu();
void addDesert();

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