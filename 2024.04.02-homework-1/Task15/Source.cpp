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
    bool isTournament(int n, int m);

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
    int n, m;
    std::cin >> n >> m;

    Graph graph;
    graph.readEdges(m);

    if (graph.isTournament(n, m))
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

bool Graph::isTournament(int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i != j)
            {
                bool found = false;
                for (int k = 0; k < m; ++k)
                {
                    if (_edge[k].from == i + 1 && _edge[k].to == j + 1)
                    {
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    bool foundReverse = false;
                    for (int k = 0; k < m; ++k)
                    {
                        if (_edge[k].from == j + 1 && _edge[k].to == i + 1)
                        {
                            foundReverse = true;
                            break;
                        }
                    }

                    if (!foundReverse)
                    {
                        return false;
                    }
                }
            }
        }
    }

    if (m != n * (n - 1) / 2)
    {
        return false;
    }

    return true;
}
