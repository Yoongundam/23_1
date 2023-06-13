#pragma once
#include <iostream>
using namespace std;

class AdjacencyMatrix {
protected:
    int vertexCount;
    char vertexName[100];
    int matrix[100][100];
    bool* visited;

public:
    AdjacencyMatrix(int count) {
        vertexCount = count;
        for (int i = 0; i < vertexCount; i++) {
            for (int j = 0; j < vertexCount; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    char getVertex(int index) {
        return vertexName[index];
    }

    bool isEmpty() {
        return vertexCount == 0;
    }

    bool isFull() {
        return vertexCount == 100;
    }

    void insertVertex(char name) {
        vertexName[vertexCount++] = name;
    }

    void insertEdge(char v1, char v2) {
        int index1 = -1, index2 = -1;
        for (int i = 0; i < vertexCount; i++) {
            if (vertexName[i] == v1) {
                index1 = i;
            }
            if (vertexName[i] == v2) {
                index2 = i;
            }
        }
        this->matrix[index1][index2] = this->matrix[index2][index1] = 1;
    }

    void deleteEdge(char v1, char v2) {
        int index1 = -1, index2 = -1;
        for (int i = 0; i < vertexCount; i++) {
            if (vertexName[i] == v1) {
                index1 = i;
            }
            if (vertexName[i] == v2) {
                index2 = i;
            }
        }
        this->matrix[index1][index2] = this->matrix[index2][index1] = 0;
    }

    int degree(char name) {
        int index = -1;
        for (int i = 0; i < vertexCount; i++) {
            if (vertexName[i] == name) {
                index = i;
                break;
            }
        }
        int count = 0;
        for (int j = 0; j < vertexCount; j++) {
            if (this->matrix[index][j] == 1) {
                count++;
            }
        }
        return count;
    }

    void DFS() {
        visited = new bool[this->vertexCount];
        memset(visited, 0, sizeof(bool) * this->vertexCount);

        for (int v = 0; v < this->vertexCount; v++) {
            if (!visited[v]) {
                cout << "\n시작정점 : " << getVertex(v) << "부터 탐색\n";
                aDFS(v);
            }
        }
        delete[] visited;
    }

    void aDFS(int v) {
        visited[v] = true;
        cout << " " << this->getVertex(v);
        for (int w = 0; w < this->vertexCount; w++) {
            if (this->matrix[v][w] == 1 && !visited[w])
                aDFS(w);
        }
    }
};