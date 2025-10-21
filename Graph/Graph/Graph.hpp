#pragma once
#include<unordered_map>
#include<vector>
#include<iostream>
#include<unordered_set>
#include<queue>
#include<map>
#include "D:\my code\Union-Find-Set\Union-Find-Set\UnionFindSet.hpp"
#include<assert.h>
#define DEF 0x3f3f3f3f
//图的存储方式：
//邻接矩阵
//1.邻接矩阵的存储方式非常直观，适合边较多的图
//2.邻接矩阵O(1)判断两个顶点的连接关系，并取到权值
//3.相对而言不适合查找一个顶点连接所有边
// 
//邻接表
//1.邻接表的存储方式节省空间，适合边较少的图
//2.邻接表适合查找一个顶点连接所有边
//3.相对而言不适合判断两个顶点的连接关系以及取到权值
// 
//总结：邻接矩阵与邻接表各有优缺点，选择哪种存储方式取决于具体应用场景和需求

//说明：V为顶点类型，W为权值类型，MAX_W为最大权值，Direction表示是否为有向图
namespace Matrix
{
	template<class W>
	class Edge
	{
	public:
		Edge()
		{}

		Edge(int src, int dest, W weight)
			:_src(src)
			, _dest(dest)
			, _weight(weight)
		{
		}
		int GetSrc() const
		{
			return _src;
		}
		int GetDest() const
		{
			return _dest;
		}
		W GetWeight() const
		{
			return _weight;
		}

		bool operator()(const Edge& e1, const Edge& e2) const
		{
			return e1._weight > e2._weight; //权值小的优先级高
		}

	private:
		int _src; //起点索引
		int _dest; //终点索引
		W _weight; //权值
	};

	template<class V, class W, W MAX_W = DEF, bool Direction = false>
	class Graph
	{
		typedef Graph<V, W, MAX_W, Direction> Self;
		typedef Edge<W> Edge;
	public:
		Graph()
		{
		}

		Graph(const std::vector<V>& vertex, size_t n)//使用顶点数组来进行初始化
			:_adj(n, std::vector<W>(n,MAX_W))
		{
			assert(vertex.size() == n);

			for (int i = 0; i < vertex.size(); i++)
			{
				_vertex.push_back(vertex[i]);
				_index[vertex[i]] = i;
			}
		}

		int GetVertexIndex(const V& v) const
		{
			auto ptr = _index.find(v);
			if (ptr != _index.end()) return ptr->second;
			else
			{
				std::cout << "不存在的顶点" << std::endl;
				return -1;
			}
		}

		void BFS(const V& src)
		{
			//从src开始进行广度优先遍历
			std::vector<bool> visited(_vertex.size(), false);//记录顶点是否被访问过
			std::queue<int> q;
			int s = GetVertexIndex(src),step = 0;
			if (s == -1) return;
			q.push(s);
			visited[s] = true;
			while (q.size())
			{
				step++;
				int n = q.size();
				for (int i = 0; i < n; i++)
				{
					int front = q.front();
					std::cout << _vertex[front] << " ";
					q.pop();
					for(int j=0;j<_vertex.size();j++)
					{
						if(_adj[front][j]!=MAX_W && !visited[j])
						{
							q.push(j);
							visited[j] = true;
						}
					}
				}
			}
			std::cout << "共有" << step << "步" << std::endl;
		}

		void DFSHelper(int s, std::vector<bool>& visited)
		{
			std::cout << _vertex[s] << " ";
			visited[s] = true;
			for (int i = 0; i < _vertex.size(); i++)
			{
				if (_adj[s][i] != MAX_W && !visited[i])
				{
					DFSHelper(i, visited);
				}
			}
		}
		void DFS(const V& src)
		{
			std::vector<bool> visited(_vertex.size(), false);//记录顶点是否被访问过
			int s = GetVertexIndex(src);
			if (s == -1) return;
			DFSHelper(s, visited);
			std::cout << std::endl;
		}
		//如果遍历的不是一个连通图？则：
		//维护一个全局访问标记数组（记录所有顶点是否被访问）；
		//循环遍历图中所有顶点；
		//对每个未被访问的顶点，以它为起点，启动一次 DFS 或 BFS；
		//每次启动新搜索，本质是在处理一个“新的连通分量”。

