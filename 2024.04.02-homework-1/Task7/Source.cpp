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
    Graph(int edges, int vertexes) : _vertexes(vertexes), _edges(edges), _edge(nullptr)
    {
    }

    ~Graph()
    {
    }

    int getVertexesCountFromEdges();
    void readMatrix(int vertexes);
    int getEdgesCountFromMatrix();
    void initMatrixFromEdges();
    void initEdgesFromMatrixOfVertexes();
    void printEdges();

private:

    void initMatrix();
    void disposeMatrix();
    void initEdges();
    void disposeEdges();
    void init();
    void dispose();

    int _vertexes;
    int** _matrixFromVertexes;
    int _edges;
    SEdge* _edge;
};

int main(int argc, char* argv[])
{
    int n;
    std::cin >> n;

    Graph graph;
    graph.readMatrix(n);
    graph.initEdgesFromMatrixOfVertexes();
    int m = 0;
    m = graph.getEdgesCountFromMatrix();
    std::cout << n << " " << m << std::endl;
    graph.printEdges();
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

int Graph::getEdgesCountFromMatrix()
{
    int count = 0;
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
        {
            count += (_matrixFromVertexes[i][j] != 0);
        }
    }
    return count;
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

void Graph::initEdgesFromMatrixOfVertexes()
{
    disposeEdges();
    _edges = getEdgesCountFromMatrix();
    initEdges();
    for (int i = 0, k = 0; i < _vertexes && k < _edges; ++i)
    {
        for (int j = 0; j < _vertexes && k < _edges; ++j)
        {
            if (_matrixFromVertexes[i][j] != 0)
            {
                _edge[k++].set(i + 1, j + 1, _matrixFromVertexes[i][j]);
            }
        }
    }
}

void Graph::printEdges()
{
    if (_edge == nullptr)
    {
        if (_matrixFromVertexes == nullptr)
        {
            std::cout << "Graph empty" << std::endl;
            return;
        }
        initEdgesFromMatrixOfVertexes();
    }
    for (int i = 0; i < _edges; ++i)
    {
        std::cout << _edge[i] << std::endl;
    }
}