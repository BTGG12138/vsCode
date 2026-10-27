from random import choice
import random
import statistics
import sys

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

print(statistics.mean([1,2,3,4,5]))
print("文件名:",sys.argv[0])
for arg in sys.argv[1:-1]:
    print("参数:",arg)