		bool AddEdge(const V& v1, const V& v2, W weight)
		{
			int i = GetVertexIndex(v1);
			int j = GetVertexIndex(v2);
			if (i == -1 || j == -1) return false;
			_adj[i][j] = weight;
			if (!Direction) _adj[j][i] = weight; //无向图
			return true;
		}

		//最小生成树:要求包含图中所有顶点的连通子图，且边的权值之和最小，顶点为n，则边数为n-1
		//Kruskal算法
		//1.将图中的所有边按照权值从小到大排序
		//2.依次取出权值最小的边，判断是否会形成环路，如果不会则加入生成树中，否则舍弃
		//3.重复步骤2，直到生成树中包含所有顶点或者边数达到顶点数-1
		W MST_Kruskal(Self& graph)
		{
			graph._vertex = _vertex;
			graph._index = _index;
			graph._adj.resize(_vertex.size(), std::vector<W>(_vertex.size(), MAX_W));

			std::priority_queue<Edge, std::vector<Edge>, Edge> pq; //小根堆
			for(int i=0;i<_adj.size();i++)
			{
				for(int j=0;j<_adj[i].size();j++) 
				{
					if (i < j && _adj[i][j] != MAX_W)//无向图只需要存储一半即可
					{
						pq.push(Edge(i,j,_adj[i][j]));
					}
				}
			}

			W totalWeight=W();
			size_t edgeCount = 1;
			UnionFindSet ufs(_vertex.size());
			while (pq.size())
			{
				Edge top = pq.top(); pq.pop();
				int src = top.GetSrc();
				int dest = top.GetDest();
				W weight = top.GetWeight();
				if(ufs.Union(src,dest)) //如果不在同一个集合中，则加入生成树中
				{
					//std::cout << _vertex[src] << "->" << _vertex[dest] << " : " << weight << std::endl;
					graph.AddEdge(_vertex[src], _vertex[dest], weight);
					totalWeight += weight;
					edgeCount++;
				}
			}

			if(edgeCount==_vertex.size()) return totalWeight;
			else
			{
				std::cout << "图不连通，无法生成最小生成树" << std::endl;
				return W();
			}
			
		}
		//Prim算法
		//1.从任意一个顶点开始，将其加入生成树中
		//2.找到所有与生成树中顶点相连的边中权值最小的边，加入生成树中
		//3.重复步骤2，直到生成树中包含所有顶点或者边数达到顶点数-1
		W MST_Prim(Self& graph, const V& src)
		{
			graph._vertex = _vertex;
			graph._index = _index;
			graph._adj.resize(_vertex.size(), std::vector<W>(_vertex.size(), MAX_W));

			std::unordered_set<int> inMST; //记录已经加入生成树的顶点
			std::priority_queue<Edge, std::vector<Edge>, Edge> pq; //小根堆
			W totalWeight = W();
			int s = GetVertexIndex(src);
			inMST.insert(s);
			for(int i=0;i<_vertex.size();i++)
			{
				if(_adj[s][i]!=MAX_W)
				{
					pq.push(Edge(s, i, _adj[s][i]));//将与s相连的边加入优先队列
				}
			}

			while (pq.size())
			{
				Edge top = pq.top(); pq.pop();
				int src = top.GetSrc();
				int dest = top.GetDest();
				W weight = top.GetWeight();
				if (!inMST.count(dest))//如果该顶点不在生成树中,如果存在那么插入就会形成环路
				{
					graph.AddEdge(_vertex[src], _vertex[dest], weight);
					//std::cout << _vertex[src] << "->" << _vertex[dest] << " : " << weight << std::endl;
					totalWeight += weight;
					for(int i=0;i<_vertex.size();i++)
					{
						if(_adj[dest][i]!=MAX_W && !inMST.count(i))
						{
							pq.push(Edge(dest, i, _adj[dest][i]));//将与dest相连的边加入优先队列
						}
					}
					inMST.insert(dest);
				}
			}

			if (inMST.size() == _vertex.size()) return totalWeight;
			else
			{
				std::cout << "图不连通，无法生成最小生成树" << std::endl;
				return W();
			}
		}

