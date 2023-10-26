# Conditional

```
- name: Install NGINX
  hosts: all
  tasks:
  - name: Install NGINX on Debian
    apt:
      name: nginx
      state: present
    when: ansible_os_family == "Debian" and
          ansible_distribution_version == "16.04"

   - name: Install NGINX on RedHat
     yum:
        name: nginx
        state: present
     when: ansible_os_family == "RedHat" or
           ansible_os_family == "SUSE"
```
we have a list of packages install the package only if required property is set to true
```
- name: Install Software
  hosts: all
  vars:
     packages:
        - name: nginx
          required: True
        - name: mysql
          required: True
        - name: apache
          required: False

  tasks:
  - name: Insta;; "{{ item. name }}" on Debian
    apt:
       name: "{{ item.name }}" 
       state: present
    when item.required == True
    loop: "{{ packages }}"
```