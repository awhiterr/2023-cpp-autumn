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
	int CountEdges();
	void createMatrix(int edges);
	int* countDegrees();
	void printAdjacency();
};

CGraph::CGraph()
	: _vertexes(0), _edges(0), _matrix(nullptr){}

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
			_matrix[i] = new int[_vertexes] { 0 };
		}
	}

	void CGraph::createMatrix(int edges)
	{
		edges = _edges;
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

int main(int argc, char* argv[])
{
	int vertexes = 0;
	std::cin >> vertexes;
	int edges = 0;
	std::cin >> edges;
	CGraph graph(vertexes, edges);
	graph.createMatrix(vertexes);


	return EXIT_SUCCESS;
}