"""
num1=int(input("还可以这样\n"))
if 48==num1!=369:
    print("48bin")
else:
    num2=input("369没毛\n").strip().lower()
    print("可以") if num2=='y' else print("不认可")

num3=int(input("你是哪年的冠军\n"))
match num3:
    case 2018:
        print("2018年冠军是法国")
    case 2014 | 2010:
        print("2014 2010年冠军是德国")
    case 2024:
        print("2024年冠军是UZI")
    case _:
        print("国为四两将")
"""
print("还可以这样\n" *3,end="")
players=["UZI","Faker","Doinb","Knight"]
for player in players:
    print(player)

players={
    "UZI":"RNG",
    "Faker":"T1",
    "Doinb":"FPX",
    "Knight":"TES"
}
for player in players:
    print(player,"的战队是",players[player])
players=[
    {"name":"UZI","team":"RNG","age":28},
    {"name":"Faker","team":"T1","age":None},
    {"name":"Doinb","team":"FPX","age":27},
    {"name":"Knight","team":"TES","age":26}
]
for player in players:
    print(player["name"],"的战队是",player["team"],"年龄是",player["age"])
#循环嵌套可以用两个占位符