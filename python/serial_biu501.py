#!/usr/bin/env python3

from serial import Serial
import bitarray
import time

ser = Serial('/dev/ttyUSB0', 115200)

for i in range(1,100):
    for a in range(0,16):
        ser.write(b'\xcc')
        ser.write((1<<a).to_bytes(2, byteorder='big'))
        #ser.write(b.to_bytes(1, byteorder='big'))
        ser.write(b'\xff')
        print("Count: {} ".format(a))
        time.sleep(0.5)

    for a in range(0,16):
        ser.write(b'\xcc')
        ser.write(((2**15)>>a).to_bytes(2, byteorder='big'))
        #ser.write(b.to_bytes(1, byteorder='big'))
        ser.write(b'\xff')
        print("Count: {} ".format(a))
        time.sleep(0.5)

for a in range(0,256):
    for b in range(0,256):
        ser.write(b'\xcc')
        ser.write(a.to_bytes(1, byteorder='big'))
        ser.write(b.to_bytes(1, byteorder='big'))
        ser.write(b'\xff')
        print("Count: {} - {}".format(a,b))
        time.sleep(0.5)


ser.close()
