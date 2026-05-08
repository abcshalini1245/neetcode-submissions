class CountSquares {
public:
    map<pair<int,int>, int> freq;

    CountSquares() {}

    // Add a point
    void add(vector<int> point) {
        freq[{point[0], point[1]}]++;
    }

    // Count squares with given point as one corner
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int ans = 0;

        for (auto &p : freq) {
            int px = p.first.first;
            int py = p.first.second;

            // Same horizontal line
            if (py == y && px != x) {
                int side = abs(px - x);

                // Upper square
                ans += p.second *
                       freq[{x, y + side}] *
                       freq[{px, y + side}];

                // Lower square
                ans += p.second *
                       freq[{x, y - side}] *
                       freq[{px, y - side}];
            }
        }
        return ans;
    }
};

