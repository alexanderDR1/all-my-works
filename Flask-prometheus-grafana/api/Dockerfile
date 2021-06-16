FROM python:3.7
COPY . /app
WORKDIR /app
RUN pip install -r requirements.txt
ENV FLASK_APP /app/server.py
EXPOSE 5000
CMD python server.py

