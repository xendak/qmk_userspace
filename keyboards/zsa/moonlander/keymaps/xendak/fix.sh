#!/bin/sh

sed -i 's/ckb.//g' ~/Downloads/eluna.py

sed -i 's/key_down/register_code/g' ~/Downloads/eluna.py
sed -i 's/key_up/unregister_code/g' ~/Downloads/eluna.py
sed -i 's/)/);/g' ~/Downloads/eluna.py
sed -i "s/')/)/g" ~/Downloads/eluna.py
sed -i "s/('/(KC_/g" ~/Downloads/eluna.py
sed -i 's/_a)/_A)/g' ~/Downloads/eluna.py
sed -i 's/_b)/_B)/g' ~/Downloads/eluna.py
sed -i 's/_h)/_H)/g' ~/Downloads/eluna.py
sed -i 's/_l)/_L)/g' ~/Downloads/eluna.py
sed -i 's/_w)/_W)/g' ~/Downloads/eluna.py
sed -i 's/_s)/_S)/g' ~/Downloads/eluna.py
sed -i 's/_d)/_D)/g' ~/Downloads/eluna.py
sed -i 's/_alt)/_LALT)/g' ~/Downloads/eluna.py
sed -i 's/_left)/_LEFT)/g' ~/Downloads/eluna.py
sed -i 's/_right)/_RIGHT)/g' ~/Downloads/eluna.py
sed -i 's/_up)/_UP)/g' ~/Downloads/eluna.py
sed -i 's/_down)/_DOWN)/g' ~/Downloads/eluna.py
sed -i 's/_f8)/_F8)/g' ~/Downloads/eluna.py
sed -i 's/_f7)/_F7)/g' ~/Downloads/eluna.py
