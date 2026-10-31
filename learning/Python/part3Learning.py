"""
try:
    num = int(input("请输入一个数字:\n"))
except ValueError:
    pass
else:
    if num == 48:
            print("48")
    else:
        print("blc")
"""

"""
from random import choice
import random
coin=choice(["正面","反面"])
print(coin)
coin=random.randint(0,1)
if coin==0:
    print("正面")
else:
    print("反面")
players=["张三","李四","王五","赵六"]
random.shuffle(players)
for player in players:
    print(player)
"""

"""
import statistics
import sys
print(statistics.mean([1,2,3,4,5]))
#求算术平均值
print("文件名:",sys.argv[0])
for arg in sys.argv[1:-1]:
#从第一个参数，到倒数第二个参数
    print("参数:",arg)
"""

import requests
response = requests.get("https://httpbin.org/get", timeout=5)
j = response.json()
print(j)
print(j["origin"]) 
# 还可以像字典一样取里面的值
#反正JSON就是计算机的一种通用数据交换格式

from part1Learning import normal_round

print(normal_round(1000.005))
#import会直接加载裸露在外的代码