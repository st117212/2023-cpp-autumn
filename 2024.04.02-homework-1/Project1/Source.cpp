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

class Edge
{
public:
    Edge() : _edges(0), _edge(nullptr)
    {
    }
    Edge(int edges) : _edges(edges), _edge(nullptr)
    {
    }

    ~Edge()
    {
        disposeEdges();
    }

protected:
    void initEdges();
    void disposeEdges();

    int _edges;
    SEdge* _edge;
};

class Vertex
{
public:
    Vertex() : _vertexes(0), _matrixFromVertexes(nullptr)
    {
    }
    Vertex(int vertexes) : _vertexes(vertexes), _matrixFromVertexes(nullptr)
    {
    }

    ~Vertex()
    {
        disposeMatrix();
    }

protected:
    void initMatrix();
    void disposeMatrix();

    int _vertexes;
    int** _matrixFromVertexes;
};

class Graph : public Edge, public Vertex
{
public:
    Graph()
    {
    }
    Graph(int edges, int vertexes) : Edge(edges), Vertex(vertexes)
    {
    }

    ~Graph()
    {
    }

    void createAdjacencyMatrix(int n);

private:
    void init();
    void dispose();
};

int main(int argc, char* argv[])
{
    Graph graph;

    int n = 0;
    std::cin >> n;

    graph.createAdjacencyMatrix(n);

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

void Edge::initEdges()
{
    disposeEdges();
    if (_edges == 0)
    {
        return;
    }
    _edge = new SEdge[_edges];
}

void Edge::disposeEdges()
{
    if (_edge != nullptr)
    {
        delete[] _edge;
        _edge = nullptr;
    }
}

void Vertex::initMatrix()
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

void Vertex::disposeMatrix()
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

void Graph::createAdjacencyMatrix(int n)
{
    int** adjMatrix = new int* [n];

    for (int i = 0; i < n; ++i)
    {
        adjMatrix[i] = new int[n]();
    }

    for (int i = 0; i < n; i++)
    {
        int numEdges;
        std::cin >> numEdges;

        for (int j = 0; j < numEdges; j++)
        {
            int connectedVertex;
            std::cin >> connectedVertex;

            adjMatrix[i][connectedVertex - 1] = 1;
        }
    }
}