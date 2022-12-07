HOW TO USE:

Download all cpp files (Python scripts not necessary)

Download quote csv and preprocesses graph txt from our drive: https://drive.google.com/drive/folders/1VieJropXMiz7Ixu0AVM4i17FsOvlw2s1?usp=sharing

Compile, generate quotes, and find similar quotes while exploring Breadth First and Depth First Searches!!!


# Quote-Quest
COP3503 Final Project

Team Members: Adam Ababon, Alvin Bang, Daniel Moraes

Problem: 
We want to be able to generate quotes by utilizing relevant inputted emotional data and be able to generate similar quotes.

Motivation:
Quotes are used in a wide variety of contexts all the time. A teacher may need a quote to inspire students. A blogger may need a quote to introduce readers to a topic they are writing about. A public speaker may need a quote to convey their ideas and enhance the credibility behind themselves and their ideas. 
Whatever the reason may be, people need quotes all the time. However, it’s often difficult to find a quote that matches the emotional context (and other requirements) one might need. For instance, searching for quotes that convey love returns a bunch of top 10-50 lists that may be overused or not accurately convey the aspects of love a user wants (positives of love, difficulties of love, heartbreak, etc.) Thus, our generator will allow users to search for quotes that match their specific emotional criteria within topics and allow the user to continue generating quotes until they find one optimal for them.

Features:
We know we have solved the problem when we are able to successfully generate quotes that match a user’s specific emotional criteria based on factors such as level of sentiment, quote length, author, and more. The user must also be able to generate quotes similar to the one generated via a graph data structure. 
*Sentiment value is a measure of the emotional coefficient (positivity/negativity) of a quote gathered using Natural Language Processing algorithms.

Data: 
Quotes: https://www.kaggle.com/datasets/manann/quotes-500k 
Data set of 500,000 quotes including their author and the category. We will be conducting further analysis on the quotes in the dataset to add columns such as sentiment quotient and quote length.

Strategy: Preliminary algorithms or data structures you may want to implement and how would you represent the data
We will be using an adjacency list graph structure comparing depth-first and breadth-first search to find the most applicable quotes relative to the input data. The adjacency list will be implemented as a map of vectors and is used to track similarities between quotes. Generating new quotes will be accomplished via breath-first and depth-first searches. Breadth-first search meaning searching all vertices connected to a vertex before searching at a deeper level, and depth-first search meaning searching deeper before searching all nearby nodes.	

