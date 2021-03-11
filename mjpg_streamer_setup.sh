# =======================================
#  Author:	  KanKunI
#  Date Created:  2020/08/21
#  Last Updated:  2020/08/23
#  Description:   install mjpg-streamer
# =======================================

echo "[+] start to setup"

# install dependency package
yes | sudo apt-get install subversion libjpeg8-dev imagemagick libv4l-dev

# install mjpg-streamer module
cd ~

svn co https://svn.code.sf.net/p/mjpg-streamer/code/ mjpg-streamer &&\
cd ./mjpg-streamer/mjpg-streamer &&\
sed -i 's/#include <linux\/stat\.h>/\/\/#include <linux\/stat\.h>/' utils.c
sed -i 's/#include <sys\/stat\.h>/\/\/#include <sys\/stat\.h>/' utils.c
make clean all

echo "[+] mjpg-streamer setup complete"
