FROM debian:trixie

RUN apt-get update && apt-get install -y \
    build-essential \
    curl \
    zsh

RUN chsh -s ~bin/zsh
RUN echo ~/.zshrc | awk '{sub(/^ZSH_THEME="\w+"$/, "ZSH_THEME=\"ys\"")}'
