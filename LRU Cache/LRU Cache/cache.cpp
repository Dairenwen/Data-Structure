#include<iostream>
#include<list>
#include<unordered_map>
#include<map>
using namespace std;
//LRU Cache 详解
//LRU 是 Least Recently Used（最近最少使用） 的缩写，是一种经典的缓存淘汰策略。
//其核心思想是：当缓存空间已满时，优先淘汰 “最近一段时间内最少被使用” 的缓存项，为新数据腾出空间。
//它广泛应用于操作系统、数据库、分布式缓存（如 Redis）等场景，核心目标是通过 “保留热门数据” 提升缓存命中率。

//LRU 的关键需求是 get 和 put 操作的时间复杂度均为 O(1)，单一数据结构无法满足，需组合两种结构：
//数据结构	作用													优势
//哈希表		快速定位缓存项（通过 key 查找 value）					查找、插入、删除的时间复杂度 O(1)
//双向链表	维护缓存项的 “使用顺序”（最近使用的在头部，最久未用的在尾部）	快速调整节点顺序、删除尾部节点 O(1)

//1. Put 操作（插入 / 更新缓存）
//场景 1：插入新 key（缓存未满）
//步骤 1：创建新节点（key, value）。
//步骤 2：将新节点插入 链表头部（标记为最近使用）。
//步骤 3：在哈希表中添加映射（key → 新节点）。
//场景 2：插入新 key（缓存已满）
//步骤 1：删除 链表尾部节点（最久未使用，即要淘汰的项）。
//步骤 2：同步删除哈希表中该尾部节点的 key 映射。
//步骤 3：执行 “场景 1” 的插入逻辑（新节点插头部 + 哈希表添加映射）。
//场景 3：更新已有 key（key 已在缓存中）
//步骤 1：通过哈希表找到对应节点，更新节点的 value。
//步骤 2：将该节点从原位置删除，重新插入 链表头部（标记为最近使用）。

//2. Get 操作（查询缓存）
//场景 1：key 存在于缓存中
//步骤 1：通过哈希表找到对应节点，返回节点的 value。
//步骤 2：将该节点从原位置删除，重新插入 链表头部（更新为最近使用）。
//场景 2：key 不存在于缓存中
//步骤 1：直接返回 null（或 “未命中” 标识）。

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
        //1.key不在缓存中
        if (!hash.count(key)) return -1;
        //2.key存在于缓存当中
        auto tmpptr = hash[key];
        int ret = tmpptr->second;
		ls.erase(tmpptr);//注意这里删除后迭代器失效，tmpptr不能再用
        auto update = ls.insert(ls.begin(), { key,ret });
        hash[key] = update;
        return ret;
    }

    void put(int key, int value) {
        //1.如果key存在，更新
        if (hash.count(key))
        {
            auto tmpptr = hash[key];
            ls.erase(tmpptr);
            auto update = ls.insert(ls.begin(), { key,value });
            hash[key] = update;
        }
		else if (ls.size() == _capacity)//2.如果key不存在，且缓存已满，删除最久未使用的
        {
            int num = ls.back().first;
            ls.pop_back();
            hash.erase(num);

            auto update = ls.insert(ls.begin(), { key,value });
            hash[key] = update;
        }
		else//3.如果key不存在，且缓存未满，直接插入
        {
            auto update = ls.insert(ls.begin(), { key,value });
            hash[key] = update;
        }
    }
};

