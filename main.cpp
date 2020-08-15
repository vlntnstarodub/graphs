#include <iostream>
#include<iomanip>
#include <vector>

#include "Dijkstra.h"
#include "Prim.h"
using namespace std;


int main() {
	
	int vertex;
	cout << "Enter quantity of vertex " << endl;
	cin >> vertex;
	vector<vector<int>> matrix (vertex);
	cout << "Enter the matrix" << endl;
	cout << setw(4);
	for (int i = 0; i < vertex; i++)
		cout << "|x" << i + 1;
	cout << endl;
	for (int i = 0; i < vertex; i++)
	{
		matrix[i].resize(vertex);
		cout << "X" << i + 1 << '|';
		for (int j = 0; j < vertex; j++)
			cin >> matrix[i][j];
	}
	int start;
	cout << "Start vertex: ";
	cin >> start;
	start = start - 1;
	Dijkstra(matrix, start, vertex);
	Prim(matrix, vertex);
	system("pause");
	return 0;
}
