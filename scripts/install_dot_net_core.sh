#!/bin/bash
sudo apt update
# The official Microsoft package repo uses HTTPS to deliver the DEB packages for ubuntu, thus install apt-transport-https
sudo apt install -y apt-transport-https
# .NET Core also relies on universe package repository
echo "make sure Community-maintained free and open-source software (universe) is checked in Software & Updates app"
read -p "Checked?" -n 1 -r
if [[ ! $REPLY =~ ^[Yy]$ ]]
then
	exit 1
fi
echo "Checking usiveral package enabled"
egrep -r '^[ ^I]*[^#].*universe' /etc/apt/sources.list*

# Adding Microsoft Package Repository
sudo cd /tmp
wget -q https://packages.microsoft.com/config/ubuntu/18.04/
packages-microsoft-prod.deb
sudo apt-get install ./packages-microsoft-prod.deb
sudo apt update
sudo apt install dotnet-sdk-2.2
echo "Checking dotnet version"
dotnet --version