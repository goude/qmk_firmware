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

### Viewing keymap.c with QMK Configurator 

`c2json` was added only hours ago - nice!

```
pyenv virtualenv 3.7.9 qmk_test
pyenv activate qmk_test
pip install -r requirements.txt
bin/qmk c2json -kb keebio/iris/rev4 -km my_keymap --no-cpp keyboards/keebio/iris/keymaps/goude/keymap.c > iris_map.json
```

Upload json file to https://config.qmk.fm

Note that some (quantum?) keycodes will make the configurator fail semi-silently, after uploading json all keys will be shown as "N/A" (and there will be `cannot read property 'name' of undefined` errors in the browser console). See the KEYCODES section at bottom of page for valid codes (hover with mouse over keys). Example: needed to replace `OSM(KC_RCTRL)` with `OSM(MOD_RCTL)`.
