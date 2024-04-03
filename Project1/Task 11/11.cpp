#include <iostream>
#include<fstream>

class CGraph
{
public:
    void ReadMatrix(int vertexes, std::ifstream& stream);
    void countStepen();

private:
    void disposeMatrix();
    void initMatrix();
    int _vertexes;
    int** _matrix;
};

void CGraph::ReadMatrix(int vertexes, std::ifstream& in)
{
    _vertexes = vertexes;
    initMatrix();
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
        {
            in >> _matrix[i][j];
        }
    }
}

void CGraph::disposeMatrix()
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

void CGraph::initMatrix()
{
    if (_vertexes == 0)
    {
        return;
    }
    _matrix = new int* [_vertexes];
    for (int i = 0; i < _vertexes; ++i)
    {
        _matrix[i] = new int[_vertexes] { 0 };
    }
}

void CGraph::countStepen()
{
    int k = 0;
    int a = 0;
    int b = 0;
    for (int i = 0; i < 5; i++)
    {
        k = 0;
        for (int j = 0; j < 5; j++)
        {
            if (_matrix[i][j] == 1)
            {
                k++;
            }
        }

        if (a == k)
        {
            b++;
        }
        a = k;
    }
    if (b == 5)
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }
}

int main(int argc, char* argv[])
{
    std::ifstream in("task11.txt");
    CGraph degree;
    degree.ReadMatrix(5, in);
    degree.countStepen();

    return EXIT_SUCCESS;
}