from cs50 import get_string
import re

text = get_string("TEXT: ")
words = text.count(" ") + 1
spezial =  text.count("!") + text.count("'") + text.count("+") + text.count("-") + text.count(".") + text.count(" ") + text.count(";") + text.count("?") + text.count("`") + text.count('"') + text.count(",")
letters = len(text) - spezial
sentence = text.count(".") + text.count("?") + text.count("!")

to100 = 100 / words
L = to100 * letters
S = to100 * sentence

grade = round(0.0588 * L - 0.296 * S - 15.8)
print(grade)
if grade >= 16:
    print("Grade 16+")
elif grade < 1:
    print("Before Grade 1")
else:
    print(f"Grade {int(grade)}")
