#include <stdio.h>

int main(void)
{

    printf("Enter the numbers from 1 to 16: ");
    
    int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0, seven = 0, eight = 0, nine = 0, ten = 0, eleven = 0, twelve = 0, thirteen = 0, fourteen = 0, fifteen = 0, sixteen = 0;
 
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d" , &one, &two, &three, &four, &five, &six, &seven, &eight, &nine, &ten, &eleven, &twelve, &thirteen, &fourteen, &fifteen, &sixteen);
    printf("%d\t%d\t%d\t%d\n", one, two, three, four);
    printf("%d\t%d\t%d\t%d\n", five, six, seven, eight);
    printf("%d\t%d\t%d\t%d\n", nine, ten, eleven, twelve); 
    printf("%d\t%d\t%d\t%d\n", thirteen, fourteen, fifteen, sixteen);
    
    // Rows sums
    printf("Row sums:\t%d\t%d\t%d\t%d\n", one + two + three + four, five + six + seven + eight, nine + ten + eleven + twelve, thirteen + fourteen + fifteen + sixteen);
    
    // Columns sums
    printf("Columns sums:\t%d\t%d\t%d\t%d\n", one + five + nine + thirteen, two + six + ten + fourteen, three + seven + eleven + fifteen, four + eight + twelve + sixteen);

    // diagonals sums
    printf("Diagonal sums:\t%d\t%d\n", one + six + eleven + sixteen, four + seven + ten + thirteen);

    return 0;
}
