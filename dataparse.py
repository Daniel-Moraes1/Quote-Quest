import nltk
import pandas as pd
from nltk.sentiment.vader import SentimentIntensityAnalyzer
# nltk.download('vader_lexicon') uncomment if downloading first time
sia = SentimentIntensityAnalyzer()


print("Reading quote list...")
df = pd.read_csv("quotes.csv")
df = df.drop(df.index[422587]) # Broken quote

# Get the top n most common quote categories
NUM_CATEGORIES = 10
categories_list = df[df.columns[2]].tolist()


print(f"Getting top {NUM_CATEGORIES} categories")
categories_count = dict()
for i in categories_list:
    try:
        categories = i.split()
    except:
        continue
    for j in range(len(categories)):
        if j != len(categories) - 1:
            categories[j] = categories[j][:-1]
        if not categories[j] in categories_count:
            categories_count[categories[j]] = 1
        else:
            categories_count[categories[j]] += 1

keys = sorted(categories_count, key=categories_count.get, reverse=True)
top_categories = keys[:NUM_CATEGORIES]

top_categories.append("hate")

# Adding hate to experiment with sentiment analysis
#top_categories = ['love', 'life', 'inspirational', 'philosophy', 'humor', 'god', 'truth', 'wisdom', 'happiness', 'hope','hate']
print(f"The top categories are {top_categories}")

new_categories_column = []
count = 0


for quote_categories in categories_list:
    new_categories_column.append([])
    try:
        quote_group = quote_categories.split()
        for category in quote_group:
            category = category.lower()
            if category[-1] == ',':
                category = category[:-1]
            if category in top_categories:
                new_categories_column[count].append(category)
        new_categories_column[count] = ", ".join(new_categories_column[count])
        count += 1
    except:
        count += 1
        continue
df['category'] = new_categories_column

#Remove quotes that have none of the top categories
df = df[df.category != ""]


sentiment_list = []
length_list = []

print("Initializing quote list...")
quote_list = df[df.columns[0]].tolist()

remove_quotations = []
print("Conducting Sentiment Analysis and getting lengths...")
for i in range(len(quote_list)):
    if i%10000 == 0:
        print(f"Sentiment Analysis completion: %.2f" % (i*100/len(quote_list)))
    try:
        # Remove quotation marks from beginnings of some quotes for uniformity
        sentiment_list.append(sia.polarity_scores(quote_list[i])['compound'])
        length_list.append(len(quote_list[i]))
    except:
        continue

print("Sentiment Analysis completion: 100%")
print("Adding Sentiment Analysis and length columns to dataframe...")


print("Swapping out non-native characters...")

for quote in range(len(quote_list)):
    for i in range(len(quote_list[quote])):
        if quote_list[quote][i] == "’":
            new_quote = quote_list[quote][:i] + "'" + quote_list[quote][i+1:]
            quote_list[quote] = new_quote
        if quote_list[quote][i] == "—":
            new_quote = quote_list[quote][:i] + "-" + quote_list[quote][i+1:]
            quote_list[quote] = new_quote
        if quote_list[quote][i] == "…":
            new_quote = quote_list[quote][:i] + "..." + quote_list[quote][i + 1:]
            quote_list[quote] = new_quote
        if quote_list[quote][i] == "”":
            new_quote = quote_list[quote][:i] + '"' + quote_list[quote][i + 1:]
            quote_list[quote] = new_quote

author_list = df[df.columns[1]].tolist()
for author in range(len(author_list)):
    try:
        for i in range(len(author_list[author])):
            if author_list[author][i] == "’":
                new_author = author_list[author][:i] + "'" + author_list[author][i+1:]
                author_list[author] = new_author
            if author_list[author][i] == "—":
                new_author = author_list[author][:i] + "-" + author_list[author][i+1:]
                author_list[author] = new_author
            if author_list[author][i] == "…":
                new_author = author_list[author][:i] + "..." + author_list[author][i + 1:]
                author_list[author] = new_author
            if author_list[author][i] == "”":
                new_author = author_list[author][:i] + '"' + author_list[author][i + 1:]
                author_list[author] = new_author
            if author_list[author][i] == "é":
                new_author = author_list[author][:i] + 'e' + author_list[author][i + 1:]
                author_list[author] = new_author
    except:
        continue


df.quote = quote_list
df.author = author_list
df['sentiment'] = sentiment_list
df['length'] = length_list
df2 = df[df['length'] < 300]
print("Exporting data to csv...")
df2.to_csv("data.csv")

print("Finished")