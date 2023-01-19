import sys
from PyQt5.QtGui import QGuiApplication
from PyQt5.QtQml import QQmlApplicationEngine
from PyQt5.QtCore import QTimer
from time import strftime, localtime

app = QGuiApplication(sys.argv)

engine = QQmlApplicationEngine()
engine.quit.connect(app.quit)
engine.load('Screen02.qml')

def update_time():
    # Pass the current time to QML.
    curr_time = strftime("%H:%M:%S", localtime())
    engine.rootObjects()[0].setProperty('currTime', curr_time)

timer = QTimer()
timer.setInterval(100)  # msecs 100 = 1/10th sec
timer.timeout.connect(update_time)
timer.start()

engine.rootObjects()[0].setProperty('currDate', "1/19/2023")

sys.exit(app.exec())