#!/bin/sh

sed -i 's/ckb.//g' ./eluna.py

sed -i 's/key_down/register_code/g' ./eluna.py
sed -i 's/key_up/unregister_code/g' ./eluna.py
sed -i 's/)/);/g' ./eluna.py
sed -i "s/')/)/g" ./eluna.py
sed -i "s/('/(KC_/g" ./eluna.py
sed -i 's/_a)/_A)/g' ./eluna.py
sed -i 's/_b)/_B)/g' ./eluna.py
sed -i 's/_h)/_H)/g' ./eluna.py
sed -i 's/_l)/_L)/g' ./eluna.py
sed -i 's/_w)/_W)/g' ./eluna.py
sed -i 's/_s)/_S)/g' ./eluna.py
sed -i 's/_d)/_D)/g' ./eluna.py
sed -i 's/_alt)/_LALT)/g' ./eluna.py
sed -i 's/_,)/_COMMA)/g' ./eluna.py
sed -i 's/_left)/_LEFT)/g' ./eluna.py
sed -i 's/_right)/_RIGHT)/g' ./eluna.py
sed -i 's/_up)/_UP)/g' ./eluna.py
sed -i 's/_down)/_DOWN)/g' ./eluna.py
sed -i 's/_f8)/_F8)/g' ./eluna.py
sed -i 's/_f7)/_F7)/g' ./eluna.py
