class MyHashMap
{
    using kv = pair<int, int>;

    int buckets = 5000;
    vector<list<kv>> map;

public:
    MyHashMap() { map = vector<list<kv>>(buckets, list<kv>()); }

    void put(int key, int value)
    {
        auto &chain = map[key % buckets];
        for (auto &itr : chain)
        {
            if (itr.first == key)
            {
                itr.second = value;
                return;
            }
        }
        chain.push_back({key, value});
    }

    int get(int key)
    {
        auto &chain = map[key % buckets];
        for (auto &itr : chain)
            if (itr.first == key)
                return itr.second;
        return -1;
    }

    void remove(int key)
    {
        auto &chain = map[key % buckets];
        for (auto &itr : chain)
        {
            if (itr.first == key)
            {
                chain.remove(itr);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */