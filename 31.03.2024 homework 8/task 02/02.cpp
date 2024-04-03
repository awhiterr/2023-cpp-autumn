#include<iostream>

class CGraph
{
private:
	int _vertexes;
	int _edges;
	int** _matrix;
	void initMatrix();
	int* _arraydeg;
public:
	CGraph();
	CGraph(int vertexes, int edges);
	~CGraph();

	void createMatrix(int vertexes, int edges);
	void CountDegree(int vertexes);
	void print_arraydeg();
	void readMatrix(int vertexes);
	void disposeMatrix();
};
CGraph::CGraph()
	: _vertexes(0), _edges(0), _matrix(nullptr) {}

CGraph::CGraph(int vertexes, int edges) : _vertexes(vertexes), _edges(edges), _matrix(nullptr), _arraydeg(nullptr)
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

void CGraph::createMatrix(int vertexes, int edges)
{
	_vertexes = vertexes;
	initMatrix();
	for (int i = 0; i < edges; ++i)
	{
		int n = 0;
		int m = 0;
		std::cin >> n;
		std::cin >> m;
		_matrix[n - 1][m - 1] = 1;
		_matrix[m - 1][n - 1] = 1;
	}
}

void CGraph::CountDegree(int vertexes)
{
	int a = 0;

	_arraydeg = new int[_vertexes] {0};
	for (int i = 0; i < _vertexes; i++)
	{
		int count = 0;
		for (int j = 0; j < _vertexes; j++)
		{
			if (_matrix[i][j] == 1)
			{
				++count;
			}

		}
		_arraydeg[i] = count;
	}
}

	void CGraph::print_arraydeg()
	{
		for (int i = 0; i < _vertexes; ++i)
		{
			std::cout << _arraydeg[i];
		}
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
	int edges = 0;
	std::cin >> vertexes;
	std::cin >> edges;
	CGraph graph(vertexes, edges);
	graph.createMatrix(vertexes, edges);
	return EXIT_SUCCESS;
}

