#include <iostream>
#include <vector>

using namespace std;

class ProductOfNumbers {
    vector<int> products;
    int n;
public:
    ProductOfNumbers() {
        products.clear();
        n = 0;
    }
    
    void add(int num) {
        if (num == 0) {
            // If we see a zero, reset the sequence because any product 
            // spanning across this zero will be 0.
            products.clear();
            n = 0;
        } else {
            if (products.empty()) {
                products.push_back(num);
            } else {
                products.push_back(products.back() * num);
            }
            n++;
        }
    }
    
    int getProduct(int k) {
        // If k is greater than the current sequence length n, 
        // it means the range includes a zero we previously reset on.
        if (k > n) {
            return 0;
        } else if (k == n) {
            // If k equals current length, return the total product of current sequence
            return products[n - 1];
        }
        // Standard range product: total product / product before the last k elements
        return products[n - 1] / products[n - k - 1];
    }
};

int main() {
    ProductOfNumbers* productOfNumbers = new ProductOfNumbers();
    
    cout << "Action: add(3)" << endl;
    productOfNumbers->add(3);        // [3]
    
    cout << "Action: add(0)" << endl;
    productOfNumbers->add(0);        // [3, 0] -> effectively resets sequence
    
    cout << "Action: add(2)" << endl;
    productOfNumbers->add(2);        // [2]
    
    cout << "Action: add(5)" << endl;
    productOfNumbers->add(5);        // [2, 5]
    
    cout << "Action: add(4)" << endl;
    productOfNumbers->add(4);        // [2, 5, 4]
    
    // getProduct(2) -> 5 * 4 = 20
    cout << "getProduct(2): " << productOfNumbers->getProduct(2) << endl; 
    
    // getProduct(3) -> 2 * 5 * 4 = 40
    cout << "getProduct(3): " << productOfNumbers->getProduct(3) << endl; 
    
    // getProduct(4) -> 0 * 2 * 5 * 4 = 0 (k > n, because of the zero reset)
    cout << "getProduct(4): " << productOfNumbers->getProduct(4) << endl; 

    cout << "Action: add(8)" << endl;
    productOfNumbers->add(8);        // [2, 5, 4, 8]
    
    // getProduct(2) -> 4 * 8 = 32
    cout << "getProduct(2): " << productOfNumbers->getProduct(2) << endl; 

    delete productOfNumbers;
    return 0;
}