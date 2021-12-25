#include "source.h"
#include <conio.h>


int main() {

	std::cout << "Hi" << std::endl;
	angle angle;
	double value;
	int nAp;
	double X, h;
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
		std::cout << "10. funk exp(x)\n";
		std::cout << "11. Runge-Kutt (2, 3, 4)\n";

		//char com = _getch();

		enum TASKS { EXIT = 0, LAB_1_1, LAB_1_2, LAB_1_3, LAB_1_4, LAB_1_5, LAB_1_6, LAB_1_7, LAB_2, LAB_3, LAB_4, LAB_5 };

		int op;
		std::cin >> op;
		try {
			switch (op) {
			case EXIT: return 0; break;
			case LAB_1_1: {
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
			case LAB_1_2:
				std::cout << "value = ";
				std::cin >> value;
				break;
			case LAB_1_3:
				angle.toRad();
				std::cout << "Precision = ";
				std::cin >> nAp;

				std::cout << "sin(" << angle.grad << "*" << angle.min << "'" << angle.sec << "'') = "
					<< std::setprecision(nAp) << sinA(angle.rad, nAp) << std::endl;
				_getch();
				break;
			case LAB_1_4:
				angle.toRad();
				std::cout << "Precision = ";
				std::cin >> nAp;

				std::cout << "cos(" << angle.grad << "*" << angle.min << "'" << angle.sec << "'') = "
					<< std::setprecision(nAp) << cosA(angle.rad, nAp) << std::endl;
				_getch();
				break;
			case LAB_1_5:
				std::cout << "Precision = ";
				std::cin >> nAp;
				std::cout << "ln(" << value << ") = " << std::setprecision(nAp) << lnA(value, nAp) << std::endl;

				_getch();
				break;
			case LAB_1_6:

				std::cout << "Precision = ";
				std::cin >> nAp;
				std::cout << "shA(" << value << ") = " << std::setprecision(nAp) << shA(value, nAp) << std::endl;

				_getch();
				break;
			case LAB_1_7:
				std::cout << "Precision = ";
				std::cin >> nAp;
				std::cout << "chA(" << value << ") = " << std::setprecision(nAp) << chA(value, nAp) << std::endl;

				_getch();
				break;
			case LAB_2:
				std::cout << "Precision = ";
				std::cin >> nAp;
				std::cout << std::setprecision(nAp) << A() << std::endl;
				_getch();
				break;
			case LAB_3:
			{
				double x[] = { 1.0, 1.1, 1.2, 1.3, 1.4 }; double y[] = { 0.000000, 0.095310, 0.182322, 0.262364, 0.336472 };
				//std::cout << "Degre = ";
				int deg = 5;
				std::cout << "Value = ";
				std::cin >> value;
				std::cout << Lagrange(value, deg, x, y);
				_getch();
				break;
			}
			case LAB_4:
				std::cout << "Enter x: ";
				std::cin >> X;
				std::cout << "Enter h: ";
				std::cin >> h;
				std::cout << "Number of operations = ";
				std::cin >> nAp;
				std::cout << std::setprecision(nAp) << std::endl;
				std::cout << deltaX(X, h) << std::endl;
				std::cout << "Precision = ";
				std::cin >> nAp;
				std::cout << std::setprecision(nAp) << std::endl;
				std::cout << searchH(X, h) << std::endl;
				_getch();
				break;
			case LAB_5:
				double x0 = 0.0, y0 = 2.0;
				std::cout << "Solution dy/dx = y - x by the RK method" << std::endl;

				std::cout << "x0 = ";
				std::cin >> x0;
				std::cout << "y0 = ";
				std::cin >> y0;

				std::cout << "Precision = ";
				std::cin >> nAp;

				std::cout << "RK order = ";
				int order = 3;
				std::cin >> order;
				if (order == 1) {
					std::cout << "\n RK2" << std::endl;
					for (int i = 1; i <= nAp; i ++) {
						std::cout << "Iteration: " << i << 
							"\t solution:" << std::setprecision(nAp) << RK2(x0, y0, i) <<
							"\t	\t eps = " << std::setprecision(2 * i) << epsRK2(x0, y0, i) << std::endl;
					}

					std::cout << "\n RK3" << std::endl;
					for (int i = 1; i <= nAp; i++) {
						std::cout << "Iteration: " << i << 
							"\t solution:" << std::setprecision(nAp) << RK3(x0, y0, i) <<
							"\t	\t eps = " << std::setprecision(2 * i) << epsRK3(x0, y0, i) << std::endl;
					}

					std::cout << "\n RK4" << std::endl;
					for (int i = 1; i <= nAp; i ++) {
						std::cout << "Iteration: " << i <<
							"\t solution:" << std::setprecision(nAp) << RK4(x0, y0, i) <<
							"\t	\t eps = " << std::setprecision(2 * i) << epsRK4(x0, y0, i) << std::endl;
					}
					_getch();
				}
				if (order == 2) {
					for (int i = 1; i <= nAp; i++)
						std::cout << "Iterations: " << i <<
												std::setprecision(nAp) << "\t solution RK2:" << RK2(x0, y0, i) << 
													"\t	\t eps = " << std::setprecision(2*i)<< epsRK2(x0, y0, i) << std::endl;
					_getch();
				}
				else
					if (order == 3) {
						for (int i = 1; i < nAp; i ++)
							std::cout << "Iterations: " << i <<
														std::setprecision(nAp) << "\t solution RK3:" << RK3(x0, y0, i) <<
													"\t	\t eps = " << std::setprecision(2*i) << epsRK3(x0, y0, i) << std::endl;
						_getch();
					}
					else
						if (order == 4) {
							for (int i = 1; i < nAp; i ++)
								std::cout << "Iterations: " << i <<
													std::setprecision(nAp) << "\t solution RK4:" << RK4(x0, y0, i) <<
													"\t	\t eps = " << std::setprecision(2*i) << epsRK4(x0, y0, i) << std::endl;
							_getch();
						}
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

