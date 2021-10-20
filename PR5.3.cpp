#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double f(const double x);
int main()
{
	double tp, tk, z;
	int n;
	cout << "tp = "; cin >> tp;
	cout << "tk = "; cin >> tk;
	cout << "n = "; cin >> n;

	cout << fixed;
	cout << "-------------------------------------------------" << endl;
	cout << "|" << setw(10) << "t" << "  |"
		<< setw(10) << "z" << "  |"
		<< endl;
	cout << "-------------------------------------------------" << endl;

	double dt = (tk - tp) / n;
	double t = tp;
	while (t <= tk)
	{
		z = f(2 * t) + (f(t * t + 1) * f(t * t + 1));
		cout << "|" << setw(10) << setprecision(5) << t << "  |"
			<< setw(10) << setprecision(5) << z << "  |"
			<< endl;
		t += dt;
	}
	return 0;
}
double f(const double x)
{
	if (abs(x) >= 1)
		return ((sin(2 * x) + 1) / (sin(x) + cos(x) * cos(x)));
	else
	{
		double S = 0;
		int n = 0;
		double a = 1;
		S = a;
		do
		{
			n++;
			double R = ((2 * (1 / n) + 1) / ((2 * n + 1) * (2 * n)));
			a *= R;
			S += a;
		} while (n < 7);
		return S;
	}
}