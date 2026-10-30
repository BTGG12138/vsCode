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
# 遍历命令行参数(跳过脚本名sys.argv[0])
for arg in sys.argv[1:]:
    image = Image.open(arg)
    images.append(image)
# 以第一张图作为基准,保存gif
images[0].save(
    "mc.gif",
    save_all=True,
    append_images=images[1:],  # 原截图写的是[images[1]],只能加第2张;改成images[1:]才支持多张
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

"""
import re
email = input("What's your email? ").strip()
#if re.search(r"^[^@]+@[^@]+\\.edu$", email):
#尽量使用\\
if re.search(r"^[0-9]+@qq\\.com$",email):
    print("Valid")
else:
    print("Invalid")
"""

#^      匹配整个字符串的最前面
#$      匹配整个字符串的最后面
#[]     匹配括号里任意一个字符
#[^]    匹配任意一个不是的字符
#大写就是取反
#\d     数字 0~9
#\s     空白字符：空格、Tab、换行 `\n`
#\w     字母 a-z、A-Z，数字 0-9，下划线 `_`
#|      匹配 A 或者 B
#()     会保存匹配到的内容
#(?)    但是不保存结果，不能单独提取

#flag赋值类型
#re.IGNORECASE  忽略大小写匹配
#re.MULTILINE   多行模式，让 ^ 和 $ 匹配每一行的开头、结尾
#re.DOTALL      让 . 可以匹配换行符 \n

import re
name = input("What's your name? ").strip()
if matches := re.search(r"^(.+), *(.+)$", name):
#   判断的同时赋值
    name = matches.group(2) + " " + matches.group(1)
print(f"hello, {name}")
#这里的group从1开始计数
#.replace(替换目标,替换内容)

#re.match(pattern, string, flags=0)                 从字符串开头匹配
#re.search(pattern, string, flags=0)                扫描整个字符串，找到第一个匹配
#re.sub(pattern, repl, string, count=0, flags=0)    替换匹配内容