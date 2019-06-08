#!/usr/bin/env python3

import random

num = 1
count = 0

while count < 1000:
    num = random.randint(1, 100000)
    print("BRI %03d" % num)
    count = count + 1