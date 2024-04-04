#include<iostream>

class CGraph
{
private:
	int _vertexes;
	int** _matrix;
	int* colour_vertexes;
	int* _vertex_degree;


public:
	CGraph();
	CGraph(int vertexes);
	~CGraph();

	void readMatrix(int vertexes);
	void disposeMatrix();
	void initMatrix();
	void init_vertexes();
	void readVertexes(int vertexes);
	int countRoads(int _vertexes);

};
CGraph::CGraph()
	: _vertexes(0), _matrix(nullptr), _vertex_degree(nullptr), colour_vertexes(nullptr) {}

CGraph::CGraph(int vertexes) : _vertexes(vertexes), _matrix(nullptr), _vertex_degree(nullptr), colour_vertexes(nullptr)
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
	colour_vertexes = new int[_vertexes];
	for (int i = 0; i < _vertexes; ++i)
	{
		colour_vertexes[i] = 0;
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



void CGraph::readVertexes(int vertexes)
{
	_vertexes = vertexes;
	init_vertexes();

	for (int i = 0; i < _vertexes; ++i)
	{
		std::cin >> colour_vertexes[i];
	}
}


int CGraph::countRoads(int _vertexes)
{
	int count = 0;
	for (int i = 1; i < _vertexes; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if ((_matrix[i][j] == 1) && (colour_vertexes[i] != colour_vertexes[j]))
			{
				count++;
			}
		}
	}
	return count;
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
	delete[] colour_vertexes;
}


int main(int argc, char* argv[])
{
	int vertexes = 0;
	std::cin >> vertexes;
	CGraph graph(vertexes);
	graph.readMatrix(vertexes);
	graph.readVertexes(vertexes);
	std::cout << graph.countRoads(vertexes);

	return EXIT_SUCCESS;
}
