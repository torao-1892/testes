#!/usr/bin/env python

import time

def read_data():
    path = '/sys/class/net/eth0/statistics/'
    rx = open(path + 'rx_bytes', 'r')
    tx = open(path + 'tx_bytes', 'r')
    return int(rx.readline()), int(tx.readline())

if __name__ == '__main__':
    rx1, tx1 = read_data()
    
    for i in range(1,100):
        time.sleep(1)
        rx2, tx2 = read_data()
        rx_rate =  (float (rx2 - rx1) / 1024) * 8
        tx_rate = (float (tx2 - tx1) / 1024) * 8
        rx1, tx1 = rx2, tx2
        print "Rx: ", "%.2f" % rx_rate, " Tx: ", "%.2f" % tx_rate 


import sched, time
s = sched.scheduler(time.time, time.sleep)
def print_time(): print "From print_time", time.time()

def print_some_times():
    print time.time()
    s.enter(5, 1, print_time, ())
    s.enter(10, 1, print_time, ())
    s.run()
    print time.time()

print_some_times()

