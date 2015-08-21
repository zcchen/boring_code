#!/usr/bin/env python
# -*-   encoding : utf8   -*-

class node():
    def __init__(self, data, next=None, prev=None):
        self.data = data
        self.next = next
        self.prev = prev

class double_cycl_list():
    head = None
    tail = head

    def append(self, data):
        print("appending data:", data)
        new_node = node(data)
        if self.head is None:
            self.head = self.tail = new_node
            self.head.next = self.tail
            self.head.prev = self.tail
        else:
            new_node.prev = self.tail
            self.tail.next = new_node
            new_node.next = self.head
            self.head.prev = new_node
            self.tail = new_node

    def remove(self, node_value):
        print("removing data:", node_value)
        current_node = self.head
        _del_flag = False
        size = self.size()
        for i in range(size):
            tmp = None
            if current_node.data == node_value:
                current_node.prev.next = current_node.next
                current_node.next.prev = current_node.prev
                if current_node is self.head:
                    self.head = current_node.next
                if current_node is self.tail:
                    self.tail = current_node.prev
                _del_flag = True
                tmp = current_node
            current_node = current_node.next
            if _del_flag == True:
                del(tmp)

    def size(self):
        current_node = self.head
        count = 0;
        if hasattr(current_node, 'data'):
            while current_node is not self.tail:
                count += 1
                current_node = current_node.next
            count += 1
        return count

    def show(self):
        size = self.size()
        print("show list data, total number is:", size)
        current_node = self.head
        while current_node is not self.tail:
            print("prev, current, next are ", current_node.prev.data,
                    current_node.data, current_node.next.data)
            current_node = current_node.next
        #else:
        if hasattr(current_node, "data"):
            print("prev, current, next are ", current_node.prev.data,
                    current_node.data, current_node.next.data)
        else:
            print("The list is empty!")


if __name__ == '__main__':
    s = double_cycl_list()
    s.show()

    s.append(12)
    s.show()

    s.append(16)
    s.show()

    s.append(26)
    s.show()

    s.append(36)
    s.show()

    s.remove(16)
    s.show()

    s.remove(12)
    s.show()

    s.remove(36)
    s.show()
