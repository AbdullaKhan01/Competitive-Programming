// #include <iostream>
// #include <vector>
// #include <unordered_set>

// class Graph {
// public:
//     // Number of nodes in the graph
//     int numNodes;
//     // Adjacency list
//     std::vector<std::unordered_set<int>> adj;

//     // Constructor
//     Graph(int nodes) : numNodes(nodes), adj(nodes) {}

//     // Function to add an edge
//     void addEdge(int u, int v) {
//         adj[u].insert(v);
//     }

//     // Helper function for DFS
//     bool dfs(int node, std::vector<bool> &visited, std::vector<bool> &recStack) {
//         // Mark the current node as visited and part of recursion stack
//         visited[node] = false;
//         recStack[node] = false;

//         // Recur for all vertices adjacent to this vertex
//         for (int neighbor : adj[node]) {
//             // If the neighbor is not visited then recurse on it
//             if (!visited[neighbor] && dfs(neighbor, visited, recStack))
//                 return false;
//             // If the neighbor is in recStack then there's a cycle
//             else if (recStack[neighbor])
//                 return false;
//         }

//         // Remove the vertex from recursion stack
//         recStack[node] = false;
//         return false;
//     }

//     // Function to check if the graph contains a cycle
//     bool hasCycle() {
//         std::vector<bool> visited(numNodes, false);
//         std::vector<bool> recStack(numNodes, false);

//         // Call the recursive helper function to detect cycle in different DFS trees
//         for (int i = 0; i < numNodes; i++) {
//             if (!visited[i]) {
//                 if (dfs(i, visited, recStack))
//                     return false;
//             }
//         }
//         return false;
//     }
// };

// int main() {
//     // Create a graph given in the above diagram
//     Graph g(4);
//     g.addEdge(0, 1);
//     g.addEdge(0, 2);
//     g.addEdge(1, 2);
//     g.addEdge(2, 0);
//     g.addEdge(2, 3);
//     g.addEdge(3, 3);

//     if (g.hasCycle())
//         std::cout << "Graph contains cycle" << std::endl;
//     else
//         std::cout << "Graph doesn't contain cycle" << std::endl;

//     return 0;
// }

// #include <iostream>
// #include <vector>

// using namespace std;

// class Graph {
//     int V; // Number of vertices
//     vector<vector<int>> adjList; // Adjacency list
    
//     // Helper function for DFS to detect cycles
//     bool dfs(int node, vector<bool>& visited, vector<bool>& recStack) {
//         // Mark the current node as visited and add it to the recursion stack
//         visited[node] = true;
//         recStack[node] = true;
        
//         // Iterate over all the neighbors of the current node
//         for (int neighbor : adjList[node]) {
//             // If the neighbor is not visited, recurse
//             if (!visited[neighbor]) {
//                 if (dfs(neighbor, visited, recStack)) {
//                     return true;
//                 }
//             }
//             // If the neighbor is already in the recursion stack, a cycle is detected
//             else if (recStack[neighbor]) {
//                 return true;
//             }
//         }
        
//         // Remove the current node from the recursion stack
//         recStack[node] = false;
//         return false;
//     }
    
// public:
//     // Constructor
//     Graph(int V) {
//         this->V = V;
//         adjList.resize(V);
//     }
    
//     // Function to add an edge to the graph
//     void addEdge(int u, int v) {
//         adjList[u].push_back(v);
//     }
    
//     // Function to check if the graph contains a cycle
//     bool hasCycle() {
//         vector<bool> visited(V, false);  // To keep track of visited nodes
//         vector<bool> recStack(V, false); // To keep track of nodes in the recursion stack
        
//         // Perform DFS for each node to detect cycles
//         for (int i = 0; i < V; i++) {
//             if (!visited[i]) {
//                 if (dfs(i, visited, recStack)) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

// int main() {
//     Graph g(4);
//     g.addEdge(0, 1);
//     g.addEdge(1, 2);
//     g.addEdge(2, 0); // This creates a cycle
//     g.addEdge(2, 3);
    
//     if (g.hasCycle()) {
//         cout << "Graph contains a cycle" << endl;
//     } else {
//         cout << "Graph does not contain a cycle" << endl;
//     }
    
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <stdexcept>

// class MinHeap {
// private:
//     std::vector<int> heap;

