#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
namespace __gnu_pbds{
          typedef tree<int,
                       null_type,
                       less_equal<int>,
                       rb_tree_tag,
                       tree_order_statistics_node_update> ordered_set;
}
using namespace __gnu_pbds;
class PBDS_multiset{
    // *If you want to change your multi ordered set data type,you should change almost everything in the above functions.
    public:
    ordered_set s;
    void insert(int x){ //this function inserts one more occurrence of (x) into the set.
         s.insert(x);
    }
    bool exist(int x){ //this function checks weather the value (x) exists in the set or not.
         if((s.upper_bound(x))==s.end()){
            return 0;
         }
         return ((*s.upper_bound(x))==x);
    }
    void erase(int x){ //this function erases one occurrence of the value (x).
         if(exist(x)){
            s.erase(s.upper_bound(x));
         }

    }
    int firstIdx(int x){ //this function returns the first index of the value (x)..(0 indexing).

        if(!exist(x)){
            return -1;
        }
        return (s.order_of_key(x));

    }
    int value(int idx){ //this function returns the value at the index (idx)..(0 indexing).

       return (*s.find_by_order(idx));

    }
    int lastIdx(int x){ //this function returns the last index of the value (x)..(0 indexing).

        if(!exist(x)){
            return -1;
        }
        if(value((int)s.size()-1)==x){
            return (int)(s.size())-1;
        }
        return firstIdx(*s.lower_bound(x))-1;

    }
    int count(int x){ //this function returns the number of occurrences of the value (x).

         if(!exist(x)){
            return 0;
         }
         return lastIdx(x)-firstIdx(x)+1;

    }
    int less_than_equal(int x){
        // returns number of elements less than equal to x
        return 1 + lastIdx(x);
    }
    int less_than(int x){
        // return number of elements less than x
        return less_than_equal(x-1);
    }
    int greater_than(int x){
        // return number of elements greater than x
        return (int)(s.size()) - less_than_equal(x);
    }
    int greater_than_equal(int x){
        // return number of elements greater than equal to x
        return (int)(s.size()) - less_than(x);
    }
    int between(int l,int r){
        return less_than_equal(r) - less_than_equal(l-1);
    }
    void print(){
        for(auto it : s){
            cout << it << " ";
        }
        cout << endl;
    }
    void clear(){ //this function clears all the elements from the set.
         s.clear();

    }
    int size(){ //this function returns the size of the set.
         return (int)(s.size());
    }
};

int main(){



     return 0;

}
