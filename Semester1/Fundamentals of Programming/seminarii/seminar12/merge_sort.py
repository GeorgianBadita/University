"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/18/2017 09:13
"""
def merge(left, right, list):
    i = 0
    j = 0
    k = 0

    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            list[k] = left[i]
            i += 1
        else:
            list[k] = right[j]
            j += 1
        k += 1

    while i < len(left):
        list[k] = left[i]
        i += 1
        k += 1

    while j < len(right):
        list[k] = right[j]
        j += 1
        k += 1

def merge_sort(list):
    if len(list) > 1:
        mid = len(list)//2
        left = list[:mid]
        right = list[mid:]

        merge_sort(left)
        merge_sort(right)

        merge(left, right, list)


l = [5, 3, 4, 2, 1]
merge_sort(l)
print(l)
