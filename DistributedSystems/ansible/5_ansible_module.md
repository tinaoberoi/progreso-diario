# Modules

* Ansible modules are categorised into various groups based on their functionality.
- *system* actions performed at system level like user, group, hostname, iptables, ping
- *commands* used to exec commands or scripts on a host like raw, shell, script
- *files* work with files (ACL module to send and retrieve ACL info on files, use the archive to pack and unpack files, )
- *database* working with databases to add or remove databases(mysql, momgodb, etc)
- *cloud* (Amazon, Azure, Docker, Google, etc) alows to create and destroy instances, performing configuration changes in networking and security management, managing containers, datacentres
- *windows* (win_copy, win_command)


## command
* *chdir*: cd into dir before running command
* *creates*: a filename if already exists this step wont run
* *executable*: change the shell used to execute the comand. Should be an absolute path to the execuatble.
* *free_form* the command module takes a free form command to run. There is no parameter actually named 'free form'. In contrast to command, copy requires src and dest to be specified not free_form.
* *removes*: a filename, when it does not exist this step wont run.
* *warn*: if command warnings are on in ansible.cfg, don not warn about this particular line if set to no/false

```
-
   name: Play1
   hosts: localhost
   tasks:
    - name: Execute command 'date'
      command: date
    - name: Display resolv.conf contents
      command: cat /etc/resolv.conf
    - name: Display resolv.conf contents
      command: cat resolv.conf chdir=/etc
    - name: Display resolv.conf contents
      command: mkdir /folder creates=/folder
```

## script
* Runs a local script on remote node after transfering it.
* To run the script on 100s of servers you dont have to copy it over 100s of servers, ansible takes care of
- automatically copying the script to remote node
- then executing them on remote systems

```
-
  name: Play1
  hosts: localhost
  tasks:
   - name: Run a script on remote server
     script: /some/local/script.sh -arg1 -arg2
```

## Service
* Manage services start, stop and restart
* In the eg we start the db service, using service module 
* Then the service module unlike the prev modules don not have a free form input which means you have to pass input in a key value pair format
There are 2 ways:
```
-
  name: Start Services in order
  hosts: localhost
  tasks:
   - name: Start the database service
     service: name=postgresql state= started
```
or dict/map format

```
-
  name: Start Services in order
  hosts: localhost
  tasks:
   - name: Start the database service
     service:
       name: postgresql
       state: started
```
**In yaml, name and state are properties of service**
```
-
  name: Start Services in order
  hosts: localhost
  tasks:
   - name: Start the database service
     service: name=postgresql state= started
   
   - name: Start the httpd service
     service: name=httpd state= started

   - name: Start the nginx service
     service:
        name: nginx
        started
```

Why the action is "started" and not "start" ?
>> we are not instructing ansible to start the service httpd but to ensure that httpd is started

- if httpd is not already started => start it
- if httpd is already started => do nothing

This is called Idempotency, An operation is idempotent if the result of performing it once is exactly the sane as the result of performing it repeatedly without any intervening actions.

## lineinfile

* search for a line in a file and replace it or add it if it doesnt exist

* Eg: Add a new server in the /etc/resolv.conf file

```
# /etc/resolv.conf

nameserver 10.1.250.1
nameserver 10.1.250.2
```
```
#playbook.yml to add another dns server

-
   name: Add DNS server to resolv.conf
   hosts: localhost
   tasks:
    - lineinfile:
         path: /etc/resolv.conf
         line: 'nameserver 10.1.250.10' 
```
playbook.yml achives idempotency, whereas the echo cmmand will add the same line each time if repeated

```
echo "nameserver 10.1.250.10" >> /etc/resolv.conf
```


## Excercises

Update the playbook with a play to Execute a script on all web server nodes. The script is located at /tmp/install_script.sh

```
-
    name: 'Execute a script on all web server nodes'
    hosts: web_nodes
    tasks:
        -
            name: 'Execute a script on all web server nodes'
            script: /tmp/install_script.sh

```

Update the playbook to add a new task to start httpd services on all web nodes
```
-
    name: 'Execute a script on all web server nodes'
    hosts: web_nodes
    tasks:
        -
            name: 'Execute a script on all web server nodes'
            script: /tmp/install_script.sh

```
```
-
    name: 'Execute a script on all web server nodes'
    hosts: web_nodes
    tasks:
        -
            name: 'Execute a script'
            script: /tmp/install_script.sh
        -
            name: 'Start httpd service'
            service: 'name=httpd state=started'

```
Update the playbook to add a new task in the beginning to add an entry into /etc/resolv.conf file for hosts. The line to be added is nameserver 10.1.250.10


Note: The new task must be executed first, so place it accordingly.

```
-
    name: 'Execute a script on all web server nodes'
    hosts: web_nodes
    tasks:
        -
            name: 'Execute a script'
            script: /tmp/install_script.sh
        -
            name: 'Start httpd service'
            service:
                name: httpd
                state: present

```

```
-
    name: 'Execute a script on all web server nodes'
    hosts: web_nodes
    tasks:
        -
            lineinfile:
               path: /etc/resolv.conf
               line: 'nameserver 10.1.250.10'
            
        -
            name: 'Execute a script'
            script: /tmp/install_script.sh
        -
            name: 'Start httpd service'
            service:
                name: httpd
                state: present

```
Update the playbook to add a new task at second position (right after adding entry to resolv.conf) to create a new web user.


Use the user module for this. User details to be used are given below:
Username: web_user
uid: 1040
group: developers

```
-
    name: 'Execute a script on all web server nodes and start httpd service'
    hosts: web_nodes
    tasks:
        -
            name: 'Update entry into /etc/resolv.conf'
            lineinfile:
                path: /etc/resolv.conf
                line: 'nameserver 10.1.250.10'
        -
            name: 'Execute a script'
            script: /tmp/install_script.sh
        -
            name: 'Start httpd service'
            service:
                name: httpd
                state: present

```
```
-
    name: 'Execute a script on all web server nodes and start httpd service'
    hosts: web_nodes
    tasks:
        -
            name: 'Update entry into /etc/resolv.conf'
            lineinfile:
                path: /etc/resolv.conf
                line: 'nameserver 10.1.250.10'
                
        -   
            name: 'Create a new web user'
            user:
              name: web_user
              uid: 1040
              group: developers
        -
            name: 'Execute a script'
            script: /tmp/install_script.sh
        -
            name: 'Start httpd service'
            service:
                name: httpd
                state: present
```