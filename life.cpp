#include "life.h"

void Life::initialize() {
	
	cout << "Do you want to change the predeterminted size(size<20x60)";
	if(userSaysYes()) ChangeSize();

	int row, col;
	for (row = 0; row < rowsize; ++row)
		for (col = 0; col < colsize; ++col)
			grid[row][col] = dead;

	int choice = 0;
	cout << "1:Input through file" << endl
		<< "2:Input with X and Space" << endl
		<< "3:Input with Numbers" << endl;

	while ((choice > 3) || (choice < 1))
		cin >> choice;

		switch (choice) {

		case 1:
			ReadFromFile();
			break;

		case 2:
			input();
			break;

		case 3:
			cout << "Enter row and column of living cells " <<
				"and finish with -1" << endl;
			while ((row != -1) || (col != -1)) {
				cin >> row >> col;
				if (row == -1 && col == -1)
					cout << "Done" << endl;
				else if ((row < 0) || (row >= rowsize))
					cout << "Row out of range" << endl;
				else if ((col < 0) || (col >= colsize))
					cout << "Column out of range" << endl;
				else
					grid[row][col] = alive;
			}
		}
}

void Life::print() const {
	for (int row = 0; row < rowsize; ++row) {
		for (int col = 0; col < colsize; ++col) {
			if (grid[row][col] == alive) cout << "*";
			else cout << " ";
		
		}
		cout << endl;
	}
}

int Life::neighborCount(int row,int col) const {
	int counter = 0;		

	for (int i = row - 1; i <= row + 1; ++i) {
		for (int j = col - 1; j <= col + 1; ++j) {
			if (grid[i][j] == alive) {
				counter++;
			}
		}
	}
	if (grid[row][col] == alive) {//counter + 1 because it counts itself
		if ((counter == 3) || (counter == 4))
			return 1;
	}
	else {
		if ((counter == 3))
			return 1;
	}
	return 0;
}

void Life::update() {
	for (int row = 0; row < rowsize; ++row) {
		for (int col = 0; col < colsize; ++col) {
			if (neighborCount(row, col) == 1) futuregrid[row][col] = alive;
			else futuregrid[row][col] = dead;
		}
	}
	for (int row = 0; row < rowsize; ++row) {
		for (int col = 0; col < colsize; ++col) {
			grid[row][col]=futuregrid[row][col];
		}
	}
}

void Life::edit() {
	char choice;
	int row;
	int col;

	cout << "Do you want to edit current generation?";
	while (userSaysYes()) {
		cout << "Enter row and column of the cell you want to edit:";
		cin >> row >> col;
		if ((row < 0) || (row >= rowsize))
			cout << "Row out of range" << endl;
		else if ((col < 0) || (col >= colsize))
			cout << "Column out of range" << endl;
		else {
			do {
				cout << endl << "Do you want it to become dead or alive(d/a)?";
				cin >> choice;
			} while (!(choice != 'd' || choice != 'D' || choice != 'A' || choice != 'a'));

			if (choice == 'D' || choice == 'd') grid[row][col] = dead;
			else grid[row][col] = alive;
		}
		cout << "Do you want to edit current generation again?";
	}
}

void Life::ChangeSize() {

	cout << "Enter the number of rows and columns you want:";
	cin >> rowsize >> colsize;

	size = new status *[rowsize];
	for (int i = 0; i < rowsize; ++i) {
		size[i] = new status[colsize];
	}
}

void Life::ReadFromFile() {
	int col;
	int row;
	string filelocation;

	    cin.ignore();
		cout << "Enter the location fo the file:";
		getline(cin, filelocation);

		Input.open(filelocation);

		while (Input.fail()) {
			cout << endl << "Cannot open file,make sure it's the correct path" << endl;
			cout << "Enter the file location:";
			getline(cin,filelocation);
			Input.open(filelocation);
		}

		while (!Input.eof()) {
			Input >> row >> col;
			grid[row][col] = alive;
		}

}

void Life::welcome() {
	cout << "Welcome to the game of life" << endl << endl;
}

void Life::input() {

	char Input[500];
	int row=0;

	cout << "Enter space for Dead,x/X for alive:";
	cin.ignore();
	cin.getline(Input,500);

	for (int col = 0; col < 500; ++col) {
		if (col == rowsize) row++;
		if ((Input[col] == 'x')|| (Input[col] == 'X'))grid[row][col] = alive;
		else grid[row][col] = dead; 
			
	}

}

void Life::deletearray() {
	for (int i = 0; i < rowsize; ++i) 
		delete[] size[i];
	delete[] size;
}
