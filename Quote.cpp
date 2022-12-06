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

Quote::Quote(float sentimentVal, int length, std::string quote, std::string category, std::string author)
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

float Quote::calculateSimilarity(Quote *q2) {
    //If the quotes are the same, similarity is 0 (perfect)
    if (q2 == this)
        return 0.0;

    float similarity(0);

    // Sentiment value
    similarity += abs(this->getSentimentVal() - q2->getSentimentVal());

    //Category
    if (this->getCategory() != q2->getCategory()) {
        similarity += 0.25;
    }

    //Length
    float l1(this->getLength()); float l2(q2->getLength());
    float length_reduction_factor = 7.0; // Chosen to ensure similarity is not too heavily impacted by length
    similarity += ((std::max(l1, l2) - std::min(l1, l2))/(std::max(l1, l2)*length_reduction_factor));

    return similarity;
}