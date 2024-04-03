#include<iostream>
class CGraph
{
private:
    int _vertexes;
    int** _matrix;
    void initMatrix();
    void deleteMatrix();
public:
    CGraph()
        : _vertexes(0), _matrix(nullptr)
    {}
    CGraph(int vertexes) :
        _vertexes(vertexes)
    {
        initMatrix();
    }

    void initMatrix()
    {
        if (_vertexes = 0)
        {
            return;
        }
        _matrix = new int* [_vertexes];
        for (int i = 0; i < _vertexes; ++i)
        {
            _matrix[i] = new int[_vertexes] {0};
        }
    }
    void readMatrix()
    {
        for (int i = 0; i < _vertexes; ++i)
        {
            for (int j = 0; j < _vertexes; ++j)
            {
                std::cin >> _matrix[i][j];
            }
        }
    }

    void deleteMatrix()
    {
        if (_matrix != nullptr)
        {
            for (int i = 0; i < _vertexes; ++i)
            {
                delete[] _matrix[i];
            }
            delete[] _matrix;
            _matrix = nullptr;
        }
    }

    void graph
};

int main(int argc[], char* argv)
{
    int vertexes = 0;
    std::cin >> vertexes;
    CGraph Degree;
    Degree.readMatrix();
    return EXIT_SUCCESS;
}