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

    void readEdges(int edges, bool haveweight = false);
    int getVertexesCountFromEdges();
    void initMatrixFromEdges();
    int completeGraph();

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
    Graph graph;

    int n = 0;
    int m = 0;
    std::cin >> n >> m;

    graph.readEdges(m);
    graph.initMatrixFromEdges();

    if (graph.completeGraph() == 1)
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }

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

void Graph::readEdges(int edges, bool haveweight)
{
    _edges = edges;
    initEdges();
    for (int i = 0; i < _edges; ++i)
    {
        std::cin >> _edge[i].from >> _edge[i].to;
        if (haveweight)
        {
            std::cin >> _edge[i].weight;
        }
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

void Graph::initMatrixFromEdges()
{
    disposeMatrix();
    _vertexes = getVertexesCountFromEdges() - 1;
    initMatrix();

    if (_matrixFromVertexes == nullptr)
    {
        _matrixFromVertexes = new int* [_vertexes];
        for (int i = 0; i < _vertexes; ++i)
        {
            _matrixFromVertexes[i] = new int[_vertexes]();
        }
    }
}

int Graph::completeGraph()
{
    int completeEdges = (_vertexes * (_vertexes - 1)) / 2;
    int actualEdges = 0;

    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
        {
            if (i != j && _matrixFromVertexes[i][j] > 0)
            {
                ++actualEdges;
            }
        }
    }
    return actualEdges == completeEdges;
}