#include <fstream>
#include <sstream>
#include <stack>
#include <set>
#include <queue>
#include "AdjacencyList.h"

AdjacencyList::AdjacencyList() {
    similarity_factor = 0.02; // Decided through rigorous and math intensive testing
}

// Reads data from CSV file. We recommend reading from graph.txt, the outputted in this function, if available
void AdjacencyList::insertData()
{
    std::ifstream inFile("data.csv");
    std::string num;
    std::string quote;
    std::string author;
    std::string category;
    std::string sentimentVal;
    std::string length;
    int index = 0;

    if (inFile.is_open()) {
        std::string line;
        std::string temp;
        getline(inFile, line);

        while (getline(inFile, line)) {
            std::istringstream stream(line);
            getline(stream, num, ',');
            getline(stream, length, ',');
            getline(stream, sentimentVal, ',');
            getline(stream, temp);
            if (temp[0] == '"') {
                quote = temp.substr(1, std::stoi(length));
                temp = temp.substr(temp.find("\",") + 2);
            } else {
                quote = temp.substr(0, std::stoi(length));
                temp = temp.substr(temp.find(',') + 1);
            }

            if (temp[0] == '"') {
                author = temp.substr(1, temp.find("\",") - 1);
                temp = temp.substr(temp.find("\",") + 2);
            } else {
                author = temp.substr(0, temp.find(','));
                temp = temp.substr(temp.find(',') + 1);
            }

            if (temp[0] == '"') {
                category = temp.substr(1, temp.find(',') - 1);
            } else {
                category = temp.substr(0, temp.find(','));
            }
            // Create Quote objects and assign index in quotes map
            Quote *q = new Quote(std::stof(sentimentVal), std::stoi(length), quote, category, author, index);
            quotes[index] = q;
            index++;
        }
    }
    // Create empty Adjacency List
    adjacency_list = std::vector<std::unordered_set<int>> (quotes.size());
}


/*
Establish edge weights between vertices
Factors include:
    Differences in sentiment(abs(sentiment(1) - sentiment(2))
    Different categories?: +.25
    Length difference: (max(length1, length2) - min(length1, length2)) / (max(length1, length2) / reduction_factor = 10)
*/

// Only add quotes to adjacency list if their similarity is <= similarity_factor
void AdjacencyList::generateEdges() {
    for (int i=0; i<quotes.size(); i++) {
        for(int j=0; j<quotes.size(); j++) {
            float similarity = quotes[i]->calculateSimilarity(quotes[j]);
            if (similarity <= similarity_factor && similarity != 0) {
                adjacency_list[i].insert(j);
            }
        }
    }

    // stores graph in a text file
    std::ofstream outFile("graph.txt");
    for (int i=0; i<adjacency_list.size(); i++) {
        outFile<<std::endl;
        if (adjacency_list[i].size() == 0)
            outFile<<-1;
        else {
            for (auto it = adjacency_list[i].begin(); it != adjacency_list[i].end(); it++) {
                outFile<<*it<<" ";
            }
        }
    }
    outFile.close();
}

// reads in the graph text file and converts it back into a graph storable in our adjacency list
void AdjacencyList::readEdges(std::string in) {
    std::ifstream graph(in);
    if(graph.is_open()) {
        int index(0);
        std::string line;
        std::string connection;
        while (getline(graph, line)) {
            std::istringstream stream(line);
            while (getline(stream, connection, ' ')) {
                int destination = std::stoi(connection);
                if (destination == -1) {
                    continue;
                }
                adjacency_list[index].insert(std::stoi(connection));
            }
            index++;
        }
    }
    graph.close();
}

// BFS function that returns a queue of quotes found via BFS
std::queue<Quote*> AdjacencyList::BFS(Quote* source) {
    std::queue<Quote*> return_queue;
    std::queue<int> bfs_queue;
    std::unordered_set<int> visited;
    int source_index = source->getIndex();

    bfs_queue.push(source_index);
    visited.insert(source_index);
    while(!bfs_queue.empty()) {
        int cur = bfs_queue.front();
        bfs_queue.pop();
        for (auto it = adjacency_list[cur].begin(); it != adjacency_list[cur].end(); it++) {
            if (visited.count(*it) == 0) {
                bfs_queue.push(*it);
                return_queue.push(quotes[*it]);
                visited.insert(*it);
            }
        }
    }
    return return_queue;
}

// DFS function that returns a queue of quotes found via DFS
std::queue<Quote*> AdjacencyList::DFS(Quote* source) {
    std::unordered_set<int> visited;
    std::stack<int> dfs_stack;
    std::queue<Quote*> queue;
    int source_index = source->getIndex();
    
    dfs_stack.push(source_index);
    visited.insert(source_index);
    while(!dfs_stack.empty()) {
        int cur = dfs_stack.top();
        dfs_stack.pop();
        for(auto it = adjacency_list[cur].begin(); it != adjacency_list[cur].end(); it++)
        {
            if(visited.count(*it) == 0) {
                dfs_stack.push(*it);
                queue.push(quotes[*it]);
                visited.insert(*it);
            }
        }
    }
    return queue;
}

// generates a quote given a sentiment and category
Quote* AdjacencyList::generateQuote(float sentiment, std::string category, int length) {
    Quote tempQuote = Quote(sentiment, length, "", category, "", -1);
    float min = 5; // Arbitrary value greater than possible from dataset
    int min_index = 0;
    for (int i=0; i<quotes.size(); i++) {
        float val = tempQuote.calculateSimilarity(quotes[i]);
        if (quotes[i]->getCategory() == category && val < min) {
            min = val;
            min_index = i;
        }
    }
    return quotes[min_index];
}

AdjacencyList::~AdjacencyList() {
    // Delete all quote objects from the adjacency List
    for (auto it = quotes.begin(); it != quotes.end(); it++) {
        delete it->second;
    }
}