import sys

from PyQt5.QtGui import QGuiApplication
from PyQt5.QtQml import QQmlApplicationEngine

app = QGuiApplication(sys.argv)

engine = QQmlApplicationEngine()
engine.quit.connect(app.quit)
engine.load('../two-axis-tracker-controller-code/GUI/main.qml')

curr_date = "11/29/2022"

# print(engine.rootObjects())
# engine.rootObjects()[0].setProperty('currDate', curr_date)

sys.exit(app.exec())