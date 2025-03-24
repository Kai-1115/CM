text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
for i in text:
    print(chr((17*ord(i)+45)%95+32), i)