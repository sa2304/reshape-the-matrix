#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

using Matrix = vector<vector<int>>;

class Solution {
 public:
  Matrix matrixReshape(Matrix &mat, int r, int c) {
    // FIXME
    return {};
  }
};

bool equals(const Matrix &lhs, const Matrix &rhs) {
  if (lhs.size() != rhs.size()) {
    return false;
  }
  for (int row = 0; row < lhs.size(); ++row) {
    const auto &left_row = lhs[row];
    const auto &right_row = rhs[row];
    if (left_row.size() != right_row.size()) {
      return false;
    }
    for (int col = 0; col < left_row.size(); ++col) {
      if (left_row[col] != right_row[col]) {
        return false;
      }
    }
  }

  return true;
}

void TestMatrixReshape() {
  Solution s;
  {
    Matrix matrix{{1, 2}, {3, 4}};
    Matrix reshaped{{1, 2, 3, 4}};
    assert(equals(reshaped, s.matrixReshape(matrix, 1, 4)));
  }
  {
    Matrix matrix{{1, 2}, {3, 4}};
    Matrix reshaped{{1, 2}, {3, 4}};
    assert(equals(reshaped, s.matrixReshape(matrix, 2, 4)));
  }
}

int main() {
  TestMatrixReshape();
  std::cout << "Ok!" << std::endl;
  return 0;
}
