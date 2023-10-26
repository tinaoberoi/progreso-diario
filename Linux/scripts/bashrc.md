# How to Avoid Frustration After Forgetting To Use Sudo Command

Have you ever typed a command in your terminal, only to find out you forgot to prefix it with the sudo command? You have to retype the whole command again just to add the sudo in front of it. Frustrating!

Add the below line to .bashrc file

```bash
alias argh='sudo $(history -p \!\!)'
```

to reflect changes

```bash
source ~/.bashrc
```