#include <iomanip>
#include <fstream>
#include <sstream>
#include <stack>
#include <set>
#include<iostream> // Delete me

#include "AdjacencyMatrix.h"


AdjacencyMatrix::AdjacencyMatrix() {}


void AdjacencyMatrix::insertData()
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
                category = temp.substr(1, temp.length() - 2);
            } else {
                category = temp.substr(0, temp.find(','));
            }

            // Create Quote objects and assign index in order map
            Quote *q = new Quote(std::stod(sentimentVal), std::stoi(length), quote, category, author);
            order[index] = q;
        }
    }
    // Create empty adjacency matrix
    adjacency_matrix =  std::vector<std::vector<float>> (order.size(), std::vector<float> (order.size(), 0));
}

// Establish edge weights between vertices as difference in sentiment values
void AdjacencyMatrix::generateEdges() {
    for (int i=0; i<adjacency_matrix.size(); i++) {
        for(int j=0; j<adjacency_matrix.size(); j++) {
            if (i!=j)
                adjacency_matrix[i][j] = order[j]->getSentimentVal() - order[i]->getSentimentVal(); // Maybe make this abs
            else
                adjacency_matrix[i][j] = -2; // Need a way to mark as null
        }
    }
    for (int i=0; i<100; i++) {
        std::cout<<adjacency_matrix[0][i]<<std::endl;
    }
}

void AdjacencyMatrix::BFS(Quote* source, bool within_category) {

}

void AdjacencyMatrix::DFS(Quote* source, bool within_category) {
    // Implement DFS with stack
    std::set<Quote*> visited;
    std::stack<Quote*> stack;
    if (source != nullptr) {
        stack.push(source);
    }
    while(!stack.empty()) {

    }



}

AdjacencyMatrix::~AdjacencyMatrix() {
    // Delete all quote objects from the adjacency matrix
    for (auto it = order.begin(); it != order.end(); it++) {
        delete it->second;
    }
}

