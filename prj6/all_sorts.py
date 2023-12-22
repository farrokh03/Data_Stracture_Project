class Sort:

    to_sort = []

    def __init__(self, unsorted):
        self.to_sort = unsorted

    def bubble_sort(self):
        array = self.to_sort

        for i in range(0, len(array) - 1):
            swapped = False
            for j in range(0, len(array) - i - 1):
                if array[j] > array[j + 1]:
                    array[j], array[j + 1] = array[j + 1], array[j]
                    swapped = True
            if swapped == False:
                break
        return array

    def insertion_sort(self):
        array = self.to_sort
        for i in range(1, len(array)):
            j = i - 1
            key = array[i]

            while j >= 0 and array[j] > key:
                array[j + 1] = array[j]
                j -= 1
            array[j + 1] = key
        return array

    def selection_sort(self):
        array = self.to_sort

        for i in range(0, len(array) - 1):
            min = i
            for j in range(i + 1, len(array)):
                if array[j] < array[min]:
                    min = j
            if min != i:
                array[min], array[i] = array[i], array[min]

        return array

    def counting_sort(self):
        array = self.to_sort
        output_array = [0] * len(array)
        max = 0
        for i in range(0, len(array)):
            if array[i] > max:
                max = array[i]

        counting_array = [0] * (max + 1)

        for i in range(0, len(array) - 1):
            counter = 0
            for j in range(0, len(array)):
                if array[j] == i:
                    try:
                        counter += 1
                        counting_array[i] = counter
                    except:
                        continue

        for i in range(1, len(counting_array)):
            counting_array[i] = counting_array[i] + counting_array[i-1]

        for i in range(len(array) - 1, -1, -1):
            key = array[i]
            value = counting_array[key]
            value = value - 1
            counting_array[key] = value
            output_array[value] = key

        return output_array

    def bucket_sort(self, array):
        bucket_array = [[]] * len(array)
        for i in array:
            bucket_index = int(i * len(bucket_array))
            bucket_array[bucket_index].append(i)

        for i in range(len(bucket_array)):
            bucket_array[i] = self.insertion_sort(bucket_array[i])

        k = 0
        for i in range(len(bucket_array)):
            for j in range(len(bucket_array[i])):
                try:
                    array[k] = bucket_array[i][j]
                    k += 1
                except:
                    continue
        return array

    def merge_sort(self, array):
        if len(array) > 1:
            mid = len(array) // 2

            left = array[:mid]

            right = array[mid:]

            self.merge_sort(left)

            self.merge_sort(right)

            i = j = k = 0

            while i < len(left) and j < len(right):
                if left[i] <= right[j]:
                    array[k] = left[i]
                    i += 1
                else:
                    array[k] = right[j]
                    j += 1
                k += 1

            while i < len(left):
                array[k] = left[i]
                i += 1
                k += 1

            while j < len(right):
                array[k] = right[j]
                j += 1
                k += 1

        return array

    def quick_sort(self):
        pass


# unordered = [9, 3, 334, 123, 6, 1, 99, 100]


unordered_counting = [2, 5, 3, 0, 2, 3, 0, 3, 1, 2, 2, 2]


sample = Sort(unordered_counting)

print(sample.merge_sort(unordered_counting))
