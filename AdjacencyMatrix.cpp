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
            Quote *q = new Quote(std::stof(sentimentVal), std::stoi(length), quote, category, author);
            order[index] = q;
            index++;
        }
    }
    // Create empty adjacency matrix
    std::cout<<order.size()<<std::endl;
    adjacency_list =  std::vector<std::set<int>> (order.size());
    std::cout<<adjacency_list.size()<<std::endl;
}

/*
Establish edge weights between vertices
Factors include:
    Differences in sentiment(abs(sentiment(1) - sentiment(2))
    Different categories?: +.25
    Length difference: (max(length1, length2) - min(length1, length2)) / (max(length1, length2) / reduction_factor = 10)
 */
void AdjacencyMatrix::generateEdges() {
    float similarity_factor = 0.001; // Only add quotes to adjacency list if their similarity is <= similarity_factor
    for (int i=0; i<1; i++) {
        // Just to check progress
        if(i % 1000 == 0) {
            std::cout<<i<<std::endl;
        }
        for(int j=0; j<order.size(); j++) {
            float similarity = order[i]->calculateSimilarity(order[j]);
            if (similarity <= similarity_factor && similarity != 0) {
                adjacency_list[i].insert(j);
            }
        }
    }

    for (auto it = adjacency_list[0].begin(); it != adjacency_list[0].end(); it++) {
        std::cout<<*it;
    }
}

std::stack<Quote*> AdjacencyMatrix::BFS(Quote* source, bool within_category) {
    std::stack<Quote*> stack;
    return stack;
}

std::stack<Quote*> AdjacencyMatrix::DFS(Quote* source, bool within_category) {
    // Implement DFS with stack
    std::set<Quote*> visited;
    std::stack<Quote*> stack;
    if (source != nullptr) {
        stack.push(source);
    }
    while(!stack.empty()) {

    }
    return stack;



}

AdjacencyMatrix::~AdjacencyMatrix() {
    // Delete all quote objects from the adjacency matrix
    for (auto it = order.begin(); it != order.end(); it++) {
        delete it->second;
    }
}

