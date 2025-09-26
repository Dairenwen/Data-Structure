#pragma once
#include<iostream>
#include<vector>
#include<unordered_map>


class UnionFindSet
{
public:
	UnionFindSet(size_t n)
		:_ufs(n,-1)
	{ }

	//���鼯�д洢Ϊ������ʾ�ýڵ�Ϊ���ڵ㣬��ֵ�ľ���ֵ��ʾ�ü��ϵĴ�С
	//������ʾ�ýڵ�ĸ��ڵ��±�
	int FindRoot(int index)
	{
		while(_ufs[index] >= 0)
		{
			index = _ufs[index];
		}
		return index;
	}

	bool Union(int a, int b)
	{
		int indexA = FindRoot(a);
		int indexB = FindRoot(b);
		if (indexA == indexB)//˵���Ѿ���ͬһ��������
			return false;
		if (_ufs[indexA] > _ufs[indexB])//˵��A���ϸ���(ע��洢���Ǹ���������ֵΪ��С)
			std::swap(indexA, indexB);
		_ufs[indexA] += _ufs[indexB];//����A���ϵĴ�С
		_ufs[indexB] = indexA;
		return true;
	}

	

	size_t GetSize() const
	{
		int count = 0;
		for (const auto& e : _ufs)
		{
			if (e < 0) ++count;
		}
		return count;
	}
private:
	std::vector<int> _ufs;
};