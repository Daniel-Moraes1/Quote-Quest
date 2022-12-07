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
	std::cout << "loading quote quotient..." << std::endl;
	std::cout << std::endl;
	// reads in graph via text file to avoid having to insert into graph each time program is run
	list.readEdges("graph.txt");
	int input;
	float sentimentVal;
	std::string category;

	while (true)
	{
		// Creates user interface
		std::cout << "Welcome to \"Quote Quest\"!" << std::endl;
		std::cout << "----------------------------------------------" << std::endl;
		std::cout << "Please enter a number for your desired initial category:" << std::endl;
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
		std::cout << "Enter 0 to exit the program" << std::endl;
		std::cout << "----------------------------------------------" << std::endl;
		std::cin >> input;


		switch (input) {
		case 0:
			exit(0);
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
		std::cout << "----------------------------------------------" << std::endl;
		std::cout << "Please enter a desired sentiment value (between -1 and 1):" << std::endl;
		std::cout << "----------------------------------------------" << std::endl;
		std::cin >> sentimentVal;

		Quote* quote = list.generateQuote(sentimentVal, category);
		std::cout << "----------------------------------------------" << std::endl;
		std::cout << "Your quote is: " << "\"" << quote->getQuote() << "\"" << std::endl;
		std::cout << "Category: " << quote->getCategory() << std::endl;
		std::cout << "Sentiment Value: " << quote->getSentimentVal() << std::endl;
		std::cout << "Author: " << quote->getAuthor() << std::endl;
		std::cout << "----------------------------------------------" << std::endl;
		std::cout << std::endl;

		std::cout << "----------------------------------------------" << std::endl;
		std::cout << "Would you like to generate another quote? (enter 1 or 2)" << std::endl;
		std::cout << "1) Yes" << std::endl;
		std::cout << "2) No" << std::endl;
		std::cout << "----------------------------------------------" << std::endl;
		std::cin >> input;

		if (input == 1)
		{
			continue;
		}
		else
		{
			std::cout << "----------------------------------------------" << std::endl;
			std::cout << "Please enter preferred method of related quote generation or if you want to get another quote (enter 1 or 2)" << std::endl;
			std::cout << "1) BFS" << std::endl;
			std::cout << "2) DFS" << std::endl;
			std::cout << "----------------------------------------------" << std::endl;
			std::cin >> input;

			std::stack<Quote*> stack;
			if (input == 1)
			{
				// set start to the current time DFS starts to run
				auto start = std::chrono::high_resolution_clock::now();
				stack = list.BFS(quote);
				// sets stop to the current time DFS ends
				auto stop = std::chrono::high_resolution_clock::now();
				// calculates the duration of the DFS method
				auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
				std::cout << "----------------------------------------------" << std::endl;
				std::cout << "The time it took for a BFS to complete was " << duration.count() << " microseconds" << std::endl;
				std::cout << std::endl;
				std::cout << "----------------------------------------------" << std::endl;
				quote = stack.top();
				std::cout << "----------------------------------------------" << std::endl;
				std::cout << "Your quote is: " << "\"" << quote->getQuote() << "\"" << std::endl;
				std::cout << "Category: " << quote->getCategory() << std::endl;
				std::cout << "Sentiment Value: " << quote->getSentimentVal() << std::endl;
				std::cout << "Author: " << quote->getAuthor() << std::endl;
				std::cout << "----------------------------------------------" << std::endl;
				std::cout << std::endl;
				stack.pop();

				// while loop to run throughout the whole stack containing our quotes stored via BFS
				while (!stack.empty())
				{
					std::cout << "----------------------------------------------" << std::endl;
					std::cout << "Would you like to view the next quote or exit? (enter 1 or 2)" << std::endl;
					std::cout << "1) Yes" << std::endl;
					std::cout << "2) No" << std::endl;
					std::cout << "----------------------------------------------" << std::endl;
					std::cin >> input;

					if (input == 1)
					{
						quote = stack.top();
						std::cout << "----------------------------------------------" << std::endl;
						std::cout << "Your quote is: " << "\"" << quote->getQuote() << "\"" << std::endl;
						std::cout << "Category: " << quote->getCategory() << std::endl;
						std::cout << "Sentiment Value: " << quote->getSentimentVal() << std::endl;
						std::cout << "Author: " << quote->getAuthor() << std::endl;
						std::cout << "----------------------------------------------" << std::endl;
						std::cout << std::endl;
						stack.pop();
					}
					else if (input == 2)
					{
						break;;
					}
					else if (input == 3)
					{
						exit(0);
					}
				}
			}
			else if (input == 2)
			{
				// set start to the current time DFS starts to run
				auto start = std::chrono::high_resolution_clock::now();
				stack = list.DFS(quote);
				// sets stop to the current time DFS ends
				auto stop = std::chrono::high_resolution_clock::now();
				// calculates the duration of the DFS method
				auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
				std::cout << "----------------------------------------------" << std::endl;
				std::cout << "The time it took for a DFS to complete was " << duration.count() << " microseconds" << std::endl;
				std::cout << "----------------------------------------------" << std::endl;
				std::cout << std::endl;
				quote = stack.top();
				std::cout << "----------------------------------------------" << std::endl;
				std::cout << "Your quote is: " << "\"" << quote->getQuote() << "\"" << std::endl;
				std::cout << "Category: " << quote->getCategory() << std::endl;
				std::cout << "Sentiment Value: " << quote->getSentimentVal() << std::endl;
				std::cout << "Author: " << quote->getAuthor() << std::endl;
				std::cout << "----------------------------------------------" << std::endl;
				std::cout << std::endl;
				stack.pop();

				// while loop to run throughout the whole stack containing our quotes stored via DFS
				while (!stack.empty())
				{
					std::cout << "----------------------------------------------" << std::endl;
					std::cout << "Would you like to view the next quote or exit? (enter 1 or 2)" << std::endl;
					std::cout << "1) Yes" << std::endl;
					std::cout << "2) No" << std::endl;
					std::cout << "----------------------------------------------" << std::endl;
					std::cin >> input;
					
					if (input == 1)
					{
						quote = stack.top();
						std::cout << "----------------------------------------------" << std::endl;
						std::cout << "Your quote is: " << "\"" << quote->getQuote() << "\"" << std::endl;
						std::cout << "Category: " << quote->getCategory() << std::endl;
						std::cout << "Sentiment Value: " << quote->getSentimentVal() << std::endl;
						std::cout << "Author: " << quote->getAuthor() << std::endl;
						std::cout << "----------------------------------------------" << std::endl;
						std::cout << std::endl;
						stack.pop();
					}
					else if (input == 2)
					{
						exit(0);
					}
				}
			}
		}
	}
	return 0;
}
