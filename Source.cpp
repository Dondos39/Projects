//Theodoros Psarra 
//Game of Life
#include <iostream>
#include <stack>
#include "utilities.h"
#include "life.h"


int main()
{
	Life configuration;
	configuration.welcome();
	configuration.initialize();
	configuration.print();
	configuration.edit();
	cout << "Continue viewing new generations?" << endl;
	while (userSaysYes()) {
		configuration.update();
		configuration.print();
		configuration.edit();
		cout << "Continue viewing new generations?" << endl;
	}

	configuration.deletearray();
	getchar();
	return 0;
}