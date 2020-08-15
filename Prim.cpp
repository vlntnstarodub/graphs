#include <iostream>
#include <vector>

#include "Prim.h"

using namespace std;
void Prim(vector<vector<int>> matrix, int vertex) {
	vector<bool> used(vertex);
	vector<int> min_e(vertex, INT_MAX), sel_e(vertex, -1);
	min_e[0] = 0;
	for (int i = 0; i < vertex; ++i) {
		int v = -1;
		for (int j = 0; j < vertex; ++j)
			if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
				v = j;
		if (min_e[v] == INT_MAX) {
			cout << "there is no way";
			exit(0);
		}

		used[v] = true;
		if (sel_e[v] != -1)
			cout << v + 1 << " - " << sel_e[v] + 1 << endl;

		for (int to = 0; to < vertex; ++to)
			if (matrix[v][to] < min_e[to]) {
				min_e[to] = matrix[v][to];
				sel_e[to] = v;
			}
	}
}