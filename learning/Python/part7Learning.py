"""
#全局变量
number=set()
def delete_num():
    global number
    #声明全局变量,不然会报错
    number.clear()
    print("清空集合")
def change(num: int) -> None:
    #:int, -> None 是类型提示,不影响运行
    print(type(num).__name__)
if __name__=="__main__":
    #局部变量
    nums=[0,1,1,48,48,3,6,9,9,9]
    for num in nums:
        number.add(num)
    for _ in number:
        print(_,end=" ")
    print()
    delete_num()
    for _ in number:
        print(_,end=" ")
    print()
    change(input("输入输入 "))
"""

"""
import argparse
#导入python自带的命令行解析模块
parser=argparse.ArgumentParser(description="这是一个测试")
#创建一个解析器对象
parser.add_argument("-n",default=0,type=int,help="输入一个数字")
#注册一个参数 -n 执行脚本时后面跟上数字
#不给参数直接输出0
args=parser.parse_args()
#解析命令行输入，把拿到的值放到 args 对象里
print(args.n)
"""

"""
def trans(num1,num2,num3):
    print(num1,num2,num3)
list=[int(1),int(4),int(8)]
trans(*list)
dictionary={"num1":1,"num2":4,"num3":8}
trans(**dictionary)
#收集/解包可迭代对象
def collect(*args,**kwargs):
    print(args)
    #args是元组,打印自带()
    print(kwargs)
    #kwargs是字典,打印自带{}
collect(1,4,8,num1=1,num2=4,num3=8)
"""

"""
def yell(*words):
    #uppercased = map(str.upper, words)
    #把可迭代对象里的每一个元素，依次传给这个函数处理，返回一个迭代器
    uppercased = [word.upper() for word in words]
    print(*uppercased)
if __name__ == "__main__":
    yell("This", "is", "CS50")
players=[
    {"name":"UZI","team":"RNG","age":int(28)},
    {"name":"Faker","team":"T1","age":int(29)},
    {"name":"Doinb","team":"FPX","age":int(27)},
    {"name":"Knight","team":"TES","age":int(26)}
]
#names=[player["name"] for player in players if player["age"] < int(28)]
#print(names)
#列表推导式
names=filter(lambda player: player["age"] < int(28), players)
#只留下让函数返回True的元素
for name in names:
    print(name["name"])
"""


players=["Faker","Oner","Keria"]
T1=[{"name":player,"team":"T1"} for player in players]
print(T1)
for i,player in enumerate(players):
    #enumerate(可迭代对象, start=0)
    print(i+2,player)
def print_eggs(num):
    for i in range(num):
        yield "大鸡蛋 "*(i+1)
        #遇到 yield就暂停,把值抛出去;下次调用继续从暂停的地方跑
        #生成器不会一次性把所有数据存进内存,要一个算一个
for _ in print_eggs(int(input("输入鸡蛋数量: "))):
    print(_)