class players:
    def __init__(self,name,num):
#构造方法，初始化对象属性
        self.name=name
        self.num=num
#把传入的数据，保存到这个对象身上，以后随时可以拿出来用
def get_player():
    name=input("输入名字 ")
    num=input("输入是个 ")
    return players(name,num)
if __name__ == "__main__":
    player=get_player()
    print(f"选手{player.name}是个{player.num}")
