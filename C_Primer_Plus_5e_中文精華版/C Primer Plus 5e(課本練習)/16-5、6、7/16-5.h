// �o�O�@�Ӽ��Y��(*.H)!!
#define SLEN 32
/*
struct names_st
{
    char first[SLEN];
	char last[SLEN];
};

typedef struct names_st names;
*/
// �H�W�����c���A�w�q�A�i�Υt�@�ؼg�k�G
typedef struct names_st
{
    char first[SLEN];
	char last[SLEN];
}names;
void get_names(names *);             // void get_names(struct names_st *pn);
void show_names(const names *);      // void show_names(const struct names_st *pn);
