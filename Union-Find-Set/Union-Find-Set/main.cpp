#include "UnionFindSet.hpp"

using namespace std;

// 547. ʡ�����������ǲ��鼯����Ŀ�е�Ӧ��
int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<int> ufs(n, -1);
    auto findroot = [&ufs](int index) {
        int root = index;
        while (ufs[root] >= 0)
        {
            root = ufs[root];
        }

		//��������·��ѹ��������;�Ľڵ㶼ֱ��ָ����ڵ�
        while (ufs[index] >= 0)
        {
			int next = index;//��¼�ڵ�
			index = ufs[index];//����������
			ufs[next] = root;//ָ����ڵ�
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

// 990. ��ʽ���̵Ŀ�������
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
	//����ǵ�ʽ���Ⱥϲ�
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
	//����ǲ���ʽ������Ƿ���ͬһ��������
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