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

    long ancestor(long descendant1, long descendant2);

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
    long a = 0;
    long b = 0;

    std::cin >> n;
    std::cin >> a;
    std::cin >> b;

    long res = graph.ancestor(a, b);
    std::cout << res << std::endl;

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

long Graph::ancestor(long descendant1, long descendant2)
{
    while (descendant1 != descendant2)
    {
        if (descendant1 > descendant2)
        {
            descendant1 /= 2;
        }
        else
        {
            descendant2 /= 2;
        }
    }
    return descendant1;
}