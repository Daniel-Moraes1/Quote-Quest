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
    int index;

public:
	Quote();
	Quote(float sentimentVal, int length, std::string quote, std::string category, std::string author, int index);
	float getSentimentVal();
	int getLength();
	std::string getQuote();
	std::string getCategory();
	std::string getAuthor();
    int getIndex();
    float calculateSimilarity(Quote* q);
    std::vector<std::string> getQuote(Quote* quote);
	
};