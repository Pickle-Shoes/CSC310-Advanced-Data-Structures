#include <iostream>
#include <fstream>
using namespace std;

#include "bst.h"

// command line argument: name of command file
// see assignment for command file guidelines
int main(int argc, char *argv[])
{
	if(argv[1] == NULL)
	{
		cout << "Please provide a file." << endl;
		return 1;
	}

	bstree t;
	FILE *fp;
	fp = fopen(argv[1], "r");
	int readNum, tallest;

	fscanf(fp, "%d", &readNum);
	while(readNum != 0)
	{
		switch(readNum)
		{
			case -1: //Remove
				fscanf(fp, "%d", &readNum);
				t.remove(readNum);
				cout << "Remove success" << endl;
				break;
			case 1: //Insert
				fscanf(fp, "%d", &readNum);
				t.insert(readNum);
				break;
			case 2: //Search
				fscanf(fp, "%d", &readNum);
				if(t.search(readNum))
					cout << "Search " << readNum << ": Found" << endl;
				else
					cout << "Search " << readNum << ": Not Found" << endl;
				break;
			case 3: //Pre-Order Print
				t.pre();
				break;
			case 4:
				t.in(); //In-Order Print
				break;
			case 5:
				t.post(); //Post-Order Print
				break;
			case 6:	//print the bst for visual
				cout << "Binary Search Tree: " << endl;
				t.printBST();
				break;
			case 7: //Number of Nodes in Tree
				cout << "Number of Nodes: " << t.numnodes() << endl;
				break;
			case 8: //Height of the Tree
				cout << "Height of Tree: " << t.height() << endl;
				break;
			case 9: //Left or Right Side Taller
				tallest = t.taller();
				if(tallest == -1)
					cout << "The left side is taller." << endl;
				else if(tallest == 1)
					cout << "The right side is taller." << endl;
				else
					cout << "Both sides are equal in height." << endl;
				break;
			default: //Default Message
				cout << "Command " << readNum << " not recognized." << endl;
		}

		//cout << "Num: " << readNum << endl;
		fscanf(fp, "%d", &readNum);
	}
	return 0;
}



