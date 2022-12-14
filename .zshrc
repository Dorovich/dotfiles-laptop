# export
export EDITOR="nvim"
export PATH="${PATH}:${HOME}/Applications:${HOME}/.local/bin"
if [ -n "$DISPLAY" ]; then
    export BROWSER="firefox"
else
    export BROWSER="links"
fi
export HISTSIZE=1000
export SAVEHIST=1000
export HISTFILE=~/.zsh_history
export BROWSER=vimb
export JavaScriptCoreUseJIT="0"
export WEBKIT_DISABLE_COMPOSITING_MODE=1

export NNN_PLUG='d:dragdrop;i:imgur;n:nuke;p:preview-tabbed'
export NNN_FIFO='/tmp/nnn.fifo'
export NNN_OPENER='/home/ness/.config/nnn/plugins/nuke'
export NNN_BMS='d:/home/ness/Descargas;c:/home/ness/.config;p:/home/ness/proyectos'
export NNN_COLORS='#01040302;1432'
export NNN_FCOLORS='c1e2040a006033f7c6d6ab01'
export NNN_TMPFILE='/tmp/.lastd'
export NNN_OPTS='R'

# alias
alias cl="clear"
alias rm="rm -I"
alias mv="mv -i"
alias ls="ls -F --color"
alias la="ls -FA --color"
alias vim="nvim"
alias v="nvim"
alias fetch="neofetch --ascii_distro linuxmint_small --config $HOME/.config/neofetch/config.conf"
alias mp="ncmpcpp"
alias clean="bleachbit -c --preset"
alias fullclean="clean && sudo bleachbit -c --preset"

alias aptup="sudo apt update && sudo apt upgrade"
alias aptupd="sudo apt update"
alias aptupg="sudo apt upgrade"
alias aptin="sudo apt install"
alias aptrm="sudo apt remove"
alias aptar="sudo apt autoremove"

alias config="/usr/bin/git --git-dir=$HOME/dotfiles/ --work-tree=$HOME"
alias configa="config add"
alias configd="config diff"
alias configs="config status"
alias configp="config push"
alias configpl="config pull"
alias configr="config rm -r"
alias configl='config log --pretty=format:"%C(magenta)%h%Creset -%C(red)%d%Creset %s %C(dim green)(%cr) [%an]" --abbrev-commit -30'

configc() {
    config commit -a -m "$*"
}

# compilador de C++ para PRO1:
alias p1++="g++ -ansi -O2 -DNDEBUG -D_GLIBCXX_DEBUG -Wall -Wextra -Werror -Wno-sign-compare -Wshadow"
# compilador de C++ para PRO2:
alias p2++="g++ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11"

# config tableta wacom
alias wacom-osu='xsetwacom --set "Wacom Intuos PT S 2 Pen stylus" Area 5167 3167 9133 6333'
alias wacom-reset='xsetwacom --set "Wacom Intuos PT S 2 Pen stylus" ResetArea'

0file() { curl -F"file=@$1" https://envs.sh ; }
0pb() { curl -F"file=@-;" https://envs.sh ; }
0url() { curl -F"url=$1" https://envs.sh ; }
0short() { curl -F"shorten=$1" https://envs.sh ; }

setopt histignorealldups sharehistory

# Use modern completion system
autoload -Uz compinit
compinit

zstyle ':completion:*' auto-description 'specify: %d'
zstyle ':completion:*' completer _expand _complete _correct _approximate
zstyle ':completion:*' format 'Completing %d'
zstyle ':completion:*' group-name ''
zstyle ':completion:*' menu select=2
eval "$(dircolors -b)"
zstyle ':completion:*:default' list-colors ${(s.:.)LS_COLORS}
zstyle ':completion:*' list-colors ''
zstyle ':completion:*' list-prompt %SAt %p: Hit TAB for more, or the character to insert%s
zstyle ':completion:*' matcher-list '' 'm:{a-z}={A-Z}' 'm:{a-zA-Z}={A-Za-z}' 'r:|[._-]=* r:|=* l:|=*'
zstyle ':completion:*' menu select=long
zstyle ':completion:*' select-prompt %SScrolling active: current selection at %p%s
zstyle ':completion:*' use-compctl false
zstyle ':completion:*' verbose true

zstyle ':completion:*:*:kill:*:processes' list-colors '=(#b) #([0-9]#)*=0=01;31'
zstyle ':completion:*:kill:*' command 'ps -u $USER -o pid,%cpu,tty,cputime,cmd'

source ~/.zsh/zsh-autosuggestions/zsh-autosuggestions.zsh

export PS1="
%B%F{red}%1~%f%b "
