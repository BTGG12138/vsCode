try:
    num = int(input("请输入一个数字:\n"))
    if num == 48:
        print("48")
    else:
        print("blc")
except ValueError:
    print("输入的不是数字")