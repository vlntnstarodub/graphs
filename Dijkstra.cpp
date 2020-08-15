#include <iostream>
#include <vector>

#include "Dijkstra.h"

using namespace std;
void Dijkstra(vector<vector<int>> matrix, int start, int vertex)
{
	vector<int> length_of_way;
	int count, index, i, u, m = start + 1;
	vector<bool> used;
	for (i = 0; i < vertex; i++)
	{
		length_of_way.push_back(INT_MAX);
		used.push_back(false);
	}
	length_of_way[start] = 0;
	for (count = 0; count < vertex - 1; count++)
	{
		int min = INT_MAX;
		for (i = 0; i < vertex; i++)
			if (!used[i] && length_of_way[i] <= min)
			{
				min = length_of_way[i];
				index = i;
			}
		u = index;
		used[u] = true;
		for (i = 0; i < vertex; i++)
			if (!used[i] && matrix[u][i] && length_of_way[u] != INT_MAX && length_of_way[u] + matrix[u][i] < length_of_way[i])
				length_of_way[i] = length_of_way[u] + matrix[u][i];
	}
	cout << "the way from the start to the rest:" << endl;
	for (i = 0; i < vertex; i++)
		if (length_of_way[i] != INT_MAX)
			cout << m << " > " << i + 1 << " = " << length_of_way[i] << endl;
		else cout << m << " > " << i + 1 << " = " << "route unavailable" << endl;
}
