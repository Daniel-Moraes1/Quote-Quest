#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Quote.h"


class AdjacencyList
{
	private:
		std::map<Quote, std::vector<Quote>> list;

	public:
		void insertData();
};

void AdjacencyList::insertData()
{
	std::ifstream inFile("data.csv");
	std::string num;
	std::string quote;
	std::string author;
	std::string category;
	std::string sentimentVal;
	std::string length;

	if (inFile.is_open())
	{
		std::string line;
		getline(inFile, line);

		while (getline(inFile, line))
		{
			std::istringstream stream(line);
			getline(stream, num, ',');
			getline(stream, quote, ',');
			getline(stream, author, ',');
			getline(stream, category, ',');
			getline(stream, sentimentVal, ',');
			getline(stream, length, ',');
		}
	}
}

int main()
{
	AdjacencyList list;
	list.insertData();
	return 0;
}