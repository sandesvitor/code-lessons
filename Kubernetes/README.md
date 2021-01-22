# INTRODUCTION TO KUBERNETES (K8s)
---

### **What is Kubernetes?**
"Open source container orchestration tool developed by Google."

It helps you manage containerized applications in different deployment environments (physical, virtual, cloud and even hybrids).

### **The need for container orchestration tool**
- Trend from **Monolith** to **Microservices**;
- Increased usage of **containers**;
- Demand for a **proper way** of **managing** those hundreds of containers;

### **What features do orchestration tools offer?**
- **High Availability** or no downtime (always available for the users!);
- **Scalability** or hight performance;
- **Disaster recovery** - backup and restore;

---
## **Kubernetes Components:**
- Volumes;
- Pod;
- Service;
- Ingress;
- Secrets;
- ConfigMap;
- StatefulSet;
- Deployment;

EX: Simple Javascript application with a simple database.
---

### 1. **Node and Pod**:

A *Node* (worker node) is a simple server, physical or virtual machine. A *Pod* is an abstraction over a container. 

What a *Pod* does, it creates this running environment or a layer on top of a container. And the reason is that Kubernetes (K8s) wants to abstract away the container runtime so you can replaced them if you want to, and also because yo don't have to directly have to work with docker. **You only interacts with Kubernetes layers!**

A *Pod* is usually meant to run only **one application container** inside of it.

### So, how each Pod communicates with one another?

Out of the box, **K8s** offers a virtual network, wich means that each Pod gets its own IP Address (not the container, the Pod). ANd each Pod can communicate with each other by the Ip Address. 

However, pods components are **effemeral**, wich means that they can die very easely, and when that happens, for whatever reason, a new Pod is created in its place, and a new Ip Address is assigned to it. That can be very inconvenient, because you would have to ajust the communication by Ip everytime such event happens.

And that's the porpous of the next component!

### 2. **Service**:

Is basicaly a **permaent Ip Address** that can be attached to each Pod (in the app example, the js app pod will have its service and the database pod will have its service)..

The lifecycle of Pod and Service are **NOT connected**, so even if the Pod dies, the Service and its Ip Address will stay!

And how can we make our application to be acessible through a browser?

### 3. **Ingress**:

An **external service** is a service that opens the communication from external sources. But obviously we wouldn't want to open our Database to be open to the public request, and for that we would create an **internal** service, wich is a type of service we specify when creating one.

An example of an URL bound with an externaol service would be **http://124.89.101.2:8080**

That represents the Ip Address of the **Node** and the port number of the services (good for testing).

The **Ingress Component** comes to forward the request to the service of the application. It will be something like this:

 ---------         ------------------       ----------------
| Request | ---> | https://my-app.com | ---> | app service IP |
 ---------         ------------------       ----------------

### 4. **ConfigMap and Secret (for external configurations)**:

Database endpoint (URL) are usually in the **built** application (an env variable for instance). If the service name of the database change in the process, you would have to re-build the image of the Pod.

For that we can use **ConfigMap**.

The ConfigMap contains external configurations of your application. If you change the name of the service (the endpoint) you just need to change de ConfigMap.

*DON'T PUT CREDENCIALS IN THE CONFIGMAP!!!*

For that purpous, use **Secret**. It is just like ConfigMap, used to store secret data in base64 encoded format.

### 5. **Volumes**:

Just as Docker, a Pod is a stateless entity· If the Pod is re-build or restarted the data will be gone! For a database this is inconvenient, because you want your data to persist.

To solve that, we use the **Volumes Component**. It attaches a physical storage to you Pod. It can be a local storage, such as you local machine, or a remote storage, outside of the K8s cluster (cloud for instance).

Since K8s cluster does not explicit manage data persistence, we can understand the Volumes as an external Harddrive pluggedf in the K8s cluster!

### 6. **Deployment**:

