#include "source.h"
#include <conio.h>


int main() {

	std::cout << "Hi" << std::endl;
	angle angle;
	double value;
	int nAp;
	while (true) {
		system("cls");

		std::cout << "0. exit\n";
		std::cout << "1. enter the angle\n";
		std::cout << "2. enter the number\n";
		std::cout << "3. sin \n";
		std::cout << "4. cos\n";
		std::cout << "5. ln\n";
		std::cout << "6. sh\n";
		std::cout << "7. ch\n";
		std::cout << "8. funk A\n";
		std::cout << "9. lagrange polynom\n";

		//char com = _getch();

		char op;
		std::cin >> op;
		try {
			switch (op) {
			case '0': return 0; break;
			case '1': {
				std::cout << "angle = ";
				std::cin >> angle.grad;
				//std::cout << "* ";
				std::cin >> angle.min;
				//std::cout << "' ";
				std::cin >> angle.sec;
				//std::cout << "'' ";
				//return 0;
				break;
			}
			case '2':
				std::cout << "value = ";
				std::cin >> value;
				break;
			case '3':
				angle.toRad();
				std::cout << "Precision = ";
				std::cin >> nAp;

				std::cout << "sin(" << angle.grad << "*" << angle.min << "'" << angle.sec << "'') = "
					<< std::setprecision(nAp) << sinA(angle, nAp) << std::endl;
				_getch();
				break;
			case '4':
				angle.toRad();
				std::cout << "Precision = ";
				std::cin >> nAp;

				std::cout << "cos(" << angle.grad << "*" << angle.min << "'" << angle.sec << "'') = "
					<< std::setprecision(nAp) << cosA(angle, nAp) << std::endl;
				_getch();
				break;
			case '5':
				std::cout << "Precision = ";
				std::cin >> nAp;
				std::cout << "ln(" << value << ") = " << std::setprecision(nAp) << lnA(value, nAp) << std::endl;

				_getch();
				break;
			case '6':

				std::cout << "Precision = ";
				std::cin >> nAp;
				std::cout << "shA(" << value << ") = " << std::setprecision(nAp) << shA(value, nAp) << std::endl;

				_getch();
				break;
			case '7':
				std::cout << "Precision = ";
				std::cin >> nAp;
				std::cout << "chA(" << value << ") = " << std::setprecision(nAp) << chA(value, nAp) << std::endl;

				_getch();
				break;
			case '8':
				std::cout << "Precision = ";
				std::cin >> nAp;
				std::cout << std::setprecision(nAp) << A() << std::endl;
				_getch();
				break;
			case '9':
				double x[] = {1.0, 1.1, 1.2, 1.3, 1.4}; double y[] = {0.000000, 0.095310, 0.182322, 0.262364, 0.336472};
				//std::cout << "Degre = ";
				int deg = 5;
				std::cout << "Value = "; std::cin >> value;

				std::cout << Lagrange(value, deg, x, y);
				_getch();
				break;
			}
		}
		catch (const char* er) {
			std::cout << er << std::endl;
			_getch();
			return 1;
		}

	}

	return 0;
}

