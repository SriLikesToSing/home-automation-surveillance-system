import os 
import time

def checkContents():
    with open('C:/Users/madhu/Desktop/Megafile/programs/tortureDevice/Smile-Detector-master/log.txt') as f:
        contents = f.read()
        searchSentence = "" #optional search sentence to query custom things such as potential passwords they could have typed in 
        if len(contents) != 0:
            os.chdir('C:\Program Files\mosquitto')
            os.system('mosquitto_pub -h localhost -p 1883 -t test/topic -m \"fire!\"')
            os.system("start C:/Users/madhu/Desktop/Megafile/programs/tortureDevice/Smile-Detector-master/audio.wav")
            time.sleep(20)
        else:
            print("nothing so far.")
















