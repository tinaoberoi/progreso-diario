# Introduction To Ansible

* We are involved in daily repetetive tasks like:
- Provisioning: sizing and creating new VMs everyday
- Configuration Management: applying configurations on them
- Continous Delievery: patching in hundreds of servers
- Application Deployment: deploying applications
- Security: performing security and compliance audits

These involve various lines of codes, rebooting servers etc. 
Solutions:
1. Creating Scripts (require time, coding skills, Maintainence)
2. Ansible (IT Automation Tool which is simple, powerfull and agentless)

Earlier which required complex scripts now require just few instructions with ansible.

Example: Imagine you have a number of hosts in your environment that you would like to restart in particular order. Some of them are web servers and others are database servers. You would like to power down web servers first then db servers. The again power up the db servers and then the web servers. --> few lines of Ansible code could make this do for you.

Example: Consider setting up a complaex infrastrcuture that spans across public and private clouds and includes 100s of vms.
(With Ansible we can provision VMs on public clouds like Amazon and also private clouds like Vmware.)
Moving on we can configure applications on these VMs, setting up communication between them such as modifying config files installing applications, configuring firewalls rules etc. Ansible built in modules support these operations.
It is easy to integrate Ansible to your environment to pull information to be be used in the automation environment, to pull information to be used in the automation process such as data from Database to get list of VMs, or trigger automation when a workflow gets approved.