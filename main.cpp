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
	std::cout <<  "Your quote is: " << "\"" << quote->getQuote() << "\"" << std::endl;
	std::cout << "by: " << quote->getAuthor() << std::endl;

	std::cout << "Please enter preferred method of quote generation (enter 1 or 2)" << std::endl;
	std::cout << "1) BFS" << std::endl;
	std::cout << "2) DFS" << std::endl;
	std::cin >> input;

	std::stack<Quote*> stack;
	if (input == 1)
	{
		auto start = std::chrono::high_resolution_clock::now();
		stack = list.BFS(quote);
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		std::cout << "The time it took for a BFS to complete was " << duration.count() << " microseconds" << std::endl;
		quote = stack.top();
		std::cout << "Your quote is: " << "\"" << quote->getQuote() << "\"" << std::endl;
		std::cout << "by: " << quote->getAuthor() << std::endl;
	}
	if (input == 2)
	{
		auto start = std::chrono::high_resolution_clock::now();
		stack = list.DFS(quote);
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		std::cout << "The time it took for a DFS to complete was " << duration.count() << " microseconds" << std::endl;
		quote = stack.top();
		std::cout << "Your quote is: " << "\"" << quote->getQuote() << "\"" << std::endl;
		std::cout << "by: " << quote->getAuthor() << std::endl;
	}
	
	
	return 0;
}