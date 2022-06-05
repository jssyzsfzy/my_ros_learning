#! /usr/bin/env python3
import math

def get_hx(x):
    num = 1/(1+math.exp(-x))
    return num

num = 1
if __name__ == "__main__":
    num = 1
    print(get_hx(num))