		//单源最短路径:
		//如果存在负权，那么Dijkstra算法失效
		void Dijkstra(const V& src, std::vector<W>& dist, std::vector<int>& ParentPath)
		{
			int n = _vertex.size();
			int s = GetVertexIndex(src);
			// vector<W> dist,记录srci-其他顶点最短路径权值数组
			dist.resize(n, MAX_W);
			// vector<int> parentPath 记录srci-其他顶点最短路径父顶点数组
			ParentPath.resize(n, -1);
			// srci的权值给一个最小值，方便贪心第一次找到这个节点
			dist[s] = W();
			// 标记是否找到最短路径的顶点集合judge,如果已经找到了就不会变了，再根据已找到的去更新其他未找到的点
			std::vector<bool> judge(n, false);

			for (int i = 0; i < n; i++)
			{
				// 贪心算法：srci到不在S中路径最短的那个顶点u
				W min = MAX_W;
				int source = s;
				for (int j = 0; j < n; j++)
				{
					if (!judge[j] && dist[j] < min)
					{
						min = dist[j];
						source = j;
					}
				}
				judge[source] = true;

				// 松弛算法：更新一遍u连接的所有边，看是否能更新出更短连接路径
				for (int k = 0; k < n; k++)
				{
					// 如果srci->u + u->k 比 srci->k更短 则进行更新
					if (!judge[k] && _adj[source][k] != MAX_W && dist[source] + _adj[source][k] < dist[k])
					{
						dist[k] = dist[source] + _adj[source][k];
						ParentPath[k] = source;
					}
				}
			}

		}

		//Dijkstra算法只能用来解决正权图的单源最短路径问题，但有些题目会出现负权图。这时这个算法
		//就不能帮助我们解决问题了，而bellman—ford算法可以解决负权图的单源最短路径问题。它的
		//优点是可以解决有负权边的单源最短路径问题，而且可以用来判断是否有负权回路。它也有明显
		//的缺点，它的时间复杂度 O(N* E) (N是点数，E是边数)普遍是要高于Dijkstra算法O(N²)的。像这里
		//如果我们使用邻接矩阵实现，那么遍历所有边的数量的时间复杂度就是O(N ^ 3)，这里也可以看出来Bellman - Ford就是一种暴力求解更新。
		bool Bellman_Ford(const V& src, std::vector<W>& dist, std::vector<int>& ParentPath)
		{
			int n = _vertex.size();
			int s = GetVertexIndex(src);
			// vector<W> dist,记录srci-其他顶点最短路径权值数组
			dist.resize(n, MAX_W);
			// vector<int> parentPath 记录srci-其他顶点最短路径父顶点数组
			ParentPath.resize(n, -1);
			// srci的权值给一个最小值，方便贪心第一次找到这个节点
			dist[s] = W();

			//循环n-1次，因为除了原点有n-1个点，就算每个点都更新最多只会更新n-1次
			for (int k = 0; k < n - 1; k++)
			{
				bool judge = false;
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < n; j++)
					{
						if (_adj[i][j] != MAX_W && dist[i] + _adj[i][j] < dist[j])
						{
							dist[j] = dist[i] + _adj[i][j];
							ParentPath[j] = i;
							judge = true;
						}
					}
				}
				if (judge == false) break;//说明没有改变，所有最小路径已经被找到
			}

