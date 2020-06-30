# Loops in Ansible

loop is a looping directive that executes the same task multiple number of times, each time it runs it stores the value of each item in the loop in a variable named item so you can simply replace the user name 

```
-
  name: Create users
  hosts: localhost
  tasks:
   - user: name=joe     state=present
   - user: name=george  state=present
   - user: name=ravi    state=present
   - user: name=kiran   state=present
   - user: name=mike    state=present
   - user: name=rani    state=present
```

```
-
  name: Create users
  hosts: localhost
  tasks:
   - user: name='{{ item }}'  state=present
     loop:
       - george
       - ravi
       - kiran
       - mike
       - rani
```
**See video**