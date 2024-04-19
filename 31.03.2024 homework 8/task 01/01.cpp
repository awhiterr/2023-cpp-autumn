
#include <iostream>

class CGraph
{
private:
    int _vertexes;
    int _edges;
    int** _matrix;

public:

    CGraph()
        : _vertexes(0), _edges(0), _matrix(nullptr)
    {}

    CGraph(int vertexes)
        : _vertexes(vertexes), _edges(0)
    {
        initMatrix();
    }


    void initMatrix()
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

    void ReadMatrix()
    {
        for (int i = 0; i < _vertexes; ++i)
        {
            for (int j = 0; j < _vertexes; ++j)
            {
                std::cin >> _matrix[i][j];
            }
        }
    }

    int CountEdges()
    {
        int count = 0;
        if (_matrix == nullptr)
        {
            if (_vertexes == 0)
            {
                std::cout << "Graph empty" << std::endl;
            }
        }
        for (int i = 0; i < _vertexes; ++i)
        {
            for (int j = 0; j < _vertexes; ++j)
            {
                if (_matrix[i][j] >= 1)
                {
                    ++count;
                }
            }
        }
        return count / 2;
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
};

int main(int argc, char* argv[])
{
    int vertexes = 0;
    std::cin >> vertexes;
    CGraph graph(vertexes);
    graph.ReadMatrix();
    std::cout << graph.CountEdges();

    return EXIT_SUCCESS;
}