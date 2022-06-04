#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void assignment1()
{
    FILE *text_file = fopen("text.txt", "r");
    FILE *replaced_file = fopen("replaced.txt", "w");
    if (text_file == NULL)
    {
        puts("The file text.txt doesn't exist!");
    }
    else
    {
        char c;
        while ((c = fgetc(text_file)) != EOF)
        {
            if (c == '-')
                c = '/';
            fputc(c, replaced_file);
        }
    }
    fclose(text_file);
    fclose(replaced_file);
}

typedef struct
{
    char car_brand;
    int production_year;
} car;
void read(car *t, int n)
{
    puts("Enter the car list.");
    for (int i = 0; i < n; i++)
    {
        printf("The car no. %d\n", i + 1);
        printf("Enter the car brand: ");
        scanf("%s", &t[i].car_brand);
        printf("Enter the year of production: ");
        scanf("%d", &t[i].production_year);
    }
}
void write(car *t, int n)
{
    puts("-----------------------------------");
    for (int i = 0; i < n; ++i)
    {
        printf("The car brand: %s\n", t[i].car_brand);
        printf("The year of production: %d\n", t[i].production_year);
    }
    puts("-----------------------------------");
}

car *select(car *t, int n, int year, int *final_size)
{
    *final_size = 0;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (t[i].production_year >= year)
        {
            (*final_size)++;
        }
    }
    car *result = (car *)malloc(*final_size * sizeof(car));
    for (int i = 0; i < n; i++)
    {
        if (t[i].production_year >= year)
        {
            result[k++] = t[i];
        }
    }
    return result;
}
void assignment2()
{
    int n, year;
    printf("Enter the size of car list: ");
    scanf("%d", &n);
    printf("Enter the production year: ");
    scanf("%d", &year);
    car *t = (car *)malloc(n * sizeof(car));
    read(t, n);
    int *final_size = (int *)malloc(1 * sizeof(int));
    car *result = select(t, n, year, final_size);
    puts("The cars exceeded from given year:");
    write(result, *final_size);
}
int main()
{
    assignment1();
    assignment2();
    return 0;
}