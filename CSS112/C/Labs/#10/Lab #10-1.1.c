#include <stdio.h>
#include <string.h>

struct Products
{
    char id[10];
    char name[20];
    int price;
};


int main() {
    int i, j, k, length = 0, quantity, targetProduct = -1;

    char expectedProduct[10];

    struct Products ProductLists[100];

    for (i = 1;;i++) {
        printf("Product No. [%d]\n", i);
        printf("ID           : ");
        fgets(ProductLists[i].id, sizeof(ProductLists[i].id), stdin);

        if (strcmp(ProductLists[i].id, "*\n") == 0) {
            length = i - 1;
            break;
        }

        printf("Product Name : ");
        fgets(ProductLists[i].name, sizeof(ProductLists[i].name), stdin);
        printf("Price        : ");
        scanf("%d", &ProductLists[i].price);
        getchar();
    }

    printf("=======================\n");
    printf("Enter the product you want to buy: \n");
    printf("Product ID : ");
    fgets(expectedProduct, sizeof(expectedProduct), stdin);

    printf("Quantity   : ");
    scanf("%d", &quantity);

    printf("=======================\n");

    for (i = 1; i <= length; i++) {
        if (strcmp(ProductLists[i].id, expectedProduct) == 0) {
            targetProduct = i;
            break;
        }
    }

    if (targetProduct == -1) {
        printf("Product not found!\n");
    } else {
        printf("Product ID     : %s", ProductLists[targetProduct].id);
        printf("Product Name   : %s", ProductLists[targetProduct].name);
        printf("Price/Unit     : %7d\n", ProductLists[targetProduct].price);
        printf("Total Quantity : %7d\n", quantity);
        printf("Total Price    : %7d\n", ProductLists[targetProduct].price * quantity);
    }

    printf("=======================\n");

    return 0;
}