#include<stdio.h>
#include<locale.h>
#include<wchar.h>

// #define DIAMOND_SYMBL	"\xE2\x99\xA0"
// #define	CLUB_SYMBOL		"\xE2\x99\xA3"
// #define HEART_SYMBOL	"\xE2\x99\xA5"
// #define SPADE_SYMBOL	"\xE2\x99\xA6"


#define DIAMOND_SYMBL	(wint_t)25C7
#define	CLUB_SYMBOL		(wint_t)2663
#define HEART_SYMBOL	(wint_t)2661
#define SPADE_SYMBOL	(wint_t)2664

int main()
{
	    char *locale;

    locale = setlocale(LC_ALL, "");
    for (int i= 0; i < 9 ; i++)
    printf("%lc \n",'\u2664');
    return 0;
}



