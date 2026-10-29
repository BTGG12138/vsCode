"""
import csv
name = input("What's your name? ")
home = input("Where's your home? ")
with open("students.csv", "a", newline="") as file:
    writer = csv.DictWriter(file, fieldnames=["name", "home"])
    # 文件不存在 / 是空文件，才写入表头
    if file.tell() == 0:
        writer.writeheader()
    writer.writerow({"name": name, "home": home})
"""

"""
import sys
from PIL import Image

#sudo apt install libavif-bin
#avifdec /home/btgg/Desktop/num1.avif num1.png
#用原生的工具将图片格式转换

images = []
# 遍历命令行参数（跳过脚本名sys.argv[0]）
for arg in sys.argv[1:]:
    image = Image.open(arg)
    images.append(image)
# 以第一张图作为基准，保存gif
images[0].save(
    "mc.gif",
    save_all=True,
    append_images=images[1:],  # 原截图写的是[images[1]]，只能加第2张；改成images[1:]才支持多张
    duration=200,  # 每帧停留时间，单位：毫秒
    loop=0         # loop=0 → 无限循环播放
)
"""

#.      匹配除换行符之外的任意单个字符
#*      前面的内容，重复 0 次或多次
#+      前面的内容，重复 1 次或多次
#?      前面的内容，重复 0 次或 1 次
#{m}    前面的内容，精确重复 m 次
#{m,n}  前面的内容，重复 m ~ n 次

import re
email = input("What's your email? ").strip()
if re.search(r"^[^@]+@[^@]+\.edu$", email):
    print("Valid")
else:
    print("Invalid")

#^      匹配整个字符串的最前面
#$      匹配整个字符串的最后面
#[]     匹配括号里任意一个字符
#[^]    匹配任意一个不是的字符