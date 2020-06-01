# Ansible Inventories
* Ansible can work with one or multiple systems at the same time.
* Inorder to work woth multiple servers, ansible needs to establish a connectivity to those servers.
* This can be done using SSH(in linux) or win rm (in windows), this is what makes ansible **agentless**. That is you dont need any aditional software on the target machine to work with ansible.
* The major disadvt of other orchestration tools is that you are required to configure an agent on the target systems before you can invoke any kind of automation.
* Information about these target systems is stored in **inventory file**.
* If you dont create a new inventory file Ansible uses default inventory file at 
```
/etc/ansible/hosts
```

## Inventory File
* Its simpley a number of servers listed one after the other

```yaml
server1.company.com
server2.company.com
```
* You can also group different servers together by defining it, under a name of group within (in sqaure brackets)

```yaml
[mail]
server3.company.com
server4.company.com
[db]
server5.company.com
server6.company.com
[web]
server7.company.com
server8.company.com
```
* Refer a number of servers using alias such as web server or db server
```yaml
web ansible_host=server1.company.com
db ansible_host=server2.company.com
mail ansible_host=server1.company.com
web2 ansible_host=server2.company.com
```
* ansible_host is parameter for defining FQDNs( A fully qualified domain name) or IP adress of host

* ansible_connection defines how ansible connects to the target server
```yaml
web ansible_host=server1.company.com ansible_connection=ssh
db ansible_host=server2.company.com ansible_connection=winrm
mail ansible_host=server1.company.com ansible_connection=ssh
web2 ansible_host=server2.company.com ansible_connection=winrm

localhost ansible_connection=localhost
```
* we can also set it to localhost to indicate that we would like to work with the localhost and not any remote hosts.

* ansible_ports define which port to connect to. By default it is 22 for SSH, but we can change it.
* ansible_user for user to make remote connections. By default set to root for linux but can be changed to admin

```yaml
web ansible_host=server1.company.com ansible_connection=ssh ansible_user=root
db ansible_host=server2.company.com ansible_connection=winrm ansible_user=admin
mail ansible_host=server1.company.com ansible_connection=ssh
web2 ansible_host=server2.company.com ansible_connection=winrm

localhost ansible_connection=localhost
```
* ansible_ssh_pass defines SSH password for Linux.

* Running Ansible cmmand
```
ansible <name of host> -m ping -i <inventory file>
```
This returns success and ensures a successful connectivity

**NoteStroting passwords in plain text not ideal. Best parctise is to set us SSH key based password auth system b/w the servers. ** 
