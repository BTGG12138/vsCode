"""
class players:
    def __init__(self,name,num):
#可以设置默认值None
#构造方法，初始化对象属性
        self.name=name
        self.num=num
    #__str__本身是特殊方法,不能加@property
    #@property是读,@property.setter是写
    def __str__(self):
    #作为字符串触发器触发
        return f"选手{self.name}是个{self.num}"
    #仅调用类名就可以调用
    @staticmethod
    def hero():
        print("根本没有这场比赛")
#记得要返回值
#把传入的数据，保存到这个对象身上，以后随时可以拿出来用
    @classmethod
    def get_player(cls):
        name=input("输入名字 ")
        num=input("输入是个 ")
        return cls(name,num)
if __name__ == "__main__":
    player=players.get_player()
    print(f"选手{player.name}是个{player.num}")
    print(player)
    player.hero()
"""
    
"""
#int("数字串", 进制),把指定进制的字符串转十进制
print(int("1010",7))
print(type(True).__name__)
class Player:
#直接仅定义类属性,不需要实例化对象
    nums=None
    @classmethod
    def get_nums(cls,nums):
        cls.nums=nums
        print(cls.nums)
#可以直接调用类方法,不需要实例化对象
Player.get_nums(int(input("输入数字 ")))
"""

