# ~/.bashrc: executed by bash(1) for non-login shells.
# see /usr/share/doc/bash/examples/startup-files (in the package bash-doc)
# for examples

# If not running interactively, don't do anything
case $- in
    *i*) ;;
      *) return;;
esac

# don't put duplicate lines or lines starting with space in the history.
# See bash(1) for more options
HISTCONTROL=ignoreboth
# for setting history length see HISTSIZE and HISTFILESIZE in bash(1)
HISTSIZE=1000
HISTFILESIZE=2000

# append to the history file, don't overwrite it
shopt -s histappend
# check the window size after each command and, if necessary,
# update the values of LINES and COLUMNS.
shopt -s checkwinsize
# If set, the pattern "**" used in a pathname expansion context will
# match all files and zero or more directories and subdirectories.
#shopt -s globstar

# make less more friendly for non-text input files, see lesspipe(1)
[ -x /usr/bin/lesspipe ] && eval "$(SHELL=/bin/sh lesspipe)"

# Alias definitions.
if [ -f ~/.aliasrc ]; then
    . ~/.aliasrc
fi

# enable programmable completion features (you don't need to enable
# this, if it's already enabled in /etc/bash.bashrc and /etc/profile
# sources /etc/bash.bashrc).
if ! shopt -oq posix; then
  if [ -f /usr/share/bash-completion/bash_completion ]; then
    . /usr/share/bash-completion/bash_completion
  elif [ -f /etc/bash_completion ]; then
    . /etc/bash_completion
  fi
fi

# NNN CONFIG
export NNN_PLUG='d:dragdrop;i:imgur;n:nuke;p:preview-tabbed'
export NNN_FIFO='/tmp/nnn.fifo'
export NNN_OPENER='/home/ness/.config/nnn/plugins/nuke'
export NNN_BMS='d:/home/ness/Descargas;c:/home/ness/.config;p:/home/ness/proyectos'
export NNN_COLORS='#01040302;1432'
export NNN_FCOLORS='c1e2040a006033f7c6d6ab01'
export NNN_TMPFILE='/tmp/.lastd'
export NNN_OPTS='R'

# BASH PROMPT
color1=$(tput setaf 1)
color2=$(tput setaf 8)
bold=$(tput bold)
reset=$(tput sgr0)
export PS1="\n\[$bold$color1\]\W \[$bold$color2\];\[$reset\] "
