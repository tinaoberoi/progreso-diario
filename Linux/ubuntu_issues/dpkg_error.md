# dpkg error processing packages

[Follow this link](https://askubuntu.com/questions/716915/dpkg-error-processing-packages-cannot-complete-install-desktop-gui-from-termina)

```bash
sudo apt-get autoremove
sudo apt-get --purge remove && sudo apt-get autoclean
sudo apt-get -f install
sudo apt-get update
sudo apt-get upgrade && sudo apt-get dist-upgrade
sudo dpkg-reconfigure -a
sudo dpkg --configure -a
```