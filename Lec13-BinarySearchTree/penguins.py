
n = int(input())
res = 0;
kindAns = ""
dictionary = { "Emperor" : 0,
                "Macaroni" : 0,
                "Little" : 0}
for i in range(n):
    penguin = input()
    kind = penguin[0 : len(penguin) - 8]
    dictionary[kind] += 1
    if (res < dictionary[kind]):
        res = dictionary[kind]
        kindAns = kind

print(kindAns + " Penguin")




