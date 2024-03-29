import sys
from PyQt5.QtGui import QGuiApplication
from PyQt5.QtQml import QQmlApplicationEngine
from PyQt5.QtCore import QTimer
import ntplib
import time
from time import ctime
from datetime import datetime

TIME_SERVER = "time.google.com"
SITE_LONGITUDE = 105.19
SITE_LATITUDE = 39.74
TIME_ZONE = 7

app = QGuiApplication(sys.argv)

engine = QQmlApplicationEngine()
engine.quit.connect(app.quit)
engine.load('Screen02.qml')

def update_time_and_date_az_el():
    # Time and Date
    ntp_client = ntplib.NTPClient()
    response = ntp_client.request(TIME_SERVER)
    curr_time_str = ctime(response.tx_time)
    date = datetime.strptime(curr_time_str, "%a %b %d %H:%M:%S %Y")
    time_list = str(date).split()
    curr_date = str(date.month) + '/' + str(date.day) + '/' + str(date.year)
    curr_time = time_list[1]
    engine.rootObjects()[0].setProperty('currDate', curr_date)
    engine.rootObjects()[0].setProperty('currTime', curr_time)
    
    # Azimuth and Elevation
    # engine.rootObjects()[0].setProperty('currAz', '%0.6f' % curr_azimuth)
    # engine.rootObjects()[0].setProperty('currEl', '%0.6f' % curr_elevation)


timer = QTimer()
timer.setInterval(500)  # msecs 100 = 1/10th sec
timer.timeout.connect(update_time_and_date_az_el)
timer.start()

# All non-updating properties in top box
engine.rootObjects()[0].setProperty('timeServer', TIME_SERVER)
engine.rootObjects()[0].setProperty('siteLongitude', str(SITE_LONGITUDE))
engine.rootObjects()[0].setProperty('siteLatitude', str(SITE_LATITUDE))
engine.rootObjects()[0].setProperty('timeZone', str(TIME_ZONE))

sys.exit(app.exec())