Now, if an user acess our endpoint in a browser (https://my-app.com, for instance), what would happen if the Pod dies? 

We can replicate everything! We can have another node also connected to the services.

A **Service** has 2 funtionalities:
- parmanent IP;
- load balancer (it catches the request and forward to the Pod that is least busy).

In order to create the replica to our application Pod, we wouldn't create a second Pod, we would create a **blueprint**. That blueprint is another component called **Deployment**.

In practice, we create Deployment, not Pods, configuring how many replicas we would have. It is a layer of abstraction on top of Pods (and Pods are a layer of abstraction on top of containers).

### 7. **StatefulSet**:

Deployement creates an blueprint for stateless Pods. But, in the case of our Database, we cannot create an replica that has no state, because a database have a state, wich is its data. If we have replicas of our DB they all would have to access the same storage that our data persists (to avoid Data Inconsistent).

For that we use the **StatefulSet** component.

*IT IS MORE DIFFICULT TO WORK THAN DEPLOYMENT! THAT'S WHY IS MORE COMMON TO WORK WWITH EXTERNAL DB!!!*


---
## **Kubernetes Architecture:**

### **Node Process**:

### 1. Worker machine in K8s cluster:
- Each Node has multiple Pods on it;
- 3 processes must be installed on every Node;
- Worker Nodes are the cluster service that actually work.

The first process that have to run in every Node is the **container runtime** (it could be Docker ou other technologies as well). 

So, because application Pods have containers running inside a container runtime needs to be installed on every Node. But the process that actually schedules those Pods and the containers that are underneath are called **Kubelet**, wich is a process of K8s itself, that interfaces with the container runtime and the machine, the Node.

### *KUBELET INTERACTS WITH BOTH - THE CONTAINER AND NODE!*

The Kubelet starts the pod with a container inside, assigning resources from the machine (Node) to the container, like CPU, RAM and storage resources.

The way that communication between them works is by **Services** that is a Load Balancer that basically catches the request directed to the Pod or Application, like DB for instance, and forward to the respective Pod. 

And the process that is responsible for forwarding requests from services to Pods, it's called **Kube Proxy**, that also have to be installed in every Node! This process have **intelligent forwarding logic inside** that makes sure communication also works in performant way with low overhead. For instance, if we hade two Nodes replicas running both an **Web Application** and a **Postgresql Database** Pods, a request to the database would not generate a search in a random DB Pod, like, for instance, a request being made in Node 1 accessing the DB Pod in Node 2. Instead of that, Kube Proxy will always forward said request to the Pod that is actually running in the same Node as the Pod that initiated the request, thus this way **avoiding the network overhead of sending the request to another machine**.

In summary, the 3 Node processes:
- Kubelet;
- Kube Proxy;
- Container Runtime.

### *So, how do we interact with this cluster?*

How to:
- ...schedule Pod?
- ...monitor?
- ...re-schedule/re-start Pod?
- ...join a new Node?

All of this **master process** are done by **Master Node**!!!

### 2. Master Nodes:

There are 4 processes run on every master Node!

**2.1 - Api Server:**

A cluster gateway that get an initial request of any updates into the cluster and queries;

Also acts as a gatekeeper for authentication. That means whenever you want to schedule new Pods, deploy new applications, create new services or any other components we have to talk to the **Api Server** in the **Master Node**, the Api Server validate your request and, if everything is fine, it forwards your request to other processes (only 1 entrypoint into the cluster!)

| Client | (update/query)---> | Api Server| (is valid?) ---> Master Node  

**2.2 - Scheduler:**

The **Scheduler** comes after the **Api Server**. Whenever you send the Api Server a request to schedule a new Pod, the Api Server will validate your request and it will hand it over to the Scheduler in order to start the application Pod in one of the **Worker Nodes**.

Instead of assign the new Pod to any Node, the Scheduler has this intelligent way of deciding where to put the new component. First it will analize you request, and determine the amount of resources it will need (CPU, RAM, storage, etc...). And than cross-check with the availability of each Node, assigning to that with the least resources used.

### *SCHEDULER JUST DECIDES ON WICH NODE NEW POD SHOULD BE SCHEDULE!*

The process that actually starts taht Pod within the container is the **Kubelet**!

**2.3 - Controller Manager:**

Detects cluster state changes (when a Pod within a Node dies, for instance, the Controller Manager is responsible for fixing it!)

In order to, in said example, re-start the Pods that have died, the **Controller Manager** makes a request to the **Scheduler** and the same above cycle happens!

**2.4 - etcd:**

A **key value storage of a cluster state information**. We can think of it as the **Cluster Brain**! Wich means that every change in the cluster, such as a Pod getting schedule or a Pod diying, all of this changes get save and updated in this ky value store.

The reason why **etcd** is the Cluster Brain is because all of this mechanism of Schedule and Controller Manager works because of its **data**. For example, how does Schedule knows what resources are available on each Worker Node? Or how does Controller Manager knows that a cluster state change in some way?

All of that information is stored in the **etcd**. What is not store in the **etcd key value store** is the **application data**. The **application data** is, for instance, the data of some Database.

---

### Example Cluster Set-Up:

- 2 Master Nodes;
- 3 Worker Nodes;

It is importante to note that the resources from Master to Worker Nodes differs. The Master Process are more importante, but they actually have **less load of work, so they need less CPU, RAM and storage**. Whereas the Worker Nodes do all the job off running those Pods with container inside, therefore they need more resources.

And as our application complexity and its demands for resources increases, we can actually add more Master and Worker Nodes, thus making a more robust system that meet our application resources require.

---

## **Minikube and kubectl - Local Setup:**

### **What is a Minikube?**

Usually in a K8s world, when we are setting up a **Production Cluster Setup** it will have **multiple Master and Worker Nodes**, with their own separate responsabillity. In summary, separated virtual or physical machines that each represents a Node!

### *So, how to test in our local environmet?*

Setting said environment in our personal machine will be a very coastly endevour, maybe even impossible depending on our machine resources. For this we can use the open source **Minikube**, witch is basically **one Node Cluster, where the master Processess and the Worker Processes both run on ONE NODE**. And this Node (machine) will have a Docker Container pre-installed.

The way we run **Minikube** is through VirtualBox, or some other Hypervisor.

To summarize:
- create a Virtual Box on our machine;
- Node runs in that Virtual Box;
- 1 Node K8s cluster;
- for testing porposes.

### **What is a kubectl?**

Now that we have this virtual Node in our local machine that represents Minikube, we need some way to interact with the cluster. We need a way to create Pods and other K8s components on the Node, and the way to do that is using **kubectl**, a **command line tool for K8s cluster**.

Remember, one the **Master Processes** called **Api Serve** is actually the main entrypoint into the K8s cluster. There are different ways to talk to the Api Server using clients:
- UI Dashboard;
- K8s API;
- CLI (kubectl - the most powerfull of any client!)

An important thing to note here is that **kubectl** isn't just for **Minikube**, if we have a Cloud Cluster we can also use kubectl to operate that cluster. We can use kubectl to deploy applications, inspect and manage cluster resources, and view logs. 

---

After installing minikube and kubectl, we can run minikube using virtualbox as a driver, following the steps bellow: 
---


```
┌─[sandesvitor@pop-os] - [~/Study/code-lessons/Kubernetes] - [1236]
└─[$] minikube start --vm-driver=virtualbox                                        [14:37:17]
😄  minikube v1.16.0 on Debian bullseye/sid
✨  Using the virtualbox driver based on user configuration
💿  Downloading VM boot image ...
    > minikube-v1.16.0.iso.sha256: 65 B / 65 B [-------------] 100.00% ? p/s 0s
    > minikube-v1.16.0.iso: 212.62 MiB / 212.62 MiB [] 100.00% 28.89 MiB p/s 8s
👍  Starting control plane node minikube in cluster minikube
💾  Downloading Kubernetes v1.20.0 preload ...
    > preloaded-images-k8s-v8-v1....: 491.00 MiB / 491.00 MiB  100.00% 8.93 MiB
🔥  Creating virtualbox VM (CPUs=2, Memory=2200MB, Disk=20000MB) ...
🐳  Preparing Kubernetes v1.20.0 on Docker 20.10.0 ...
    ▪ Generating certificates and keys ...
    ▪ Booting up control plane ...
    ▪ Configuring RBAC rules ...
🔎  Verifying Kubernetes components...
🌟  Enabled addons: storage-provisioner, default-storageclass
🏄  Done! kubectl is now configured to use "minikube" cluster and "default" namespace by default
┌─[sandesvitor@pop-os] - [~/Study/code-lessons/Kubernetes] - [1237]
└─[$] kubectl get nodes                                                            [14:40:43]
NAME       STATUS   ROLES                  AGE   VERSION
minikube   Ready    control-plane,master   52s   v1.20.0
┌─[sandesvitor@pop-os] - [~/Study/code-lessons/Kubernetes] - [1238]
└─[$] minikube status                                                              [14:41:24]
minikube
type: Control Plane
host: Running
kubelet: Running
apiserver: Running
kubeconfig: Configured
timeToStop: Nonexistent
```