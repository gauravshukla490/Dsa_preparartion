class MinHeap{
    vector<int>heap;

 public:
  //find parent
 int parent(int i){
    return (i-1)/2;
 }

 //find left child
 int leftChild(int i){
    return 2*i+1;
 }

 //find right child
 int rightChild(int i){
    return 2*i+2;
 }

 //heapify down
 void insert(int val){
    heap.push_back(val);

    int i = heap.size()-1;

    while(i>=0 && heap[parent(i)] > heap[i]){
        swap(heap[parent(i)] , heap[i]);
        i = parent(i);
    }
 }

//get minimum
int getMin(){
    
     if (heap.empty())
            return -1;

        return heap[0];
}

//heapify down ->smallest = push up
void heapifyDown(int i){
    
    int n = heap.size();

    while(true){
         
        int smallest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if(left < n && heap[left] < heap[smallest]){
            smallest = left;
        }

        if(right < n && heap[right] < heap[smallest]){
            smallest = right;
        }

        if(smallest == i) break;

        swap(heap[i] , heap[smallest]);

    }
}

//delete minimum
void deleteMin(){
    
     if (heap.empty())
            return;

    heap[0] = heap.back();
    heap.push_back();

     if (!heap.empty())
            heapifyDown(0);
}

//extract minimum
 int extractMin() {

        if (heap.empty())
            return -1;

        int ans = heap[0];

        deleteMin();

        return ans;
    }


//decrease key
  void decreaseKey(int i, int newVal) {

        heap[i] = newVal;

        while (i > 0 && heap[parent(i)] > heap[i]) {

            swap(heap[parent(i)], heap[i]);

            i = parent(i);
        }
    }

//delete key
 void deleteKey(int i) {

        decreaseKey(i, INT_MIN);

        deleteMin();
    }

//build heap
  void buildHeap(vector<int> &arr) {

        heap = arr;

        int n = heap.size();

        for (int i = n / 2 - 1; i >= 0; i--) {

            heapifyDown(i);
        }
    }
}