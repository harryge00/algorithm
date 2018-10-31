## 1. Fix the cluster

```
# kubectl get node
NAME                            STATUS     ROLES     AGE       VERSION
ip-172-20-35-231.ec2.internal   NotReady   master    1d        v1.9.8
```

The Master node is `NotReady`. It seems like the kubelet is not running?

```
kubectl describe node ip-172-20-35-231.ec2.internal
Name:               ip-172-20-35-231.ec2.internal
Roles:              master
Labels:             beta.kubernetes.io/arch=amd64
                    beta.kubernetes.io/instance-type=t2.medium
                    beta.kubernetes.io/os=linux
                    failure-domain.beta.kubernetes.io/region=us-east-1
                    failure-domain.beta.kubernetes.io/zone=us-east-1a
                    kops.k8s.io/instancegroup=master-us-east-1a
                    kubernetes.io/hostname=ip-172-20-35-231.ec2.internal
                    kubernetes.io/role=master
                    node-role.kubernetes.io/master=
Annotations:        node.alpha.kubernetes.io/ttl=0
                    projectcalico.org/IPv4Address=172.20.35.231/19
                    volumes.kubernetes.io/controller-managed-attach-detach=true
Taints:             node-role.kubernetes.io/master:NoSchedule
CreationTimestamp:  Sat, 08 Sep 2018 01:14:10 +0800
Conditions:
  Type             Status    LastHeartbeatTime                 LastTransitionTime                Reason                     Message
  ----             ------    -----------------                 ------------------                ------                     -------
  OutOfDisk        False     Sat, 08 Sep 2018 01:49:14 +0800   Sat, 08 Sep 2018 01:14:10 +0800   KubeletHasSufficientDisk   kubelet has sufficient disk space available
  MemoryPressure   Unknown   Sat, 08 Sep 2018 01:49:14 +0800   Sat, 08 Sep 2018 01:51:09 +0800   NodeStatusUnknown          Kubelet stopped posting node status.
  DiskPressure     Unknown   Sat, 08 Sep 2018 01:49:14 +0800   Sat, 08 Sep 2018 01:51:09 +0800   NodeStatusUnknown          Kubelet stopped posting node status.
  Ready            Unknown   Sat, 08 Sep 2018 01:49:14 +0800   Sat, 08 Sep 2018 01:51:09 +0800   NodeStatusUnknown          Kubelet stopped posting node status.
Addresses:
  InternalIP:   172.20.35.231
  ExternalIP:   18.212.57.155
  InternalDNS:  ip-172-20-35-231.ec2.internal
  ExternalDNS:  ec2-18-212-57-155.compute-1.amazonaws.com
  Hostname:     ip-172-20-35-231.ec2.internal
Capacity:
 cpu:     2
 memory:  4049296Ki
 pods:    110
Allocatable:
 cpu:     2
 memory:  3946896Ki
 pods:    110
System Info:
 Machine ID:                 382a7b4d31764ae689851b2b2eaab848
 System UUID:                EC257EED-D9B6-133A-26F9-9BE81DA2CFD9
 Boot ID:                    270cf610-e3d6-4fb4-8e7c-e943f03c4873
 Kernel Version:             4.4.121-k8s
 OS Image:                   Debian GNU/Linux 8 (jessie)
 Operating System:           linux
 Architecture:               amd64
 Container Runtime Version:  docker://17.3.2
 Kubelet Version:            v1.9.8
 Kube-Proxy Version:         v1.9.8
PodCIDR:                     100.96.0.0/24
ExternalID:                  i-0176574f2ffca9e75
Non-terminated Pods:         (7 in total)
  Namespace                  Name                                                     CPU Requests  CPU Limits  Memory Requests  Memory Limits
  ---------                  ----                                                     ------------  ----------  ---------------  -------------
  kube-system                dns-controller-f94d5744-w89mw                            50m (2%)      0 (0%)      50Mi (1%)        0 (0%)
  kube-system                etcd-server-events-ip-172-20-35-231.ec2.internal         100m (5%)     0 (0%)      0 (0%)           0 (0%)
  kube-system                etcd-server-ip-172-20-35-231.ec2.internal                200m (10%)    0 (0%)      0 (0%)           0 (0%)
  kube-system                kube-apiserver-ip-172-20-35-231.ec2.internal             150m (7%)     0 (0%)      0 (0%)           0 (0%)
  kube-system                kube-controller-manager-ip-172-20-35-231.ec2.internal    100m (5%)     0 (0%)      0 (0%)           0 (0%)
  kube-system                kube-proxy-ip-172-20-35-231.ec2.internal                 100m (5%)     0 (0%)      0 (0%)           0 (0%)
  kube-system                kube-scheduler-ip-172-20-35-231.ec2.internal             100m (5%)     0 (0%)      0 (0%)           0 (0%)
Allocated resources:
  (Total limits may be over 100 percent, i.e., overcommitted.)
  CPU Requests  CPU Limits  Memory Requests  Memory Limits
  ------------  ----------  ---------------  -------------
  800m (40%)    0 (0%)      50Mi (1%)        0 (0%)
Events:
  Type    Reason                   Age   From                                    Message
  ----    ------                   ----  ----                                    -------
  Normal  Starting                 59m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
  Normal  NodeAllocatableEnforced  59m   kubelet, ip-172-20-35-231.ec2.internal  Updated Node Allocatable limit across pods
  Normal  Starting                 59m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
  Normal  Starting                 59m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
  Normal  Starting                 59m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
  Normal  Starting                 59m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
  Normal  NodeAllocatableEnforced  59m   kubelet, ip-172-20-35-231.ec2.internal  Updated Node Allocatable limit across pods
  Normal  Starting                 59m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
  Normal  Starting                 59m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
  Normal  Starting                 59m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
  Normal  Starting                 59m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
  Normal  Starting                 59m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
  Normal  Starting                 59m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
  Normal  NodeAllocatableEnforced  59m   kubelet, ip-172-20-35-231.ec2.internal  Updated Node Allocatable limit across pods
  Normal  Starting                 59m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
  Normal  Starting                 59m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
  Normal  Starting                 59m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
  Normal  Starting                 59m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
  Normal  Starting                 59m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
  Normal  Starting                 59m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
  Normal  Starting                 59m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
  Normal  Starting                 59m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
  Normal  Starting                 59m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
  Normal  Starting                 59m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
  Normal  NodeAllocatableEnforced  59m   kubelet, ip-172-20-35-231.ec2.internal  Updated Node Allocatable limit across pods
  Normal  Starting                 59m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
  Normal  NodeAllocatableEnforced  59m   kubelet, ip-172-20-35-231.ec2.internal  Updated Node Allocatable limit across pods
  Normal  Starting                 59m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
  Normal  Starting                 58m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
  Normal  Starting                 58m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
  Normal  Starting                 58m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
  Normal  Starting                 58m   kubelet, ip-172-20-35-231.ec2.internal  Starting kubelet.
```

