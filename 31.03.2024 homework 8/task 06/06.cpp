#include <iostream>

class CGraph
{
private:
	int _vertexes;
	int _edges;
	int** _matrix;
	int* _vertex_degree;
public:
	CGraph();
	CGraph(int vertexes, int edges);
	~CGraph();
	void initMatrix();
	void createMatrix(int vertexes);
	int countVertexes();
	void disposeMatrix();
	int* countDegrees();

};

CGraph::CGraph()
		: _vertexes(0), _edges(0), _matrix(nullptr), _vertex_degree(nullptr) {}

CGraph::CGraph(int vertexes, int edges = 0)
		: _vertexes(vertexes), _edges(edges), _matrix(nullptr), _vertex_degree(nullptr)
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

void CGraph::createMatrix(int vertexes)
{
	initMatrix();
	for (int i = 0; i < _vertexes - 1; ++i)
	{
		int n = 0;
		int m = 0;
		std::cin >> n;
		std::cin >> m;
		_matrix[n - 1][m - 1] = 1;
		_matrix[m - 1][n - 1] = 1;
	}
}
int* CGraph::countDegrees()
{
	int* _vertex_degree = new int [_vertexes] {0};
	for (int i = 0; i < _vertexes; ++i)
	{
		int count = 0;
		for (int j = 0; j < _vertexes; ++j)
		{
			if (_matrix[i][j] == 1)
			{
				count++;
			}
		}
		_vertex_degree[i] = count;
	}
	return _vertex_degree;
}

	int CGraph::countVertexes()
	{
		int count_vertexes = 0;
		for (int i = 0; i < _vertexes; ++i)
		{
			if (countDegrees()[i] > 1)
			{
				count_vertexes++;
			}
		}
		return count_vertexes;
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
		delete[] _vertex_degree;
	}

	int main(int argc, char* argv[])
	{
		int vertexes = 0;
		std::cin >> vertexes;

		CGraph graph(vertexes);
		graph.createMatrix(vertexes);
		std::cout << graph.countVertexes();

		return EXIT_SUCCESS;
	}