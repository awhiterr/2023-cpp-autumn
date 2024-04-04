#include <iostream>

class CGraph
{
public:
    void ReadMatrix(int vertexes);
    void countDegree();
    CGraph();
    CGraph(int vertexes, int edges);
    ~CGraph();
private:
    void disposeMatrix();
    void initMatrix();
    int _vertexes;
    int** _matrix;
};

CGraph::CGraph() : _vertexes(0), _matrix(nullptr)
{}
CGraph::CGraph(int vertexes, int edges) :_vertexes(vertexes), _matrix(nullptr)
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
}

void CGraph::countDegree()
{
    for (int i = 0; i < _vertexes; i++)
    {
        int count = 0;
        for (int j = 0; j < _vertexes; j++)
        {
            if (_matrix[i][j] == 1)
            {
                count++;
            }
        }
        std::cout << count << " ";
    }
}
CGraph::~CGraph()
{
    disposeMatrix();
}

int main(int argc, char* argv[])
{
    int vertexes = 0;
    std::cin >> vertexes;
    CGraph degree;
    degree.ReadMatrix(vertexes);
    degree.countDegree();

    return EXIT_SUCCESS;
}