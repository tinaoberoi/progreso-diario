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


## Excerises:

Ansible Inventory
The web servers are linux, but the db server is windows. Add additional parameters in each line to add ansible_connection, ansible_user and password. Use the below table for information about credentials.


Alias	Host	Connection	User	Password
web1	server1.company.com	SSH	root	Password123!
web2	server2.company.com	SSH	root	Password123!
web3	server3.company.com	SSH	root	Password123!
db1	server4.company.com	Windows	administrator	Password123!

```yaml
# Sample Inventory File

# Web Servers
web1 ansible_host=server1.company.com ansible_connection=ssh ansible_user=root ansible_ssh_pass=Password123!
web2 ansible_host=server2.company.com ansible_connection=ssh ansible_user=root ansible_ssh_pass=Password123!
web3 ansible_host=server3.company.com ansible_connection=ssh ansible_user=root ansible_ssh_pass=Password123!

# Database Servers
db1 ansible_host=server4.company.com ansible_connection=winrm ansible_user=administrator ansible_password=Password123!
```

We have created a group for web servers. Similarly create a group for database servers named db_servers and add db1 server to it.
```
# Sample Inventory File

# Web Servers
web1 ansible_host=server1.company.com ansible_connection=ssh ansible_user=root ansible_ssh_pass=Password123!
web2 ansible_host=server2.company.com ansible_connection=ssh ansible_user=root ansible_ssh_pass=Password123!
web3 ansible_host=server3.company.com ansible_connection=ssh ansible_user=root ansible_ssh_pass=Password123!

# Database Servers
db1 ansible_host=server4.company.com ansible_connection=winrm ansible_user=administrator ansible_password=Password123!

[web_servers]
web1
web2
web3
```
```
# Sample Inventory File

# Web Servers
web1 ansible_host=server1.company.com ansible_connection=ssh ansible_user=root ansible_ssh_pass=Password123!
web2 ansible_host=server2.company.com ansible_connection=ssh ansible_user=root ansible_ssh_pass=Password123!
web3 ansible_host=server3.company.com ansible_connection=ssh ansible_user=root ansible_ssh_pass=Password123!

# Database Servers
db1 ansible_host=server4.company.com ansible_connection=winrm ansible_user=administrator ansible_password=Password123!


[web_servers]
web1
web2
web3

[db_servers]
db1
```

Let us now create a group of groups. Create a new group called all_servers and add the previously created groups web_servers and db_servers to it.


Note: Syntax:
[parent_group:children]
child_group1
child_group2

```
# Sample Inventory File

# Web Servers
web1 ansible_host=server1.company.com ansible_connection=ssh ansible_user=root ansible_ssh_pass=Password123!
web2 ansible_host=server2.company.com ansible_connection=ssh ansible_user=root ansible_ssh_pass=Password123!
web3 ansible_host=server3.company.com ansible_connection=ssh ansible_user=root ansible_ssh_pass=Password123!

# Database Servers
db1 ansible_host=server4.company.com ansible_connection=winrm ansible_user=administrator ansible_password=Password123!


[web_servers]
web1
web2
web3

[db_servers]
db1

[all_servers:children]
web_servers
db_servers
```