			//多用一次循环来检查是否存在负权回路，对于负权回路，每多一次循环就会更小，最小路径趋近负无穷
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (_adj[i][j] != MAX_W && dist[i] + _adj[i][j] < dist[j])
					{
						return false;
					}
				}
			}
		
			return true;
		}

		// 多源最短路径--Floyd - Warshall算法
		void Floyd_Warshall(std::vector<std::vector<W>>& dist,std::vector<std::vector<int>>& ParentPath)
		{
			int n = _vertex.size();
			dist.resize(n, std::vector<W>(n, MAX_W));
			ParentPath.resize(n, std::vector<int>(n, -1));

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (_adj[i][j] != MAX_W)
					{
						dist[i][j] = _adj[i][j];
						ParentPath[i][j] = i;
					}
				}
				dist[i][i] = 0;
				//ParentPath[i][i] = -1;
			}

			//k（中间节点）必须放在最外层枚举：保证每次用 k 优化路径时，i 到 k 和 k 到 j 的路径已经是 “最优的”。
			for (int k = 0; k < n; k++)
			{
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < n; j++)
					{
						//若i→k和k→j都可达，且“i→k→j”更短，更新dist[i][j]
						if (dist[i][k]!= MAX_W && dist[k][j] != MAX_W && dist[i][k] + dist[k][j] < dist[i][j])
						{
							dist[i][j] = dist[i][k] + dist[k][j];
							//i->k->j j上一个顶点为k
							ParentPath[i][j] = ParentPath[k][j];
						}
					}
				}
			}
		}

		void Print() const
		{
			for (int i = 0; i < _vertex.size(); i++)
			{
				std::cout << _vertex[i] << " ";
			}
			std::cout << std::endl;
			for (int i = 0; i < _vertex.size(); i++)
			{
				std::cout << i << " ";
			}
			std::cout << std::endl;

			for (int i = 0; i < _adj.size(); i++)
			{
				for (int j = 0; j < _adj[i].size(); j++)
				{
					if (_adj[i][j] == MAX_W) std::cout << "∞" << " ";
					else std::cout << _adj[i][j] << " ";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;


		}

	private:
		std::vector<V> _vertex; //顶点集合
		std::unordered_map<V, int> _index; //顶点索引
		std::vector<std::vector<W>> _adj; //邻接矩阵
	};
}

namespace Linktable
{
	template<class W>
	class Edge
	{
	public:
		Edge()
		{}

		Edge(int src, int dest, W weight)
			:_src(src)
			, _dest(dest)
			, _weight(weight)
			, _next(nullptr)
		{}

		bool Setnext(Edge* next)
		{
			_next = next;
			return true;
		}

		int GetSrc() const
		{
			return _src;
		}
		int GetDest() const
		{
			return _dest;
		}
		W GetWeight() const
		{
			return _weight;
		}
		Edge<W>* GetNext() const
		{
			return _next;
		}

	private:
		int _src; //起点索引
		int _dest; //终点索引
		W _weight; //权值
		Edge<W>* _next; //指向下一个边的指针
	};


	template<class V, class W, W MAX_W = DEF, bool Direction = false>
	class Graph
	{
		typedef Edge<W> Edge;
	public:
		Graph()
		{
		}

		Graph(const std::vector<V>& vertex, size_t n)//使用顶点数组来进行初始化
			:_adj(n,nullptr)
		{
			assert(vertex.size() == n);

			for (int i = 0; i < vertex.size(); i++)
			{
				_vertex.push_back(vertex[i]);
				_index[vertex[i]] = i;
			}
		}

		int GetVertexIndex(const V& v) const
		{
			auto ptr = _index.find(v);
			if (ptr != _index.end()) return ptr->second;
			else
			{
				std::cout << "不存在的顶点" << std::endl;
				return -1;
			}
		}

		bool AddEdge(const V& v1,const V& v2, W weight)
		{
			int i = GetVertexIndex(v1);
			int j = GetVertexIndex(v2);
			if (i == -1 || j == -1) return false;
			
			Edge* e = new Edge(i, j, weight);
			e->Setnext(_adj[i]);
			_adj[i] = e;//这里是头插法

			if(!Direction) //无向图
			{
				Edge* e = new Edge(j, i, weight);
				e->Setnext(_adj[j]);
				_adj[j] = e;//这里是头插法
			}
			return true;
		}

		void Print() const
		{
			for (int i = 0; i < _vertex.size(); i++)
			{
				std::cout << _vertex[i] << " ";
			}
			std::cout << std::endl;
			for (int i = 0; i < _vertex.size(); i++)
			{
				std::cout << i << " ";
			}
			std::cout << std::endl;

			for(int i = 0; i < _adj.size(); i++)
			{
				Edge* p = _adj[i];
				std::cout << p->GetSrc();
				while(p)
				{
					std::cout << "->(" << p->GetDest() << "," << p->GetWeight() << ")";
					p = p->GetNext();
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;


		}

	private:
		std::vector<V> _vertex; //顶点集合
		std::unordered_map<V, int> _index; //顶点索引
		std::vector<Edge*> _adj; //邻接表
	};
}