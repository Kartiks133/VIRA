import speech_recognition as sr
import time

def get_command():
    recognizer = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening...")
        recognizer.pause_threshold = 1  # small pause before recognizing
        audio = recognizer.listen(source, timeout=5, phrase_time_limit=5)

    try:
        command = recognizer.recognize_google(audio)
        print("You said:", command)
        time.sleep(2)
        return command.lower()
    except sr.WaitTimeoutError:
        print("Listening timed out while waiting for phrase to start.")
        time.sleep(2)
    except sr.UnknownValueError:
        print("Could not understand audio.")
        time.sleep(2)
    except sr.RequestError as e:
        print(f"Could not request results; {e}")
        time.sleep(2)
    
    return "none"

command = get_command()

with open("command.txt", "w") as f:
    f.write(command)
