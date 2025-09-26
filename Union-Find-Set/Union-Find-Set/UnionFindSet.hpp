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

	//并查集中存储为负数表示该节点为根节点，且值的绝对值表示该集合的大小
	//正数表示该节点的父节点下标
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
		if (indexA == indexB)//说明已经在同一个集合中
			return false;
		if (_ufs[indexA] > _ufs[indexB])//说明A集合更大(注意存储的是负数，绝对值为大小)
			std::swap(indexA, indexB);
		_ufs[indexA] += _ufs[indexB];//更新A集合的大小
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