The kubelet keep restarting. We have to ssh into the master.

After ssh into the master:
```
# systemctl status kubelet
● kubelet.service - Kubernetes Kubelet Server
   Loaded: loaded (/lib/systemd/system/kubelet.service; static)
   Active: activating (auto-restart) (Result: exit-code) since Sun 2018-09-09 13:12:00 UTC; 281ms ago
     Docs: https://github.com/kubernetes/kubernetes
  Process: 7359 ExecStart=/usr/local/bin/kubelet $DAEMON_ARGS (code=exited, status=255)
 Main PID: 7359 (code=exited, status=255)

Sep 09 13:12:00 ip-172-20-35-231 systemd[1]: kubelet.service: main process exited, code=exited, status=255/n/a
Sep 09 13:12:00 ip-172-20-35-231 systemd[1]: Unit kubelet.service entered failed state.


# journalctl -u kubelet --since="2018-09-09 13:00"
Sep 09 13:00:00 ip-172-20-35-231 kubelet[27240]: F0909 13:00:00.639458   27240 server.go:141] listen tcp 0.0.0.0:10250: bind: address already in use
Sep 09 13:00:00 ip-172-20-35-231 systemd[1]: kubelet.service: main process exited, code=exited, status=255/n/a
Sep 09 13:00:00 ip-172-20-35-231 systemd[1]: Unit kubelet.service entered failed state.
Sep 09 13:00:02 ip-172-20-35-231 systemd[1]: kubelet.service holdoff time over, scheduling restart.
```

