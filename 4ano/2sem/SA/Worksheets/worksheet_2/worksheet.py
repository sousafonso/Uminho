"""
1. Collect keyboard data, create a log file with the collected data and calculate relevant metrics;
2. Send the raw data to a feed using Firebase
"""

from pynput import keyboard
from datetime import datetime

#detect key press
def on_press(key):
    try:
        print('alphanumeric key {0} pressed'.format(str(key.char)))
        log_data(datetime.now(),'KeyPressed', str(key.char))
    except:
        print('special key {0} pressed'.format(str(key)))
        log_data(datetime.now(),'SpecialKeyPressed', str(key))

#detect key releases
def on_release(key):
    print('{0} released'.format(str(key)))
    if key == keyboard.Key.esc:
        try:
            log_data(datetime.now(),'KeyReleased', str(key.char))
        except AttributeError:
            log_data(datetime.now(),'KeyReleased', str(key))
    #stop listener
    print('Gracefully Stopping!')
    return False

def log_data(timestamp, event_type, key):
    with open('./SA/Worksheets/worksheet_2/key_log.txt', 'a') as log_file:
        log_file.write(f'{timestamp} - {event_type}: {key}\n')
    log_file.close()

#collecting events
with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
    listener.join()

#in a non-blocking fashion
listener = keyboard.Listener(on_press=on_press, on_release=on_release)
listener.start()