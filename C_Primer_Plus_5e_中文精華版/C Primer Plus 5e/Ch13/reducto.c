// reducto.c -- reduces your files by two-thirds!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>    // for strcpy(), strcat()
int main(int argc, char *argv[])
{
    FILE  *in, *out;   // declare two FILE pointers
    int ch;
    char name[40];     // storage for output filename
    int count = 0;

    if (argc < 2)      // check for an input file  
    {
         fprintf(stderr, "Usage: %s filename\n", argv[0]);
         exit(1);
    }
    if ((in = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n",
                argv[1]);
        exit(2);
    }
    strcpy(name,argv[1]);   // copy filename into array
    strcat(name,".red");    // append .red to name 
    if ((out = fopen(name, "w")) == NULL)
    {                       // open file for writing
        fprintf(stderr,"Can't create output file.\n");
        exit(3);
    }
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);  // print every 3rd char
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr,"Error in closing files\n");
    return 0;
}