We need to find out which process is using 10250:

```
# netstat -altup|grep 10250
tcp        0      0 localhost:10250         localhost:4001          ESTABLISHED 1104/kube-apiserver
tcp6       0      0 localhost:4001          localhost:10250         ESTABLISHED 1024/etcd
```

Kube-apiserver has already occupied 10250 port. We do not want to stop kube-apiserver. So try to make Kubelet use another port.
Add `--port=10259 --healthz-port=10245` to ``/etc/sysconfig/kubelet` and restart `kubelet.service`.

```
$ kubectl get node
NAME                            STATUS    ROLES     AGE       VERSION
ip-172-20-35-231.ec2.internal   Ready     master    2d        v1.9.8
ip-172-20-37-226.ec2.internal   Ready     node      2d        v1.9.8
```
Now the master kubelet is running.

We can also find there is no calico in kube-system and calico-config looks incorrect.

```
# Save the current calico-config to backup.yaml
kubectl get cm calico-config -o yaml -n kube-system > caclico-config.backup.yaml
# delete the calico-config
kubectl delete calico-config -n kube-system
# create calico controller and nodes
kubectl create -f calico.yaml
```

The calico.yaml is based on kops's template:
```
kind: ClusterRole
apiVersion: rbac.authorization.k8s.io/v1beta1
metadata:
  name: calico
  labels:
    role.kubernetes.io/networking: "1"
rules:
- apiGroups:
  - ""
  resources:
  - pods
  - namespaces
  - nodes
  verbs:
  - get
  - list
  - watch
- apiGroups:
  - extensions
  resources:
  - networkpolicies
  verbs:
  - get
  - list
  - watch

---

apiVersion: v1
kind: ServiceAccount
metadata:
  name: calico
  namespace: kube-system
  labels:
    role.kubernetes.io/networking: "1"
---

kind: ClusterRoleBinding
apiVersion: rbac.authorization.k8s.io/v1beta1
metadata:
  name: calico
  labels:
    role.kubernetes.io/networking: "1"
roleRef:
  apiGroup: rbac.authorization.k8s.io
  kind: ClusterRole
  name: calico
subjects:
- kind: ServiceAccount
  name: calico
  namespace: kube-system
---
apiVersion: v1
data:
  calico_backend: bird
  cni_network_config: |-
    {
      "name": "k8s-pod-network",
      "cniVersion": "0.3.0",
      "plugins": [
        {
          "type": "calico",
          "etcd_endpoints": "__ETCD_ENDPOINTS__",
          "log_level": "info",
          "ipam": {
            "type": "calico-ipam"
          },
          "policy": {
            "type": "k8s",
            "k8s_api_root": "https://__KUBERNETES_SERVICE_HOST__:__KUBERNETES_SERVICE_PORT__",
            "k8s_auth_token": "__SERVICEACCOUNT_TOKEN__"
          },
          "kubernetes": {
            "kubeconfig": "/etc/cni/net.d/__KUBECONFIG_FILENAME__"
          }
        },
        {
          "type": "portmap",
          "snat": true,
          "capabilities": {"portMappings": true}
        }
      ]
    }
  etcd_endpoints: http://etcd-a.internal.hge.hiring.usehurrier.com:4001
kind: ConfigMap
metadata:
  annotations:
  name: calico-config
  namespace: kube-system
---
apiVersion: extensions/v1beta1
kind: Deployment
metadata:
  name: calico-kube-controllers
  namespace: kube-system
  labels:
    k8s-app: calico-kube-controllers
    role.kubernetes.io/networking: "1"
