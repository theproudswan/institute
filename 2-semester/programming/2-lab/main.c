#include <stdio.h>


int main(){
    puts("Part #1\n");

    float to_pow = 6; 
    printf("Initially a = %.0f\n", to_pow);
    to_pow*=to_pow; // pow 2
    to_pow*=to_pow; // pow 4
    float tmp = to_pow; // to memorize pow 4
    to_pow*=to_pow; // pow 8
    to_pow = to_pow*to_pow*to_pow*tmp; // pow 8+8+8+4 = 28
    printf("Result a^28 = %.0lf\n", to_pow);

    ///////////////////////////////////////////////////////

    puts("\nPart #2\n");
    int x = 115, y = 140, z = 10; // Важно отметить, что в дальнейшем z делится на 2.
                                  // Поэтому в иных случаях либо поменять тип на float (и в выводе тоже), либо всегда делать z чётным.
    int max = 0;
    (x < y)? (max = y): (max = x);
    (max < z)? max = z:(1);
    printf("For x = %i, y = %i, z = %i    max = %i\n", x, y, z, max);

    int min = 0;
    (x + y + z/2 < x*y*z)? (min = x + y + z/2): (min = x*y*z);
    min = min*min + 1;
    printf("For x = %i, y = %i, z = %i    min^2(x+y+z/2, x*y*z)+1 = %i", x, y, z, min);

    return 0;
}
