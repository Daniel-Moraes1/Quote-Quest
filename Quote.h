#pragma once
#include <string>

class Quote
{
private:
	int sentimentVal;
	int length;
	std::string quote;
	std::string category;
	std::string author;

public:
	Quote();
	Quote(int sentimentVal, int length, std::string quote, std::string category, std::string author);
	int getSentimentVal();
	int getLength();
	std::string getQuote();
	std::string getCategory();
	std::string getAuthor();
	
};