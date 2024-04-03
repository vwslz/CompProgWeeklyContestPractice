#include <bits/stdc++.h>

bool valid(int gc[7][7], bool odd) {
  for (int r = 1; r < 6; r++) {
    for (int c = 1; c < 6; c++) {
      if (gc[r][c] && ((r + c) % 2 == odd)) {
        if (gc[r - 1][c - 1] && gc[r - 1][c + 1] && gc[r + 1][c - 1] &&
            gc[r + 1][c + 1]) {
          return false;
        }
      }
    }
  }
  return true;
}

bool check(int g[7][7], int flips_left, int idx,
           std::vector<std::pair<int, int>>& vec, int valid_val) {
  if (flips_left == 0) {
    return valid(g, valid_val);
  }
  if (idx >= vec.size()) {
    return false;
  }
  bool result = false;
  result |= check(g, flips_left, idx + 1, vec, valid_val);
  g[vec[idx].first][vec[idx].second] ^= 1;
  result |= check(g, flips_left - 1, idx + 1, vec, valid_val);
  g[vec[idx].first][vec[idx].second] ^= 1;
  return result;
}

int main() {
  std::vector<std::pair<int, int>> odd, even;
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      if ((i + j) % 2) {
        odd.emplace_back(i, j);
      } else {
        even.emplace_back(i, j);
      }
    }
  }

  int t;
  std::cin >> t;
  while (t--) {
    int g[7][7];
    char c;
    for (int i = 0; i < 7; ++i) {
      for (int j = 0; j < 7; ++j) {
        std::cin >> c;
        g[i][j] = (c == 'B');
      }
    }
    int res = 0;
    for (int i = 0; i <= 4; ++i) {
      if (check(g, i, 0, odd, 1)) {
        res += i;
        break;
      }
    }
    for (int i = 0; i <= 4; ++i) {
      if (check(g, i, 0, even, 0)) {
        res += i;
        break;
      }
    }
    std::cout << res << std::endl;
  }
  return 0;
}
