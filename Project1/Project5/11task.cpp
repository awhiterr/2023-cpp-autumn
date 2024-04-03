#include<iostream>
class CGraph
{
private:
    int _vertexes;
    int** _matrix;
    int* _arraydeg;

    void initMatrix()
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
    void deleteMatrix()
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
public:
    CGraph()
        : _vertexes(0), _matrix(nullptr), _arraydeg(nullptr)
    {}
    CGraph(int vertexes) :
        _vertexes(vertexes), _matrix(nullptr), _arraydeg(nullptr)
    {
        initMatrix();
    }

    void countDegree(int vertexes)
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
        for (int f = 0; f < _vertexes; f++)
        {
            if (_arraydeg[f] != _arraydeg[0])
            {
                std::cout << "NO";
                return;
            }
        }
        std::cout << "YES";
    }

        void readMatrix(int vertexes)
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

        ~CGraph()
        {
            deleteMatrix();
            delete[] _arraydeg;
        }

    };

    int main(int argc[], char* argv)
    {
        int vertexes = 0;
        std::cin >> vertexes;
        CGraph Degree;
        Degree.readMatrix(vertexes);
        Degree.countDegree(vertexes);
        return EXIT_SUCCESS;
    }