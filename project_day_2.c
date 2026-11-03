#include <stdio.h>

int main()
{
    int type, count = 0;
    float old, current, units, energy, fixed, bill;
    float total = 0;

    printf("1 = Home, 2 = Shop, 0 = Stop\n");

    while (1)
    {
        printf("\nEnter connection type: ");
        scanf("%d", &type);

        if (type == 0)
            break;

        if (type != 1 && type != 2)
        {
            printf("Invalid type\n");
            continue;
        }

        printf("Enter previous reading: ");
        scanf("%f", &old);

        printf("Enter current reading: ");
        scanf("%f", &current);

        if (current < old)
        {
            printf("Invalid reading\n");
            continue;
        }

        units = current - old;

        if (type == 1)
        {
            if (units <= 100)
                energy = units * 5;
            else if (units <= 200)
                energy = 500 + (units - 100) * 6.5;
            else
                energy = 1150 + (units - 200) * 8;

            fixed = 60;
        }
        else
        {
            energy = units * 8;
            fixed = 150;
        }

        bill = energy + fixed + energy * 0.05;
        total = total + bill;
        count++;

        printf("Units: %.2f\n", units);
        printf("Bill: Rs. %.2f\n", bill);
    }

    printf("\nNumber of bills: %d\n", count);
    printf("Total amount: Rs. %.2f\n", total);

    return 0;
}