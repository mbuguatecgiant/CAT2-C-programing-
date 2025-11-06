/*
Name:MARK MBUGUA KARANJA 
REG NO:CT101/G/26487/25
DESCRIPTION:CAT 2 Q2
*/


#include <stdio.h>

int main() {
    float hours, rate, gross_pay, taxes, net_pay;

    
    printf("Enter hours worked in a week: ");
    scanf("%f", &hours);

    printf("Enter hourly wage: ");
    scanf("%f", &rate);

    
    if (hours <= 40) {
        gross_pay = hours * rate;
    } 
    else {
        gross_pay = (40 * rate) + ((hours - 40) * rate * 1.5);
    }

    
    if (gross_pay <= 600) {
        taxes = gross_pay * 0.15;
    }
     else {
        taxes = (600 * 0.15) + ((gross_pay - 600) * 0.20);
    }

    
    net_pay = gross_pay - taxes;

    
    printf("Gross pay: $%.f", gross_pay);
    printf("\nTaxes: $%.f", taxes);
    printf("\nNet pay: $%.f", net_pay);

    return 0;
}