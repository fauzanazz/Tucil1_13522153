#include <iostream>
#include <fstream>
using namespace std;

class Matrix {
    private:
        int rows;
        int cols;
        int **data;



    public:
        // Constructor
        // Getter and Setter

        /// @brief Get Data from Matrix
        /// @param r row index
        /// @param c column index
        /// @return Data that the matrix has
        int GetMatrixData(int r, int c){
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
        void SetMatrixData(int **setData){
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    SetMatrixData(i, j, setData[i][j]);
                }
            }
        }


        /// @brief Matrix Constructor
        /// @param r sum row
        /// @param c sum column
        /// @param GenerateRandom boolean to generate random matrix
        /// @param setData matrix that will be set to the matrix (if GenerateRandom is false)
        Matrix(int r, int c, bool GenerateRandom = true, int **setData = NULL) {
            rows = r;
            cols = c;
        
            data = new int*[rows];
            for (int i = 0; i < rows; i++) {
                data[i] = new int[cols];
                if (GenerateRandom) {
                    for (int j = 0; j < cols; j++) {
                        data[i][j] = rand() % 16;
                    }
                } else if (setData != NULL) {
                    for (int j = 0; j < cols; j++) {
                        data[i][j] = setData[i][j];
                    }
                }
            }
        }
};

class FileManager {
    private:
        string temporary;
        string filename;
        fstream file;
    public:
        void WriteFile(string filename, string content) {
            file.open(filename, ios::out);
            file << content;
            file.close();
        }

        string ReadFile(string filename) {
            file.open(filename, ios::in);
            while (getline(file, temporary)) {
                cout << temporary << endl;
            }
            file.close();
            return temporary;
        }
};


int main() {
    cout << "Hello, World!" << endl;
    return 0;
}