#include"Graph.hpp"
using namespace std;


void TestGraphBellmanFord()
{
	vector<char> str = { 's','y','z','t','x' };
	Matrix::Graph<char, int, INT_MAX, true> g(str, str.size());
	g.AddEdge('s', 't', 6);
	g.AddEdge('s', 'y', 7);
	g.AddEdge('y', 'z', 9);
	g.AddEdge('y', 'x', -3);
	g.AddEdge('z', 's', 2);
	g.AddEdge('z', 'x', 7);
	g.AddEdge('t', 'x', 5);
	g.AddEdge('t', 'y', 8);
	g.AddEdge('t', 'z', -4);
	g.AddEdge('x', 't', -2);
	std::vector<int> dist;
	std::vector<int> parentPath;
	if (g.Bellman_Ford('s', dist, parentPath))
	{
		std::cout << "不存在负权回路" << std::endl;
	}
	else
	{
		std::cout << "存在负权回路" << std::endl;
	}
}

int main()
{
	/*vector<int> v = { 0,1,2,3,4,5 };
	Matrix::Graph<int, int, DEF, false> g(v, v.size());
	g.AddEdge(0, 1, 6);
	g.AddEdge(0, 2, 1);
	g.AddEdge(0, 3, 5);
	g.AddEdge(1, 2, 2);
	g.AddEdge(1, 4, 5);
	g.AddEdge(2, 3, 2);
	g.AddEdge(2, 4, 6);
	g.AddEdge(2, 5, 4);

	g.Print();*/
											
	/*vector<string> a = { "张三", "李四", "王五", "赵六" };
	Matrix::Graph<string, int> g1(a, 4);
	g1.AddEdge("张三", "李四", 100);
	g1.AddEdge("张三", "王五", 200);
	g1.AddEdge("王五", "赵六", 30);
	g1.Print();
	g1.BFS("张三");
	g1.DFS("张三");*/

	/*Matrix::Graph<string, int> g2(a, 4);
	g2.MST_Kruskal(g1);*/

	//std::cout << "最小生成树(Prim算法):" << std::endl;

	//Matrix::Graph<char, int> mst;  // 空图，用于存储MST
	//Matrix::Graph<char, int> mst1;  // 空图，用于存储MST

	//vector<char> c = { 'a','b','c','d','e','f','g','h','i' };
	//Matrix::Graph<char, int> g(c, c.size());
	//g.AddEdge('a', 'b', 4);
	//g.AddEdge('a', 'h', 8);
	//g.AddEdge('a', 'h', 9);
	//g.AddEdge('b', 'c', 8);
	//g.AddEdge('b', 'h', 11);
	//g.AddEdge('c', 'i', 2);
	//g.AddEdge('c', 'f', 4);
	//g.AddEdge('c', 'd', 7);
	//g.AddEdge('d', 'f', 14);
	//g.AddEdge('d', 'e', 9);
	//g.AddEdge('e', 'f', 10);
	//g.AddEdge('f', 'g', 2);
	//g.AddEdge('g', 'h', 1);
	//g.AddEdge('g', 'i', 6);
	//g.AddEdge('h', 'i', 7);
	//g.Print();
	//int totalWeight = g.MST_Prim(mst, 'a');

	//g.MST_Kruskal(mst1);

	TestGraphBellmanFord();

	return 0;
}