#include <stdio.h>
#include <limits.h>

int main(){
    puts("Part #1\n");
    ///////////////////////////////////////////////////////////////////////////
    printf("signed char -> signed short int -> signed int -> signed long\n\n");
    signed char s_ch        = CHAR_MAX;
    signed short int ss_i   = s_ch;
    signed int s_i          = ss_i;
    signed long sl          = s_i;
    printf("CHAR_MAX: %i -> %i -> %i -> %i\n", s_ch, ss_i, s_i, sl);

    s_ch                    = CHAR_MIN;
    ss_i                    = s_ch;
    s_i                     = ss_i;
    sl                      = s_i;
    printf("CHAR_MIN: %i -> %i -> %i -> %i\n", s_ch, ss_i, s_i, sl);

    s_ch                    = 121;
    ss_i                    = s_ch;
    s_i                     = ss_i;
    sl                      = s_i;
    printf("NUM (121): %i -> %i -> %i -> %i\n\n\n", s_ch, ss_i, s_i, sl);
    ///////////////////////////////////////////////////////////////////////////
    printf("unsigned char -> unsigned short int -> unsigned int -> unsigned long\n\n");
    unsigned char u_ch      = UCHAR_MAX;
    unsigned short int us_i = u_ch;
    unsigned int u_i        = us_i;
    unsigned long ul        = u_i;
    printf("UCHAR_MAX: %u -> %hu -> %u -> %lu\n", u_ch, us_i, u_i, ul);

    u_ch                    = 0;
    us_i                    = u_ch;
    u_i                     = us_i;
    ul                      = u_i;
    printf("UCHAR_MIN: %u -> %hu -> %u -> %lu\n", u_ch, us_i, u_i, ul);

    u_ch                    = 15;
    us_i                    = u_ch;
    u_i                     = us_i;
    ul                      = u_i;
    printf("NUM (15): %u -> %hu -> %u -> %lu\n\n\n", u_ch, us_i, u_i, ul);
    ///////////////////////////////////////////////////////////////////////////
    printf("unsigned long -> unsigned int -> unsigned short int -> unsigned char\n\n");
    ul                      = ULONG_MAX;
    u_i                     = ul;
    us_i                    = u_i;
    u_ch                    = us_i;    
    printf("ULONG_MAX: %lu -> %u -> %hu -> %u\n", ul, u_i, us_i, u_ch);
    ul                      = 0;
    u_i                     = ul;
    us_i                    = u_i;
    u_ch                    = us_i;    
    printf("ULONG_MIN: %lu -> %u -> %hu -> %u\n", ul, u_i, us_i, u_ch);
    ul                      = 355;
    u_i                     = ul;
    us_i                    = u_i;
    u_ch                    = us_i;    
    printf("NUM (355): %lu -> %u -> %hu -> %u\n\n", ul, u_i, us_i, u_ch);
    ///////////////////////////////////////////////////////////////////////////
    printf("signed long -> signed int -> signed short int -> signed char\n\n");
    sl                      = LONG_MAX;
    s_i                     = sl;
    ss_i                    = s_i;
    s_ch                    = ss_i;
    printf("LONG_MAX: %li -> %i -> %hd -> %d\n", sl, s_i, ss_i, s_ch);
    sl                      = LONG_MIN;
    s_i                     = sl;
    ss_i                    = s_i;
    s_ch                    = ss_i;
    printf("LONG_MIN: %li -> %i -> %hd -> %d\n", sl, s_i, ss_i, s_ch);
    sl                      = 765;
    s_i                     = sl;
    ss_i                    = s_i;
    s_ch                    = ss_i;
    printf("NUM (765): %li -> %i -> %hd -> %d\n\n\n", sl, s_i, ss_i, s_ch);
    ///////////////////////////////////////////////////////////////////////////

    puts("Part #2\n\n");

    s_i = INT_MAX;
    puts("signed int MAX -> signed int MAX + 1");
    printf("%i -> %i\n\n", s_i, s_i + 1);

    s_i = INT_MIN;
    puts("signed int MIN -> signed int MIN - 1");
    printf("%i -> %i\n\n", s_i, s_i - 1);

    u_i = UINT_MAX;
    puts("unsigned int MAX -> unsigned int MAX + 1");
    printf("%u -> %u\n\n", u_i, u_i + 1);

    u_i = 0;
    puts("unsigned int MIN -> unsigned int MIN - 1");
    printf("%u -> %u\n\n", u_i, u_i - 1);
    return 0;
}
 