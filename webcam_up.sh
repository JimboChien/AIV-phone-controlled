# =========================================
#  Author:        KanKunI
#  Date Created:  2020/08/21
#  Last Updated:  2020/08/23
#  Description:   run mjpg-streamer script
# =========================================

cd /home/pi/mjpg-streamer/mjpg-streamer
./mjpg_streamer [-b] -i "./input_uvc.so -y  -r QVGA -f 15" -o "./output_http.so -w ./www -p 8090"
