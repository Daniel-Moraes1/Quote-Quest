#include "Quote.h"
#include <string>
#include <iostream>

Quote::Quote()
{
	this->sentimentVal = 0;
	this->length = 0;
	this->quote = "";
	this->category = "";
	this->author = "";
    this->index = 0;
}

Quote::Quote(float sentimentVal, int length, std::string quote, std::string category, std::string author, int index)
{
	this->sentimentVal = sentimentVal;
	this->length = length;
	this->quote = quote;
	this->category = category;
	this->author = author;
    this->index = index;
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

int Quote::getIndex() {
    return this->index;
}

float Quote::calculateSimilarity(Quote *q2) {
    //If the quotes are the same, similarity is 0 (perfect)
    if (q2 == this)
        return 0.0;

    float similarity = 0.0;


    // Sentiment value
    similarity += std::max(this->getSentimentVal(), q2->getSentimentVal()) - std::min(this->getSentimentVal(), q2->getSentimentVal());
    //Category
    if (this->getCategory() != q2->getCategory()) {
        similarity += 0.0075; // Must be low enough to jump between categories if sentiments are close enough
    }

    //Length
    float l1(this->getLength()); float l2(q2->getLength());
    float length_reduction_factor = 50.0; // Chosen to ensure similarity is not too heavily impacted by length
    similarity += ((std::max(l1, l2) - std::min(l1, l2))/(std::max(l1, l2)*length_reduction_factor));


    return similarity;
}


/* OUTPUT FORMAT (all strings)
 * [0] QUOTE
 * [1] AUTHOR
 * [2] CATEGORY: (one of) love, life, inspirational, philosophy, humor, god, truth, wisdom, happiness, hope, hate
 * [3] SENTIMENT (-1, 1)
 * [4] LENGTH (in characters)
*/
std::vector<std::string> Quote::getQuoteAttributes() {
    std::vector<std::string> output = {this->getQuote(),
                                       this->getAuthor(),
                                       this->getCategory(),
                                       std::to_string(this->getSentimentVal()),
                                       std::to_string(this->getLength())};
    return output;
}