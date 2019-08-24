import fileinput
import sys

#https://open.kattis.com/problems/anagramcounting

def factorial(n):
    n = int(n)
    result = int(1)
    for i in range(1, n+1):
        result *= int(i)
    return result


def nChooseX(n, x):
    result = int(factorial(n))/(int(factorial(x))*int(factorial(n-x)))
    return result


for lines in sys.stdin:
    lettersOccurence = []
    for v in range(0, 200):
        lettersOccurence.append(int(0))
    totalOcc = int(0)
    for c in lines:
        if(ord(c) == 10):
            continue
        totalOcc += 1
        lettersOccurence[ord(c)]+=1
    totalVal = int(1)
    for i in lettersOccurence:
        if(i == 0):
            continue
        if(totalOcc == 0):
            break
        totalVal *= int(nChooseX(totalOcc, i))
        totalOcc -= int(i)
    print(totalVal)
