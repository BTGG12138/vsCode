from part1Learning import normal_round

"""
x = input("输入三位及以上小数\n")
num = float(x)
y = normal_round(num)
expect = round(num, 2)
assert abs(y - expect) < 1e-10, f"round()函数不符合预期，输入{x}，输出{y}，预期{expect}"
#if not abs(float(x) - y) > 1e-10:
#    raise AssertionError(f"round()函数不符合预期，输入{x}，输出{y}")
print(f"输入{x}，输出{y}，符合预期")
# __init__.py 标记当前文件夹为Python包
# 支持使用 from 包名.模块名 import xxx 的方式导入
"""

"""
nums=[]
for _ in range(3):
    nums.append(int(input("输入输入 ")))
for num in sorted(nums,reverse=True):
    print(f"数字是 {num}")
"""

"""
file=open("nums.txt","a")
#'w'是覆写模式
while True:
    num=input("输入输入 ")
    if num==' ':
        file.write("\n")
        file.close()
        break
    file.write(num)
"""

with open("nums.txt",'r') as file:
#    lines=file.readlines()
#for line in lines:
    for line in file:
        print("数字是 ",line.rstrip())
nums=[]
with open("nums.csv") as file:
    for line in file:
        num=line.rstrip().split(',')
        print("这是",num[1])