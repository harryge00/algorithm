"annotations": {
    "ips": "10.0.0.3",
    "mask": "24",
    "interface": "eth2"
    "routes": ["192.168.1.0/16"]
}

# ip addr
2: eth2: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc noqueue state UP 
    link/ether 02:42:0a:1e:62:1b brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.3/24 scope global eth2
       valid_lft forever preferred_lft forever
# ip route
10.0.0.0/24 dev eth2  proto kernel  scope link  src 10.0.0.3 
172.25.0.0/16 via 10.0.0.1 dev eth1 