// 這是一個標頭檔(*.H)!!
#define SLEN 32
/*
struct names_st
{
    char first[SLEN];
	char last[SLEN];
};

typedef struct names_st names;
*/
// 以上的結構型態定義，可用另一種寫法：
typedef struct names_st
{
    char first[SLEN];
	char last[SLEN];
}names;
void get_names(names *);             // void get_names(struct names_st *pn);
void show_names(const names *);      // void show_names(const struct names_st *pn);
