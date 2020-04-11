# goude's iris rev 4 qmk config

This is my iris configuration, based on the default. Aim is to optimize for zsh/tmux/neovim,
possibly with encoders replacing the upper thumb buttons (currently no encoders attached).

## Prerequisites

Install the prerequisite packages like so:

```sh
sudo utils/qmk_install.sh
```

In order for this to work on Ubuntu (and possibly other distros), you may need
to use a root shell instead of sudo (`sudo su -`) not contaminated by pyenv to
avoid /usr/bin/pip3 warnings.

## Build Instructions

```sh
make keebio/iris/rev4:goude
```

## Flash Instructions

```sh
make keebio/iris/rev4:goude:flash
```

Do this for one keyboard half at a time. Plug in the keyboard with a USB-C
connector, run the flash command, press and hold the reset button for a few
seconds until the keyboard is detected.

## Notes

Experience after performing a couple of `keymap.c` updates.

On Ubuntu:

```sh
vim keymap.c
sudo make keebio/iris/rev4:goude:flash
# Press reset key combo
```

No need to flash halves separately when updating, it seems.
