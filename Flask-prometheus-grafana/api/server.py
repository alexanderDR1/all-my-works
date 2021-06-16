import logging

from flask import Flask
from prometheus_flask_exporter import PrometheusMetrics

logging.basicConfig(level=logging.INFO)
logging.info("Setting LOGLEVEL to INFO")

api = Flask(__name__)
metrics = PrometheusMetrics(api)

metrics.info("app_info", "description", version="1.0.0")


@api.route("/say-hello/")
def hello():
    return {"message": "hello"}


@api.route("/error")
def error():
    i = 1/0
    return str(i), 500

if __name__ == '__main__':
    api.run('0.0.0.0', port=5000)
