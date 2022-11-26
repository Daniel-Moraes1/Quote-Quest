import nltk
import pandas as pd
from nltk.sentiment.vader import SentimentIntensityAnalyzer
#nltk.download('vader_lexicon')
sia = SentimentIntensityAnalyzer()
#sia.polarity_scores

print("Reading quote list...")
df = pd.read_csv("quotes.csv")
df = df.drop(df.index[422587])

print("Initializing quote list...")
quote_list = df[df.columns[0]].tolist()

sentiment_list = []
length_list = []

print("Conducting Sentiment Analysis and getting lengths...")
i = 0
for quote in quote_list:
    try:
        sentiment_list.append(sia.polarity_scores(quote)['compound'])
        length_list.append(len(quote))
    except:
        print(i)
    i+=1

print("Adding Sentiment Analysis and length columns to dataframe...")
df['sentiment'] = sentiment_list
df['length'] = length_list

print("Exporting data to csv...")
df.to_csv("data.csv")

print("Finished")
