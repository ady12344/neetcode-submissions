class DynamicArray {
int *arr;
int size;
int capacity;
public:
    
    DynamicArray(int capacity) {
        this->arr = new int[capacity];
        this->size = 0;
        this->capacity = capacity;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(size >= capacity){
            resize();
        }
        arr[size] = n;
        size++;
    }

    int popback() {
        int returnVal = arr[size-1];
        size--;
        return returnVal;
    }

    void resize() {
        int *newArr = new int[2*capacity];
        this->capacity *=2;
        for(int i = 0 ; i < size ; i++){
            newArr[i] = arr[i];
        }

        this->arr = newArr;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
