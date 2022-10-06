import os
import keylogger
import detect_smile
from multiprocessing import Process
import time
import keyboard
import random 
import cv2 
import random

def runGuitar():
    #command line argument to run guitar to esp8266
    os.chdir('C:\Program Files\mosquitto')
    starttime = time.time()
    while True:
        n = random.uniform(10, 30)
        os.system('mosquitto_pub -h localhost -p 1883 -t test/topic -m \"play!\"')
        print('it is working PLAY')
        time.sleep(n - ((time.time() - starttime) % n))


def runDooDooSmell():
    #command line argument to run smellGeneratorto esp8266
    os.chdir('C:\Program Files\mosquitto')
    starttime = time.time()
    while True:
        n = random.uniform(20, 30)
        print('it is working sharting!')
        os.system('mosquitto_pub -h localhost -p 1883 -t test/topic -m \"sharting!\"')
        time.sleep(n - ((time.time() - starttime) % n))

def loggingLoop():
    starttime = time.time()
    while True:
        keylogger.checkContents()
        time.sleep(10.0 - ((time.time() -starttime ) % 10.0))

def main():
    print('hi')

    #print a starting audio message depending on what time it is to wake up 
    #(with saulGoodman deepfake voice)
    os.system("start C:/Users/madhu/Desktop/Megafile/programs/tortureDevice/Smile-Detector-master/audio2.wav")

    #take a picture of me 
    cam = cv2.VideoCapture(0)
    s, img = cam.read()
    if s:
        cv2.namedWindow("cam-test", 640)
        cv2.imshow("cam-test", img)
        cv2.waitKey(0)
        cv2.destroyWindow("cam-test")
        cv2.imwrite("stupidface.jpg", img)

    #start the keylogger and visual detection software 
    p3 = Process(target=detect_smile.main)
    p1 = Process(target=runGuitar)
    p2 = Process(target=runDooDooSmell)
    p4 = Process(target=loggingLoop)

    p1.start()
    p2.start()
    p3.start()
    p4.start()

if __name__ == '__main__':
    main()















































