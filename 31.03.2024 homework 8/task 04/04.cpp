#include <iostream>

class CGraph
{
public:
    void ReadMatrix(int vertexes);
    void countDegree();
    CGraph();
    CGraph(int vertexes, int edges);
    ~CGraph();
    int Path(int a, int b, int c);
    int Muller();

private:
    void disposeMatrix();
    void initMatrix();
    int _vertexes;
    int** _matrix;
};

CGraph::CGraph() : _vertexes(0), _matrix(nullptr)
{}
CGraph::CGraph(int vertexes, int matrix) :_vertexes(vertexes), _matrix(nullptr)
{}

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

void CGraph::ReadMatrix(int vertexes)
{
    _vertexes = vertexes;
    initMatrix();
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
        {
            std::cin >> _matrix[i][j];
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
};

int CGraph::Path(int a, int b, int c)
{
    return _matrix[a][b] + _matrix[b][c] + _matrix[c][a];
};

int CGraph::Muller()
{
    int minDistance = Path(0, 1, 2);
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = i + 1; j < _vertexes; ++j)
        {
            for (int k = j + 1; k < _vertexes; ++k)
            {
                if (Path(i, j, k) <= minDistance)
                {
                    minDistance = Path(i, j, k);
                }
            }
        }
    }
    return minDistance;
};
CGraph::~CGraph()
{
    disposeMatrix();
}

int main(int argc, char* argv[])
{
    int vertexes = 0;
    std::cin >> vertexes;
    CGraph graph;
    graph.ReadMatrix(vertexes);
    std::cout << graph.Muller();

    return EXIT_SUCCESS;
}