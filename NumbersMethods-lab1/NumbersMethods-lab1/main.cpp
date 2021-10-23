#include "source.h"
#include <conio.h>
#include <iomanip>

int main() {

	std::cout << "Hi" << std::endl;
	angle angle;
	double value;
	int nAp;
	while (true) {
		system("cls");

		std::cout << "0. exit\n";
		std::cout << "1. write angle\n";
		std::cout << "2. write number\n";
		std::cout << "3. sin \n";
		std::cout << "4. cos\n";
		std::cout << "5. sh\n";
		std::cout << "6. ch\n";
		std::cout << "7. ln\n";

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
					<< sinA(angle, nAp) << std::endl;
				_getch();
				break;
			case '4':
				angle.toRad();
				std::cout << "Precision = ";
				std::cin >> nAp;

				std::cout << "cos(" << angle.grad << "*" << angle.min << "'" << angle.sec << "'') = "
					<< cosA(angle, nAp) << std::endl;
				_getch();
				break;
			case '5':
				angle.toRad();
				std::cout << "Precision = ";
				std::cin >> nAp;
				std::cout << "shA(" << value << ") = " << shA(value, nAp) << std::endl;
				_getch();
				break;

			case '6': break;

			case '7': break;

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
					std::cout << "ln(" << value << ") = " << lnA(value, nAp) << std::endl;
					
					_getch();
					break;
				case '6':

					std::cout << "Precision = ";
					std::cin >> nAp;
					std::cout << "shA(" << value << ") = " << shA(value, nAp) << std::endl;

					_getch();
					break;
				case '7':
					std::cout << "Precision = ";
					std::cin >> nAp;
					std::cout << "chA(" << value << ") = " << chA(value, nAp) << std::endl;

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

