#pragma once
#define MAX_VERTEX_NUM 100
#include <iostream>
using namespace std;
class ADJMatGraph {
protected:
	int size;
	char vertices[MAX_VERTEX_NUM];
	int adj[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
public:
	ADJMatGraph() { init(); }
	char getVertex(int i) { return vertices[i]; }
	int getEdge(int i, int j) { return adj[i][j]; }
	void setEdge(int i, int j, int val) { adj[i][j] = val; }
	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX_VERTEX_NUM; }

	void init() {
		size = 0;
		for (int i = 0; i < MAX_VERTEX_NUM; i++)
			for (int j = 0; j < MAX_VERTEX_NUM; j++)
				setEdge(i, j, 0);
	}
	void insertVertex(char name) {
		if (!isFull())vertices[size++] = name;
		else cout << "Error: 그래프 정점 개수 초과\n";
	}
	void insertEdge(char u, char v, int w) {
		int uIndex = u - 'A';
		int vIndex = v - 'A';
		setEdge(uIndex, vIndex, w);
		setEdge(vIndex, uIndex, w);
	}
	void deleteEdge(char u, char v) {
		int uIndex = u - 'A';
		int vIndex = v - 'A';
		setEdge(uIndex, vIndex, 0);
		setEdge(vIndex, uIndex, 0);
	}
	int degree(char v) {
		int vIndex = v - 'A';
		int count = 0;
		for (int i = 0; i < size; i++) {
			if (adj[vIndex][i] != 0)
				count++;
		}
		return count;
	}
	void adjacent(char v) {
		int vIndex = v - 'A';
		cout << getVertex(vIndex) << "와 인접한 정점들: ";
		for (int i = 0; i < size; i++) {
			if (adj[vIndex][i] != 0)
				cout << getVertex(i) << " ";
		}
		cout << endl;
	}
	void display() {
		cout << "정점의 개수: " << size << endl;
		cout << " ";
		for (int i = 0; i < size; i++) {
			if (i == 0) cout << "";
			cout << getVertex(i) << "";
		}
		cout << endl;

		for (int i = 0; i < size; i++) {
			cout << getVertex(i) << "";
			for (int j = 0; j < size; j++)
				cout << getEdge(i, j) << "";
			cout << endl;
		}
	}
};