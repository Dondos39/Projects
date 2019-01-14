#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "utilities.h"
using namespace std;

enum status { dead, alive };

class Life {
public:
	void initialize();
	void print() const;
	void update();
	void edit();
	void welcome();
	void ChangeSize();
	void ReadFromFile();
	void input();
	void deletearray();
private:
	int neighborCount(int, int) const;
	int rowsize = 20;
	int colsize = 60;
	status **size;
	ifstream Input;

	status grid[20][60];
	status futuregrid[20][60];
};