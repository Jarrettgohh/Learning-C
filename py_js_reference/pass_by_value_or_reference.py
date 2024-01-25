

def swap(a, b):

    a += 1
    b += 1
    # t = a

    # a = b
    # b = t

    print(f"a = {a}, b = {b}")
    return a, b


def change_arr(arr):
    arrr = arr
    del arrr[:1]


def main():
    arr = [1, 2, 3]
    a = 1
    b = 2

    a, b = swap(a, b)
    change_arr(arr)

    # print(f"a = {a}, b = {b}")
    print(arr)


main()
