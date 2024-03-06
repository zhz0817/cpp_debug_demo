#include <bits/stdc++.h>
using namespace std;
#define ll long long
class UnionFind {
private:
  vector<int> parents;
  vector<int> sizes;

public:
  UnionFind(int n) : parents(n), sizes(n, 1) {
    iota(parents.begin(), parents.end(), 0);//每个位置的值是数组下标
  }
  int Find(int x) {
    if (parents[x] == x) {
      return x;
    }
    return parents[x] = Find(parents[x]);
  }
  void Union(int x, int y) {
    int rx = Find(x), ry = Find(y);
    if (rx != ry) {
      if (sizes[rx] > sizes[ry]) {
        parents[ry] = rx;
        sizes[rx] += sizes[ry];
      } else {
        parents[rx] = ry;
        sizes[ry] += sizes[rx];
      }
    }
  }
  int GetSize(int x) { return sizes[x]; }
};

class Solution {
public:
  long long countPairs(int n, vector<vector<int>> &edges) {
    UnionFind uf(n);
    for (const auto &edge : edges) {
      uf.Union(edge[0], edge[1]);
    }
    long long res = 0;
    for (int i = 0; i < n; i++) {
      res += n - uf.GetSize(uf.Find(i));
    }
    return res / 2;
  }
};

void getNums(string s) {
  string t = "";
  for (int i = 0; i < s.size(); i++) {
    char ch = s[i];
    if (ch == '[') {
      t += '{';
    } else if (ch == ']') {
      t += '}';
    } else {
      t += ch;
    }
  }
  cout << t << endl;
}
int main() {
  Solution s;
  vector<vector<int>> vector1{{0, 2}, {0, 5}, {2, 4}, {1, 6}, {5, 4}};
  s.countPairs(7, vector1);
  cout<<"hello world"<<endl;
  system("pause");//删除这一行控制台会瞬间消失，不要动这行代码
  return 0;
}
