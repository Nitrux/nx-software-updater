export TZ=Asia/Kolkata

apt-get --yes update
apt-get --yes install wget

### Add KDENeon Repository
echo 'deb http://archive.neon.kde.org/dev/stable/ bionic main' | tee /etc/apt/sources.list.d/neon-stable.list
wget -qO - 'http://archive.neon.kde.org/public.key' | apt-key add -

### Install Dependencies
apt-get -yes update
apt-get --yes dist-upgrade
apt-get --yes install cmake extra-cmake-modules build-essential automake autotools-dev g++ debhelper qtbase5-dev qtdeclarative5-dev libkf5auth-dev libkf5coreaddons-dev libkf5kcmutils-dev libkf5i18n-dev libkf5plasma-dev libkf5kdelibs4support-dev libkf5declarative-dev

### Build Deb
debuild -b -us -uc