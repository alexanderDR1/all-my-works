## Example on how to use Prometheus and Grafana to monitor a Flask API application and K8S cluster metrics


### Docker compose setup:

```
git clone https://github.com/Dgotlieb/Flask-prometheus-grafana.git
start docker machine (Desktop / Quickstart terminal)
docker-compose up
```

### Access

* API URL1: http:// < docker-machine-ip > :5000/say-hello
* API URL2: http:// < docker-machine-ip > :5000/error
* Prometheus: http:// < docker-machine-ip / localhost > :9090/
* Grafana: http:// < docker-machine-ip / localhost > :3000 `[username: admin, password: pass@123]`

### K8S setup:

```
$ minikube start
$ helm repo add prometheus-community https://prometheus-community.github.io/helm-charts
$ helm install prom prometheus-community/kube-prometheus-stack
$ kubectl expose deployment prom-grafana --type=LoadBalancer --name mygraph --port=80 --target-port=3000 --protocol=TCP
$ minikube service mygraph --url

Enter your browser at the above URL --> username: admin, password: prom-operator
```
