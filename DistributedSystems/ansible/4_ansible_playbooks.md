# PlayBooks
* They are ansible orchestration language.
* Set of instructions written that we want ansible to do.(A list of dictionaries)
* Eg: 
- running a series of commands in sequence and restarting those servers in a particular order.
- deploying 100s of VMs in a public or private cloud infra, provisioning storage to VMs, setting up firewals.
* All playbooks are written in yaml format.
* A playbook is ayaml file containing a set of plays, a play is a set of activities to be run on a single or a group of hosts.
* A Task is a single action to be performed on host.(exec a command or script on host, shutdown, restart, installing a package)
**Note**
- Host you want to perform these operations against is ALWAYS set at play level
- We can have any host/group as "hosts:", just makesure any host or group is first defined in the inventory file. All connection information of the host is retrieved from the inventory file.

```yaml
-
   name: Play1
   hosts: localhost
   tasks:
    - name: Execute command 'date'
      command: date

    - name: Execute script on server
      script: test_script

    - name: Install httpd service
      yum:
       name: httpd
       state: present

    - name: Start web server
      service:
        name: httpd
        state: started 

```


## Modules:
The different actions run by Tasks are modules.
Eg: coomand, script, yum,service

## Running Ansible Playbook
- Execute Ansible Playbook Syntax:
```
ansible-playbook <playbook file name>
```
* To run Ansible:
```
ansible <hosts> -a <command>
ansible all -a "/sbin/reboot"

ansible <hosts> -m <module>
ansible target1 -m ping
```
* To run Ansible Playbook
```
ansible-playbook <playbook-name>
ansible-playbook playbook-server.yml
```

**Note:**
Ansible creates a group named "all" by default having all the hosts in our inventory file.

## Examples

Update the task to execute the command cat /etc/hosts and change task name to Execute a command to display hosts file
```
-
    name: 'Execute a command to display hosts file on localhost'
    hosts: localhost
    tasks:
        -
            name: 'Execute a date command'
            command: date

```

```
-
    name: 'Execute a command to display hosts file on localhost'
    hosts: localhost
    tasks:
        -
            name: 'Execute a command to display hosts file'
            command: 'cat /etc/hosts'

```
Update the playbook to add a second task. The new task must execute the command cat /etc/hosts and change new task name to Execute a command to display hosts file

```
-
    name: 'Execute two commands on localhost'
    hosts: localhost
    tasks:
        -
            name: 'Execute a date command'
            command: date

```
```
-
    name: 'Execute two commands on localhost'
    hosts: localhost
    tasks:
        -
            name: 'Execute a date command'
            command: date
        -
            name: 'Execute a command to display hosts file'
            command: 'cat /etc/hosts'

```
We have been running all tasks on localhost. We would now like to run these tasks on the web_node1. Update the play to run the tasks on web_node1.

```
-
    name: 'Execute two commands on localhost'
    hosts: localhost
    tasks:
        -
            name: 'Execute a date command'
            command: date
        -
            name: 'Execute a command to display hosts file'
            command: 'cat /etc/hosts'

```
```
-
    name: 'Execute two commands on web_node1'
    hosts: web_node1
    tasks:
        -
            name: 'Execute a date command'
            command: date
        -
            name: 'Execute a command to display hosts file'
            command: 'cat /etc/hosts'
```
Create a new play named Execute a command to display hosts file contents on web_node2 to execute cat /etc/hosts command on second node web_node2 and name the task Execute a command to display hosts file.


Refer to the attached inventory file

```
-
    name: 'Execute command to display date on web_node1'
    hosts: web_node1
    tasks:
        -
            name: 'Execute a date command'
            command: date

```
```
# Sample Inventory File

# Web Servers
sql_db1 ansible_host=sql01.xyz.com ansible_connection=ssh ansible_user=root ansible_ssh_pass=Lin$Pass
sql_db2 ansible_host=sql02.xyz.com ansible_connection=ssh ansible_user=root ansible_ssh_pass=Lin$Pass
web_node1 ansible_host=web01.xyz.com ansible_connection=ssh ansible_user=administrator ansible_ssh_pass=Win$Pass
web_node2 ansible_host=web02.xyz.com ansible_connection=ssh ansible_user=administrator ansible_ssh_pass=Win$Pass
web_node3 ansible_host=web03.xyz.com ansible_connection=ssh ansible_user=administrator ansible_ssh_pass=Win$Pass

[db_nodes]
sql_db1
sql_db2

[web_nodes]
web_node1
web_node2
web_node3

[boston_nodes]
sql_db1
web_node1

[dallas_nodes]
sql_db2
web_node2
web_node3

[us_nodes:children]
boston_nodes
dallas_nodes
```

```
-
    name: 'Execute command to display date on web_node1'
    hosts: web_node1
    tasks:
        -
            name: 'Execute a date command'
            command: date
-
    name: 'Execute a command to display hosts file contents on web_node2'
    hosts: web_node2
    tasks:
        -
            name: 'Execute a command to display hosts file'
            command: 'cat /etc/hosts'

```
You are assigned a task to restart a number of servers in a particular sequence. The sequence and the commands to be used are given below. Note that the commands should be run on respective servers only. Refer to the inventory file and update the playbook to create the below sequence.

Note: Use the description below to name the plays and tasks.

Stop the web services on web server nodes - service httpd stop
Shutdown the database services on db server nodes - service mysql stop
Restart all servers (web and db) at once - /sbin/shutdown -r
Start the database services on db server nodes - service mysql start
Start the web services on web server nodes - service httpd start
Warning: Do not use this playbook in a real setup. There are better ways to do these actions. This is only for simple practise.

```
-
    name: 'Stop the web services on web server nodes'
    hosts: web_nodes
    tasks:
        -
            name: 'Stop the web services on web server nodes'
            command: 'service httpd stop'

```
```

```