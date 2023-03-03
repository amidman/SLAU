#include<vector>

template<typename T>
class CSR {
    private:
        int row_num;
        int col_num;
        std::vector<T> values;
        std::vector<T> cols;
        std::vector<T> rows;
    public:
        T operator[](int i, int j) const {
            for (int k = rows[i]; k < rows[i+1]; ++k) {
                if (cols[k] == j) {
                    return values[k];
                }
            }
            return 0;
        }

        T operator*(std::vector<T> vec) const {
            std::vector<T> res(row_num);
            for (int i = 0; i < row_num; ++i) {
                for (int j = rows[i]; j < rows[i+1]; ++j) {
                    res[i] += values[j] * vec[j];
                }
            }
        }
};