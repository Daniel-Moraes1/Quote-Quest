#include <iomanip>
#include <fstream>
#include <sstream>
#include <stack>
#include <set>
#include <queue>

#include<iostream> // Delete me

#include "AdjacencyList.h"

AdjacencyList::AdjacencyList() {
    similarity_factor = 0.005;
}


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
    std::cout<<quotes.size();
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
        // Just to check progress
        if(i % 250 == 0) {
            std::cout<<i<<std::endl;
        }
        for(int j=0; j<quotes.size(); j++) {
            float similarity = quotes[i]->calculateSimilarity(quotes[j]);
            if (similarity <= similarity_factor && similarity != 0) {
                adjacency_list[i].insert(j);
            }
        }
    }

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

void AdjacencyList::readEdges(std::string in) {
    std::ifstream graph(in);
    if(graph.is_open()) {
        int index(0);
        std::string line;
        std::string connection;
        while (getline(graph, line)) {
            std::istringstream stream(line);
            getline(stream, connection, ' ');
            std::cout<<connection;
            adjacency_list[index].insert(std::stoi(connection));
        }
    }
}

std::stack<Quote*> AdjacencyList::BFS(Quote* source) {
    std::stack<Quote*> stack;
    std::queue<int> queue;
    int source_index = source->getIndex();
    queue.push(source_index);
    std::unordered_set<int> visited;
    visited.insert(source_index);
    while(!queue.empty()) {
        int cur = queue.front();
        queue.pop();
        for (auto it = adjacency_list[cur].begin(); it != adjacency_list[cur].end(); it++) {
            if (visited.count(*it) == 0) {
                queue.push(*it);
                stack.push(quotes[*it]);
                visited.insert(*it);
            }
        }
    }
    return stack;
}

std::stack<Quote*> AdjacencyList::DFS(Quote* source) {
    int source_index = source->getIndex();
    // Implement DFS with stack
    std::unordered_set<int> visited;
    std::stack<int> dfs_stack;
    std::stack<Quote*> return_stack;
    dfs_stack.push(source_index);
    while(!dfs_stack.empty()) {
        dfs_stack.pop();
    }
    return return_stack;
}

AdjacencyList::~AdjacencyList() {
    // Delete all quote objects from the adjacency List
    for (auto it = quotes.begin(); it != quotes.end(); it++) {
        delete it->second;
    }
}