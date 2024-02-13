#include "gamestart.h"
#include "ui_gamestart.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <utility>
#include <random>
#include <chrono>
#include <cstring>
#include <cerrno>
#include <algorithm>


using namespace std;

GameStart::GameStart(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GameStart)
{
    ui->setupUi(this);
}

GameStart::~GameStart()
{
    delete ui;
}



using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    vector<vector<int>> data;

public:
    [[nodiscard]] int getRows() const {
        return rows;
    }

    [[nodiscard]] int getCols() const {
        return cols;
    }

    [[nodiscard]] int getMatrixData(int r, int c) const {
        return data[r][c];
    }

    [[nodiscard]] vector<vector<int>>& getData() {
        return data;
    }

    /// @brief Get Data from Matrix
    /// @param r row index
    /// @param c column index
    /// @return Data that the matrix has
    [[nodiscard]] int GetMatrixData(int r, int c) const {
        return data[r][c];
    }

    /// @brief Set Data to Matrix
    /// @param r row index
    /// @param c col index
    /// @param value the value that will be set to the matrix
    void SetMatrixData(int r, int c, int value){
        data[r][c] = value;
    }

    /// @brief Set Data to Matrix, the inputted matrix will be set to the matrix size if the setter is larger
    /// @param setData Matrix that will be set to the matrix
    void SetMatrixData(const vector<vector<int>>& setData){
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                SetMatrixData(i, j, setData[i][j]);
            }
        }
    }


    /// @brief Matrix Constructor
    /// @param r sum row
    /// @param c sum column
    /// @param GenerateRandom boolean to generate random matrix with a set of value
    /// @param setData matrix that will be set to the matrix (if GenerateRandom is false)
    Matrix(int r, int c, bool GenerateRandom = true, const vector<vector<int>>& setData = {}) {
        rows = r;
        cols = c;
        data.resize(rows, vector<int>(cols));

        const vector<int> allowedDigits = {0x1C, 0x55, 0x7A, 0xBD, 0xE9, 0xFF};

        if (GenerateRandom) {
            const auto seed = chrono::system_clock::now().time_since_epoch().count();
            default_random_engine generator(seed);
            uniform_int_distribution<vector<int>::size_type> distribution(0, allowedDigits.size() - 1);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    data[i][j] = allowedDigits[distribution(generator)];
                }
            }
        } else if (!setData.empty()) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    data[i][j] = setData[i][j];
                }
            }
        }
    }
};

/// @brief Sequence class
class Sequence {
    vector<int> data;
public:
    Sequence() = default;

    /// @brief Sequence Constructor
    /// @param len length of the sequence
    /// @param GenerateRandom boolean to generate random sequence with a set of value
    /// @param setData sequence that will be set to the sequence (if GenerateRandom is false)
    explicit Sequence(int len, const bool GenerateRandom = true, const vector<int>& setData = {}) {
        data.resize(len);

        if (GenerateRandom) {
            const auto seed = chrono::system_clock::now().time_since_epoch().count();
            default_random_engine generator(seed);
            uniform_int_distribution<vector<int>::size_type> distribution(0, 255);
            for (int i = 0; i < len; i++) {
                data[i] = distribution(generator);
            }
        } else if (!setData.empty()) {
            for (int i = 0; i < len; i++) {
                data[i] = setData[i];
            }
        }
    }

    /// @brief Set Data to Sequence
    /// @param index index of the sequence
    /// @param value the value that will be set to the sequence
    void SetData(int index, int value){
        data[index] = value;
    }

    /// @brief Set Data to Sequence, the inputted sequence will be set to the sequence size if the setter is larger
    /// @param setData sequence that will be set to the sequence
    void SetData(const vector<int>& setData){
        for (int i = 0; i < data.size(); i++) {
            SetData(i, setData[i]);
        }
    }

    [[nodiscard]] int getData(int index) const{
        return data[index];
    }

    [[nodiscard]] size_t getLength() const {
        return data.size();
    }

};

class Data {
private:
    int buffer_size{};
    int matrix_width, matrix_height;
    Matrix matrix;
    int number_of_sequences;
    vector<Sequence> sequences;
    int buffer;

public:

    void printSequences() const {
        for (int i = 0; i < number_of_sequences; i++) {
            cout << "Sequence " << i << ": ";
            for (int j = 0; j < sequences[i].getLength(); j++) {
                cout << hex << sequences[i].getData(j) << " ";
            }
            cout << endl;
        }
    }

