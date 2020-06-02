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