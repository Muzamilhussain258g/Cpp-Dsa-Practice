class Node {
    data;
    nextNode;
    constructor(data) {
        this.data = data;
        this.nextNode = null;
    }
}

class LL {
    head;
    tail;

    pushBack(data) {
        let newNode = new Node(data)
        if (this.head != null) {
            this.tail.nextNode = newNode;
            this.tail = newNode
        } else {
            this.head = newNode
            this.tail = newNode
        }
    }
    display() {
        let temp = this.head
        while (temp != null) {
            console.log(temp.data)
            temp = temp.nextNode
        }
    }
}

let linkList  = new LL();

linkList.pushBack(1)
linkList.pushBack(2)
linkList.pushBack(3)
linkList.pushBack(4)
linkList.pushBack(5)
linkList.pushBack(6)
linkList.pushBack(7)
linkList.pushBack(8)
linkList.pushBack(9)
linkList.pushBack(10)
linkList.display()