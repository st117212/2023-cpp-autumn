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

    void readMatrix(int vertexes);
    void sourcesdrains();

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
    std::cin >> n;

    graph.readMatrix(n);
    graph.sourcesdrains();
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

void Graph::sourcesdrains()
{
    int* sources = new int[_vertexes];
    int* drains = new int[_vertexes];
    int sourcesCount = 0;
    int drainsCount = 0;

    for (int i = 0; i < _vertexes; ++i)
    {
        bool isSource = true;
        bool isDrain = true;

        for (int j = 0; j < _vertexes; ++j)
        {
            if (_matrixFromVertexes[j][i] != 0)
            {
                isSource = false;
            }

            if (_matrixFromVertexes[i][j] != 0)
            {
                isDrain = false;
            }
        }

        if (isSource)
        {
            sources[sourcesCount++] = i + 1;
        }

        if (isDrain)
        {
            drains[drainsCount++] = i + 1;
        }
    }

    std::cout << sourcesCount << " ";
    for (int i = 0; i < sourcesCount; ++i)
    {
        std::cout << sources[i] << " ";
    }
    std::cout << std::endl;

    std::cout << drainsCount << " ";
    for (int i = 0; i < drainsCount; ++i)
    {
        std::cout << drains[i] << " ";
    }
    std::cout << std::endl;

    delete[] sources;
    delete[] drains;
}