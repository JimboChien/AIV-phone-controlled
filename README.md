# A.I.V 模擬智慧車 - 手機控制

## 📦 Installation

1. 將專案下載及更新
    ```sh
    $ git clone https://github.com/JimboChien/AIV-phone-controlled.git
    ```

2. 更新樹莓派 <img src="https://cdn.iconscout.com/icon/free/png-256/raspberry-pi-3-569254.png" width="20" height="20" />
    ```sh
    $ sudo apt-get update
    ```

## <img src="https://cdn.iconscout.com/icon/free/png-256/arduino-4-569256.png" width="40" height="40" />Arduino

Arduino 相關程式在 `Arduino` 資料夾下：
| 名稱            | 說明                         |
| :-------------: | :--------------------------  |
| ir_distance     | 紅外線偵測距離               |
| control_servo   | 控制車子行走                 |
| avoid_obstacles | 結合紅外線偵測及控制車子行走 |

## <img src="https://cdn.iconscout.com/icon/free/png-256/webcam-2044033-1724880.png" width="40" height="40" />Webcam

1. 透過 `mjpg_streamer_setup.sh` 檔安裝相關套件

    ```shell
    $ ./mjpg_streamer_setup.sh
    ```
    
2. 啟動 webcam

    ```shell
    $ ./webcam_sh.up
    ```

3. 開啟瀏覽器，輸入 localhost:8090

## 📱 手機控制
1. 啟動 webcam 

    ```shell
    $ ./webcam_sh.up
    ```
    
2. 啟動 Socket Server

    ```shell
    $ python3 phone_control_server
    ```
    
3. 打開 Android 手機<img src="https://cdn.iconscout.com/icon/free/png-256/android-247-1175275.png" width="20" height="20" />下載專用 app<img src="https://i.imgur.com/17YORkW.png" width="20" height="20" />

4. 進入 app 後打開右上角設定⚙︎，輸入樹莓派<img src="https://cdn.iconscout.com/icon/free/png-256/raspberry-pi-3-569254.png" width="20" height="20" />IP位置
