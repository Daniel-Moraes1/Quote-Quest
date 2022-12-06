#pragma once
#include <string>
#include <vector>

class Quote
{
private:
	float sentimentVal;
	int length;
	std::string quote;
	std::string author;
    std::string category;

public:
	Quote();
	Quote(int sentimentVal, int length, std::string quote, std::string category, std::string author);
	float getSentimentVal();
	int getLength();
	std::string getQuote();
	std::string getCategory();
	std::string getAuthor();
	
};