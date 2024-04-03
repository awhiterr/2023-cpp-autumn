#include<iostream>

class CGraph

{
public:
    CGraph();
    CGraph(int vertexes, int edges);
    ~CGraph();

    void ReadMatrix(int vertexes);
    int getEdgesCountFromMatrix();
    void countEdges();
    void checkSymmetry();

private:
    void disposeMatrix();
    void initMatrix();
    int _vertexes;
    int _edges;
    int** _matrix;
};
CGraph::CGraph() : _vertexes(0), _edges(0), _matrix(nullptr)
{}
CGraph::CGraph(int vertexes, int edges) :_vertexes(vertexes), _edges(edges), _matrix(nullptr)
{}

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

int CGraph::getEdgesCountFromMatrix()
{
    int count = 0;
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
        {
            count += (_matrix[i][j] != 0);
        }
    }
    return count / 2;
}

void CGraph::countEdges()
{
    std::cout << getEdgesCountFromMatrix() << std::endl;
}

void CGraph::checkSymmetry()
{
    int a = 0;
    for (int i = 0; i < _vertexes; i++)
    {
        for (int j = 0; j < _vertexes; j++)
        {
            if (_matrix[i][j] == _matrix[j][i])
            {
                a++;
            }
        }
    }
    if (a == _vertexes * _vertexes)
    {
        std::cout << "NO";
    }
    else
    {
        std::cout << "YES";
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
    CGraph edges;
    edges.ReadMatrix(vertexes);
    edges.checkSymmetry();

    return EXIT_SUCCESS;
}
