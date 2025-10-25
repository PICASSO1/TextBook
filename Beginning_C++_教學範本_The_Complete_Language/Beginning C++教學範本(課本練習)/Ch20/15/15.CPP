#include <vector>
#include "Bean.H"

using namespace std;

void constructor_tests(void)
{
	clear_bean_log();
	vector<Bean> V;
	usage_report("vector<Bean> V");
	vector<Bean> W(3);
	usage_report("vector<Bean> W(3)");
	vector<Bean> X(5, Bean());
	usage_report("vector<Bean> X(5, Bean())");
	vector<Bean> Y(X.begin(), X.end());
	usage_report("vector<Bean> Y(X.begin(), X.end())");

	return;
}

void resize_tests(int reserve = 0)
{
	vector<Bean> V;
	if(reserve != 0)
	{
		cout << "resize_tests performed after reserving space for " << reserve << " elements. " << endl;
		V.reserve(reserve);
	}
	clear_bean_log();
	int size[8] = {1, 10, 100, 20, 50, 101, 0};
	for(int i(0); i<7; ++i)
	{
		V.resize(sizes[i]);
		cout << "resizing V to " << sizes[i] << endl;
		usage_report();
	}

	return;
}

void insert_tests(void)
{
	Bean E;
	vector<Bean> W, V;
	clear_bean_log();
	for(int j(0); j<1000; ++j)
		W.push_back(E);
	usage_report("1000 push_back() operations. ");
	for(int k(0); k<1000; ++k)
		V.insert(V.begin(), E);
	usage_report("1000 inserts at front. ");

	return;
}

void assign_and_compare_tests(void)
{
	vector<Bean> X(77), Y(456);
	cout << "X has 77 members; Y has 456 members. " << endl;
	clear_bean_log();
	X == Y; usage_report("compare: X == Y ");
	X = X;  usage_report("assign self: X = X ");
	X < Y;  usage_report("order: X < Y ");
	X = Y;  usage_report("assign: X = Y ");
	X == Y; usage_report("compare: X == Y ");

	return;
}

int main(int argc, char *argv[], char *envp[])
{
	constructor_tests();
	resize_tests();
	resize_tests(100);
	insert_tests();
	assing_and_compare_tests();

	return 0;
}