    void printMatrix () const {
        for (int i = 0; i < matrix_height; i++) {
            for (int j = 0; j < matrix_width; j++) {
                cout << hex << matrix.GetMatrixData(i, j) << " ";
            }
            cout << endl;
        }
    }

    /// @brief Read data from file
    /// @param filename
    void readFromFile(const string& filename) {
        ifstream file(filename);

        if (!file) {
            cout << "Unable to open file: " << filename << endl;
            cout << "Error code: " << strerror(errno) << endl;
            return;
        }

        file >> buffer_size;

        file >> matrix_width >> matrix_height;
        matrix = Matrix(matrix_width, matrix_height);
        for (int i = 0; i < matrix_height; i++) {
            for (int j = 0; j < matrix_width; j++) {
                string hexValue;
                file >> hexValue;
                matrix.SetMatrixData(i, j, stoi(hexValue, nullptr, 16));
            }
        }

        file >> number_of_sequences;
        sequences.resize(number_of_sequences, Sequence());
        for (int i = 0; i < number_of_sequences; i++) {
            string hexValue;
            file >> hexValue;
            sequences[i].SetData(0, stoi(hexValue, nullptr, 16));
        }
    }

    Data() : buffer(10), matrix(10, 10) {
        matrix_width = 10;
        matrix_height = 10;
        matrix = Matrix(matrix_width, matrix_height);
        number_of_sequences = 5;
        for (int i = 0; i < number_of_sequences; i++) {
            sequences.emplace_back(5);
        }
    }

    ~Data() {
        while (!sequences.empty()) {
            sequences.pop_back();
        }
    }

    pair<vector<int>, vector<vector<int>>> solve() {
        return findMoves(matrix.getData(), {0, 0}, {{}, {}, {}}, vector<int>(1, 0), 1, buffer_size);
    }

    /// @brief update the score of the game in a row
    /// @param row the row that is being check
    /// @param built_sequences the built sequences
    /// @param sequences sequences that is being built
    /// @return the score and the updated sequences
    static pair < vector<int>, vector<vector<int>> > updateScore (vector<int> row, vector<vector<int>> built_sequences, vector<vector<int>> sequences) {
        vector<int> score(row.size(), 0);
        vector<vector<int>> updated_sequences(row.size(), vector<int>());

        // Copy the built sequences to the updated sequences
        for (int i = 0; i < row.size(); i++) {
            updated_sequences[i] = built_sequences[i];
        }

        // iterate through the row and column
        for (int i = 0; i < row.size(); i++) {
            for (int j = 0; j < built_sequences.size(); j++) {

                vector<int> target_sequence = sequences[j];

                // Check if the current sequence is still being built
                if (target_sequence.size() > built_sequences[j].size() && row[i] == target_sequence[built_sequences[j].size()]) {
                    updated_sequences[i].push_back(row[i]);

                    if (updated_sequences[i].size() < target_sequence.size()) {
                        score[i] += j + 1;
                    } else {
                        score[i] += (j + 1) * 9;
                    }
                } else {
                    // If the current sequence is not being built, clear the sequence
                    if (updated_sequences[i].size() < target_sequence.size()) {
                        updated_sequences[i].clear();
                    }
                }
            }
        }

        return make_pair(score, updated_sequences);
    }


