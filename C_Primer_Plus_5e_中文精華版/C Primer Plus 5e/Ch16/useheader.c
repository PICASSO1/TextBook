// useheader.c -- use the names_st structure
#include <stdio.h>
#include "names.h"
// remember to link with names.c
int main(void)
{
    names candidate;
 	
    get_names(&candidate);
    show_names(&candidate);
    
    return 0;
}
