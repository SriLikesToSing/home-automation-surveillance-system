import os 
import time

def checkContents():
    with open('C:/Users/madhu/Desktop/Megafile/programs/tortureDevice/Smile-Detector-master/log.txt') as f:
        contents = f.read()
        searchSentence = "jeff bezos is everybody's daddy"
        if searchSentence not in contents:
            print("U HAVE FAILED LOL")
            os.chdir('C:\Program Files\mosquitto')
            os.system('mosquitto_pub -h localhost -p 1883 -t test/topic -m \"fire!\"')
            os.system("start C:/Users/madhu/Desktop/Megafile/programs/tortureDevice/Smile-Detector-master/audio.wav")
            time.sleep(20)
            #play audio clip
        else:
            print("U are saved for now.")
            #play audio clip
















