#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
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
	std::ifstream inFile("test_data.csv");
	std::string num;
	std::string quote;
	std::string author;
	std::string category;
	std::string sentimentVal;
	std::string length;

	if (inFile.is_open())
	{
		std::string line;
		std::string temp;
		getline(inFile, line);

		while (getline(inFile, line))
		{
			std::istringstream stream(line);
			getline(stream, num, ',');
			getline(stream, length, ',');
			getline(stream, sentimentVal, ',');
			getline(stream, temp);
			if (temp[0] == '"')
			{
				quote = temp.substr(1, std::stoi(length));
				temp = temp.substr(temp.find("\",") + 2);
			}
			else
			{
				quote = temp.substr(0, std::stoi(length));
				temp = temp.substr(temp.find(',') + 1);
			}

			if (temp[0] == '"')
			{
				author = temp.substr(1, temp.find("\",") - 1);
				temp = temp.substr(temp.find("\",") + 2);
			}
			else
			{
				author = temp.substr(0, temp.find(','));
				temp = temp.substr(temp.find(',') + 1);
			}

			if (temp[0] == '"')
			{
				category = temp.substr(1, temp.length() - 2);
			}
			else
			{
				category = temp.substr(0, temp.find(','));
			}
			Quote q(std::stod(sentimentVal), std::stoi(length), quote, category, author);
		}
	}
}

int main()
{
	AdjacencyList list;
	list.insertData();
	return 0;
}