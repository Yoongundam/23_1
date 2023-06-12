#include "ADJMatGraph.h"
int main()
{
	cout << "19110171_윤건" << endl;
	ADJMatGraph g1;
	for (int i = 0; i < 6; i++)
		g1.insertVertex('A' + i);
	g1.insertEdge('A', 'B', 1);// => g1.insertEdge('A','B',1);
	g1.insertEdge('A', 'D', 1);
	g1.insertEdge('B', 'C', 1);
	g1.insertEdge('B', 'D', 1);
	g1.insertEdge('C', 'D', 1);
	g1.insertEdge('B', 'E', 1);
	g1.insertEdge('C', 'E', 1);
	cout << "인접 행렬로 표현한 그래프\n";
	g1.display();
	g1.degree('B');
	cout << "B의 차수 값 : " << g1.degree('B') << endl;
	g1.deleteEdge('B', 'C');// => g1.deleteEdge('A','B');
	g1.degree('B');
	cout << "B와 C 간선 제거 후 B의 차수 값 : " << g1.degree('B') << endl;
	g1.adjacent('B');// => g1.adjacent('B');
	g1.deleteEdge('C', 'D');
	g1.deleteEdge('A', 'D');
	g1.deleteEdge('B', 'E');
	g1.insertEdge('C', 'F', 1);
	cout << "F를 추가하고 몇 간선 제거 후 g1 그래프\n";
	g1.display();

	return 0;
}