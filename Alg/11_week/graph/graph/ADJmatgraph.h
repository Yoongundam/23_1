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
		else cout << "Error: �׷��� ���� ���� �ʰ�\n";
	}
	void insertEdge(int u, int v ,int w) {
		setEdge(u, v, w);
		setEdge(v, u, w);
	}
	void deleteEdge(int u, int v) {
		setEdge(u, v, 0);
		setEdge(v, u, 0);
	}
	int degree(int v) {
		int count = 0;
		for (int i=0; i < size; i++) {
			if (adj[v][i] != 0)
				count++;
		}
		return count;
	}
	void adjacent(int u) {
		cout << getVertex(u) << "�� ������ ������ : ";
		for (int i = 0; i < size; i++) {
			if (adj[u][i] != 0)
				cout << getVertex(i)<<" ";
		}
		cout << endl;
	}
	void display() {
		cout << "������ ����: " << size << endl;
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