function Node(value){
    this.value = value;
    this.previous = null;
    this.next = null;
}

const emptyDLL = {
    first: null,
    last: null,
    n: 0
};

export class DoublyLinkedList{

    constructor(){
        Object.assign(this, emptyDLL)
    }

    insert(value){
        let newNode = new Node(value);
        
        let prevNode = null;
        let currentNode = this.first;

        while (currentNode != null && currentNode.value < value) {
            prevNode = currentNode;
            currentNode = currentNode.next;
        }

        if(prevNode)
            prevNode.next = newNode; 
        else
            this.first = newNode;
        
        if (currentNode)
            prevNode = newNode;
        else
            this.last = newNode;

        newNode.next = currentNode;
        newNode.previous = prevNode;

        this.n++;

        return true;
    }

    remove(value){

        if(this.n === 0 || this.search(value) === -1)
            return false;

        let prevNode;
        let currentNode;
        
        while(this.search(value) !== -1){
            prevNode = null;
            currentNode = this.first;

            while (currentNode && currentNode.value < value) {
                prevNode = currentNode;
                currentNode = currentNode.next;
            }

            if(currentNode.value === value){
                if(prevNode){
                    prevNode.next = currentNode.next;
                    if (currentNode.next) 
                        currentNode = prevNode;
                    else 
                        this.last = prevNode;
                } else{
                    this.first = currentNode.next;
                    if (currentNode.next) 
                        this.first.previous = null;
                    else 
                        this.last = null;
                }

                this.n--;
                
            }
        }

        
        return true;

    }

    search (value) {
        if (this.n === 0) 
            return -1;

        let currentNode = this.first;
        let i = 0;
        while (currentNode != null && currentNode.value < value){ 
            currentNode = currentNode.next;
            i++;
        }
        
        if (currentNode)
            return currentNode.value === value ? i : -1;

        return -1; 
    }

    getSize(){
        return this.n;
    }

    getAtIndex(index){
        let tmp = this.first;
        for (let i = 0; tmp != null && i < index; i++)
          tmp = tmp.next;

        if (tmp != null)
          return tmp.value;
        else
          return -1;
    }

    values(){
        let valuesList = [];
        for(let i = 0; i < this.getSize(); i++)
            valuesList.push(this.getAtIndex(i));
        
        return valuesList;
    }

    clear(){
        Object.assign(this, emptyDLL)
    } 
}

export default new DoublyLinkedList();
