#!/bin/bash

mpd_script="${HOME}/.config/herbstluftwm/scripts/mpd.sh"

while true; do
    mpc status | grep "playing" 2> /dev/null
    if [ $? -eq 0 ]; then
        choice=$(echo -e "pause\njump\nartist\nalbum\ntrack\nload\nclear\nupdate\ntoggle" | dmenu -p "[>] $(mpc current -f "%title%")")
    else
        choice=$(echo -e "play\njump\nartist\nalbum\ntrack\nload\nclear\nupdate\ntoggle" | dmenu -p "[-] $(mpc current -f "%title%")")
    fi

    case $choice in
        play)
            mpc play
            ;;
        pause)
            mpc pause
            ;;
        jump)
            $mpd_script -j
            ;;
        artist)
            $mpd_script -a
            ;;
        album)
            $mpd_script -l
            ;;
        track)
            $mpd_script -t
            ;;
        load)
            $mpd_script -p
            ;;
        clear)
            mpc clear
            ;;
        update)
            mpc update
            ;;
        toggle)
            mpc status | grep "random: on" 2> /dev/null
            if [ $? -eq 0 ]; then random="?"; else random="-"; fi
            mpc status | grep "consume: on" 2> /dev/null
            if [ $? -eq 0 ]; then consume="X"; else consume="-"; fi
            mpc status | grep "repeat: on" 2> /dev/null
            if [ $? -eq 0 ]; then repeat="@"; else repeat="-"; fi

            option=$(echo -e "random\nconsume\nrepeat" | dmenu -p "[$random$consume$repeat]")

            case $option in
                random)
                    mpc random
                    ;;
                consume)
                    mpc consume
                    ;;
                repeat)
                    mpc repeat
                    ;;
            esac
            ;;
        *)
            echo 'Program terminated'
            break
        ;;
    esac
done
