#include "utilities.h"

int max(int a, int b) {
	return (a > b ? a : b);
}

int min(int a, int b) {
	return (a < b ? a : b);
}

bool userSaysYes() {
	char c;
	bool initialResponse = true;

	do {
		if (initialResponse) cout << "{y/n)?";
		else cout << "respond with either y or n: ";
		initialResponse = false;
		cin >> c;
	} while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');

	return (c == 'y' || c == 'Y');
}