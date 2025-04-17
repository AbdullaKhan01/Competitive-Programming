# def binary(a):
#     s = ""
#     while(a!=0):
#         s+=str(a%2)
#         a = a//2
#     return s    
a=int(input())
# print(bin(a))
# # ans = ""
# # for i in str(a):
# #     x = binary(int(i))
# #     for i in range(4-len(x)):
# #         x = "0"+x
# #     ans = ans+x
# # print(ansa = int(input())
for i in str(a):
    x = bin(int(i))[2:]
    for j in range(4-len(str(x))):
        print(0,end='')
    print(x,end='')