spec:
  # The controllers can only have a single active instance.
  replicas: 1
  template:
    metadata:
      name: calico-kube-controllers
      namespace: kube-system
      labels:
        k8s-app: calico-kube-controllers
        role.kubernetes.io/networking: "1"
      annotations:
        scheduler.alpha.kubernetes.io/critical-pod: ''
    spec:
      # The controllers must run in the host network namespace so that
      # it isn't governed by policy that would prevent it from working.
      hostNetwork: true
      serviceAccountName: calico
      tolerations:
      - key: node-role.kubernetes.io/master
        effect: NoSchedule
      - key: CriticalAddonsOnly
        operator: Exists
      containers:
        - name: calico-kube-controllers
          image: quay.io/calico/kube-controllers:v1.0.3
          resources:
            requests:
              cpu: 10m
          env:
            # By default only policy, profile, workloadendpoint are turned
            # on, node controller will decommission nodes that do not exist anymore
            # this and CALICO_K8S_NODE_REF in calico-node fixes #3224, but invalid nodes that are
            # already registered in calico needs to be deleted manually, see
            # https://docs.projectcalico.org/v2.6/usage/decommissioning-a-node
            - name: ENABLED_CONTROLLERS
              value: policy,profile,workloadendpoint,node
            # The location of the Calico etcd cluster.
            - name: ETCD_ENDPOINTS
              valueFrom:
                configMapKeyRef:
                  name: calico-config
                  key: etcd_endpoints
      volumes:
        - name: etc-hosts
          hostPath:
            path: /etc/hosts
---
# This manifest installs the calico/node container, as well
# as the Calico CNI plugins and network config on
# each master and worker node in a Kubernetes cluster.
kind: DaemonSet
apiVersion: extensions/v1beta1
metadata:
  name: calico-node
  namespace: kube-system
  labels:
    k8s-app: calico-node
    role.kubernetes.io/networking: "1"
spec:
  selector:
    matchLabels:
      k8s-app: calico-node
  updateStrategy:
    rollingUpdate:
      maxUnavailable: 1
    type: RollingUpdate
  template:
    metadata:
      labels:
        k8s-app: calico-node
        role.kubernetes.io/networking: "1"
      annotations:
        scheduler.alpha.kubernetes.io/critical-pod: ''
    spec:
      hostNetwork: true
      serviceAccountName: calico
      tolerations:
      - key: CriticalAddonsOnly
        operator: Exists
      - effect: NoExecute
        operator: Exists
      - effect: NoSchedule
        operator: Exists
      # Minimize downtime during a rolling upgrade or deletion; tell Kubernetes to do a "force
      # deletion": https://kubernetes.io/docs/concepts/workloads/pods/pod/#termination-of-pods.
      terminationGracePeriodSeconds: 0
      containers:
        # Runs calico/node container on each Kubernetes node.  This
        # container programs network policy and routes on each
        # host.
        - name: calico-node
          image: quay.io/calico/node:v2.6.7
          resources:
            requests:
              cpu: 10m
          env:
            # The location of the Calico etcd cluster.
            - name: ETCD_ENDPOINTS
              valueFrom:
                configMapKeyRef:
                  name: calico-config
                  key: etcd_endpoints
            # Enable BGP.  Disable to enforce policy only.
            - name: CALICO_NETWORKING_BACKEND
              valueFrom:
                configMapKeyRef:
                  name: calico-config
                  key: calico_backend
            # Configure the IP Pool from which Pod IPs will be chosen.
            - name: CALICO_IPV4POOL_CIDR
              value: 100.96.0.0/11
            - name: CALICO_IPV4POOL_IPIP
              value: always
            - name: CLUSTER_TYPE
              value: kops,bgp
            - name: CALICO_DISABLE_FILE_LOGGING
              value: "true"
            - name: CALICO_K8S_NODE_REF
              valueFrom:
                fieldRef:
                  apiVersion: v1
                  fieldPath: spec.nodeName
            - name: IP
            - name: FELIX_IPV6SUPPORT
              value: "false"
            - name: FELIX_LOGSEVERITYSCREEN
              value: info
            - name: FELIX_PROMETHEUSMETRICSENABLED
              value: "false"
            - name: FELIX_PROMETHEUSMETRICSPORT
              value: "9091"
            - name: FELIX_PROMETHEUSGOMETRICSENABLED
              value: "true"
            - name: FELIX_PROMETHEUSPROCESSMETRICSENABLED
              value: "true"
            - name: FELIX_HEALTHENABLED
              value: "true"
          securityContext:
            privileged: true
          volumeMounts:
            - mountPath: /lib/modules
              name: lib-modules
              readOnly: true
            - mountPath: /var/run/calico
              name: var-run-calico
              readOnly: false
            # Necessary for gossip based DNS
            - mountPath: /etc/hosts
              name: etc-hosts
              readOnly: true
        # This container installs the Calico CNI binaries
        # and CNI network config file on each node.
        - name: install-cni
          image: quay.io/calico/cni:v1.11.2
          resources:
            requests:
              cpu: 10m
          imagePullPolicy: Always
          command: ["/install-cni.sh"]
          env:
            # The name of calico config file
            - name: CNI_CONF_NAME
              value: 10-calico.conflist
            # The location of the Calico etcd cluster.
            - name: ETCD_ENDPOINTS
              valueFrom:
                configMapKeyRef:
                  name: calico-config
                  key: etcd_endpoints
            # The CNI network config to install on each node.
            - name: CNI_NETWORK_CONFIG
              valueFrom:
                configMapKeyRef:
                  name: calico-config
                  key: cni_network_config
          volumeMounts:
            - mountPath: /host/opt/cni/bin
              name: cni-bin-dir
            - mountPath: /host/etc/cni/net.d
              name: cni-net-dir
            # Necessary for gossip based DNS
            - mountPath: /etc/hosts
              name: etc-hosts
              readOnly: true
      volumes:
        # Used by calico/node.
        - name: lib-modules
          hostPath:
            path: /lib/modules
        - name: var-run-calico
          hostPath:
            path: /var/run/calico
        # Used to install CNI.
        - name: cni-bin-dir
          hostPath:
            path: /opt/cni/bin
        - name: cni-net-dir
          hostPath:
            path: /etc/cni/net.d
        - name: etc-hosts
          hostPath:
            path: /etc/hosts
