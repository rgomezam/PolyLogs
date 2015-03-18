//============================================================================
// Name        : dilog.cpp
// Author      : Raquel Gomez
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//============================================================================
// Name        : polilogs2.cpp
// Author      : Raquel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Simple code to calculate a Dilogarithm, based on the expansion presented in 't Hooft + Veltman "Scalar One-Loop Integrals" (1979), appendix A

#include <iostream>
#include <complex> //Library for complex math
#include <iomanip> // IO Manipulators library. Contains function setprecission();
//#include <cmath> //?
using namespace std;

const double BERNOULLI[] = { 1, -0.5, 0.166667, 0., -0.0333333, 0., 0.0238095,
		0., -0.0333333, 0., 0.0757576, 0., -0.253114, 0., 1.16667, 0., -7.09216,
		0., 54.9712, 0., -529.124, 0., 6192.12, 0., -86580.3, 0., 1.42552e6, 0.,
		-2.72982e7, 0., 6.01581e8, 0., -1.51163e10, 0., 4.29615e11, 0.,
		-1.37117e13, 0., 4.88332e14, 0. };

const double PI = 3.141592653589793238463;

complex<double> x;

double factorial(int);
complex<double> Li2(complex<double>);
complex<double> Li2b(complex<double>);
complex<double> Li2c(complex<double>);

int main() {
	char a;

	while (true) {
		cout << "Want to see some polylogs? (y/n) " << endl;
		cin >> a;

		switch (a) {
		case 'y': {
			cout << " Introduce Re(x)" << endl;
			cin >> real(x);
			cout << " Introduce Im(x)" << endl;
			cin >> imag(x);

			if (norm(x) < 0.5) {
				cout << "case 1: norm(x) = " << norm(x) << " < 0.5 " << endl;
				cout << "Li2(x) = " << setprecision(13) << Li2(x) << endl;
			}

			else if ((norm(x) > 0.5) && (norm(x) < 2)) {

				cout << "case 2: 0.5 < norm(x)= " << norm(x) << " < 2 " << endl;
				cout << "Li2(x) = " << setprecision(13) << Li2b(x) << endl;
			}
			else {
				cout << "case 3: norm(x) = " << norm(x) << " > 2 " << endl;
				cout << "Li2(x) = " << setprecision(13) << Li2c(x) << endl;
			}

			break;
		}
		case 'n':
			cout << "OK. Bye bye! " << endl;
			return 0;
		}
	}
	return 0;
}

double factorial(int n) {
	double f = 1;
	for (int i = 1; i <= n; i++) {
		f *= i;
	}
	return f;
}

//complex <double> a=3+4i;
//complex <double> b=1+2i;

complex<double> Li2(complex<double> x) {

	complex<double> li2(0., 0.);
	complex<double> z = -log(1. - x);

	for (int n = 0; n <= 39; n++) {

		//complex <double> temp2= Bernoulli[n]*pow(z, n+1)/factorial(n+1);
		li2 += BERNOULLI[n] * pow(z, n + 1) / factorial(n + 1);
	}

	return li2;
}

complex<double> Li2b(complex<double> x) {

	complex<double> li2b(0., 0.);

	if (imag(x))

		li2b = -Li2(1. - x) + (1. / 6.) * PI * PI - log(x) * log(1. - x);

	else

		li2b = -Li2(1. - x) + (1. / 6.) * PI * PI;

	return li2b;
}


 complex<double> Li2c(complex<double> x){


 complex <double> li2c  (0. , 0.);

 if (imag(x))

 li2c= - Li2(1./x) - (1./6.)*PI*PI - 0.5 * log(-x)*log(-x) ;

 else

 li2c= - Li2(1./x) - (1./6.)*PI*PI - 0.5 * log (-2. *x) ;




 return li2c;
 }
