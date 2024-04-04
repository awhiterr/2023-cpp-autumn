#include<iostream>

class CGraph
{
private:
	int _vertexes;
	int _edges;
	int** _matrix;
	int* _lights;
	int* _vertex_degree;
public:
	CGraph();
	CGraph(int vertexes, int edges);
	~CGraph();

	void createMatrix(int vertexes, int edges);
	void readMatrix(int vertexes);
	void disposeMatrix();
	void initMatrix();
	void init_vertexes();
	int* countDegrees();

	void print_countDegrees();

};
CGraph::CGraph()
	: _vertexes(0), _edges(0), _matrix(nullptr), _vertex_degree(nullptr), _lights (nullptr) {}

CGraph::CGraph(int vertexes, int edges) : _vertexes(vertexes), _edges(edges), _matrix(nullptr), _vertex_degree(nullptr), _lights(nullptr)
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

void CGraph::CGraph::init_vertexes()
{
	if (_vertexes == 0)
	{
		return;
	}
	_lights = new int [_vertexes];
	for (int i = 0; i < _vertexes; ++i)
	{
		_lights[i] = 0;
	}
}

void CGraph::createMatrix(int vertexes, int edges)
{
	_edges = edges;
	initMatrix();
	for (int i = 0; i < _edges; ++i)
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

void CGraph::print_countDegrees()
{
	for (int i = 0; i < _vertexes; ++i)
	{
		std::cout << countDegrees()[i] << " ";
	}
	std::cout << std::endl;
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
		delete[] _lights;
		delete[] _vertex_degree;
	}


int main(int argc, char* argv[])
{
	int vertexes = 0;
	int edges = 0;
	std::cin >> vertexes;
	CGraph graph(vertexes, edges);
	graph.createMatrix(vertexes, edges);
	graph.print_countDegrees();
	return EXIT_SUCCESS;
}

