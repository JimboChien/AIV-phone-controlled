# =========================================
#  Author:        JimboChien
#  Date Created:  2020/08/21
#  Last Updated:  2021/03/12
#  Description:   run mjpg-streamer script
# =========================================

cd /home/pi/mjpg-streamer/mjpg-streamer
./mjpg_streamer [-b] -i "./input_uvc.so -y  -r QVGA -f 15" -o "./output_http.so -w ./www -p 8090"
