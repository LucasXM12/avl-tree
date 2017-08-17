// AVLTree.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include <iostream>
#include <conio.h>

#include "Tree.h"
#include "AVLTree.h"

using namespace std;

int main() {
	Tree aux;

	for (int i = 0; i < 15; i++) {
		aux.addNode(i);
		cout << aux << endl << endl;
	}
	

	_getch();

	return 0;
}

