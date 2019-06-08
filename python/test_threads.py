#!/usr/bin/python

import Queue
import threading
import time
import serial
import random

exitFlag = 0

class myThread (threading.Thread):
   def __init__(self, threadID, name, q, port):
      threading.Thread.__init__(self)
      self.threadID = threadID
      self.name = name
      self.q = q
      self.port = port
      self.data = 0
      self.string = ''
      self.serial = serial.Serial('/dev/' + self.port, 9600)
   def run(self):
      print "Abrindo porta Serial: " + self.port
      process_data(self)
      print "Finalizando " + self.port

def process_data(threadSelf):
   while not exitFlag:
      # time.sleep(random.randint(1,5))
      c = threadSelf.serial.read()
      threadSelt.string += c
      if '<F>' in threadSelf.string:
          queueLock.acquire()
          threadSelf.q.put(threadSelf.name + ": " + threadSelf.string)
          threadSelf.string = ''
          queueLock.release()
          #print "%s processing %s" % (threadSelf.name, threadSelf.data)

threadList = ["72c", "Controlador"]
queueLock = threading.Lock()
workQueue = Queue.Queue(10)
threads = []
threadID = 1
portList = ["ttyUSB0", "ttyUSB1"]

# Create new threads
for tName in threadList:
   thread = myThread(threadID, tName, workQueue, portList[threadID - 1])
   thread.start()
   threads.append(thread)
   threadID += 1

# Fill the queue
try:
    while True:
        queueLock.acquire()
        if not workQueue.empty():
            print "Main: ", workQueue.get()
        queueLock.release()
        time.sleep(0.5)
finally:
    exitFlag = 1

for t in threads:
   t.join()
print "Exiting Main Thread"
