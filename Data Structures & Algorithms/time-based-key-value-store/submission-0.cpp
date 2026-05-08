class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end())
            return "";

        auto &v = mp[key];

        // scan backwards
        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i].first <= timestamp)
                return v[i].second;
        }
        return "";
    }
};

