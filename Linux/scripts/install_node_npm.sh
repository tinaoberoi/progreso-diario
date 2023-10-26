#!/bin/bash
cd ~
curl -sL https://deb.nodesource.com/setup_10.x -o nodesource_setup.sh
sudo bash nodesource_setup.sh
echo "Installing nodejs"
sudo apt install nodejs
echo "Checking nodejs version"
nodejs -v
echo "Installing npm"
sudo apt install npm
echo "Checking npm version"
npm -v
