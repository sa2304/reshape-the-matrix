#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

using Matrix = vector<vector<int>>;

class Solution {
 public:
  vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
    const int ROWS = mat.size();
    const int COLUMNS = mat.front().size();
    if (ROWS == r && COLUMNS == c) { return mat; }
    if (ROWS * COLUMNS != r * c) { return mat; }

    vector<vector<int>> result(r, vector<int>(c));
    int read_row = 0, read_column = 0, write_row = 0, write_column = 0;
    while (write_row < r) {
      result[write_row][write_column] = mat[read_row][read_column];
      ++read_column;
      if (COLUMNS == read_column) {
        ++read_row;
        read_column = 0;
      }

      ++write_column;
      if (c == write_column) {
        ++write_row;
        write_column = 0;
      }
    }

    return result;
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
