#include <stdio.h>
#define VAT 0.07

int main() {

    float product_price;
    printf("Enter the price: ");
    scanf("%f", &product_price);

    float vat_included_price = product_price + (product_price * VAT);

    float discount_total = vat_included_price * (vat_included_price > 10000 ? 0.1 : 0.05);

    float final_price = vat_included_price - discount_total;

    printf("**********************************\n");
    printf("*   Price        : %10.2f    *\n", product_price);
    printf("*   Price + VAT  : %10.2f    *\n", vat_included_price);
    printf("*   Discount     : %10.2f    *\n", discount_total);
    printf("*   Net Pay      : %10.2f    *\n", final_price);
    printf("**********************************\n");

    return 0;
}