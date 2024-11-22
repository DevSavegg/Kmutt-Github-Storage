#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define data_name "Data.txt"

typedef struct
{
    char id[10];
    char name[20];
    int price;
} Products;

int split_data(Products *productLists, FILE *data) {
    int n = 0, i, count, tmp;
    char buffer[100], tempString[100], tempInt[20];

    while (fgets(buffer, sizeof(buffer), data) != NULL) {
        count = 0;
        for (i = 0; i < sizeof(buffer); i++) {
            if (buffer[i] == ',') {
                tempString[count] = '\0';
                break;
            }

            tempString[count] = buffer[i];
            count++;
        }
        //printf("%s,%d,", tempString, count);
        strncpy(productLists[n].id, tempString, count);
        //printf("%s   ", productLists[n].id);

        count = 0;
        for (i = i + 1; i < sizeof(buffer); i++) {
            if (buffer[i] == ',') {
                tempString[count] = '\0';
                break;
            }

            tempString[count] = buffer[i];
            count++;
        }
        //printf("%s,%d,", tempString, count);
        strncpy(productLists[n].name, tempString, count);
        //printf("%s   ", productLists[n].name);

        count = 0;
        for (i = i + 1; i < sizeof(buffer); i++) {
            if (buffer[i] == '\n') {
                tempString[count] = '\0';
                break;
            }

            tempString[count] = buffer[i];
            count++;
        }
        //printf("%s,%d,", tempString, count);
        productLists[n].price = atoi(tempString);
        //printf("%d\n\n", productLists[n].price);

        n++;
    }

    return n;
}

int main() {
    char buffer[1000];

    int i, j, k, length = 0, quantity, targetProduct = -1;

    char expectedProduct[10];

    Products ProductLists[100];

    FILE *dataFile = fopen(data_name, "ab");
    FILE *r_dataFile;

    for (i = 1;;i++) {
        printf("Product No. [%d]\n", i);
        printf("ID           : ");
        fgets(ProductLists[i].id, sizeof(ProductLists[i].id), stdin);

        if (strcmp(ProductLists[i].id, "*\n") == 0) {
            length = i - 1;
            break;
        }

        for (j = 0; j < 100; j++) {
            if (ProductLists[i].id[j] == '\n') {
                ProductLists[i].id[j] = '\0';
            }
        }

        printf("Product Name : ");
        fgets(ProductLists[i].name, sizeof(ProductLists[i].name), stdin);

        for (j = 0; j < 100; j++) {
            if (ProductLists[i].name[j] == '\n') {
                ProductLists[i].name[j] = '\0';
            }
        }

        printf("Price        : ");
        scanf("%d", &ProductLists[i].price);
        getchar();

        fprintf(dataFile, "%s,%s,%d\n", ProductLists[i].id, ProductLists[i].name, ProductLists[i].price);
    }
    fclose(dataFile);

    r_dataFile = fopen(data_name, "rt");
    Products displayProductLists[100];

    length = split_data(displayProductLists, r_dataFile);

    printf("%d", length);

    printf("=======================\n");
    printf("Enter the product you want to buy: \n");
    printf("Product ID : ");
    fgets(expectedProduct, sizeof(expectedProduct), stdin);

    for (j = 0; j < 100; j++) {
            if (expectedProduct[j] == '\n') {
                expectedProduct[j] = '\0';
            }
        }

    printf("Quantity   : ");
    scanf("%d", &quantity);

    printf("=======================\n");

    for (i = 0; i < length; i++) {
        //printf("%s, %s\n", displayProductLists[i].id, expectedProduct);
        if (strcmp(displayProductLists[i].id, expectedProduct) == 0) {
            targetProduct = i;
            break;
        }
    }

    if (targetProduct == -1) {
        printf("Product not found!\n");
    } else {
        printf("Product ID     : %s\n", displayProductLists[targetProduct].id);
        printf("Product Name   : %s\n", displayProductLists[targetProduct].name);
        printf("Price/Unit     : %7d\n", displayProductLists[targetProduct].price);
        printf("Total Quantity : %7d\n", quantity);
        printf("Total Price    : %7d\n", displayProductLists[targetProduct].price * quantity);
    }

    printf("=======================\n");

    fclose(r_dataFile);

    return 0;
}