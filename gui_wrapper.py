import sys
from PySide6.QtWidgets import QApplication
from PySide6.QtQuick import QQuickView

if __name__ == "__main__":
    app = QApplication()
    view = QQuickView()

    view.setSource("Screen01.qml")
    view.show()
    sys.exit(app.exec())