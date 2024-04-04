#include <iostream>

class CGraph
{
private:
    int _vertexes;
    int _edges;
    int** _matrix;

public:
    CGraph();
    CGraph(int vertexes, int edges);
    ~CGraph();

    void initMatrix();
    void disposeMatrix();
    void createMatrix(int vertexes);
    void printMatrix();
};

CGraph::CGraph()
    : _vertexes(0), _edges(0), _matrix(nullptr) {}

CGraph::CGraph(int vertexes, int edges = 0)
    : _vertexes(vertexes), _edges(edges), _matrix(nullptr)
{
    initMatrix();
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
        _matrix[i] = new int[_vertexes] {0};
    }
}
void CGraph::createMatrix(int edges)
{
    initMatrix();
    edges = _edges;
    for (int i = 0; i < _vertexes; ++i)
    {
        int vertex = 0;
        std::cin >> vertex;
        if (vertex != 0)
        {
            for (int j = 1; j <= vertex; ++j)
            {
                int n = 0;
                std::cin >> n;
                _matrix[n - 1][i] = 1;
            }

        }

    }

}


void CGraph::printMatrix()
{
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
            std::cout << _matrix[j][i] << " ";
        }
        std::cout << std::endl;
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
CGraph::~CGraph()
{
    disposeMatrix();
}
int main(int argc, char* argv[])
{
    int vertexes = 0;
    std::cin >> vertexes;
    CGraph graph(vertexes);
    graph.createMatrix(vertexes);
    std::cout << vertexes << std::endl;
    graph.printMatrix();
    
    return EXIT_SUCCESS;
}