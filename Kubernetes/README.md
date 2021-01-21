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

**DON'T PUT CREDENCIALS IN THE CONFIGMAP!!!**

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

**IT IS MORE DIFFICULT TO WORK THAN DEPLOYMENT! THAT'S WHY IS MORE COMMON TO WORK WWITH EXTERNAL DB!!!**

