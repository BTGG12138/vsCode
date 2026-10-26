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

#两个参数的输出中间自动加空格
print("你是谁", "我猜不到", "后面还要加空格",sep=' ', end='\n', flush=False)
print('还可以"这样"')
print("还可以\"这样\"")

x=input("快点 ").strip()
y=input("懂得 ").strip()
z=float(x)/float(y)
print("这个", z)
#round()四舍五入是银行家算法，取最近的偶数
#math.trunc()取整数部分
def normal_round(num, dec=2):
    s = 10**dec
    return int(num*s + 0.5)/s
z_round = normal_round(z)