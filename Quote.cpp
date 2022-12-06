#include "Quote.h"
#include <string>

Quote::Quote()
{
	this->sentimentVal = 0;
	this->length = 0;
	this->quote = "";
	this->category = "";
	this->author = "";
}

Quote::Quote(int sentimentVal, int length, std::string quote, std::string category, std::string author)
{
	this->sentimentVal = sentimentVal;
	this->length = length;
	this->quote = quote;
	this->category = category;
	this->author = author;
}

float Quote::getSentimentVal()
{
	return this->sentimentVal;
}

int Quote::getLength()
{
	return this->length;
}

std::string Quote::getQuote()
{
	return this->quote;
}

std::string Quote::getCategory()
{
	return this->category;
}


std::string Quote::getAuthor()
{
	return this->author;
}