```
Now calico is running.
We can find `kubedns` is `CrashBackoff` and serviceAccount kube-dns is missing. Create sa:
```
apiVersion: v1
kind: ServiceAccount
metadata:
  name: kube-dns
  namespace: kube-system
```
And delete `kubedns` pods, new pods will work. We can check by `nslookup nginx` in pods running in default namespace.


## 2. Fix Credentials

After the calico works, delete the old dashboard and the new pod is running. But we need ingress or ELB to visit dashboard from external browser. I create a service with ELB:
```
apiVersion: v1
kind: Service
metadata:
  name: my-dashboard
  namespace: kube-system
  annotations:
    external-dns.alpha.kubernetes.io/hostname: mydashboard.hge.hiring.usehurrier.com.
spec:
  type: LoadBalancer
  ports:
  - port: 443
    protocol: TCP
    targetPort: 8443
  selector:
    k8s-app: kubernetes-dashboard
```

Then visit `mydashboard.hge.hiring.usehurrier.com` and login with token from secrets. 
And it seems like the role `kubernetes-dashboard-minimal` has limited apiGroups and only works in kube-system.
```
$ kubectl get role -n kube-system  kubernetes-dashboard-minimal -o yaml
```

So bind `cluster-admin` to the `kube-system:kubernetes-dashboard`

```
kubectl create clusterrolebinding kubernetes-dashboard -n kube-system --clusterrole=cluster-admin --serviceaccount=kube-system:kubernetes-dashboard
```

## 3. Deploy a wordpress exposing the service with Nginx-Ingress controller
Install helm first:
```
helm init
```
Update RBAC:
```
kubectl create serviceaccount --namespace kube-system tiller
kubectl create clusterrolebinding tiller-cluster-rule --clusterrole=cluster-admin --serviceaccount=kube-system:tiller
kubectl patch deploy --namespace kube-system tiller-deploy -p '{"spec":{"template":{"spec":{"serviceAccount":"tiller"}}}}'
helm init --service-account tiller --upgrade
```

Install Nginx-ingress
```
helm install stable/nginx-ingress --name my-nginx-ingress
```
We need to annotate the ingress-controller service to make externalDNS work:
```
kubectl annotate service my-nginx-ingress-controller external-dns.alpha.kubernetes.io/hostname=hge.hiring.usehurrier.com
```

Install worldpress
```
helm install --name wordpress2 \
  --set wordpressUsername=user,wordpressPassword=OQMRfNAk6G,mariadb.mariadbRootPassword=secretpassword,ingress.enabled=true,ingress.hosts[0].name=wordpress2.hge.hiring.usehurrier.com stable/wordpress
```
wordpress login: user: OQMRfNAk6G
