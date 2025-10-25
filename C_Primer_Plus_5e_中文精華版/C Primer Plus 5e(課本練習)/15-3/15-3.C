#include <stdio.h>
// 定義是否透明
#define YES 1
#define NO 0
// 定義線條樣式
#define SOLID 0
#define DOTTED 1
#define DASHED 2
// 定義主要顏色
#define BLUE 4
#define GREEN 2
#define RED 1
// 定義混合色
#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

struct box_props
{
    unsigned int opaque      : 1;
	unsigned int fill_color  : 3;
	unsigned int             : 4;
	unsigned int show_bolder : 1;
	unsigned int border_color: 3;
	unsigned int border_style: 2;
	unsigned int             : 2;
};

const char *colors[8]={"black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"};

int main(void)
{
    struct box_props box={YES, YELLOW, YES, GREEN, DASHED};
	fprintf(stdout, "Box is %s. \n", box.opaque==YES?"opaque":"transparent");
	fprintf(stdout, "The border style is ");
	switch(box.border_style)
	{
	    case SOLID : fprintf(stdout, "solid. \n");
			         break;
	    case DOTTED: fprintf(stdout, "dotted. \n");
			         break;
		case DASHED: fprintf(stdout, "dashed. \n");
			         break;
		default    : fprintf(stdout, "unknow type. \n");
	}
	printf("The fill color is %s. \n", colors[box.fill_color]);
	printf("The border color is %s. \n", colors[box.border_color]);
	box.opaque=NO;
	box.fill_color=WHITE;
	box.border_color=MAGENTA;
    box.border_style=SOLID;
	printf("After changes box is %s. \n", box.opaque==YES?"opaque":"transparent");
	printf("The border style is ");
	switch(box.border_style)
	{
	    case SOLID : fprintf(stdout, "solid. \n");
			         break;
	    case DOTTED: fprintf(stdout, "dotted. \n");
			         break;
		case DASHED: fprintf(stdout, "dashed. \n");
			         break;
		default    : fprintf(stdout, "unknow type. \n");
	}
	printf("The fill_color is %s. \n", colors[box.fill_color]);
	printf("The border color is %s. \n", colors[box.border_color]);

	return 0;
}