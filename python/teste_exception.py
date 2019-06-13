#!/usr/bin/env python

import time

for i in range(1, 100):
    time.sleep(0.250)
    try:
        print "Teste: ", i
        if i % 7 == 0:
            aux = i / 0
        else:
            print "Tudo Ok"
    except Exception as e:
        print "Deu algum erro!", repr(e)