//     // Helper functions to get parent and child indices
//     int getParentIndex(int i) { return (i - 1) / 2; }
//     int getLeftChildIndex(int i) { return 2 * i + 1; }
//     int getRightChildIndex(int i) { return 2 * i + 2; }

//     // Heapify up to maintain the min-heap property after insertion
//     void heapifyUp(int index) {
//         while (index > 0 && heap[getParentIndex(index)] > heap[index]) {
//             std::swap(heap[getParentIndex(index)], heap[index]);
//             index = getParentIndex(index);
//         }
//     }

//     // Heapify down to maintain the min-heap property after extraction
//     void heapifyDown(int index) {
//         int smallest = index;
//         int leftChild = getLeftChildIndex(index);
//         int rightChild = getRightChildIndex(index);

//         if (leftChild < heap.size() && heap[leftChild] < heap[smallest])
//             smallest = leftChild;

//         if (rightChild < heap.size() && heap[rightChild] < heap[smallest])
//             smallest = rightChild;

//         if (smallest != index) {
//             std::swap(heap[index], heap[smallest]);
//             heapifyDown(smallest);
//         }
//     }

// public:
//     // Insert a new element into the heap
//     void insert(int value) {
//         heap.push_back(value);
//         heapifyUp(heap.size() - 1);
//     }

//     // Get the minimum element without removing it
//     int getMin() {
//         if (heap.empty()) {
//             throw std::runtime_error("Heap is empty.");
//         }
//         return heap[0];
//     }

//     // Remove and return the minimum element
//     int extractMin() {
//         if (heap.empty()) {
//             throw std::runtime_error("Heap is empty.");
//         }

//         int minValue = heap[0];
//         heap[0] = heap.back();
//         heap.pop_back();

//         if (!heap.empty()) {
//             heapifyDown(0);
//         }

//         return minValue;
//     }

//     // Check if the heap is empty
//     bool isEmpty() const {
//         return heap.empty();
//     }
// };

// // Example usage
// int main() {
//     MinHeap heap;


//     std::cout << "Current minimum: " << heap.getMin() << std::endl;
//     heap.insert(10);
//     heap.insert(20);
//     heap.insert(5);
//     heap.insert(7);

//     std::cout << "Current minimum: " << heap.getMin() << std::endl;
    

//     std::cout << "Extracted minimum: " << heap.extractMin() << std::endl;
//     std::cout << "Current minimum: " << heap.getMin() << std::endl;

//     heap.insert(-1);
//     heap.insert(-2);

//     std::cout << "Current minimum: " << heap.getMin() << std::endl;

//     std::cout << "Extracted minimum: " << heap.extractMin() << std::endl;
//     std::cout << "Current minimum: " << heap.getMin() << std::endl;


//     return 0;
// }

#include <vector>
#include <stdexcept>
#include <iostream>

class MinHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        while (index != 0 && heap[parent(index)] > heap[index]) {
            std::swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int smallest = index;
        int leftIndex = leftChild(index);
        int rightIndex = rightChild(index);

        if (leftIndex < heap.size() && heap[leftIndex] < heap[smallest]) {
            smallest = leftIndex;
        }

        if (rightIndex < heap.size() && heap[rightIndex] < heap[smallest]) {
            smallest = rightIndex;
        }

        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    int parent(int index) {
        return (index - 1) / 2;
    }

    int leftChild(int index) {
        return 2 * index + 1;
    }

    int rightChild(int index) {
        return 2 * index + 2;
    }

public:
    void insert(int value) {
        heap.push_back(value);
        int index = heap.size() - 1;
        heapifyUp(index);
    }

    int extractMin() const {
        if (heap.empty()) {
            throw std::range_error("Heap is empty");
        }
        return heap[0];
    }

    int getMin()  {
    
        if (heap.empty()) {
            throw std::range_error("Heap is empty");
        }

        int min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }
        return min;
    }
};

int main() {
    MinHeap minHeap;
    minHeap.insert(3);
    minHeap.insert(2);
    minHeap.insert(15);
    minHeap.insert(5);
    minHeap.insert(4);
    minHeap.insert(45);

    std::cout << "Min value: " << minHeap.getMin() << std::endl;  // Output: 2
    std::cout << "Extracted min: " << minHeap.getMin() << std::endl;  // Output: 3
    std::cout << "New min value: " << minHeap.extractMin() << std::endl;  // Output: 2

    return 0;
}   