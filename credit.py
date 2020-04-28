from cs50 import get_int
from sys import exit

number = get_int("Number: ")

arr = []
while number > 1:
    temp = number % 10
    temp = int(temp)
    arr.append(temp)
    number /= 10
num = 0
for i in range(len(arr)):
    if i % 2:
        if (arr[i] * 2) > 9:
            num += (arr[i] * 2) % 10
            num += int((arr[i] * 2) / 10)
        else:
            num += arr[i] * 2
    else:
        num += arr[i]
if num % 10 != 0:
    print("INVALID")
    exit(0)
else:
    card_host = arr[len(arr) - 1] * 10 + arr[len(arr) - 2]
    if card_host == 37:
        print("AMEX")
    elif card_host == 55 or card_host == 51:
        print("MASTERCARD")
    elif card_host == 41 or card_host == 40:
        print("VISA")
    else:
        print("INVALID")
