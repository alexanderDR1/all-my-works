import time
import redis

from flask import Flask



app = Flask(__name__)


app = Flask(__name__)
cache = redis.Redis(host='redis', port=6379)



@app.route('/')
def hello():
    return 'Hello World! my name is: alex'

if __name__ == "__main__":
    app.run(port=10000)


#if __name__ == '__main__':
 #  app.run(port=10000)



