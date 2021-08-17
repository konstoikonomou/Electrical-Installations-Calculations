
/* File used for calculations of cooling load (lighting and ventilation load), considering Energy Efficiency Ruling for Buildings in Greece (K.En.A.K) */

#include <stdio.h>

int main()
{
    int choice;
    double length = 0, width = 0, height = 0, last_kenak_col = 0;
    double third_kenak_col_lighting = 0;
    double result;
    
    printf("1: Lighting Load\n2: Ventilation Load\n1 or 2? ");
    scanf("%d", &choice);
    
    if(choice == 1){
        printf("Length (horizontally in Autocad): ");
        scanf("%lf", &length);
        printf("Width (vertically in Autocad): ");
        scanf("%lf", &width);
        printf("third kenak column lighting: ");
        scanf("%lf", &third_kenak_col_lighting);
        
        result = (length * width * third_kenak_col_lighting *  0.3);
        // 30% of lighting converted to heat
        printf("\nLighting load: %.3lf W", result);
    }
    else if(choice == 2){
        printf("Length (horizontally in Autocad): ");
        scanf("%lf", &length);
        printf("Width (vertically in Autocad): ");
        scanf("%lf", &width);
        printf("Height (floor till metal ceiling): ");
        scanf("%lf", &height);
        printf("last kenak col: ");
        scanf("%lf", &last_kenak_col);
    
        result = (height * length * last_kenak_col) / (length * width * height);

        printf("\nNumber of air switchings per hour: %.3lf", result);
    }
    
    return 0;
}
