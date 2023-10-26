# Variables
* ansible_host, ansible_connection all are variables
* we can aslo define variables inside playbook too

```
-
  name: Add DNS server to resolv.conf
  hosts: localhost
  vars:
    dns_server: 10.1.250.10
  tasks:
      - lineinfile:
          path: /etc/resolv.comf
          line: 'nameserver 10.1.250.10'
```
* or a separate file for variables 
```
variable1: value1
variable2: value2 
```

## Using variable

```
-
  name: Add DNS server to resolv.conf
  hosts: localhost
  vars:
    dns_server: 10.1.250.10
  tasks:
      - lineinfile:
          path: /etc/resolv.comf
          line: 'nameserver {{ dns_server }}'
```

Example:
```
-
  name: Set Firewall Configuration
  hosts: web
  tasks:
  - firewalld:
      service: https
      permanent: true
      state: enabled

  - firewalld:
      port:8081/tcp
      permanent: true
      state: disabled

  - firewalld:
      port: 161-162/udp
      permanent: true
      state: disabled

  - firewalld:
      source: 192.0.2.0/24
      Zone: internal
      state: enabled
```
using variables from inventory file
```
# Sample Inventory File

Web http_port=8081 snmp_port=161-162 inter_ip_range=192.0.2.0
```
```
-
  name: Set Firewall Configuration
  hosts: web
  tasks:
  - firewalld:
      service: https
      permanent: true
      state: enabled

  - firewalld:
      port:'{{ http_port }}'/tcp
      permanent: true
      state: disabled

  - firewalld:
      port: '{{ snmp_port }}'/udp
      permanent: true
      state: disabled

  - firewalld:
      source: '{{ inter_ip_range }}'/24
      Zone: internal
      state: enabled

```
or a separate variale file (name of file: name of hosts)
```
# Sample variable file - web.yaml
http_port=8081
snmp_port=161-162
inter_ip_range=192.0.2.0
```
This using of variables {{ }} is called Jinja 2 Templating

**NOTE**
* Wrong: source: {{ http_port }}
* Right: source: '{{ http_port }}'
* Right: source: Something{{ http_port }}Something......