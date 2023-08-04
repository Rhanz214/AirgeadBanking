#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

int mn() {
	int testNum;
	char word = 'c';

	while (true) {
		try {
			cout << "Enter number: ";
			cin >> testNum;

			if (testNum < 5) {
				throw runtime_error("Invalid Num.");
				break;
			}

			cout << "Enter char";
			cin >> word;

			if (word != 'a') {
				throw runtime_error("invalid character");
				break;
			}
			break;
		}
		catch (runtime_error& excpt) {
			cout << excpt.what() << endl;
			cout << "Incorrect info entered." << endl;
		}
	}

	cout << "did it work?" << endl;

	return 0;
}