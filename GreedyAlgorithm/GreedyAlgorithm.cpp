// GreedyAlgorithm.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <fstream>


#define V 40
int moeblob = 0;


int minKey(int key[], bool mstSet[])
{

	int min = 99999999, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}


void printMST(int parent[], int n, int graph[V][V])
{

	for (int i = 1; i < V; i++){
		moeblob = moeblob + graph[i][parent[i]];
	}
	std::cout << moeblob << '\n';
}


void primMST(int graph[V][V])
{
	int parent[V];
	int key[V];
	bool mstSet[V];
	for (int i = 0; i < V; i++)
		key[i] = 99999999, mstSet[i] = false;

	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < V - 1; count++)
	{

		int u = minKey(key, mstSet);

		mstSet[u] = true;

		for (int v = 0; v < V; v++)

			if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	printMST(parent, V, graph);
}


int main()
{

	int graph[V][V];

	int a = 0;
	int b = 0;

	std::string kknd = "-";
	std::ifstream file("network.txt");
	std::string str;

	while (std::getline(file, str))
	{
		std::string input = str;
		std::istringstream ss(input);
		std::string token;

		while (std::getline(ss, token, ',')) {

			if (token == kknd){
				graph[a][b] = 0;
			}
			else{
				graph[a][b] = atoi(token.c_str());;
			}

			b = b + 1;
		}
		b = 0;
		a = a + 1;
	}

	primMST(graph);

	system("pause");
	return 0;

}
