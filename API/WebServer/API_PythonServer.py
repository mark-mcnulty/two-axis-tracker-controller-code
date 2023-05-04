#structure designed for furutre Python developement of API communication creates a class with a HTTP server and uses ctypes library
from ctypes.wintypes import BYTE
from http.server import HTTPServer, BaseHTTPRequestHandler

HOST = #insert host ip address here
PORT = 9999

class NeuralHTTP(BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.send_header("Content-type","test/html")
        self.end_headers()

        self.wfile.write(bytes("<html><body><h1>hello, world!</h1></body></html>"), "utf-8")


server = HTTPServer((HOST,PORT),NeuralHTTP)
print("Server now running...")
server.server_forever
server.server_close
print("Server stoppped")
