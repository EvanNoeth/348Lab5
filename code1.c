//Evan Noeth, Friday 3:00 PM Lab
#include <stdio.h>
#define TOTAL_MONTHS 12

void displayMonthlySales(float sales[]);
void displaySalesSummary(float sales[]);
void displaySixMonthAverage(float sales[]);
void displaySalesInDescendingOrder(float sales[]);

int main() {
    float monthlySales[TOTAL_MONTHS];
    const char* monthNames[TOTAL_MONTHS] = {"January", "February", "March", "April", "May", "June",
                                            "July", "August", "September", "October", "November", "December"};

    printf("Enter the sales for each month:\n");
    for (int i = 0; i < TOTAL_MONTHS; i++) {
        printf("Enter sales for %s: ", monthNames[i]);
        scanf("%f", &monthlySales[i]);
    }
    
    displayMonthlySales(monthlySales);
    displaySalesSummary(monthlySales);
    displaySixMonthAverage(monthlySales);
    displaySalesInDescendingOrder(monthlySales);
    
    return 0;
}

void displayMonthlySales(float sales[]) {
    printf("\nMonthly Sales Report:\n");
    printf("Month\t\tSales\n");
    const char* monthNames[TOTAL_MONTHS] = {"January", "February", "March", "April", "May", "June",
                                            "July", "August", "September", "October", "November", "December"};
    for (int i = 0; i < TOTAL_MONTHS; i++) {
        printf("%s\t$%.2f\n", monthNames[i], sales[i]);
    }
}

void displaySalesSummary(float sales[]) {
    float lowestSale = sales[0], highestSale = sales[0], totalSales = 0;
    int lowestMonthIndex = 0, highestMonthIndex = 0;
    
    for (int i = 0; i < TOTAL_MONTHS; i++) {
        if (sales[i] < lowestSale) {
            lowestSale = sales[i];
            lowestMonthIndex = i;
        }
        if (sales[i] > highestSale) {
            highestSale = sales[i];
            highestMonthIndex = i;
        }
        totalSales += sales[i];
    }
    
    float averageSales = totalSales / TOTAL_MONTHS;
    
    const char* monthNames[TOTAL_MONTHS] = {"January", "February", "March", "April", "May", "June",
                                            "July", "August", "September", "October", "November", "December"};
    
    printf("\nSales Summary Report:\n");
    printf("Minimum sales: $%.2f (%s)\n", lowestSale, monthNames[lowestMonthIndex]);
    printf("Maximum sales: $%.2f (%s)\n", highestSale, monthNames[highestMonthIndex]);
    printf("Average sales: $%.2f\n", averageSales);
}

void displaySixMonthAverage(float sales[]) {
    const char* monthNames[TOTAL_MONTHS] = {"January", "February", "March", "April", "May", "June",
                                            "July", "August", "September", "October", "November", "December"};

    printf("\nSix-Month Moving Average Report:\n");
    
    for (int i = 0; i <= TOTAL_MONTHS - 6; i++) {
        float sixMonthTotal = 0;
        for (int j = i; j < i + 6; j++) {
            sixMonthTotal += sales[j];
        }
        float sixMonthAverage = sixMonthTotal / 6;
        
        // Print the range of months for each six-month period
        printf("%s-%s: $%.2f\n", monthNames[i], monthNames[i + 5], sixMonthAverage);
    }
}

void displaySalesInDescendingOrder(float sales[]) {
    float sortedSales[TOTAL_MONTHS];
    int sortedMonthIndices[TOTAL_MONTHS];
    const char* monthNames[TOTAL_MONTHS] = {"January", "February", "March", "April", "May", "June",
                                            "July", "August", "September", "October", "November", "December"};

    for (int i = 0; i < TOTAL_MONTHS; i++) {
        sortedSales[i] = sales[i];
        sortedMonthIndices[i] = i;
    }
    
    for (int i = 0; i < TOTAL_MONTHS - 1; i++) {
        for (int j = i + 1; j < TOTAL_MONTHS; j++) {
            if (sortedSales[i] < sortedSales[j]) {
                // Swap sales values
                float tempSale = sortedSales[i];
                sortedSales[i] = sortedSales[j];
                sortedSales[j] = tempSale;
                
                // Swap corresponding months
                int tempMonthIndex = sortedMonthIndices[i];
                sortedMonthIndices[i] = sortedMonthIndices[j];
                sortedMonthIndices[j] = tempMonthIndex;
            }
        }
    }
    printf("\nSales Report (Highest to Lowest):\n");
    for (int i = 0; i < TOTAL_MONTHS; i++) {
        printf("%s\t$%.2f\n", monthNames[sortedMonthIndices[i]], sortedSales[i]);
    }
}
