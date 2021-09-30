#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int n, k, n1, n2, i_n, raz;
	cout << "Введите числа n k (Количество цифр числа n >k):" << endl;
	cin >> n>>k;
	n= fabs(n);
	n1 = n;
	n = fabs(n);
	n1 = n;
	n2 = n;
	for (i_n = 0; n1 > 0; i_n++)
	{
		n1 = n1 / 10;
	}
	k = fabs(k);
	if (i_n >= k) 
	{
        raz = i_n - k;
		n2 = n2 / pow(10, raz);
		cout << "Первые "<< k<< " цифр(ы) из числа " << n << ": " << n2;
		return 0;
	}
	else
	{
		cout << "Введите k < количества цифр числа n!!";
		return 0;
	}
}