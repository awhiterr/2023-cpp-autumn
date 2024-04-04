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
    void readMatrix(int vertexes);
    int CountEdges();
    void PrintEdges();
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

int CGraph::CountEdges()
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
                count++;
            }
        }
    }
    return count;
}

    void CGraph::readMatrix(int vertexes)
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

    void CGraph::PrintEdges()
    {
        for (int i = 0; i < _vertexes; ++i)
        {
            for (int j = 0; j < _vertexes; ++j)
            {
                if (_matrix[i][j] == 1)
                {
                    std::cout << i + 1 << " " << j + 1 << std::endl;
                }
            }
        }
    }

    CGraph::~CGraph()
    {
        disposeMatrix();
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

    int main(int argc, char* argv[])
    {
        int vertexes = 0;
        std::cin >> vertexes;

        CGraph graph(vertexes);

        graph.readMatrix(vertexes);

        std::cout << vertexes << " ";
        std::cout << graph.CountEdges() << std::endl;
        graph.PrintEdges();
        return EXIT_SUCCESS;
    }
  