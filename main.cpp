#include <string>
#include <iostream>
#include "Quote.h"
#include <stack>
#include "AdjacencyList.h"
#include <chrono>

int main()
{
	AdjacencyList list;
	list.insertData();
	list.readEdges("graph.txt");
	int input;
	float sentimentVal;
	std::string category;

	std::cout << "Welcome to \"Quote Quest\"!" << std::endl;
	std::cout << "----------------------------------------------!" << std::endl;
	std::cout << "Please enter a number for your desired category:" << std::endl;
	std::cout << "1) Love" << std::endl;
	std::cout << "2) Life" << std::endl;
	std::cout << "3) Inspiration" << std::endl;
	std::cout << "4) Philosophy" << std::endl;
	std::cout << "5) Humor" << std::endl;
	std::cout << "6) God" << std::endl;
	std::cout << "7) Truth" << std::endl;
	std::cout << "8) Wisdom" << std::endl;
	std::cout << "9) Happiness" << std::endl;
	std::cout << "10) Hope" << std::endl;
	std::cout << "11) Hate" << std::endl;
	std::cin >> input;

	
	switch (input) {
		case 1:
			category = "love";
			break;
		case 2:
			category = "life";
			break;
		case 3:
			category = "inspiration";
			break;
		case 4:
			category = "philisophy";
			break;
		case 5:
			category = "humor";
			break;
		case 6:
			category = "god";
			break;
		case 7:
			category = "truth";
			break;
		case 8:
			category = "wisdom";
			break;
		case 9:
			category = "happiness";
			break;
		case 10:
			category = "hope";
			break;
		case 11:
			category = "hate";
			break;
	}
	std::cout << "Please enter a desired sentiment value (between -1 and 1):" << std::endl;
	std::cin >> sentimentVal;

	Quote* quote = list.generateQuote(sentimentVal, category);
	std::cout << quote->getQuote() << std::endl;
	std::stack<Quote*> temp;

	
	
	return 0;
}