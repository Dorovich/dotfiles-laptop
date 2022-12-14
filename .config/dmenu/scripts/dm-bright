#!/bin/sh

while true; do
    choice=$(echo "+\n-" | dmenu -p "screen brightness:")
    case $choice in
        +)
            brightnessctl s +3
            ;;
        -)
            brightnessctl s 3-
            ;;
        *)
            break
            ;;
    esac
done
