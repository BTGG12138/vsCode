"""
isWant=input("我想拉屎吗？\n").strip().capitalize()
if ',' in isWant:
    _is, reason= isWant.split(",")
else:
    _is = isWant
if _is=='y' or 'Y':
    print("我想拉屎")
else:
    print("我不想拉屎")
print("这能输出中文吗？")
isWant=isWant.lower().title()
print("我的想法是 "+isWant)
#is判断内存地址是否相同
"""

"""
下午再说
"""

"""
#两个参数的输出中间自动加空格
print("你是谁", "我猜不到", "后面还要加空格",sep=' ', end='\n', flush=False)
print('还可以"这样"')
print("还可以\"这样\"")
x=input("快点 ").strip()
y=input("懂得 ").strip()
z=float(x)/float(y)
print("这个", z)
"""

z_round = float(input("输入1000.005\n"))
#round()四舍五入是银行家算法，取最近的偶数
#只有第一位小数是5时才会出现银行家算法
#math.trunc()取整数部分
def normal_round(num, dec=2):
#保留小数点后dec位
    s = 10**dec
    #十的dec次方
    return int(num*s + 0.5)/s
    #+0.5是为了四舍五入
z_round = normal_round(z_round)
print(f"{z_round:,}")

#记得结尾调用主函数