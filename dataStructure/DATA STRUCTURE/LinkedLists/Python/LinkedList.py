class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

    def addToEnd(self, data):
        if self.next == None:
            self.next = Node(data)
        else:
            self.next.addToEnd(data)

    def addSorted(self, data):
        if self.next == None:
            self.next = Node(data)
        elif data < self.next.data:
            temp = Node(data)
            temp.next = self.next
            self.next = temp
        else:
            self.next.addSorted(data)


class LinkedList:
    def __init__(self):
        self.head = None

    def printList(self):
        temp = self.head
        while(temp):
            print(f"|{temp.data}|->", end="")
            temp = temp.next

    def addToBeggining(self, data):
        if self.head == None:
            self.head = Node(data)
        else:
            temp = Node(data)
            temp.next = self.head
            self.head = temp

    def addToEnd(self, data):
        if self.head == None:
            self.head = Node(data)
        else:
            self.head.addToEnd(data)
    
    def addSorted(self, data):
        if self.head == None:
            self.head = Node(data)
        elif data < self.head.data:
            self.addToBeggining(data)
        else:
            self.head.addSorted(data)

    def deleteNode(self, key):
        temp = self.head

        # 'is' operator checks if two variables point to the same object in memory!        
        # only use when comparing to 'None'
        if temp is not None:
            if temp.data == key:
                self.head = temp.next
                temp = None
        
        while temp is not None:
            if temp.data == key:
                break
            prev = temp
            temp = temp.next
        
        if temp == None:
            return
        
        prev.next = temp.next
        temp = None



if __name__ == "__main__":
    print("EXEMPLO 1:")
    llist = LinkedList()
    llist.head = Node(1)
    second = Node(2)
    third = Node(3)
    llist.head.next = second
    second.next = third    
    llist.printList()

    print("\n\nEXEMPLO 2:")
    llist.addToBeggining(5)    
    llist.printList()

    print("\n\nEXEMPLO 3:")
    llist2 = LinkedList()
    llist2.addToBeggining(1)
    llist2.addToBeggining(2)
    llist2.addToBeggining(3)
    llist2.printList()

    print("\n\nEXEMPLO 4:")
    llist3 = LinkedList()
    llist3.addToEnd(1)
    llist3.addToEnd(2)
    llist3.addToEnd(3)
    llist3.printList()

    print("\n\nEXEMPLO 5:")
    llist3 = LinkedList()
    llist3.addSorted(9)
    llist3.addSorted(2)
    llist3.addSorted(5)
    llist3.printList()

    print("\n\nEXEMPLO 6:")
    llist4 = LinkedList()
    llist4.addSorted(9)
    llist4.addSorted(2)
    llist4.addSorted(5)
    print("Before deleting Node(2):")
    llist4.printList()
    llist4.deleteNode(2)
    print("\nAfter deleting Node(2):")
    llist4.printList()