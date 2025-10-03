#include<iostream>
#include<list>
#include<unordered_map>
#include<map>
using namespace std;
//LRU Cache ���
//LRU �� Least Recently Used���������ʹ�ã� ����д����һ�־���Ļ�����̭���ԡ�
//�����˼���ǣ�������ռ�����ʱ��������̭ �����һ��ʱ�������ٱ�ʹ�á� �Ļ����Ϊ�������ڳ��ռ䡣
//���㷺Ӧ���ڲ���ϵͳ�����ݿ⡢�ֲ�ʽ���棨�� Redis���ȳ���������Ŀ����ͨ�� �������������ݡ� �������������ʡ�

//LRU �Ĺؼ������� get �� put ������ʱ�临�ӶȾ�Ϊ O(1)����һ���ݽṹ�޷����㣬��������ֽṹ��
//���ݽṹ	����													����
//��ϣ��		���ٶ�λ�����ͨ�� key ���� value��					���ҡ����롢ɾ����ʱ�临�Ӷ� O(1)
//˫������	ά��������� ��ʹ��˳�򡱣����ʹ�õ���ͷ�������δ�õ���β����	���ٵ����ڵ�˳��ɾ��β���ڵ� O(1)

//1. Put ���������� / ���»��棩
//���� 1�������� key������δ����
//���� 1�������½ڵ㣨key, value����
//���� 2�����½ڵ���� ����ͷ�������Ϊ���ʹ�ã���
//���� 3���ڹ�ϣ�������ӳ�䣨key �� �½ڵ㣩��
//���� 2�������� key������������
//���� 1��ɾ�� ����β���ڵ㣨���δʹ�ã���Ҫ��̭�����
//���� 2��ͬ��ɾ����ϣ���и�β���ڵ�� key ӳ�䡣
//���� 3��ִ�� ������ 1�� �Ĳ����߼����½ڵ��ͷ�� + ��ϣ�����ӳ�䣩��
//���� 3���������� key��key ���ڻ����У�
//���� 1��ͨ����ϣ���ҵ���Ӧ�ڵ㣬���½ڵ�� value��
//���� 2�����ýڵ��ԭλ��ɾ�������²��� ����ͷ�������Ϊ���ʹ�ã���

//2. Get ��������ѯ���棩
//���� 1��key �����ڻ�����
//���� 1��ͨ����ϣ���ҵ���Ӧ�ڵ㣬���ؽڵ�� value��
//���� 2�����ýڵ��ԭλ��ɾ�������²��� ����ͷ��������Ϊ���ʹ�ã���
//���� 2��key �������ڻ�����
//���� 1��ֱ�ӷ��� null���� ��δ���С� ��ʶ����

class LRUCache {
    typedef list<pair<int, int>>::iterator lsit;
private:
    unordered_map<int, lsit> hash;
    list<pair<int, int>> ls;
    int _capacity;
public:
    LRUCache(int capacity)
        :_capacity(capacity)
    {
    }

    int get(int key) {
        //1.key���ڻ�����
        if (!hash.count(key)) return -1;
        //2.key�����ڻ��浱��
        auto tmpptr = hash[key];
        int ret = tmpptr->second;
		ls.erase(tmpptr);//ע������ɾ���������ʧЧ��tmpptr��������
        auto update = ls.insert(ls.begin(), { key,ret });
        hash[key] = update;
        return ret;
    }

    void put(int key, int value) {
        //1.���key���ڣ�����
        if (hash.count(key))
        {
            auto tmpptr = hash[key];
            ls.erase(tmpptr);
            auto update = ls.insert(ls.begin(), { key,value });
            hash[key] = update;
        }
		else if (ls.size() == _capacity)//2.���key�����ڣ��һ���������ɾ�����δʹ�õ�
        {
            int num = ls.back().first;
            ls.pop_back();
            hash.erase(num);

            auto update = ls.insert(ls.begin(), { key,value });
            hash[key] = update;
        }
		else//3.���key�����ڣ��һ���δ����ֱ�Ӳ���
        {
            auto update = ls.insert(ls.begin(), { key,value });
            hash[key] = update;
        }
    }
};

