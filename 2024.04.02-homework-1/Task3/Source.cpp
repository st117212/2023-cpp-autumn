#include<iostream>

struct SEdge
{
    int from;
    int to;
    int weight;

    SEdge(int from = 0, int to = 0, int weight = 1) : from(from), to(to), weight(weight)
    {
    }

    SEdge(const SEdge& copy) : from(copy.from), to(copy.to), weight(copy.weight)
    {
    }

    ~SEdge()
    {
    }

    void set(int from, int to, int weight)
    {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }

    friend std::ostream& operator<<(std::ostream& stream, const SEdge& edge);
};

class Graph
{
public:
    Graph()
    {
    }
    Graph(int edges, int vertexes) : _vertexes(vertexes), _edges(edges), _edge(nullptr), _rgbRoads(nullptr)
    {
    }

    ~Graph()
    {
    }

    void readMatrix(int vertexes);
    void initMatrixFromEdges();
    int getVertexesCountFromEdges();

    void readRGBRoads(int countOfRGBRoads);
    int countWrongRGBRoads();

private:

    void initMatrix();
    void disposeMatrix();
    void initEdges();
    void disposeEdges();
    void init();
    void dispose();

    void colorMatrix();
    void initRGBRoads();
    void disposeRGBRoads();

    int _countOfRGBRoads;
    int* _rgbRoads;
    int _vertexes;
    int** _matrixFromVertexes;
    int _edges;
    SEdge* _edge;
};

int main(int argc, char* argv[])
{
    Graph graph;
    int n = 0;
    int m = 0;

    std::cin >> n;
    graph.readMatrix(n);
    graph.readRGBRoads(n);

    std::cout << graph.countWrongRGBRoads() << std::endl;
    return EXIT_SUCCESS;
}

std::ostream& operator<<(std::ostream& stream, const SEdge& edge)
{
    stream << edge.from << " " << edge.to;
    if (edge.weight > 1)
    {
        stream << " " << edge.weight;
    }
    return stream;
}

void Graph::initEdges()
{
    disposeEdges();
    if (_edges == 0)
    {
        return;
    }
    _edge = new SEdge[_edges];
}

void Graph::disposeEdges()
{
    if (_edge != nullptr)
    {
        delete[] _edge;
        _edge = nullptr;
    }
}

void Graph::initMatrix()
{
    disposeMatrix();
    if (_vertexes == 0)
    {
        return;
    }
    _matrixFromVertexes = new int* [_vertexes];
    for (int i = 0; i < _vertexes; ++i)
    {
        _matrixFromVertexes[i] = new int[_vertexes] {0};
    }
}

void Graph::disposeMatrix()
{
    if (_matrixFromVertexes != nullptr)
    {
        for (int i = 0; i < _vertexes; ++i)
        {
            delete[] _matrixFromVertexes[i];
        }
        delete[] _matrixFromVertexes;
        _matrixFromVertexes = nullptr;
    }
}

void Graph::init()
{
    initMatrix();
    initEdges();
}

void Graph::dispose()
{
    disposeMatrix();
    disposeEdges();
}

void Graph::initMatrixFromEdges()
{
    disposeMatrix();
    _vertexes = getVertexesCountFromEdges();
    initMatrix();

    if (_matrixFromVertexes == nullptr)
    {
        _matrixFromVertexes = new int* [_vertexes];
        for (int i = 0; i < _vertexes; ++i)
        {
            _matrixFromVertexes[i] = new int[_vertexes]();
        }
    }

    for (int i = 0; i < _edges; ++i)
    {
        _matrixFromVertexes[_edge[i].from][_edge[i].to] = _edge[i].weight;
    }
}

int Graph::getVertexesCountFromEdges()
{
    int res = INT_MIN;
    for (int i = 0; i < _edges; ++i)
    {
        res = (res > _edge[i].from) ? ((res > _edge[i].to) ? res : _edge[i].to)
            : ((_edge[i].from > _edge[i].to) ? _edge[i].from : _edge[i].to);
    }
    return res + 1;
}

void Graph::readMatrix(int vertexes)
{
    _vertexes = vertexes;
    initMatrix();
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
        {
            std::cin >> _matrixFromVertexes[i][j];
        }
    }
}

void Graph::initRGBRoads()
{
    disposeRGBRoads();
    _rgbRoads = new int[_countOfRGBRoads];
}

void Graph::disposeRGBRoads()
{
    if (_rgbRoads != nullptr)
    {
        delete[] _rgbRoads;
        _rgbRoads = nullptr;
    }
}

void Graph::readRGBRoads(int countOfRGBRoads)
{
    _countOfRGBRoads = countOfRGBRoads;
    initRGBRoads();
    for (int i = 0; i < _countOfRGBRoads; ++i)
    {
        std::cin >> _rgbRoads[i];
    }
}

void Graph::colorMatrix()
{
    for (int i = 0, k = 0; i < _countOfRGBRoads; ++i, ++k)
    {
        for (int j = 0; j < _countOfRGBRoads; ++j)
        {
            _matrixFromVertexes[j][i] = _rgbRoads[k] * _matrixFromVertexes[j][i];
        }
    }
}

int Graph::countWrongRGBRoads()
{
    int count = 0;
    colorMatrix();
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
        {
            if (_matrixFromVertexes[i][j] != 0 && (_matrixFromVertexes[i][j] != _matrixFromVertexes[j][i]))
            {
                count++;
            }
        }
    }
    return (count / 2);
}