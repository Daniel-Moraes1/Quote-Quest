#include <map>
#include <vector>
#include <string>
#include <iostream>

#include "Quote.h"
#include "AdjacencyList.h"

int main()
{
	AdjacencyList list;
	list.insertData();
	list.generateEdges();

	return 0;
}