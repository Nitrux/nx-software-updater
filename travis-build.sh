export TZ=Asia/Kolkata

apt-get --yes update
apt-get --yes install wget

### Add KDENeon Repository
echo 'deb http://archive.neon.kde.org/dev/stable/ bionic main' | tee /etc/apt/sources.list.d/neon-stable.list
wget -qO - 'http://archive.neon.kde.org/public.key' | apt-key add -

### Install Dependencies
apt-get -yes update
apt-get --yes dist-upgrade
apt-get --yes install cmake extra-cmake-modules build-essential automake autotools-dev g++ qtdeclarative5-dev-tools qml-module-qtgraphicaleffects plasma-framework-dev qtbase5-dev qtdeclarative5-dev libqt5xmlpatterns5-dev libkf5* gettext

### Build Deb
debuild -b -us -uc