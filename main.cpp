#include "detonatedBombs.cpp"
#include <gtest/gtest.h>
#include <vector>
#include <fstream>

std::vector<std::vector<int>> readBombsFromFile(const std::string& filename) {
    std::vector<std::vector<int>> bombs;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "file is not open: " << filename << std::endl;
        return bombs;
    }

    int rows, cols;
    file >> rows >> cols;

    for (int i = 0; i < rows; ++i) {
        std::vector<int> row;
        for (int j = 0; j < cols; ++j) {
            int value;
            file >> value;
            row.push_back(value);
        }
        bombs.push_back(row);
    }

    file.close();
    return bombs;
}

TEST(MaxBombs, DetonatedTest) {
    std::vector<std::vector<int>> bombs1 = { {2, 1, 3}, {6, 1, 4} };
    ASSERT_EQ(2, maxDetBombs(bombs1));

    std::vector<std::vector<int>> bombs2 = { {1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4} };
    ASSERT_EQ(5, maxDetBombs(bombs2));

    std::vector<std::vector<int>> bombs3 = { {1, 1, 5}, {10, 10, 5} };
    ASSERT_EQ(1, maxDetBombs(bombs3));

    std::string absolutePath = "C:/Users/Dinara/MSU-practice/booombs/bombsFromFile.txt";
    std::vector<std::vector<int>> bombsFromFile = readBombsFromFile(absolutePath);
    ASSERT_EQ(3, maxDetBombs(bombsFromFile));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
