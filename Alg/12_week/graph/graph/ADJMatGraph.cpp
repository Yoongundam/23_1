#include "AdjMatGraph.h"
int main() {
	cout << "19110171_윤건" << endl;
	AdjacencyMatrix g1(0);
	g1.insertVertex('A');
	g1.insertVertex('B');
	g1.insertVertex('C');
	g1.insertVertex('D');
	g1.insertEdge('A','B');
	g1.insertEdge('A','D');
	g1.insertEdge('B','C');
	g1.insertEdge('C','D');
	g1.insertEdge('B','D');
	//g1.display();

	g1.insertVertex('E');
	g1.insertEdge('B','E');
	g1.insertEdge('C','E');
	//g1.display();
	cout << "B의 차수는 ? " << g1.degree('B') << endl;
	g1.deleteEdge('B', 'C');
	cout << "B의 차수는 ? " << g1.degree('B') << endl;
	//g1.adjacent(1);
	g1.DFS();
	cout << "\n\n****************\n";
	g1.deleteEdge('B', 'C');
	g1.deleteEdge('B', 'E');
	g1.deleteEdge('D', 'C');
	g1.DFS();

	cout << "\n\n****************\n";
	g1.deleteEdge('A', 'D');
	g1.deleteEdge('D', 'B');
	g1.DFS();

	return 0;
}