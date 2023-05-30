#include "ADJMatGraph.h"
int main()
{
	ADJMatGraph g1;
	for (int i = 0; i < 6; i++)
		g1.insertVertex('A' + i);
	g1.insertEdge(0, 1,1);// => g1.insertEdge('A','B',1);
	g1.insertEdge(0, 3,1);
	g1.insertEdge(1, 2,1);
	g1.insertEdge(1, 3,1);
	g1.insertEdge(2, 3,1);
	g1.insertEdge(1, 4, 1);
	g1.insertEdge(2, 4, 1);
	cout << "인접 행렬로 표현한 그래프\n";
	g1.display();
	g1.degree(1);
	cout << "B의 차수 값 : " << g1.degree(1) << endl;
	g1.deleteEdge(1, 2);// => g1.deleteEdge('A','B');
	g1.degree(1);
	cout << "B와 C 간선 제거 후 B의 차수 값 : " << g1.degree(1) << endl;
	g1.adjacent(1);// => g1.adjacent('B');
	g1.deleteEdge(2, 3);
	g1.deleteEdge(0, 3);
	g1.deleteEdge(1, 4);
	g1.insertEdge(2, 5, 1);
	cout << "E를 추가하고 몇 간선 제거 후 g1 그래프\n";
	g1.display();

	return 0;
}