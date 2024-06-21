# A solution for the Hashmap problem
class MyHashMap(object):

    def __init__(self):
        self.keyRange = 769
        self.bucketArray = [Bucket() for i in range(self.keyRange)]

    def _hash(self, key):
        return key % self.keyRange

    def put(self, key, value):
        """
        :type key: int
        :rtype: None
        """
        bucket = self.bucketArray[self._hash(key)]
        bucket.add(key, value)

    def remove(self, key):
        """
        :type key: int
        :rtype: None
        """
        bucket = self.bucketArray[self._hash(key)]
        bucket.remove(key)

    def get(self, key):
        """
        :type key: int
        :rtype: bool
        """
        bucket = self.bucketArray[self._hash(key)]
        print(f"   {bucket.contains(key)}")
        return bucket.contains(key)

""" Implementation using a linked list as a bucket.
"""
class Node:
    def __init__(self, key, value, nextNode=None):
        self.key = key
        self.value  = value
        self.nextNode = nextNode

class Bucket:
    def __init__(self):
        self.head = Node(0,0)

    def add(self, key, value):
        if self.contains(key) == -1:
            newnode = Node(key, value, self.head.nextNode)
            self.head.nextNode = newnode
        else:
            curr = self.head.nextNode
            while curr is not None:
                if curr.key == key:
                    curr.value = value
                    break

    def remove(self, key):
        prev = self.head
        curr = self.head.nextNode
        while curr is not None:
            if key == curr.key:
                prev.nextNode = curr.nextNode
                return
            prev = curr
            curr = curr.nextNode  
    
    def contains(self, key):
        curr = self.head.nextNode
        while curr is not None:
            if curr.key == key:
                return curr.value
            curr = curr.nextNode
        return -1


if __name__ == "__main__":

    # Your MyHashSet object will be instantiated and called as such:
    obj = MyHashMap()
    obj.put(1,1)
    obj.put(2,2)
    obj.get(1)
    obj.get(3)
    obj.put(2,1)
    obj.get(2)
    obj.remove(2)
    obj.get(2)
    