    /// @brief find the moves that is possible to do in recursion
    /// @param game_matrix the matrix
    /// @param current_position the current position
    /// @param sequence_built sequence that is being buit
    /// @param max_game_score max game score
    /// @param depth the depth of recursion
    /// @param buffer_size the buffer size
    /// @return the max game score and the new positions
    pair<vector<int>, vector<vector<int>>> findMoves(vector<vector<int>> game_matrix, pair<int, int> current_position, vector<vector<int>> sequence_built, vector<int> max_game_score, int depth, int buffer_size) {
        vector<pair<int, int>> new_positions_map;
        int current_score = max_game_score[0];

        pair<int, int> next_move = {0, 0};

        // Where to move, row or column
        bool movementDecider = depth % 2 == 1;
        vector<int> game_row;

        // If the movement decider is true, then the game row is the current row
        // If the movement decider is false, then the game row is the current column
        if (movementDecider) {
            game_row = game_matrix[current_position.second];
        } else {
            for (auto & i : game_matrix) {
                game_row.push_back(i[current_position.first]);
            }
        }

        // Change vector<sequence> to vector<vector<int>>
        vector<vector<int>> sequences;
        for (auto & i : sequences) {
            vector<int> temp;
            for (auto & j : i) {
                temp.push_back(j);
            }
            sequences.push_back(temp);
        }

        // Find the score and the sequences
        pair<vector<int>, vector<vector<int>>> score_and_sequences = updateScore(game_row, std::move(sequence_built), sequences);

        // Get the maximum rewards
        int maxRewards = *max_element(score_and_sequences.first.begin(), score_and_sequences.first.end());

        // Get the indexes of the maximum rewards
        vector<int> yCords;
        vector<int> xCords;
        vector<int> maxScoreIndex = get_indexes(score_and_sequences.first, maxRewards);

        // If the movement decider is true, then the yCords is the current row
        // else the xCords is the current column
        if (movementDecider) {
            yCords = vector<int>(maxScoreIndex.size(), current_position.second);
            xCords = maxScoreIndex;
        } else {
            yCords = maxScoreIndex;
            xCords = vector<int>(maxScoreIndex.size(), current_position.first);
        }

        // Change the xCords and yCords to a pair of x and y
        vector<pair<int, int>> new_positions;
        for (int i = 0; i < xCords.size(); i++) {
            new_positions.emplace_back(xCords[i], yCords[i]);
        }

        // Remove the current position from the new positions
        auto it = find(new_positions.begin(), new_positions.end(), current_position);
        if (it != new_positions.end()) {
            new_positions.erase(it);
        }

        // If the depth is greater than the buffer size, return the max game score and the new positions
        if (depth >= buffer_size) {
            return make_pair(vector<int>(1, max_game_score[0] + maxRewards), new_positions.empty() ? vector<vector<int>>() : vector<vector<int>>(1, {new_positions[0].first, new_positions[0].second}));
        }

        // Iterate through the new positions
        for (auto& pos : new_positions) {
            vector<vector<int>> new_game_matrix = game_matrix;
            new_game_matrix[pos.second][pos.first] = 0;

            const vector<vector<int>>& new_sequence = sequence_built;
            auto [new_maxRewards, temp_positions_map] = findMoves(new_game_matrix, pos, new_sequence, vector<int>(1, maxRewards), depth + 1, buffer_size);

            // If the new max rewards + the current score is greater than the max game score, then the max game score is the new max rewards + the current score
            if (new_maxRewards[0] + current_score > max_game_score[0]) {
                max_game_score[0] = new_maxRewards[0] + current_score;
                next_move = pos;
                new_positions_map = convert_to_pairs(temp_positions_map);
            }
        }

        // If the next move is not empty, then the new positions map is the next move
        new_positions_map.push_back(next_move);
        return make_pair(vector<int>(1, max_game_score[0]), convert_to_vectors(new_positions_map));
    };

    /// @brief convert the sequence built to a vector of pair of int
    /// @param pairs
    /// @return vector of vector of int
    static vector<vector<int>> convert_to_vectors(const vector<pair<int, int>>& pairs) {
        vector<vector<int>> vecs;
        for (auto &p : pairs) {
            vecs.push_back({p.first, p.second});
        }
        return vecs;
    }

    /// @brief get indexes of the element in the vector
    /// @param vec the vector
    /// @param element element to find
    /// @return indexes of the element in the vector
    static vector<int> get_indexes(vector<int> vec, int element) {
        vector<int> indexes;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == element) {
                indexes.push_back(i);
            }
        }
        return indexes;
    }

    /// @brief Convert the sequence built to a vector of pair of int
    /// @param vec the vector of sequence built
    /// @return vector of pair of int
    static vector<pair<int, int>> convert_to_pairs(vector<vector<int>> vec) {
        vector<pair<int, int>> pairs;
        for (auto &v : vec) {
            pairs.emplace_back(v[0], v[1]);
        }
        return pairs;
    }


    /// @brief print all data that is stored in the class
    void printAll() const {
        cout<<"Buffer Size: "<<buffer_size<<endl;
        cout<<"Matrix Width: "<<matrix_width<<endl;
        cout<<"Matrix Height: "<<matrix_height<<endl;
        cout<<"Number of Sequence: "<<number_of_sequences<<endl;

        printMatrix();
        printSequences();
    }

};

