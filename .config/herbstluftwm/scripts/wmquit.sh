#!/bin/sh

confirmation=$(echo "NO\nYES" | dmenu -i -p "Do you really want to quit?")

case $confirmation in
    "YES")
        herbstclient quit
        ;;
    *)
        exit
        ;;
esac
