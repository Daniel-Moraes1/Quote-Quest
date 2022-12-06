#include <map>
#include <vector>
#include <string>
#include <iostream>

#include "Quote.h"
#include "AdjacencyMatrix.h"

int main()
{
	AdjacencyMatrix matrix;
	matrix.insertData();
    matrix.generateEdges();

	return 0;
}