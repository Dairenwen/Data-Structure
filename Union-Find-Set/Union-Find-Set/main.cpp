#include "UnionFindSet.hpp"

using namespace std;

// 547. 省份数量，这是并查集在题目中的应用
int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<int> ufs(n, -1);
    auto findroot = [&ufs](int index) {
        int root = index;
        while (ufs[root] >= 0)
        {
            root = ufs[root];
        }

		//这里做了路径压缩，将沿途的节点都直接指向根节点
        while (ufs[index] >= 0)
        {
			int next = index;//记录节点
			index = ufs[index];//继续往上找
			ufs[next] = root;//指向根节点
        }

        return root;

        };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isConnected[i][j])
            {
                int indexa = findroot(i), indexb = findroot(j);
                if (indexa != indexb)
                {
                    ufs[indexa] += ufs[indexb];
                    ufs[indexa] = indexb;
                }
            }
        }
    }

    int count = 0;
    for (const auto& e : ufs)
    {
        if (e < 0) ++count;
    }
    return count;
}

// 990. 等式方程的可满足性
bool equationsPossible(vector<string>& equations) {
    int n = equations.size();
    vector<int> ufs(26, -1);

    auto findroot = [&ufs](int index) {
        int root = index;
        while (ufs[root] >= 0)
        {
            root = ufs[root];
        }
        while (ufs[index] >= 0)
        {
            int next = index;
            index = ufs[index];
            ufs[next] = root;
        }
        return root;

        };
	//如果是等式，先合并
    for (int i = 0; i < n; i++)
    {
        if (equations[i][1] == '=')
        {
            int a = equations[i][0] - 97, b = equations[i][3] - 97;
            int indexa = findroot(a), indexb = findroot(b);
            if (indexa != indexb)
            {
                ufs[indexa] += ufs[indexb];
                ufs[indexa] = indexb;
            }
        }
    }
	//如果是不等式，检查是否在同一个集合中
    for (int i = 0; i < n; i++)
    {
        if (equations[i][1] == '!')
        {
            int a = equations[i][0] - 97, b = equations[i][3] - 97;
            int indexa = findroot(a), indexb = findroot(b);
            if (indexa == indexb)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
	UnionFindSet ufs(10);
	return 0;
}